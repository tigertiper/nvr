#include "MediaTranStore.h"
#include "MediaSDK.h"
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include "nvr.h"
#include "syslog.h"
#include "rd_wr.h"
#include "multi_stream.h"
#include "nvr_srp.h"
 
unsigned int NAR_startRecord(char *camerID, char *camerName,int recordType,
                 int recVlmID, char *header,unsigned int headLen, char *desc, int descLen)
{
     /*initial struct : createargs: start*/
     CREATEargs createargs; 
     createargs.recordType = recordType;
     createargs.camerID = camerID;
     createargs.camerAlias = camerName;
     createargs.recordType = recordType;
     createargs.header.header_val = header;
     createargs.header.header_len = headLen;
     createargs.describe = desc;
     createargs.describeLen = descLen;
     /*initial: end*/
     return nvrproc_create(createargs);
}
int NAR_stopRecord(unsigned int recordHandle)
{
    return nvrproc_close(recordHandle);
}

int NAR_record(unsigned int recordHandle,const char *data ,int dataLen,
          unsigned int beginTime,unsigned int endTime)
{ 
    WRITEargs writeargs; 
    writeargs.recordHandle = recordHandle;
    writeargs.beginTime = beginTime;
    writeargs.data.data_val = (char*)data;
    writeargs.data.data_len = dataLen;
    return nvrproc_write(writeargs); 
}
char *readline(char *mbuf, int maxlen, FILE *fp)
{
	int len=0,i=0;
	char *buf = (char*)malloc(maxlen);
	 if(NULL == buf)
	  {	
		perror("malloc:");
		return NULL;	
	  }	 
	 if(fgets(buf, maxlen, fp) == NULL)
		return NULL;


	while((*(buf+len) == 0x20 || *(buf+len) == '\t') && len<maxlen-1)
		len++;
	
    while(len<maxlen-1 && *(buf+len)!='\n' && *(buf+len)!='#' )
    	  {
  
		 *(mbuf+i)=*(buf+len);
        len++;
		  i++;
          }
    *(mbuf+i)='\0';
	 free(buf); 
    return mbuf;
}


void* MediaStoreThread(void *arg)
{ 
    RecordParas paras[MAX_IPC_NUMS];
    char LineString[MAX_LINE_LEN];
    int i=0;
    int linesnum=0;
    pthread_t id[MAX_IPC_NUMS];
    FILE* fp;
    char cameraType[MAX_CAMERATYPE_LEN], cameraPort[MAX_CAMERAPORT_LEN], cameraID[MAX_CAMERAID_LEN],cameraIP[MAX_CAMERAIP_LEN];  

    syslog(LOG_INFO, "start store_thread.\n");
 
    while(1){ 
            //read conf file 
            syslog(LOG_INFO, "open camera.conf...!\n");
            if((fp = fopen(CAMERA_CONF, "r"))<=0){
                syslog(LOG_INFO, "open camera.conf error!\n");
                return NULL;
            }
            syslog(LOG_INFO, "open camera.conf success!\n");
            for(i=0;i<MAX_IPC_NUMS;i++){ 
                memset(LineString, 0, MAX_LINE_LEN); 
                strcpy(cameraType, "N/A");
            	strcpy(cameraPort, "N/A");		
            	strcpy(cameraID, "N/A");
            	strcpy(cameraIP, "N/A");  
                if(readline(LineString, MAX_LINE_LEN, fp) == NULL){
        			break;
        		} 
                if(!strcmp(LineString, ""))
			       continue; 

                sscanf(LineString,"%s%s%s%s",cameraType, cameraID, cameraIP,cameraPort);
                if(!strcmp(cameraType,"N/A") || !strcmp(cameraID,"N/A") || !strcmp(cameraIP,"N/A") || !strcmp(cameraPort,"N/A")){
                    continue;
                } 
                paras[linesnum].cameraType = atoi(cameraType);
                paras[linesnum].cameraPort= atoi(cameraPort);
                strcpy(paras[linesnum].cameraID, cameraID);
            	strcpy(paras[linesnum].cameraIP, cameraIP);   
                linesnum++;
            } 
            fclose(fp); 
            
            for(i=0;i<linesnum;i++){
                     syslog(LOG_ERR,"cameraType:%d cameraID:%s cameraIP:%s cameraPort:%d\n",paras[i].cameraType,paras[i].cameraID,paras[i].cameraIP,paras[i].cameraPort);
                     switch(paras[i].cameraType){
                         case 1: //706camera
                             pthread_create(&id[i], NULL, Aero_Store_Thread, (void *)&paras[i]);
                             break;
                         case 2: //HK camera
                             pthread_create(&id[i], NULL, HK_Store_Thread, (void *)&paras[i]);
                              break;
                     }
            } 
             
            for(i=0;i<linesnum;i++){
                 pthread_join(id[i], NULL); 
            } 
            
    }
    return 0;
}

void *Aero_Store_Thread(void *arg)
{
    int sockfd; 
    int recVlmID = 0; 
	int headLen = 40;
    int recordhandle;
    char data[128];
    RecordParas* recordpara = (RecordParas*)arg; 

    while(1)
    {  
        sockfd=IPC_AddMediaSource(recordpara->cameraIP,recordpara->cameraPort,1,1,3);  //连接摄像头
        if(sockfd<0)
        {
            syslog(LOG_ERR,"connect Aero IPC %s error!\n", recordpara->cameraIP);
            continue;
        }
        else
        {
            syslog(LOG_ERR,"connect Aero IPC %s sucess!\n", recordpara->cameraIP);
        }
        
        if(IPC_StartTransmit(sockfd)<0)     //摄像头开始传输
        {
            syslog(LOG_ERR,"Aero IPC %s StartTransmit error!\n", recordpara->cameraIP);
            if(IPC_RemoveMediaSource(sockfd)<0)  //移除流媒体
            {
                syslog(LOG_ERR,"disconnect Aero IPC %s error!\n", recordpara->cameraIP);
            }
            else
            {
                //syslog(LOG_ERR,"disconnect IPC %s success!\n", recordpara->cameraIP);
            }
            continue;
        }
        else
        {
           syslog(LOG_ERR,"Aero IPC %s StartTransmit sucess!\n", recordpara->cameraIP);
        }
        
        recordhandle = NAR_startRecord( recordpara->cameraID, recordpara->cameraID,recordpara->cameraType, recVlmID,data,headLen , recordpara->cameraID, strlen(recordpara->cameraID));
        if(recordhandle < 0)
        {
            syslog(LOG_ERR,"Aero IPC %s start record in %s failed! errorCode:%lu\n",recordpara->cameraIP, recordpara->cameraID, nvrproc_getlasterror());
             
            if(IPC_StopTransmit(sockfd)<0)//停止传输
            {
                syslog(LOG_ERR,"Aero IPC %s StopTransmit error!\n", recordpara->cameraIP);
            }
            else
            {
                //syslog(LOG_ERR,"Aero IPC %s StopTransmit success!\n", recordpara->cameraIP);
            }
            if(IPC_RemoveMediaSource(sockfd)<0)  //移除流媒体
            {
                syslog(LOG_ERR,"disconnect Aero IPC %s error!\n", recordpara->cameraIP);
            }
            else
            {
                //syslog(LOG_ERR,"disconnect Aero IPC %s success!\n", recordpara->cameraIP);
            }
            continue;
        }
        else
        {
            syslog(LOG_ERR,"Aero IPC %s start record in %s success!\n", recordpara->cameraIP, recordpara->cameraID);
        }

        void* cbArgs = (void*) recordhandle;
        
        //starRecord
        if(IPC_SetGetDataCB(sockfd, &Aero_Store_CallBack, cbArgs)<0) //设置流回调函数
        {
            syslog(LOG_ERR,"Aero IPC %s SetGetDataCB error!\n", recordpara->cameraIP);
            if(NAR_stopRecord(recordhandle)<0)
            {
                syslog(LOG_ERR,"Aero IPC %s stop Record in %s error! errorCode:%lu\n", recordpara->cameraIP, recordpara->cameraID, nvrproc_getlasterror());
            }
            else
            {
                //syslog(LOG_ERR,"Aero IPC %s stop Record in %s success!\n", recordpara->cameraIP, recordpara->cameraID);
            }
            if(IPC_StopTransmit(sockfd)<0)//停止传输
            {
                syslog(LOG_ERR,"Aero IPC %s StopTransmit error!\n", recordpara->cameraIP);
            }
            else
            {
                //syslog(LOG_ERR,"Aero IPC %s StopTransmit success!\n", recordpara->cameraIP);
            }
            if(IPC_RemoveMediaSource(sockfd)<0)  //移除流媒体
            {
                syslog(LOG_ERR,"disconnect Aero IPC %s error!\n", recordpara->cameraIP);
            }
            else
            {
                //syslog(LOG_ERR,"disconnect Aero IPC %s success!\n", recordpara->cameraIP);
            }
            continue;
        }
        else
        {
            //syslog(LOG_ERR,"Aero IPC %s SetGetDataCB success!\n",recordpara->cameraIP);
        }
         
        if (IPC_SetGetDataCBRun(sockfd, 1)<0) //启动流回调函数线程，开始存储
        {
            syslog(LOG_ERR,"Aero IPC %s GetDataCB Run error!\n",recordpara->cameraIP);
                //stopRecord
            if(NAR_stopRecord(recordhandle))
            {
                syslog(LOG_ERR,"Aero IPC %s stop Record in %s error!\n", recordpara->cameraIP, recordpara->cameraID);
            }
            else
            {
                //syslog(LOG_ERR,"Aero IPC %s stop Record in %s success!\n", recordpara->cameraIP, recordpara->cameraID);
            } 
            
            if(IPC_StopTransmit(sockfd)<0)//停止传输
            {
                syslog(LOG_ERR,"Aero IPC %s StopTransmit error!\n", recordpara->cameraIP);
            }
            else
            {
                //syslog(LOG_ERR,"Aero IPC %s StopTransmit success!\n", recordpara->cameraIP);
            }

            if(IPC_RemoveMediaSource(sockfd)<0)  //移除流媒体
            {
                syslog(LOG_ERR,"disconnect Aero IPC %s error!\n", recordpara->cameraIP);
            }
            else
            {
               //syslog(LOG_ERR,"disconnect IPC %s success!\n", recordpara->cameraIP);
            }
            continue;
        } 
    }
}

int Aero_Store_CallBack(void* handle, char *pData, int nSize)
{
     //if get request,send to client
     //record by recordhandle 
   //  pthread_mutex_lock(&record_lock);

     if(NAR_record((unsigned int)handle , pData, nSize, time(NULL), time(NULL))<0)
     {
        syslog(LOG_ERR,"errorCode is %lu\n", nvrproc_getlasterror());
       // pthread_mutex_unlock(&record_lock);
        return -1;
     }
     //pthread_mutex_unlock(&record_lock);
     return 0;
}

void * HK_Store_Thread(void * para){

    /*info to login HK camera*/
    char HK_userName[] = "admin";
    char HK_password[] = "12345";
    int stopResult = 0;

    LONG lUserID = 0;

    LONG streamHandle = 0;
    //unsigned int NVR_recordHandle = 0;

    NET_DVR_DEVICEINFO_V30 struDeviceInfo;
    NET_DVR_CLIENTINFO ClientInfo = {0};
    //ClientInfo.hPlayWnd = NULL;
    ClientInfo.lChannel = 1;
    ClientInfo.lLinkMode = 0;
    ClientInfo.sMultiCastIP = NULL;


    RecordParas *t_para = (RecordParas *)para;
    HKcameraArgs hkargs;

    //hkargs.NVR_LoginID = t_para->NVR_LoginID;//nvr server loginID
    strcpy(hkargs.NAR_cameraID, t_para->cameraID);//the VolID in nvr server
    hkargs.block_flag = 0;
    hkargs.NAR_recordHandle = 0;
    hkargs.HK_streamHandle = &streamHandle;

    while(1){
    	//-----------Init
    	NET_DVR_Init();
        hkargs.block_flag = 0;

    	//------------Set Connecttime and ReconnectTime
    	NET_DVR_SetConnectTime(2000,1);
    	NET_DVR_SetReconnect(10000,TRUE);

    	//-------------HKLogin
    	lUserID = NET_DVR_Login_V30(t_para->cameraIP, t_para->cameraPort, HK_userName, HK_password, &struDeviceInfo);
    	if(lUserID < 0){
    	    syslog(LOG_ERR,"connect HK IPC %s failed! errorCode: %d\n", t_para->cameraIP, NET_DVR_GetLastError());
    	    NET_DVR_Cleanup();//clear all the info
            continue;
    	}
        syslog(LOG_ERR,"connect HK IPC %s sucess!\n", t_para->cameraIP);

	//set exception callback function
    	NET_DVR_SetExceptionCallBack_V30(0, NULL, HK_RP_Exp_Callback, &hkargs);

	//get data stream and store
   	streamHandle = NET_DVR_RealPlay_V30(lUserID, &ClientInfo, HK_Store_CallBack, &hkargs, 0);
        if(streamHandle < 0){
            NET_DVR_Logout(lUserID);//get wrong handle ,logout
            NET_DVR_Cleanup();
            continue;
    	}
    	while(!hkargs.block_flag){ 
    	}
        stopResult = NET_DVR_StopRealPlay(streamHandle);
        syslog(LOG_INFO,"(InHKTransdata) stoped real play ? result:%d\n", stopResult);
        NET_DVR_Logout_V30(lUserID);
        syslog(LOG_INFO,"(InHKTransdata) HKcamera Logout(loginID was %d)\n",lUserID);
        NET_DVR_Cleanup();
        if(hkargs.block_flag == 1){
			break;
		}
    }
	return NULL;
}


//handle with the streaming data from HK camera
void CALLBACK HK_Store_CallBack(LONG streamHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize,void* dwUser){ 
    
    //info to login nvrd
    char server_VolAlias[] = "camera";
    int  server_VolrecordType = 2;
    int  server_recVlmID = 0;
    char server_desc[] = "describe";
    int  server_descLen = strlen(server_desc);

    //static unsigned int hres = 0;
    //static unsigned int last_hres = 0;

    HKcameraArgs * pUser = (HKcameraArgs *)dwUser;
    
    int ret = 0;
    unsigned int beginTime = 0;
    unsigned int endTime = 0;
    time_t currentTime;

    currentTime = time(NULL);
    beginTime = currentTime;
    endTime = currentTime;

    int stopRecord_result;

    //syslog(LOG_ERR,"hk_store is running");
    switch(dwDataType){
        case NET_DVR_SYSHEAD:
            if(dwBufSize > 0){
                pUser->NAR_recordHandle = NAR_startRecord(pUser->NAR_cameraID, server_VolAlias, server_VolrecordType, \
                                      server_recVlmID, (char *)pBuffer, (int)dwBufSize, server_desc, server_descLen);
                if(pUser->NAR_recordHandle == (unsigned int)(-1)){
                    syslog(LOG_ERR,"(IN hk_store) HK Startrecord fail:errCode:%lu\n",nvrproc_getlasterror());
                    pUser->block_flag = 1;
                }else{
					; //start succeed
				}
                    
            }else{
                syslog(LOG_INFO,"(IN hk_store) nodata(head) from HK camera!\n");
			}
            break;
        case NET_DVR_STREAMDATA://streaming data 
            if(dwBufSize > 0){
                ret = NAR_record(pUser->NAR_recordHandle, (const char *)pBuffer, (int)dwBufSize, beginTime, endTime);
                if(ret < 0){
                    syslog(LOG_INFO,"(IN hk_store) HK record fail:errCode:%lu\n",nvrproc_getlasterror());
                    if(pUser->NAR_recordHandle != (unsigned int)(-1)){
                        stopRecord_result = NAR_stopRecord(pUser->NAR_recordHandle);
                        syslog(LOG_INFO,"(IN hk_store)Now stop the record(Handle %d),stopResult:%d\n",pUser->NAR_recordHandle, stopRecord_result);
                        pUser->block_flag = 1;
                    }
                }else{
                    //syslog(LOG_ERR,"data length: %d\n", dwBufSize);
					//recording
				}
			}else{
                syslog(LOG_INFO,"(IN hk_store) nodata from(stream) HK camera!\n");	
            }
            break;
    
        default:
            syslog(LOG_INFO,"(IN hk_store) can't identify the data type\n");
            
    }
}

//handle with the exception
void CALLBACK HK_RP_Exp_Callback(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser){
    //char tempbuf[256] = {0};
    int stopRecord_result;
    //int stopHK_realplay_result; 
	
    HKcameraArgs *dwUser = (HKcameraArgs *)pUser;
    switch(dwType){
        case EXCEPTION_RECONNECT:   //need to reconnect?
            syslog(LOG_INFO,"(InHKExpHandle)-------reconnect?-------\n");
            
			if(dwUser->NAR_recordHandle != (unsigned int)(-1)){
                syslog(LOG_INFO,"(InHKExpHandle) ready to stop record!\n");
				stopRecord_result = NAR_stopRecord(dwUser->NAR_recordHandle);
                syslog(LOG_INFO,"(InHKExpHandle)Now stop the record(Handle %d),stopResult:%d\n",dwUser->NAR_recordHandle, stopRecord_result);
            }
            syslog(LOG_INFO,"(InHKExpHandle) ready to change the value of block_flag\n");
			dwUser->block_flag = 2;
            break;
        default:
            syslog(LOG_INFO,"(InHKExpHandle)---don't know how to handle with this issue---\n");
            
            if(dwUser->NAR_recordHandle != (unsigned int)(-1)){
                syslog(LOG_INFO,"(InHKExpHandle) ready to stop record!\n");
				stopRecord_result = NAR_stopRecord(dwUser->NAR_recordHandle);
                syslog(LOG_INFO,"(InHKExpHandle)Now stop the record(Handle %d),stopResult:%d\n",dwUser->NAR_recordHandle, stopRecord_result);
            }
            syslog(LOG_INFO,"(InHKExpHandle) ready to change the value of block_flag\n");
			dwUser->block_flag = 2;
            break;
    }
}
