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
#include <poll.h> 
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <time.h>
#include <sys/time.h>
#include "nvr.h"
#include "Debug.h"
#include "rd_wr.h"
#include "multi_stream.h"
#include "syslog.h"
 

#define PRC_SVC
#define SERV_PORT 8000 
#define REC_HEAD_SIZE 14 
#define REC_RESULT_SIZE 10
#define OPEN_MAX 256

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
		syslog(LOG_INFO,  "closing record stream, IPC:%s, handle:0x%x...",pcameraID, streamHandle);
		pthread_rwlock_wrlock(&streamInfos[i]->RWlock_Recording);
		pthread_mutex_unlock(&streamInfos[i]->Mutex_Buffer[streamInfos[i]->BFlag]);
		streamInfos[i]->isRecording = 0;
		pthread_rwlock_unlock(&streamInfos[i]->RWlock_Recording);
        if(streamInfos[i]->wrThread > 0) {
            pthread_join(streamInfos[i]->wrThread, NULL);
        }
		streamInfos[i]->count = streamInfos[i]->vi->count;
		memcpy(streamInfos[i]->t, streamInfos[i]->vi->t, WriteLen * sizeof(tnode));
		streamInfos[i]->vi->count = 0;
		if ((res = CloseRecordSeg(streamHandle, streamInfos[i])) == -1) {
			syslog(LOG_ERR,  "close record stream fail, IPC:%s, handle:0x%x, errno:%u.\n",pcameraID, streamHandle, ErrorFlag);
		} else {
            syslog(LOG_INFO,  "close record stream success, IPC:%s, handle:0x%x.\n",pcameraID, streamHandle);
        } 
		releaseStreamInfo(&streamInfos[i]);
	} 
	else {			//is recording
		i = findDownloadInfo(streamHandle); 
		if(i < 0)
		{
			ErrorFlag = ERR_HANDLE;
			syslog(LOG_ERR,  "close stream fail:handle 0x%x is not exist.\n", streamHandle);
			return -1;
		}
		strcpy(pcameraID,  pDInfo[i]->CameraID);
		syslog(LOG_ERR,  "closing download stream, IPC:%s, handle:0x%x...",pcameraID, streamHandle);
		res = CloseRecordSeg(streamHandle, NULL);
		if(res < 0){
			syslog(LOG_ERR,  "close download stream fail, IPC:%s, handle:0x%x, errno:%u.\n",pcameraID, streamHandle, ErrorFlag);
		} else {
            syslog(LOG_INFO,  "close download stream success, IPC:%s, handle:0x%x.\n",pcameraID, streamHandle);
        }
		releaseDownloadInfo(&pDInfo[i]);
	}
	return res;
}
 
unsigned int
nvrproc_create(CREATEargs createargs)
{
	syslog(LOG_INFO,  "creating record stream, IPC:%s...", createargs.camerID);
	int i = 0; 
    unsigned int handle;
    unsigned int inactivehandle;
	seginfo sinfo;
    i = findStreamInfoByCID(createargs.camerID); 
    if (i >=0) {
        if ((time(NULL) - streamInfos[i]->lastRecordTime) > 5) { 
            inactivehandle = streamInfos[i]->handle;
            syslog(LOG_INFO,  "closing a inactive record stream, IPC:%s, handle:0x%x...", createargs.camerID, inactivehandle);
    		pthread_rwlock_wrlock(&streamInfos[i]->RWlock_Recording);
    		pthread_mutex_unlock(&streamInfos[i]->Mutex_Buffer[streamInfos[i]->BFlag]);
    		streamInfos[i]->isRecording = 0;
    		pthread_rwlock_unlock(&streamInfos[i]->RWlock_Recording);
            if(streamInfos[i]->wrThread > 0) {
                pthread_join(streamInfos[i]->wrThread, NULL);
            }
    		streamInfos[i]->count = streamInfos[i]->vi->count;
    		memcpy(streamInfos[i]->t, streamInfos[i]->vi->t, WriteLen * sizeof(tnode));
    		streamInfos[i]->vi->count = 0;
    		if (CloseRecordSeg(inactivehandle, streamInfos[i]) < 0) {
    			syslog(LOG_ERR,  "close the inactive record stream fail, IPC:%s, handle:0x%x, errno:%u.", createargs.camerID, inactivehandle, ErrorFlag);
    		} else {
                syslog(LOG_INFO,  "close the inactive record stream success, IPC:%s, handle:0x%x.", createargs.camerID, inactivehandle);
            }
    		releaseStreamInfo(&streamInfos[i]);
        } else {
            ErrorFlag = CAMERA_IS_RECORDING;
            syslog(LOG_ERR,  "create record stream fail:camera is recording, IPC:%s, errno:%u.\n",createargs.camerID, ErrorFlag);
            return -1;
        }             
    }
	sinfo.frame = 0;
	sinfo.height = 1;
	sinfo.width = 2;
	sinfo.size = createargs.header.header_len;
	strcpy(sinfo.des, createargs.describe); 
	handle = CreatRecordSeg(createargs.camerID, &sinfo, createargs.header.header_val, createargs.header.header_len);
	if (handle == (unsigned int)-1)
	{
		syslog(LOG_ERR,  "create record stream fail:error handle, IPC:%s, errno:%u.\n",createargs.camerID, ErrorFlag);
		return -1;
	}
	i = findStreamInfo(handle);
	if (i < 0) {
		i = allocStreamInfo(handle);
		if (i < 0) {
			syslog(LOG_ERR,  "create record stream fail:error alloc, IPC:%s, errno:%u.\n",createargs.camerID, ErrorFlag);
            CloseRecordSeg(handle, NULL);
			return -1;
		}
	} else if (streamInfos[i]->isRecording) {		
		syslog(LOG_ERR,  "create record stream fail:exist handle, IPC:%s, handle:0x%x.\n",createargs.camerID, handle);
		return -1;
	}

	/*initial streamInfo vars */
	strcpy(streamInfos[i]->cameraID, createargs.camerID);
	streamInfos[i]->BFlag = 0;
	streamInfos[i]->isRecording = 1;
    streamInfos[i]->writeDataLen = 0;
    
	pthread_mutex_lock(&streamInfos[i]->Mutex_Buffer[streamInfos[i]->BFlag]);
    
	if (pthread_create(&streamInfos[i]->wrThread, NULL, writeThread, (void *)streamInfos[i]) != 0) {
		ErrorFlag = NVR_CREATWRITEDATATHREADFAIL;
		pthread_mutex_unlock(&streamInfos[i]->Mutex_Buffer[streamInfos[i]->BFlag]);
        CloseRecordSeg(handle, NULL);
        releaseStreamInfo(&streamInfos[i]);
		syslog(LOG_ERR,  "create record stream fail:create writethread fail, IPC:%s, errno:%u.\n",createargs.camerID, ErrorFlag);
		return -1;
	}
	syslog(LOG_INFO,  "create record stream success, IPC:%s, handle:0x%x.\n",createargs.camerID,  handle);
	return handle;
}

unsigned int
nvrproc_write(WRITEargs writeargs)
{
	//syslog(LOG_INFO,   "...nvrproc_write, begintime=%u...", writeargs.beginTime);
	int wlen = 0, i = 0, writeCost = 0;
	struct timeval time2, time1;
	int fd = 0;
	//gettimeofday(&time2,NULL);

	i = findStreamInfo(writeargs.recordHandle);
	if (i < 0 || writeargs.data.data_len <= 0) {
		ErrorFlag = ERR_HANDLE;
		syslog(LOG_ERR,   "error record handle:0x%x.\n", writeargs.recordHandle);
		return -1;
	}

	//write to buf when the time is changed
	
	if(streamInfos[i]->writeTime == 0 || streamInfos[i]->writeTime == writeargs.beginTime)
	{
		streamInfos[i]->writeTime = writeargs.beginTime;
		memcpy(streamInfos[i]->writeData + streamInfos[i]->writeDataLen, writeargs.data.data_val, writeargs.data.data_len);
		streamInfos[i]->writeDataLen += writeargs.data.data_len; 
		return writeargs.data.data_len;
	}
	
	syslog(LOG_DEBUG,   "...nvrproc_write, cameraID:%s, handle:0x%x, begintime:%u...", streamInfos[i]->cameraID, streamInfos[i]->handle, writeargs.beginTime);
	if (writeTnodeToBuf(streamInfos[i], streamInfos[i]->writeTime, streamInfos[i]->writeDataLen) < 0) {
		syslog(LOG_ERR,   "write tnode to buf fail, IPC:%s, errno:%u.\n", streamInfos[i]->cameraID, ErrorFlag);
		return -1;
	}
	gettimeofday(&time1, NULL);
	//printf("writetnode cost %d : %10ld\n",time1.tv_sec-time2.tv_sec,time1.tv_usec-time2.tv_usec);

	if (writeToBuf(streamInfos[i], streamInfos[i]->writeData, streamInfos[i]->writeDataLen) < 0) {
		ErrorFlag = WRITE_LVM_ERR;
		syslog(LOG_ERR,   "write data to buf fail, IPC:%s, errno:%u.\n", streamInfos[i]->cameraID, ErrorFlag);
		return -1;
	}
	streamInfos[i]->v->storeAddr += streamInfos[i]->writeDataLen;
    
	streamInfos[i]->writeTime = writeargs.beginTime;
	bzero(streamInfos[i]->writeData, streamInfos[i]->writeDataLen);
	streamInfos[i]->writeDataLen = 0;
	memcpy(streamInfos[i]->writeData + streamInfos[i]->writeDataLen, writeargs.data.data_val, writeargs.data.data_len);
	streamInfos[i]->writeDataLen += writeargs.data.data_len; 

	gettimeofday(&time2, NULL);
	if (time1.tv_sec == time2.tv_sec)
		writeCost = time2.tv_usec - time1.tv_usec;
	else
		writeCost = (time2.tv_sec * 1000000) + time2.tv_usec - time1.tv_usec - time1.tv_sec * 1000000;
	if (writeCost > 1000)
		syslog(LOG_DEBUG,   "write data cost %10ld us, IPC:%s",  writeCost, streamInfos[i]->cameraID);

	//printf("... write %d bytes,time = %d ...",writeargs.data.data_len,writeargs.beginTime);
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
			ret = __write(si->vi->fd, si->RecordBuffer[si->wrFlag], si->BUsed_Size[si->wrFlag], si->wrAddr[si->wrFlag], &si->vi->mutex);
			gettimeofday(&time1, NULL);
			//printf("_write cost %d : %10ld\n", time1.tv_sec - time.tv_sec, time1.tv_usec - time.tv_usec);
			//          printf("%ld:%d:buf[0-111]%d\n",si->wrAddr[si->wrFlag],si->BUsed_Size[si->wrFlag],si->wrFlag);
			if (ret == -1) {
				ErrorFlag = WRITE_LVM_ERR;
				//pthread_rwlock_wrlock(&si->RWlock_Recording);
				si->isRecording = 0;
				//pthread_rwlock_unlock(&si->RWlock_Recording);
				syslog(LOG_ERR,  "write lvm error, IPC:%s, errno:%u\n", si->cameraID, ErrorFlag);
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
	syslog(LOG_INFO,  "opening download stream, IPC:%s...", openargs.camerID);
	unsigned int handle;
	int i = 0;

	handle = openRecordSeg(openargs.camerID, openargs.beginTime, openargs.endTime, openargs.mode);
	if (handle == (unsigned int)-1) {
		syslog(LOG_ERR, "open download stream fail:error handle, IPC:%s, errno:%u.\n",openargs.camerID, ErrorFlag);
		return handle;
	}
	if ((i = initDownloadInfo(handle)) < 0)
	{
		syslog(LOG_ERR, "open download stream fail:max download streams, IPC:%s, errno:%u.\n",openargs.camerID, ErrorFlag);
		return -1;
	}
	//added by wsr 20121029
	pthread_rwlock_wrlock(&DInfo_PRW);
	strcpy(pDInfo[i]->CameraID, openargs.camerID);
	pthread_rwlock_unlock(&DInfo_PRW);
	//end
	syslog(LOG_INFO,  "open download stream sucess, IPC:%s, handle:0x%x.\n", openargs.camerID, handle);
	return handle;
}

READres
nvrproc_read(READargs readargs)
{
	//syslog(LOG_ERR,  "... read ...,handle  = %d\n", readargs.playHandle);
	int readLen = 0, i;
	i = findDownloadInfo(readargs.playHandle);
	if(i < 0)
	{
	    ErrorFlag = ERR_HANDLE;
		syslog(LOG_ERR,  "read data fail:error handle, handle:0x%x, errno:%u.\n", readargs.playHandle, ErrorFlag);
        bzero(&readres, sizeof(READres));
        return readres;
	}
	readLen = ReadStream(readargs.playHandle, readBuf, readargs.readSize, readargs.mode);

	//syslog(LOG_ERR,  "read %d bytes\n", readLen);
	if (readLen < 0) {
		syslog(LOG_ERR,  "read data fail, IPC:%s, errno:%u.\n", pDInfo[i]->CameraID, ErrorFlag);
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
	syslog(LOG_INFO,  "getting recordseg header, IPC:%s...", gethargs.camerID);
	headerInfo.nextBeginTime = _GetRecordSegHead(gethargs.camerID, &gethargs.beginTime, &gethargs.endTime, headBuf, &(headerInfo.data.data_len));
	if(headerInfo.nextBeginTime == ERR_RETURN)
	{
		syslog(LOG_ERR,  "get recordseg header fail, IPC:%s, errno:%u.\n", gethargs.camerID, ErrorFlag);	
		headerInfo.data.data_len = 0;
	}
	headerInfo.data.data_val = headBuf;
	headerInfo.beginTime = gethargs.beginTime;
	headerInfo.endTime = gethargs.endTime;
	syslog(LOG_INFO,  "get recordseg header success, IPC:%s.\n", gethargs.camerID);
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
		syslog(LOG_ERR,  "search record fail, IPC:%s, errno:%u.\n", searchargs.camerID, ErrorFlag);		
	}
	recordInfo.cmmnArgs.beginTime = searchargs.beginTime;
	recordInfo.cmmnArgs.endTime = searchargs.endTime;
	//strcpy(recordInfo.describe,si.des);
	recordInfo.describe = si.des;
	recordInfo.describeLen = strlen(si.des);
	
	//syslog(LOG_ERR,  "search record successfully in record volume %s!", searchargs.camerID);
	return recordInfo;
}

RECORDBYORDERres
nvrproc_searchrecordbyorder(RECORDBYORDERargs searchargs)
{    
	//syslog(LOG_INFO,  "%s start to search record by order!", searchargs.camerID);
	RECORDBYORDERres recordInfo;
	seginfo si;
	recordInfo.flag=GetRecordInfoOnebyOne(searchargs.camerID, &searchargs.beginTime, &searchargs.endTime, &si, &searchargs.num);
	if(recordInfo.flag == ERR_RETURN)
	{
		syslog(LOG_ERR, "search record fail, IPC:%s, errono:%u.\n", searchargs.camerID, ErrorFlag);
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
	syslog(LOG_INFO,  "set record info, IPC:%s\n", setrecinfoargs.cmmnArgs.camerID);
	return 1;
}

VOLUMinfo
nvrproc_getvolumeinfo(unsigned int camerid)
{
	syslog(LOG_INFO,  "get volume info, IPC:%s\n", camerid);
	static VOLUMinfo voluminfo; 
	bzero(&voluminfo, sizeof(VOLUMinfo));
	return voluminfo;
}

unsigned int
nvrproc_delete(DELargs delargs)
{
	syslog(LOG_INFO,  "deleting record segment, IPC:%s...", delargs.camerID);
	uint32_t ret;
	ret = DeleteRecordSeg(delargs.beginTime, delargs.endTime, delargs.camerID);
	if(ret < 0)
	{
		syslog(LOG_ERR, "delete record segment fail, IPC:%s, errno:%u.\n", delargs.camerID, ErrorFlag);
		return ret;
	}
	syslog(LOG_INFO,  "delete record segment success, IPC:%s.\n", delargs.camerID);
	return ret;
}


unsigned int
nvrproc_login(LOGINargs loginargs)
{
	syslog(LOG_INFO,  "login, IP:%s, PORT:%u...", ClientIP, ClientPort);
	clearInactiveStreams();
	//get_lv_name(lv, MAX_LV_NUM);
	//if(num<=0)return -1;
	if (loginargs.userName == NULL || loginargs.pwd == NULL)
	{
		syslog(LOG_ERR, "login fail:empty usrname or password, IP:%s, PORT:%u.\n", ClientIP, ClientPort);
		return 1;
	}
	if (strcmp(loginargs.userName, "admin")
	    || strcmp(loginargs.pwd, "password"))
	{	
		syslog(LOG_ERR, "login fail:error usrname or password, IP:%s, PORT:%u.\n", ClientIP, ClientPort);
		return 1;
	}
    syslog(LOG_INFO,  "login sucess, IP:%s, PORT:%u.\n", ClientIP, ClientPort);
	return 0;
}

int
nvrproc_logout(unsigned int userid)
{
	syslog(LOG_INFO,  "logout, id:%u.\n", userid);

	return 0;
}

unsigned long
nvrproc_getlasterror()
{
	syslog(LOG_INFO,  "get last error, erron:%u.\n", ErrorFlag);
	return ErrorFlag;
}

unsigned int
nvrproc_getrecsize(GETRECSIZEargs getRecSizeArgs)
{
	syslog(LOG_INFO,  "getting recordseg size, IPC:%s...", getRecSizeArgs.camerID);
	unsigned int recordSize = 0;
	unsigned int beginTime, endTime;
	beginTime = getRecSizeArgs.beginTime;
	endTime = getRecSizeArgs.endTime;
	headerInfo.nextBeginTime = _GetRecordSegHead(getRecSizeArgs.camerID, &beginTime, &endTime, headBuf, &recordSize);
	if (headerInfo.nextBeginTime == ERR_RETURN)
	{
		syslog(LOG_ERR, "get recordseg size fail, IPC:%s, erron:%u.\n", getRecSizeArgs.camerID, ErrorFlag);
		return 0;
	}
	if (beginTime < getRecSizeArgs.beginTime)
		beginTime = getRecSizeArgs.beginTime;
	if (endTime > getRecSizeArgs.endTime)
		endTime = getRecSizeArgs.endTime;
	recordSize = GetRecordSegSize(getRecSizeArgs.camerID, beginTime, endTime);
	if (recordSize < 0)
	{
		syslog(LOG_ERR, "get recordseg size fail, IPC:%s, erron:%u.\n", getRecSizeArgs.camerID, ErrorFlag);
		return 0;
	}
	
	syslog(LOG_INFO,  "get recordseg size success, IPC:%s.\n", getRecSizeArgs.camerID);
	return recordSize;
}

int
nvrproc_creatrecvol(CREATRECVOLargs creatRecVolArgs)
{
	syslog(LOG_INFO,  "creating recordvol, IPC:%s...",creatRecVolArgs.name);
	int ret = 0, i;
	uint64_t volSize = creatRecVolArgs.blockSize;
	volSize *= creatRecVolArgs.blocks; 
	if(initCameraInfos()<0){
        syslog(LOG_ERR,  "create recordvol fail:init camerainofs error!");
        return -1;
    } 
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
        	syslog(LOG_ERR,  "create recordvol fail, IPC:%s, errno:%u.\n",creatRecVolArgs.name, ErrorFlag);
        	return ret;
        }

        lv[i].length = get_free_vol_size(lv[i].lv_name);
        syslog(LOG_ERR,  "create recordvol sucess, IPC:%s, vediovol:%s.\n",creatRecVolArgs.name, lv[i].lv_name);
    }
    else
    {
        ret = CreateRecordVol(creatRecVolArgs.volumeid,
		      creatRecVolArgs.name,
		      creatRecVolArgs.alias,
		      creatRecVolArgs.savedDays, creatRecVolArgs.delPolicy, creatRecVolArgs.encodeType, creatRecVolArgs.blocks);
        if(ret < 0)
        {
        	syslog(LOG_ERR,  "create recordvol fail, IPC:%s, errno:%u.\n",creatRecVolArgs.name, ErrorFlag);
        	return ret;
        }
        syslog(LOG_INFO,  "create recordvol success, IPC:%s, vediovol:%s.\n",creatRecVolArgs.name, creatRecVolArgs.volumeid);
    }
	return ret;
}

int
nvrproc_delrecvol(DELRECVOLargs delRecVolArgs)
{
	syslog(LOG_INFO,  "deleting recordvol, IPC:%s...", delRecVolArgs.cameraID);
	int ret = 0, i;
    if(initCameraInfos()<0){
        syslog(LOG_ERR,  "delete recordvol fail:init camerainofs error!");
        return -1;
    } 
	ret = DeleteRecordVol(delRecVolArgs.cameraID, delRecVolArgs.mode);
	if(ret < 0)
	{
		syslog(LOG_ERR,  "delete recordvol fail, IPC:%s, errno:%u.\n",delRecVolArgs.cameraID, ErrorFlag);
		return ret;
	}
	for (i = 0; i < MAX_LV_NUM; i++)
		lv[i].length = get_free_vol_size(lv[i].lv_name);
	syslog(LOG_INFO,  "delete recordvol success, IPC:%s.\n",delRecVolArgs.cameraID);
	return ret;
}

void
clearInactiveStreams()
{
	syslog(LOG_DEBUG,  "clearing inactive download streams...");
	int i = 0; 
	for (; i < MAX_STREAMS; i++) { 
		if (pDInfo[i] && (time(NULL) - pDInfo[i]->lastReadTime > 30))
		{
			syslog(LOG_INFO, "closing a inactive download stream, IPC:%s, handle:0x%x.", pDInfo[i]->CameraID, pDInfo[i]->dHandle); 
    		if(CloseRecordSeg(pDInfo[i]->dHandle, NULL) < 0){
    			syslog(LOG_ERR,  "close the download stream fail, IPC:%s, handle:0x%x, errno:%u.",pDInfo[i]->CameraID, pDInfo[i]->dHandle, ErrorFlag);
    		} else {
                syslog(LOG_INFO,  "close the download stream success, IPC:%s, handle:0x%x.",pDInfo[i]->CameraID, pDInfo[i]->dHandle);
            }
		    releaseDownloadInfo(&pDInfo[i]);
		}
	}
    syslog(LOG_DEBUG,  "clear inactive download streams sucess.");
}

void *
WriteTnodeThread(void *arg)
{
	syslog(LOG_INFO,  "start write tnode thread.");
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
			syslog(LOG_ERR,  "write back tnodes fail, IPC:%s, errno:%u.", streamInfos[i]->cameraID, ErrorFlag);
		}
		streamInfos[i]->count = 0;
		if (put_vnode(streamInfos[i]->sbinfo, streamInfos[i]->v, NULL, streamInfos[i]->ID) < 0) {
			syslog(LOG_ERR, "put vnode fail, IPC:%s, errno:%u.", streamInfos[i]->cameraID, ErrorFlag);
		}
		pthread_rwlock_unlock(&SInfo_PRW);

	}
}
 
void *
VolOpThread(void *arg)
{
	syslog(LOG_INFO,  "start volume operation thread.");
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
		syslog(LOG_ERR,  "msgget failed with error: %d. *exit*", errno);
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
				syslog(LOG_ERR,  "create record volume %s in %s faile.(errno:%u).", creatMsg.name, creatMsg.volumeid, ErrorFlag);
			}
			if (msgsnd(sendQID, (void *)&resMsg, sizeof(int), 0) == -1) {
				syslog(LOG_ERR, "send msg failed when create record volume %s in %s.", creatMsg.name, creatMsg.volumeid);
				break;
			}
			continue;
		}

		if (msgrcv(recvQID, (void *)&delMsg, sizeof(DelRecVolMsg) - sizeof(long int), DEL_REC_VOL_ARGS, IPC_NOWAIT) != -1) {
			resMsg.msgType = DEL_REC_VOL_RES;
			resMsg.result = DeleteRecordVol(delMsg.cameraID, delMsg.mode);
			if (msgsnd(sendQID, (void *)&resMsg, sizeof(int), 0) == -1) {
				fprintf(stderr, "send msg failed\n");
				syslog(LOG_ERR, "send msg failed when delete record volume %s.", delMsg.cameraID);
				break;
			}
			continue;
		}

		if (msgrcv(recvQID, (void *)&delVideoMsg, sizeof(DelVideoVolMsg) - sizeof(long int), DEL_VIDEO_VOL_ARGS, IPC_NOWAIT) != -1) {
			resMsg.msgType = DEL_VIDEO_VOL_RES;
			resMsg.result = DeleteVideoVol(delVideoMsg.volName);
			if (msgsnd(sendQID, (void *)&resMsg, sizeof(int), 0) == -1) {
				fprintf(stderr, "send msg failed\n");
				syslog(LOG_ERR, "send msg failed when delete videovol %s.", delVideoMsg.volName);
				break;
			}
			continue;
		}

		sleep(1);
	}
	syslog(LOG_ERR, "VolOPThread exit!");
	pthread_exit(0);
}

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
    bzero(lv_info, max*sizeof(LvInfo));
    setenv("LVM_SUPPRESS_FD_WARNINGS", "1", 1);
	if ((fp = popen("lvs -o vg_name,lv_name --noheadings --separator /", "r")) != NULL) {
        syslog(LOG_INFO,  "show vediovol list:");
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
                syslog(LOG_INFO, "vediovol_%d:\t%s\t%ld",num,lv_info[num].lv_name,lv_info[num].length);
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
				 syslog(LOG_ERR, "opening vediovol %s error!",lv_name);
                 return -1;
            }
            if((vbitmap=(char *)malloc(sizeof(char) *(MaxUsers / 8)))==NULL){
                ErrorFlag=MALLOC_ERR;
                close(fd);
				syslog(LOG_ERR, "malloc error!");
                return -1;
            }
            if(_read(fd, vbitmap, MaxUsers / 8, VBitmapAddr)<0){
                 close(fd);
                 free(vbitmap);
				 syslog(LOG_ERR, "read vbitmap error!");
                 return -1;
            }
            count=0;
            while(count<MaxUsers) {
                if(bit(vbitmap,count)){
                      if(_read(fd,buf,Vnode_SIZE,VnodeAddr+count*Vnode_SIZE)<0){
                          close(fd);
                          free(vbitmap);
				          syslog(LOG_ERR, "read vode error!");
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

void *
UpdateThread(void *arg)
{
    syslog(LOG_INFO,  "start update thread.");
    while(1) {
        sleep(120);
        clearInactiveStreams(); 
    }
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
        syslog(LOG_INFO, "start nvrd (pid:%u) success! ",pid);
        fp = fopen(PID_FILE, "w+");
        fputs(cmd, fp);
        fclose(fp);
        return 0;
    }
    if ((fp = fopen(PID_FILE, "r")) == NULL) 
        
    {
        syslog(LOG_ERR, "open pidfile error!");
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
        syslog(LOG_ERR, "call popen failed!");
        return -1;
    }
    else
    { 
        while(fgets(cmd, 255, fp) != NULL)
        {
            
            sscanf(cmd, "%u", &file_pid);
            syslog(LOG_ERR, "start failed! nvrd (pid:%u) is exist!",file_pid );
            fclose(fp);
            return 1;
        }
        fclose(fp); 
        sprintf(cmd, "%u\0", pid);
        fp = fopen(PID_FILE, "w+");
        fputs(cmd, fp);
        fclose(fp);
        syslog(LOG_INFO, "start nvrd (pid:%u) success! ",pid);
        return 0;
    }
}

int tcp_create()
{
    int listenfd;
    struct sockaddr_in servaddr;
    if((listenfd=socket(AF_INET,SOCK_STREAM,0))<0){
		close(listenfd);
		return -1;
	}
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(SERV_PORT);
	if(bind(listenfd,(struct sockaddr *) &servaddr,sizeof(servaddr))<0){
		printf("error in binding\n");
		close(listenfd);
		return -1;
	}    
	if(listen(listenfd,10)<0){
		printf("error in listening\n");
		close(listenfd);
		return -1;
	}
    return listenfd;
}

int tcp_send(int fd, char *buf, int len, int flags)
{
    int nsend=0,send_count=0;
    int length =len;
 
    if(buf==NULL)
        return -1;
  
    while(length > 0)
    {
        nsend =send(fd, buf+send_count, length, flags);
        if(nsend == 0)
            return 0;
         
        if(nsend < 0)
        {
             perror("Failed send(),error code:");
             return -1;
        }
        else
        {
         length -= nsend;
         send_count += nsend;
        }
    }
    return send_count;
}

int tcp_recv(int fd, char *buf, int len, int flags)
{
     
    int nrec=0,recv_count=0;
    int length =len;
 
    if(buf==NULL)
        return -1;
  
    while(length > 0)
    {
        nrec =recv(fd, buf+recv_count, length, flags);
        if(nrec == 0)
            return 0;
         
        if(nrec < 0)
        {
             perror("Failed recv(),error code:");
             return -1;
        }
        else
        {
         length -= nrec;
         recv_count += nrec;
        }
    }
    return recv_count;
}
int enc_rec_result(char *presult, int* pret, unsigned int* perron)
{
    char headchar = 'h';
    char tailchar  = 't';
    memcpy(presult, &headchar, sizeof(char));
    presult += sizeof(char);
    memcpy(presult, pret, sizeof(int));
    presult += sizeof(int);
    memcpy(presult, perron, sizeof(unsigned int));
    presult += sizeof(unsigned int);
    memcpy(presult, &tailchar, sizeof(char)); 
    return 0;
} 
int dec_rec_head(char *phead, unsigned int* precordhandle, unsigned int* pdatalen, unsigned int* pbegintime)
{
    char headchar = '\0';
    char tailchar  = '\0';
    memcpy(&headchar, phead, sizeof(char));
    if (headchar != 'h') 
        return -1;
    phead += sizeof(char); 
    memcpy(precordhandle, phead, sizeof(unsigned int));
    phead += sizeof(unsigned int);     
    memcpy(pdatalen, phead, sizeof(unsigned int));
    phead += sizeof(unsigned int); 
    memcpy(pbegintime, phead, sizeof(unsigned int));
    phead += sizeof(unsigned int);
    memcpy(&tailchar, phead, sizeof(char)); 
    if (tailchar != 't') 
        return -1;
    return 0;

}

int record (int sockfd ) 
{ 
    int rc, ret;
    unsigned int erron = 0;
    char phead[REC_HEAD_SIZE];
    char presult[REC_RESULT_SIZE];
    char data[MAX_RECORD_DATA_SIZE];
    unsigned int datalen=0, handle=0, begintime=0;
    WRITEargs writeargs;
    bzero(phead, REC_HEAD_SIZE);
    bzero(presult, REC_RESULT_SIZE); 
    rc = tcp_recv(sockfd, phead, REC_HEAD_SIZE, 0);
    if(rc <= 0)
    { 
         return -1;
    }
    if (dec_rec_head(phead, &handle, &datalen, &begintime) < 0) 
    {
        syslog(LOG_ERR, "dec_rec_head error!");
        return -1;
    }
    rc = tcp_recv(sockfd, data, datalen, 0);
    if(rc <= 0)
    {
        return -1;
    }
    writeargs.recordHandle = handle;
    writeargs.beginTime = begintime;
    writeargs.data.data_val = data;
    writeargs.data.data_len = datalen;
    ret =  nvrproc_write(writeargs);
    if(ret < 0)
        erron = ErrorFlag;
    enc_rec_result(presult, &ret, &erron);
    rc = tcp_send(sockfd, presult, REC_RESULT_SIZE, 0);
    if(rc <= 0)
    { 
         return -1;
    } 
    return ret; 
}  

void *recordthread(void* arg)
{
      int socket=(int)arg;
      int ready;
      unsigned int last_request_time;
      struct pollfd pfd;
      pfd.events = POLLIN;
	  pfd.fd = socket;
      while(1) {
        ready = poll(&pfd, 1, 3000); 
        if (ready < 0) {
            break;
        }
        if (ready == 0) {

            if ((time(NULL) - last_request_time) > 30) { //if no data come for 30s, close connect
                syslog(LOG_ERR, "no data come exceed 30 seconds, sockfd:%d", socket);
                break;
            }
            continue;  
        }
        last_request_time = time(NULL);
        if(record(socket) < 0) {
            break;
        }
      }
      close(socket);
      syslog(LOG_INFO, "close record socket %d.", socket);
}

void *SerialRecordThread(void* arg)
{
    syslog(LOG_INFO,  "start record thread.");

    int i, maxi, listenfd, connfd, sockfd;
    int nready;
    ssize_t n; 
    socklen_t clilen;
    struct pollfd client[OPEN_MAX];
    struct sockaddr_in cliaddr;
    listenfd = (int)arg;
    client[0].fd = listenfd;
    client[0].events = POLLIN;
    for (i =1; i < OPEN_MAX; i++)
        client[i].fd = -1;
    maxi = 0;
    while(1) { 
        nready = poll(client, maxi + 1, -1); 
        if (nready == 0) {
            continue;
        }
        if (client[0].revents == POLLIN) { 
            clilen = sizeof(cliaddr);
            connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
            if (connfd < 0) {
                perror("server accept:");
                continue;
            }
            for (i = 1; i < OPEN_MAX; i++) {
                if (client[i].fd < 0) {
                    client[i].fd = connfd;
                    syslog(LOG_DEBUG,  "create new record socket.");
                    break;
                }
            }
            if (i == OPEN_MAX)
                syslog(LOG_INFO,  "too many record socket.defused.");
            client[i].events = POLLIN;
            if (i > maxi)
                maxi = i;  /*max index in client[] array*/
            if (--nready <=0)
                continue;       /*no more readable descriptors*/
        } 
        for (i = 1; i <= maxi; i++) { 
            if ( client[i].revents == POLLIN) {
                if (record(client[i].fd) < 0) {
                    close(client[i].fd);
                    client[i].fd = -1;
                }
            }
            else
                continue;
            if (--nready <= 0)
                break;
        }
    }
}

void *ParallelRecordThread(void* arg)
{
    syslog(LOG_INFO, "start parallel record thread.");
    int server_socket,client_socket,result,len;
    struct sockaddr_in clientaddr;
    pthread_t pt;  
    server_socket = (int)arg; 
    while(1)
    {
        if((client_socket = accept(server_socket, (struct sockaddr*)&clientaddr, (socklen_t*)&len))==0)
        {
            perror("server accept:");
            continue; 
        }
 
        if((result=pthread_create(&pt, NULL, recordthread, (void *)client_socket))!=0)
        {
            perror("pthread create:");
            continue; 
        }
        pthread_detach(pt);
        syslog(LOG_DEBUG, "create new record thread, sockfd:%d.", client_socket);
    }    
}

