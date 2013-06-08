#ifndef _INIT_H
#define _INIT_H
 
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
#include <sys/resource.h>
#include <signal.h>
#include "nvr.h" 
#include "rd_wr.h"
#include "multi_stream.h"
#include "syslog.h" 
#include"info.h" 
#include "multi_stream.h"


#define SERV_PORT 8000 
#define REC_HEAD_SIZE 14 
#define REC_RESULT_SIZE 10
#define OPEN_MAX 256
#define LOCKFILE "/var/run/nvrd.pid"
#define LOCKMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
#define VERDATA "2013.06.08"
#define NVRDVER "1.16.5"
#ifdef JYJ
#define PRJNAME "JYJ"
#endif
#ifdef TAM
#define PRJNAME "TAM"
#endif
#ifdef NAR
#define PRJNAME "NAR"
#endif
#define R_UNLIMITED	(~0UL)


extern pthread_rwlock_t DInfo_PRW;
extern pthread_rwlock_t SInfo_PRW;
char ClientIP[IPLEN];
unsigned short int ClientPort; 


int tcp_create();
int already_running(void); 
void * UpdateThread(void *arg);
void *VolOpThread(void *);
void *WriteTnodeThread(void *);
void *SerialRecordThread(void* arg);
void *ParallelRecordThread(void* arg);
void *UpdateThread(void *arg); 
void firstinit();

#endif

