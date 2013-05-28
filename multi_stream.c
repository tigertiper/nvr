#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "multi_stream.h"
#include "rd_wr.h"
pthread_rwlock_t SInfo_PRW = PTHREAD_RWLOCK_INITIALIZER;
pthread_rwlock_t DInfo_PRW = PTHREAD_RWLOCK_INITIALIZER;
unsigned int loginList[MAX_LOGINS] = { 0 };
int
findStreamInfo(unsigned int handle) 
{
	int i = 0;
	
	    //LOCKINFO("read lock...");
	    pthread_rwlock_rdlock(&SInfo_PRW);
	
	    //LOCKINFO("get read lock...");
	    i = HASH(handle);
	for (; i < MAX_STREAMS + HASH(handle); i++)
		 {
		if (!streamInfos[HASH(i)])
			continue;
		if (streamInfos[HASH(i)]->handle == handle)
			 {
			pthread_rwlock_unlock(&SInfo_PRW);
			
			    //LOCKINFO("read unlock...");
			    return HASH(i);
			}
		}
	pthread_rwlock_unlock(&SInfo_PRW);
	
	    //LOCKINFO("read unlock...");
	    return -1;
}

int
findStreamInfoByCID(char* cameraID) 
{
	int i = 0;
	pthread_rwlock_rdlock(&SInfo_PRW);
	for (; i < MAX_STREAMS ; i++)
	 {
		if (!streamInfos[i])
			continue;
		if (strcmp(streamInfos[i]->cameraID, cameraID) == 0 )
		 {
			pthread_rwlock_unlock(&SInfo_PRW);
			return i;
		}
	}
	pthread_rwlock_unlock(&SInfo_PRW);
	return -1;
}

int
allocStreamInfo(unsigned int handle) 
{
	pthread_rwlock_wrlock(&SInfo_PRW);
	int i = HASH(handle);
	for (; i < MAX_STREAMS + HASH(handle); i++)
	 {
		if (!streamInfos[HASH(i)])
			break;
	}
	if (i == MAX_STREAMS + HASH(handle))
	{
		ErrorFlag = MAX_CAMERA;
		pthread_rwlock_unlock(&SInfo_PRW);
		return -1;
	}
	
	 i = HASH(i);
	streamInfos[i] = (StreamInfo *) malloc(sizeof(StreamInfo));
    if (streamInfos[i] == NULL) {
        pthread_rwlock_unlock(&SInfo_PRW);
        ErrorFlag = MALLOC_ERR;
        return -1;
    }
	pthread_rwlock_unlock(&SInfo_PRW);
	initWriteStream(handle, &(streamInfos[i]->v), &(streamInfos[i]->ID), &(streamInfos[i]->sbinfo), &(streamInfos[i]->vi));
	streamInfos[i]->wrAddr[0] = streamInfos[i]->v->storeAddr;
	streamInfos[i]->count = 0;
	streamInfos[i]->lastRecordTime = time(NULL);
	streamInfos[i]->handle = handle;
	streamInfos[i]->wrFlag = 0;
	streamInfos[i]->isRecording = 0;
	streamInfos[i]->BTotal_Size[0] = STREAM_BUFFER_SIZE;
	streamInfos[i]->BTotal_Size[1] = STREAM_BUFFER_SIZE;
	streamInfos[i]->BEmpty_Size[0] = STREAM_BUFFER_SIZE;
	streamInfos[i]->BEmpty_Size[1] = STREAM_BUFFER_SIZE;
	streamInfos[i]->BUsed_Size[0] = 0;
	streamInfos[i]->BUsed_Size[1] = 0;
    streamInfos[i]->wrThread = 0;
	pthread_rwlock_init(&streamInfos[i]->RWlock_Recording, NULL);
	pthread_mutex_init(&streamInfos[i]->Mutex_Buffer[0], NULL);
	pthread_mutex_init(&streamInfos[i]->Mutex_Buffer[1], NULL);
	return i;
}

void
releaseStreamInfo(StreamInfo ** si)
{
	if(*si == NULL)
		return;
	pthread_rwlock_wrlock(&SInfo_PRW);
	pthread_mutex_destroy(&(*si)->Mutex_Buffer[1]);
	pthread_mutex_destroy(&(*si)->Mutex_Buffer[0]);
	pthread_rwlock_destroy(&(*si)->RWlock_Recording);
	bzero((*si), sizeof(StreamInfo)); 
	free(*si);
	*si = NULL;
	pthread_rwlock_unlock(&SInfo_PRW);
    return;
}
int
initDownloadInfo(unsigned int dhandle) 
{
	pthread_rwlock_wrlock(&DInfo_PRW);
	int i = HASH(dhandle);
	for (; i < MAX_STREAMS + HASH(dhandle); i++)
		 {
		if (!pDInfo[HASH(i)]) {
			pDInfo[HASH(i)] = (DownloadInfo *) malloc(sizeof(DownloadInfo));
			if (!pDInfo[HASH(i)]) {
				pthread_rwlock_unlock(&DInfo_PRW);
                ErrorFlag = MALLOC_ERR;
				return -1;
			}
			pDInfo[HASH(i)]->dHandle = dhandle;
			pDInfo[HASH(i)]->lastReadTime = time(NULL);
			//added by wsr 20121029
			memset(pDInfo[HASH(i)]->CameraID, 0, CNameLength);
			//end
			pthread_rwlock_unlock(&DInfo_PRW);
			return HASH(i);
		}
		}
	pthread_rwlock_unlock(&DInfo_PRW);
	ErrorFlag = MAX_CAMERA;
	return -1;
}
int
findDownloadInfo(unsigned int dhandle) 
{
	int i = HASH(dhandle);
	pthread_rwlock_rdlock(&DInfo_PRW);
	for (; i < MAX_STREAMS + HASH(dhandle); i++)
		 {
		if (!pDInfo[HASH(i)])
			continue;
		if (pDInfo[HASH(i)]->dHandle == dhandle) {
			pthread_rwlock_unlock(&DInfo_PRW);
			return HASH(i);
		}
		}
	pthread_rwlock_unlock(&DInfo_PRW);
	ErrorFlag = ERR_HANDLE;
	return -1;
}
 
void
releaseDownloadInfo(DownloadInfo** di) 
{
	if(*di == NULL)
	    return;
	pthread_rwlock_wrlock(&DInfo_PRW);
	bzero((*di), sizeof(DownloadInfo)); 
	free(*di);
	*di = NULL;
	pthread_rwlock_unlock(&DInfo_PRW);
	return;
}

