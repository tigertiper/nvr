#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "MediaSDK.h" 
#include "HCNetSDK.h"
#include <fcntl.h>

#define MAX_CAMERAID_LEN 100
#define MAX_CAMERAPORT_LEN 100
#define MAX_CAMERAIP_LEN 100
#define MAX_LINE_LEN 1024
#define MAX_CAMERATYPE_LEN 100
#define MAX_IPC_NUMS 20
#define MAX_STREAM_SIZE 3*1024*1024
#define ServerPort 8001
#define MAX_SENDBUFFER_LEN 10*1024
#define CAMERA_CONF "/root/camera.conf"

typedef struct RecordParas{
    char cameraID[MAX_CAMERAID_LEN];
    char cameraIP[MAX_CAMERAIP_LEN];
    int cameraPort;
    int cameraType;  
}RecordParas;
typedef struct HKcameraArgs{
	char NAR_cameraID[MAX_CAMERAID_LEN];
	unsigned int NAR_recordHandle;
	LONG *HK_streamHandle;
	int block_flag;
}HKcameraArgs;
typedef struct SendInfo{  
    int fd;
    char data[MAX_SENDBUFFER_LEN];
    int datalen;
    int sendflag;
    int stopSend;
    struct SendInfo *next;
}SendInfo;

/*HKcamera Thread*/
void *HK_Store_Thread(void * para);
void CALLBACK HK_RP_Exp_Callback(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser);
void CALLBACK HK_Store_CallBack(LONG streamHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize,void* dwUser);

/*Aerocamera Thread*/
void *Aero_Store_Thread(void *arg);
int Aero_Store_CallBack(void* handle, char *pData, int nSize);

/*NAR SDK*/
unsigned int NAR_startRecord(char *camerID, char *camerName,int recordType,int recVlmID, char *header,unsigned int headLen, char *desc, int descLen);
int NAR_stopRecord(unsigned int recordHandle);
int NAR_record(unsigned int recordHandle,const char *data ,int dataLen,unsigned int beginTime,unsigned int endTime);
char *readline(char *mbuf, int maxlen, FILE *fp);
void* MediaStoreThread(void *arg);

