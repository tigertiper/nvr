#ifndef _INFO_H
#define _INFO_H

#ifndef _LARGEFILE_SOURCE
#define _LARGEFILE_SOURCE
#endif

#ifndef _LARGEFILE64_SOURCE
#define _LARGEFILE64_SOURCE
#endif

#define _FILE_OFFSET_BITS 64

#include<pthread.h>
#include<string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

//#include"util.h"
#define MaxBlocks (1024*1024/8)
#define MaxUsers  1024
#define CNameLength       64	//摄像头名字最大长度
#define VolNameLength     64	//录像卷名字长度
#define MaxchunkCount     32	//一路摄像头的最大离散chunk数目
#define  FNameLength      7	//文件系统名字的长度
#define MaxDesLen        1024	//描述信息的最大长度
#define MaxBufBitmapLen  (1024/8)	//缓冲区的bitmap长度
#define BuffNodeNum        192
#define H264 1
#define MJPEG 2
#define MPEG4 3
#define MAGIC 0x7061
#define SIZEOF(a)  ((64-sizeof(a)%64)+sizeof(a))
#define size_t			////////////////////////
#define ReadRECORD 0
#define WriteRECORD    1
#define EXTEND     1
#define NOTEXTEND  0
#define CHUNKNULL (MaxBlocks*8+1)
#define ISRecycled 1
#define NOTRecycled 0
#define TLEN      (1728*3)
#define FISTTIMESIZE (90*24*60*60/TLEN)
#define WriteLen  (FISTTIMESIZE/30)
#define Maxtime  (90*24*60*60)	//modify
#define NOTSET  0
#define SET     1
#define BufTime 60*2
#define TimeBuffSize (800)
#define BLOCKSIZE (128*1024*1024)	//////////////////////////??????
#define TimeNULL -1
#define FILE_SYS_NAME "VEDIO_\0"
#define STRING_NULL   "NULL_\0"


#define CONF_LEN      (VolNameLength+CNameLength+20)

#define SB_SIZE 128
#define Vnode_SIZE 512
#define DSI_SIZE   1048
#define SEG_SIZE  8
#define SEGINFO_SIZE (DSI_SIZE+10*1024)
#define Tnode_SIZE   16
#define LvmCount  256
#define BitmapAddr  (SB_SIZE)
#define VBitmapAddr (SB_SIZE+MaxBlocks)
#define VnodeAddr   (SB_SIZE+MaxBlocks+MaxUsers/8)
#define DataAddr    (SB_SIZE+MaxBlocks+MaxUsers/8+MaxUsers*Vnode_SIZE)
#define DataAddr1   (1024*SEG_SIZE+1024*SEGINFO_SIZE+FISTTIMESIZE*Tnode_SIZE+Maxtime*Tnode_SIZE)
#define BLKGETSIZE   _IO(0x12,96)

#define MALLOC_ERR 10010	//分配内存失败
#define OPEN_FILE_ERR 10011	//打开逻辑卷失败
#define READ_LVM_ERR  10012	//读逻辑卷失败
#define NOT_MATCH_SIZE 10013	//再次启动时，上次保存的逻辑卷大小与当前的大小超过1M
#define LVM_SMALL     10014	//逻辑卷的容量太小
#define CREATING_LVM  10015	//当前正在创建另一逻辑卷，请稍后再试
#define NOT_EXIST_LVM 10015	//没有找到对应逻辑卷
#define NOT_EXIST_RECORD 10016	//录像卷未存在
#define CREATING_RECORD 10017	//当前正在创建录像卷，请稍后再试
#define MAX_LVM_COUNT  10018	//最读创建256个视频逻辑卷
#define BUILD_MEM_ERR  10019	//为视频卷建立内存结构失败
#define WRITE_LVM_ERR  10020	//写逻辑卷失败
#define MAX_RDWR_COUNT 10021	//对一逻辑卷达到了最大的读写路数，128路
#define ALLOC_FD_ERR   10022	//分配fd失败
#define TOO_FLAGS       10023	//为录像卷分配的块太分散
#define EXIST_SAME_NAME  10024	//已经存在相同名字。
#define ERR_HANDLE       10025	//错误的句柄
#define TIME_ERR      10026	//输入的开始时间或结束时间检索不出数据
#define COLSE_ERR     10027	//还有读或者写未关闭，不能关闭录像卷
#define LOCK_ERR      10028	//
#define NOT_EXIST_CAMERA   10029	//在配置文件中未找到摄像头的记录信息
#define ERR_TIME_INTERL 10031
#define NVR_CREATWRITEDATATHREADFAIL 10030
#define SPACE_NOT_ENOUGH 10032
#define ZERO_TNODE 10033
#define NOT_EXIST_CAMERALIST 10034
#define CAMERA_IS_RECORDING 10035




#define spin_init(spinlock) pthread_mutex_init(&(spinlock), NULL)
#define  spin_lock(spinlock)  pthread_mutex_lock(&(spinlock))
#define spin_trylock(spinlock) pthread_mutex_trylock(&(spinlock))
#define spin_unlock(spinlock)   pthread_mutex_unlock(&(spinlock))
#define spin_destroy(spinlock)  pthread_mutex_destroy(&(spinlock))
#define spin_rwinit(spinlock)  pthread_rwlock_init(&(spinlock),NULL)
#define spin_rdlock(spinlock)   pthread_rwlock_rdlock(&(spinlock))
#define spin_wrlock(spinlock) pthread_rwlock_wrlock(&(spinlock))
#define spin_rwunlock(spinlock) pthread_rwlock_unlock(&(spinlock))
#define spin_trywrlock(spinlock) pthread_rwlock_trywrlock(&(spinlock))
#define spin_tryrdlock(spinlock) pthread_rwlock_trywrlock(&(spinlock))
#define spin_rwdestroy(spinlock) pthread_rwlock_destroy(&(spinlock))

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef int int32_t;
typedef long long int64_t;
typedef pthread_mutex_t spinlock_t;
typedef pthread_rwlock_t spinrwlock_t;

typedef struct superBlcok {
    char fileSystemName[FNameLength];	//文件系统类型
    unsigned long long totalSize;	//总容量
    short vnodeCount;		//已分配的vnode
    long long blockSize;	//数据块大小
    int mTime;			//最后一次装载fs的时间
    int wTime;			//超级块的最后一次写入时间
    short magic;		//用来识别文件系统的幻数
// long long  dataAddr;//数据块的起始地址
    long long dataBlocksCount;	//总的存储数据块的数目
    long long freeBlocksCount;	//空闲数据块的数目
    int interval;		//写回磁盘的间隔时间
} SBlock;

typedef struct initInfo {	//配置文件的记录结构
    int mode;
    char volName[VolNameLength];	//所在卷名称
    char fileSystemName[FNameLength];	//文件系统类型
    unsigned long long size;	//总容量
} _initInfo;

typedef struct timeNode {
    int time;
    int len;
    long long addr;
} tnode;

typedef struct vnodeInfo {
    char key;
    short ID;
    int fd;			//打开的文件描述符
    char status;		//1表示用于写录像，0表示读录像
    int count;			//计时器，用于记录tnode缓存数目
    tnode t[TimeBuffSize];	//时间缓存空间
    int beginTime;
    int endTime;
    union {
	unsigned long long nextTimeAddr;
	char is_starttime;
    };
    struct vnodeInfo *next;	//使用链表结构连接 链表有序
    pthread_mutex_t mutex;
} *_vnodeInfo;

typedef struct _vnode {
    char cameraid[CNameLength];	//摄像头名字
    char alias[CNameLength];	//摄像头别名
    char volName[VolNameLength];	//所在卷名称
    int block[MaxchunkCount][2];	//分配给该vnode指示录像卷的块，用块号记录
    long long storeAddr;	//下一次写入地址
    long long curSnode;		//当前snode号
    long long firstIndex;	//时间索引表首地址
    long long queryAdd;		//下一次写时间索引地址
    char isRecycle;		//回转标志位
    short savedDays;		//录像保存天数
    char delPolicy;		//录像覆盖策略
    char encodeType;		//编码格式 #define H264 1；
//#define MJPEG 2；#define MPEG4 3；
    short count;		//一级索引的计数器
    short wr_count;		//一级索引的写位置
    char SnodeRecycle;		////1 Recycled; 0 notRecycled 
    _vnodeInfo _bf;		//指向对应的缓冲区
    spinrwlock_t spin;
    char status;
#ifdef SPACE_TIME_SYNCHRONIZATION
    char SpaceState;
    short origin_count;
    uint32_t origin_time;
#endif    
} vnode;

/*typedef struct _Voluminfo {
	char cameraid[CNameLength];	//摄像头名字
	char alias[CNameLength];	//摄像头别名
	char volName[VolNameLength];	//所在卷名称
	short savedDays;	//录像保存天数
	char delPolicy;		//录像覆盖策略
	char encodeType;	//编码格式 #define H264 1；
} Voluminfo;*/

typedef struct bufferHead {
    char map[MaxBufBitmapLen];
    pthread_rwlock_t spin;
} *bfHead;

typedef struct sbInfo {
    SBlock *_es;		//超级块的指针
    char volName[VolNameLength];	//所在卷名称
    char *bitmap;		//位图的缓冲区
    char *vnodemapping;		//vnode映射的缓存区
    char *vnodeTable;		//vnode的缓冲区
    //pthread_mutex_t spinSuperblock;       //超级块和位图的锁
    //pthread_rwlock_t spinvnode;   //vbitmap和vnode的位图的锁
    bfHead _bh;			//用于管理缓冲区的结构体
    char *_bf;			//共享的缓冲区
    struct sbInfo *next;
    pthread_mutex_t mutex;	//for open volName mutex,
} *_sbinfo;

typedef struct {
    _sbinfo table[LvmCount];
    pthread_rwlock_t spin;
} SBTable;

typedef struct DateSegIndex {
    int start_time;
    int end_time;
} segindex;

typedef struct DataSegInfo {
    int size;			//对应的数据段头大小
    int frame;			//帧率,单位为：帧/秒
    short width;		//分辨率
    short height;		//分辨率
    char des[MaxDesLen];	//描述信息
} seginfo;
//全局变量


extern SBTable sbTable;

void sb_to_buf(char *buf, SBlock * sb);
void buf_to_sb(char *buf, SBlock * sb);
void vnode_to_buf(char *buf, vnode * v);
void buf_to_vnode(char *buf, vnode * v);
void DSI_to_buf(char *buf, seginfo * seg);
void buf_to_DSI(char *buf, seginfo * seg);
int set_clr_bitmap(_sbinfo sbinfo, vnode * v, int flag);
int free_blocks(_sbinfo sbinfo, vnode * v, int time);
int put_sb(_sbinfo sbinfo, vnode * v);
char *extend_buf(vnode * v, _sbinfo sbinfo, char mode);
int test_or_alloc_ID(_sbinfo sbinfo, char *name, int len, int *n,
		     int flag);
int cal_alloc_chunk(_sbinfo sbinfo, vnode * v, unsigned long long  blocks);
_sbinfo get_sbinfo(const char *volumeid);
_vnodeInfo get_Vi(vnode * v, int key);
int delete_vi(_sbinfo sbinfo, vnode * v, char mode, int key);
int free_vi(_sbinfo sbinfo, int nr);
//int read_vol_by_camera(char *vol_path, const char *cameraid);
//int write_parm_file(const char *vol_path, const char *cameraid);

_vnodeInfo alloc_vi(_sbinfo sbinfo);

extern int put_vnode(_sbinfo sbinfo, vnode * v, char *_vbitmap, int ID);

/*Bitops_add.c*/
extern /*inline */ int bit(char *addr, int nr);
extern /*inline */ int setbit_(char *addr, int nr);
extern /*inline */ int clrbit_(char *addr, int nr);
extern /*inline */ int find_first_zero(char *addr, int nr);

/*util.c*/
/*
extern  int spin_init(pthread_mutex_t spinlock);
extern  int spin_lock(pthread_mutex_t spinlock);
extern  int spin_trylock(pthread_mutex_t spinlock);
extern  int spin_unlock(pthread_mutex_t spinlock);
extern  int spin_destroy(pthread_mutex_t spinlock);
extern  int spin_rwinit(pthread_rwlock_t spinlock);
extern int spin_rdlock(pthread_rwlock_t spinlock);
extern  int spin_wrlock(pthread_rwlock_t spinlock);
extern  int spin_rwunlock(pthread_rwlock_t spinlock);
extern / int spin_trywrlock(pthread_rwlock_t spinlock);
extern  int spin_rwdestroy(pthread_rwlock_t spinlock);
extern int spin_tryrdlock(pthread_rwlock_t spinlock);
*/


extern unsigned int ErrorFlag;
extern int buf_hash(char *name, int len);
extern void _Debug(char *s, int line, char *file);
extern int _read(int fd, char *buf, int size, long long offset);
extern int _write(int fd, char *buf, int size, long long offset);

/**init.c*/

extern unsigned long long InitFalg;
extern int free_vnode(_sbinfo sbinfo, vnode * v);


/*getsize.c*/

#endif
