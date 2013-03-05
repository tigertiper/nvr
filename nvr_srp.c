#include <rpc/rpc.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/time.h>
#include "nvr.h"
#include "Debug.h"
#include "rd_wr.h"
#include "multi_stream.h"

#define PRC_SVC

extern pthread_rwlock_t DInfo_PRW;
extern char ClientIP[IPLEN];
extern unsigned short int ClientPort;
extern int debug_level;
int trace_enter_count = 0;


extern pthread_rwlock_t SInfo_PRW;

static int retcode;
static READres readres;
static HEADERinfo headerInfo;
//static SEARCHres recordInfo;
static char readBuf[MAX_READ_SIZE];
static char headBuf[MAX_HEADER_LENGTH];
long long get_free_vol_size(const char *volName); 


unsigned int
nvrproc_close(unsigned int streamHandle)
{
	int res = 0;
	int i = 0;		//index of streamIfos
	char pcameraID[CAMERAIDLEN];

	i = findStreamInfo(streamHandle);
	if (i >= 0) {		//is recording	
		strcpy(pcameraID, streamInfos[i]->cameraID);
		TRACE_LOG( "Start to close record segment in record volume %s, handle:%d!\n",pcameraID, streamHandle);
		pthread_rwlock_wrlock(&streamInfos[i]->RWlock_Recording);
		pthread_mutex_unlock(&streamInfos[i]->Mutex_Buffer[streamInfos[i]->BFlag]);
		streamInfos[i]->isRecording = 0;
		pthread_rwlock_unlock(&streamInfos[i]->RWlock_Recording);

		pthread_join(streamInfos[i]->wrThread, NULL);
		streamInfos[i]->count = streamInfos[i]->vi->count;
		memcpy(streamInfos[i]->t, streamInfos[i]->vi->t, WriteLen * sizeof(tnode));
		streamInfos[i]->vi->count = 0;
		if ((res = CloseRecordSeg(streamHandle, streamInfos[i])) == -1) {
			TRACE_LOG( "Close record segment failed in record volume %s, handle:%d! (errno:%u)\n",pcameraID, streamHandle, ErrorFlag);
		}
		//  pthread_rwlock_wrlock(&streamInfos[i]->RWlock_Recording);
		//      pthread_mutex_unlock(&streamInfos[i]->Mutex_Buffer[streamInfos[i]->BFlag]);
		//      streamInfos[i]->isRecording = 0;
		//      pthread_rwlock_unlock(&streamInfos[i]->RWlock_Recording);
		// waiting for the end of send_thread
		//      pthread_join(streamInfos[i]->wrThread , NULL);
		releaseStreamInfo(&streamInfos[i]);
	} 
	else {			//is recording
		i = findDownloadInfo(streamHandle);
		if(i < 0)
		{
			ErrorFlag = ERR_HANDLE;
			TRACE_LOG( "Close record segment failed in record volume %s, handle:%u not exist! cancel!(errno:%u)\n", pcameraID, streamHandle, ErrorFlag);
			return -1;
		}
		strcpy(pcameraID,  pDInfo[i]->CameraID);
		TRACE_LOG( "Start to close record segment in record volume %s, handle:%u!\n",pcameraID, streamHandle);
		res = CloseRecordSeg(streamHandle, NULL);
		if(res < 0){
			TRACE_LOG( "Close record segment failed in record volume %s, handle:%d! (errno:%u)\n",pcameraID, streamHandle, ErrorFlag);
		}
		releaseDownloadInfo(streamHandle);
	}
	TRACE_LOG( "Close record segment successfully in record volume %s, handle:%u!\n",pcameraID, streamHandle);
	return res;
}


unsigned int
nvrproc_create(CREATEargs createargs)
{
	TRACE_LOG( "Start to create record segment in record volume %s.\n", createargs.camerID);
	unsigned int handle;
	int i = 0;
	seginfo sinfo;
	sinfo.frame = 0;
	sinfo.height = 1;
	sinfo.width = 2;
	sinfo.size = createargs.header.header_len;
	strcpy(sinfo.des, createargs.describe);
    
	if((i= findStreamInfoByCID(createargs.camerID) )!= -1)
	{
        if (streamInfos[i] && streamInfos[i]->lastRecordTime && ((time(NULL) - streamInfos[i]->lastRecordTime) > 10)) { 
			nvrproc_close(streamInfos[i]->handle);
        }
        else{
            ErrorFlag = CAMERA_IS_RECORDING; 
            TRACE_LOG( "Create record segment in record volume %s failed! (errno:%d)\n",createargs.camerID, ErrorFlag);
            return -1;
        }
	}

	handle = CreatRecordSeg(createargs.camerID, &sinfo, createargs.header.header_val, createargs.header.header_len);
	if (handle == (unsigned int)-1)
	{
		TRACE_LOG( "Create record segment in record volume %s failed!(errno:%d)\n",createargs.camerID, ErrorFlag);
		return -1;
	}
	i = findStreamInfo(handle);
	if (i < 0) {
		i = allocStreamInfo(handle);
		if (i < 0) {
			TRACE_LOG( "Create record segment in record volume %s failed!(errno:%d)\n",createargs.camerID, ErrorFlag);
			return -1;
		}
	} else if (streamInfos[i]->isRecording) {		
		TRACE_LOG( "Create record segment in record volume %s failed!(Camera is recording!)\n",createargs.camerID);
		return -1;
	}

	/*initial streamInfo vars */
	strcpy(streamInfos[i]->cameraID, createargs.camerID);
	streamInfos[i]->BFlag = 0;
	streamInfos[i]->isRecording = 1;

	pthread_mutex_lock(&streamInfos[i]->Mutex_Buffer[streamInfos[i]->BFlag]);

	if (pthread_create(&streamInfos[i]->wrThread, NULL, writeThread, (void *)streamInfos[i]) != 0) {
		ErrorFlag = NVR_CREATWRITEDATATHREADFAIL;
		pthread_mutex_unlock(&streamInfos[i]->Mutex_Buffer[streamInfos[i]->BFlag]);
		TRACE_LOG( "Create record segment in record volume %s failed!(errno:%d)\n",createargs.camerID, ErrorFlag);
		return -1;
	}

	TRACE_LOG( "Create record segment in record volume %s successfully, handle:%d!\n",createargs.camerID,  handle);
	return handle;
}


unsigned int
nvrproc_write(WRITEargs writeargs)
{
	//TRACE_LOG( "...nvrproc_write...\n");
	int wlen = 0, i = 0, writeCost = 0;
	struct timeval time2, time1;
	//gettimeofday(&time2,NULL);

	i = findStreamInfo(writeargs.recordHandle);
	if (i < 0 || writeargs.data.data_len <= 0) {
		ErrorFlag = ERR_HANDLE;
		TRACE_LOG( "%u write error, (errno:%d).\n", writeargs.recordHandle, ErrorFlag);
		return -1;
	}
	if (writeTnodeToBuf(streamInfos[i], writeargs.beginTime, writeargs.data.data_len) < 0) {
		TRACE_LOG( "write error in record volume %s, (errno:%d).\n", streamInfos[i]->cameraID, ErrorFlag);
		return -1;
	}
	gettimeofday(&time1, NULL);
	//printf("writetnode cost %d : %10ld\n",time1.tv_sec-time2.tv_sec,time1.tv_usec-time2.tv_usec);

	if (writeToBuf(streamInfos[i], writeargs.data.data_val, writeargs.data.data_len) < 0) {
		ErrorFlag = WRITE_LVM_ERR;
		TRACE_LOG( "write error in record volume %s, (errno:%d).\n", streamInfos[i]->cameraID, ErrorFlag);
		return -1;
	}
	streamInfos[i]->v->storeAddr += writeargs.data.data_len;

	gettimeofday(&time2, NULL);
	if (time1.tv_sec == time2.tv_sec)
		writeCost = time2.tv_usec - time1.tv_usec;
	else
		writeCost = (time2.tv_sec * 1000000) + time2.tv_usec - time1.tv_usec - time1.tv_sec * 1000000;
	if (writeCost > 1000)
		TRACE_LOG( "write data in record volume %s cost: %10ld us\n", streamInfos[i]->cameraID,  writeCost);

	//printf("... write %d bytes,time = %d ...\n",writeargs.data.data_len,writeargs.beginTime); 
	return writeargs.data.data_len;
}

int
writeToBuf(StreamInfo * si, char *data, int dataLen)
{
	char *pc = NULL;
	//struct timeval time2,time1;
	//keep the record op if atomic, assured one buffer is alway Locked!
	pthread_rwlock_rdlock(&si->RWlock_Recording);

	if (!si->isRecording) {	//Recieved stop record command
		pthread_rwlock_unlock(&si->RWlock_Recording);
		return -1;
	}

	if (dataLen > si->BEmpty_Size[si->BFlag]
	    || (si->wrAddr[si->BFlag] + si->BUsed_Size[si->BFlag]) != si->v->storeAddr) {
		//swich the buffer to record the data of a new secord
		pthread_mutex_unlock(&si->Mutex_Buffer[si->BFlag]);
		si->BFlag = (si->BFlag + 1) % 2;
		//      gettimeofday(&time2,NULL);
		pthread_mutex_lock(&si->Mutex_Buffer[si->BFlag]);
		si->wrAddr[si->BFlag] = si->v->storeAddr;
		//      gettimeofday(&time1,NULL);
		//      printf("switch buf cost %d : %10ld\n",time1.tv_sec-time2.tv_sec,time1.tv_usec-time2.tv_usec);
	}
	si->lastRecordTime = time(NULL);
	//append data to buffer
	pc = si->RecordBuffer[si->BFlag] + si->BUsed_Size[si->BFlag];
	//gettimeofday(&time2,NULL);
	memcpy(pc, data, dataLen);	//record the new data
	//gettimeofday(&time1,NULL);
	//printf("memcpy cost %d : %10ld\n",time1.tv_sec-time2.tv_sec,time1.tv_usec-time2.tv_usec);

	si->BUsed_Size[si->BFlag] += dataLen;
	si->BEmpty_Size[si->BFlag] = si->BTotal_Size[si->BFlag] - si->BUsed_Size[si->BFlag];

	pthread_rwlock_unlock(&si->RWlock_Recording);

	return 0;
}

void *
writeThread(void *arg)
{
	int ret = 0;
	StreamInfo *si = (StreamInfo *) arg;
	struct timeval time, time1;
	while (1) {
		pthread_rwlock_rdlock(&si->RWlock_Recording);
		if (!si->isRecording) {
			pthread_rwlock_unlock(&si->RWlock_Recording);
			return 0;
		}
		pthread_rwlock_unlock(&si->RWlock_Recording);
		pthread_mutex_lock(&si->Mutex_Buffer[si->wrFlag]);
		if (si->BUsed_Size[si->wrFlag] > 0) {
			//pthread_mutex_lock(&si->Mutex_Buffer[si->wrFlag]);

			gettimeofday(&time, NULL);
			//注意互斥
			ret = __write(si->vi->fd, si->RecordBuffer[si->wrFlag], si->BUsed_Size[si->wrFlag], si->wrAddr[si->wrFlag], &si->vi->mutex);
			gettimeofday(&time1, NULL);
			//printf("_write cost %d : %10ld\n", time1.tv_sec - time.tv_sec, time1.tv_usec - time.tv_usec);
			//          printf("%ld:%d:buf[0-111]%d\n",si->wrAddr[si->wrFlag],si->BUsed_Size[si->wrFlag],si->wrFlag);
			if (ret == -1) {
				ErrorFlag = WRITE_LVM_ERR;
				//pthread_rwlock_wrlock(&si->RWlock_Recording);
				si->isRecording = 0;
				//pthread_rwlock_unlock(&si->RWlock_Recording);
				TRACE_LOG( "write error in record volume %s..(errno:%d)\n", si->cameraID, ErrorFlag);
			}
			/*clear the buffer, and reset it */
			//bzero(si->RecordBuffer[si->wrFlag], si->BUsed_Size[si->wrFlag]);
			si->BUsed_Size[si->wrFlag] = 0;
			si->BEmpty_Size[si->wrFlag] = si->BTotal_Size[si->wrFlag];
			pthread_mutex_unlock(&si->Mutex_Buffer[si->wrFlag]);
			si->wrFlag = (si->wrFlag + 1) % 2;	//switch buffer
		} else {
			pthread_mutex_unlock(&si->Mutex_Buffer[si->wrFlag]);
		}
	}

	return 0;
}

unsigned int
nvrproc_open(CMMNargs openargs)
{
	TRACE_LOG( "start to open record segment in record volume %s.\n", openargs.camerID);
	unsigned int handle;
	int i = 0;

	handle = openRecordSeg(openargs.camerID, openargs.beginTime, openargs.endTime, openargs.mode);
	if (handle == (unsigned int)-1) {
		TRACE_LOG("open record segment error in record volume %s.(errno:%u).\n",openargs.camerID, ErrorFlag);
		return handle;
	}
	if ((i = initDownloadInfo(handle)) < 0)
	{
		TRACE_LOG("open record segment error in record volume %s.(errno:%u).\n",openargs.camerID, ErrorFlag);
		return -1;
	}
	//added by wsr 20121029
	pthread_rwlock_wrlock(&DInfo_PRW);
	strcpy(pDInfo[i]->CameraID, openargs.camerID);
	pthread_rwlock_unlock(&DInfo_PRW);
	//end
	TRACE_LOG( "open record segment successfully in record volume %s, handle:%u!.\n", openargs.camerID, handle);
	return handle;
}

READres
nvrproc_read(READargs readargs)
{
	//TRACE_LOG( "... read ...,handle  = %d\n", readargs.playHandle);
	int readLen = 0, i;
	i = findDownloadInfo(readargs.playHandle);
	if(i < 0)
	{
		TRACE_LOG( "read data error in record volume %s.(errno:%u).\n", pDInfo[i]->CameraID, ErrorFlag);
	}
	readLen = ReadStream(readargs.playHandle, readBuf, readargs.readSize, readargs.mode);

	//TRACE_LOG( "read %d bytes\n", readLen);
	if (readLen < 0) {
		TRACE_LOG( "read data error in record volume %s.(errno:%u).\n", pDInfo[i]->CameraID, ErrorFlag);
		readLen = 0;
	}
	readres.data.data_val = readBuf;
	readres.data.data_len = readLen;
	readres.dataLen = readLen;
	pDInfo[i]->lastReadTime = time(NULL);
	return readres;
}

HEADERinfo
nvrproc_getheader(CMMNargs gethargs)
{
	TRACE_LOG( "start to get record header of record volume %s!\n", gethargs.camerID);
	headerInfo.nextBeginTime = _GetRecordSegHead(gethargs.camerID, &gethargs.beginTime, &gethargs.endTime, headBuf, &(headerInfo.data.data_len));
	if(headerInfo.nextBeginTime == ERR_RETURN)
	{
		TRACE_LOG( "get record header of record volume %s error! (errno:%u)\n", gethargs.camerID, ErrorFlag);	
		headerInfo.data.data_len = 0;
	}
	headerInfo.data.data_val = headBuf;
	headerInfo.beginTime = gethargs.beginTime;
	headerInfo.endTime = gethargs.endTime;
	TRACE_LOG( "get record header of record volume %s successfully!\n", gethargs.camerID);
	return headerInfo;
}

SEARCHres
nvrproc_searchrecord(SEARCHargs searchargs)
{ 
	SEARCHres recordInfo;
	seginfo si;
	recordInfo.cmmnArgs = searchargs;
	recordInfo.nextBeginTime = GetRecordInfo(searchargs.camerID, &searchargs.beginTime, &searchargs.endTime, &si);
	if(headerInfo.nextBeginTime == ERR_RETURN)
	{
		TRACE_LOG( "search record error in record volume %s!(errno:%u)\n", searchargs.camerID, ErrorFlag);		
	}
	recordInfo.cmmnArgs.beginTime = searchargs.beginTime;
	recordInfo.cmmnArgs.endTime = searchargs.endTime;
	//strcpy(recordInfo.describe,si.des);
	recordInfo.describe = si.des;
	recordInfo.describeLen = strlen(si.des);
	
	//TRACE_LOG( "search record successfully in record volume %s!\n", searchargs.camerID);
	return recordInfo;
}

RECORDBYORDERres
nvrproc_searchrecordbyorder(RECORDBYORDERargs searchargs)
{    
	//TRACE_LOG( "%s start to search record by order!\n", searchargs.camerID);
	RECORDBYORDERres recordInfo;
	seginfo si;
	recordInfo.flag=GetRecordInfoOnebyOne(searchargs.camerID, &searchargs.beginTime, &searchargs.endTime, &si, &searchargs.num);
	if(recordInfo.flag == ERR_RETURN)
	{
		TRACE_LOG("search record in record volume %s by order error. (errono:%u)\n", searchargs.camerID, ErrorFlag);
	}
	recordInfo.beginTime = searchargs.beginTime;
	recordInfo.endTime = searchargs.endTime;
	recordInfo.describe = si.des;
	recordInfo.describeLen = strlen(si.des);
	return recordInfo;
}

unsigned int
nvrproc_setrecinfo(SETRECINFOargs setrecinfoargs)
{
	TRACE_LOG( "%s start to setrecinfo!\n", setrecinfoargs.cmmnArgs.camerID);
	return 1;
}

VOLUMinfo
nvrproc_getvolumeinfo(unsigned int camerid)
{
	TRACE_LOG( "... getvolumeinfo ..., cameraID = %s\n", camerid);
	static VOLUMinfo *voluminfo;
	voluminfo = (VOLUMinfo *) malloc(sizeof(VOLUMinfo));
	bzero(voluminfo, sizeof(READres));
	return *voluminfo;
}

unsigned int
nvrproc_delete(DELargs delargs)
{
	TRACE_LOG( "delete record segment in record volume %s!\n", delargs.camerID);
	uint32_t ret;
	ret = DeleteRecordSeg(delargs.beginTime, delargs.endTime, delargs.camerID);
	if(ret < 0)
	{
		TRACE_LOG("delete record segment error in record volume %s. (errno:%u).", delargs.camerID, ErrorFlag);
		return ret;
	}
	TRACE_LOG( "delete record segment successfully in record volume %s!\n", delargs.camerID);
	return ret;
}


unsigned int
nvrproc_login(LOGINargs loginargs)
{
	TRACE_LOG( "%s:%d start to login!\n", ClientIP, ClientPort);
	clearInactiveStreams();
	//get_lv_name(lv, MAX_LV_NUM);
	//if(num<=0)return -1;
	if (loginargs.userName == NULL || loginargs.pwd == NULL)
	{
		TRACE_LOG("%s:%d login error, error usrname or password!\n", ClientIP, ClientPort);
		return 1;
	}
	if (strcmp(loginargs.userName, "admin")
	    || strcmp(loginargs.pwd, "password"))
	{	
		TRACE_LOG("%s:%d login error, error usrname or password!\n", ClientIP, ClientPort);
		return 1;
	}
	return 0;
}

int
nvrproc_logout(unsigned int userid)
{
	TRACE_LOG( "%d start to logout!\n", userid);

	return 0;
}

unsigned long
nvrproc_getlasterror()
{
	TRACE_LOG( "getlasterror, err = %d\n", ErrorFlag);
	return ErrorFlag;
}

unsigned int
nvrproc_getrecsize(GETRECSIZEargs getRecSizeArgs)
{
	TRACE_LOG( "start to get record size in record volume %s.\n", getRecSizeArgs.camerID);
	unsigned int recordSize = 0;
	unsigned int beginTime, endTime;
	beginTime = getRecSizeArgs.beginTime;
	endTime = getRecSizeArgs.endTime;
	headerInfo.nextBeginTime = _GetRecordSegHead(getRecSizeArgs.camerID, &beginTime, &endTime, headBuf, &recordSize);
	if (headerInfo.nextBeginTime == ERR_RETURN)
	{
		TRACE_LOG("get record size error in record volume %s. (errono:%u)\n", getRecSizeArgs.camerID, ErrorFlag);
		return 0;
	}
	if (beginTime < getRecSizeArgs.beginTime)
		beginTime = getRecSizeArgs.beginTime;
	if (endTime > getRecSizeArgs.endTime)
		endTime = getRecSizeArgs.endTime;
	recordSize = GetRecordSegSize(getRecSizeArgs.camerID, beginTime, endTime);
	if (recordSize < 0)
	{
		TRACE_LOG("get record size error in record volume %s. (errono:%u)\n", getRecSizeArgs.camerID, ErrorFlag);
		return 0;
	}
	
	TRACE_LOG( "get record size successfully in record volume %s.\n", getRecSizeArgs.camerID);
	return recordSize;
}

int
nvrproc_creatrecvol(CREATRECVOLargs creatRecVolArgs)
{
	TRACE_LOG( "start to create record volume %s in %s!\n",creatRecVolArgs.name, creatRecVolArgs.volumeid);
	int ret = 0, i;
	uint64_t volSize = creatRecVolArgs.blockSize;
	volSize *= creatRecVolArgs.blocks;
	//num = get_lv_name(lv,MAX_LV_NUM);
	//if(num<=0)return -1;
    if('\0' == *creatRecVolArgs.volumeid)
    {
        for (i = 0; i < MAX_LV_NUM; i++) {
        	if (lv[i].length > volSize / 1024 / 1024)
        		break;
        }

        if(i == MAX_LV_NUM)
        {
        	ErrorFlag = SPACE_NOT_ENOUGH;
        	ret = -1;
        	return ret;
        }

        ret = CreateRecordVol(lv[i].lv_name,
        		      creatRecVolArgs.name,
        		      creatRecVolArgs.alias,
        		      creatRecVolArgs.savedDays, creatRecVolArgs.delPolicy, creatRecVolArgs.encodeType, volSize / (128 * 1024 * 1024));
        if(ret < 0)
        {
        	TRACE_LOG( "create record volume %s error.(errno:%u)\n",creatRecVolArgs.name, ErrorFlag);
        	return ret;
        }

        lv[i].length = get_free_vol_size(lv[i].lv_name);
        TRACE_LOG( "create record volume %s in %s successfully!\n",creatRecVolArgs.name, creatRecVolArgs.volumeid);
    }
    else
    {
        ret = CreateRecordVol(creatRecVolArgs.volumeid,
		      creatRecVolArgs.name,
		      creatRecVolArgs.alias,
		      creatRecVolArgs.savedDays, creatRecVolArgs.delPolicy, creatRecVolArgs.encodeType, creatRecVolArgs.blocks);
        if(ret < 0)
        {
        	TRACE_LOG( "create record volume %s error.(errno:%u)\n",creatRecVolArgs.name, ErrorFlag);
        	return ret;
        }
        TRACE_LOG( "create record vol %s in %s successfully!\n",creatRecVolArgs.name, creatRecVolArgs.volumeid);
    }
	return ret;
}

int
nvrproc_delrecvol(DELRECVOLargs delRecVolArgs)
{
	TRACE_LOG( "start to delete record vol %s!\n", delRecVolArgs.cameraID);

	int ret = 0, i;
	ret = DeleteRecordVol(delRecVolArgs.cameraID, delRecVolArgs.mode);
	if(ret < 0)
	{
		TRACE_LOG( "delete record volume %s error.(errno:%u)\n",delRecVolArgs.cameraID, ErrorFlag);
		return ret;
	}
	for (i = 0; i < MAX_LV_NUM; i++)
		lv[i].length = get_free_vol_size(lv[i].lv_name);
	TRACE_LOG( "delete record volume %s successfully!\n",delRecVolArgs.cameraID);
	return ret;
}

void
clearInactiveStreams()
{
	TRACE_LOG( "Start to clear inactive streams!\n");

	int i = 0;
	unsigned int curTime = time(NULL);

	for (; i < MAX_STREAMS; i++) {
		pthread_rwlock_rdlock(&SInfo_PRW);
		//note: while nothing to write,how to close
		if (streamInfos[i] && streamInfos[i]->lastRecordTime && ((curTime - streamInfos[i]->lastRecordTime) > 120)) {
			TRACE_LOG("Close record stream%s:%u!\n", streamInfos[i]->cameraID, streamInfos[i]->handle);
			pthread_rwlock_unlock(&SInfo_PRW);
			nvrproc_close(streamInfos[i]->handle);
		} else
			pthread_rwlock_unlock(&SInfo_PRW);
		if (pDInfo[i] && (curTime - pDInfo[i]->lastReadTime > 30))
		{
			TRACE_LOG("Close download stream %s:%u!\n", pDInfo[i]->CameraID, pDInfo[i]->dHandle);
			nvrproc_close(pDInfo[i]->dHandle);
		}
	}
}

void *
WriteTnodeThread(void *arg)
{
	TRACE_LOG( "Start write tnode thread!\n");
	int i = 0;
	for (;; i = (i + 1) % MAX_STREAMS) {
		if (i == 0)
			sleep(20);
		pthread_rwlock_rdlock(&SInfo_PRW);
		if (streamInfos[i] == NULL || streamInfos[i]->count < WriteLen) {
			pthread_rwlock_unlock(&SInfo_PRW);
			continue;
		}

		if (write_back_tnodes(streamInfos[i]->sbinfo, streamInfos[i]->v, streamInfos[i]->vi, streamInfos[i]) < 0) {
			TRACE_LOG( "%s write back tnodes failed. (errno:%u)\n", streamInfos[i]->cameraID, ErrorFlag);
		}
		streamInfos[i]->count = 0;
		if (put_vnode(streamInfos[i]->sbinfo, streamInfos[i]->v, NULL, streamInfos[i]->ID) < 0) {
			TRACE_LOG("%s update vnode failed. (errno:%u)\n", streamInfos[i]->cameraID, ErrorFlag);
		}
		pthread_rwlock_unlock(&SInfo_PRW);

	}
}

//负责录象卷操作的线程
void *
VolOpThread(void *arg)
{
	TRACE_LOG( "Start volume operations!\n");
	CreatRecVolMsg creatMsg;
	DelRecVolMsg delMsg;
	DelVideoVolMsg delVideoMsg;
	ResMsg resMsg;
	//key_t sendKey,recvKey;
	int sendQID, recvQID;
	ssize_t ret;

	//recvKey = ftok("/opt/HTRaid/conf/camera.conf",1);
	//sendKey = ftok("/opt/HTRaid/conf/msgfile",1);

	sendQID = msgget((key_t) 706504, 0666 | IPC_CREAT);
	recvQID = msgget((key_t) 706507, 0666 | IPC_CREAT);
	if (sendQID == -1 || recvQID == -1) {
		TRACE_LOG( "msgget failed with error: %d. *exit*\n", errno);
		exit(1);
	}
    
	while (1) {
		ret = msgrcv(recvQID, (void *)&creatMsg, sizeof(CreatRecVolMsg) - sizeof(long int), CREAT_REC_VOL_ARGS, IPC_NOWAIT);
		if (ret != -1) {
			resMsg.msgType = CREAT_REC_VOL_RES;
			resMsg.result = CreateRecordVol(creatMsg.volumeid,
							creatMsg.name,
							creatMsg.alias, creatMsg.savedDays, creatMsg.delPolicy, creatMsg.encodeType, creatMsg.blocks);
			if(resMsg.result < 0)
			{
				TRACE_LOG( "create record volume %s in %s faile.(errno:%u).\n", creatMsg.name, creatMsg.volumeid, ErrorFlag);
			}
			if (msgsnd(sendQID, (void *)&resMsg, sizeof(int), 0) == -1) {
				TRACE_LOG("Send msg failed when create record volume %s in %s.\n", creatMsg.name, creatMsg.volumeid);
				break;
			}
			continue;
		}

		if (msgrcv(recvQID, (void *)&delMsg, sizeof(DelRecVolMsg) - sizeof(long int), DEL_REC_VOL_ARGS, IPC_NOWAIT) != -1) {
			resMsg.msgType = DEL_REC_VOL_RES;
			resMsg.result = DeleteRecordVol(delMsg.cameraID, delMsg.mode);
			if (msgsnd(sendQID, (void *)&resMsg, sizeof(int), 0) == -1) {
				fprintf(stderr, "send msg failed\n");
				TRACE_LOG("Send msg failed when delete record volume %s.\n", delMsg.cameraID);
				break;
			}
			continue;
		}

		if (msgrcv(recvQID, (void *)&delVideoMsg, sizeof(DelVideoVolMsg) - sizeof(long int), DEL_VIDEO_VOL_ARGS, IPC_NOWAIT) != -1) {
			resMsg.msgType = DEL_VIDEO_VOL_RES;
			resMsg.result = DeleteVideoVol(delVideoMsg.volName);
			if (msgsnd(sendQID, (void *)&resMsg, sizeof(int), 0) == -1) {
				fprintf(stderr, "send msg failed\n");
				TRACE_LOG("Send msg failed when delete video volume %s.\n", delVideoMsg.volName);
				break;
			}
			continue;
		}

		sleep(1);
	}
	TRACE_LOG("VolOPThread exit!");
	pthread_exit(0);
}

//********************************

long long
get_free_vol_size(const char *volName)
{
	int fd1;
	char buf[SB_SIZE];
	long long size;
	SBlock *sb;
	if ((sb = (SBlock *) malloc(sizeof(SBlock))) < 0) {
		ErrorFlag = MALLOC_ERR;
		return -1;
	}
	if ((fd1 = open(volName, O_RDONLY)) < 0) {
		ErrorFlag = OPEN_FILE_ERR;
		goto err;
	}
	if (_read(fd1, buf, SB_SIZE, 0) < 0) {
		ErrorFlag = READ_LVM_ERR;
		goto err;
	}
	buf_to_sb(buf, sb);
	close(fd1);
	if (sb->magic != MAGIC || (strcmp(sb->fileSystemName, FILE_SYS_NAME) != 0)) {
		free(sb);
		return -1;
	}
	size = sb->freeBlocksCount * ((sb->blockSize / 1024) / 1024);
	free(sb);
	return size;
      err:
	free(sb);
	close(fd1);
	return -1;
}


int
get_lv_name(LvInfo * lv_info, int max)
{
	int num = 0;
	FILE *fp = NULL;
	char line[MAXLINE];
	char *tmp;
	int i;
	if ((fp = popen("lvs -o vg_name,lv_name --noheadings --separator /", "r")) != NULL) {
		while (fgets(line, MAXLINE, fp) != NULL) {
			i = 0;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			//printf("%s",&line[i]);
			tmp = &line[i];
			while (line[i] != '\n')
				i++;
			line[i] = '\0';
			strcpy(lv_info[num].lv_name, "/dev/");
			strcat(lv_info[num].lv_name, tmp);
			lv_info[num].length = get_free_vol_size(lv_info[num].lv_name); 
			if (lv_info[num].length != -1)
            {         
                TRACE_LOG("VedioVoL%d:\t%s\t%ld\n",num,lv_info[num].lv_name,lv_info[num].length);
                num++;
            }
            else
            {
                bzero(lv_info[num].lv_name, CNameLength);
            }
			if (num >= max)
				break;
		}
		pclose(fp);
	}
	return num;
}

int initCameraInfos()
{
     int i;
     int count=0;
     char *vbitmap;
     int fd;
     char buf[Vnode_SIZE];
     vnode v;
     const char *lv_name;
     removeCameraList();
     if(creatCameraList()<0)
        return -1;
     get_lv_name (lv, MAX_LV_NUM);  
     for (i = 0; i < MAX_LV_NUM; i++) {
            lv_name = (const char*)lv[i].lv_name;
            if('\0' == *lv_name)
            {
                break;
            } 
            if((fd=open(lv_name, O_RDONLY))<0){
                 ErrorFlag=OPEN_FILE_ERR;
				 TRACE_LOG("Opening VedioVol %s error!\n",lv_name);
                 return -1;
            }
            if((vbitmap=(char *)malloc(sizeof(char) *(MaxUsers / 8)))==NULL){
                ErrorFlag=MALLOC_ERR;
                close(fd);
				TRACE_LOG("Malloc error!\n");
                return -1;
            }
            if(_read(fd, vbitmap, MaxUsers / 8, VBitmapAddr)<0){
                 close(fd);
                 free(vbitmap);
				 TRACE_LOG("Read vbitmap error!\n");
                 return -1;
            }
            count=0;
            while(count<MaxUsers) {
                if(bit(vbitmap,count)){
                      if(_read(fd,buf,Vnode_SIZE,VnodeAddr+count*Vnode_SIZE)<0){
                          close(fd);
                          free(vbitmap);
				          TRACE_LOG("Read vode error!\n");
                          return -1;
                       }
                       buf_to_vnode(buf,&v);
                       addCameraInfo(v.cameraid,lv_name);  
                }
            count++;
            }
            close(fd);
            free(vbitmap);   
     }
     return 0;
}

int isRunning()
{
    pid_t pid = -1, file_pid = -1;
    FILE *fp = NULL;
    pid = getpid();
    char cmd[256];
    bzero(cmd, 256);
    if(access(PID_FILE, 0)<0)
    { 
        sprintf(cmd, "%u\0", pid);
        TRACE_LOG("Start Nvrd (pid:%u) Success! \n",pid);
        fp = fopen(PID_FILE, "w+");
        fputs(cmd, fp);
        fclose(fp);
        return 0;
    }
    if ((fp = fopen(PID_FILE, "r")) == NULL) 
        
    {
        TRACE_LOG("Open pidfile error!");
        return -1;
	}

    if(fgets(cmd, 255, fp) == NULL)
    {
        fclose(fp);
        return -1;
    } 
    fclose(fp);
    sscanf(cmd, "%u", &file_pid); 
    sprintf(cmd, "ps -ef|grep nvrd|awk '{print $2}'|grep %u\0", file_pid);
    if(NULL == (fp= popen(cmd, "r")))
    {
        TRACE_LOG("Call popen failed!");
        return -1;
    }
    else
    { 
        while(fgets(cmd, 255, fp) != NULL)
        {
            
            sscanf(cmd, "%u", &file_pid);
            TRACE_LOG("Start Failed! Nvrd (pid:%u) is Exist!\n",file_pid );
            fclose(fp);
            return 1;
        }
        fclose(fp); 
        sprintf(cmd, "%u\0", pid);
        fp = fopen(PID_FILE, "w+");
        fputs(cmd, fp);
        fclose(fp);
        TRACE_LOG("Start Nvrd (pid:%u) Success! \n",pid);
        return 0;
    }
}

