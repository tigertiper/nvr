#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "Debug.h"
#include "multi_stream.h"
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
	if (*si)
		free(*si);
	*si = NULL;
	pthread_rwlock_unlock(&SInfo_PRW);
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


//wangchong
    int
releaseDownloadInfo(unsigned int dhandle) 
{
	int i = 0;
	i = findDownloadInfo(dhandle);
	if (i < 0) {
		printf("dhandle does not exist!\n");
		return -1;
	}
	pthread_rwlock_wrlock(&DInfo_PRW);
	if (pDInfo[i]) {
		bzero(pDInfo[i], sizeof(DownloadInfo));
		free(pDInfo[i]);
		pDInfo[i] = NULL;
	}
	pthread_rwlock_unlock(&DInfo_PRW);
	return 0;
}

int get_stream_infos()
{
	int i = 0;
	int fd = 0;
	char buf[MAXLINE];
	char status1[10], status2[10];
	char* pstr;
	strcpy(status1, "Active");
	strcpy(status2, "InActive");

 	if((fd = open(STREAM_STA_FILE, O_CREAT | O_WRONLY | O_TRUNC )) < 0)
	{
		perror("open file failed!");
		return -1;
	}
	
	for( i = 0; i < MAX_STREAMS; i ++)
	{
		pthread_rwlock_rdlock(&SInfo_PRW);
		if(streamInfos[i])
		{
			bzero(buf, MAXLINE);
			if(streamInfos[i]->lastRecordTime - (int)time(NULL) > 30)
				pstr = status2;
			else
				pstr = status1;
			sprintf(buf, "%s\tRECORD\t%s\t%u\n", streamInfos[i]->cameraID, pstr , streamInfos[i]->lastRecordTime);
			pthread_rwlock_unlock(&SInfo_PRW);		
			write(fd, buf, strlen(buf));
			continue;
		}
		pthread_rwlock_unlock(&SInfo_PRW);		
	}

		
	for( i = 0; i < MAX_STREAMS; i ++)
	{
		bzero(buf, MAXLINE);
		pthread_rwlock_rdlock(&DInfo_PRW);
		if(pDInfo[i])
		{
			bzero(buf, MAXLINE);
			if(pDInfo[i]->lastReadTime - (int)time(NULL) > 30)
				pstr = status2;
			else
				pstr = status1;
			sprintf(buf, "%s\tDOWNLOAD\t%s\t%u\n", pDInfo[i]->CameraID, pstr , pDInfo[i]->lastReadTime);
			pthread_rwlock_unlock(&DInfo_PRW);	
			write(fd, buf, strlen(buf));
			continue;
		}
		pthread_rwlock_unlock(&DInfo_PRW);		
	}

	close(fd);

	return 0;
}

