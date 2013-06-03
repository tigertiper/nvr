#include "init.h" 
#include "nvr_srp.h"
#include "rd_wr.h"
#include "util.h"

#define PRC_SVC

static READres readres; 
static HEADERinfo headerInfo; 
static char readBuf[MAX_READ_SIZE];
static char headBuf[MAX_HEADER_LENGTH]; 


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
	streamInfos[i]->writeTime = 0;
    
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
	int i = 0, writeCost = 0;
	struct timeval time2, time1;
	//gettimeofday(&time2,NULL);

	i = findStreamInfo(writeargs.recordHandle);
	if (i < 0 || writeargs.data.data_len <= 0) {
		ErrorFlag = ERR_HANDLE;
		syslog(LOG_ERR,   "write error: error handle 0x%x.", writeargs.recordHandle);
		return -1;
	}

	//write to buf when the time is changed or buf is full
	if (streamInfos[i]->writeTime !=0 && ((streamInfos[i]->writeTime != writeargs.beginTime ) \
            || ((streamInfos[i]->writeDataLen + writeargs.data.data_len) > STREAM_BUFFER_SIZE) )) {
            
		syslog(LOG_DEBUG,	"...nvrproc_write, cameraID:%s, handle:0x%x, begintime:%u...", streamInfos[i]->cameraID, streamInfos[i]->handle, writeargs.beginTime);
		if (writeTnodeToBuf(streamInfos[i], streamInfos[i]->writeTime, streamInfos[i]->writeDataLen) < 0) {
			syslog(LOG_ERR,   "write error: write tnode to buf fail, IPC:%s, errno:%u.", streamInfos[i]->cameraID, ErrorFlag);
			return -1;
		}
		
		gettimeofday(&time1, NULL);
		//printf("writetnode cost %d : %10ld\n",time1.tv_sec-time2.tv_sec,time1.tv_usec-time2.tv_usec);
		
		if (writeToBuf(streamInfos[i], streamInfos[i]->writeData, streamInfos[i]->writeDataLen) < 0) {
			ErrorFlag = WRITE_LVM_ERR;
			syslog(LOG_ERR,   "write error: write data to buf fail, IPC:%s, errno:%u.", streamInfos[i]->cameraID, ErrorFlag);
			return -1;
		}
		
		gettimeofday(&time2, NULL);
		if (time1.tv_sec == time2.tv_sec)
			writeCost = time2.tv_usec - time1.tv_usec;
		else
			writeCost = (time2.tv_sec * 1000000) + time2.tv_usec - time1.tv_usec - time1.tv_sec * 1000000;
		if (writeCost > 1000)
			syslog(LOG_DEBUG,   "write data cost %10ld us, IPC:%s",  writeCost, streamInfos[i]->cameraID);

		//printf("... write %d bytes,time = %d ...",writeargs.data.data_len,writeargs.beginTime);
		streamInfos[i]->v->storeAddr += streamInfos[i]->writeDataLen;
		
		bzero(streamInfos[i]->writeData, streamInfos[i]->writeDataLen);
		streamInfos[i]->writeDataLen = 0;
		streamInfos[i]->writeTime = writeargs.beginTime;
		memcpy(streamInfos[i]->writeData + streamInfos[i]->writeDataLen, writeargs.data.data_val, writeargs.data.data_len);
		streamInfos[i]->writeDataLen += writeargs.data.data_len;

		return writeargs.data.data_len;
	}

	streamInfos[i]->writeTime = writeargs.beginTime;
	memcpy(streamInfos[i]->writeData + streamInfos[i]->writeDataLen, writeargs.data.data_val, writeargs.data.data_len);
	streamInfos[i]->writeDataLen += writeargs.data.data_len; 
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
				//syslog(LOG_ERR,  "write lvm error, IPC:%s, errno:%u\n", si->cameraID, ErrorFlag);
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

unsigned int
nvrproc_login(LOGINargs loginargs)
{
	syslog(LOG_INFO,  "login, IP:%s, PORT:%u...", ClientIP, ClientPort);
	clearInactiveStreams();
    if(initCameraInfos()<0){
        syslog(LOG_ERR,  "login fail:init cameraInfos error, IP:%s, PORT:%u.", ClientIP, ClientPort);
        return 1;
    } 
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

int
nvrproc_delvedvol(DELVEDVOLargs delVedVolArgs)
{
	syslog(LOG_INFO,  "deleting vediovol, volname:%s...", delVedVolArgs.volname);
	int ret = 0; 
    char cmd[256];
	ret = DeleteVideoVol(delVedVolArgs.volname);
	if(ret < 0)
	{
		syslog(LOG_ERR,  "delete vediovol fail, volname:%s, errno:%u.\n",delVedVolArgs.volname, ErrorFlag);
		return ret;
	}
    if(delVedVolArgs.mode) 
    {
        sprintf(cmd, "lvremove -f %s >/dev/null 2>&1", delVedVolArgs.volname);
        system(cmd);
    }
	syslog(LOG_INFO,  "delete vediovol success, volname:%s.\n",delVedVolArgs.volname);
    
	return ret;
}

