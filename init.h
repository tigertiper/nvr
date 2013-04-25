#include"info.h"
int get_LVM_size(const char *volName);
long long get_free_vol_size(const char *volName);
int get_cameras_from_vol(char **cameras, int *num, const char *volName);
int init(char *VolPath);
extern int tcp_create();
extern void *listen_request_thread(void *args);
extern void *VolOpThread(void *);
extern void *WriteTnodeThread(void *);
extern void *TcpPollThread(void *);
extern void *UpdateThread(void *arg);
extern int initCameraInfos();

