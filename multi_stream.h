#ifndef _MULTI_STREAM_H
#define _MULTI_STREAM_H

#include <pthread.h>
#include "info.h"
extern const unsigned int StoreBufferSize;

#define MAX_CAMERA 100
#define MAX_LOGINS 1024
#define MAX_STREAMS 100
#define MAX_CAMERA_NUMS 100
#define CAMERAIDLEN 256
#define STREAM_BUFFER_SIZE 10*1024*1024
#define HASH(hd) (((unsigned int)hd%MAX_STREAMS))


#define MAX_HEADER_LENGTH 10240
#define LVMTESTNAME "/dev/vg01/lv02"
#define MAX_READ_SIZE 5*1024*1024
#define MAXLINE 512
#define MAX_LV_NUM 256

#define STREAM_STA_FILE "/opt/HTRaid/conf/stream_status.conf"

#ifndef LVINFO_
#define LVINFO_
typedef struct {
	char lv_name[CNameLength];
	long long length;
} LvInfo;
LvInfo lv[MAX_LV_NUM];
#endif

#ifndef STREAMINFO
#define STREAMINFO
/*Record the infomation of one stream*/ 
struct StreamInfo {
	char cameraID[CAMERAIDLEN];
	unsigned int handle;
	vnode * v;
	int ID;
	_sbinfo sbinfo;
	_vnodeInfo vi;
	uint64_t wrAddr[2];
	int count;			//计时器，用于记录tnode缓存数目
	tnode t[WriteLen];		//时间缓存空间
	unsigned int lastRecordTime;
	int BFlag;			//index for the RecordBuffer array
	int wrFlag;
	char RecordBuffer[2][STREAM_BUFFER_SIZE];	//two buffer,  for store data from the same time in turn
	unsigned int BTotal_Size[2];	//total size of RecordBuffer 
	unsigned int BUsed_Size[2];	//used space of RecordBuffer
	unsigned int BEmpty_Size[2];	//empty space of RecordBuffer
	pthread_mutex_t Mutex_Buffer[2];
	pthread_rwlock_t RWlock_Recording;
	int isRecording;		//represent the status of record operation
	pthread_t wrThread;
};
typedef struct StreamInfo StreamInfo;

#endif				/*  */
    
#ifndef STREAMINFOS
#define STREAMINFOS
    /*
       point the StreamInfo, it  will be allocated when vedio stream is started, and will be free when the 
       stream is stoped.
     */ 
    StreamInfo * streamInfos[MAX_STREAMS];

#endif				/*  */
    
#ifndef PTHREAD_RWLOCK_SINFO_
#define PTHREAD_RWLOCK_SINFO_
//pthread_rwlock_t SInfo_PRW = PTHREAD_RWLOCK_INITIALIZER;
#endif				/*  */
    
#ifndef DOWNLOAD_INFO_
#define DOWNLOAD_INFO_
    struct DownloadInfo {
    unsigned int dHandle;
    unsigned int lastReadTime;
	//added by wsr 20121029
	char CameraID[CNameLength];
	//end
    
	//int isDownloading;
};
typedef struct DownloadInfo DownloadInfo;

#endif				/*  */
    
#ifndef DINFO_
#define DINFO_
    DownloadInfo * pDInfo[MAX_STREAMS];

#endif				/*  */
    
#ifndef PTHREAD_RWLOCK_DINFO_
#define PTHREAD_RWLOCK_DINFO_
//pthread_rwlock_t DInfo_PRW;
#endif				/*  */
    
/*Found the index of streamInfos by handle*/ 
extern int findStreamInfo(unsigned int handle);	//called by record,stopRecord
extern int allocStreamInfo(unsigned int handle);	//called by startrecord
extern void releaseStreamInfo(StreamInfo ** si);	//called by stoprecord
void clearInactiveStreams();
extern int initDownloadInfo(unsigned int dhandle);
extern int findDownloadInfo(unsigned int dhandle);
extern int releaseDownloadInfo(unsigned int dhandle);
int writeToBuf(StreamInfo * si, char *data, int dataLen);
int write_data(_sbinfo, vnode *, _vnodeInfo, char *, unsigned int,
		StreamInfo *);
void *writeThread(void *arg);
int get_stream_infos();


#endif				/*  */
    
