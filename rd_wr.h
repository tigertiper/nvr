#ifndef __RD_WR_H
#define __RD_WR_H
#include"info.h"
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "multi_stream.h"

#define ERR_RETURN 0xFFFFFFFF
#define SBINFO(a) sbTable.table[(a)>>8 & 0x000000FF]
#define _ID(a)      ((a)>>16 & 0x0000FFFF)


enum my_msg_type {
    CREAT_REC_VOL_ARGS = 1,
    CREAT_REC_VOL_RES,
    DEL_REC_VOL_ARGS,
    DEL_REC_VOL_RES,
    DEL_VIDEO_VOL_ARGS,
    DEL_VIDEO_VOL_RES
};

typedef struct {
    long int msgType;
    char volumeid[50];
    char name[50];
    char alias[50];
    short savedDays;
    char delPolicy;
    char encodeType;
    unsigned long long blocks;
} CreatRecVolMsg;

typedef struct {
    long int msgType;
    char cameraID[50];
    int mode;
} DelRecVolMsg;

typedef struct {
    long int msgType;
    int result;
} ResMsg;

typedef struct {
    long int msgType;
    char volName[VolNameLength];
} DelVideoVolMsg;
 
typedef struct CameraInfo{
   char CameraID[CAMERAIDLEN];
   char lv_name[VolNameLength];
   struct CameraInfo* next;
}CameraInfo;

extern CameraInfo*CameraInfos;
extern unsigned long long get_lv_size(const char *volName);
int is_vedio_LVM(const char *Volpath, SBlock * sb);
int get_lv_name(LvInfo * lv_info, int max);
int CreatRecordSeg(char *cameraid, seginfo * sinfo, char *buf, short size);
int write_back_tnodes(_sbinfo sbinfo, vnode * v, _vnodeInfo vi, StreamInfo * si);
int initWriteStream(unsigned int handle, vnode ** v, int *ID, _sbinfo * sbinfo, _vnodeInfo * vi);
int writeTnodeToBuf(StreamInfo * si, uint32_t startTime, int size);
int ReadStream(uint32_t handle, char *buf, int size, char mode);
int openRecordSeg(const char *cameraid, int beginTime, int endTime,
		  int mode);
uint32_t _GetRecordSegHead(const char *cameraid, uint32_t * pStartTime,
			   uint32_t * pEndTime, char *buf, uint32_t *size);
uint32_t GetRecordInfo(const char *cameraid, uint32_t * pStartTime,
		       uint32_t * pEndTime, seginfo * si);
uint32_t GetRecordInfoOnebyOne(const char *cameraid, uint32_t * pStartTime, 
               uint32_t * pEndTime, seginfo * si, uint32_t *n);

int DeleteRecordPara(const char *cameraid, uint32_t beginTime,
		     uint32_t endTime);
int DeleteRecordSeg(uint32_t startTime, uint32_t endTime,
		    const char *cameraid);
int CloseRecordSeg(uint32_t handle, StreamInfo * si);
int GetRecordSegSize(const char *cameraid, uint32_t StartTime, uint32_t EndTime);	//以K为单位
int CreateRecordVol(char *volumeid, char *name,
		    char *alias, short savedDays,
		    char delPolicy, char encodeType,
		    unsigned long long blocks);
int DeleteRecordVol(const char *cameraid, int mode);	//0 表示强制使用，1,如果有使用，不删除
int DeleteVideoVol(const char *volPath);
int alloc_blocks_for_vnode(_sbinfo sbinfo, unsigned long long blocks, vnode * v);
int get_cameras_from_vol(char cameras[][CNameLength], int *num,
			 const char *volName);
long long get_free_vol_size(const char *volName);
_sbinfo init(const char *volume_path);
int get_dev_ID(const char *cameraid, _sbinfo * sbinf);
int creatCameraList();
void showCameraList();
int addCameraInfo(const char * cameraID,  const char * volName);
int read_vol_by_camera( char * vol_path, const char * cameraID);
int removeCameraInfo(const char *cameraID);
int removeCameraInfoByVol(const char *vol_path);
int initCameraInfos();

#endif
