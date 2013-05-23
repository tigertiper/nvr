 #ifndef _HC_NET_SDK_H_
#define _HC_NET_SDK_H_

#ifndef __PLAYRECT_defined
#define __PLAYRECT_defined
typedef struct __PLAYRECT
{
    int x;                               
    int y;                                  
    int uWidth;                            
    int uHeight;                            
}PLAYRECT;
#endif


#if (defined(_WIN32)) //windows
#define NET_DVR_API  extern "C"__declspec(dllimport)
typedef  unsigned _int64 UINT64;
#elif defined(__linux__) //linux
typedef     unsigned int    DWORD;
typedef     unsigned short  WORD;
typedef     unsigned short  USHORT;
typedef     int            LONG;
typedef  	unsigned char	BYTE ;
typedef     int BOOL;
typedef     unsigned int   	UINT;
typedef 	void* 			LPVOID;
typedef 	void* 			HANDLE;
typedef     unsigned int*  LPDWORD; 
typedef  unsigned long long UINT64;

#ifndef    TRUE
#define    TRUE	1
#endif
#ifndef    FALSE
#define	   FALSE 0
#endif
#ifndef    NULL
#define	   NULL 0
#endif

#define __stdcall 
#define CALLBACK  

#ifndef __HWND_defined
#define __HWND_defined
typedef PLAYRECT HWND;
#endif

//#define NET_DVR_API extern "C" 
#define NET_DVR_API

typedef unsigned int   COLORKEY;
typedef unsigned int    COLORREF;

#ifndef __HDC_defined
#define __HDC_defined
typedef struct __DC
{
    void*   surface;                        // SDL窗口的Surface
    HWND    hWnd;                           // HDC所在的窗口句柄
}DC;
#endif

typedef DC* HDC;

typedef struct tagInitInfo
{
    int uWidth;
    int uHeight;
}INITINFO;
#endif

//宏定义
#define MAX_NAMELEN			    16		//DVR本地登陆名
#define MAX_RIGHT			    32		//设备支持的权限（1-12表示本地权限，13-32表示远程权限）
#define NAME_LEN			    32      //用户名长度
#define PASSWD_LEN			    16      //密码长度
#define SERIALNO_LEN		    48      //序列号长度
#define MACADDR_LEN			    6       //mac地址长度
#define MAX_ETHERNET		    2       //设备可配以太网络
#define MAX_NETWORK_CARD        4       //设备可配最大网卡数目
#define PATHNAME_LEN		    128     //路径长度
#define MAX_PRESET_V13          16      //预置点

#define MAX_TIMESEGMENT_V30	    8       //9000设备最大时间段数
#define MAX_TIMESEGMENT		    4       //8000设备最大时间段数

#define MAX_SHELTERNUM			4       //8000设备最大遮挡区域数
#define MAX_DAYS				7       //每周天数
#define PHONENUMBER_LEN			32      //pppoe拨号号码最大长度

#define MAX_DISKNUM_V30			33		//9000设备最大硬盘数/* 最多33个硬盘(包括16个内置SATA硬盘、1个eSATA硬盘和16个NFS盘) */
#define MAX_DISKNUM		        16      //8000设备最大硬盘数
#define MAX_DISKNUM_V10		    8       //1.2版本之前版本

#define MAX_WINDOW_V30			32      //9000设备本地显示最大播放窗口数
#define MAX_WINDOW				16      //8000设备最大硬盘数
#define MAX_VGA_V30				4       //9000设备最大可接VGA数
#define MAX_VGA			    	1       //8000设备最大可接VGA数

#define MAX_USERNUM_V30			32      //9000设备最大用户数
#define MAX_USERNUM			    16      //8000设备最大用户数
#define MAX_EXCEPTIONNUM_V30	32      //9000设备最大异常处理数
#define MAX_EXCEPTIONNUM		16      //8000设备最大异常处理数
#define MAX_LINK				6       //8000设备单通道最大视频流连接数

#define MAX_DECPOOLNUM			4       //单路解码器每个解码通道最大可循环解码数
#define MAX_DECNUM				4       //单路解码器的最大解码通道数（实际只有一个，其他三个保留）
#define MAX_TRANSPARENTNUM		2       //单路解码器可配置最大透明通道数
#define MAX_CYCLE_CHAN			16      //单路解码器最大轮巡通道数
#define MAX_CYCLE_CHAN_V30      64      //最大轮巡通道数（扩展）
#define MAX_DIRNAME_LENGTH		80      //最大目录长度
#define MAX_WINDOWS				16      //最大窗口数

#define MAX_STRINGNUM_V30		8		//9000设备最大OSD字符行数数
#define MAX_STRINGNUM			4       //8000设备最大OSD字符行数数
#define MAX_STRINGNUM_EX		8       //8000定制扩展
#define MAX_AUXOUT_V30			16      //9000设备最大辅助输出数
#define MAX_AUXOUT			    4       //8000设备最大辅助输出数
#define MAX_HD_GROUP			16      //9000设备最大硬盘组数
#define MAX_NFS_DISK			8       //8000设备最大NFS硬盘数

#define IW_ESSID_MAX_SIZE	    32      //WIFI的SSID号长度
#define IW_ENCODING_TOKEN_MAX	32      //WIFI密锁最大字节数
#define MAX_SERIAL_NUM			64	    //最多支持的透明通道路数
#define MAX_DDNS_NUMS	        10      //9000设备最大可配ddns数
#define MAX_DOMAIN_NAME		    64		/* 最大域名长度 */
#define MAX_EMAIL_ADDR_LEN	    48      //最大email地址长度
#define MAX_EMAIL_PWD_LEN		32      //最大email密码长度

#define MAXPROGRESS		        100     //回放时的最大百分率
#define MAX_SERIALNUM	        2       //8000设备支持的串口数 1-232， 2-485
#define CARDNUM_LEN		        20      //卡号长度
#define MAX_VIDEOOUT_V30        4       //9000设备的视频输出数
#define MAX_VIDEOOUT	        2       //8000设备的视频输出数

#define MAX_PRESET_V30			    256		/* 9000设备支持的云台预置点数 */
#define MAX_TRACK_V30			    256		/* 9000设备支持的云台轨迹数 */
#define MAX_CRUISE_V30			    256		/* 9000设备支持的云台巡航数 */
#define MAX_PRESET				    128		/* 8000设备支持的云台预置点数 */
#define MAX_TRACK				    128		/* 8000设备支持的云台轨迹数 */
#define MAX_CRUISE				    128		/* 8000设备支持的云台巡航数 */

#define CRUISE_MAX_PRESET_NUMS	    32 	    /* 一条巡航最多的巡航点 */

#define MAX_SERIAL_PORT             8       //9000设备支持232串口数
#define MAX_PREVIEW_MODE            8       /* 设备支持最大预览模式数目 1画面,4画面,9画面,16画面.... */
#define MAX_MATRIXOUT               16      /* 最大模拟矩阵输出个数 */
#define LOG_INFO_LEN                11840   /* 日志附加信息 */
#define DESC_LEN                    16      /* 云台描述字符串长度 */
#define PTZ_PROTOCOL_NUM            200     /* 9000最大支持的云台协议数 */

#define MAX_AUDIO			        1       //8000语音对讲通道数
#define MAX_AUDIO_V30			    2       //9000语音对讲通道数
#define MAX_CHANNUM			        16      //8000设备最大通道数
#define MAX_ALARMIN			        16      //8000设备最大报警输入数
#define MAX_ALARMOUT		        4       //8000设备最大报警输出数
//9000 IPC接入
#define MAX_ANALOG_CHANNUM          32      //最大32个模拟通道
#define MAX_ANALOG_ALARMOUT         32      //最大32路模拟报警输出 
#define MAX_ANALOG_ALARMIN          32      //最大32路模拟报警输入

#define MAX_IP_DEVICE               32      //允许接入的最大IP设备数
#define MAX_IP_DEVICE_V40           64      // 允许接入的最大IP设备数 最多可添加64个 IVMS 2000等新设备
#define MAX_IP_CHANNEL              32      //允许加入的最多IP通道数
#define MAX_IP_ALARMIN              128     //允许加入的最多报警输入数
#define MAX_IP_ALARMOUT             64      //允许加入的最多报警输出数

#define MAX_RECORD_FILE_NUM         20      // 每次删除或者刻录的最大文件数
//SDK_V31 ATM
#define MAX_ACTION_TYPE	        12	    //自定义协议叠加交易行为最大行为个数 
#define MAX_ATM_PROTOCOL_NUM    256   //每种输入方式对应的ATM最大协议数
#define  ATM_CUSTOM_PROTO       1025   //自定义协议 值为1025
#define ATM_PROTOCOL_SORT       4       //ATM协议段数 
#define ATM_DESC_LEN            32      //ATM描述字符串长度
// SDK_V31 ATM

/* 最大支持的通道数 最大模拟加上最大IP支持 */
#define MAX_CHANNUM_V30               ( MAX_ANALOG_CHANNUM + MAX_IP_CHANNEL )//64
#define MAX_ALARMOUT_V30              ( MAX_ANALOG_ALARMOUT + MAX_IP_ALARMOUT )//96
#define MAX_ALARMIN_V30               ( MAX_ANALOG_ALARMIN + MAX_IP_ALARMIN )//160

#define MAX_LANERECT_NUM        5    //最大车牌识别区域数
#define MAX_FORTIFY_NUM     10   //最大布防个数
#define MAX_INTERVAL_NUM    4    //最大时间间隔个数
#define MAX_CHJC_NUM        3    //最大车辆省份简称字符个数
#define MAX_VL_NUM          5    //最大虚拟线圈个数
#define MAX_DRIVECHAN_NUM       16       //最大车道数
#define MAX_COIL_NUM             3        //最大线圈个数
#define MAX_SIGNALLIGHT_NUM    6   //最大信号灯个数

/*******************全局错误码 begin**********************/	
#define NET_DVR_NOERROR 					0	//没有错误
#define NET_DVR_PASSWORD_ERROR 				1	//用户名密码错误
#define NET_DVR_NOENOUGHPRI 				2	//权限不足
#define NET_DVR_NOINIT 						3	//没有初始化
#define NET_DVR_CHANNEL_ERROR 				4	//通道号错误
#define NET_DVR_OVER_MAXLINK 				5	//连接到DVR的客户端个数超过最大
#define NET_DVR_VERSIONNOMATCH				6	//版本不匹配
#define NET_DVR_NETWORK_FAIL_CONNECT		7	//连接服务器失败
#define NET_DVR_NETWORK_SEND_ERROR			8	//向服务器发送失败
#define NET_DVR_NETWORK_RECV_ERROR			9	//从服务器接收数据失败
#define NET_DVR_NETWORK_RECV_TIMEOUT		10	//从服务器接收数据超时
#define NET_DVR_NETWORK_ERRORDATA			11	//传送的数据有误
#define NET_DVR_ORDER_ERROR					12	//调用次序错误
#define NET_DVR_OPERNOPERMIT				13	//无此权限
#define NET_DVR_COMMANDTIMEOUT				14	//DVR命令执行超时
#define NET_DVR_ERRORSERIALPORT				15	//串口号错误
#define NET_DVR_ERRORALARMPORT				16	//报警端口错误
#define NET_DVR_PARAMETER_ERROR 			17  //参数错误
#define NET_DVR_CHAN_EXCEPTION				18	//服务器通道处于错误状态
#define NET_DVR_NODISK						19	//没有硬盘
#define NET_DVR_ERRORDISKNUM				20	//硬盘号错误
#define NET_DVR_DISK_FULL					21	//服务器硬盘满
#define NET_DVR_DISK_ERROR					22	//服务器硬盘出错
#define NET_DVR_NOSUPPORT					23	//服务器不支持
#define NET_DVR_BUSY						24	//服务器忙
#define NET_DVR_MODIFY_FAIL					25	//服务器修改不成功
#define NET_DVR_PASSWORD_FORMAT_ERROR		26	//密码输入格式不正确
#define NET_DVR_DISK_FORMATING				27	//硬盘正在格式化，不能启动操作
#define NET_DVR_DVRNORESOURCE				28	//DVR资源不足
#define	NET_DVR_DVROPRATEFAILED				29  //DVR操作失败
#define NET_DVR_OPENHOSTSOUND_FAIL 			30  //打开PC声音失败
#define NET_DVR_DVRVOICEOPENED 				31  //服务器语音对讲被占用
#define	NET_DVR_TIMEINPUTERROR				32  //时间输入不正确
#define	NET_DVR_NOSPECFILE					33  //回放时服务器没有指定的文件
#define NET_DVR_CREATEFILE_ERROR			34	//创建文件出错
#define	NET_DVR_FILEOPENFAIL				35  //打开文件出错
#define	NET_DVR_OPERNOTFINISH				36  //上次的操作还没有完成
#define	NET_DVR_GETPLAYTIMEFAIL				37  //获取当前播放的时间出错
#define	NET_DVR_PLAYFAIL					38  //播放出错
#define NET_DVR_FILEFORMAT_ERROR			39  //文件格式不正确
#define NET_DVR_DIR_ERROR					40	//路径错误
#define NET_DVR_ALLOC_RESOURCE_ERROR		41  //资源分配错误
#define NET_DVR_AUDIO_MODE_ERROR			42	//声卡模式错误
#define NET_DVR_NOENOUGH_BUF				43	//缓冲区太小
#define NET_DVR_CREATESOCKET_ERROR		 	44	//创建SOCKET出错
#define NET_DVR_SETSOCKET_ERROR				45	//设置SOCKET出错
#define NET_DVR_MAX_NUM						46	//个数达到最大
#define NET_DVR_USERNOTEXIST				47	//用户不存在
#define NET_DVR_WRITEFLASHERROR				48  //写FLASH出错
#define NET_DVR_UPGRADEFAIL					49  //DVR升级失败
#define NET_DVR_CARDHAVEINIT				50  //解码卡已经初始化过
#define NET_DVR_PLAYERFAILED				51	//调用播放库中某个函数失败
#define NET_DVR_MAX_USERNUM					52  //设备端用户数达到最大
#define NET_DVR_GETLOCALIPANDMACFAIL		53  //获得客户端的IP地址或物理地址失败
#define NET_DVR_NOENCODEING					54	//该通道没有编码
#define NET_DVR_IPMISMATCH					55	//IP地址不匹配
#define NET_DVR_MACMISMATCH					56	//MAC地址不匹配
#define NET_DVR_UPGRADELANGMISMATCH			57	//升级文件语言不匹配
#define NET_DVR_MAX_PLAYERPORT				58	//播放器路数达到最大
#define NET_DVR_NOSPACEBACKUP				59	//备份设备中没有足够空间进行备份
#define NET_DVR_NODEVICEBACKUP				60	//没有找到指定的备份设备
#define NET_DVR_PICTURE_BITS_ERROR			61	//图像素位数不符，限24色
#define NET_DVR_PICTURE_DIMENSION_ERROR		62	//图片高*宽超限， 限128*256
#define NET_DVR_PICTURE_SIZ_ERROR			63	//图片大小超限，限100K
#define NET_DVR_LOADPLAYERSDKFAILED			64	//载入当前目录下Player Sdk出错
#define NET_DVR_LOADPLAYERSDKPROC_ERROR		65	//找不到Player Sdk中某个函数入口
#define NET_DVR_LOADDSSDKFAILED				66	//载入当前目录下DSsdk出错
#define NET_DVR_LOADDSSDKPROC_ERROR		    67	//找不到DsSdk中某个函数入口
#define NET_DVR_DSSDK_ERROR					68	//调用硬解码库DsSdk中某个函数失败
#define NET_DVR_VOICEMONOPOLIZE				69	//声卡被独占
#define NET_DVR_JOINMULTICASTFAILED			70	//加入多播组失败
#define NET_DVR_CREATEDIR_ERROR				71	//建立日志文件目录失败
#define NET_DVR_BINDSOCKET_ERROR			72	//绑定套接字失败
#define NET_DVR_SOCKETCLOSE_ERROR			73	//socket连接中断，此错误通常是由于连接中断或目的地不可达
#define NET_DVR_USERID_ISUSING			    74	//注销时用户ID正在进行某操作
#define NET_DVR_SOCKETLISTEN_ERROR			75	//监听失败
#define NET_DVR_PROGRAM_EXCEPTION			76	//程序异常
#define NET_DVR_WRITEFILE_FAILED			77	//写文件失败
#define NET_DVR_FORMAT_READONLY				78  //禁止格式化只读硬盘
#define NET_DVR_WITHSAMEUSERNAME		    79  //用户配置结构中存在相同的用户名
#define NET_DVR_DEVICETYPE_ERROR            80  /*导入参数时设备型号不匹配*/
#define NET_DVR_LANGUAGE_ERROR              81  /*导入参数时语言不匹配*/
#define NET_DVR_PARAVERSION_ERROR           82  /*导入参数时软件版本不匹配*/
#define NET_DVR_IPCHAN_NOTALIVE             83  /*预览时外接IP通道不在线*/
#define NET_DVR_RTSP_SDK_ERROR				84	/*加载高清IPC通讯库StreamTransClient.dll失败*/
#define NET_DVR_CONVERT_SDK_ERROR			85	/*加载转码库失败*/
#define NET_DVR_IPC_COUNT_OVERFLOW			86  /*超出最大的ip接入通道数*/
#define NET_DVR_PARAMMODE_ERROR             88 //图像增强仪，参数模式错误（用于硬件设置时，客户端进行软件设置时错误值）
//2009-01-04 
#define NET_DVR_CODESPITTER_OFFLINE			89 //视频综合平台，码分器不在线
#define NET_DVR_BACKUP_COPYING				90  //设备正在备份
//2010-01-16
#define NET_DVR_CHAN_NOTSUPPORT             91  // 通道不支持该操作

#define NET_DVR_CALLINEINVALID                  92  // 高度线位置太集中或长度线不够倾斜 
#define NET_DVR_CALCANCELCONFLICT               93  // 取消标定冲突，如果设置了规则及全局的实际大小尺寸过滤
#define NET_DVR_CALPOINTOUTRANGE                94 	// 标定点超出范围 
#define NET_DVR_FILTERRECTINVALID               95  // 尺寸过滤器不符合要求
// 2010-5-28

// 阵列错误码
#define RAID_ERROR_INDEX	200
#define NET_DVR_NAME_NOT_ONLY               (RAID_ERROR_INDEX + 0)  // 名称已存在
#define NET_DVR_OVER_MAX_ARRAY              (RAID_ERROR_INDEX + 1 ) // 阵列达到上限
#define NET_DVR_OVER_MAX_VD                 (RAID_ERROR_INDEX + 2 ) // 虚拟磁盘达到上限
#define NET_DVR_VD_SLOT_EXCEED              (RAID_ERROR_INDEX + 3 ) // 虚拟磁盘槽位已满
#define NET_DVR_PD_STATUS_INVALID           (RAID_ERROR_INDEX + 4 ) // 重建阵列所需物理磁盘状态错误
#define NET_DVR_PD_BE_DEDICATE_SPARE        (RAID_ERROR_INDEX + 5 ) // 重建阵列所需物理磁盘为指定热备
#define NET_DVR_PD_NOT_FREE                 (RAID_ERROR_INDEX + 6 ) // 重建阵列所需物理磁盘非空闲
#define NET_DVR_CANNOT_MIG2NEWMODE          (RAID_ERROR_INDEX + 7 ) // 不能从当前的阵列类型迁移到新的阵列类型
#define NET_DVR_MIG_PAUSE                   (RAID_ERROR_INDEX + 8 ) // 迁移操作已暂停
#define NET_DVR_MIG_CANCEL                  (RAID_ERROR_INDEX + 9 ) // 正在执行的迁移操作已取消
#define NET_DVR_EXIST_VD                    (RAID_ERROR_INDEX + 10) // 阵列上阵列上存在虚拟磁盘，无法删除阵列
#define NET_DVR_TARGET_IN_LD_FUNCTIONAL     (RAID_ERROR_INDEX + 11) // 对象物理磁盘为虚拟磁盘组成部分且工作正常
#define NET_DVR_HD_IS_ASSIGNED_ALREADY      (RAID_ERROR_INDEX + 12) // 指定的物理磁盘被分配为虚拟磁盘
#define NET_DVR_INVALID_HD_COUNT            (RAID_ERROR_INDEX + 13) // 物理磁盘数量与指定的RAID等级不匹配
#define NET_DVR_LD_IS_FUNCTIONAL            (RAID_ERROR_INDEX + 14) // 阵列正常，无法重建
#define NET_DVR_BGA_RUNNING                 (RAID_ERROR_INDEX + 15) // 存在正在执行的后台任务
#define NET_DVR_LD_NO_ATAPI                 (RAID_ERROR_INDEX + 16) // 无法用ATAPI盘创建虚拟磁盘
#define NET_DVR_MIGRATION_NOT_NEED          (RAID_ERROR_INDEX + 17) // 阵列无需迁移
#define NET_DVR_HD_TYPE_MISMATCH            (RAID_ERROR_INDEX + 18) // 物理磁盘不属于同意类型
#define NET_DVR_NO_LD_IN_DG                 (RAID_ERROR_INDEX + 19) // 无虚拟磁盘，无法进行此项操作
#define NET_DVR_NO_ROOM_FOR_SPARE           (RAID_ERROR_INDEX + 20) // 磁盘空间过小，无法被指定为热备盘
#define NET_DVR_SPARE_IS_IN_MULTI_DG        (RAID_ERROR_INDEX + 21) // 磁盘已被分配为某阵列热备盘
#define NET_DVR_DG_HAS_MISSING_PD           (RAID_ERROR_INDEX + 22) // 阵列缺少盘

// 智能错误码 
#define VCA_ERROR_INDEX                     300 // 智能错误码索引
#define NET_DVR_ID_ERROR                    (VCA_ERROR_INDEX + 0)   // 配置ID不合理
#define NET_DVR_POLYGON_ERROR               (VCA_ERROR_INDEX + 1)   // 多边形不符合要求
#define NET_DVR_RULE_PARAM_ERROR            (VCA_ERROR_INDEX + 2)   // 规则参数不合理
#define NET_DVR_RULE_CFG_CONFLICT           (VCA_ERROR_INDEX + 3)   // 配置信息冲突
#define NET_DVR_CALIBRATE_NOT_READY         (VCA_ERROR_INDEX + 4)   // 当前没有标定信息
#define NET_DVR_CAMERA_DATA_ERROR           (VCA_ERROR_INDEX + 5)   // 摄像机参数不合理
#define NET_DVR_CALIBRATE_DATA_UNFIT        (VCA_ERROR_INDEX + 6)	// 长度不够倾斜，不利于标定
#define NET_DVR_CALIBRATE_DATA_CONFLICT     (VCA_ERROR_INDEX + 7)	// 标定出错，以为所有点共线或者位置太集中
#define NET_DVR_CALIBRATE_CALC_FAIL         (VCA_ERROR_INDEX + 8)	// 摄像机标定参数值计算失败
#define	NET_DVR_CALIBRATE_LINE_OUT_RECT		(VCA_ERROR_INDEX + 9)	// 输入的样本标定线超出了样本外接矩形框
#define NET_DVR_ENTER_RULE_NOT_READY		(VCA_ERROR_INDEX + 10)	// 没有设置进入区域
#define NET_DVR_AID_RULE_NO_INCLUDE_LANE	(VCA_ERROR_INDEX + 11)	// 交通事件规则中没有包括车道（特值拥堵和逆行）
#define NET_DVR_LANE_NOT_READY				(VCA_ERROR_INDEX + 12)	// 当前没有设置车道
#define NET_DVR_RULE_INCLUDE_TWO_WAY		(VCA_ERROR_INDEX + 13)	// 事件规则中包含2种不同方向
#define NET_DVR_LANE_TPS_RULE_CONFLICT      (VCA_ERROR_INDEX + 14)  // 车道和数据规则冲突
#define NET_DVR_NOT_SUPPORT_EVENT_TYPE      (VCA_ERROR_INDEX + 15)  // 不支持的事件类型
#define NET_DVR_LANE_NO_WAY                 (VCA_ERROR_INDEX + 16)  // 车道没有方向
#define NET_DVR_SIZE_FILTER_ERROR           (VCA_ERROR_INDEX + 17)  // 尺寸过滤框不合理

#define NET_DVR_RTSP_GETPORTFAILED			        407  //rtsp 得到端口错误
#define NET_DVR_RTSP_DESCRIBESENDTIMEOUT			411  //rtsp decribe 发送超时
#define NET_DVR_RTSP_DESCRIBESENDERROR				412  //rtsp decribe 发送失败
#define NET_DVR_RTSP_DESCRIBERECVTIMEOUT			413  //rtsp decribe 接收超时
#define NET_DVR_RTSP_DESCRIBERECVDATALOST			414  //rtsp decribe 接收数据错误
#define NET_DVR_RTSP_DESCRIBERECVERROR			    415  //rtsp decribe 接收失败
#define NET_DVR_RTSP_DESCRIBESERVERERR				416  //rtsp decribe 服务器返回401,501等错误

#define NET_DVR_RTSP_SETUPSENDTIMEOUT			    421  //rtsp setup 发送超时
#define NET_DVR_RTSP_SETUPSENDERROR					422  //rtsp setup 发送错误
#define NET_DVR_RTSP_SETUPRECVTIMEOUT				423  //rtsp setup 接收超时
#define NET_DVR_RTSP_SETUPRECVDATALOST				424  //rtsp setup 接收数据错误
#define NET_DVR_RTSP_SETUPRECVERROR					425  //rtsp setup 接收失败
#define NET_DVR_RTSP_OVER_MAX_CHAN					426  //rtsp setup 服务器返回401,501等错误,超过最大连接数

#define NET_DVR_RTSP_PLAYSENDTIMEOUT			    431  //rtsp play 发送超时
#define NET_DVR_RTSP_PLAYSENDERROR					432  //rtsp play 发送错误
#define NET_DVR_RTSP_PLAYRECVTIMEOUT				433  //rtsp play 接收超时
#define NET_DVR_RTSP_PLAYRECVDATALOST				434  //rtsp play 接收数据错误
#define NET_DVR_RTSP_PLAYRECVERROR					435  //rtsp play 接收失败
#define NET_DVR_RTSP_PLAYSERVERERR					436  //rtsp play 服务器返回401,501等错误

#define NET_DVR_RTSP_TEARDOWNSENDTIMEOUT			441  //rtsp teardown 发送超时
#define NET_DVR_RTSP_TEARDOWNSENDERROR				442  //rtsp teardown 发送错误
#define NET_DVR_RTSP_TEARDOWNRECVTIMEOUT			443  //rtsp teardown 接收超时
#define NET_DVR_RTSP_TEARDOWNRECVDATALOST			444  //rtsp teardown 接收数据错误
#define NET_DVR_RTSP_TEARDOWNRECVERROR				445  //rtsp teardown 接收失败
#define NET_DVR_RTSP_TEARDOWNSERVERERR				446  //rtsp teardown 服务器返回401,501等错误

#define  NET_PLAYM4_NOERROR					    500	//no error
#define	 NET_PLAYM4_PARA_OVER				    501	//input parameter is invalid;
#define  NET_PLAYM4_ORDER_ERROR				    502	//The order of the function to be called is error.
#define	 NET_PLAYM4_TIMER_ERROR				    503	//Create multimedia clock failed;
#define  NET_PLAYM4_DEC_VIDEO_ERROR			    504	//Decode video data failed.
#define  NET_PLAYM4_DEC_AUDIO_ERROR			    505	//Decode audio data failed.
#define	 NET_PLAYM4_ALLOC_MEMORY_ERROR		    506	//Allocate memory failed.
#define  NET_PLAYM4_OPEN_FILE_ERROR			    507	//Open the file failed.
#define  NET_PLAYM4_CREATE_OBJ_ERROR		    508	//Create thread or event failed
#define  NET_PLAYM4_CREATE_DDRAW_ERROR		    509	//Create DirectDraw object failed.
#define  NET_PLAYM4_CREATE_OFFSCREEN_ERROR      510	//failed when creating off-screen surface.
#define  NET_PLAYM4_BUF_OVER			        511	//buffer is overflow
#define  NET_PLAYM4_CREATE_SOUND_ERROR	        512	//failed when creating audio device.	
#define	 NET_PLAYM4_SET_VOLUME_ERROR	        513	//Set volume failed
#define  NET_PLAYM4_SUPPORT_FILE_ONLY	        514	//The function only support play file.
#define  NET_PLAYM4_SUPPORT_STREAM_ONLY	        515	//The function only support play stream.
#define  NET_PLAYM4_SYS_NOT_SUPPORT		        516	//System not support.
#define  NET_PLAYM4_FILEHEADER_UNKNOWN          517	//No file header.
#define  NET_PLAYM4_VERSION_INCORRECT	        518	//The version of decoder and encoder is not adapted.  
#define  NET_PALYM4_INIT_DECODER_ERROR          519	//Initialize decoder failed.
#define  NET_PLAYM4_CHECK_FILE_ERROR	        520	//The file data is unknown.
#define  NET_PLAYM4_INIT_TIMER_ERROR	        521	//Initialize multimedia clock failed.
#define	 NET_PLAYM4_BLT_ERROR			        522	//Blt failed.
#define  NET_PLAYM4_UPDATE_ERROR		        523	//Update failed.
#define  NET_PLAYM4_OPEN_FILE_ERROR_MULTI       524   //openfile error, streamtype is multi
#define  NET_PLAYM4_OPEN_FILE_ERROR_VIDEO       525   //openfile error, streamtype is video
#define  NET_PLAYM4_JPEG_COMPRESS_ERROR         526   //JPEG compress error
#define  NET_PLAYM4_EXTRACT_NOT_SUPPORT         527	//Don't support the version of this file.
#define  NET_PLAYM4_EXTRACT_DATA_ERROR          528	//extract video data failed.

#define NET_QOS_OK								 700					//no error
#define NET_QOS_ERROR							 (NET_QOS_OK - 1)		//qos error
#define NET_QOS_ERR_INVALID_ARGUMENTS			 (NET_QOS_OK - 2)		//invalid arguments 
#define NET_QOS_ERR_SESSION_NOT_FOUND			 (NET_QOS_OK - 3)		//session net found
#define NET_QOS_ERR_LIB_NOT_INITIALIZED          (NET_QOS_OK - 4)		//lib not initialized
#define NET_QOS_ERR_OUTOFMEM                     (NET_QOS_OK - 5)		//outtofmem
#define NET_QOS_ERR_PACKET_UNKNOW                (NET_QOS_OK - 10)		//packet unknow
#define NET_QOS_ERR_PACKET_VERSION               (NET_QOS_OK - 11)		//packet version error
#define NET_QOS_ERR_PACKET_LENGTH                (NET_QOS_OK - 12)		//packet length error
#define NET_QOS_ERR_PACKET_TOO_BIG               (NET_QOS_OK - 13)		//packet too big
#define NET_QOS_ERR_SCHEDPARAMS_INVALID_BANDWIDTH (NET_QOS_OK - 20)		//schedparams invalid bandwidth
#define NET_QOS_ERR_SCHEDPARAMS_BAD_FRACTION      (NET_QOS_OK - 21)		//schedparams bad fraction
#define NET_QOS_ERR_SCHEDPARAMS_BAD_MINIMUM_INTERVAL (NET_QOS_OK - 22)	//schedparams bad minimum interval
/*******************全局错误码 end**********************/

/*************************************************
NET_DVR_IsSupport()返回值
1－9位分别表示以下信息（位与是TRUE)表示支持；
**************************************************/
#define NET_DVR_SUPPORT_DDRAW			0x01//支持DIRECTDRAW，如果不支持，则播放器不能工作；
#define NET_DVR_SUPPORT_BLT				0x02//显卡支持BLT操作，如果不支持，则播放器不能工作；
#define NET_DVR_SUPPORT_BLTFOURCC		0x04//显卡BLT支持颜色转换，如果不支持，播放器会用软件方法作RGB转换；
#define NET_DVR_SUPPORT_BLTSHRINKX		0x08//显卡BLT支持X轴缩小；如果不支持，系统会用软件方法转换；
#define NET_DVR_SUPPORT_BLTSHRINKY		0x10//显卡BLT支持Y轴缩小；如果不支持，系统会用软件方法转换；
#define NET_DVR_SUPPORT_BLTSTRETCHX		0x20//显卡BLT支持X轴放大；如果不支持，系统会用软件方法转换；
#define NET_DVR_SUPPORT_BLTSTRETCHY		0x40//显卡BLT支持Y轴放大；如果不支持，系统会用软件方法转换；
#define NET_DVR_SUPPORT_SSE				0x80//CPU支持SSE指令，Intel Pentium3以上支持SSE指令；
#define NET_DVR_SUPPORT_MMX				0x100//CPU支持MMX指令集，Intel Pentium3以上支持SSE指令；

/**********************云台控制命令 begin*************************/	
#define LIGHT_PWRON		2	/* 接通灯光电源 */
#define WIPER_PWRON		3	/* 接通雨刷开关 */
#define FAN_PWRON		4	/* 接通风扇开关 */
#define HEATER_PWRON	5	/* 接通加热器开关 */
#define AUX_PWRON1		6	/* 接通辅助设备开关 */
#define AUX_PWRON2		7	/* 接通辅助设备开关 */
#define SET_PRESET		8	/* 设置预置点 */
#define CLE_PRESET		9	/* 清除预置点 */

#define ZOOM_IN			11	/* 焦距以速度SS变大(倍率变大) */
#define ZOOM_OUT		12	/* 焦距以速度SS变小(倍率变小) */
#define FOCUS_NEAR      13  /* 焦点以速度SS前调 */
#define FOCUS_FAR       14  /* 焦点以速度SS后调 */
#define IRIS_OPEN       15  /* 光圈以速度SS扩大 */
#define IRIS_CLOSE      16  /* 光圈以速度SS缩小 */

#define TILT_UP			21	/* 云台以SS的速度上仰 */
#define TILT_DOWN		22	/* 云台以SS的速度下俯 */
#define PAN_LEFT		23	/* 云台以SS的速度左转 */
#define PAN_RIGHT		24	/* 云台以SS的速度右转 */
#define UP_LEFT			25	/* 云台以SS的速度上仰和左转 */
#define UP_RIGHT		26	/* 云台以SS的速度上仰和右转 */
#define DOWN_LEFT		27	/* 云台以SS的速度下俯和左转 */
#define DOWN_RIGHT		28	/* 云台以SS的速度下俯和右转 */
#define PAN_AUTO		29	/* 云台以SS的速度左右自动扫描 */

#define FILL_PRE_SEQ	30	/* 将预置点加入巡航序列 */
#define SET_SEQ_DWELL	31	/* 设置巡航点停顿时间 */
#define SET_SEQ_SPEED	32	/* 设置巡航速度 */
#define CLE_PRE_SEQ		33	/* 将预置点从巡航序列中删除 */
#define STA_MEM_CRUISE	34	/* 开始记录轨迹 */
#define STO_MEM_CRUISE	35	/* 停止记录轨迹 */
#define RUN_CRUISE		36	/* 开始轨迹 */
#define RUN_SEQ			37	/* 开始巡航 */
#define STOP_SEQ		38	/* 停止巡航 */
#define GOTO_PRESET		39	/* 快球转到预置点 */

/**********************云台控制命令 end*************************/	

/*************************************************
回放时播放控制命令宏定义 
NET_DVR_PlayBackControl
NET_DVR_PlayControlLocDisplay
NET_DVR_DecPlayBackCtrl的宏定义
具体支持查看函数说明和代码
**************************************************/	
#define NET_DVR_PLAYSTART		1//开始播放
#define NET_DVR_PLAYSTOP		2//停止播放
#define NET_DVR_PLAYPAUSE		3//暂停播放
#define NET_DVR_PLAYRESTART		4//恢复播放
#define NET_DVR_PLAYFAST		5//快放
#define NET_DVR_PLAYSLOW		6//慢放
#define NET_DVR_PLAYNORMAL		7//正常速度
#define NET_DVR_PLAYFRAME		8//单帧放
#define NET_DVR_PLAYSTARTAUDIO	9//打开声音
#define NET_DVR_PLAYSTOPAUDIO	10//关闭声音
#define NET_DVR_PLAYAUDIOVOLUME	11//调节音量
#define NET_DVR_PLAYSETPOS		12//改变文件回放的进度
#define NET_DVR_PLAYGETPOS		13//获取文件回放的进度
#define NET_DVR_PLAYGETTIME		14//获取当前已经播放的时间(按文件回放的时候有效)
#define NET_DVR_PLAYGETFRAME	15//获取当前已经播放的帧数(按文件回放的时候有效)
#define NET_DVR_GETTOTALFRAMES  16//获取当前播放文件总的帧数(按文件回放的时候有效)
#define NET_DVR_GETTOTALTIME    17//获取当前播放文件总的时间(按文件回放的时候有效)
#define NET_DVR_THROWBFRAME		20//丢B帧
#define NET_DVR_SETSPEED		24//设置码流速度
#define NET_DVR_KEEPALIVE		25//保持与设备的心跳(如果回调阻塞，建议2秒发送一次)
#define NET_DVR_PLAYSETTIME		26//按绝对时间定位
#define NET_DVR_PLAYGETTOTALLEN		27//获取按时间回放对应时间段内的所有文件的总长度

//远程按键定义如下：
/* key value send to CONFIG program */
#define KEY_CODE_1 1
#define KEY_CODE_2 2
#define KEY_CODE_3 3
#define KEY_CODE_4 4
#define KEY_CODE_5 5
#define KEY_CODE_6 6
#define KEY_CODE_7 7
#define KEY_CODE_8 8
#define KEY_CODE_9 9
#define KEY_CODE_0 10
#define KEY_CODE_POWER 11
#define KEY_CODE_MENU 12
#define KEY_CODE_ENTER 13
#define KEY_CODE_CANCEL 14
#define KEY_CODE_UP 15
#define KEY_CODE_DOWN 16
#define KEY_CODE_LEFT 17
#define KEY_CODE_RIGHT 18
#define KEY_CODE_EDIT 19
#define KEY_CODE_ADD 20
#define KEY_CODE_MINUS 21
#define KEY_CODE_PLAY 22
#define KEY_CODE_REC 23
#define KEY_CODE_PAN 24
#define KEY_CODE_M 25
#define KEY_CODE_A 26
#define KEY_CODE_F1 27
#define KEY_CODE_F2 28

/* for PTZ control */
#define KEY_PTZ_UP_START KEY_CODE_UP
#define KEY_PTZ_UP_STOP 32

#define KEY_PTZ_DOWN_START KEY_CODE_DOWN
#define KEY_PTZ_DOWN_STOP 33

#define KEY_PTZ_LEFT_START KEY_CODE_LEFT
#define KEY_PTZ_LEFT_STOP 34

#define KEY_PTZ_RIGHT_START KEY_CODE_RIGHT
#define KEY_PTZ_RIGHT_STOP 35

#define KEY_PTZ_AP1_START KEY_CODE_EDIT /* 光圈+ */
#define KEY_PTZ_AP1_STOP 36

#define KEY_PTZ_AP2_START KEY_CODE_PAN /* 光圈- */
#define KEY_PTZ_AP2_STOP 37

#define KEY_PTZ_FOCUS1_START KEY_CODE_A /* 聚焦+ */
#define KEY_PTZ_FOCUS1_STOP 38

#define KEY_PTZ_FOCUS2_START KEY_CODE_M /* 聚焦- */
#define KEY_PTZ_FOCUS2_STOP 39

#define KEY_PTZ_B1_START 40 /* 变倍+ */
#define KEY_PTZ_B1_STOP 41

#define KEY_PTZ_B2_START 42 /* 变倍- */
#define KEY_PTZ_B2_STOP 43

//9000新增
#define KEY_CODE_11 44
#define KEY_CODE_12 45
#define KEY_CODE_13 46
#define KEY_CODE_14 47
#define KEY_CODE_15 48
#define KEY_CODE_16 49

#define AUDIOTALKTYPE_G722       0
#define AUDIOTALKTYPE_G711_MU    1
/*************************参数配置命令 begin*******************************/
//用于NET_DVR_SetDVRConfig和NET_DVR_GetDVRConfig,注意其对应的配置结构

#define NET_DVR_GET_DEVICECFG		100		//获取设备参数
#define NET_DVR_SET_DEVICECFG		101		//设置设备参数
#define NET_DVR_GET_NETCFG			102		//获取网络参数
#define NET_DVR_SET_NETCFG			103		//设置网络参数
#define NET_DVR_GET_PICCFG			104		//获取图象参数
#define NET_DVR_SET_PICCFG			105		//设置图象参数
#define NET_DVR_GET_COMPRESSCFG		106		//获取压缩参数
#define NET_DVR_SET_COMPRESSCFG		107		//设置压缩参数
#define NET_DVR_GET_RECORDCFG		108		//获取录像时间参数
#define NET_DVR_SET_RECORDCFG		109		//设置录像时间参数
#define NET_DVR_GET_DECODERCFG		110		//获取解码器参数
#define NET_DVR_SET_DECODERCFG		111		//设置解码器参数
#define NET_DVR_GET_RS232CFG 		112		//获取232串口参数
#define NET_DVR_SET_RS232CFG		113		//设置232串口参数
#define NET_DVR_GET_ALARMINCFG 		114		//获取报警输入参数
#define NET_DVR_SET_ALARMINCFG		115		//设置报警输入参数
#define NET_DVR_GET_ALARMOUTCFG 	116		//获取报警输出参数
#define NET_DVR_SET_ALARMOUTCFG		117		//设置报警输出参数
#define NET_DVR_GET_TIMECFG 		118		//获取DVR时间
#define NET_DVR_SET_TIMECFG			119		//设置DVR时间
#define NET_DVR_GET_PREVIEWCFG 		120		//获取预览参数
#define NET_DVR_SET_PREVIEWCFG		121		//设置预览参数
#define NET_DVR_GET_VIDEOOUTCFG 	122		//获取视频输出参数
#define NET_DVR_SET_VIDEOOUTCFG		123		//设置视频输出参数
#define NET_DVR_GET_USERCFG 		124		//获取用户参数
#define NET_DVR_SET_USERCFG			125		//设置用户参数
#define NET_DVR_GET_EXCEPTIONCFG 	126		//获取异常参数
#define NET_DVR_SET_EXCEPTIONCFG	127		//设置异常参数
#define NET_DVR_GET_ZONEANDDST		128		//获取时区和夏时制参数
#define NET_DVR_SET_ZONEANDDST		129		//设置时区和夏时制参数
#define NET_DVR_GET_SHOWSTRING		130		//获取叠加字符参数
#define NET_DVR_SET_SHOWSTRING		131		//设置叠加字符参数
#define NET_DVR_GET_EVENTCOMPCFG	132		//获取事件触发录像参数
#define NET_DVR_SET_EVENTCOMPCFG	133		//设置事件触发录像参数

#define NET_DVR_GET_FTPCFG			134		//获取抓图的FTP参数(基线)
#define NET_DVR_SET_FTPCFG			135		//设置抓图的FTP参数(基线)

#define NET_DVR_GET_AUXOUTCFG		140		//获取报警触发辅助输出设置(HS设备辅助输出2006-02-28)
#define NET_DVR_SET_AUXOUTCFG		141		//设置报警触发辅助输出设置(HS设备辅助输出2006-02-28)
#define NET_DVR_GET_PREVIEWCFG_AUX 	142		//获取-s系列双输出预览参数(-s系列双输出2006-04-13)
#define NET_DVR_SET_PREVIEWCFG_AUX	143		//设置-s系列双输出预览参数(-s系列双输出2006-04-13)

/*********************************智能部分接口 begin***************************************/
//行为对应（NET_VCA_RULECFG）
#define NET_DVR_SET_RULECFG		152	//设置行为分析规则
#define NET_DVR_GET_RULECFG	    153	//获取行为分析规则
//球机标定参数（NET_DVR_TRACK_CFG ）
#define NET_DVR_SET_TRACK_CFG  160//设置球机的配置参数 
#define NET_DVR_GET_TRACK_CFG  161//获取球机的配置参数

//智能分析仪取流配置结构
#define NET_DVR_SET_IVMS_STREAMCFG		162		//设置智能分析仪取流参数
#define NET_DVR_GET_IVMS_STREAMCFG		163		//获取智能分析仪取流参数
//智能控制参数结构
#define NET_DVR_SET_VCA_CTRLCFG			164	 //设置智能控制参数
#define NET_DVR_GET_VCA_CTRLCFG			165	 //获取智能控制参数

//屏蔽区域NET_VCA_MASK_REGION_LIST
#define NET_DVR_SET_VCA_MASK_REGION		166	 //设置屏蔽区域参数
#define NET_DVR_GET_VCA_MASK_REGION		167	 //获取屏蔽区域参数

//ATM进入区域 NET_VCA_ENTER_REGION
#define NET_DVR_SET_VCA_ENTER_REGION	168	 //设置进入区域参数
#define NET_DVR_GET_VCA_ENTER_REGION	169	 //获取进入区域参数

//标定线配置NET_VCA_LINE_SEGMENT_LIST
#define NET_DVR_SET_VCA_LINE_SEGMENT	170	 //设置标定线
#define NET_DVR_GET_VCA_LINE_SEGMENT	171	 //获取标定线

// ivms屏蔽区域NET_IVMS_MASK_REGION_LIST
#define NET_DVR_SET_IVMS_MASK_REGION	172	 //设置IVMS屏蔽区域参数
#define NET_DVR_GET_IVMS_MASK_REGION	173	 //获取IVMS屏蔽区域参数
// ivms进入检测区域NET_IVMS_ENTER_REGION
#define NET_DVR_SET_IVMS_ENTER_REGION	174	 //设置IVMS进入区域参数
#define NET_DVR_GET_IVMS_ENTER_REGION	175	 //获取IVMS进入区域参数

#define NET_DVR_SET_IVMS_BEHAVIORCFG    176	//设置智能分析仪行为规则参数
#define NET_DVR_GET_IVMS_BEHAVIORCFG	177	//获取智能分析仪行为规则参数

// IVMS 回放检索
#define NET_DVR_IVMS_SET_SEARCHCFG		178	//设置IVMS回放检索参数
#define NET_DVR_IVMS_GET_SEARCHCFG		179	//获取IVMS回放检索参数

#define NET_DVR_SET_POSITION_TRACK       180     // 设置场景跟踪配置信息
#define NET_DVR_GET_POSITION_TRACK       181     // 获取场景跟踪配置信息

#define NET_DVR_SET_CALIBRATION         182    // 设置标定信息
#define NET_DVR_GET_CALIBRATION         183    // 获取标定信息

#define NET_DVR_SET_PDC_RULECFG         184    // 设置人流量统计规则
#define NET_DVR_GET_PDC_RULECFG         185    // 获取人流量统计规则

#define NET_DVR_SET_PU_STREAMCFG        186     // 设置前段取流设备信息
#define NET_DVR_GET_PU_STREAMCFG        187     // 获取前段取流设备信息

#define NET_VCA_SET_SIZE_FILTER         194     // 设置全局尺寸过滤器
#define NET_VCA_GET_SIZE_FILTER         195     // 获取全局尺寸过滤器

#define NET_DVR_SET_TRACK_PARAMCFG       196     // 设置球机本地菜单规则
#define NET_DVR_GET_TRACK_PARAMCFG       197     // 获取球机本地菜单规则

#define NET_DVR_SET_DOME_MOVEMENT_PARAM 198     // 设置球机机芯参数
#define NET_DVR_GET_DOME_MOVEMENT_PARAM 199     // 获取球机机芯参数

/**************************************智能部分接口 begin**********************************/


#define NET_DVR_GET_PICCFG_EX		200		//获取图象参数(SDK_V14扩展命令)
#define NET_DVR_SET_PICCFG_EX		201		//设置图象参数(SDK_V14扩展命令)
#define NET_DVR_GET_USERCFG_EX 		202		//获取用户参数(SDK_V15扩展命令)
#define NET_DVR_SET_USERCFG_EX		203		//设置用户参数(SDK_V15扩展命令)
#define NET_DVR_GET_COMPRESSCFG_EX	204		//获取压缩参数(SDK_V15扩展命令2006-05-15)
#define NET_DVR_SET_COMPRESSCFG_EX	205		//设置压缩参数(SDK_V15扩展命令2006-05-15)


#define NET_DVR_GET_NETAPPCFG		222		//获取网络应用参数 NTP/DDNS/EMAIL
#define NET_DVR_SET_NETAPPCFG		223		//设置网络应用参数 NTP/DDNS/EMAIL
#define NET_DVR_GET_NTPCFG			224		//获取网络应用参数 NTP
#define NET_DVR_SET_NTPCFG			225		//设置网络应用参数 NTP
#define NET_DVR_GET_DDNSCFG			226		//获取网络应用参数 DDNS
#define NET_DVR_SET_DDNSCFG			227		//设置网络应用参数 DDNS
//对应NET_DVR_EMAILPARA
#define NET_DVR_GET_EMAILCFG		228		//获取网络应用参数 EMAIL
#define NET_DVR_SET_EMAILCFG		229		//设置网络应用参数 EMAIL

#define NET_DVR_GET_NFSCFG			230		/* NFS disk config */
#define NET_DVR_SET_NFSCFG			231		/* NFS disk config */

#define NET_DVR_GET_SHOWSTRING_EX	238		//获取叠加字符参数扩展(支持8条字符)
#define NET_DVR_SET_SHOWSTRING_EX	239		//设置叠加字符参数扩展(支持8条字符)
#define NET_DVR_GET_NETCFG_OTHER	244		//获取网络参数
#define NET_DVR_SET_NETCFG_OTHER	245		//设置网络参数

//对应NET_DVR_EMAILCFG结构
#define NET_DVR_GET_EMAILPARACFG	250		//Get EMAIL parameters
#define NET_DVR_SET_EMAILPARACFG	251		//Setup EMAIL parameters


#define NET_DVR_GET_DDNSCFG_EX		274	//获取扩展DDNS参数
#define NET_DVR_SET_DDNSCFG_EX		275	//设置扩展DDNS参数

#define	NET_DVR_SET_PTZPOS			292		//云台设置PTZ位置
#define	NET_DVR_GET_PTZPOS			293		//云台获取PTZ位置
#define	NET_DVR_GET_PTZSCOPE		294		//云台获取PTZ范围

/*********************************智能交通事件begin***************************************/
#define NET_DVR_GET_REFERENCE_REGION   400          // 获取参考区域
#define NET_DVR_SET_REFERENCE_REGION   401          // 设置参考区域

#define NET_DVR_GET_TRAFFIC_MASK_REGION     402     // 获取交通事件屏蔽区域
#define NET_DVR_SET_TRAFFIC_MASK_REGION     403     //  设置交通事件屏蔽区域

// #define NET_DVR_GET_SCENE_MODE          404         // 获取场景模式
// #define NET_DVR_SET_SCENE_MODE          405         // 设置场景模式 

#define NET_DVR_SET_AID_RULECFG         404         // 设置交通事件规则参数
#define NET_DVR_GET_AID_RULECFG         405         // 获取交通事件规则参数

#define NET_DVR_SET_TPS_RULECFG         406         // 设置交通统计规则参数
#define NET_DVR_GET_TPS_RULECFG         407         // 获取交通统计规则参数

#define NET_DVR_SET_LANECFG				408			// 设置车道规则
#define	NET_DVR_GET_LANECFG				409			// 获取车道规则


/*********************************智能交通事件end***************************************/
#define NET_DVR_SET_FACEDETECT_RULECFG     420         // 设置人脸检测规则
#define NET_DVR_GET_FACEDETECT_RULECFG     421         // 获取人脸检测规则

/***************************DS9000新增命令(_V30) begin *****************************/
//网络(NET_DVR_NETCFG_V30结构)
#define NET_DVR_GET_NETCFG_V30		    1000		//获取网络参数
#define NET_DVR_SET_NETCFG_V30		    1001		//设置网络参数

//图象(NET_DVR_PICCFG_V30结构)
#define NET_DVR_GET_PICCFG_V30		    1002		//获取图象参数
#define NET_DVR_SET_PICCFG_V30		    1003		//设置图象参数

//录像时间(NET_DVR_RECORD_V30结构)
#define NET_DVR_GET_RECORDCFG_V30	    1004		//获取录像参数
#define NET_DVR_SET_RECORDCFG_V30	    1005		//设置录像参数

//用户(NET_DVR_USER_V30结构)
#define NET_DVR_GET_USERCFG_V30 	    1006		//获取用户参数
#define NET_DVR_SET_USERCFG_V30		    1007		//设置用户参数

//9000DDNS参数配置(NET_DVR_DDNSPARA_V30结构)
#define     NET_DVR_GET_DDNSCFG_V30		1010		//获取DDNS(9000扩展)
#define     NET_DVR_SET_DDNSCFG_V30		1011		//设置DDNS(9000扩展)

//EMAIL功能(NET_DVR_EMAILCFG_V30结构)
#define NET_DVR_GET_EMAILCFG_V30		1012	//获取EMAIL参数 
#define NET_DVR_SET_EMAILCFG_V30		1013	//设置EMAIL参数 

//巡航参数 (NET_DVR_CRUISE_PARA结构)
#define 	NET_DVR_GET_CRUISE			1020		
#define 	NET_DVR_SET_CRUISE			1021		


//报警输入结构参数 (NET_DVR_ALARMINCFG_V30结构)
#define 	NET_DVR_GET_ALARMINCFG_V30			1024		
#define 	NET_DVR_SET_ALARMINCFG_V30			1025

//报警输出结构参数 (NET_DVR_ALARMOUTCFG_V30结构)
#define 	NET_DVR_GET_ALARMOUTCFG_V30			1026		
#define 	NET_DVR_SET_ALARMOUTCFG_V30			1027

//视频输出结构参数 (NET_DVR_VIDEOOUT_V30结构)
#define 	NET_DVR_GET_VIDEOOUTCFG_V30			1028		
#define 	NET_DVR_SET_VIDEOOUTCFG_V30			1029	

//叠加字符结构参数 (NET_DVR_SHOWSTRING_V30结构)
#define 	NET_DVR_GET_SHOWSTRING_V30			1030		
#define 	NET_DVR_SET_SHOWSTRING_V30			1031

//异常结构参数 (NET_DVR_EXCEPTION_V30结构)
#define 	NET_DVR_GET_EXCEPTIONCFG_V30		1034		
#define 	NET_DVR_SET_EXCEPTIONCFG_V30		1035

//串口232结构参数 (NET_DVR_RS232CFG_V30结构)
#define 	NET_DVR_GET_RS232CFG_V30			1036		
#define 	NET_DVR_SET_RS232CFG_V30			1037

//网络硬盘接入结构参数 (NET_DVR_NET_DISKCFG结构)
#define		NET_DVR_GET_NET_DISKCFG				1038		//网络硬盘接入获取
#define		NET_DVR_SET_NET_DISKCFG				1039		//网络硬盘接入设置
//压缩参数 (NET_DVR_COMPRESSIONCFG_V30结构)
#define     NET_DVR_GET_COMPRESSCFG_V30	        1040		
#define     NET_DVR_SET_COMPRESSCFG_V30	        1041		

//获取485解码器参数 (NET_DVR_DECODERCFG_V30结构)
#define     NET_DVR_GET_DECODERCFG_V30		    1042		//获取解码器参数
#define     NET_DVR_SET_DECODERCFG_V30		    1043		//设置解码器参数

//获取预览参数 (NET_DVR_PREVIEWCFG_V30结构)
#define     NET_DVR_GET_PREVIEWCFG_V30		    1044		//获取预览参数
#define     NET_DVR_SET_PREVIEWCFG_V30		    1045		//设置预览参数

//辅助预览参数 (NET_DVR_PREVIEWCFG_AUX_V30结构)
#define     NET_DVR_GET_PREVIEWCFG_AUX_V30		1046		//获取辅助预览参数
#define     NET_DVR_SET_PREVIEWCFG_AUX_V30		1047		//设置辅助预览参数

//IP接入配置参数 （NET_DVR_IPPARACFG结构）
#define     NET_DVR_GET_IPPARACFG               1048        //获取IP接入配置信息 
#define     NET_DVR_SET_IPPARACFG               1049        //设置IP接入配置信息

//IP报警输入接入配置参数 （NET_DVR_IPALARMINCFG结构）
#define     NET_DVR_GET_IPALARMINCFG            1050        //获取IP报警输入接入配置信息 
#define     NET_DVR_SET_IPALARMINCFG            1051        //设置IP报警输入接入配置信息

//IP报警输出接入配置参数 （NET_DVR_IPALARMOUTCFG结构）
#define     NET_DVR_GET_IPALARMOUTCFG           1052        //获取IP报警输出接入配置信息 
#define     NET_DVR_SET_IPALARMOUTCFG           1053        //设置IP报警输出接入配置信息

//硬盘管理的参数获取 (NET_DVR_HDCFG结构)
#define     NET_DVR_GET_HDCFG			        1054	    //获取硬盘管理配置参数
#define     NET_DVR_SET_HDCFG			        1055	    //设置硬盘管理配置参数
//盘组管理的参数获取 (NET_DVR_HDGROUP_CFG结构)
#define     NET_DVR_GET_HDGROUP_CFG			    1056	    //获取盘组管理配置参数
#define     NET_DVR_SET_HDGROUP_CFG			    1057	    //设置盘组管理配置参数

//设备编码类型配置(NET_DVR_COMPRESSION_AUDIO结构)
#define     NET_DVR_GET_COMPRESSCFG_AUD         1058        //获取设备语音对讲编码参数
#define     NET_DVR_SET_COMPRESSCFG_AUD         1059        //设置设备语音对讲编码参数

//IP接入配置参数 （NET_DVR_IPPARACFG_V31结构）
#define     NET_DVR_GET_IPPARACFG_V31            1060        //获取IP接入配置信息 
#define     NET_DVR_SET_IPPARACFG_V31            1061        //设置IP接入配置信息

// 通道资源配置 (NET_DVR_IPPARACFG_V40结构)
#define NET_DVR_GET_IPPARACFG_V40               1062        // 获取IP接入配置
#define NET_DVR_SET_IPPARACFG_V40               1063        // 设置IP接入配置

#define NET_DVR_GET_CCDPARAMCFG              1067       //IPC获取CCD参数配置
#define NET_DVR_SET_CCDPARAMCFG              1068       //IPC设置CCD参数配置

#define NET_DVR_GET_IOINCFG		                1070    //获取抓拍机IO输入参数
#define NET_DVR_SET_IOINCFG		                1071	 //设置抓拍机IO输入参数

#define NET_DVR_GET_IOOUTCFG		            1072    //获取抓拍机IO输出参数
#define NET_DVR_SET_IOOUTCFG		            1073	 //设置抓拍机IO输出参数

#define NET_DVR_GET_FLASHCFG		            1074    //获取IO闪光灯输出参数
#define NET_DVR_SET_FLASHCFG		            1075	 //设置IO闪光灯输出参数

#define NET_DVR_GET_LIGHTSNAPCFG		        1076    //获取抓拍机红绿灯参数
#define NET_DVR_SET_LIGHTSNAPCFG	        	1077	 //设置抓拍机红绿灯参数

#define NET_DVR_GET_MEASURESPEEDCFG		        1078    //获取抓拍机测速参数
#define NET_DVR_SET_MEASURESPEEDCFG		        1079	 //设置抓拍机测速参数

#define NET_DVR_GET_IMAGEOVERLAYCFG	            1080//获取抓拍机图像叠加信息参数
#define NET_DVR_SET_IMAGEOVERLAYCFG	            1081//设置抓拍机图像叠加信息参数

#define NET_DVR_GET_SNAPCFG	                    1082//获取单IO触发抓拍功能配置
#define NET_DVR_SET_SNAPCFG	                    1083//设置单IO触发抓拍功能配置

#define NET_DVR_GET_VTPPARAM		            1084//获取虚拟线圈参数
#define NET_DVR_SET_VTPPARAM		            1085//设置虚拟线圈参数

#define NET_DVR_GET_SNAPENABLECFG					1086//获取抓拍机使能参数
#define NET_DVR_SET_SNAPENABLECFG					1087//设置抓拍机使能参数

#define NET_DVR_GET_POSTEPOLICECFG      1088        //获取卡口电警参数
#define NET_DVR_SET_POSTEPOLICECFG      1089        //设置卡口电警参数

#define NET_DVR_GET_JPEGCFG_V30					1090		//获取抓图的JPEG参数(基线)
#define NET_DVR_SET_JPEGCFG_V30					1091		//设置抓图的JPEG参数(基线)

#define NET_DVR_GET_SPRCFG	                    1092    //获取车牌识别参数
#define NET_DVR_SET_SPRCFG	                    1093    //设置车牌识别参数

#define NET_DVR_GET_PLCCFG    1094   //获取车牌亮度补偿参数
#define NET_DVR_SET_PLCCFG    1095  //设置车牌亮度补偿参数

#define NET_DVR_GET_DEVICESTATECFG              1096   //获取设备当前状态参数

#define NET_DVR_GET_DEVICECFG_V40	1100//获取扩展设备参数 
#define NET_DVR_SET_DEVICECFG_V40	1101//设置扩展设备参数

#define NET_DVR_GET_ZEROCHANCFG   	1102	//获取零通道压缩参数 
#define NET_DVR_SET_ZEROCHANCFG  	1103	//设置零通道压缩参数

#define NET_DVR_GET_ZERO_PREVIEWCFG_V30 1104    // 获取零通道预览参数配置
#define NET_DVR_SET_ZERO_PREVIEWCFG_V30 1105    // 设置零通道预览参数配置

#define NET_DVR_SET_ZERO_ZOOM	1106     //设置零通道的缩放配置 
#define NET_DVR_GET_ZERO_ZOOM	1107     //获取零通道的缩放配置

#define	NET_DVR_NATASSOCIATECFG_GET	1110    //获取NAT功能相关信息
#define	NET_DVR_NATASSOCIATECFG_SET	1111     //设置NAT功能相关信息

#define NET_DVR_GET_SNMPCFG   	                1112    //获取SNMP参数 
#define NET_DVR_SET_SNMPCFG  	                1113    //设置SNMP参数

#define	NET_DVR_VIDEOPLATFORMALARMCFG_GET	1130//获取视频综合平台报警配置
#define	NET_DVR_VIDEOPLATFORMALARMCFG_SET	1131//设置视频综合平台报警配置

#define NET_DVR_GET_RAID_ADAPTER_INFO   1134    // 获取适配器信息
#define NET_DVR_SET_RAID_ADAPTER_INFO   1135    // 设置适配器信息   


//多网卡配置
#define     NET_DVR_GET_NETCFG_MULTI            1161        //获取多网卡配置
#define     NET_DVR_SET_NETCFG_MULTI            1162        //设置多网卡配置

#define NET_DVR_SET_SENSOR_CFG					1180        // 设置模拟量参数
#define NET_DVR_GET_SENSOR_CFG					1181        // 获取模拟量参数
#define NET_DVR_SET_ALARMIN_PARAM				1182		// 设置报警输入参数
#define NET_DVR_GET_ALARMIN_PARAM				1183		// 获取报警输入参数
#define NET_DVR_SET_ALARMOUT_PARAM				1184		// 设置报警输出参数
#define NET_DVR_GET_ALARMOUT_PARAM				1185		// 获取报警输出参数
#define NET_DVR_SET_SIREN_PARAM					1186		// 设置警号参数
#define NET_DVR_GET_SIREN_PARAM					1187		// 获取警号参数
#define NET_DVR_SET_ALARM_RS485CFG				1188		// 设置报警主机485参数
#define NET_DVR_GET_ALARM_RS485CFG				1189		// 获取报警主机485参数
#define NET_DVR_GET_ALARMHOST_MAIN_STATUS		1190		// 获取报警主机主要状态
#define NET_DVR_GET_ALARMHOST_OTHER_STATUS		1191		// 获取报警主机其他状态
#define NET_DVR_SET_ALARMHOST_ENABLECFG			1192		//获取报警主机使能状态
#define NET_DVR_GET_ALARMHOST_ENABLECFG			1193		//设置报警主机使能状态
#define NET_DVR_SET_ALARM_CAMCFG				1194		// 设置视频综合平台报警触发CAM操作配置
#define NET_DVR_GET_ALARM_CAMCFG				1195		// 设置视频综合平台报警触发CAM操作配置
#define NET_DVR_GET_GATEWAY_CFG                 1196        // 获取门禁参数配置
#define NET_DVR_SET_GATEWAY_CFG                 1197        // 设置门禁参数配置

#define NET_DVR_GET_ZOOMCAMCFG                  1200        //获取一体机前端参数
#define NET_DVR_SET_ZOOMCAMCFG                  1201        //设置一体机前端参数

#define     NET_DVR_GET_ISCSI_CFG                   11070     // 获取ISCSI存储配置协议 
#define     NET_DVR_SET_ISCSI_CFG                   11071     // 获取ISCSI存储配置协议 

/***************************DS9000新增命令(_V30) end *****************************/

/*************************参数配置命令 end*******************************/


/*******************查找文件和日志函数返回值*************************/
#define NET_DVR_FILE_SUCCESS		1000	//获得文件信息
#define NET_DVR_FILE_NOFIND			1001	//没有文件
#define NET_DVR_ISFINDING			1002	//正在查找文件
#define	NET_DVR_NOMOREFILE			1003	//查找文件时没有更多的文件
#define	NET_DVR_FILE_EXCEPTION		1004	//查找文件时异常

/*********************回调函数类型 begin************************/
#define COMM_ALARM					0x1100	//8000报警信息主动上传
#define	COMM_TRADEINFO				0x1500  //ATMDVR主动上传交易信息

#define COMM_ALARM_V30				0x4000	//9000报警信息主动上传
#define COMM_IPCCFG			        0x4001	//9000设备IPC接入配置改变报警信息主动上传
#define COMM_IPCCFG_V31			    0x4002	//9000设备IPC接入配置改变报警信息主动上传扩展 9000_1.1
#define COMM_IPCCFG_V40             0x4003  // IVMS 2000 编码服务器 NVR IPC接入配置改变时报警信息上传


/*************操作异常类型(消息方式, 回调方式(保留))****************/
#define EXCEPTION_EXCHANGE			0x8000	//用户交互时异常
#define EXCEPTION_AUDIOEXCHANGE		0x8001	//语音对讲异常
#define EXCEPTION_ALARM				0x8002	//报警异常
#define EXCEPTION_PREVIEW			0x8003	//网络预览异常
#define EXCEPTION_SERIAL			0x8004	//透明通道异常
#define EXCEPTION_RECONNECT			0x8005	//预览时重连
#define EXCEPTION_ALARMRECONNECT	0x8006	//报警时重连
#define EXCEPTION_SERIALRECONNECT	0x8007	//透明通道重连
#define SERIAL_RECONNECTSUCCESS 0x8008	//透明通道重连成功
#define EXCEPTION_PLAYBACK	        0x8010	//回放异常
#define EXCEPTION_DISKFMT	        0x8011	//硬盘格式化
#define EXCEPTION_PASSIVEDECODE     0x8012  //被动解码异常
#define EXCEPTION_EMAILTEST             0x8013  // 邮件测试异常    
#define EXCEPTION_BACKUP                0x8014  // 备份异常
#define PREVIEW_RECONNECTSUCCESS      0x8015  //预览时重连成功
#define ALARM_RECONNECTSUCCESS     0x8016  //报警时重连成功
//2010-11-10 the third generation sdk
#define RESUME_EXCHANGE				0x8017	//用户交互恢复(3g 设备)
/********************预览回调函数*********************/
#define NET_DVR_SYSHEAD			1	//系统头数据
#define NET_DVR_STREAMDATA		2	//视频流数据（包括复合流和音视频分开的视频流数据）
#define NET_DVR_AUDIOSTREAMDATA	3	//音频流数据
#define NET_DVR_STD_VIDEODATA	4	//标准视频流数据
#define NET_DVR_STD_AUDIODATA	5	//标准音频流数据

//设备型号(DVR类型)
/* 设备类型 */
#define DVR							1				/*对尚未定义的dvr类型返回NETRET_DVR*/
#define ATMDVR						2				/*atm dvr*/
#define DVS							3				/*DVS*/
#define DEC							4				/* 6001D */
#define ENC_DEC						5				/* 6001F */
#define DVR_HC						6				/*8000HC*/
#define DVR_HT						7				/*8000HT*/
#define DVR_HF						8				/*8000HF*/
#define DVR_HS						9				/* 8000HS DVR(no audio) */
#define DVR_HTS						10              /* 8016HTS DVR(no audio) */
#define DVR_HB						11              /* HB DVR(SATA HD) */
#define DVR_HCS						12              /* 8000HCS DVR */
#define DVS_A						13              /* 带ATA硬盘的DVS */
#define DVR_HC_S					14              /* 8000HC-S */
#define DVR_HT_S					15              /* 8000HT-S */
#define DVR_HF_S					16              /* 8000HF-S */
#define DVR_HS_S					17              /* 8000HS-S */
#define ATMDVR_S					18              /* ATM-S */
#define LOWCOST_DVR					19				/*7000H系列*/
#define DEC_MAT						20              /*多路解码器*/
#define DVR_MOBILE					21				/* mobile DVR */                 
#define DVR_HD_S					22              /* 8000HD-S */
#define DVR_HD_SL					23				/* 8000HD-SL */
#define DVR_HC_SL					24				/* 8000HC-SL */
#define DVR_HS_ST					25				/* 8000HS_ST */
#define DVS_HW						26              /* 6000HW */
#define DS630X_D					27              /* 多路解码器 */
#define DS640X_HD					28				/*640X高清解码器*/
#define DS610X_D                    29              /*610X解码器*/
#define IPCAM						30				/*IP 摄像机*/
#define MEGA_IPCAM					31				/*852F&852MF*/
#define IPCAM_X62MF					32				/*862MF可以接入9000设备*/
#define ITCCAM                      35              /*智能高清网络摄像机*/
#define ZOOMCAM                     38              /*一体机*/
#define IPDOME                      40              /*IP 标清球机*/
#define IPDOME_MEGA200              41              /*IP 200万高清球机*/
#define IPDOME_MEGA130              42              /*IP 130万高清球机*/
#define IPMOD						50				/*IP 模块*/
#define IDS6501_HF_P                60              // 6501 车牌 
#define IDS6101_HF_A                61              //智能ATM
#define IDS6002_HF_B                62          //双机跟踪：DS6002-HF/B
#define IDS6101_HF_B	            63              //行为分析：DS6101-HF/B DS6101-HF/B_SATA
#define IDS52XX		                64          //智能分析仪IVMS
#define IDS90XX						65				// 9000智能
#define IDS8104_AHL_S_HX            66          // 海鑫人脸识别 ATM
#define IDS8104_AHL_S_H             67              // 私有人脸识别 ATM
#define IDS91XX						68				// 9100智能
#define IIP_CAM_B                   69              // 智能行为IP摄像机
#define DS71XX_H					71				/* DS71XXH_S */
#define DS72XX_H_S					72				/* DS72XXH_S */
#define DS73XX_H_S					73				/* DS73XXH_S */
#define DS72XX_HF_S                 74              //DS72XX_HF_S
#define DS73XX_HFI_S                75              //DS73XX_HFI_S
#define DS76XX_H_S					76				/* DVR,e.g. DS7604_HI_S */
#define DS76XX_N_S					77				/* NVR,e.g. DS7604_NI_S */
#define DS81XX_HS_S					81				/* DS81XX_HS_S */
#define DS81XX_HL_S					82				/* DS81XX_HL_S */
#define DS81XX_HC_S					83				/* DS81XX_HC_S */
#define DS81XX_HD_S					84				/* DS81XX_HD_S */
#define DS81XX_HE_S					85				/* DS81XX_HE_S */
#define DS81XX_HF_S					86				/* DS81XX_HF_S */
#define DS81XX_AH_S					87				/* DS81XX_AH_S */
#define DS81XX_AHF_S				88				/* DS81XX_AHF_S */
#define DS90XX_HF_S		            90              /*DS90XX_HF_S*/
#define DS91XX_HF_S					91              /*DS91XX_HF_S*/
#define DS91XX_HD_S					92              /*91XXHD-S(MD)*/
#define IDS90XX_A					93				// 9000智能 ATM
#define IDS91XX_A					94				// 9100智能 ATM
#define DS95XX_N_S					95              /*DS95XX_N_S NVR 不带任何输出*/
#define DS96XX_N_SH					96              /*DS96XX_N_SH NVR*/
#define DS90XX_HF_SH                97              /*DS90XX_HF_SH */   
#define DS91XX_HF_SH                98              /*DS91XX_HF_SH */
#define DS_B10_XY                   100             /*视频综合平台设备型号(X:编码板片数，Y:解码板片数)*/
#define DS_6504HF_B10               101             /*视频综合平台内部编码器*/
#define DS_6504D_B10                102             /*视频综合平台内部解码器*/
#define DS_1832_B10                 103             /*视频综合平台内部码分器*/
#define DS_6401HFH_B10              104             /*视频综合平台内部光纤板*/
#define DS_65XXHC					105				//65XXHC DVS
#define DS_65XXHC_S					106				//65XXHC-SATA DVS
#define DS_65XXHF					107				//65XXHF DVS
#define DS_65XXHF_S					108				//65XXHF-SATA DVS
#define DS_6500HF_B                 109             //65 rack DVS
#define IVMS_6200_C                 110             // iVMS-6200(/C)  
#define IVMS_6200_B                 111             // iVMS-6200(/B)
#define DS_72XXHV_ST15				112				//72XXHV_ST15 DVR
#define DS_72XXHV_ST20				113				//72XXHV_ST20 DVR
#define IVMS_6200_T			        114             // IVMS-6200(/T)
#define IVMS_6200_BP                115             // IVMS-6200(/BP)
#define DS_81XXHC_ST				116				//DS_81XXHC_ST
#define DS_81XXHS_ST				117				//DS_81XXHS_ST
#define DS_81XXAH_ST				118				//DS_81XXAH_ST
#define DS_81XXAHF_ST				119				//DS_81XXAHF_ST
#define DS_66XXDVS				    120				//66XX DVS

#define DS_1964_B10                 121             /*视频综合平台内部报警器*/
#define DS_B10N04_IN				122             /*视频综合平台内部级联输入*/
#define DS_B10N04_OUT				123             /*视频综合平台内部级联输出*/
#define DS_B10N04_INTEL             124             /*视频综合平台内部智能*/
#define DS_6408HFH_B10E_RM          125             //V6高清
#define DS_B10N64F1_RTM             126             //V6级联不带DSP
#define DS_B10N64F1D_RTM            127             //V6级联带DSP
#define DS_B10_SDS                  128             //视频综合平台子域控制器
#define DS_B10_DS                   129             //视频综合平台域控制器
#define DS_6401HFH_B10V    			130     	    //VGA高清编码器
#define DS_6504D_B10B               131             /*视频综合平台内部标清解码器*/
#define DS_6504D_B10H               132             /*视频综合平台内部高清解码器*/
#define DS_6504D_B10V               133             /*视频综合平台内部VGA解码器*/

#define DS_19DXX					145				/*动环监控报警主机*/	
#define DS_19XX                     146             /*1900系列报警主机*/ 

#define IDS_8104_AHFL_S_H           171             // 8104ATM 
#define IDS_65XX_HF_A               172             // 65 ATM
#define IDS90XX_HF_RH               173             // 9000 智能RH
#define IDS91XX_HF_RH               174             // 9100 智能RH设备
#define IDS_65XX_HF_B               175             // 65 行为分析
#define IDS_65XX_HF_P               176             // 65 车牌识别


#define DS90XX_HF_RH                181             // 9000 RH
#define DS91XX_HF_RH                182             // 9100 RH设备
#define DS78XX_SE                   183             // DVR_78se

#define ENCODER_SERVER				200			// 编码卡服务器
#define DECODER_SERVER              201         // 解码卡服务器
#define PCNVR_SERVER                202         // PCNVR存储服务器
/**********************设备类型 end***********************/

/*************************************************
参数配置结构、参数(其中_V30为9000新增)
**************************************************/

/////////////////////////////////////////////////////////////////////////
//校时结构参数
typedef struct
{
	DWORD dwYear;		//年
	DWORD dwMonth;		//月
	DWORD dwDay;		//日
	DWORD dwHour;		//时
	DWORD dwMinute;		//分
	DWORD dwSecond;		//秒
}NET_DVR_TIME, *LPNET_DVR_TIME;

//时间段(子结构)
typedef struct
{
	//开始时间
    BYTE byStartHour;
	BYTE byStartMin;
	//结束时间
	BYTE byStopHour;
	BYTE byStopMin;
}NET_DVR_SCHEDTIME, *LPNET_DVR_SCHEDTIME;

/*设备报警和异常处理方式*/
#define NOACTION			0x0				/*无响应*/
#define WARNONMONITOR		0x1				/*监视器上警告*/
#define WARNONAUDIOOUT		0x2				/*声音警告*/
#define UPTOCENTER			0x4				/*上传中心*/
#define TRIGGERALARMOUT		0x8				/*触发报警输出*/

//报警和异常处理结构(子结构)(多处使用)(9000扩展)
typedef struct
{
	DWORD	dwHandleType;	/*处理方式,处理方式的"或"结果*/
	/*0x00: 无响应*/
	/*0x01: 监视器上警告*/
	/*0x02: 声音警告*/
	/*0x04: 上传中心*/
	/*0x08: 触发报警输出*/
	/*0x10: Jpeg抓图并上传EMail*/
	BYTE byRelAlarmOut[MAX_ALARMOUT_V30];  
    //报警触发的输出通道,报警触发的输出,为1表示触发该输出
}NET_DVR_HANDLEEXCEPTION_V30, *LPNET_DVR_HANDLEEXCEPTION_V30;

//报警和异常处理结构(子结构)(多处使用)
typedef struct
{
	DWORD	dwHandleType;			/*处理方式,处理方式的"或"结果*/
	/*0x00: 无响应*/
	/*0x01: 监视器上警告*/
	/*0x02: 声音警告*/
	/*0x04: 上传中心*/
	/*0x08: 触发报警输出*/
	/*0x10: Jpeg抓图并上传EMail*/
	BYTE byRelAlarmOut[MAX_ALARMOUT];  //报警触发的输出通道,报警触发的输出,为1表示触发该输出
}NET_DVR_HANDLEEXCEPTION, *LPNET_DVR_HANDLEEXCEPTION;

//DVR设备参数
typedef struct
{
	DWORD dwSize;
	BYTE sDVRName[NAME_LEN];     //DVR名称
	DWORD dwDVRID;				//DVR ID,用于遥控器 //V1.4(0-99), V1.5(0-255)
	DWORD dwRecycleRecord;		//是否循环录像,0:不是; 1:是
	//以下不可更改
	BYTE sSerialNumber[SERIALNO_LEN];  //序列号
	DWORD dwSoftwareVersion;			//软件版本号,高16位是主版本,低16位是次版本
	DWORD dwSoftwareBuildDate;			//软件生成日期,0xYYYYMMDD
	DWORD dwDSPSoftwareVersion;		    //DSP软件版本,高16位是主版本,低16位是次版本
	DWORD dwDSPSoftwareBuildDate;		// DSP软件生成日期,0xYYYYMMDD
	DWORD dwPanelVersion;				// 前面板版本,高16位是主版本,低16位是次版本
	DWORD dwHardwareVersion;	// 硬件版本,高16位是主版本,低16位是次版本
	BYTE byAlarmInPortNum;		//DVR报警输入个数
	BYTE byAlarmOutPortNum;		//DVR报警输出个数
	BYTE byRS232Num;			//DVR 232串口个数
	BYTE byRS485Num;			//DVR 485串口个数
	BYTE byNetworkPortNum;		//网络口个数
	BYTE byDiskCtrlNum;			//DVR 硬盘控制器个数
	BYTE byDiskNum;				//DVR 硬盘个数
	BYTE byDVRType;				//DVR类型, 1:DVR 2:ATM DVR 3:DVS ......
	BYTE byChanNum;				//DVR 通道个数
	BYTE byStartChan;			//起始通道号,例如DVS-1,DVR - 1
	BYTE byDecordChans;			//DVR 解码路数
	BYTE byVGANum;				//VGA口的个数
	BYTE byUSBNum;				//USB口的个数
    BYTE byAuxoutNum;			//辅口的个数
    BYTE byAudioNum;			//语音口的个数
    BYTE byIPChanNum;			//最大数字通道数
}NET_DVR_DEVICECFG, *LPNET_DVR_DEVICECFG;

/*
IP地址
*/
typedef struct
{		
	char	sIpV4[16];						/* IPv4地址 */
	BYTE	byIPv6[128];						/* 保留 */
}NET_DVR_IPADDR, *LPNET_DVR_IPADDR;


/*
网络数据结构(子结构)(9000扩展)
*/
typedef struct 
{
	NET_DVR_IPADDR	struDVRIP;          					//DVR IP地址
	NET_DVR_IPADDR	struDVRIPMask;  //DVR IP地址掩码
	DWORD	dwNetInterface;   								//网络接口1-10MBase-T 2-10MBase-T全双工 3-100MBase-TX 4-100M全双工 5-10M/100M自适应
	WORD	wDVRPort;										//端口号
	WORD	wMTU;											//增加MTU设置，默认1500。
	BYTE	byMACAddr[MACADDR_LEN];							// 物理地址
	BYTE    byRes[2];              //保留
}NET_DVR_ETHERNET_V30, *LPNET_DVR_ETHERNET_V30;

/*
网络数据结构(子结构)
*/
typedef struct
{
	char sDVRIP[16];          //DVR IP地址
	char sDVRIPMask[16];      //DVR IP地址掩码
	DWORD dwNetInterface;     //网络接口 1-10MBase-T 2-10MBase-T全双工 3-100MBase-TX 4-100M全双工 5-10M/100M自适应
	WORD wDVRPort;		      //端口号
	BYTE byMACAddr[MACADDR_LEN];		//服务器的物理地址
}NET_DVR_ETHERNET;

//pppoe结构
typedef struct 
{
	DWORD	dwPPPOE;										//0-不启用,1-启用
	BYTE	sPPPoEUser[NAME_LEN];							//PPPoE用户名
	char	sPPPoEPassword[PASSWD_LEN];						// PPPoE密码
	NET_DVR_IPADDR	struPPPoEIP;							//PPPoE IP地址
}NET_DVR_PPPOECFG, *LPNET_DVR_PPPOECFG;

//网络配置结构(9000扩展)
typedef struct
{	
	DWORD dwSize;
	NET_DVR_ETHERNET_V30	struEtherNet[MAX_ETHERNET];		//以太网口
	NET_DVR_IPADDR	struRes1[2];					/*保留*/
	NET_DVR_IPADDR	struAlarmHostIpAddr;					/* 报警主机IP地址 */
	WORD	wRes2[2];								/* 保留 */
	WORD	wAlarmHostIpPort;								/* 报警主机端口号 */
	BYTE    byUseDhcp;                                      /* 是否启用DHCP 0xff-无效 0-不启用 1-启用*/
	BYTE	byRes3;
	NET_DVR_IPADDR	struDnsServer1IpAddr;					/* 域名服务器1的IP地址 */
	NET_DVR_IPADDR	struDnsServer2IpAddr;					/* 域名服务器2的IP地址 */
	BYTE	byIpResolver[MAX_DOMAIN_NAME];					/* IP解析服务器域名或IP地址 */
	WORD	wIpResolverPort;								/* IP解析服务器端口号 */
	WORD	wHttpPortNo;									/* HTTP端口号 */
	NET_DVR_IPADDR	struMulticastIpAddr;					/* 多播组地址 */
	NET_DVR_IPADDR	struGatewayIpAddr;						/* 网关地址 */
	NET_DVR_PPPOECFG struPPPoE;	
    BYTE    byRes[64];
} NET_DVR_NETCFG_V30, *LPNET_DVR_NETCFG_V30;

//多网卡配置网卡结构
typedef struct 
{
	NET_DVR_IPADDR struDVRIP;           //DVR IP地址
	NET_DVR_IPADDR struDVRIPMask;           //DVR IP地址掩码
	DWORD dwNetInterface;    //网络接口1-10MBase-T 2-10MBase-T全双工 3-100MBase-TX 4-100M全双工 5-10M/100M/1000M自适应
	BYTE byRes1[2]; 
	WORD wMTU;             //增加MTU设置，默认1500。
	BYTE byMACAddr[MACADDR_LEN]; //物理地址，只用于显示
	BYTE byRes2[2]; //保留
	BYTE byUseDhcp;                          /* 是否启用DHCP */
	BYTE byRes3[3];
	NET_DVR_IPADDR struGatewayIpAddr;     /* 网关地址 */
	NET_DVR_IPADDR struDnsServer1IpAddr; /* 域名服务器1的IP地址 */
	NET_DVR_IPADDR struDnsServer2IpAddr; /* 域名服务器2的IP地址 */
}NET_DVR_ETHERNET_MULTI, *LPNET_DVR_ETHERNET_MULTI;

//多网卡网络配置结构
typedef struct
{
	DWORD  dwSize;
	BYTE   byDefaultRoute;        //默认路由，0表示struEtherNet[0]，1表示struEtherNet[1]
	BYTE   byNetworkCardNum;      //设备实际可配置的网卡数目
	BYTE   byRes[2]; //保留
	NET_DVR_ETHERNET_MULTI struEtherNet[MAX_NETWORK_CARD]; //以太网口
	NET_DVR_IPADDR         struManageHost1IpAddr;     /* 主管理主机IP地址 */
	NET_DVR_IPADDR         struManageHost2IpAddr;     /* 辅管理主机IP地址 */
	NET_DVR_IPADDR	       struAlarmHostIpAddr; /* 报警主机IP地址 */
	WORD wManageHost1Port;     /* 主管理主机端口号 */
	WORD wManageHost2Port;     /* 辅管理主机端口号 */
	WORD wAlarmHostIpPort;     /* 报警主机端口号 */
	BYTE  byIpResolver[MAX_DOMAIN_NAME];     /* IP解析服务器域名或IP地址 */
	WORD wIpResolverPort; /* IP解析服务器端口号 */
	WORD wDvrPort; //通讯端口 默认8000 
	WORD wHttpPortNo; /* HTTP端口号 */
	BYTE  byRes2[6];
	NET_DVR_IPADDR   struMulticastIpAddr; /* 多播组地址 */
	NET_DVR_PPPOECFG struPPPoE;
	BYTE        byRes3[24];
}NET_DVR_NETCFG_MULTI, *LPNET_DVR_NETCFG_MULTI;

//网络配置结构
typedef struct
{
	DWORD dwSize;
	NET_DVR_ETHERNET struEtherNet[MAX_ETHERNET];		/* 以太网口 */
	char sManageHostIP[16];		//远程管理主机地址
	WORD wManageHostPort;		//远程管理主机端口号
	char sIPServerIP[16];            //IPServer服务器地址
	char sMultiCastIP[16];     //多播组地址
	char sGatewayIP[16];       	//网关地址
	char sNFSIP[16];			//NFS主机IP地址
	BYTE sNFSDirectory[PATHNAME_LEN];//NFS目录
	DWORD dwPPPOE;				//0-不启用,1-启用
	BYTE sPPPoEUser[NAME_LEN];	//PPPoE用户名
	char sPPPoEPassword[PASSWD_LEN];// PPPoE密码
	char sPPPoEIP[16];			//PPPoE IP地址(只读)
	WORD wHttpPort;				//HTTP端口号
}NET_DVR_NETCFG, *LPNET_DVR_NETCFG;

//通道图象结构
//移动侦测(子结构)(9000扩展)
typedef struct 
{
	BYTE byMotionScope[64][96];									/*侦测区域,0-96位,表示64行,共有96*64个小宏块,为1表示是移动侦测区域,0-表示不是*/
	BYTE byMotionSensitive;										/*移动侦测灵敏度, 0 - 5,越高越灵敏,oxff关闭*/
	BYTE byEnableHandleMotion;									/* 是否处理移动侦测 0－否 1－是*/ 
	BYTE byRes;											/* 保留 */
	char reservedData;	
	NET_DVR_HANDLEEXCEPTION_V30 struMotionHandleType;				/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
	BYTE byRelRecordChan[MAX_CHANNUM_V30];									/* 报警触发的录象通道*/
}NET_DVR_MOTION_V30, *LPNET_DVR_MOTION_V30;

//移动侦测(子结构)
typedef struct 
{
	BYTE byMotionScope[18][22];	/*侦测区域,共有22*18个小宏块,为1表示改宏块是移动侦测区域,0-表示不是*/
	BYTE byMotionSensitive;		/*移动侦测灵敏度, 0 - 5,越高越灵敏,0xff关闭*/
	BYTE byEnableHandleMotion;	/* 是否处理移动侦测 */
	char reservedData[2];
	NET_DVR_HANDLEEXCEPTION strMotionHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//布防时间
	BYTE byRelRecordChan[MAX_CHANNUM]; //报警触发的录象通道,为1表示触发该通道
}NET_DVR_MOTION, *LPNET_DVR_MOTION;

//遮挡报警(子结构)(9000扩展)  区域大小704*576
typedef struct 
{
	DWORD dwEnableHideAlarm;				/* 是否启动遮挡报警 ,0-否,1-低灵敏度 2-中灵敏度 3-高灵敏度*/
	WORD wHideAlarmAreaTopLeftX;			/* 遮挡区域的x坐标 */
	WORD wHideAlarmAreaTopLeftY;			/* 遮挡区域的y坐标 */
	WORD wHideAlarmAreaWidth;				/* 遮挡区域的宽 */
	WORD wHideAlarmAreaHeight;				/*遮挡区域的高*/
	NET_DVR_HANDLEEXCEPTION_V30 strHideAlarmHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
}NET_DVR_HIDEALARM_V30, *LPNET_DVR_HIDEALARM_V30;
//遮挡报警(子结构)  区域大小704*576
typedef struct 
{
	DWORD dwEnableHideAlarm;				/* 是否启动遮挡报警 ,0-否,1-低灵敏度 2-中灵敏度 3-高灵敏度*/
	WORD wHideAlarmAreaTopLeftX;			/* 遮挡区域的x坐标 */
	WORD wHideAlarmAreaTopLeftY;			/* 遮挡区域的y坐标 */
	WORD wHideAlarmAreaWidth;				/* 遮挡区域的宽 */
	WORD wHideAlarmAreaHeight;				/*遮挡区域的高*/
	NET_DVR_HANDLEEXCEPTION strHideAlarmHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//布防时间
}NET_DVR_HIDEALARM, *LPNET_DVR_HIDEALARM;

//信号丢失报警(子结构)(9000扩展)
typedef struct 
{
	BYTE byEnableHandleVILost;	/* 是否处理信号丢失报警 */
	NET_DVR_HANDLEEXCEPTION_V30 strVILostHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
}NET_DVR_VILOST_V30, *LPNET_DVR_VILOST_V30;

//信号丢失报警(子结构)
typedef struct 
{
	BYTE byEnableHandleVILost;	/* 是否处理信号丢失报警 */
	NET_DVR_HANDLEEXCEPTION strVILostHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//布防时间
}NET_DVR_VILOST, *LPNET_DVR_VILOST;

//遮挡区域(子结构)
typedef struct 
{
	WORD wHideAreaTopLeftX;				/* 遮挡区域的x坐标 */
	WORD wHideAreaTopLeftY;				/* 遮挡区域的y坐标 */
	WORD wHideAreaWidth;				/* 遮挡区域的宽 */
	WORD wHideAreaHeight;				/*遮挡区域的高*/
}NET_DVR_SHELTER, *LPNET_DVR_SHELTER;

typedef struct
{
	BYTE byBrightness;  	/*亮度,0-255*/
	BYTE byContrast;    	/*对比度,0-255*/	
	BYTE bySaturation;  	/*饱和度,0-255*/
	BYTE byHue;    			/*色调,0-255*/
}NET_DVR_COLOR, *LPNET_DVR_COLOR;


//通道图象结构(9000扩展)
typedef struct
{
	DWORD dwSize;
	BYTE sChanName[NAME_LEN];
	DWORD dwVideoFormat;	/* 只读 视频制式 1-NTSC 2-PAL*/
	NET_DVR_COLOR struColor;//	图像参数
	char reservedData [60];/*保留*/
	//显示通道名
	DWORD dwShowChanName; // 预览的图象上是否显示通道名称,0-不显示,1-显示 区域大小704*576
	WORD wShowNameTopLeftX;				/* 通道名称显示位置的x坐标 */
	WORD wShowNameTopLeftY;				/* 通道名称显示位置的y坐标 */
	//视频信号丢失报警
	NET_DVR_VILOST_V30 struVILost;
	NET_DVR_VILOST_V30 struRes;		/*保留*/
	//移动侦测
	NET_DVR_MOTION_V30 struMotion;
	//遮挡报警
	NET_DVR_HIDEALARM_V30 struHideAlarm;
	//遮挡  区域大小704*576
	DWORD dwEnableHide;		/* 是否启动遮挡 ,0-否,1-是*/
	NET_DVR_SHELTER struShelter[MAX_SHELTERNUM];
	//OSD
	DWORD dwShowOsd;// 预览的图象上是否显示OSD,0-不显示,1-显示 区域大小704*576
	WORD wOSDTopLeftX;				/* OSD的x坐标 */
	WORD wOSDTopLeftY;				/* OSD的y坐标 */
	BYTE byOSDType;					/* OSD类型(主要是年月日格式) */
	/* 0: XXXX-XX-XX 年月日 */
	/* 1: XX-XX-XXXX 月日年 */
	/* 2: XXXX年XX月XX日 */
	/* 3: XX月XX日XXXX年 */
	/* 4: XX-XX-XXXX 日月年*/
	/* 5: XX日XX月XXXX年 */
	BYTE byDispWeek;				/* 是否显示星期 */
	BYTE byOSDAttrib;				/* OSD属性:透明，闪烁 */
	/* 0: 不显示OSD */
	/* 1: 透明,闪烁 */
	/* 2: 透明,不闪烁 */
	/* 3: 闪烁,不透明 */
	/* 4: 不透明,不闪烁 */
    BYTE byHourOSDType;				/* OSD小时制:0-24小时制,1-12小时制 */
	BYTE byRes[64];
}NET_DVR_PICCFG_V30, *LPNET_DVR_PICCFG_V30;

//通道图象结构SDK_V14扩展
typedef struct 
{
	DWORD dwSize;
	BYTE sChanName[NAME_LEN];
	DWORD dwVideoFormat;	/* 只读 视频制式 1-NTSC 2-PAL*/
	BYTE byBrightness;  	/*亮度,0-255*/
	BYTE byContrast;    	/*对比度,0-255*/
	BYTE bySaturation;  	/*饱和度,0-255 */
	BYTE byHue;    			/*色调,0-255*/
	//显示通道名
	DWORD dwShowChanName; // 预览的图象上是否显示通道名称,0-不显示,1-显示 区域大小704*576
	WORD wShowNameTopLeftX;				/* 通道名称显示位置的x坐标 */
	WORD wShowNameTopLeftY;				/* 通道名称显示位置的y坐标 */
	//信号丢失报警
	NET_DVR_VILOST struVILost;
	//移动侦测
	NET_DVR_MOTION struMotion;
	//遮挡报警
	NET_DVR_HIDEALARM struHideAlarm;
	//遮挡  区域大小704*576
	DWORD dwEnableHide;		/* 是否启动遮挡 ,0-否,1-是*/
	NET_DVR_SHELTER struShelter[MAX_SHELTERNUM];
	//OSD
	DWORD dwShowOsd;// 预览的图象上是否显示OSD,0-不显示,1-显示 区域大小704*576
	WORD wOSDTopLeftX;				/* OSD的x坐标 */
	WORD wOSDTopLeftY;				/* OSD的y坐标 */
	BYTE byOSDType;					/* OSD类型(主要是年月日格式) */
	/* 0: XXXX-XX-XX 年月日 */
	/* 1: XX-XX-XXXX 月日年 */
	/* 2: XXXX年XX月XX日 */
	/* 3: XX月XX日XXXX年 */
	/* 4: XX-XX-XXXX 日月年*/
	/* 5: XX日XX月XXXX年 */
	BYTE byDispWeek;				/* 是否显示星期 */
	BYTE byOSDAttrib;				/* OSD属性:透明，闪烁 */
	/* 0: 不显示OSD */
	/* 1: 透明,闪烁 */
	/* 2: 透明,不闪烁 */
	/* 3: 闪烁,不透明 */
	/* 4: 不透明,不闪烁 */
	BYTE byHourOsdType;		/* OSD小时制:0-24小时制,1-12小时制 */
}NET_DVR_PICCFG_EX, *LPNET_DVR_PICCFG_EX;

//通道图象结构(SDK_V13及之前版本)
typedef struct 
{
	DWORD dwSize;
	BYTE sChanName[NAME_LEN];
	DWORD dwVideoFormat;	/* 只读 视频制式 1-NTSC 2-PAL*/
	BYTE byBrightness;  	/*亮度,0-255*/
	BYTE byContrast;    	/*对比度,0-255*/
	BYTE bySaturation;  	/*饱和度,0-255 */
	BYTE byHue;    			/*色调,0-255*/
	//显示通道名
	DWORD dwShowChanName; // 预览的图象上是否显示通道名称,0-不显示,1-显示 区域大小704*576
	WORD wShowNameTopLeftX;				/* 通道名称显示位置的x坐标 */
	WORD wShowNameTopLeftY;				/* 通道名称显示位置的y坐标 */
	//信号丢失报警
	NET_DVR_VILOST struVILost;
	//移动侦测
	NET_DVR_MOTION struMotion;
	//遮挡报警
	NET_DVR_HIDEALARM struHideAlarm;
	//遮挡  区域大小704*576
	DWORD dwEnableHide;		/* 是否启动遮挡 ,0-否,1-是*/
	WORD wHideAreaTopLeftX;				/* 遮挡区域的x坐标 */
	WORD wHideAreaTopLeftY;				/* 遮挡区域的y坐标 */
	WORD wHideAreaWidth;				/* 遮挡区域的宽 */
	WORD wHideAreaHeight;				/*遮挡区域的高*/
	//OSD
	DWORD dwShowOsd;// 预览的图象上是否显示OSD,0-不显示,1-显示 区域大小704*576
	WORD wOSDTopLeftX;				/* OSD的x坐标 */
	WORD wOSDTopLeftY;				/* OSD的y坐标 */
	BYTE byOSDType;					/* OSD类型(主要是年月日格式) */
	/* 0: XXXX-XX-XX 年月日 */
	/* 1: XX-XX-XXXX 月日年 */
	/* 2: XXXX年XX月XX日 */
	/* 3: XX月XX日XXXX年 */
	/* 4: XX-XX-XXXX 日月年*/
	/* 5: XX日XX月XXXX年 */
	BYTE byDispWeek;				/* 是否显示星期 */
	BYTE byOSDAttrib;				/* OSD属性:透明，闪烁 */
	/* 0: 不显示OSD */
	/* 1: 透明,闪烁 */
	/* 2: 透明,不闪烁 */
	/* 3: 闪烁,不透明 */
	/* 4: 不透明,不闪烁 */
	char reservedData2;
}NET_DVR_PICCFG, *LPNET_DVR_PICCFG;

//码流压缩参数(子结构)(9000扩展)
typedef struct 
{
	BYTE byStreamType;		//码流类型 0-视频流, 1-复合流, 表示事件压缩参数时最高位表示是否启用压缩参数
	BYTE byResolution;  	//分辨率0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5（保留）,6-QVGA(320*240), 
	                        //16-VGA（640*480）, 17-UXGA（1600*1200）, 18-SVGA （800*600）,
	                        //19-HD720p（1280*720）,20-XVGA,  21-HD900p, 27-1920*1080, 
							//28-2560*1920, 29-1600*304, 30-2048*1536, 31-2448*2048,32-2448*1200,
							//33-2448*800,34-XGA（1024*768），35-SXGA（1280*1024）	
	BYTE byBitrateType;		//码率类型 0:变码率, 1:定码率
	BYTE byPicQuality;		//图象质量 0-最好 1-次好 2-较好 3-一般 4-较差 5-差
	DWORD dwVideoBitrate; 	//视频码率 0-保留 1-16K 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
	// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
	//最高位(31位)置成1表示是自定义码流, 0-30位表示码流值。
	DWORD dwVideoFrameRate;	//帧率 0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20; V2.0版本中新加14-15; 15-18; 16-22;
	WORD  wIntervalFrameI;  //I帧间隔
	//2006-08-11 增加单P帧的配置接口，可以改善实时流延时问题
	BYTE  byIntervalBPFrame;//0-BBP帧; 1-BP帧; 2-单P帧
 	BYTE  byres1;        //保留
 	BYTE  byVideoEncType;   //视频编码类型 0 私有h264;1标准h264; 2标准mpeg4; 3-M-JPEG
 	BYTE  byAudioEncType;   //音频编码类型 0-OggVorbis;1-G711_U;2-G711_A
 	BYTE  byres[10];//这里保留音频的压缩参数
}NET_DVR_COMPRESSION_INFO_V30, *LPNET_DVR_COMPRESSION_INFO_V30;

//通道压缩参数(9000扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO_V30 struNormHighRecordPara;    //录像 对应8000的普通
	NET_DVR_COMPRESSION_INFO_V30 struRes;//保留 char reserveData[28];
    NET_DVR_COMPRESSION_INFO_V30 struEventRecordPara;       //事件触发压缩参数
	NET_DVR_COMPRESSION_INFO_V30 struNetPara;               //网传(子码流)
}NET_DVR_COMPRESSIONCFG_V30, *LPNET_DVR_COMPRESSIONCFG_V30;

//码流压缩参数(子结构)
typedef struct 
{
	BYTE byStreamType;		//码流类型0-视频流,1-复合流,表示压缩参数时最高位表示是否启用压缩参数
	BYTE byResolution;  	//分辨率0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF, 5-2QCIF(352X144)(车载专用)
	BYTE byBitrateType;		//码率类型0:变码率，1:定码率
	BYTE  byPicQuality;		//图象质量 0-最好 1-次好 2-较好 3-一般 4-较差 5-差
	DWORD dwVideoBitrate; 	//视频码率 0-保留 1-16K(保留) 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
							// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
							//最高位(31位)置成1表示是自定义码流, 0-30位表示码流值(MIN-32K MAX-8192K)。
	DWORD dwVideoFrameRate;	//帧率 0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20;
}NET_DVR_COMPRESSION_INFO, *LPNET_DVR_COMPRESSION_INFO;

//通道压缩参数
typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO struRecordPara; //录像/事件触发录像
	NET_DVR_COMPRESSION_INFO struNetPara;	//网传/保留
}NET_DVR_COMPRESSIONCFG, *LPNET_DVR_COMPRESSIONCFG;

//码流压缩参数(子结构)(扩展) 增加I帧间隔
typedef struct 
{
	BYTE byStreamType;		//码流类型0-视频流, 1-复合流
	BYTE byResolution;  	//分辨率0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF, 5-2QCIF(352X144)(车载专用)
	BYTE byBitrateType;		//码率类型0:变码率，1:定码率
	BYTE  byPicQuality;		//图象质量 0-最好 1-次好 2-较好 3-一般 4-较差 5-差
	DWORD dwVideoBitrate; 	//视频码率 0-保留 1-16K(保留) 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
	// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
	//最高位(31位)置成1表示是自定义码流, 0-30位表示码流值(MIN-32K MAX-8192K)。
	DWORD dwVideoFrameRate;	//帧率 0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20, //V2.0增加14-15, 15-18, 16-22;
	WORD  wIntervalFrameI;  //I帧间隔
	//2006-08-11 增加单P帧的配置接口，可以改善实时流延时问题
	BYTE  byIntervalBPFrame;//0-BBP帧; 1-BP帧; 2-单P帧
	BYTE  byRes;
}NET_DVR_COMPRESSION_INFO_EX, *LPNET_DVR_COMPRESSION_INFO_EX;

//通道压缩参数(扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO_EX struRecordPara; //录像
	NET_DVR_COMPRESSION_INFO_EX struNetPara;	//网传
}NET_DVR_COMPRESSIONCFG_EX, *LPNET_DVR_COMPRESSIONCFG_EX;


//时间段录像参数配置(子结构)
typedef struct 
{
	NET_DVR_SCHEDTIME struRecordTime;
	BYTE byRecordType;	//0:定时录像，1:移动侦测，2:报警录像，3:动测|报警，4:动测&报警, 5:命令触发, 6: 智能录像
	char reservedData[3];
}NET_DVR_RECORDSCHED, *LPNET_DVR_RECORDSCHED;

//全天录像参数配置(子结构)
typedef struct 
{
	WORD wAllDayRecord;				/* 是否全天录像 0-否 1-是*/
	BYTE byRecordType;				/* 录象类型 0:定时录像，1:移动侦测，2:报警录像，3:动测|报警，4:动测&报警 5:命令触发, 6: 智能录像*/
	char reservedData;
}NET_DVR_RECORDDAY, *LPNET_DVR_RECORDDAY;

//通道录像参数配置(9000扩展)
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwRecord;  						/*是否录像 0-否 1-是*/
	NET_DVR_RECORDDAY	struRecAllDay[MAX_DAYS];
	NET_DVR_RECORDSCHED	struRecordSched[MAX_DAYS][MAX_TIMESEGMENT_V30];
	DWORD	dwRecordTime;					/* 录象延时长度 0-5秒， 1-20秒， 2-30秒， 3-1分钟， 4-2分钟， 5-5分钟， 6-10分钟*/
	DWORD	dwPreRecordTime;				/* 预录时间 0-不预录 1-5秒 2-10秒 3-15秒 4-20秒 5-25秒 6-30秒 7-0xffffffff(尽可能预录) */
	DWORD	dwRecorderDuration;				/* 录像保存的最长时间 */
	BYTE	byRedundancyRec;	/*是否冗余录像,重要数据双备份：0/1*/
	BYTE	byAudioRec;		/*录像时复合流编码时是否记录音频数据：国外有此法规*/
	BYTE	byReserve[10];	
}NET_DVR_RECORD_V30, *LPNET_DVR_RECORD_V30;

//通道录像参数配置
typedef struct 
{
	DWORD dwSize;
	DWORD dwRecord;  /*是否录像 0-否 1-是*/
	NET_DVR_RECORDDAY struRecAllDay[MAX_DAYS];
	NET_DVR_RECORDSCHED struRecordSched[MAX_DAYS][MAX_TIMESEGMENT];
	DWORD dwRecordTime;	/* 录象时间长度 */
	DWORD dwPreRecordTime;	/* 预录时间 0-不预录 1-5秒 2-10秒 3-15秒 4-20秒 5-25秒 6-30秒 7-0xffffffff(尽可能预录) */
}NET_DVR_RECORD, *LPNET_DVR_RECORD;

//云台协议表结构配置
typedef struct
{ 
    DWORD dwType;               /*解码器类型值*/    
    BYTE  byDescribe[DESC_LEN]; /*解码器的描述符，和8000中的一致*/    
}NET_DVR_PTZ_PROTOCOL;

typedef struct
{    
    DWORD   dwSize;    
    NET_DVR_PTZ_PROTOCOL struPtz[PTZ_PROTOCOL_NUM];/*最大200中PTZ协议*/    
    DWORD   dwPtzNum;           /*有效的ptz协议数目，从0开始(即计算时加1)*/
    BYTE    byRes[8];
}NET_DVR_PTZCFG, *LPNET_DVR_PTZCFG;

/***************************云台类型(end)******************************/

//通道解码器(云台)参数配置(9000扩展)
typedef struct 
{
	DWORD dwSize;
	DWORD dwBaudRate;//波特率(bps)，0－50，1－75，2－110，3－150，4－300，5－600，6－1200，7－2400，8－4800，9－9600，10－19200， 11－38400，12－57600，13－76800，14－115.2k;
	BYTE byDataBit;// 数据有几位 0－5位，1－6位，2－7位，3－8位;
	BYTE byStopBit;// 停止位 0－1位，1－2位;
	BYTE byParity;// 校验 0－无校验，1－奇校验，2－偶校验;
	BYTE byFlowcontrol;// 0－无，1－软流控,2-硬流控
	WORD wDecoderType;//解码器类型, 从0开始，对应ptz协议列表从NET_DVR_IPC_PROTO_LIST得到
	WORD wDecoderAddress;	/*解码器地址:0 - 255*/
	BYTE bySetPreset[MAX_PRESET_V30];		/* 预置点是否设置,0-没有设置,1-设置*/
	BYTE bySetCruise[MAX_CRUISE_V30];		/* 巡航是否设置: 0-没有设置,1-设置 */
	BYTE bySetTrack[MAX_TRACK_V30];		    /* 轨迹是否设置,0-没有设置,1-设置*/
}NET_DVR_DECODERCFG_V30, *LPNET_DVR_DECODERCFG_V30;

//通道解码器(云台)参数配置
typedef struct 
{
	DWORD dwSize;
	DWORD dwBaudRate;       //波特率(bps)，0－50，1－75，2－110，3－150，4－300，5－600，6－1200，7－2400，8－4800，9－9600，10－19200， 11－38400，12－57600，13－76800，14－115.2k;
	BYTE byDataBit;         // 数据有几位 0－5位，1－6位，2－7位，3－8位;
	BYTE byStopBit;         // 停止位 0－1位，1－2位;
	BYTE byParity;          // 校验 0－无校验，1－奇校验，2－偶校验;
	BYTE byFlowcontrol;     // 0－无，1－软流控,2-硬流控
	WORD wDecoderType;      //解码器类型  NET_DVR_IPC_PROTO_LIST中得到
	WORD wDecoderAddress;	/*解码器地址:0 - 255*/
	BYTE bySetPreset[MAX_PRESET];		/* 预置点是否设置,0-没有设置,1-设置*/
	BYTE bySetCruise[MAX_CRUISE];		/* 巡航是否设置: 0-没有设置,1-设置 */
	BYTE bySetTrack[MAX_TRACK];		/* 轨迹是否设置,0-没有设置,1-设置*/
}NET_DVR_DECODERCFG, *LPNET_DVR_DECODERCFG;

//ppp参数配置(子结构)
typedef struct 
{
	NET_DVR_IPADDR struRemoteIP;	//远端IP地址
	NET_DVR_IPADDR struLocalIP;		//本地IP地址
	char sLocalIPMask[16];			//本地IP地址掩码
	BYTE sUsername[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	BYTE byPPPMode;					//PPP模式, 0－主动，1－被动
	BYTE byRedial;					//是否回拨 ：0-否,1-是
	BYTE byRedialMode;				//回拨模式,0-由拨入者指定,1-预置回拨号码
	BYTE byDataEncrypt;				//数据加密,0-否,1-是
	DWORD dwMTU;					//MTU
	char sTelephoneNumber[PHONENUMBER_LEN];   //电话号码
}NET_DVR_PPPCFG_V30, *LPNET_DVR_PPPCFG_V30;

//ppp参数配置(子结构)
typedef struct 
{
	char sRemoteIP[16];				//远端IP地址
	char sLocalIP[16];				//本地IP地址
	char sLocalIPMask[16];			//本地IP地址掩码
	BYTE sUsername[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	BYTE byPPPMode;					//PPP模式, 0－主动，1－被动
	BYTE byRedial;					//是否回拨 ：0-否,1-是
	BYTE byRedialMode;				//回拨模式,0-由拨入者指定,1-预置回拨号码
	BYTE byDataEncrypt;				//数据加密,0-否,1-是
	DWORD dwMTU;					//MTU
	char sTelephoneNumber[PHONENUMBER_LEN];   //电话号码
}NET_DVR_PPPCFG, *LPNET_DVR_PPPCFG;

//RS232串口参数配置(9000扩展)
typedef struct
{
    DWORD dwBaudRate;   /*波特率(bps)，0－50，1－75，2－110，3－150，4－300，5－600，6－1200，7－2400，8－4800，9－9600，10－19200， 11－38400，12－57600，13－76800，14－115.2k;*/
    BYTE byDataBit;     /* 数据有几位 0－5位，1－6位，2－7位，3－8位 */
    BYTE byStopBit;     /* 停止位 0－1位，1－2位 */
    BYTE byParity;      /* 校验 0－无校验，1－奇校验，2－偶校验 */
    BYTE byFlowcontrol; /* 0－无，1－软流控,2-硬流控 */
    DWORD dwWorkMode;   /* 工作模式，0－232串口用于PPP拨号，1－232串口用于参数控制，2－透明通道  3- ptz模式 4-报警盒模式*/
}NET_DVR_SINGLE_RS232;

//RS232串口参数配置(9000扩展)
typedef struct 
{
	DWORD dwSize;
    NET_DVR_SINGLE_RS232 struRs232[MAX_SERIAL_PORT];/*注意：此结构修改了，原来是单个结构，现在修改为了数组结构*/
	NET_DVR_PPPCFG_V30 struPPPConfig;
}NET_DVR_RS232CFG_V30, *LPNET_DVR_RS232CFG_V30;

//RS232串口参数配置
typedef struct 
{
	DWORD dwSize;
	DWORD dwBaudRate;//波特率(bps)，0－50，1－75，2－110，3－150，4－300，5－600，6－1200，7－2400，8－4800，9－9600，10－19200， 11－38400，12－57600，13－76800，14－115.2k;
	BYTE byDataBit;// 数据有几位 0－5位，1－6位，2－7位，3－8位;
	BYTE byStopBit;// 停止位 0－1位，1－2位;
	BYTE byParity;// 校验 0－无校验，1－奇校验，2－偶校验;
	BYTE byFlowcontrol;// 0－无，1－软流控,2-硬流控
	DWORD dwWorkMode;// 工作模式，0－窄带传输(232串口用于PPP拨号)，1－控制台(232串口用于参数控制)，2－透明通道
	NET_DVR_PPPCFG struPPPConfig;
}NET_DVR_RS232CFG, *LPNET_DVR_RS232CFG;

//报警输入参数配置(9000扩展)
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmInName[NAME_LEN];	/* 名称 */
	BYTE byAlarmType;	            //报警器类型,0：常开,1：常闭
	BYTE byAlarmInHandle;	        /* 是否处理 0-不处理 1-处理*/
    BYTE byChannel;                 // 报警输入触发智能识别通道
    BYTE byRes1[1];			
	NET_DVR_HANDLEEXCEPTION_V30 struAlarmHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30];//布防时间
	BYTE byRelRecordChan[MAX_CHANNUM_V30]; //报警触发的录象通道,为1表示触发该通道
	BYTE byEnablePreset[MAX_CHANNUM_V30];		/* 是否调用预置点 0-否,1-是*/
	BYTE byPresetNo[MAX_CHANNUM_V30];			/* 调用的云台预置点序号,一个报警输入可以调用多个通道的云台预置点, 0xff表示不调用预置点。*/
	BYTE byRes2[192];					/*保留*/
	BYTE byEnableCruise[MAX_CHANNUM_V30];		/* 是否调用巡航 0-否,1-是*/
	BYTE byCruiseNo[MAX_CHANNUM_V30];			/* 巡航 */
	BYTE byEnablePtzTrack[MAX_CHANNUM_V30];		/* 是否调用轨迹 0-否,1-是*/
	BYTE byPTZTrack[MAX_CHANNUM_V30];			/* 调用的云台的轨迹序号 */
    BYTE byRes3[16];
}NET_DVR_ALARMINCFG_V30, *LPNET_DVR_ALARMINCFG_V30;

//报警输入参数配置
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmInName[NAME_LEN];	/* 名称 */
	BYTE byAlarmType;	//报警器类型,0：常开,1：常闭
	BYTE byAlarmInHandle;	/* 是否处理 0-不处理 1-处理*/
    BYTE byChannel;                 // 报警输入触发智能识别通道
    BYTE byRes;                     
    NET_DVR_HANDLEEXCEPTION struAlarmHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//布防时间
	BYTE byRelRecordChan[MAX_CHANNUM]; //报警触发的录象通道,为1表示触发该通道
	BYTE byEnablePreset[MAX_CHANNUM];		/* 是否调用预置点 0-否,1-是*/
	BYTE byPresetNo[MAX_CHANNUM];			/* 调用的云台预置点序号,一个报警输入可以调用多个通道的云台预置点, 0xff表示不调用预置点。*/
	BYTE byEnableCruise[MAX_CHANNUM];		/* 是否调用巡航 0-否,1-是*/
	BYTE byCruiseNo[MAX_CHANNUM];			/* 巡航 */
	BYTE byEnablePtzTrack[MAX_CHANNUM];		/* 是否调用轨迹 0-否,1-是*/
	BYTE byPTZTrack[MAX_CHANNUM];			/* 调用的云台的轨迹序号 */
}NET_DVR_ALARMINCFG, *LPNET_DVR_ALARMINCFG;


//上传报警信息(9000扩展)
typedef struct 
{
	DWORD dwAlarmType;/*0-信号量报警,1-硬盘满,2-信号丢失,3－移动侦测,4－硬盘未格式化,5-读写硬盘出错,6-遮挡报警,7-制式不匹配, 8-非法访问, 9-视频信号异常，
                        10-录像异常 11- 智能场景变化  12-阵列异常 */
	DWORD dwAlarmInputNumber;/*报警输入端口*/
	BYTE byAlarmOutputNumber[MAX_ALARMOUT_V30];/*触发的输出端口，为1表示对应输出*/
	BYTE byAlarmRelateChannel[MAX_CHANNUM_V30];/*触发的录像通道，为1表示对应录像, dwAlarmRelateChannel[0]对应第1个通道*/
	BYTE byChannel[MAX_CHANNUM_V30];/*dwAlarmType为2或3,6，9，10时，表示哪个通道，dwChannel[0]对应第1个通道*/
	BYTE byDiskNumber[MAX_DISKNUM_V30];/*dwAlarmType为1,4,5时,表示哪个硬盘, dwDiskNumber[0]对应第1个硬盘*/
#ifdef SDK_CHEZAI
	NET_DVR_ADDIT_POSITION GPS_pos;  /* GPS定位信息 */
#endif
}NET_DVR_ALARMINFO_V30, *LPNET_DVR_ALARMINFO_V30;


typedef struct 
{
	DWORD dwAlarmType;/*0-信号量报警,1-硬盘满,2-信号丢失,3－移动侦测,4－硬盘未格式化,5-读写硬盘出错,6-遮挡报警,7-制式不匹配, 8-非法访问, 9-视频信号异常，10-录像异常 11- 智能场景变化*/
	DWORD dwAlarmInputNumber;/*报警输入端口*/
	DWORD dwAlarmOutputNumber[MAX_ALARMOUT];/*触发的输出端口，哪一位为1表示对应哪一个输出*/
	DWORD dwAlarmRelateChannel[MAX_CHANNUM];/*触发的录像通道，哪一位为1表示对应哪一路录像, dwAlarmRelateChannel[0]对应第1个通道*/
	DWORD dwChannel[MAX_CHANNUM];/*dwAlarmType为2或3,6,9,10时，表示哪个通道，dwChannel[0]位对应第1个通道*/
	DWORD dwDiskNumber[MAX_DISKNUM];/*dwAlarmType为1,4,5时,表示哪个硬盘, dwDiskNumber[0]位对应第1个硬盘*/
}NET_DVR_ALARMINFO, *LPNET_DVR_ALARMINFO;




//////////////////////////////////////////////////////////////////////////////////////
//IPC接入参数配置
/* IP设备结构 */
typedef struct 
{
    DWORD dwEnable;				    /* 该IP设备是否启用 */
    BYTE sUserName[NAME_LEN];		/* 用户名 */
    BYTE sPassword[PASSWD_LEN];	    /* 密码 */ 
    NET_DVR_IPADDR struIP;			/* IP地址 */
    WORD wDVRPort;			 	    /* 端口号 */
    BYTE byRes[34];				/* 保留 */
}NET_DVR_IPDEVINFO, *LPNET_DVR_IPDEVINFO;

//ipc接入设备信息扩展，支持ip设备的域名添加
typedef struct tagNET_DVR_IPDEVINFO_V31
{
    BYTE byEnable;				    //该IP设备是否有效
	BYTE byProType;					//协议类型，0-私有协议，1-松下协议，2-索尼
    BYTE byEnableQuickAdd;        // 0 不支持快速添加  1 使用快速添加 
    // 快速添加需要设备IP和协议类型，其他信息由设备默认指定
    BYTE byRes1;					//保留字段，置0
    BYTE sUserName[NAME_LEN];		//用户名
    BYTE sPassword[PASSWD_LEN];	    //密码
    BYTE byDomain[MAX_DOMAIN_NAME];	//设备域名
    NET_DVR_IPADDR struIP;			//IP地址
    WORD wDVRPort;			 	    // 端口号
    BYTE byRes2[34];				//保留字段，置0
}NET_DVR_IPDEVINFO_V31, *LPNET_DVR_IPDEVINFO_V31;

/* IP通道匹配参数 */
typedef struct 
{
    BYTE byEnable;					/* 该通道是否在线 */
    BYTE byIPID;					/* IP设备ID 取值1- MAX_IP_DEVICE */
    BYTE byChannel;					/* 通道号 */
	BYTE byres[33];					//保留,置0
} NET_DVR_IPCHANINFO, *LPNET_DVR_IPCHANINFO;

/* IP接入配置结构 */
typedef struct 
{
    DWORD dwSize;			                            /* 结构大小 */
    NET_DVR_IPDEVINFO  struIPDevInfo[MAX_IP_DEVICE];    /* IP设备 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];        /* 模拟通道是否启用，从低到高表示1-32通道，0表示无效 1有效 */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	/* IP通道 */    
}NET_DVR_IPPARACFG, *LPNET_DVR_IPPARACFG;
/* 扩展IP接入配置结构 */
typedef struct tagNET_DVR_IPPARACFG_V31
{
    DWORD dwSize;			                            /* 结构大小 */
    NET_DVR_IPDEVINFO_V31  struIPDevInfo[MAX_IP_DEVICE];    /* IP设备 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];        /* 模拟通道是否启用，从低到高表示1-32通道，0表示无效 1有效 */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	/* IP通道 */    
}NET_DVR_IPPARACFG_V31, *LPNET_DVR_IPPARACFG_V31;

typedef  struct tagNET_DVR_IPSERVER_STREAM
{
    BYTE    byEnable;   // 是否启用
    BYTE    byRes[3];               // 保留字节
    NET_DVR_IPADDR struIPServer;    //IPServer 地址
    WORD    wPort;                  //IPServer 端口
    WORD    wDvrNameLen;            // DVR 名称长度
    BYTE    byDVRName[NAME_LEN];    // DVR名称
    WORD    wDVRSerialLen;          // 序列号长度
    WORD    byRes1[2];              // 保留字节
    BYTE    byDVRSerialNumber[SERIALNO_LEN];    // DVR序列号长度
    BYTE    byUserName[NAME_LEN];   // DVR 登陆用户名
    BYTE    byPassWord[PASSWD_LEN]; // DVR登陆密码
    BYTE    byChannel;              // DVR 通道
    BYTE    byRes2[11];             //  保留字节
}NET_DVR_IPSERVER_STREAM, *LPNET_DVR_IPSERVER_STREAM;

/*流媒体服务器基本配置*/
typedef struct tagNET_DVR_STREAM_MEDIA_SERVER_CFG
{
    BYTE	byValid;			/*是否启用流媒体服务器取流,0表示无效，非0表示有效*/
    BYTE	byRes1[3];
    NET_DVR_IPADDR  struDevIP;      
    WORD	wDevPort;			/*流媒体服务器端口*/    
    BYTE	byTransmitType;		/*传输协议类型 0-TCP，1-UDP*/
    BYTE	byRes2[69];
}NET_DVR_STREAM_MEDIA_SERVER_CFG,*LPNET_DVR_STREAM_MEDIA_SERVER_CFG;

//设备通道信息
typedef struct tagNET_DVR_DEV_CHAN_INFO
{
    NET_DVR_IPADDR 	struIP;		    //DVR IP地址
    WORD 	wDVRPort;			 	//端口号
    BYTE 	byChannel;				//通道号
    BYTE	byTransProtocol;		//传输协议类型0-TCP，1-UDP
    BYTE	byTransMode;			//传输码流模式 0－主码流 1－子码流
    BYTE	byFactoryType;			/*前端设备厂家类型,通过接口获取*/
    BYTE	byRes[6];
    BYTE    byDomain[MAX_DOMAIN_NAME];	//设备域名
    BYTE	sUserName[NAME_LEN];	//监控主机登陆帐号
    BYTE	sPassword[PASSWD_LEN];	//监控主机密码
}NET_DVR_DEV_CHAN_INFO,*LPNET_DVR_DEV_CHAN_INFO;

typedef struct tagNET_DVR_PU_STREAM_CFG
{
    DWORD								dwSize;
    NET_DVR_STREAM_MEDIA_SERVER_CFG	struStreamMediaSvrCfg;
    NET_DVR_DEV_CHAN_INFO				struDevChanInfo;
}NET_DVR_PU_STREAM_CFG,*LPNET_DVR_PU_STREAM_CFG;

typedef union tagNET_DVR_GET_STREAM_UNION
{
    NET_DVR_IPCHANINFO      struChanInfo;	/*IP通道信息*/
    NET_DVR_IPSERVER_STREAM struIPServerStream;  // IPServer去流
    NET_DVR_PU_STREAM_CFG  struPUStream;     //  通过前端设备获取流媒体去流
}NET_DVR_GET_STREAM_UNION, *LPNET_DVR_GET_STREAM_UNION;

typedef enum
{
    IP_DEVICE = 0,
    STREAM_MEDIA,
    IPSERVER
}GET_STREAM_TYPE;

typedef struct tagNET_DVR_STREAM_MODE
{
    BYTE    byGetStreamType; //取流方式，0-直接从设备取流，1-从流媒体取流、2-通过IPServer获得ip地址后取流
    BYTE    byRes[3];      // 保留字节
    NET_DVR_GET_STREAM_UNION uGetStream;    // 不同取流方式结构体
}NET_DVR_STREAM_MODE, *LPNET_DVR_STREAM_MODE;
/*扩展IP接入配置设备*/
typedef struct tagNET_DVR_IPPARACFG_V40
{
    DWORD      dwSize;			                /* 结构大小 */
    DWORD      dwAChanNum;					//最大模拟通道个数
    DWORD      dwDChanNum;                  //数字通道个数
    DWORD      dwStartDChan;		            //起始数字通道
    BYTE       byAnalogChanEnable[MAX_CHANNUM_V30];    /* 模拟通道是否启用，从低到高表示1-64通道，0表示无效 1有效 */
    NET_DVR_IPDEVINFO_V31   struIPDevInfo[MAX_IP_DEVICE_V40];      /* IP设备 */
    NET_DVR_STREAM_MODE  struStreamMode [MAX_CHANNUM_V30];
    BYTE            byRes2[20];                 // 保留字节
}NET_DVR_IPPARACFG_V40, *LPNET_DVR_IPPARACFG_V40;

/* 报警输出参数 */
typedef struct 
{
    BYTE byIPID;					/* IP设备ID取值1- MAX_IP_DEVICE */
    BYTE byAlarmOut;				/* 报警输出号 */
    BYTE byRes[18];					/* 保留 */
}NET_DVR_IPALARMOUTINFO, *LPNET_DVR_IPALARMOUTINFO;

/* IP报警输出配置结构 */
typedef struct 
{
    DWORD dwSize;			                        /* 结构大小 */    
   NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT];/* IP报警输出 */
}NET_DVR_IPALARMOUTCFG, *LPNET_DVR_IPALARMOUTCFG;

/* 报警输入参数 */
typedef struct 
{
    BYTE byIPID;					/* IP设备ID取值1- MAX_IP_DEVICE */
    BYTE byAlarmIn;					/* 报警输入号 */
    BYTE byRes[18];					/* 保留 */
}NET_DVR_IPALARMININFO, *LPNET_DVR_IPALARMININFO;

/* IP报警输入配置结构 */
typedef struct 
{
    DWORD dwSize;			                        /* 结构大小 */    
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];/* IP报警输入 */
}NET_DVR_IPALARMINCFG, *LPNET_DVR_IPALARMINCFG;

//ipc alarm info
typedef struct tagNET_DVR_IPALARMINFO
{
    NET_DVR_IPDEVINFO  struIPDevInfo[MAX_IP_DEVICE];            /* IP设备 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];                /* 模拟通道是否启用，0-未启用 1-启用 */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	        /* IP通道 */
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];    /* IP报警输入 */
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT]; /* IP报警输出 */
}NET_DVR_IPALARMINFO, *LPNET_DVR_IPALARMINFO;

//ipc配置改变报警信息扩展 9000_1.1
typedef struct tagNET_DVR_IPALARMINFO_V31
{
    NET_DVR_IPDEVINFO_V31  struIPDevInfo[MAX_IP_DEVICE];            /* IP设备 */
    BYTE byAnalogChanEnable[MAX_ANALOG_CHANNUM];                /* 模拟通道是否启用，0-未启用 1-启用 */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_IP_CHANNEL];	        /* IP通道 */
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];    /* IP报警输入 */
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT]; /* IP报警输出 */   
}NET_DVR_IPALARMINFO_V31, *LPNET_DVR_IPALARMINFO_V31;

typedef struct tagNET_DVR_IPALARMINFO_V40
{
    NET_DVR_IPDEVINFO_V31 struIPDevInfo[MAX_IP_DEVICE_V40];           // IP设备
    BYTE     byAnalogChanEnable[MAX_CHANNUM_V30];           /* 模拟通道是否启用，0-未启用 1-启用 */
    NET_DVR_IPCHANINFO struIPChanInfo[MAX_CHANNUM_V30];	        /* IP通道 */
    NET_DVR_IPALARMININFO struIPAlarmInInfo[MAX_IP_ALARMIN];    /* IP报警输入 */
    NET_DVR_IPALARMOUTINFO struIPAlarmOutInfo[MAX_IP_ALARMOUT]; /* IP报警输出 */   
    BYTE                    byRes[20];                          // 保留字节
}NET_DVR_IPALARMINFO_V40, *LPNET_DVR_IPALARMINFO_V40;

typedef enum _HD_STAT_
{
	HD_STAT_OK					=	0,  /* 正常 */
	HD_STAT_UNFORMATTED			=	1,  /* 未格式化 */
	HD_STAT_ERROR           	=	2,  /* 错误 */
	HD_STAT_SMART_FAILED    	=	3,  /* SMART状态 */
	HD_STAT_MISMATCH        	=	4,  /* 不匹配 */
	HD_STAT_IDLE            	=	5,  /* 休眠*/
	NET_HD_STAT_OFFLINE     	=	6  /*网络盘处于未连接状态 */	
}HD_STAT;


//本地硬盘信息配置
typedef struct
{
    DWORD dwHDNo;         /*硬盘号, 取值0~MAX_DISKNUM_V30-1*/
    DWORD dwCapacity;     /*硬盘容量(不可设置)*/
    DWORD dwFreeSpace;    /*硬盘剩余空间(不可设置)*/
    DWORD dwHdStatus;     /*硬盘状态(不可设置) HD_STAT*/
    BYTE  byHDAttr;       /*0-默认, 1-冗余; 2-只读*/
	BYTE  byHDType;		  /*0-本地硬盘,1-ESATA硬盘,2-NAS硬盘,3-iSCSI硬盘 4-Array虚拟磁盘*/
    BYTE  byDiskDriver;   // 值 代表其ASCII字符 
	BYTE  byRes1[1];
    DWORD dwHdGroup;      /*属于哪个盘组 1-MAX_HD_GROUP*/
    BYTE  byRes2[120];
}NET_DVR_SINGLE_HD, *LPNET_DVR_SINGLE_HD;

typedef struct
{
    DWORD dwSize;
    DWORD dwHDCount;          /*硬盘数(不可设置)*/
    NET_DVR_SINGLE_HD struHDInfo[MAX_DISKNUM_V30];//硬盘相关操作都需要重启才能生效；
}NET_DVR_HDCFG, *LPNET_DVR_HDCFG;

//本地盘组信息配置
typedef struct
{
    DWORD dwHDGroupNo;       /*盘组号(不可设置) 1-MAX_HD_GROUP*/        
    BYTE byHDGroupChans[MAX_CHANNUM_V30]; /*盘组对应的录像通道, 0-表示该通道不录象到该盘组，1-表示录象到该盘组*/
    BYTE byRes[8];
}NET_DVR_SINGLE_HDGROUP, *LPNET_DVR_SINGLE_HDGROUP;

typedef struct
{
    DWORD dwSize;
    DWORD dwHDGroupCount;        /*盘组总数(不可设置)*/
    NET_DVR_SINGLE_HDGROUP struHDGroupAttr[MAX_HD_GROUP];//硬盘相关操作都需要重启才能生效；
}NET_DVR_HDGROUP_CFG, *LPNET_DVR_HDGROUP_CFG;
                                       

//配置缩放参数的结构
typedef struct
{
    DWORD dwSize;
    DWORD dwMajorScale;    /* 主显示 0-不缩放，1-缩放*/
    DWORD dwMinorScale;    /* 辅显示 0-不缩放，1-缩放*/
    DWORD dwRes[2];
}NET_DVR_SCALECFG, *LPNET_DVR_SCALECFG;



//DVR报警输出(9000扩展)
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmOutName[NAME_LEN];	/* 名称 */
	DWORD dwAlarmOutDelay;	/* 输出保持时间(-1为无限，手动关闭) */
	//0-5秒,1-10秒,2-30秒,3-1分钟,4-2分钟,5-5分钟,6-10分钟,7-手动
	NET_DVR_SCHEDTIME struAlarmOutTime[MAX_DAYS][MAX_TIMESEGMENT_V30];/* 报警输出激活时间段 */
    BYTE byRes[16];
}NET_DVR_ALARMOUTCFG_V30, *LPNET_DVR_ALARMOUTCFG_V30;

//DVR报警输出
typedef struct 
{
	DWORD dwSize;
	BYTE sAlarmOutName[NAME_LEN];	/* 名称 */
	DWORD dwAlarmOutDelay;	/* 输出保持时间(-1为无限，手动关闭) */
	//0-5秒,1-10秒,2-30秒,3-1分钟,4-2分钟,5-5分钟,6-10分钟,7-手动
	NET_DVR_SCHEDTIME struAlarmOutTime[MAX_DAYS][MAX_TIMESEGMENT];/* 报警输出激活时间段 */
}NET_DVR_ALARMOUTCFG, *LPNET_DVR_ALARMOUTCFG;

//DVR本地预览参数(9000扩展)
typedef struct 
{
    DWORD dwSize;
    BYTE byPreviewNumber;//预览数目,0-1画面,1-4画面,2-9画面,3-16画面,0xff:最大画面
    BYTE byEnableAudio;//是否声音预览,0-不预览,1-预览
    WORD wSwitchTime;//切换时间,0-不切换,1-5s,2-10s,3-20s,4-30s,5-60s,6-120s,7-300s
    BYTE bySwitchSeq[MAX_PREVIEW_MODE][MAX_WINDOW_V30];//切换顺序,如果lSwitchSeq[i]为 0xff表示不用
    BYTE byRes[24];
}NET_DVR_PREVIEWCFG_V30, *LPNET_DVR_PREVIEWCFG_V30;
//DVR本地预览参数
typedef struct 
{
	DWORD dwSize;
	BYTE byPreviewNumber;//预览数目,0-1画面,1-4画面,2-9画面,3-16画面,0xff:最大画面
	BYTE byEnableAudio;//是否声音预览,0-不预览,1-预览
	WORD wSwitchTime;//切换时间,0-不切换,1-5s,2-10s,3-20s,4-30s,5-60s,6-120s,7-300s
	BYTE bySwitchSeq[MAX_WINDOW];//切换顺序,如果lSwitchSeq[i]为 0xff表示不用
}NET_DVR_PREVIEWCFG, *LPNET_DVR_PREVIEWCFG;

//DVR视频输出
typedef struct 
{
	WORD wResolution;							/* 分辨率 */
	WORD wFreq;									/* 刷新频率 */
	DWORD dwBrightness;							/* 亮度 */
}NET_DVR_VGAPARA;

/*
* MATRIX输出参数结构
*/
typedef struct
{		
	WORD	wOrder[MAX_ANALOG_CHANNUM];		/* 预览顺序, 0xff表示相应的窗口不预览 */
	WORD	wSwitchTime;				/* 预览切换时间 */
	BYTE	res[14];
}NET_DVR_MATRIXPARA_V30, *LPNET_DVR_MATRIXPARA_V30;

typedef struct 
{
	WORD wDisplayLogo;						/* 显示视频通道号 */
	WORD wDisplayOsd;						/* 显示时间 */
}NET_DVR_MATRIXPARA;

typedef struct 
{
	BYTE byVideoFormat;						/* 输出制式,0-PAL,1-NTSC */
	BYTE byMenuAlphaValue;					/* 菜单与背景图象对比度 */
	WORD wScreenSaveTime;					/* 屏幕保护时间 0-从不,1-1分钟,2-2分钟,3-5分钟,4-10分钟,5-20分钟,6-30分钟 */
	WORD wVOffset;							/* 视频输出偏移 */
	WORD wBrightness;						/* 视频输出亮度 */
	BYTE byStartMode;						/* 启动后视频输出模式(0:菜单,1:预览)*/
	BYTE byEnableScaler;                    /* 是否启动缩放 (0-不启动, 1-启动)*/
}NET_DVR_VOOUT;

//DVR视频输出(9000扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_VOOUT struVOOut[MAX_VIDEOOUT_V30];
	NET_DVR_VGAPARA struVGAPara[MAX_VGA_V30];	/* VGA参数 */
	NET_DVR_MATRIXPARA_V30 struMatrixPara[MAX_MATRIXOUT];		/* MATRIX参数 */
    BYTE byRes[16];
}NET_DVR_VIDEOOUT_V30, *LPNET_DVR_VIDEOOUT_V30;

//DVR视频输出
typedef struct 
{
	DWORD dwSize;
	NET_DVR_VOOUT struVOOut[MAX_VIDEOOUT];
	NET_DVR_VGAPARA struVGAPara[MAX_VGA];	/* VGA参数 */
	NET_DVR_MATRIXPARA struMatrixPara;		/* MATRIX参数 */
}NET_DVR_VIDEOOUT, *LPNET_DVR_VIDEOOUT;

//单用户参数(子结构)(9000扩展)
typedef struct
{
	BYTE sUserName[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	BYTE byLocalRight[MAX_RIGHT];	/* 本地权限 */
	/*数组0: 本地控制云台*/
	/*数组1: 本地手动录象*/
	/*数组2: 本地回放*/
	/*数组3: 本地设置参数*/
	/*数组4: 本地查看状态、日志*/
	/*数组5: 本地高级操作(升级，格式化，重启，关机)*/
    /*数组6: 本地查看参数 */
    /*数组7: 本地管理模拟和IP camera */
    /*数组8: 本地备份 */
    /*数组9: 本地关机/重启 */    
	BYTE byRemoteRight[MAX_RIGHT];/* 远程权限 */	
	/*数组0: 远程控制云台*/
	/*数组1: 远程手动录象*/
	/*数组2: 远程回放 */
	/*数组3: 远程设置参数*/
	/*数组4: 远程查看状态、日志*/
	/*数组5: 远程高级操作(升级，格式化，重启，关机)*/
	/*数组6: 远程发起语音对讲*/
	/*数组7: 远程预览*/
	/*数组8: 远程请求报警上传、报警输出*/
	/*数组9: 远程控制，本地输出*/
	/*数组10: 远程控制串口*/	
    /*数组11: 远程查看参数 */
    /*数组12: 远程管理模拟和IP camera */
    /*数组13: 远程关机/重启 */
	BYTE byNetPreviewRight[MAX_CHANNUM_V30];		/* 远程可以预览的通道 0-有权限，1-无权限*/
	BYTE byLocalPlaybackRight[MAX_CHANNUM_V30];	/* 本地可以回放的通道 0-有权限，1-无权限*/
	BYTE byNetPlaybackRight[MAX_CHANNUM_V30];	/* 远程可以回放的通道 0-有权限，1-无权限*/
	BYTE byLocalRecordRight[MAX_CHANNUM_V30];		/* 本地可以录像的通道 0-有权限，1-无权限*/
	BYTE byNetRecordRight[MAX_CHANNUM_V30];		/* 远程可以录像的通道 0-有权限，1-无权限*/
	BYTE byLocalPTZRight[MAX_CHANNUM_V30];		/* 本地可以PTZ的通道 0-有权限，1-无权限*/
	BYTE byNetPTZRight[MAX_CHANNUM_V30];			/* 远程可以PTZ的通道 0-有权限，1-无权限*/
	BYTE byLocalBackupRight[MAX_CHANNUM_V30];		/* 本地备份权限通道 0-有权限，1-无权限*/
	NET_DVR_IPADDR struUserIP;		/* 用户IP地址(为0时表示允许任何地址) */
	BYTE byMACAddr[MACADDR_LEN];	/* 物理地址 */
	BYTE byPriority;				/* 优先级，0xff-无，0--低，1--中，2--高 */
                                    /*
                                    无……表示不支持优先级的设置
                                    低……默认权限:包括本地和远程回放,本地和远程查看日志和状态,本地和远程关机/重启
                                    中……包括本地和远程控制云台,本地和远程手动录像,本地和远程回放,语音对讲和远程预览
                                          本地备份,本地/远程关机/重启
                                    高……管理员
                                    */
	BYTE	byAlarmOnRight;         // 报警输入口布防权限
	BYTE	byAlarmOffRight;        // 报警输入口撤防权限
	BYTE	byBypassRight;          // 报警输入口旁路权限
	BYTE	byRes[14];	
}NET_DVR_USER_INFO_V30, *LPNET_DVR_USER_INFO_V30;

//单用户参数(SDK_V15扩展)(子结构)
typedef struct 
{
	BYTE sUserName[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	DWORD dwLocalRight[MAX_RIGHT];	/* 权限 */
	/*数组0: 本地控制云台*/
	/*数组1: 本地手动录象*/
	/*数组2: 本地回放*/
	/*数组3: 本地设置参数*/
	/*数组4: 本地查看状态、日志*/
	/*数组5: 本地高级操作(升级，格式化，重启，关机)*/
	DWORD dwLocalPlaybackRight;		/* 本地可以回放的通道 bit0 -- channel 1*/
	DWORD dwRemoteRight[MAX_RIGHT];	/* 权限 */
	/*数组0: 远程控制云台*/
	/*数组1: 远程手动录象*/
	/*数组2: 远程回放 */
	/*数组3: 远程设置参数*/
	/*数组4: 远程查看状态、日志*/
	/*数组5: 远程高级操作(升级，格式化，重启，关机)*/
	/*数组6: 远程发起语音对讲*/
	/*数组7: 远程预览*/
	/*数组8: 远程请求报警上传、报警输出*/
	/*数组9: 远程控制，本地输出*/
	/*数组10: 远程控制串口*/
	DWORD dwNetPreviewRight;		/* 远程可以预览的通道 bit0 -- channel 1*/
	DWORD dwNetPlaybackRight;		/* 远程可以回放的通道 bit0 -- channel 1*/
	char sUserIP[16];				/* 用户IP地址(为0时表示允许任何地址) */
	BYTE byMACAddr[MACADDR_LEN];	/* 物理地址 */
}NET_DVR_USER_INFO_EX, *LPNET_DVR_USER_INFO_EX;

//单用户参数(子结构)
typedef struct 
{
	BYTE sUserName[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	DWORD dwLocalRight[MAX_RIGHT];	/* 权限 */
	/*数组0: 本地控制云台*/
	/*数组1: 本地手动录象*/
	/*数组2: 本地回放*/
	/*数组3: 本地设置参数*/
	/*数组4: 本地查看状态、日志*/
	/*数组5: 本地高级操作(升级，格式化，重启，关机)*/
	DWORD dwRemoteRight[MAX_RIGHT];	/* 权限 */
	/*数组0: 远程控制云台*/
	/*数组1: 远程手动录象*/
	/*数组2: 远程回放 */
	/*数组3: 远程设置参数*/
	/*数组4: 远程查看状态、日志*/
	/*数组5: 远程高级操作(升级，格式化，重启，关机)*/
	/*数组6: 远程发起语音对讲*/
	/*数组7: 远程预览*/
	/*数组8: 远程请求报警上传、报警输出*/
	/*数组9: 远程控制，本地输出*/
	/*数组10: 远程控制串口*/
	char sUserIP[16];				/* 用户IP地址(为0时表示允许任何地址) */
	BYTE byMACAddr[MACADDR_LEN];	/* 物理地址 */
}NET_DVR_USER_INFO, *LPNET_DVR_USER_INFO;


//DVR用户参数(9000扩展)
typedef struct
{
	DWORD dwSize;
	NET_DVR_USER_INFO_V30 struUser[MAX_USERNUM_V30];
}NET_DVR_USER_V30, *LPNET_DVR_USER_V30;

//DVR用户参数(SDK_V15扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_USER_INFO_EX struUser[MAX_USERNUM];
}NET_DVR_USER_EX, *LPNET_DVR_USER_EX;

//DVR用户参数
typedef struct 
{
	DWORD dwSize;
	NET_DVR_USER_INFO struUser[MAX_USERNUM];
}NET_DVR_USER, *LPNET_DVR_USER;

//DVR异常参数(9000扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_HANDLEEXCEPTION_V30 struExceptionHandleType[MAX_EXCEPTIONNUM_V30];
	/*数组0-盘满,1- 硬盘出错,2-网线断,3-局域网内IP 地址冲突, 4-非法访问, 5-输入/输出视频制式不匹配, 6-视频信号异常, 7-录像异常*/
}NET_DVR_EXCEPTION_V30, *LPNET_DVR_EXCEPTION_V30;

//DVR异常参数
typedef struct 
{
	DWORD dwSize;
	NET_DVR_HANDLEEXCEPTION struExceptionHandleType[MAX_EXCEPTIONNUM];
	/*数组0-盘满,1- 硬盘出错,2-网线断,3-局域网内IP 地址冲突,4-非法访问, 5-输入/输出视频制式不匹配, 6-视频信号异常*/
}NET_DVR_EXCEPTION, *LPNET_DVR_EXCEPTION;

//通道状态(9000扩展)
typedef struct 
{
	BYTE byRecordStatic; //通道是否在录像,0-不录像,1-录像
	BYTE bySignalStatic; //连接的信号状态,0-正常,1-信号丢失
	BYTE byHardwareStatic;//通道硬件状态,0-正常,1-异常,例如DSP死掉
	BYTE byRes1;		//保留
	DWORD dwBitRate;//实际码率
	DWORD dwLinkNum;//客户端连接的个数
	NET_DVR_IPADDR struClientIP[MAX_LINK];//客户端的IP地址
    DWORD dwIPLinkNum;//如果该通道为IP接入，那么表示IP接入当前的连接数
	BYTE byRes[12];
}NET_DVR_CHANNELSTATE_V30, *LPNET_DVR_CHANNELSTATE_V30;

//通道状态
typedef struct 
{
	BYTE byRecordStatic; //通道是否在录像,0-不录像,1-录像
	BYTE bySignalStatic; //连接的信号状态,0-正常,1-信号丢失
	BYTE byHardwareStatic;//通道硬件状态,0-正常,1-异常,例如DSP死掉
	char reservedData;		//保留
	DWORD dwBitRate;//实际码率
	DWORD dwLinkNum;//客户端连接的个数
	DWORD dwClientIP[MAX_LINK];//客户端的IP地址
}NET_DVR_CHANNELSTATE, *LPNET_DVR_CHANNELSTATE;

//硬盘状态
typedef struct 
{
	DWORD dwVolume;//硬盘的容量
	DWORD dwFreeSpace;//硬盘的剩余空间
	DWORD dwHardDiskStatic; //硬盘的状态,0-活动,1-休眠,2-不正常
}NET_DVR_DISKSTATE, *LPNET_DVR_DISKSTATE;

//DVR工作状态(9000扩展)
typedef struct 
{
	DWORD dwDeviceStatic; 	//设备的状态,0-正常,1-CPU占用率太高,超过85%,2-硬件错误,例如串口死掉
	NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM_V30];
	NET_DVR_CHANNELSTATE_V30 struChanStatic[MAX_CHANNUM_V30];//通道的状态
	BYTE  byAlarmInStatic[MAX_ALARMIN_V30]; //报警端口的状态,0-没有报警,1-有报警
	BYTE  byAlarmOutStatic[MAX_ALARMOUT_V30]; //报警输出端口的状态,0-没有输出,1-有报警输出
	DWORD  dwLocalDisplay;//本地显示状态,0-正常,1-不正常
    BYTE  byAudioChanStatus[MAX_AUDIO_V30];//表示语音通道的状态 0-未使用，1-使用中, 0xff无效
    BYTE  byRes[10];
}NET_DVR_WORKSTATE_V30, *LPNET_DVR_WORKSTATE_V30;

//DVR工作状态
typedef struct 
{
	DWORD dwDeviceStatic; 	//设备的状态,0-正常,1-CPU占用率太高,超过85%,2-硬件错误,例如串口死掉
	NET_DVR_DISKSTATE  struHardDiskStatic[MAX_DISKNUM];
	NET_DVR_CHANNELSTATE struChanStatic[MAX_CHANNUM];//通道的状态
	BYTE  byAlarmInStatic[MAX_ALARMIN]; //报警端口的状态,0-没有报警,1-有报警
	BYTE  byAlarmOutStatic[MAX_ALARMOUT]; //报警输出端口的状态,0-没有输出,1-有报警输出
	DWORD  dwLocalDisplay;//本地显示状态,0-正常,1-不正常
}NET_DVR_WORKSTATE, *LPNET_DVR_WORKSTATE;

/************************DVR日志 begin***************************/


/* 报警 */
//主类型
#define MAJOR_ALARM						0x1
//次类型
#define MINOR_ALARM_IN					0x1		/* 报警输入 */
#define MINOR_ALARM_OUT					0x2		/* 报警输出 */
#define MINOR_MOTDET_START				0x3		/* 移动侦测报警开始 */
#define MINOR_MOTDET_STOP				0x4		/* 移动侦测报警结束 */
#define MINOR_HIDE_ALARM_START			0x5		/* 遮挡报警开始 */
#define MINOR_HIDE_ALARM_STOP			0x6		/* 遮挡报警结束 */
#define MINOR_VCA_ALARM_START			0x7		/*智能报警开始*/
#define MINOR_VCA_ALARM_STOP			0x8		/*智能报警停止*/
#define MINOR_ITS_ALARM_START           0x09    // 交通事件报警开始
#define MINOR_ITS_ALARM_STOP            0x0A    // 交通事件报警结束
//2010-11-10 网络报警日志
#define MINOR_NETALARM_START            0x0b    /*网络报警开始*/
#define MINOR_NETALARM_STOP             0x0c    /*网络报警结束*/
//2010-12-16 报警板日志，与"MINOR_ALARM_IN"配对使用
#define MINOR_NETALARM_RESUME			0x0d	/*网络报警恢复*/
/* 异常 */
//主类型
#define MAJOR_EXCEPTION					0x2
//次类型
#define MINOR_VI_LOST					0x21	/* 视频信号丢失 */
#define MINOR_ILLEGAL_ACCESS			0x22	/* 非法访问 */
#define MINOR_HD_FULL					0x23	/* 硬盘满 */
#define MINOR_HD_ERROR					0x24	/* 硬盘错误 */
#define MINOR_DCD_LOST					0x25	/* MODEM 掉线(保留不使用) */
#define MINOR_IP_CONFLICT				0x26	/* IP地址冲突 */
#define MINOR_NET_BROKEN				0x27	/* 网络断开*/
#define MINOR_REC_ERROR                 0x28    /* 录像出错 */
#define MINOR_IPC_NO_LINK               0x29    /* IPC连接异常 */
#define MINOR_VI_EXCEPTION              0x2a    /* 视频输入异常(只针对模拟通道) */
#define MINOR_IPC_IP_CONFLICT           0x2b    /*ipc ip 地址 冲突*/
#define MINOR_SENCE_EXCEPTION           0x2c    // 场景异常

//2009-12-16 增加视频综合平台日志类型
#define MINOR_FANABNORMAL				0x31	/* 视频综合平台：风扇状态异常 */
#define MINOR_FANRESUME					0x32	/* 视频综合平台：风扇状态恢复正常 */
#define MINOR_SUBSYSTEM_ABNORMALREBOOT	0x33	/* 视频综合平台：6467异常重启 */
#define MINOR_MATRIX_STARTBUZZER		0x34	/* 视频综合平台：dm6467异常，启动蜂鸣器 */

//2010-01-22 增加视频综合平台异常日志次类型
#define MINOR_NET_ABNORMAL				0x35	/*网络状态异常*/
#define MINOR_MEM_ABNORMAL				0x36	/*内存状态异常*/
#define MINOR_FILE_ABNORMAL				0x37	/*文件状态异常*/
#define MINOR_PANEL_ABNORMAL			0x38 /*前面板连接异常*/
#define MINOR_PANEL_RESUME				0x39 /*前面板恢复正常*/	
#define MINOR_RS485_DEVICE_ABNORMAL		0x3a 	/*RS485连接状态异常*/
#define MINOR_RS485_DEVICE_REVERT		0x3b    /*RS485连接状态异常恢复*/
/* 操作 */
//主类型
#define MAJOR_OPERATION					0x3
//次类型
#define MINOR_START_DVR					0x41	/* 开机 */
#define MINOR_STOP_DVR					0x42	/* 关机 */
#define MINOR_STOP_ABNORMAL				0x43	/* 异常关机 */
#define MINOR_REBOOT_DVR                0x44    /*本地重启设备*/

#define MINOR_LOCAL_LOGIN				0x50	/* 本地登陆 */
#define MINOR_LOCAL_LOGOUT				0x51	/* 本地注销登陆 */
#define MINOR_LOCAL_CFG_PARM			0x52	/* 本地配置参数 */
#define MINOR_LOCAL_PLAYBYFILE          0x53	/* 本地按文件回放或下载 */
#define MINOR_LOCAL_PLAYBYTIME          0x54	/* 本地按时间回放或下载*/
#define MINOR_LOCAL_START_REC			0x55	/* 本地开始录像 */
#define MINOR_LOCAL_STOP_REC			0x56	/* 本地停止录像 */
#define MINOR_LOCAL_PTZCTRL				0x57	/* 本地云台控制 */
#define MINOR_LOCAL_PREVIEW				0x58	/* 本地预览 (保留不使用)*/
#define MINOR_LOCAL_MODIFY_TIME         0x59	/* 本地修改时间(保留不使用) */
#define MINOR_LOCAL_UPGRADE             0x5a	/* 本地升级 */
#define MINOR_LOCAL_RECFILE_OUTPUT      0x5b    /* 本地备份录象文件 */
#define MINOR_LOCAL_FORMAT_HDD          0x5c    /* 本地初始化硬盘 */
#define MINOR_LOCAL_CFGFILE_OUTPUT      0x5d    /* 导出本地配置文件 */
#define MINOR_LOCAL_CFGFILE_INPUT       0x5e    /* 导入本地配置文件 */
#define MINOR_LOCAL_COPYFILE            0x5f    /* 本地备份文件 */
#define MINOR_LOCAL_LOCKFILE            0x60    /* 本地锁定录像文件 */
#define MINOR_LOCAL_UNLOCKFILE          0x61    /* 本地解锁录像文件 */
#define MINOR_LOCAL_DVR_ALARM           0x62    /* 本地手动清除和触发报警*/
#define MINOR_IPC_ADD                   0x63    /* 本地添加IPC */
#define MINOR_IPC_DEL                   0x64    /* 本地删除IPC */
#define MINOR_IPC_SET                   0x65    /* 本地设置IPC */
#define MINOR_LOCAL_START_BACKUP		0x66	/* 本地开始备份 */
#define MINOR_LOCAL_STOP_BACKUP			0x67	/* 本地停止备份*/
#define MINOR_LOCAL_COPYFILE_START_TIME 0x68	/* 本地备份开始时间*/
#define MINOR_LOCAL_COPYFILE_END_TIME	0x69	/* 本地备份结束时间*/
#define MINOR_LOCAL_ADD_NAS             0x6a	/*本地添加网络硬盘 （nfs、iscsi）*/
#define MINOR_LOCAL_DEL_NAS             0x6b	/* 本地删除nas盘 （nfs、iscsi）*/
#define MINOR_LOCAL_SET_NAS             0x6c	/* 本地设置nas盘 （nfs、iscsi）*/

#define MINOR_REMOTE_LOGIN				0x70	/* 远程登录 */
#define MINOR_REMOTE_LOGOUT				0x71	/* 远程注销登陆 */
#define MINOR_REMOTE_START_REC			0x72	/* 远程开始录像 */
#define MINOR_REMOTE_STOP_REC			0x73	/* 远程停止录像 */
#define MINOR_START_TRANS_CHAN			0x74	/* 开始透明传输 */
#define MINOR_STOP_TRANS_CHAN			0x75	/* 停止透明传输 */
#define MINOR_REMOTE_GET_PARM			0x76	/* 远程获取参数 */
#define MINOR_REMOTE_CFG_PARM			0x77	/* 远程配置参数 */
#define MINOR_REMOTE_GET_STATUS         0x78	/* 远程获取状态 */
#define MINOR_REMOTE_ARM				0x79	/* 远程布防 */
#define MINOR_REMOTE_DISARM				0x7a	/* 远程撤防 */
#define MINOR_REMOTE_REBOOT				0x7b	/* 远程重启 */
#define MINOR_START_VT					0x7c	/* 开始语音对讲 */
#define MINOR_STOP_VT					0x7d	/* 停止语音对讲 */
#define MINOR_REMOTE_UPGRADE			0x7e	/* 远程升级 */
#define MINOR_REMOTE_PLAYBYFILE         0x7f	/* 远程按文件回放 */
#define MINOR_REMOTE_PLAYBYTIME         0x80	/* 远程按时间回放 */
#define MINOR_REMOTE_PTZCTRL			0x81	/* 远程云台控制 */
#define MINOR_REMOTE_FORMAT_HDD         0x82    /* 远程格式化硬盘 */
#define MINOR_REMOTE_STOP               0x83    /* 远程关机 */
#define MINOR_REMOTE_LOCKFILE			0x84	/* 远程锁定文件 */
#define MINOR_REMOTE_UNLOCKFILE         0x85	/* 远程解锁文件 */
#define MINOR_REMOTE_CFGFILE_OUTPUT     0x86    /* 远程导出配置文件 */
#define MINOR_REMOTE_CFGFILE_INTPUT     0x87    /* 远程导入配置文件 */
#define MINOR_REMOTE_RECFILE_OUTPUT     0x88    /* 远程导出录象文件 */
#define MINOR_REMOTE_DVR_ALARM          0x89    /* 远程手动清除和触发报警*/
#define MINOR_REMOTE_IPC_ADD			0x8a	/* 远程添加IPC */
#define MINOR_REMOTE_IPC_DEL			0x8b	/* 远程删除IPC */
#define MINOR_REMOTE_IPC_SET			0x8c	/* 远程设置IPC */
#define MINOR_REBOOT_VCA_LIB            0x8d    /*重启智能库*/
#define MINOR_REMOTE_ADD_NAS            0x8e   /* 远程添加nas盘 （nfs、iscsi）*/
#define MINOR_REMOTE_DEL_NAS            0x8f   /* 远程删除nas盘 （nfs、iscsi）*/
#define MINOR_REMOTE_SET_NAS            0x90   /* 远程设置nas盘 （nfs、iscsi）*/

//2010-05-26 增加审讯DVR日志类型
#define MINOR_LOCAL_START_REC_CDRW      0x91   /* 本地开始刻录 */
#define MINOR_LOCAL_STOP_REC_CDRW       0x92   /* 本地停止刻录 */
#define MINOR_REMOTE_START_REC_CDRW     0x93   /* 远程开始刻录 */
#define MINOR_REMOTE_STOP_REC_CDRW      0x94   /* 远程停止刻录 */

//2009-12-16 增加视频综合平台日志类型
#define MINOR_SUBSYSTEMREBOOT           0xa0	/*视频综合平台：dm6467 正常重启*/
#define MINOR_MATRIX_STARTTRANSFERVIDEO 0xa1	/*视频综合平台：矩阵切换开始传输图像*/
#define MINOR_MATRIX_STOPTRANSFERVIDEO	0xa2	/*视频综合平台：矩阵切换停止传输图像*/
#define MINOR_REMOTE_SET_ALLSUBSYSTEM   0xa3	/*视频综合平台：设置所有6467子系统信息*/
#define MINOR_REMOTE_GET_ALLSUBSYSTEM   0xa4	/*视频综合平台：获取所有6467子系统信息*/
#define MINOR_REMOTE_SET_PLANARRAY      0xa5	/*视频综合平台：设置计划轮巡组*/
#define MINOR_REMOTE_GET_PLANARRAY      0xa6	/*视频综合平台：获取计划轮巡组*/
#define MINOR_MATRIX_STARTTRANSFERAUDIO 0xa7	/*视频综合平台：矩阵切换开始传输音频*/
#define MINOR_MATRIX_STOPRANSFERAUDIO   0xa8	/*视频综合平台：矩阵切换停止传输音频*/
#define MINOR_LOGON_CODESPITTER         0xa9	/*视频综合平台：登陆码分器*/
#define MINOR_LOGOFF_CODESPITTER        0xaa	/*视频综合平台：退出码分器*/

//2010-01-22 增加视频综合平台中解码器操作日志
#define MINOR_START_DYNAMIC_DECODE 		0xb0	/*开始动态解码*/
#define MINOR_STOP_DYNAMIC_DECODE		0xb1	/*停止动态解码*/
#define MINOR_GET_CYC_CFG				0xb2	/*获取解码器通道轮巡配置*/
#define MINOR_SET_CYC_CFG				0xb3	/*设置解码通道轮巡配置*/
#define MINOR_START_CYC_DECODE			0xb4	/*开始轮巡解码*/
#define MINOR_STOP_CYC_DECODE			0xb5	/*停止轮巡解码*/
#define MINOR_GET_DECCHAN_STATUS		0xb6	/*获取解码通道状态*/
#define MINOR_GET_DECCHAN_INFO			0xb7	/*获取解码通道当前信息*/
#define MINOR_START_PASSIVE_DEC			0xb8	/*开始被动解码*/
#define MINOR_STOP_PASSIVE_DEC			0xb9	/*停止被动解码*/
#define MINOR_CTRL_PASSIVE_DEC			0xba	/*控制被动解码*/
#define MINOR_RECON_PASSIVE_DEC			0xbb	/*被动解码重连*/
#define MINOR_GET_DEC_CHAN_SW			0xbc	/*获取解码通道总开关*/
#define MINOR_SET_DEC_CHAN_SW			0xbd	/*设置解码通道总开关*/
#define MINOR_CTRL_DEC_CHAN_SCALE		0xbe	/*解码通道缩放控制*/
#define MINOR_SET_REMOTE_REPLAY			0xbf	/*设置远程回放*/
#define MINOR_GET_REMOTE_REPLAY			0xc0	/*获取远程回放状态*/
#define MINOR_CTRL_REMOTE_REPLAY		0xc1	/*远程回放控制*/
#define MINOR_SET_DISP_CFG				0xc2	/*设置显示通道*/
#define MINOR_GET_DISP_CFG				0xc3	/*获取显示通道设置*/
#define MINOR_SET_PLANTABLE				0xc4	/*设置计划轮巡表*/
#define MINOR_GET_PLANTABLE				0xc5	/*获取计划轮巡表*/
#define MINOR_START_PPPPOE				0xc6	/*开始PPPoE连接*/
#define MINOR_STOP_PPPPOE				0xc7	/*结束PPPoE连接*/
#define MINOR_UPLOAD_LOGO				0xc8	/*上传LOGO*/
//2010-12-16 报警板日志
#define MINOR_REMOTE_BYPASS             0xd0    /* 远程旁路*/
#define MINOR_REMOTE_UNBYPASS           0xd1    /* 远程旁路恢复*/
#define MINOR_REMOTE_SET_ALARMIN_CFG    0xd2    /* 远程设置报警输入参数*/
#define MINOR_REMOTE_GET_ALARMIN_CFG    0xd3    /* 远程获取报警输入参数*/
#define MINOR_REMOTE_SET_ALARMOUT_CFG   0xd4    /* 远程设置报警输出参数*/
#define MINOR_REMOTE_GET_ALARMOUT_CFG   0xd5    /* 远程获取报警输出参数*/
#define MINOR_REMOTE_ALARMOUT_OPEN_MAN  0xd6    /* 远程手动开启报警输出*/
#define MINOR_REMOTE_ALARMOUT_CLOSE_MAN 0xd7    /* 远程手动关闭报警输出*/
#define MINOR_REMOTE_ALARM_ENABLE_CFG   0xd8    /* 远程设置报警主机的RS485串口使能状态*/
#define MINOR_DBDATA_OUTPUT				0xd9	/* 导出数据库记录 */
#define MINOR_DBDATA_INPUT				0xda	/* 导入数据库记录 */
#define MINOR_MU_SWITCH					0xdb	/* 级联切换 */
#define MINOR_MU_PTZ					0xdc	/* 级联PTZ控制 */

#define MINOR_LOCAL_CONF_REB_RAID       0x101           /*本地配置自动重建*/
#define MINOR_LOCAL_CONF_SPARE          0x102           /*本地配置热备*/
#define MINOR_LOCAL_ADD_RAID            0x103           /*本地创建阵列*/
#define MINOR_LOCAL_DEL_RAID            0x104           /*本地删除阵列*/
#define MINOR_LOCAL_MIG_RAID            0x105           /*本地迁移阵列*/
#define MINOR_LOCAL_REB_RAID            0x106           /* 本地手动重建阵列*/
#define MINOR_LOCAL_QUICK_CONF_RAID     0x107           /*本地一键配置*/
#define MINOR_LOCAL_ADD_VD              0x108           /*本地创建虚拟磁盘*/
#define MINOR_LOCAL_DEL_VD              0x109           /*本地删除虚拟磁盘*/
#define MINOR_LOCAL_RP_VD               0x10a           /*本地修复虚拟磁盘*/
#define MINOR_LOCAL_FORMAT_EXPANDVD     0X10b           /*本地扩展虚拟磁盘扩容*/
#define MINOR_LOCAL_RAID_UPGRADE        0X10c           /*本地raid卡升级*/    
#define MINOR_REMOTE_CONF_REB_RAID      0x111           /*远程配置自动重建*/
#define MINOR_REMOTE_CONF_SPARE         0x112            /*远程配置热备*/
#define MINOR_REMOTE_ADD_RAID           0x113           /*远程创建阵列*/
#define MINOR_REMOTE_DEL_RAID           0x114           /*远程删除阵列*/
#define MINOR_REMOTE_MIG_RAID           0x115           /*远程迁移阵列*/
#define MINOR_REMOTE_REB_RAID           0x116           /* 远程手动重建阵列*/
#define MINOR_REMOTE_QUICK_CONF_RAID    0x117           /*远程一键配置*/
#define MINOR_REMOTE_ADD_VD             0x118           /*远程创建虚拟磁盘*/
#define MINOR_REMOTE_DEL_VD             0x119           /*远程删除虚拟磁盘*/
#define MINOR_REMOTE_RP_VD              0x11a           /*远程修复虚拟磁盘*/
#define MINOR_REMOTE_FORMAT_EXPANDVD    0X11b           /*远程虚拟磁盘扩容*/
#define MINOR_REMOTE_RAID_UPGRADE       0X11c           /*远程raid卡升级*/    

/*日志附加信息*/
//主类型
#define MAJOR_INFORMATION               0x4     /*附加信息*/
//次类型
#define MINOR_HDD_INFO                  0xa1 /*硬盘信息*/
#define MINOR_SMART_INFO                0xa2 /*SMART信息*/
#define MINOR_REC_START                 0xa3 /*开始录像*/
#define MINOR_REC_STOP                  0xa4 /*停止录像*/
#define MINOR_REC_OVERDUE				0xa5 /*过期录像删除*/
#define MINOR_LINK_START				0xa6 //连接前端设备
#define MINOR_LINK_STOP					0xa7 //断开前端设备　
#define MINOR_NET_DISK_INFO				0xa8 //网络硬盘信息
#define MINOR_RAID_INFO                 0xa9 //raid相关信息

typedef enum tagALARMHOST_MAJOR_TYPE
{
    MAJOR_ALARMHOST_ALARM = 1,
    MAJOR_ALARMHOST_EXCEPTION,
    MAJOR_ALARMHOST_OPERATION,
    MAJ0R_ALARMHOST_EVENT
}ALARMHOST_MAJOR_TYPE;

typedef enum tagALARMHOST_MINOR_TYPE
{
    // 报警 
    MINOR_SHORT_CIRCUIT =0x01,      // 短路报警
    MINOR_BROKEN_CIRCUIT,           // 断路报警
    MINOR_ALARM_RESET,              // 报警复位
    MINOR_ALARM_NORMAL,				// 报警恢复正常
    MINOR_PASSWORD_ERROR,			// 密码错误（连续3次输入密码错误）
    MINOR_ID_CARD_ILLEGALLY,		// 非法感应卡ID
    MINOR_KEYPAD_REMOVE,			// 键盘防拆
    MINOR_KEYPAD_REMOVE_RESTORE,	// 键盘防拆复位
    MINOR_DEV_REMOVE,				// 设备防拆
    MINOR_DEV_REMOVE_RESTORE,		// 设备防拆复位
    MINOR_BELOW_ALARM_LIMIT1,		// 模拟量低于报警限1
    MINOR_BELOW_ALARM_LIMIT2,		// 模拟量低于报警限2
    MINOR_BELOW_ALARM_LIMIT3,		// 模拟量低于报警限3
    MINOR_BELOW_ALARM_LIMIT4,		// 模拟量低于报警限4
    MINOR_ABOVE_ALARM_LIMIT1,		// 模拟量低于报警限1
    MINOR_ABOVE_ALARM_LIMIT2,		// 模拟量低于报警限2
    MINOR_ABOVE_ALARM_LIMIT3,		// 模拟量低于报警限3
    MINOR_ABOVE_ALARM_LIMIT4,		// 模拟量低于报警限4

    // 异常
    MINOR_POWER_ON      = 0x01,	// 上电
    MINOR_POWER_OFF,				// 掉电
    MINOR_WDT_RESET,				// WDT 复位
    MINOR_LOW_BATTERY_VOLTAGE,		// 蓄电池电压低
    MINOR_AC_LOSS,					// 交流电断电
    MINOR_AC_RESTORE,				// 交流电恢复
    MINOR_RTC_EXCEPTION,			// RTC实时时钟异常
    MINOR_NETWORK_CONNECT_FAILURE,	// 网络连接断
    MINOR_NETWORK_CONNECT_RESTORE,	// 网络连接恢复
    MINOR_TEL_LINE_CONNECT_FAILURE,	// 电话线连接断
    MINOR_TEL_LINE_CONNECT_RESTORE,	// 电话线连接恢复
    MINOR_EXPANDER_BUS_LOSS,		// 扩展总线模块掉线
    MINOR_EXPANDER_BUS_RESTORE,		// 扩展总线模块掉线恢复
    MINOR_KEYPAD_BUS_LOSS,			// 键盘总线模块掉线
    MINOR_KEYPAD_BUS_RESTORE,		// 键盘总线模块掉线恢复
    MINOR_SENSOR_FAILURE,			// 模拟量传感器故障
    MINOR_SENSOR_RESTORE,			// 模拟量传感器恢复
    MINOR_RS485_CONNECT_FAILURE,	// RS485通道连接断
    MINOR_RS485_CONNECT_RESTORE,	// RS485通道连接断恢复

    // 操作 
    MINOR_GUARD         = 0x01,	// 布防
    MINOR_UNGUARD,					// 撤防
    MINOR_BYPASS,					// 旁路
    MINOR_DURESS_ACCESS,			// 挟持
    MINOR_ALARMHOST_LOCAL_REBOOT,	// 本地重启
    MINOR_ALARMHOST_REMOTE_REBOOT,	// 远程重启
    MINOR_ALARMHOST_LOCAL_UPGRADE,	// 本地升级
    MINOR_ALARMHOST_REMOTE_UPGRADE,	// 远程升级
    MINOR_RECOVERY_DEFAULT_PARAM,	// 恢复默认参数
    MINOR_ALARM_OUTPUT,				// 控制报警输出
    MINOR_ACCESS_OPEN,				// 控制门禁开
    MINOR_ACCESS_CLOSE,				// 控制门禁关
    MINOR_SIREN_OPEN,				// 控制警号开
    MINOR_SIREN_CLOSE,				// 控制警号关
    MINOR_MOD_ZONE_CONFIG,		// 修改防区设置
    MINOR_MOD_ALARMOUT_CONIFG,	// 控制报警输出配置
    MINOR_MOD_ANALOG_CONFIG,		// 修改模拟量配置
    MINOR_RS485_CONFIG,				// 修改485通道配置
    MINOR_PHONE_CONFIG,				// 修改拨号配置
    MINOR_ADD_ADMIN,        // 增加管理员
    MINOR_MOD_ADMIN_PW,	// 修改管理员密码
    MINOR_DEL_ADMIN,		// 上除管理员
    MINOR_ADD_NETUSER,		// 后端操作员
    MINOR_MOD_NETUSER_PW,	// 修改后端操作员密码
    MINOR_DEL_NETUSER,				// 删除后端操作员
    MINOR_ADD_OPERATORUSER,			// 增加前端操作员
    MINOR_MOD_OPERATORUSER_PW,		//修改前端操作员密码
    MINOR_DEL_OPERATORUSER,			// 删除前端操作员
    MINOR_ADD_KEYPADUSER,			// 增加键盘/读卡器用户	
    MINOR_DEL_KEYPADUSER,			// 删除键盘/读卡器用户	
    MINOR_REMOTEUSER_LOGIN,		// 远程用户登陆
    MINOR_REMOTEUSER_LOGOUT,		// 远程用户注销
    MINOR_REMOTE_GUARD,				// 远程布防
    MINOR_REMOTE_UNGUARD,			// 远程撤防
    MINOR_MOD_HOST_CONFIG,          // 修改主机配置
    MINOR_RESTORE_BYPASS,			// 旁路恢复

    // 事件 
    MINOR_SCHOOLTIME_IRGI_B = 0x01,		// B码校时
    MINOR_SCHOOLTIME_SDK,				// SDK校时
    MINOR_SCHOOLTIME_SELFTEST			// 定时自检校时
}ALARMHOST_MINOR_TYPE;

//当日志的主类型为MAJOR_OPERATION=03，次类型为MINOR_LOCAL_CFG_PARM=0x52或者MINOR_REMOTE_GET_PARM=0x76或者MINOR_REMOTE_CFG_PARM=0x77时，dwParaType:参数类型有效，其含义如下：
#define PARA_VIDEOOUT	0x1
#define PARA_IMAGE		0x2
#define PARA_ENCODE		0x4
#define PARA_NETWORK	0x8
#define PARA_ALARM		0x10
#define PARA_EXCEPTION	0x20
#define PARA_DECODER	0x40    /*解码器*/
#define PARA_RS232		0x80
#define PARA_PREVIEW	0x100
#define PARA_SECURITY	0x200
#define PARA_DATETIME	0x400
#define PARA_FRAMETYPE	0x800    /*帧格式*/
#define PARA_VCA_RULE   0x1001  //行为规则 
#define PARA_VCA_CTRL   0x1002  //配置智能控制信息
#define PARA_VCA_PLATE  0x1003 //  车牌识别

#define PARA_CODESPLITTER 0x2000 /*码分器参数*/
//2010-01-22 增加视频综合平台日志信息次类型
#define PARA_RS485		  0x2001			/* RS485配置信息*/
#define PARA_DEVICE		  0x2002			/* 设备配置信息*/
#define PARA_HARDDISK	  0x2003			/* 硬盘配置信息 */
#define PARA_AUTOBOOT	  0x2004			/* 自动重启配置信息*/
#define PARA_HOLIDAY	  0x2005			/* 节假日配置信息*/			
#define PARA_IPC		  0x2006			/* IP通道配置 */	

//日志信息(9000扩展)
typedef struct 
{
	NET_DVR_TIME strLogTime;
	DWORD	dwMajorType;	//主类型 1-报警; 2-异常; 3-操作; 0xff-全部
	DWORD	dwMinorType;//次类型 0-全部;
	BYTE	sPanelUser[MAX_NAMELEN]; //操作面板的用户名
	BYTE	sNetUser[MAX_NAMELEN];//网络操作的用户名
	NET_DVR_IPADDR	struRemoteHostAddr;//远程主机地址
	DWORD	dwParaType;//参数类型,9000设备MINOR_START_VT/MINOR_STOP_VT时，表示语音对讲的端子号
	DWORD	dwChannel;//通道号
	DWORD	dwDiskNumber;//硬盘号
	DWORD	dwAlarmInPort;//报警输入端口
	DWORD	dwAlarmOutPort;//报警输出端口
    DWORD   dwInfoLen;
    char    sInfo[LOG_INFO_LEN];
}NET_DVR_LOG_V30, *LPNET_DVR_LOG_V30;

//日志信息
typedef struct 
{
	NET_DVR_TIME strLogTime;
	DWORD	dwMajorType;	//主类型 1-报警; 2-异常; 3-操作; 0xff-全部
	DWORD	dwMinorType;//次类型 0-全部;
	BYTE	sPanelUser[MAX_NAMELEN]; //操作面板的用户名
	BYTE	sNetUser[MAX_NAMELEN];//网络操作的用户名
	char	sRemoteHostAddr[16];//远程主机地址
	DWORD	dwParaType;//参数类型
	DWORD	dwChannel;//通道号
	DWORD	dwDiskNumber;//硬盘号
	DWORD	dwAlarmInPort;//报警输入端口
	DWORD	dwAlarmOutPort;//报警输出端口
}NET_DVR_LOG, *LPNET_DVR_LOG;

/************************DVR日志 end***************************/

/************************动环报警管理主机日志查找 begin************************************************/
typedef struct tagNET_DVR_ALARMHOST_SEARCH_LOG_PARAM
{
    WORD            wMajorType;		// 主类型
    WORD            wMinorType;		// 次类型 
    NET_DVR_TIME    struStartTime;	// 开始时间 
    NET_DVR_TIME    struEndTime;	// 结束时间
    BYTE            byRes[8];		// 保留字节
}NET_DVR_ALARMHOST_SEARCH_LOG_PARAM, LPNET_DVR_ALARMHOST_SEARCH_LOG_PARAM;

typedef struct tagNET_DVR_ALARMHOST_LOG_RET
{
    NET_DVR_TIME	struLogTime;                //  日志时间
    BYTE		    sUserName[NAME_LEN];     // 操作用户
    NET_DVR_IPADDR	struIPAddr;                 // 操作IP地址
    WORD		    wMajorType;                 // 主类型 
    WORD		    wMinorType;                 // 次类型
    WORD	    	wParam;	                    // 操作参数
    BYTE		    byRes[10];
    DWORD		    dwInfoLen;	                // 描述信息长度
    char			sInfo[LOG_INFO_LEN];       // 描述信息
}NET_DVR_ALARMHOST_LOG_RET, *LPNET_DVR_ALARMHOST_LOG_RET;

/*************************动环报警管理主机日志查找 end***********************************************/

//报警输出状态(9000扩展)
typedef struct 
{
	BYTE Output[MAX_ALARMOUT_V30];
}NET_DVR_ALARMOUTSTATUS_V30, *LPNET_DVR_ALARMOUTSTATUS_V30;

//报警输出状态
typedef struct 
{
	BYTE Output[MAX_ALARMOUT];
}NET_DVR_ALARMOUTSTATUS, *LPNET_DVR_ALARMOUTSTATUS;

//交易信息
typedef struct 
{
	USHORT m_Year;
	USHORT m_Month;
	USHORT m_Day;
	USHORT m_Hour;
	USHORT m_Minute;
	USHORT m_Second;
	BYTE DeviceName[24];	//设备名称
	DWORD dwChannelNumer;	//通道号
	BYTE CardNumber[32];	//卡号
	char cTradeType[12];	//交易类型
	DWORD dwCash;			//交易金额
}NET_DVR_TRADEINFO, *LPNET_DVR_TRADEINFO;


//ATM专用
/****************************ATM(begin)***************************/
#define NCR		0
#define DIEBOLD	1
#define WINCOR_NIXDORF	2
#define SIEMENS	3
#define OLIVETTI	4
#define FUJITSU	5
#define HITACHI	6
#define SMI		7
#define IBM		8
#define BULL	9
#define YiHua	10
#define LiDe	11
#define GDYT	12
#define Mini_Banl	13
#define GuangLi	14
#define DongXin	15
#define ChenTong	16
#define NanTian	17
#define XiaoXing	18
#define GZYY	19
#define QHTLT	20
#define DRS918	21
#define KALATEL	22
#define NCR_2	23	
#define NXS		24


/*帧格式*/
typedef struct 
{
	BYTE code[12];		/* 代码 */
}NET_DVR_FRAMETYPECODE;


//ATM参数
typedef struct 
{
	DWORD dwSize;
	char sATMIP[16];						/* ATM IP地址 */
	DWORD dwATMType;						/* ATM类型 */
	DWORD dwInputMode;						/* 输入方式	0-网络侦听 1-网络接收 2-串口直接输入 3-串口ATM命令输入*/
	DWORD dwFrameSignBeginPos;              /* 报文标志位的起始位置*/
	DWORD dwFrameSignLength;				/* 报文标志位的长度 */
	BYTE  byFrameSignContent[12];			/* 报文标志位的内容 */
	DWORD dwCardLengthInfoBeginPos;			/* 卡号长度信息的起始位置 */
	DWORD dwCardLengthInfoLength;			/* 卡号长度信息的长度 */
	DWORD dwCardNumberInfoBeginPos;			/* 卡号信息的起始位置 */
	DWORD dwCardNumberInfoLength;			/* 卡号信息的长度 */
	DWORD dwBusinessTypeBeginPos;           /* 交易类型的起始位置 */
	DWORD dwBusinessTypeLength;				/* 交易类型的长度 */
	NET_DVR_FRAMETYPECODE frameTypeCode[10];/* 类型 */
}NET_DVR_FRAMEFORMAT, *LPNET_DVR_FRAMEFORMAT;
//SDK_V31 ATM

/*过滤设置*/
typedef struct	tagNET_DVR_FILTER
{	
	BYTE			        byEnable;			//0,不启用;1,启用
	BYTE					byMode;				//0,ASCII;1,HEX	
    BYTE                    byFrameBeginPos;    // 需要过滤目标字符串起始位置     
	BYTE					byRes[1];           // 保留字节
	BYTE 					byFilterText[16];	//过滤字符串
	BYTE					byRes2[12];         // 保留字节
}NET_DVR_FILTER, *LPNET_DVR_FILTER;

//数据包分析 数据包标识
typedef struct	tagNET_DVR_IDENTIFICAT
{	
	BYTE					byStartMode;		//起始字符模式:0,ASCII;1,HEX
	BYTE					byEndMode;			//结束字符模式：0,ASCII;1,HEX
	BYTE					byRes[2];           //保留字节
	NET_DVR_FRAMETYPECODE	struStartCode;		//数据包起始标识字符
	NET_DVR_FRAMETYPECODE	struEndCode;		//数据包结束标识字符
	BYTE					byRes1[12];         //保留字节
}NET_DVR_IDENTIFICAT, *LPNET_DVR_IDENTIFICAT;

typedef struct	tagNET_DVR_PACKAGE_LOCATION/*报文信息位置*/
{	
	BYTE 					byOffsetMode;			/*报文位置信息模式 0,token(字符标志模式);1,fix（固定模式）*/
    BYTE                    byRes1[3];				// 保留字节
	DWORD  				    dwOffsetPos;			/*mode为1的时候使用,固定偏移大小*/
	NET_DVR_FRAMETYPECODE	struTokenCode;			/*标志位*/
	BYTE					byMultiplierValue;		/*标志位多少次出现*/
	BYTE					byEternOffset;			/*附加字符偏移量*/
	BYTE					byCodeMode;			    /*0,ASCII;1,HEX*/
	BYTE 					byRes2[9];			    //保留字节
}NET_DVR_PACKAGE_LOCATION, *LPNET_DVR_PACKAGE_LOCATION;


typedef struct	tagNET_DVR_PACKAGE_LENGTH//报文信息长度
{	
	BYTE					byLengthMode;			//长度类型，0,可变长度;1,固定长度;2,自助长度(从卡号中获取)
    BYTE                    byRes1[3];              // 保留字节
	DWORD  			    	dwFixLength;			    //mode为1的时候使用,固定长度大小
	DWORD					dwMaxLength;            //报文信息最大长度  byLengthMode 为0 时使用
	DWORD					dwMinLength;            //报文信息最小长度  byLengthMode为1时使用
	BYTE					byEndMode;			    //可变长度 终结符模式 0,ASCII;1,HEX	
    BYTE                    byRes2[3];              //保留字节
	NET_DVR_FRAMETYPECODE	struEndCode;		//可变长度终结符
	DWORD					dwLengthPos;			//lengthMode为2的时候使用，卡号长度在报文中的位置
	DWORD					dwLengthLen;			//lengthMode为2的时候使用，卡号长度的长度
	BYTE					byRes3[8];              // 保留字节
}NET_DVR_PACKAGE_LENGTH,* LPNET_DVR_PACKAGE_LENGTH;
 
typedef struct	tagNET_DVR_OSD_POSITION//OSD 叠加的位置
{	
	BYTE					byPositionMode;		//叠加风格，共2种；0，不显示；1，自定义
    BYTE                    byRes1[3];          // 保留字节
	DWORD 					dwPosX;				//x坐标，叠加风格为自定义时使用
	DWORD					dwPosY;				//y坐标，叠加风格为自定义时使用
	BYTE					byRes2[8];          //保留字节
}NET_DVR_OSD_POSITION, *LPNET_DVR_OSD_POSITION;

typedef struct	tagNET_DVR_DATE_FORMAT//日期显示格式
{	
	BYTE					byMonth;			    //Month,0.mm;1.mmm;2.mmmm							
	BYTE 					byDay;				    //Day,0.dd;									
	BYTE 					byYear;				    //Year,0.yy;1.yyyy	
	BYTE					byDateForm;			    //0~5，年月日的排列组合
	BYTE					byRes[20];              // 保留字节
	char					chSeprator[4];		    //分隔符
	char	    			chDisplaySeprator[4];	//显示分隔符
    BYTE	    			byDisplayForm;			//0~5，3个item的排列组合
	BYTE					res[27];                // 保留字节
}NET_DVR_DATE_FORMAT, *LPNET_DVR_DATE_FORMAT;
typedef struct	tagNET_DVRT_TIME_FORMAT//时间显示格式
{	
	BYTE					byTimeForm;				//1. HH MM SS;0. HH MM
	BYTE 					byRes1[23];             // 保留字节
    BYTE                    byHourMode;             //0,12;1,24 
    BYTE                    byRes2[3];              // 保留字节
	char					chSeprator[4]; 			//报文分隔符，暂时没用
	char					chDisplaySeprator[4];	//显示分隔符
	BYTE	    			byDisplayForm;			//0~5，3个item的排列组合
    BYTE                    byRes3[3];              // 保留字节
	BYTE					byDisplayHourMode;		//0,12;1,24 
	BYTE					byRes4[19];             // 保留字节
}NET_DVR_TIME_FORMAT, *LPNET_DVR_TIME_FORMAT;

typedef struct tagNET_DVR_OVERLAY_CHANNEL
{	
	BYTE                    byChannel[64];//叠加的通道 每个字节标识一个通道， 例如byChannel[0]值为1对应叠加通道1，0表示不叠加通道1。
	DWORD					dwDelayTime;			//叠加延时时间
	BYTE					byEnableDelayTime;		//是否启用叠加延时
	BYTE					byRes[11];          // 保留字节
}NET_DVR_OVERLAY_CHANNEL, *LPNET_DVR_OVERLAY_CHANNEL;

// ATM 报文行为信息
typedef struct tagNET_DVR_ATM_PACKAGE_ACTION
{	
	NET_DVR_PACKAGE_LOCATION	struPackageLocation;// 报文位置信息
	NET_DVR_OSD_POSITION		struOsdPosition;    // OSD 叠加位置
	NET_DVR_FRAMETYPECODE		struActionCode;		//交易类型行为码
	NET_DVR_FRAMETYPECODE		struPreCode;		//叠加字符前的字符
	BYTE					byActionCodeMode;		//交易类型行为码模式0,ASCII;1,HEX
	BYTE					byRes[7];               // 保留字节
}NET_DVR_ATM_PACKAGE_ACTION, *LPNET_DVR_ATM_PACKAGE_ACTION;

// ATM 报文DATA信息
typedef struct tagNET_DVR_ATM_PACKAGE_DATE
{	
	NET_DVR_PACKAGE_LOCATION	struPackageLocation;// 日期在报文中的位置信息
	NET_DVR_DATE_FORMAT		    struDateForm;		//日期显示格式
	NET_DVR_OSD_POSITION		struOsdPosition;	// OSD叠加位置信息
	BYTE				    	res[8]; 			// 保留字节
}NET_DVR_ATM_PACKAGE_DATE, *LPNET_DVR_ATM_PACKAGE_DATE;


//ATM报文时间信息
typedef struct tagNET_DVR_ATM_PACKAGE_TIME
{	
	NET_DVR_PACKAGE_LOCATION	location;		// 时间在报文中的位置信息
	NET_DVR_TIME_FORMAT		    struTimeForm;	// 时间显示格式
	NET_DVR_OSD_POSITION		struOsdPosition;// OSD 叠加位置信息
	BYTE					    byRes[8];		// 保留字节
}NET_DVR_ATM_PACKAGE_TIME, *LPNET_DVR_ATM_PACKAGE_TIME;


// ATM 其他报文信息（卡号，交易金额，交易序号）
typedef struct tagNET_DVR_ATM_PACKAGE_OTHERS
{	
	NET_DVR_PACKAGE_LOCATION	struPackageLocation; //报文位置信息
	NET_DVR_PACKAGE_LENGTH	struPackageLength;		//长度信息
	NET_DVR_OSD_POSITION		struOsdPosition;	// OSD叠加位置信息
	NET_DVR_FRAMETYPECODE		struPreCode;		//叠加字符前的字符
	BYTE					res[8];					//保留字节
}NET_DVR_ATM_PACKAGE_OTHERS, *LPNET_DVR_ATM_PACKAGE_OTHERS;


//用户自定义协议
typedef struct tagNET_DVR_ATM_USER_DEFINE_PROTOCOL
{
    NET_DVR_IDENTIFICAT        struIdentification;  //报文标志
    NET_DVR_FILTER             struFilter; //数据包过滤设置
    NET_DVR_ATM_PACKAGE_OTHERS struCardNoPara; //叠加卡号设置
    NET_DVR_ATM_PACKAGE_ACTION struTradeActionPara[MAX_ACTION_TYPE]; //叠加交易行为设置 0-9 依次对应InCard OutCard OverLay SetTime GetStatus Query WithDraw Deposit ChanPass Transfer
    NET_DVR_ATM_PACKAGE_OTHERS struAmountPara; //叠加交易金额设置
    NET_DVR_ATM_PACKAGE_OTHERS struSerialNoPara; //叠加交易序号设置
    NET_DVR_OVERLAY_CHANNEL    struOverlayChan; //叠加通道设置
    NET_DVR_ATM_PACKAGE_DATE   struRes1; //叠加日期，保留
    NET_DVR_ATM_PACKAGE_TIME   struRes2; //叠加时间，保留
    BYTE                       byRes3[124];        //保留
}NET_DVR_ATM_USER_DEFINE_PROTOCOL, *LPNET_DVR_ATM_USER_DEFINE_PROTOCOL;

typedef struct tagNET_DVR_ATM_FRAMEFORMAT_V30
{		
    DWORD                        dwSize;                 //结构大小
    BYTE					    byEnable;				/*是否启用0,不启用;1,启用*/
    BYTE					    byInputMode;			/**输入方式:0-网络监听、1网络协议、2-串口监听、3-串口协议*/
    BYTE					    byRes1[34];              //保留字节 
    NET_DVR_IPADDR		    	struAtmIp;				/*ATM 机IP 网络监听时使用 */
    WORD					    wAtmPort;				/* 网络协议方式时是使用*/
    BYTE					    byRes2[2];              // 保留字节
    DWORD					    dwAtmType;				/*ATM协议类型，从NET_DVR_ATM_PROTOCOL结构中获取，如果类型为自定义时使用用户自定义协议*/
    NET_DVR_ATM_USER_DEFINE_PROTOCOL   struAtmUserDefineProtocol; //用户自定义协议，当ATM类型为自定时需要使用该定义
    BYTE					    byRes3[8];
}NET_DVR_ATM_FRAMEFORMAT_V30, *LPNET_DVR_ATM_FRAMEFORMAT_V30;


typedef struct  tagNET_DVR_ATM_PROTO_TYPE
{
    DWORD dwAtmType; //ATM协议类型，同时作为索引序号 ATM 配置中的dwAtmType 自定义时为1025
    char chDesc[ATM_DESC_LEN]; //ATM协议简单描述
}NET_DVR_ATM_PROTO_TYPE, *LPNET_DVR_ATM_PROTO_TYPE; //协议信息数据结构

typedef struct tagNET_DVR_ATM_PROTO_LIST    //ATM 协议列表
{
    DWORD                  dwAtmProtoNum;           // 协议列表的个数
    NET_DVR_ATM_PROTO_TYPE struAtmProtoType[MAX_ATM_PROTOCOL_NUM]; //协议列表信息
}NET_DVR_ATM_PROTO_LIST, *LPNET_DVR_ATM_PROTO_LIST;

typedef struct tagNET_DVR_ATM_PROTOCOL
{
    DWORD dwSize;
    NET_DVR_ATM_PROTO_LIST struNetListenList; // 网络监听协议描述
    NET_DVR_ATM_PROTO_LIST struSerialListenList; //串口监听协议描述
    NET_DVR_ATM_PROTO_LIST struNetProtoList;     //网络协议描述
    NET_DVR_ATM_PROTO_LIST struSerialProtoList;   //串口协议描述
    NET_DVR_ATM_PROTO_TYPE struCustomProto;        //自定义协议
}NET_DVR_ATM_PROTOCOL, *LPNET_DVR_ATM_PROTOCOL;
// SDK_V31

/*****************************DS-6001D/F(begin)***************************/
//DS-6001D Decoder
typedef struct 
{
	BYTE byEncoderIP[16];		//解码设备连接的服务器IP
	BYTE byEncoderUser[16];		//解码设备连接的服务器的用户名
	BYTE byEncoderPasswd[16];	//解码设备连接的服务器的密码
	BYTE bySendMode;			//解码设备连接服务器的连接模式
	BYTE byEncoderChannel;		//解码设备连接的服务器的通道号
	WORD wEncoderPort;			//解码设备连接的服务器的端口号
	BYTE reservedData[4];		//保留
}NET_DVR_DECODERINFO, *LPNET_DVR_DECODERINFO;

typedef struct 
{
	BYTE byEncoderIP[16];		//解码设备连接的服务器IP
	BYTE byEncoderUser[16];		//解码设备连接的服务器的用户名
	BYTE byEncoderPasswd[16];	//解码设备连接的服务器的密码
	BYTE byEncoderChannel;		//解码设备连接的服务器的通道号
	BYTE bySendMode;			//解码设备连接的服务器的连接模式
	WORD wEncoderPort;			//解码设备连接的服务器的端口号
	DWORD dwConnectState;		//解码设备连接服务器的状态
	BYTE reservedData[4];		//保留
}NET_DVR_DECODERSTATE, *LPNET_DVR_DECODERSTATE;

/*解码设备控制码定义*/
#define NET_DEC_STARTDEC		1
#define NET_DEC_STOPDEC			2
#define NET_DEC_STOPCYCLE		3
#define NET_DEC_CONTINUECYCLE	4
/*连接的通道配置*/
typedef struct 
{
	char sDVRIP[16];				/* DVR IP地址 */
	WORD wDVRPort;			 		/* 端口号 */
	BYTE sUserName[NAME_LEN];		/* 用户名 */
	BYTE sPassword[PASSWD_LEN];		/* 密码 */
	BYTE byChannel;					/* 通道号 */
	BYTE byLinkMode;				/* 连接模式 */
	BYTE byLinkType;				/* 连接类型 0－主码流 1－子码流 */
}NET_DVR_DECCHANINFO, *LPNET_DVR_DECCHANINFO;

/*每个解码通道的配置*/
typedef struct 
{
	BYTE	byPoolChans;			/*每路解码通道上的循环通道数量, 最多4通道 0表示没有解码*/
	NET_DVR_DECCHANINFO struchanConInfo[MAX_DECPOOLNUM];
	BYTE	byEnablePoll;			/*是否轮巡 0-否 1-是*/
	BYTE	byPoolTime;				/*轮巡时间 0-保留 1-10秒 2-15秒 3-20秒 4-30秒 5-45秒 6-1分钟 7-2分钟 8-5分钟 */
}NET_DVR_DECINFO, *LPNET_DVR_DECINFO;

/*整个设备解码配置*/
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwDecChanNum; 		/*解码通道的数量*/
	NET_DVR_DECINFO struDecInfo[MAX_DECNUM];
}NET_DVR_DECCFG, *LPNET_DVR_DECCFG;

//2005-08-01
/* 解码设备透明通道设置 */
typedef struct 
{
	DWORD dwEnableTransPort;	/* 是否启动透明通道 0－不启用 1－启用*/
	char sDecoderIP[16];		/* DVR IP地址 */
	WORD wDecoderPort;			/* 端口号 */
	WORD wDVRTransPort;			/* 配置前端DVR是从485/232输出，1表示232串口,2表示485串口 */
	char cReserve[4];
}NET_DVR_PORTINFO, *LPNET_DVR_PORTINFO;

typedef struct 
{
	DWORD dwSize;
	NET_DVR_PORTINFO struTransPortInfo[MAX_TRANSPARENTNUM]; /* 数组0表示232 数组1表示485 */
}NET_DVR_PORTCFG, *LPNET_DVR_PORTCFG;

/* 控制网络文件回放 */
typedef struct 
{
	DWORD dwSize;
	char sDecoderIP[16];		/* DVR IP地址 */
	WORD wDecoderPort;			/* 端口号 */
	WORD wLoadMode;				/* 回放下载模式 1－按名字 2－按时间 */
	union
	{
		BYTE byFile[100];		/* 回放的文件名 */
		struct
		{
			DWORD dwChannel;
			BYTE sUserName[NAME_LEN];	/*请求视频用户名*/
			BYTE sPassword[PASSWD_LEN];	/* 密码 */
			NET_DVR_TIME struStartTime;	/* 按时间回放的开始时间 */
			NET_DVR_TIME struStopTime;	/* 按时间回放的结束时间 */
		}bytime;
	}mode_size;
}NET_DVR_PLAYREMOTEFILE, *LPNET_DVR_PLAYREMOTEFILE;

/*当前设备解码连接状态*/
typedef struct 
{
	DWORD dwWorkType;		/*工作方式：1：轮巡、2：动态连接解码、3：文件回放下载 4：按时间回放下载*/
	char sDVRIP[16];		/*连接的设备ip*/
	WORD wDVRPort;			/*连接端口号*/
	BYTE byChannel;			/* 通道号 */
	BYTE byLinkMode;		/* 连接模式 */
	DWORD	dwLinkType;		/*连接类型 0－主码流 1－子码流*/
	union
	{
		struct
		{
			BYTE sUserName[NAME_LEN];	/*请求视频用户名*/
			BYTE sPassword[PASSWD_LEN];	/* 密码 */
			char cReserve[52];
		}userInfo;
		struct
		{
			BYTE   fileName[100];
		}fileInfo;
		struct
		{
			DWORD	dwChannel;
			BYTE	sUserName[NAME_LEN];	/*请求视频用户名*/
			BYTE	sPassword[PASSWD_LEN];	/* 密码 */
			NET_DVR_TIME struStartTime;		/* 按时间回放的开始时间 */
			NET_DVR_TIME struStopTime;		/* 按时间回放的结束时间 */
		}timeInfo;
	}objectInfo;
}NET_DVR_DECCHANSTATUS, *LPNET_DVR_DECCHANSTATUS;

typedef struct 
{
	DWORD   dwSize;
	NET_DVR_DECCHANSTATUS struDecState[MAX_DECNUM];
}NET_DVR_DECSTATUS, *LPNET_DVR_DECSTATUS;
/*****************************DS-6001D/F(end)***************************/

//单字符参数(子结构)
typedef struct 
{
	WORD wShowString;				// 预览的图象上是否显示字符,0-不显示,1-显示 区域大小704*576,单个字符的大小为32*32
	WORD wStringSize;				/* 该行字符的长度，不能大于44个字符 */
	WORD wShowStringTopLeftX;		/* 字符显示位置的x坐标 */
	WORD wShowStringTopLeftY;		/* 字符名称显示位置的y坐标 */
	char sString[44];				/* 要显示的字符内容 */
}NET_DVR_SHOWSTRINGINFO, *LPNET_DVR_SHOWSTRINGINFO;

//叠加字符(9000扩展)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM_V30];				/* 要显示的字符内容 */
}NET_DVR_SHOWSTRING_V30, *LPNET_DVR_SHOWSTRING_V30;

//叠加字符扩展(8条字符)
typedef struct 
{
	DWORD dwSize;
	NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM_EX];				/* 要显示的字符内容 */
}NET_DVR_SHOWSTRING_EX, *LPNET_DVR_SHOWSTRING_EX;

//叠加字符
typedef struct 
{
	DWORD dwSize;
	NET_DVR_SHOWSTRINGINFO struStringInfo[MAX_STRINGNUM];				/* 要显示的字符内容 */
}NET_DVR_SHOWSTRING, *LPNET_DVR_SHOWSTRING;

/****************************DS9000新增结构(begin)******************************/

/*
EMAIL参数结构
*/
typedef struct
{		
	DWORD		dwSize;
	BYTE		sAccount[NAME_LEN];				/* 账号*/ 
	BYTE		sPassword[MAX_EMAIL_PWD_LEN];			/*密码 */
	struct
	{
		BYTE	sName[NAME_LEN];				/* 发件人姓名 */
		BYTE	sAddress[MAX_EMAIL_ADDR_LEN];		/* 发件人地址 */
	}struSender;
	BYTE		sSmtpServer[MAX_EMAIL_ADDR_LEN];	/* smtp服务器 */
	BYTE		sPop3Server[MAX_EMAIL_ADDR_LEN];	/* pop3服务器 */
	struct
	{
		BYTE	sName[NAME_LEN];				/* 收件人姓名 */
		BYTE	sAddress[MAX_EMAIL_ADDR_LEN];		/* 收件人地址 */
	}struReceiver[3];							/* 最多可以设置3个收件人 */
	BYTE		byAttachment;					/* 是否带附件 */
	BYTE		bySmtpServerVerify;				/* 发送服务器要求身份验证 */
    BYTE        byMailInterval;                 /* mail interval */
	BYTE        byEnableSSL;					//ssl是否启用9000_1.1
	WORD        wSmtpPort;						//gmail的465，普通的为25     
	BYTE        byRes[74];						//保留
} NET_DVR_EMAILCFG_V30, *LPNET_DVR_EMAILCFG_V30;

/*
DVR实现巡航数据结构
*/
typedef struct
{	
	DWORD 	dwSize;
	BYTE	byPresetNo[CRUISE_MAX_PRESET_NUMS];		/* 预置点号 */
	BYTE 	byCruiseSpeed[CRUISE_MAX_PRESET_NUMS];	/* 巡航速度 */
	WORD	wDwellTime[CRUISE_MAX_PRESET_NUMS];		/* 停留时间 */
	BYTE	byEnableThisCruise;						/* 是否启用 */
	BYTE	res[15];
}NET_DVR_CRUISE_PARA, *LPNET_DVR_CRUISE_PARA; 
/****************************DS9000新增结构(end)******************************/


//时间点
typedef struct 
{
	DWORD dwMonth;		//月 0-11表示1-12个月
	DWORD dwWeekNo;		//第几周 0－第1周 1－第2周 2－第3周 3－第4周 4－最后一周
	DWORD dwWeekDate;	//星期几 0－星期日 1－星期一 2－星期二 3－星期三 4－星期四 5－星期五 6－星期六
	DWORD dwHour;		//小时	开始时间0－23 结束时间1－23
	DWORD dwMin;		//分	0－59
}NET_DVR_TIMEPOINT;

//夏令时参数
typedef struct 
{
	DWORD dwSize;
	BYTE byRes1[16];			//保留
	DWORD dwEnableDST;		//是否启用夏时制 0－不启用 1－启用
	BYTE byDSTBias;	//夏令时偏移值，30min, 60min, 90min, 120min, 以分钟计，传递原始数值
	BYTE byRes2[3];
	NET_DVR_TIMEPOINT struBeginPoint;	//夏时制开始时间
	NET_DVR_TIMEPOINT struEndPoint;	//夏时制停止时间
}NET_DVR_ZONEANDDST, *LPNET_DVR_ZONEANDDST;

//图片质量
typedef struct 
{
	/*注意：当图像压缩分辨率为VGA时，支持0=CIF, 1=QCIF, 2=D1抓图，
	当分辨率为3=UXGA(1600x1200), 4=SVGA(800x600), 5=HD720p(1280x720),6=VGA,7=XVGA, 8=HD900p
	仅支持当前分辨率的抓图*/
	WORD	wPicSize;				/* 0=CIF, 1=QCIF, 2=D1 3=UXGA(1600x1200), 4=SVGA(800x600), 5=HD720p(1280x720),6=VGA*/
	WORD	wPicQuality;			/* 图片质量系数 0-最好 1-较好 2-一般 */
}NET_DVR_JPEGPARA, *LPNET_DVR_JPEGPARA;

/* aux video out parameter */
//辅助输出参数配置
typedef struct 
{
	DWORD dwSize;
	DWORD dwAlarmOutChan;                       /* 选择报警弹出大报警通道切换时间：1画面的输出通道: 0:主输出/1:辅1/2:辅2/3:辅3/4:辅4 */
	DWORD dwAlarmChanSwitchTime;                /* :1秒 - 10:10秒 */
	DWORD dwAuxSwitchTime[MAX_AUXOUT];			/* 辅助输出切换时间: 0-不切换,1-5s,2-10s,3-20s,4-30s,5-60s,6-120s,7-300s */
	BYTE  byAuxOrder[MAX_AUXOUT][MAX_WINDOW];	/* 辅助输出预览顺序, 0xff表示相应的窗口不预览 */
}NET_DVR_AUXOUTCFG, *LPNET_DVR_AUXOUTCFG;


//ntp
typedef struct 
{
	BYTE sNTPServer[64];   /* Domain Name or IP addr of NTP server */
	WORD wInterval;		 /* adjust time interval(hours) */
	BYTE byEnableNTP;    /* enable NPT client 0-no，1-yes*/
	signed char cTimeDifferenceH; /* 与国际标准时间的 小时偏移-12 ... +13 */
	signed char cTimeDifferenceM;/* 与国际标准时间的 分钟偏移0, 30, 45*/
	BYTE res1;
    WORD wNtpPort;         /* ntp server port 9000新增 设备默认为123*/
    BYTE res2[8];
}NET_DVR_NTPPARA, *LPNET_DVR_NTPPARA;

//ddns
typedef struct 
{
	BYTE sUsername[NAME_LEN];  /* DDNS账号用户名/密码 */
	BYTE sPassword[PASSWD_LEN];
	BYTE sDomainName[64];       /* 域名 */
	BYTE byEnableDDNS;			/*是否应用 0-否，1-是*/
	BYTE res[15];
}NET_DVR_DDNSPARA, *LPNET_DVR_DDNSPARA;


typedef struct
{
	BYTE byHostIndex;					/* 0-私有DDNS 1－Dyndns 2－PeanutHull(花生壳)*/
	BYTE byEnableDDNS;					/*是否应用DDNS 0-否，1-是*/
	WORD wDDNSPort;						/* DDNS端口号 */
	BYTE sUsername[NAME_LEN];			/* DDNS用户名*/
	BYTE sPassword[PASSWD_LEN];			/* DDNS密码 */
	BYTE sDomainName[MAX_DOMAIN_NAME];	/* 设备配备的域名地址 */
	BYTE sServerName[MAX_DOMAIN_NAME];	/* DDNS 对应的服务器地址，可以是IP地址或域名 */
	BYTE byRes[16];
}NET_DVR_DDNSPARA_EX, *LPNET_DVR_DDNSPARA_EX;

//9000扩展
typedef struct
{
    BYTE byEnableDDNS;
    BYTE byHostIndex;/* 0-私有DDNS 1－Dyndns 2－PeanutHull(花生壳) 3- NO-IP*/
    BYTE byRes1[2];
    struct
    {    
        BYTE sUsername[NAME_LEN];			/* DDNS账号用户名*/
        BYTE sPassword[PASSWD_LEN];			/* 密码 */
        BYTE sDomainName[MAX_DOMAIN_NAME];	/* 设备配备的域名地址 */
        BYTE sServerName[MAX_DOMAIN_NAME];	/* DDNS协议对应的服务器地址，可以是IP地址或域名 */
        WORD wDDNSPort;						/* 端口号 */
        BYTE byRes[10];
    } struDDNS[MAX_DDNS_NUMS];
    BYTE byRes2[16];
}NET_DVR_DDNSPARA_V30, *LPNET_DVR_DDNSPARA_V30;

//email
typedef struct 
{
	BYTE sUsername[64];  /* 邮件账号/密码 */
	BYTE sPassword[64];
	BYTE sSmtpServer[64];
	BYTE sPop3Server[64];
	BYTE sMailAddr[64];   /* email */
	BYTE sEventMailAddr1[64];  /* 上传报警/异常等的email */
	BYTE sEventMailAddr2[64];
	BYTE res[16];
}NET_DVR_EMAILPARA, *LPNET_DVR_EMAILPARA;

//网络参数配置
typedef struct 
{
	DWORD  dwSize;
	char  sDNSIp[16];                /* DNS服务器地址 */
	NET_DVR_NTPPARA  struNtpClientParam;      /* NTP参数 */
	NET_DVR_DDNSPARA struDDNSClientParam;     /* DDNS参数 */
	BYTE res[464];			/* 保留 */
}NET_DVR_NETAPPCFG, *LPNET_DVR_NETAPPCFG;

//nfs结构配置
typedef struct
{
    char sNfsHostIPAddr[16];
    BYTE sNfsDirectory[PATHNAME_LEN];        // PATHNAME_LEN = 128
}NET_DVR_SINGLE_NFS, *LPNET_DVR_SINGLE_NFS;

typedef struct 
{
	DWORD  dwSize;
	NET_DVR_SINGLE_NFS struNfsDiskParam[MAX_NFS_DISK];
}NET_DVR_NFSCFG, *LPNET_DVR_NFSCFG;

typedef struct tagNET_DVR_ISCSI_CFG
{   
    DWORD dwSize;                   // 结构大小
    WORD wVrmPort;                  // VRM 监听端口
    BYTE byEnable;                  // 是否启用 ISCSI存储
    BYTE byRes[69];                 // 保留字节
    NET_DVR_IPADDR struVrmAddr;          // VRM ip地址 16位
    char chNvtIndexCode[64];        //nvt index Code 
}NET_DVR_ISCSI_CFG, *LPNET_DVR_ISCSI_CFG;  

//巡航点配置(私有IP快球专用)
typedef struct
{
    BYTE	PresetNum;	//预置点
    BYTE	Dwell;		//停留时间
    BYTE	Speed;		//速度
    BYTE	Reserve;	//保留
}NET_DVR_CRUISE_POINT, *LPNET_DVR_CRUISE_POINT;

typedef struct 
{
	NET_DVR_CRUISE_POINT struCruisePoint[32];			//最大支持32个巡航点
}NET_DVR_CRUISE_RET, *LPNET_DVR_CRUISE_RET;

/************************************多路解码器(begin)***************************************/
typedef struct 
{
	DWORD	dwSize;
	char	sFirstDNSIP[16];
	char	sSecondDNSIP[16];
	char	sRes[32];
}NET_DVR_NETCFG_OTHER, *LPNET_DVR_NETCFG_OTHER;

typedef struct 
{
	char 	sDVRIP[16];				/* DVR IP地址 */
	WORD 	wDVRPort;			 	/* 端口号 */
	BYTE 	byChannel;				/* 通道号 */
	BYTE	byTransProtocol;			/* 传输协议类型 0-TCP, 1-UDP */
	BYTE	byTransMode;				/* 传输码流模式 0－主码流 1－子码流*/
	BYTE	byRes[3];
	BYTE	sUserName[NAME_LEN];			/* 监控主机登陆帐号 */
	BYTE	sPassword[PASSWD_LEN];			/* 监控主机密码 */
}NET_DVR_MATRIX_DECINFO, *LPNET_DVR_MATRIX_DECINFO;

//启动/停止动态解码
typedef struct 
{
	DWORD	dwSize;				
	NET_DVR_MATRIX_DECINFO struDecChanInfo;		/* 动态解码通道信息 */
}NET_DVR_MATRIX_DYNAMIC_DEC, *LPNET_DVR_MATRIX_DYNAMIC_DEC;

typedef struct  
{
    DWORD 	dwSize;
    DWORD   dwIsLinked;         /* 解码通道状态 0－休眠 1－正在连接 2－已连接 3-正在解码 */
    DWORD   dwStreamCpRate;     /* Stream copy rate, X kbits/second */
    char    cRes[64];		/* 保留 */
}NET_DVR_MATRIX_DEC_CHAN_STATUS, *LPNET_DVR_MATRIX_DEC_CHAN_STATUS;

typedef struct 
{
	DWORD	dwSize;
	NET_DVR_MATRIX_DECINFO struDecChanInfo;		/* 解码通道信息 */
	DWORD	dwDecState;	/* 0-动态解码 1－循环解码 2－按时间回放 3－按文件回放 */
	NET_DVR_TIME StartTime;		/* 按时间回放开始时间 */
	NET_DVR_TIME StopTime;		/* 按时间回放停止时间 */
	char    sFileName[128];		/* 按文件回放文件名 */
}NET_DVR_MATRIX_DEC_CHAN_INFO, *LPNET_DVR_MATRIX_DEC_CHAN_INFO;

//连接的通道配置 2007-11-05
typedef struct 
{
	DWORD dwEnable;					/* 是否启用 0－否 1－启用*/
	NET_DVR_MATRIX_DECINFO struDecChanInfo;		/* 轮巡解码通道信息 */
}NET_DVR_MATRIX_DECCHANINFO, *LPNET_DVR_MATRIX_DECCHANINFO;

//2007-11-05 新增每个解码通道的配置
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwPoolTime;			/*轮巡时间 */
	NET_DVR_MATRIX_DECCHANINFO struchanConInfo[MAX_CYCLE_CHAN];
}NET_DVR_MATRIX_LOOP_DECINFO, *LPNET_DVR_MATRIX_LOOP_DECINFO;

//2007-12-22
typedef struct 
{
	BYTE	baudrate; 	/* 波特率 */
	BYTE	databits;		/* 数据位 */
	BYTE	stopbits;		/* 停止位 */
	BYTE	parity;		/* 奇偶校验位 */
	BYTE	flowcontrol;	/* 流控 */
	BYTE	res[3];
}TTY_CONFIG, *LPTTY_CONFIG;

typedef struct  
{					
	BYTE byTranChanEnable;	/* 当前透明通道是否打开 0：关闭 1：打开 */	
	/*
	 *	多路解码器本地有1个485串口，1个232串口都可以作为透明通道,设备号分配如下：
	 *	0 RS485
	 *	1 RS232 Console
	 */
	BYTE	byLocalSerialDevice;			/* Local serial device */
	/*
	 *	远程串口输出还是两个,一个RS232，一个RS485
	 *	1表示232串口
	 *	2表示485串口
	 */
	BYTE	byRemoteSerialDevice;			/* Remote output serial device */
	BYTE	res1;							/* 保留 */
	char	sRemoteDevIP[16];				/* Remote Device IP */
	WORD	wRemoteDevPort;				/* Remote Net Communication Port */
	BYTE	res2[2];						/* 保留 */
	TTY_CONFIG RemoteSerialDevCfg;
}NET_DVR_MATRIX_TRAN_CHAN_INFO, *LPNET_DVR_MATRIX_TRAN_CHAN_INFO;

typedef struct  
{
	DWORD dwSize;
	BYTE 	by232IsDualChan; /* 设置哪路232透明通道是全双工的 取值1到MAX_SERIAL_NUM */
	BYTE	by485IsDualChan; /* 设置哪路485透明通道是全双工的 取值1到MAX_SERIAL_NUM */
	BYTE	res[2];	/* 保留 */
	NET_DVR_MATRIX_TRAN_CHAN_INFO struTranInfo[MAX_SERIAL_NUM];/*同时支持建立MAX_SERIAL_NUM个透明通道*/
}NET_DVR_MATRIX_TRAN_CHAN_CONFIG, *LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG;

//2007-12-24 Merry Christmas Eve...
typedef struct 
{
	DWORD	dwSize;
	char	sDVRIP[16];		/* DVR IP地址 */	
	WORD	wDVRPort;			/* 端口号 */	
	BYTE	byChannel;			/* 通道号 */
	BYTE 	byReserve;
	BYTE	sUserName[NAME_LEN];		/* 用户名 */
	BYTE	sPassword[PASSWD_LEN];		/* 密码 */
	DWORD	dwPlayMode;   	/* 0－按文件 1－按时间*/        	
	NET_DVR_TIME StartTime;
	NET_DVR_TIME StopTime;
	char    sFileName[128];
}NET_DVR_MATRIX_DEC_REMOTE_PLAY, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY;

/* 文件播放命令 */
#define NET_DVR_PLAYSTART		1//开始播放
#define NET_DVR_PLAYSTOP		2//停止播放
#define NET_DVR_PLAYPAUSE		3//暂停播放
#define NET_DVR_PLAYRESTART		4//恢复播放
#define NET_DVR_PLAYFAST		5//快放
#define NET_DVR_PLAYSLOW		6//慢放
#define NET_DVR_PLAYNORMAL		7//正常速度
#define NET_DVR_PLAYSTARTAUDIO	9//打开声音
#define NET_DVR_PLAYSTOPAUDIO	10//关闭声音
#define NET_DVR_PLAYSETPOS		12//改变文件回放的进度

typedef struct 
{
	DWORD	dwSize;
	DWORD	dwPlayCmd;		/* 播放命令 见文件播放命令*/
	DWORD	dwCmdParam;		/* 播放命令参数 */
}NET_DVR_MATRIX_DEC_REMOTE_PLAY_CONTROL, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_CONTROL;

typedef struct  
{
	DWORD dwSize;
	DWORD dwCurMediaFileLen;		/* 当前播放的媒体文件长度 */       
	DWORD dwCurMediaFilePosition;	/* 当前播放文件的播放位置 */        
	DWORD dwCurMediaFileDuration;	/* 当前播放文件的总时间 */        
	DWORD dwCurPlayTime;			/* 当前已经播放的时间 */        
	DWORD dwCurMediaFIleFrames;		/* 当前播放文件的总帧数 */        
	DWORD dwCurDataType;			/* 当前传输的数据类型，19-文件头，20-流数据， 21-播放结束标志 */        
	BYTE res[72];	
}NET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS, *LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS;

//2009-4-11 added by likui 多路解码器new
typedef struct tagNET_MATRIX_PASSIVEMODE
{
    WORD	wTransProtol;		//传输协议，0-TCP, 1-UDP, 2-MCAST
    WORD	wPassivePort;		//UDP端口, TCP时默认
    NET_DVR_IPADDR  struMcastIP;	//TCP,UDP时无效, MCAST时为多播地址
    BYTE	byStreamType;/* 数据播放模式:REAL_TIME_STREAM(1)实时流,RECORD_STREAM(2)文件流 */
    BYTE	byRes[7];
}NET_DVR_MATRIX_PASSIVEMODE, *LPNET_DVR_MATRIX_PASSIVEMODE;

typedef struct tagMATRIX_TRAN_CHAN_INFO 
{					
	BYTE byTranChanEnable;	/* 当前透明通道是否打开 0：关闭 1：打开 */	
/*
	 *	多路解码器本地有1个485串口，1个232串口都可以作为透明通道,设备号分配如下：
	 *	0 RS485
	 *	1 RS232 Console
	 */
	BYTE	byLocalSerialDevice;			/* Local serial device */
/*
	 *	远程串口输出还是两个,一个RS232，一个RS485
	 *	1表示232串口
	 *	2表示485串口
	 */
	BYTE	byRemoteSerialDevice;			/* Remote output serial device */
	BYTE	byRes1;							/* 保留 */		
    NET_DVR_IPADDR  struRemoteDevIP;/* Remote Device IP */
	WORD    wRemoteDevPort;				/* Remote Net Communication Port */
    BYTE    byIsEstablished;			/* 透明通道建立成功标志，0-没有成功，1-建立成功 */
    BYTE	byRes2;						/* 保留 */
	TTY_CONFIG RemoteSerialDevCfg;
	BYTE  	byUsername[NAME_LEN]; 		/* 32BYTES */
	BYTE   	byPassword[PASSWD_LEN]; 		/* 16BYTES */
	BYTE 	byRes3[16];
} NET_DVR_MATRIX_TRAN_CHAN_INFO_V30,*LPNET_DVR_MATRIX_TRAN_CHAN_INFO_V30;

typedef struct tagMATRIX_TRAN_CHAN_CONFIG 
{
	DWORD   dwSize;
	BYTE 	by232IsDualChan; /* 设置哪路232透明通道是全双工的 取值1到MAX_SERIAL_NUM */
	BYTE	by485IsDualChan; /* 设置哪路485透明通道是全双工的 取值1到MAX_SERIAL_NUM */
	BYTE	vyRes[2];	/* 保留 */
	NET_DVR_MATRIX_TRAN_CHAN_INFO_V30 struTranInfo[MAX_SERIAL_NUM];/*同时支持建立MAX_SERIAL_NUM个透明通道*/
}NET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30,*LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30;

typedef struct  
{
    DWORD								dwEnable;	/* 是否启用 0－否 1－启用*/
    NET_DVR_STREAM_MEDIA_SERVER_CFG	streamMediaServerCfg;	
    NET_DVR_DEV_CHAN_INFO 		struDevChanInfo;		/* 轮巡解码通道信息 */
}NET_DVR_MATRIX_CHAN_INFO_V30,*LPNET_DVR_CYC_SUR_CHAN_ELE_V30;

typedef struct  tagMATRIX_LOOP_DECINFO_V30
{
    DWORD							dwSize;
    DWORD							dwPoolTime;		/*轮巡间隔*/
    NET_DVR_MATRIX_CHAN_INFO_V30	struchanConInfo[MAX_CYCLE_CHAN_V30];
    BYTE               				byRes[16];
} NET_DVR_MATRIX_LOOP_DECINFO_V30,*LPNET_DVR_MATRIX_LOOP_DECINFO_V30;


typedef struct tagDEC_MATRIX_CHAN_INFO_V30
{
    DWORD	dwSize;
    NET_DVR_STREAM_MEDIA_SERVER_CFG streamMediaServerCfg;	/*流媒体服务器配置*/
    NET_DVR_DEV_CHAN_INFO 			  struDevChanInfo;		/* 解码通道信息 */
    DWORD	dwDecState;		/* 0-动态解码 1－循环解码 2－按时间回放 3－按文件回放 */
    NET_DVR_TIME StartTime;		/* 按时间回放开始时间 */
    NET_DVR_TIME StopTime;		/* 按时间回放停止时间 */
    char    sFileName[128];		/* 按文件回放文件名 */
    DWORD   dwGetStreamMode;	/*取流模式:1-主动，2-被动*/
    NET_DVR_MATRIX_PASSIVEMODE      struPassiveMode;
    BYTE	byRes[32];
}NET_DVR_MATRIX_DEC_CHAN_INFO_V30,*LPNET_DVR_MATRIX_DEC_CHAN_INFO_V30;

#define MAX_RESOLUTIONNUM    64 //支持的最大分辨率数目
typedef struct tagNET_DVR_MATRIX_ABILITY
{
    DWORD dwSize;
    BYTE  byDecNums;
    BYTE  byStartChan;
    BYTE  byVGANums;
    BYTE  byBNCNums;
    BYTE  byVGAWindowMode[8][12];     /*VGA支持的窗口模式，VGA1可能由混合输出*/
    BYTE  byBNCWindowMode[4];       	/*BNC支持的窗口模式*/
    BYTE  byDspNums;   
    BYTE  byHDMINums;//HDMI显示通道个数（从25开始）
    BYTE  byDVINums;//DVI显示通道个数（从29开始）
	BYTE  byRes1[13];
	BYTE  bySupportResolution[MAX_RESOLUTIONNUM];//按照上面的枚举定义,一个字节代表一个分辨率是//否支持，1：支持，0：不支持
	BYTE  byHDMIWindowMode[4][8];//HDMI支持的窗口模式
	BYTE  byDVIWindowMode[4][8];//DVI支持的窗口模式
	BYTE  byRes2[24];
}NET_DVR_MATRIX_ABILITY, *LPNET_DVR_MATRIX_ABILITY;
//上传logo结构
typedef struct tagNET_DVR_DISP_LOGOCFG
{
    DWORD		dwCorordinateX;	//图片显示区域X坐标
    DWORD		dwCorordinateY;	//图片显示区域Y坐标
    BYTE        byRes1[8];
    BYTE        byFlash;  //是否闪烁1-闪烁，0-不闪烁
    BYTE        byTranslucent; //是否半透明1-半透明，0-不半透明
    BYTE		byRes2[6];				//保留
    DWORD		dwLogoSize;//LOGO大小，包括BMP的文件头
}NET_DVR_DISP_LOGOCFG,*LPNET_DVR_DISP_LOGOCFG;

/*编码类型*/
#define NET_DVR_ENCODER_UNKOWN 0 /*未知编码格式*/
#define NET_DVR_ENCODER_H264   1 /*私有 264*/
#define NET_DVR_ENCODER_S264  2 /*Standard H264*/
#define NET_DVR_ENCODER_MPEG4  3 /*MPEG4*/
#define NET_DVR_ORIGINALSTREAM    4 /*Original Stream*/
#define NET_DVR_PICTURE			  5/*Picture*/

/* 打包格式 */
#define NET_DVR_STREAM_TYPE_UNKOWN   0     /*未知打包格式*/
#define NET_DVR_STREAM_TYPE_PRIVT   1     /*私有格式*/
#define NET_DVR_STREAM_TYPE_TS    7   /* TS打包 */
#define NET_DVR_STREAM_TYPE_PS   8   /* PS打包 */
#define NET_DVR_STREAM_TYPE_RTP  9    /* RTP打包 */
#define NET_DVR_STREAM_TYPE_ORIGIN    10 //未打包(视频综合平台解码子系统用)

/*解码通道状态*/
typedef struct
{
    BYTE  byDecodeStatus; /*当前状态:0:未启动，1：启动解码*/
    BYTE  byStreamType;    /*码流类型*/
    BYTE  byPacketType;     /*打包方式*/
    BYTE  byRecvBufUsage; /*接收缓冲使用率*/
    BYTE  byDecBufUsage; /*解码缓冲使用率*/
    BYTE  byFpsDecV; /*视频解码帧率*/
    BYTE  byFpsDecA; /*音频解码帧率*/
    BYTE  byCpuLoad;     /*DSP CPU使用率*/ 
    BYTE  byRes1[4];    
    DWORD dwDecodedV; /*解码的视频帧*/
    DWORD dwDecodedA; /*解码的音频帧*/
    WORD wImgW; /*解码器当前的图像大小,宽*/
    WORD wImgH; //高
    BYTE byVideoFormat; /*视频制式:0-NON,NTSC--1,PAL--2*/
    BYTE byRes2[27];
}NET_DVR_MATRIX_CHAN_STATUS, *LPNET_DVR_MATRIX_CHAN_STATUS;

/*显示通道状态*/
#define NET_DVR_MAX_DISPREGION 16         /*每个显示通道最多可以显示的窗口*/
//分辨率
//
typedef enum
{
	/*VGA*/
    VGA_NOT_AVALIABLE,
    VGA_THS8200_MODE_SVGA_60HZ,    //(800*600)
    VGA_THS8200_MODE_SVGA_75HZ,    //(800*600)
    VGA_THS8200_MODE_XGA_60HZ,     //(1024*768)
    VGA_THS8200_MODE_XGA_70HZ,     //(1024*768)
    VGA_THS8200_MODE_SXGA_60HZ,    //(1280*1024)
    VGA_THS8200_MODE_720P_60HZ,    //(1280*720)
    VGA_THS8200_MODE_1080I_60HZ,   //(1920*1080)
    VGA_THS8200_MODE_1080P_30HZ,   //(1920*1080)
    VGA_THS8200_MODE_UXGA_30HZ,    //(1600*1200)
	/*HDMI*/	
	HDMI_SII9134_MODE_XGA_60HZ,	   //(1024*768)
	HDMI_SII9134_MODE_SXGA_60HZ,   //(1280*1024)
	HDMI_SII9134_MODE_SXGA2_60HZ,  //(1280*960)
	HDMI_SII9134_MODE_720P_60HZ,   //(1280*720)	
	HDMI_SII9134_MODE_720P_50HZ,   //(1280*720)		
	HDMI_SII9134_MODE_1080I_60HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080I_50HZ,  //(1920*1080)	
	HDMI_SII9134_MODE_1080P_25HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080P_30HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080P_50HZ,  //(1920*1080)
	HDMI_SII9134_MODE_1080P_60HZ,  //(1920*1080)
	HDMI_SII9134_MODE_UXGA_60HZ,   //(1600*1200)
	/*DVI*/	
	DVI_SII9134_MODE_XGA_60HZ,	   //(1024*768)
	DVI_SII9134_MODE_SXGA_60HZ,	   //(1280*1024)
	DVI_SII9134_MODE_SXGA2_60HZ,   //(1280*960)
	DVI_SII9134_MODE_720P_60HZ,	   //(1280*720)	
	DVI_SII9134_MODE_720P_50HZ,    //(1280*720)		
	DVI_SII9134_MODE_1080I_60HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080I_50HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_25HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_30HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_50HZ,   //(1920*1080)
	DVI_SII9134_MODE_1080P_60HZ,   //(1920*1080)
	DVI_SII9134_MODE_UXGA_60HZ     //(1600*1200)
}VGA_MODE;

//低帧率定义
#define           LOW_DEC_FPS_1_2                51
#define           LOW_DEC_FPS_1_4                52
#define           LOW_DEC_FPS_1_8                53
#define           LOW_DEC_FPS_1_16               54

/*视频制式标准*/
typedef enum
{
    VS_NON = 0,
    VS_NTSC = 1,
    VS_PAL = 2
}VIDEO_STANDARD;

typedef struct tagNET_DVR_VGA_DISP_CHAN_CFG
{        
    DWORD	dwSize; 
    BYTE	byAudio;			/*音频是否开启,0-否，1-是*/
    BYTE    byAudioWindowIdx;      /*音频开启子窗口*/
    BYTE 	byVgaResolution;      /*VGA的分辨率*/
    BYTE	byVedioFormat;         /*1:NTSC,2:PAL,0-NULL*/
    DWORD	dwWindowMode;		/*画面模式,从能力集获取,目前支持1,2,4,9,16*/       
    BYTE	byJoinDecChan[MAX_WINDOWS];/*各个子窗口关联的解码通道*/
    BYTE	byEnlargeStatus;          /*是否处于放大状态，0：不放大，1：放大*/
    BYTE    byEnlargeSubWindowIndex;//放大的子窗口号
	union
	{
		BYTE byRes[16];
		struct
		{
			/*各个子窗口对应解码通道所对应的解码子系统的槽位号(对于视频综合平台中解码子系统有效)*/
			BYTE	 byJoinDecoderId[MAX_WINDOWS];
		}struVideoPlatform;
		struct
		{
			BYTE	 byRes[16];
		}struNotVideoPlatform;
	}struDiff;
	/*区分共用体，0-视频综合平台内部解码器显示通道配置，1-其他解码器显示通道配置*/
	BYTE		byUnionType;
	BYTE		byScale; /*显示模式，0---真实显示，1---缩放显示( 针对BNC )*/
}NET_DVR_VGA_DISP_CHAN_CFG,*LPNET_DVR_VGA_DISP_CHAN_CFG;


/*显示通道状态*/
#define NET_DVR_MAX_DISPREGION 16 /*每个显示通道最多可以显示的窗口*/
typedef struct
{
    BYTE  byDispStatus;          /*显示状态：0：未显示，1：启动显示*/
    BYTE  byBVGA;                /*0-BNC，1-VGA， 2-HDMI，3-DVI*/
    BYTE  byVideoFormat;        /*视频制式:1:NTSC,2:PAL,0-NON*/
    BYTE  byWindowMode;        /*当前画面模式*/
    BYTE  byJoinDecChan[MAX_WINDOWS];        /*各个子窗口关联的解码通道*/
    BYTE  byFpsDisp[NET_DVR_MAX_DISPREGION]; /*每个子画面的显示帧率*/
    BYTE  byRes2[32];
}NET_DVR_DISP_CHAN_STATUS, *LPNET_DVR_DISP_CHAN_STATUS;

#define MAX_DECODECHANNUM   32//多路解码器最大解码通道数
#define MAX_DISPCHANNUM   24//多路解码器最大显示通道数

/*解码器设备状态*/
typedef struct tagNET_DVR_DECODER_WORK_STATUS
{
    DWORD dwSize;
    NET_DVR_MATRIX_CHAN_STATUS struDecChanStatus[MAX_DECODECHANNUM]; /*解码通道状态*/
    NET_DVR_DISP_CHAN_STATUS   struDispChanStatus[MAX_DISPCHANNUM];  /*显示通道状态*/
    BYTE byAlarmInStatus[MAX_ANALOG_ALARMIN];         /*报警输入状态*/
    BYTE byAalarmOutStatus[MAX_ANALOG_ALARMOUT];       /*报警输出状态*/
    BYTE byAudioInChanStatus;          /*语音对讲状态*/
    BYTE byRes[127];
}NET_DVR_DECODER_WORK_STATUS,*LPNET_DVR_DECODER_WORK_STATUS;

//2009-12-1 增加被动解码播放控制
typedef struct tagNET_DVR_PASSIVEDECODE_CONTROL
{
    DWORD	dwSize;
    DWORD	dwPlayCmd;		/* 播放命令 见文件播放命令*/
    DWORD	dwCmdParam;		/* 播放命令参数 */
    BYTE	byRes[16];//Reverse
}NET_DVR_PASSIVEDECODE_CONTROL,*LPNET_DVR_PASSIVEDECODE_CONTROL;

#define		PASSIVE_DEC_PAUSE			1	/*被动解码暂停(仅文件流有效)*/
#define		PASSIVE_DEC_RESUME			2	/*恢复被动解码(仅文件流有效)*/
#define 	PASSIVE_DEC_FAST          	3   /*快速被动解码(仅文件流有效)*/
#define 	PASSIVE_DEC_SLOW			4   /*慢速被动解码(仅文件流有效)*/
#define 	PASSIVE_DEC_NORMAL      	5   /*正常被动解码(仅文件流有效)*/
#define 	PASSIVE_DEC_ONEBYONE      	6  /*被动解码单帧播放(保留)*/
#define 	PASSIVE_DEC_AUDIO_ON 		7   /*音频开启*/
#define 	PASSIVE_DEC_AUDIO_OFF		8  	 /*音频关闭*/
#define		PASSIVE_DEC_RESETBUFFER	    9    /*清空缓冲区(仅文件流有效)*/
//2009-12-16 增加控制解码器解码通道缩放
typedef struct tagNET_DVR_MATRIX_DECCHAN_CONTROL
{        
	DWORD	dwSize;
	BYTE	byDecChanScaleStatus;/*解码通道显示缩放控制,1表示缩放显示，0表示真实显示*/
	BYTE	byRes[67];//Reverse
}NET_DVR_MATRIX_DECCHAN_CONTROL,*LPNET_DVR_MATRIX_DECCHAN_CONTROL;

/************************************多路解码器(end)***************************************/
//2009-8-19 视频综合平台接口函数
/************************************视频综合平台(begin)***************************************/
#define MAX_SUBSYSTEM_NUM	80   //一个矩阵系统中最多子系统数量
#define MAX_SERIALLEN		36  //最大序列号长度
#define MAX_LOOPPLANNUM		16//最大计划切换组
#define DECODE_TIMESEGMENT 4//计划解码每天时间段数
typedef struct tagNET_DVR_SUBSYSTEMINFO
{
    BYTE		bySubSystemType;//子系统类型，1-解码用子系统，2-编码用子系统，3-级联输出子系统，4-级联输入子系统，5-码分器子系统，6-报警主机子系统，7-智能子系统，0-NULL（此参数只能获取）		
    BYTE		byChan;//子系统通道数，对于码分子系统，代表485串口数量（此参数只能获取）					
    BYTE		byLoginType;//注册类型，1-直连，2-DNS，3-花生壳
    BYTE		byRes1[5];
    NET_DVR_IPADDR   struSubSystemIP;		/*IP地址（可修改）*/
    WORD		wSubSystemPort;        //子系统端口号（可修改）
    BYTE		byRes2[6];
    NET_DVR_IPADDR  struSubSystemIPMask;//子网掩码
    NET_DVR_IPADDR	struGatewayIpAddr;	/* 网关地址*/   
    BYTE		sUserName[NAME_LEN];	/* 用户名 （此参数只能获取）*/
    BYTE		sPassword[PASSWD_LEN];	/*密码（此参数只能获取）*/
    char		sDomainName[MAX_DOMAIN_NAME];//域名(可修改)
    char 		sDnsAddress[MAX_DOMAIN_NAME];/*DNS域名或IP地址*/
    BYTE		sSerialNumber[SERIALNO_LEN];//序列号（此参数只能获取）
}NET_DVR_SUBSYSTEMINFO, *LPNET_DVR_SUBSYSTEMINFO;

typedef struct tagNET_DVR_ALLSUBSYSTEMINFO
{
    DWORD dwSize;
    NET_DVR_SUBSYSTEMINFO struSubSystemInfo[MAX_SUBSYSTEM_NUM];
    BYTE byRes[8];
}NET_DVR_ALLSUBSYSTEMINFO, *LPNET_DVR_ALLSUBSYSTEMINFO;

typedef struct  tagNET_DVR_LOOPPLAN_SUBCFG
{
    DWORD 						    dwSize;
    DWORD							dwPoolTime;		/*轮巡间隔，单位：秒*/      
    NET_DVR_MATRIX_CHAN_INFO_V30 struChanConInfo[MAX_CYCLE_CHAN_V30];
    BYTE               				byRes[16];
}NET_DVR_LOOPPLAN_SUBCFG,*LPNET_DVR_LOOPPLAN_SUBCFG;

typedef struct tagNET_DVR_ALARMMODECFG
{
    DWORD 	dwSize;
    BYTE	byAlarmMode;//报警触发类型，1-轮巡，2-保持		
    WORD	wLoopTime;//轮巡时间, 单位：秒			
    BYTE    byRes[9];
}NET_DVR_ALARMMODECFG,*LPNET_DVR_ALARMMODECFG;

typedef struct  tagNET_DVR_CODESPLITTERINFO
{
    DWORD			dwSize;
    NET_DVR_IPADDR   struIP;		/*码分器IP地址*/
    WORD		wPort;        			//码分器端口号
    BYTE		byRes1[6];
    BYTE		sUserName[NAME_LEN];	/* 用户名 */
    BYTE		sPassword[PASSWD_LEN];	/*密码 */
    BYTE        byChan;//码分器485号
    BYTE		by485Port;//485口地址
    BYTE		byRes2[14];
} NET_DVR_CODESPLITTERINFO, *LPNET_DVR_CODESPLITTERINFO;

typedef struct tagNET_DVR_ASSOCIATECFG
{
    BYTE	byAssociateType;//关联类型，1-报警
    WORD	wAlarmDelay;//报警延时，0－5秒；1－10秒；2－30秒；3－1分钟；4－2分钟；5－5分钟；6－10分钟；
    BYTE	byAlarmNum;//报警号，具体的值由应用赋，相同的报警赋相同的值
    BYTE	byRes[8];
} NET_DVR_ASSOCIATECFG,*LPNET_DVR_ASSOCIATECFG;

typedef struct tagNET_DVR_DYNAMICDECODE
{
    DWORD						    dwSize;
    NET_DVR_ASSOCIATECFG   		struAssociateCfg;//触发动态解码关联结构
    NET_DVR_PU_STREAM_CFG		struPuStreamCfg;//动态解码结构
    BYTE							byRes[8];
}NET_DVR_DYNAMICDECODE,*LPNET_DVR_DYNAMICDECODE;

typedef struct  tagNET_DVR_DECODESCHED
{
	NET_DVR_SCHEDTIME  struSchedTime;//
    BYTE  byDecodeType;/*0-无，1-轮巡解码，2-动态解码*/
	BYTE  byLoopGroup;//轮巡组号
	BYTE  byRes[6];
	NET_DVR_PU_STREAM_CFG struDynamicDec;//动态解码
} NET_DVR_DECODESCHED, *LPNET_DVR_DECODESCHED;

typedef struct tagNET_DVR_PLANDECODE
{
	DWORD dwSize;
	NET_DVR_DECODESCHED struDecodeSched[MAX_DAYS][DECODE_TIMESEGMENT];//周一作为开始，和9000一致
	BYTE byRes[8];
} NET_DVR_PLANDECODE,*LPNET_DVR_PLANDECODE;

//end
/************************************视频综合平台(end)***************************************/
typedef struct 
{	/* 12 bytes */
	DWORD	dwSize;
	char	sUserName[32];
	char 	sPassWord[32];
	char 	sFromName[32];			/* Sender *///字符串中的第一个字符和最后一个字符不能是"@",并且字符串中要有"@"字符
	char 	sFromAddr[48];			/* Sender address */
	char 	sToName1[32];			/* Receiver1 */
	char 	sToName2[32];			/* Receiver2 */
	char 	sToAddr1[48];			/* Receiver address1 */
	char 	sToAddr2[48];			/* Receiver address2 */
	char	sEmailServer[32];		/* Email server address */
	BYTE	byServerType;			/* Email server type: 0-SMTP, 1-POP, 2-IMTP…*/
	BYTE	byUseAuthen;			/* Email server authentication method: 1-enable, 0-disable */
	BYTE	byAttachment;			/* enable attachment */
	BYTE	byMailinterval;			/* mail interval 0-2s, 1-3s, 2-4s. 3-5s*/
} NET_DVR_EMAILCFG, *LPNET_DVR_EMAILCFG;

typedef struct 
{
	DWORD dwSize;
	NET_DVR_COMPRESSION_INFO_EX  struLowCompression;	//定时录像
	NET_DVR_COMPRESSION_INFO_EX  struEventCompression;	//事件触发录像
}NET_DVR_COMPRESSIONCFG_NEW, *LPNET_DVR_COMPRESSIONCFG_NEW;

//球机位置信息
typedef struct
{
    WORD wAction;//获取时该字段无效
    WORD wPanPos;//水平参数
    WORD wTiltPos;//垂直参数
    WORD wZoomPos;//变倍参数
}NET_DVR_PTZPOS, *LPNET_DVR_PTZPOS;

//球机范围信息
typedef struct
{
    WORD wPanPosMin;//水平参数min
    WORD wPanPosMax;//水平参数max
    WORD wTiltPosMin;//垂直参数min
    WORD wTiltPosMax;//垂直参数max
    WORD wZoomPosMin;//变倍参数min
    WORD wZoomPosMax;//变倍参数max
}NET_DVR_PTZSCOPE, *LPNET_DVR_PTZSCOPE;

//rtsp配置 ipcamera专用
typedef struct
{
    DWORD dwSize;         //长度
    WORD  wPort;          //rtsp服务器侦听端口
    BYTE  byReserve[54];  //预留
}NET_DVR_RTSPCFG, *LPNET_DVR_RTSPCFG;

/********************************接口参数结构(begin)*********************************/

//NET_DVR_Login()参数结构
typedef struct
{
	BYTE sSerialNumber[SERIALNO_LEN];   //序列号
	BYTE byAlarmInPortNum;		        //DVR报警输入个数
	BYTE byAlarmOutPortNum;		        //DVR报警输出个数
	BYTE byDiskNum;				        //DVR硬盘个数
	BYTE byDVRType;				        //DVR类型, 1:DVR 2:ATM DVR 3:DVS ......
	BYTE byChanNum;				        //DVR 通道个数
	BYTE byStartChan;			        //起始通道号,例如DVS-1,DVR - 1
}NET_DVR_DEVICEINFO, *LPNET_DVR_DEVICEINFO;

//NET_DVR_Login_V30()参数结构
typedef struct
{
    BYTE sSerialNumber[SERIALNO_LEN];  //序列号
    BYTE byAlarmInPortNum;		        //报警输入个数
    BYTE byAlarmOutPortNum;		        //报警输出个数
    BYTE byDiskNum;				    //硬盘个数
    BYTE byDVRType;				    //设备类型, 1:DVR 2:ATM DVR 3:DVS ......
    BYTE byChanNum;				    //模拟通道个数
    BYTE byStartChan;			        //起始通道号,例如DVS-1,DVR - 1
    BYTE byAudioChanNum;                //语音通道数
    BYTE byIPChanNum;					//最大数字通道个数  
	BYTE byZeroChanNum;			//零通道编码个数 //2010-01-16
	BYTE byMainProto;			//主码流传输协议类型 0-private, 1-rtsp
	BYTE bySubProto;				//子码流传输协议类型0-private, 1-rtsp
    BYTE bySupport;        //能力，位与结果为0表示不支持，1表示支持，
                            //bySupport & 0x1, 表示是否支持智能搜索
                            //bySupport & 0x2, 表示是否支持备份
                            //bySupport & 0x4, 表示是否支持压缩参数能力获取
                            //bySupport & 0x8, 表示是否支持多网卡
                            //bySupport & 0x10, 表示支持远程SADP
                            //bySupport & 0x20  表示支持Raid卡功能
                            //bySupport & 0x40  表示支持IPSAN 目录查找
    BYTE byRes1[20];					//保留
}NET_DVR_DEVICEINFO_V30, *LPNET_DVR_DEVICEINFO_V30;

//sdk网络环境枚举变量，用于远程升级
typedef enum _SDK_NET_ENV
{
    LOCAL_AREA_NETWORK = 0,
        WIDE_AREA_NETWORK
}SDK_NETWORK_ENVIRONMENT;

//显示模式
typedef enum
{
	NORMALMODE = 0,
	OVERLAYMODE
}DISPLAY_MODE;

//发送模式
typedef enum
{
	PTOPTCPMODE = 0,
	PTOPUDPMODE,
	MULTIMODE,
	RTPMODE,
	RESERVEDMODE
}SEND_MODE;

//抓图模式
typedef enum 
{
	BMP_MODE = 0,		//BMP模式
	JPEG_MODE = 1		//JPEG模式 
}CAPTURE_MODE;

//实时声音模式
typedef enum
{
	MONOPOLIZE_MODE = 1,//独占模式
	SHARE_MODE = 2		//共享模式
}REALSOUND_MODE;

//软解码预览参数
typedef struct
{
	LONG lChannel;//通道号
	LONG lLinkMode;//最高位(31)为0表示主码流，为1表示子，0－30位表示码流连接方式: 0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-音视频分开(TCP)
	HWND hPlayWnd;//播放窗口的句柄,为NULL表示不播放图象
	char* sMultiCastIP;//多播组地址
}NET_DVR_CLIENTINFO, *LPNET_DVR_CLIENTINFO;

//SDK状态信息(9000新增)
typedef struct 
{
    DWORD dwTotalLoginNum;		//当前login用户数
    DWORD dwTotalRealPlayNum;	//当前realplay路数
    DWORD dwTotalPlayBackNum;	//当前回放或下载路数
    DWORD dwTotalAlarmChanNum;	//当前建立报警通道路数
    DWORD dwTotalFormatNum;		//当前硬盘格式化路数
    DWORD dwTotalFileSearchNum;	//当前日志或文件搜索路数
    DWORD dwTotalLogSearchNum;	//当前日志或文件搜索路数
    DWORD dwTotalSerialNum;	    //当前透明通道路数
    DWORD dwTotalUpgradeNum;	//当前升级路数
    DWORD dwTotalVoiceComNum;	//当前语音转发路数
    DWORD dwTotalBroadCastNum;	//当前语音广播路数
    DWORD dwTotalListenNum;	    //当前网络监听路数
    DWORD dwEmailTestNum;       //当前邮件计数路数
    DWORD dwBackupNum;          // 当前文件备份路数
	DWORD dwTotalInquestUploadNum; //当前审讯上传路数
    DWORD dwRes[6];
}NET_DVR_SDKSTATE, *LPNET_DVR_SDKSTATE;

//SDK功能支持信息(9000新增)
typedef struct 
{
    DWORD dwMaxLoginNum;		//最大login用户数 MAX_LOGIN_USERS
    DWORD dwMaxRealPlayNum;		//最大realplay路数 WATCH_NUM
    DWORD dwMaxPlayBackNum;		//最大回放或下载路数 WATCH_NUM
    DWORD dwMaxAlarmChanNum;	//最大建立报警通道路数 ALARM_NUM
    DWORD dwMaxFormatNum;		//最大硬盘格式化路数 SERVER_NUM
    DWORD dwMaxFileSearchNum;	//最大文件搜索路数 SERVER_NUM
    DWORD dwMaxLogSearchNum;	//最大日志搜索路数 SERVER_NUM
    DWORD dwMaxSerialNum;	    //最大透明通道路数 SERVER_NUM
    DWORD dwMaxUpgradeNum;	    //最大升级路数 SERVER_NUM
    DWORD dwMaxVoiceComNum;		//最大语音转发路数 SERVER_NUM
    DWORD dwMaxBroadCastNum;	//最大语音广播路数 MAX_CASTNUM
    DWORD dwRes[10];
}NET_DVR_SDKABL, *LPNET_DVR_SDKABL;

//报警设备信息
typedef struct
{   
    BYTE byUserIDValid;                 /* userid是否有效 0-无效，1-有效 */
    BYTE bySerialValid;                 /* 序列号是否有效 0-无效，1-有效 */
    BYTE byVersionValid;                /* 版本号是否有效 0-无效，1-有效 */
    BYTE byDeviceNameValid;             /* 设备名字是否有效 0-无效，1-有效 */
    BYTE byMacAddrValid;                /* MAC地址是否有效 0-无效，1-有效 */    
    BYTE byLinkPortValid;               /* login端口是否有效 0-无效，1-有效 */
    BYTE byDeviceIPValid;               /* 设备IP是否有效 0-无效，1-有效 */
    BYTE bySocketIPValid;               /* socket ip是否有效 0-无效，1-有效 */
    LONG lUserID;                       /* NET_DVR_Login()返回值, 布防时有效 */
    BYTE sSerialNumber[SERIALNO_LEN];	/* 序列号 */
    DWORD dwDeviceVersion;			    /* 版本信息 高16位表示主版本，低16位表示次版本*/
    char sDeviceName[NAME_LEN];		    /* 设备名字 */
    BYTE byMacAddr[MACADDR_LEN];		/* MAC地址 */    
    WORD wLinkPort;                     /* link port */
    char sDeviceIP[128];    			/* IP地址 */
    char sSocketIP[128];    			/* 报警主动上传时的socket IP地址 */
    BYTE byIpProtocol;                  /* Ip协议 0-IPV4, 1-IPV6 */
    BYTE byRes2[11];
}NET_DVR_ALARMER, *LPNET_DVR_ALARMER;

//硬解码显示区域参数(子结构)
typedef struct
{
	long bToScreen;
	long bToVideoOut;
	long nLeft;
	long nTop;
	long nWidth;
	long nHeight;
	long nReserved;
}NET_DVR_DISPLAY_PARA, *LPNET_DVR_DISPLAY_PARA;

//硬解码预览参数
typedef struct
{
	LONG lChannel;//通道号
	LONG lLinkMode; //最高位(31)为0表示主码流，为1表示子，0－30位表示码流连接方式:0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-电话线，5－128k宽带，6－256k宽带，7－384k宽带，8－512k宽带；
	char* sMultiCastIP;
	NET_DVR_DISPLAY_PARA struDisplayPara;
}NET_DVR_CARDINFO, *LPNET_DVR_CARDINFO;

//录象文件参数
typedef struct 
{
	char sFileName[100];//文件名
	NET_DVR_TIME struStartTime;//文件的开始时间
	NET_DVR_TIME struStopTime;//文件的结束时间
	DWORD dwFileSize;//文件的大小
}NET_DVR_FIND_DATA, *LPNET_DVR_FIND_DATA;

//录象文件参数(9000)
typedef struct 
{
    char sFileName[100];//文件名
    NET_DVR_TIME struStartTime;//文件的开始时间
    NET_DVR_TIME struStopTime;//文件的结束时间
    DWORD dwFileSize;//文件的大小
    char sCardNum[32];
    BYTE byLocked;//9000设备支持,1表示此文件已经被锁定,0表示正常的文件
	BYTE byFileType;  //文件类型:0－定时录像,1-移动侦测 ，2－报警触发，
	//3-报警|移动侦测 4-报警&移动侦测 5-命令触发 6-手动录像
    BYTE byRes[2];
}NET_DVR_FINDDATA_V30, *LPNET_DVR_FINDDATA_V30;

//录象文件参数(带卡号)
typedef struct 
{
	char sFileName[100];//文件名
	NET_DVR_TIME struStartTime;//文件的开始时间
	NET_DVR_TIME struStopTime;//文件的结束时间
	DWORD dwFileSize;//文件的大小
	char sCardNum[32];
}NET_DVR_FINDDATA_CARD, *LPNET_DVR_FINDDATA_CARD;


//录象文件查找条件结构
typedef struct 
{
    LONG lChannel;//通道号
    DWORD dwFileType;//录象文件类型0xff－全部，0－定时录像,1-移动侦测 ，2－报警触发，
                    //3-报警|移动侦测 4-报警&移动侦测 5-命令触发 6-手动录像
    DWORD dwIsLocked;//是否锁定 0-正常文件,1-锁定文件, 0xff表示所有文件
    DWORD dwUseCardNo;//是否使用卡号
    BYTE sCardNumber[32];//卡号
    NET_DVR_TIME struStartTime;//开始时间
    NET_DVR_TIME struStopTime;//结束时间
}NET_DVR_FILECOND, *LPNET_DVR_FILECOND;

//云台区域选择放大缩小(私有 快球专用)
typedef struct 
{
	int xTop;     //方框起始点的x坐标
	int yTop;     //方框结束点的y坐标
	int xBottom;  //方框结束点的x坐标
	int yBottom;  //方框结束点的y坐标
	int bCounter; //保留
}NET_DVR_POINT_FRAME, *LPNET_DVR_POINT_FRAME;

//语音对讲参数
typedef struct tagNET_DVR_COMPRESSION_AUDIO
{
	BYTE  byAudioEncType;   //音频编码类型 0-OggVorbis;1-G711_U;2-G711_A
	BYTE  byres[7];//这里保留音频的压缩参数 
}NET_DVR_COMPRESSION_AUDIO, *LPNET_DVR_COMPRESSION_AUDIO;

//2009-7-22
#define NET_DVR_GET_AP_INFO_LIST	305//获取无线网络资源参数
#define NET_DVR_SET_WIFI_CFG		306	//设置IP监控设备无线参数
#define NET_DVR_GET_WIFI_CFG		307	//获取IP监控设备无线参数
#define NET_DVR_SET_WIFI_WORKMODE	308	//设置IP监控设备网口工作模式参数
#define NET_DVR_GET_WIFI_WORKMODE	309	//获取IP监控设备网口工作模式参数

#define IW_ESSID_MAX_SIZE						 32
#define WIFI_WEP_MAX_KEY_COUNT					 4
#define WIFI_WEP_MAX_KEY_LENGTH					 33
#define WIFI_WPA_PSK_MAX_KEY_LENGTH				 63
#define WIFI_WPA_PSK_MIN_KEY_LENGTH				 8
#define WIFI_MAX_AP_COUNT						 20

typedef struct tagNET_DVR_AP_INFO
{
	char  sSsid[IW_ESSID_MAX_SIZE];
	DWORD  dwMode;						/* 0 mange 模式;1 ad-hoc模式，参见NICMODE */
	DWORD  dwSecurity;           /*0 不加密；1 wep加密；2 wpa-psk;3 wpa-Enterprise;4-WPA2_PSK参见WIFISECURITY*/
	DWORD  dwChannel;            /*1-11表示11个通道*/
	DWORD  dwSignalStrength;    /*0-100信号由最弱变为最强*/
	DWORD  dwSpeed;               /*速率,单位是0.01mbps*/
}NET_DVR_AP_INFO,*LPNET_DVR_AP_INFO;

typedef struct tagNET_DVR_AP_INFO_LIST
{
	DWORD dwSize;
	DWORD dwCount;        /*无线AP数量，不超过20*/
	NET_DVR_AP_INFO struApInfo[WIFI_MAX_AP_COUNT];
}NET_DVR_AP_INFO_LIST,*LPNET_DVR_AP_INFO_LIST;

typedef struct tagNET_DVR_WIFIETHERNET
{	
	char sIpAddress[16];				/*IP地址*/
	char sIpMask[16];					/*掩码*/	
	BYTE	byMACAddr[MACADDR_LEN];		/*物理地址，只用来显示*/
	BYTE	bRes[2];
	DWORD	dwEnableDhcp;				/*是否启动dhcp  0不启动 1启动*/
	DWORD	dwAutoDns;					/*如果启动dhcp是否自动获取dns,0不自动获取 1自动获取；对于有线如果启动dhcp目前自动获取dns*/	
	char sFirstDns[16];						 /*第一个dns域名*/
	char sSecondDns[16];					 /*第二个dns域名*/
	char sGatewayIpAddr[16]; 				/* 网关地址*/
	BYTE   bRes2[8];
}NET_DVR_WIFIETHERNET,*LPNET_DVR_WIFIETHERNET;

typedef struct tagNET_DVR_WIFI_CFG_EX
{
	NET_DVR_WIFIETHERNET struEtherNet;        /*wifi网口*/
	char sEssid[IW_ESSID_MAX_SIZE];	 /*SSID*/
	DWORD dwMode;      /* 0 mange 模式;1 ad-hoc模式，参见*/
	DWORD dwSecurity; /*0-不加密;1-wep加密;2-wpa-psk; 3-WPA_ENTPRISE;4-WPA2_PSK */
	union 
	{
		struct 
		{
			DWORD dwAuthentication;/*0 -开放式 1-共享式*/
			DWORD dwKeyLength;/* 0 -64位；1- 128位；2-152位*/
			DWORD dwKeyType;/*0 16进制;1 ASCI */
			DWORD dwActive;/*0 索引：0---3表示用哪一个密钥*/
			char sKeyInfo[WIFI_WEP_MAX_KEY_COUNT][WIFI_WEP_MAX_KEY_LENGTH];
		}wep;
		struct 
		{
			DWORD dwKeyLength;/*8-63个ASCII字符*/
			char sKeyInfo[WIFI_WPA_PSK_MAX_KEY_LENGTH];
			BYTE byEncryptType;  /*WPA/WPA2模式下加密类型,0-AES, 1-TKIP*/
		}wpa_psk;
		
	}key;	
}NET_DVR_WIFI_CFG_EX,*LPNET_DVR_WIFI_CFG_EX;

//wifi配置结构
typedef struct tagNET_DVR_WIFI_CFG
{
	DWORD dwSize;
	NET_DVR_WIFI_CFG_EX struWifiCfg;
}NET_DVR_WIFI_CFG,*LPNET_DVR_WIFI_CFG;

//wifi工作模式
typedef struct tagNET_DVR_WIFI_WORKMODE
{
	DWORD dwSize;
	DWORD dwNetworkInterfaceMode; /*0 自动切换模式　1 有线模式*/
}NET_DVR_WIFI_WORKMODE,*LPNET_DVR_WIFI_WORKMODE;

/******************************能力集获取*********************************/
//能力获取命令
#define DEVICE_ALL_ABILITY            0x000  //设备全部能力
#define DEVICE_SOFTHARDWARE_ABILITY   0x001  //设备软硬件能力
#define DEVICE_NETWORK_ABILITY        0x002   //设备网络能力
#define DEVICE_ENCODE_ALL_ABILITY     0x003  //设备所有编码能力
#define	DEVICE_ENCONE_CURRENT         0x004  //设备当前编码能力
#define IPC_FRONT_PARAMETER				0x005	//ipc前端参数
#define IPC_UPGRADE_DESCRIPTION			0x006	//ipc升级信息
#define VCA_DEV_ABILITY 	 0x100 //设备智能分析的总能力
#define VCA_CHAN_ABILITY     0x110 //行为分析能力
#define MATRIXDECODER_ABILITY 0x200 //多路解码器显示、解码能力
#define COMPRESSIONCFG_ABILITY  0x400    //获取压缩参数能力获取

//报警回调命令
//对应NET_DVR_PLATE_RESULT
#define  COMM_ALARM_PLATE				0x1101	//车牌识别报警信息
//对应NET_VCA_RULE_ALARM
#define  COMM_ALARM_RULE				0x1102	//行为分析报警信息
#define  COMM_ALARM_PDC                 0x1103  // 人数统计报警信息
#define  COMM_ALARM_VIDEOPLATFORM        0x1104  // 视频综合平台报警
#define COMM_ALARM_ALARMHOST        0x1105  // 网络报警主机报警
#define  COMM_ALARM_FACE                0x1106   // 人脸检测识别报警信息
#define COMM_RULE_INFO_UPLOAD           0x1107  //  事件数据信息上传
#define COMM_ALARM_AID                  0x1110      // 交通事件报警信息
#define COMM_ALARM_TPS                  0x1111  // 交通参数统计报警信息
#define COMM_SENSOR_VALUE_UPLOAD		0x1120  // 模拟量数据实时上传
#define COMM_SENSOR_ALARM          		0x1121  // 模拟量报警上传
#define COMM_SWITCH_ALARM				0x1122	// 开关量报警
#define COMM_ALARMHOST_EXCEPTION        0x1123  // 报警主机故障报警
//车牌报警NET_DVR_PLATE_RESULT
#define COMM_UPLOAD_PLATE_RESULT		0x2800	//上传车牌信息

//结构参数宏定义 
#define VCA_MAX_POLYGON_POINT_NUM		10		//检测区域最多支持10个点的多边形
#define MAX_RULE_NUM					8		//最多规则条数
#define MAX_TARGET_NUM    				30		//最多目标个数
#define MAX_CALIB_PT 					6		//最大标定点个数
#define MIN_CALIB_PT 					4		//最小标定点个数
#define MAX_TIMESEGMENT_2	    		2		//最大时间段数
#define MAX_LICENSE_LEN					16		//车牌号最大长度
#define MAX_PLATE_NUM					3		//车牌个数
#define MAX_MASK_REGION_NUM				4       //最多四个屏蔽区域
#define MAX_SEGMENT_NUM					6        //摄像机标定最大样本线数目
#define MIN_SEGMENT_NUM					3        //摄像机标定最小样本线数目


//智能控制信息
#define MAX_VCA_CHAN  16//最大智能通道数
typedef struct tagNET_VCA_CTRLINFO
{
	BYTE   byVCAEnable;		//是否开启智能
	BYTE   byVCAType;	    //智能能力类型，VCA_CHAN_ABILITY_TYPE 
	BYTE   byStreamWithVCA; //码流中是否带智能信息
    BYTE   byMode;			//模式，VCA_CHAN_MODE_TYPE ,atm能力的时候需要配置
	BYTE   byRes[4]; 		//保留，设置为0 
}NET_VCA_CTRLINFO, * LPNET_VCA_CTRLINFO;

//智能控制信息结构
typedef struct tagNET_VCA_CTRLCFG
{
	DWORD dwSize;
	NET_VCA_CTRLINFO  struCtrlInfo[MAX_VCA_CHAN]; 	//控制信息,数组0对应设备的起始通道
	BYTE byRes[16];
}NET_VCA_CTRLCFG, * LPNET_VCA_CTRLCFG;

//智能设备能力集
typedef struct tagNET_VCA_DEV_ABILITY
{
	DWORD dwSize;			//结构长度
	BYTE byVCAChanNum;		//智能通道个数
	BYTE byPlateChanNum; 	//车牌通道个数
	BYTE byBBaseChanNum;	//行为基本版个数
	BYTE byBAdvanceChanNum; //行为高级版个数
	BYTE byBFullChanNum;    //行为完整版个数
	BYTE byATMChanNum;		//智能ATM个数
    BYTE byPDCChanNum;      //人数统计通道个数
    BYTE byITSChanNum;      // 交通事件通道个数
    BYTE byBPrisonChanNum;	// 行为监狱版通道个数
    BYTE byRes[31];
}NET_VCA_DEV_ABILITY, *LPNET_VCA_DEV_ABILITY;


//行为分析能力类型
typedef enum _VCA_ABILITY_TYPE_
{
    TRAVERSE_PLANE_ABILITY           = 0x01,      //穿越警戒面
    ENTER_AREA_ABILITY          = 0x02,      //进入区域
    EXIT_AREA_ABILITY           = 0x04,      //离开区域
    INTRUSION_ABILITY           = 0x08,      //入侵
    LOITER_ABILITY               = 0x10,     //徘徊
    LEFT_TAKE_ABILITY            = 0x20,     //物品遗留拿取
    PARKING_ABILITY              = 0x40,     //停车
    RUN_ABILITY                  = 0x80,    //快速移动
	HIGH_DENSITY_ABILITY         = 0x100,    //人员聚集
	LF_TRACK_ABILITY			 = 0x200,    //球机跟踪
    VIOLENT_MOTION_ABILITY		= 0x400,		// 剧烈运动检测
    REACH_HIGHT_ABILITY			= 0x800,		// 攀高检测
    GET_UP_ABILITY				= 0x1000,	// 起身检测
    LEFT_ABILITY                = 0x2000,       // 物品遗留
    TAKE_ABILITY                = 0x4000,       // 物品拿取
    HUMAN_ENTER_ABILITY         = 0x10000000,   //人靠近ATM           只在ATM_PANEL模式下支持
    OVER_TIME_ABILITY           = 0x20000000,   //操作超时            只在ATM_PANEL模式下支持
	STICK_UP_ABILITY             = 0x40000000,  //贴纸条
	INSTALL_SCANNER_ABILITY      = 0x80000000   //安装读卡器
}VCA_ABILITY_TYPE;


//智能通道类型
typedef enum _VCA_CHAN_ABILITY_TYPE_
{
	VCA_BEHAVIOR_BASE     =  1,   //行为分析基本版
	VCA_BEHAVIOR_ADVANCE  =  2,   //行为分析高级版
	VCA_BEHAVIOR_FULL     =  3,   //行为分析完整版
    VCA_PLATE     		  =  4,   //车牌能力
	VCA_ATM               =  5,    //ATM能力
    VCA_PDC               =  6,      // 人流量统计
    VCA_ITS               =  7,      // 智能 交通事件
    VCA_BEHAVIOR_PRISON   =  8,     // 行为分析监狱版      
}VCA_CHAN_ABILITY_TYPE;

//智能ATM模式类型(ATM能力特有)
typedef enum _VCA_CHAN_MODE_TYPE_
{
    VCA_ATM_PANEL     =  0, //ATM面板
    VCA_ATM_SURROUND  =  1,  //ATM环境
    VCA_ATM_FACE		= 2	//ATM人脸
}VCA_CHAN_MODE_TYPE;


//通道能力输入参数
typedef struct tagNET_VCA_CHAN_IN_PARAM
{
	BYTE byVCAType;	    //VCA_CHAN_ABILITY_TYPE枚举值
	BYTE byMode;		//模式，VCA_CHAN_MODE_TYPE ,atm能力的时候需要配置  当VCA_TYPE 为交通事件 模式参照TRAFFIC_SCENE_MODE
	BYTE byRes[2]; 	    //保留，设置为0 
}NET_VCA_CHAN_IN_PARAM, *LPNET_VCA_CHAN_IN_PARAM;


//行为能力集结构
typedef struct tagNET_VCA_BEHAVIOR_ABILITY
{
	DWORD dwSize;		 //结构长度
	DWORD dwAbilityType; //支持的能力类型，按位表示，见VCA_ABILITY_TYPE定义
	BYTE byMaxRuleNum;	 //最大规则数
	BYTE byMaxTargetNum; //最大目标数
    BYTE	bySupport;		// 支持的功能类型   按位表示  
                            // bySupport & 0x01 支持标定功能
    BYTE byRes[9];        //保留，设置为0
}NET_VCA_BEHAVIOR_ABILITY, *LPNET_VCA_BEHAVIOR_ABILITY;

// 交通能力集结构
typedef struct tagNET_DVR_ITS_ABILITY
{
    DWORD 	dwSize;             // 结构体大小
    DWORD 	dwAbilityType;      // 支持的能力列表  参照ITS_ABILITY_TYPE
	BYTE 	byMaxRuleNum;	 	//最大规则数
	BYTE 	byMaxTargetNum; 	//最大目标数
   	BYTE	byRes[10];		    // 保留
}NET_DVR_ITS_ABILITY, *LPNET_DVR_ITS_ABILITY;

/***********************************end*******************************************/

/************************************智能参数结构*********************************/
//智能共用结构
//坐标值归一化,浮点数值为当前画面的百分比大小, 精度为小数点后三位
//点坐标结构
typedef struct tagNET_VCA_POINT
{	
	float fX;								// X轴坐标, 0.001~1
	float fY;								//Y轴坐标, 0.001~1
}NET_VCA_POINT, *LPNET_VCA_POINT;

//区域框结构
typedef struct tagNET_VCA_RECT
{
	float fX;               //边界框左上角点的X轴坐标, 0.001~1
	float fY;               //边界框左上角点的Y轴坐标, 0.001~1
	float fWidth;           //边界框的宽度, 0.001~1
	float fHeight;          //边界框的高度, 0.001~1
}NET_VCA_RECT, *LPNET_VCA_RECT;

//行为分析事件类型
typedef enum _VCA_EVENT_TYPE_
{
	VCA_TRAVERSE_PLANE		= 0x1,    //穿越警戒面
	VCA_ENTER_AREA		= 0x2,    //目标进入区域,支持区域规则
	VCA_EXIT_AREA		= 0x4,    //目标离开区域,支持区域规则
	VCA_INTRUSION		= 0x8,    //周界入侵,支持区域规则
	VCA_LOITER			= 0x10,   //徘徊,支持区域规则
	VCA_LEFT_TAKE		= 0x20,   //物品遗留拿取,支持区域规则
	VCA_PARKING			= 0x40,   //停车,支持区域规则
	VCA_RUN				= 0x80,   //快速移动,支持区域规则
	VCA_HIGH_DENSITY	= 0x100,  //区域内人员聚集,支持区域规则
    VCA_VIOLENT_MOTION	= 0x200,		// 剧烈运动检测
    VCA_REACH_HIGHT		= 0x400,		// 攀高检测
    VCA_GET_UP			= 0x800,	// 起身检测
    VCA_LEFT            = 0x1000,   // 物品遗留
    VCA_TAKE            = 0x2000,   // 物品拿取
    VCA_HUMAN_ENTER     = 0x10000000,   //人靠近ATM           只在ATM_PANEL模式下支持
    VCA_OVER_TIME       = 0x20000000,   //操作超时            只在ATM_PANEL模式下支持
    VCA_STICK_UP        = 0x40000000,  //贴纸条,支持区域规则
    VCA_INSTALL_SCANNER = 0x80000000 //安装读卡器,支持区域规则
}VCA_EVENT_TYPE;

//警戒面穿越方向类型
typedef enum _VCA_CROSS_DIRECTION_
{
	VCA_BOTH_DIRECTION,  // 双向 
	VCA_LEFT_GO_RIGHT,   // 由左至右 
	VCA_RIGHT_GO_LEFT    // 由右至左 
}VCA_CROSS_DIRECTION;

//线结构
typedef struct tagNET_VCA_LINE
{
	NET_VCA_POINT struStart;    //起点 
	NET_VCA_POINT struEnd;      //终点
}NET_VCA_LINE, *LPNET_VCA_LINE;

//多边型结构体
typedef struct tagNET_VCA_POLYGON
{
	DWORD dwPointNum;                                  //有效点 大于等于3，若是3点在一条线上认为是无效区域，线交叉认为是无效区域 
	NET_VCA_POINT  struPos[VCA_MAX_POLYGON_POINT_NUM]; //多边形边界点,最多十个 
}NET_VCA_POLYGON, *LPNET_VCA_POLYGON;

//警戒面参数
typedef struct tagNET_VCA_TRAVERSE_PLANE
{	
    NET_VCA_LINE struPlaneBottom;  //警戒面底边
    VCA_CROSS_DIRECTION dwCrossDirection; //穿越方向: 0-双向，1-从左到右，2-从右到左
    BYTE byRes1;//保留
    BYTE byPlaneHeight; //警戒面高度
    BYTE byRes2[38];				//保留
}NET_VCA_TRAVERSE_PLANE, *LPNET_VCA_TRAVERSE_PLANE;

//进入/离开区域参数
typedef struct tagNET_VCA_AREA
{
    NET_VCA_POLYGON struRegion;//区域范围
    BYTE byRes[8];
}NET_VCA_AREA, *LPNET_VCA_AREA;

//根据报警延迟时间来标识报警中带图片，报警间隔和IO报警一致，1秒发送一个。
//入侵参数
typedef struct tagNET_VCA_INTRUSION
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD wDuration;    //行为事件触发时间阈值: 1-120秒，建议5秒，判断是有效报警的时间  在ATM系统中触发文件阈值为 1-1000秒
    BYTE byRes[6];
}NET_VCA_INTRUSION, *LPNET_VCA_INTRUSION;

//徘徊参数
typedef struct tagNET_VCA_PARAM_LOITER
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD wDuration; //触发时间阈值：1-120秒，建议10秒
    BYTE byRes[6];
}NET_VCA_LOITER, *LPNET_VCA_LOITER;

//物品遗留/物品拿取参数
typedef struct tagNET_VCA_TAKE_LEFT
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD wDuration; //触发时间阈值：1-120秒，建议10秒
    BYTE byRes[6];
}NET_VCA_TAKE_LEFT, *LPNET_VCA_TAKE_LEFT;

//停车参数
typedef struct tagNET_VCA_PARKING
{
    NET_VCA_POLYGON struRegion;	//区域范围
    WORD wDuration;				//触发时间阈值：1-100秒，建议10秒
    BYTE byRes[6];
}NET_VCA_PARKING, *LPNET_VCA_PARKING;

//快速移动参数
typedef struct tagNET_VCA_RUN
{
	NET_VCA_POLYGON struRegion;	//区域范围
    float  fRunDistance;		//人快速移动最大距离, 范围: [0.1, 1.00] 像素模式 实际模式(1,20)m/s
    BYTE    byRes1;             // 保留字节
    BYTE    byMode;             // 0 像素模式  1 实际模式
    BYTE byRes[2];
}NET_VCA_RUN, *LPNET_VCA_RUN;

//人员聚集参数
typedef struct tagNET_VCA_HIGH_DENSITY
{
    NET_VCA_POLYGON struRegion;//区域范围
    float           fDensity;       //聚集比率, 范围: [0.1, 1.0]
    BYTE            byRes;          // 保留字节
    WORD            wDuration;      // 触发人员聚集参数报警阈值 20-360s
}NET_VCA_HIGH_DENSITY, *LPNET_VCA_HIGH_DENSITY; 

//剧烈运动参数
typedef struct tagNET_VCA_VIOLENT_MOTION
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD wDuration; //触发剧烈运动报警阈值：1-120秒
    BYTE  bySensitivity;       //灵敏度参数，范围[1,5]
    BYTE byRes[5];
}NET_VCA_VIOLENT_MOTION, *LPNET_VCA_VIOLENT_MOTION; 
// 攀高参数
typedef struct tagNET_VCA_REACH_HIGHT
{
    NET_VCA_LINE struVcaLine;   //攀高警戒面
    WORD wDuration; //触发攀高报警阈值：1-120秒
    BYTE	byRes[6];           // 保留字节
}NET_VCA_REACH_HIGHT, *LPNET_VCA_REACH_HIGHT;

// 起床参数
typedef struct tagNET_VCA_GET_UP
{
    NET_VCA_POLYGON struRegion; // 区域范围
    WORD	wDuration;	// 触发起床报警阈值1-120 秒
    BYTE	byRes[6];		// 保留字节
}NET_VCA_GET_UP, * LPNET_VCA_GET_UP;

// 物品遗留
typedef struct tagNET_VCA_LEFT
{
    NET_VCA_POLYGON struRegion;     // 区域范围
    WORD      wDuration;      // 触发物品遗留报警阈值 4-60秒
    BYTE       byRes[6];       // 保留字节
}NET_VCA_LEFT, *LPNET_VCA_LEFT;

// 物品拿取
typedef struct tagNET_VCA_TAKE
{
    NET_VCA_POLYGON struRegion;     // 区域范围
    WORD            wDuration;      // 触发物品拿取报警阈值4-60秒
    BYTE            byRes[6];       // 保留字节
}NET_VCA_TAKE, *LPNET_VCA_TAKE;

typedef struct tagNET_VCA_OVER_TIME
{
    NET_VCA_POLYGON     struRegion;    // 区域范围
    WORD               wDuration;  // 操作报警时间阈值 4s-60000s
    BYTE   byRes[6];   // 保留字节
}NET_VCA_OVER_TIME, *LPNET_VCA_OVER_TIME;

typedef struct tagNET_VCA_HUMAN_ENTER
{
    DWORD                dwRes[23];			//保留字节
}NET_VCA_HUMAN_ENTER, *LPNET_VCA_HUMAN_ENTER;

//贴纸条参数
typedef struct tagNET_VCA_STICK_UP
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD wDuration; //触发时间阈值：4-60秒，建议10秒
    BYTE  bySensitivity;       //灵敏度参数，范围[1,5]
    BYTE byRes[5];
}NET_VCA_STICK_UP, *LPNET_VCA_STICK_UP; 

//读卡器参数
typedef struct tagNET_VCA_SCANNER
{
    NET_VCA_POLYGON struRegion;//区域范围
    WORD wDuration; //读卡持续时间：4-60秒
    BYTE  bySensitivity;       //灵敏度参数，范围[1,5]
    BYTE byRes[5];
}NET_VCA_SCANNER, *LPNET_VCA_SCANNER; 


//警戒事件参数
typedef union tagNET_VCA_EVENT_UNION
{
	DWORD                uLen[23];			//参数
	NET_VCA_TRAVERSE_PLANE    struTraversePlane;		//穿越警戒面参数 
	NET_VCA_AREA    	 struArea;			//进入/离开区域参数
	NET_VCA_INTRUSION    struIntrusion;		//入侵参数
	NET_VCA_LOITER       struLoiter;		//徘徊参数
	NET_VCA_TAKE_LEFT    struTakeTeft;		//物品遗留/物品拿取参数
	NET_VCA_PARKING      struParking;		//停车参数
	NET_VCA_RUN          struRun;			//快速移动参数
	NET_VCA_HIGH_DENSITY struHighDensity;	//人员聚集参数  
    NET_VCA_VIOLENT_MOTION struViolentMotion;	// 剧烈运动
    NET_VCA_REACH_HIGHT	struReachHight;	// 攀高
    NET_VCA_GET_UP		struGetUp;		//起床
    NET_VCA_LEFT        struLeft;       // 物品遗留
    NET_VCA_TAKE        struTake;       // 物品拿取
    NET_VCA_HUMAN_ENTER struHumanEnter; // 人员进入
	NET_VCA_OVER_TIME   struOvertime;   // 操作超时
    NET_VCA_STICK_UP 	struStickUp;		//贴纸条
    NET_VCA_SCANNER 	struScanner;		//读卡器参数 	
}NET_VCA_EVENT_UNION, *LPNET_VCA_EVENT_UNION;

// 尺寸过滤器类型
typedef enum _VCA_SIZE_FILTER_MODE_
{
	IMAGE_PIX_MODE, //根据像素大小设置
	REAL_WORLD_MODE, //根据实际大小设置
    DEFAULT_MODE 	// 默认模式
}SIZE_FILTER_MODE;
//尺寸过滤器
typedef struct tagNET_VCA_SIZE_FILTER
{
	BYTE    byActive;			//是否激活尺寸过滤器 0-否 非0-是
    BYTE    byMode;		 //过滤器模式SIZE_FILTER_MODE
	BYTE    byRes[2];        //保留，置0
	NET_VCA_RECT struMiniRect;    //最小目标框,全0表示不设置
	NET_VCA_RECT struMaxRect;	  //最大目标框,全0表示不设置
}NET_VCA_SIZE_FILTER, *LPNET_VCA_SIZE_FILTER;

//警戒规则结构
typedef struct tagNET_VCA_ONE_RULE
{
	BYTE   byActive;					//是否激活规则,0-否,非0-是
	BYTE   byRes[7];         			//保留，设置为0字段
    BYTE   byRuleName[NAME_LEN];		//规则名称
	VCA_EVENT_TYPE dwEventType;			//行为分析事件类型
    NET_VCA_EVENT_UNION uEventParam;	//行为分析事件参数
    NET_VCA_SIZE_FILTER  struSizeFilter;  //尺寸过滤器
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//布防时间
	NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //处理方式 
	BYTE byRelRecordChan[MAX_CHANNUM_V30];			//报警触发的录象通道,为1表示触发该通道
}NET_VCA_ONE_RULE, *LPNET_VCA_ONE_RULE;

//行为分析配置结构体
typedef struct tagNET_VCA_RULECFG
{
	DWORD  dwSize;			//结构长度
	BYTE    byPicProType;	//报警时图片处理方式 0-不处理 非0-上传
	BYTE    byRes[3];
	NET_DVR_JPEGPARA struPictureParam; 		//图片规格结构
	NET_VCA_ONE_RULE  struRule[MAX_RULE_NUM];  //规则数组
}NET_VCA_RULECFG, *LPNET_VCA_RULECFG;

//简化目标结构体
typedef struct tagNET_VCA_TARGET_INFO
{
	DWORD    dwID;				//目标ID ,人员聚集过高报警时为0
	NET_VCA_RECT struRect;      //目标边界框 
    BYTE      byRes[4];			//保留
}NET_VCA_TARGET_INFO, *LPNET_VCA_TARGET_INFO;

//简化的规则信息, 包含规则的基本信息
typedef struct tagNET_VCA_RULE_INFO
{
	BYTE   byRuleID;		    //规则ID,0-7
	BYTE   byRes[3];			//保留
    BYTE   byRuleName[NAME_LEN]; //规则名称
	VCA_EVENT_TYPE  dwEventType; //警戒事件类型
    NET_VCA_EVENT_UNION uEventParam;//事件参数
}NET_VCA_RULE_INFO, *LPNET_VCA_RULE_INFO;

//前端设备地址信息，智能分析仪表示的是前端设备的地址信息，其他设备表示本机的地址
typedef struct tagNET_VCA_DEV_INFO
{
	NET_DVR_IPADDR  struDevIP; //前端设备地址， 
	WORD wPort; 			//前端设备端口号， 
	BYTE byChannel;  		//前端设备通道， 
    BYTE byIvmsChannel;		// Ivms 通道 
} NET_VCA_DEV_INFO, *LPNET_VCA_DEV_INFO;

//行为分析结果上报结构
typedef struct  tagNET_VCA_RULE_ALARM
{
	DWORD    dwSize;						//结构长度
	DWORD    dwRelativeTime;				//相对时标
	DWORD    dwAbsTime;						//绝对时标
	NET_VCA_RULE_INFO     struRuleInfo;		//事件规则信息
	NET_VCA_TARGET_INFO  struTargetInfo;	//报警目标信息
	NET_VCA_DEV_INFO  	 struDevInfo;		//前端设备信息
	DWORD dwPicDataLen;						//返回图片的长度 为0表示没有图片，大于0表示该结构后面紧跟图片数据*/
    BYTE       byPicType;		//  0-普通图片 1-对比图片
    BYTE       byRes[3];		// 保留字节
    DWORD      dwRes[3];		/* 保留，设置为0*/
	BYTE  *pImage;   						//指向图片的指针
}NET_VCA_RULE_ALARM, *LPNET_VCA_RULE_ALARM;

//行为分析规则DSP信息叠加结构
typedef struct tagNET_VCA_DRAW_MODE
{ 
	DWORD  dwSize;
	BYTE	byDspAddTarget;			//编码是否叠加目标
	BYTE    byDspAddRule;			//编码是否叠加规则
	BYTE	byDspPicAddTarget;		//抓图是否叠加目标
	BYTE	byDspPicAddRule;		//抓图是否叠加规则
	BYTE	byRes[4];			
}NET_VCA_DRAW_MODE, *LPNET_VCA_DRAW_MODE;

//标定点子结构
typedef struct tagNET_DVR_CB_POINT
{
	NET_VCA_POINT struPoint;     //标定点，主摄像机（枪机）
	NET_DVR_PTZPOS struPtzPos;  //球机输入的PTZ坐标
	BYTE	byRes[8];
}NET_DVR_CB_POINT, LPNET_DVR_CB_POINT;

//标定参数配置结构
typedef struct tagNET_DVR_TRACK_CALIBRATION_PARAM
{	
	BYTE byPointNum;			//有效标定点个数
	BYTE byRes[3];				
	NET_DVR_CB_POINT  struCBPoint[MAX_CALIB_PT]; //标定点组
}NET_DVR_TRACK_CALIBRATION_PARAM, *LPNET_DVR_TRACK_CALIBRATION_PARAM;

//球机配置结构
typedef struct tagNET_DVR_TRACK_CFG 
{	
	DWORD dwSize;				//结构长度	
    BYTE byEnable;				//标定使能
    BYTE byFollowChan;          // 被控制的从通道
    BYTE byDomeCalibrate;			//设置智能跟踪球机标定，1设置 0不设置 
    BYTE byRes;					// 保留字节
	NET_DVR_TRACK_CALIBRATION_PARAM  struCalParam; //标定点组
}NET_DVR_TRACK_CFG, *LPNET_DVR_TRACK_CFG ;

//跟踪模式
typedef enum _TRACK_MODE_
{
	MANUAL_CTRL = 0,  //手动跟踪
	ALARM_TRACK    //报警触发跟踪
}TRACK_MODE;

//手动控制结构
typedef struct tagNET_DVR_MANUAL_CTRL_INFO 
{
	NET_VCA_POINT struCtrlPoint;
	BYTE  byRes[8];
}NET_DVR_MANUAL_CTRL_INFO, *LPNET_DVR_MANUAL_CTRL_INFO ;

//跟踪模式结构
typedef struct tagNET_DVR_TRACK_MODE
{
	DWORD dwSize;		//结构长度
	BYTE byTrackMode;   //跟踪模式
    BYTE byRuleConfMode;   //规则配置跟踪模式0-本地配置跟踪，1-远程配置跟踪
    BYTE byRes[2];   //保留，置0
	union
	{
		DWORD dwULen[4];
		NET_DVR_MANUAL_CTRL_INFO  struManualCtrl;//手动跟踪结构
	}uModeParam;
}NET_DVR_TRACK_MODE,*LPNET_DVR_TRACK_MODE;

typedef struct tagNET_DVR_ALARM_JPEG
{
    BYTE    byPicProType;	    /*报警时图片处理方式 0-不处理 1-上传*/
    BYTE    byRes[3];           //保留字节
    NET_DVR_JPEGPARA struPicParam; 				/*图片规格结构*/
}NET_DVR_ALARM_JPEG, *LPNET_DVR_ALARM_JPEG;

//分析仪行为分析规则结构
//警戒规则结构
typedef struct tagNET_IVMS_ONE_RULE_
{
	BYTE    byActive;           /* 是否激活规则,0-否, 非0-是 */
	BYTE	byRes1[7];	//保留，设置为0字段
	BYTE   byRuleName[NAME_LEN]; //规则名称
	VCA_EVENT_TYPE dwEventType;   //行为分析事件类型
    NET_VCA_EVENT_UNION uEventParam;//行为分析事件参数
    NET_VCA_SIZE_FILTER  struSizeFilter;  //尺寸过滤器
	BYTE byRes2[68]; /*保留，设置为0*/
}NET_IVMS_ONE_RULE, *LPNET_IVMS_ONE_RULE;

// 分析仪规则结构
typedef struct tagNET_IVMS_RULECFG
{
	NET_IVMS_ONE_RULE  struRule[MAX_RULE_NUM];   //规则数组
}NET_IVMS_RULECFG, *LPNET_IVMS_RULECFG;

// IVMS行为分析配置结构
typedef struct tagNET_IVMS_BEHAVIORCFG
{
    DWORD dwSize;
	BYTE    byPicProType;	    //报警时图片处理方式 0-不处理 非0-上传
	BYTE    byRes[3];
	NET_DVR_JPEGPARA struPicParam; 				//图片规格结构
	NET_IVMS_RULECFG struRuleCfg[MAX_DAYS][MAX_TIMESEGMENT];//每个时间段对应规则
} NET_IVMS_BEHAVIORCFG, *LPNET_IVMS_BEHAVIORCFG;

//智能分析仪取流计划子结构
typedef struct tagNET_IVMS_DEVSCHED
{
	NET_DVR_SCHEDTIME 	struTime;       //时间参数
	NET_DVR_PU_STREAM_CFG struPUStream; //前端取流参数
}NET_IVMS_DEVSCHED, *LPNET_IVMS_DEVSCHED;

//智能分析仪参数配置结构
typedef struct tagNET_IVMS_STREAMCFG
{
    DWORD dwSize;
	NET_IVMS_DEVSCHED	struDevSched[MAX_DAYS][MAX_TIMESEGMENT];//按时间段配置前端取流以及规则信息
} NET_IVMS_STREAMCFG, *LPNET_IVMS_STREAMCFG;

//屏蔽区域
typedef struct tagNET_VCA_MASK_REGION
{
    BYTE byEnable;			//是否激活, 0-否，非0-是
	BYTE byRes[3];         //保留，置0
	NET_VCA_POLYGON  struPolygon; //屏蔽多边形
}NET_VCA_MASK_REGION, * LPNET_VCA_MASK_REGION;

//屏蔽区域链表结构
typedef struct tagNET_VCA_MASK_REGION_LIST
{
	DWORD dwSize;     //结构长度
	BYTE byRes[4];     //保留，置0
	NET_VCA_MASK_REGION  struMask[MAX_MASK_REGION_NUM]; //屏蔽区域数组
}NET_VCA_MASK_REGION_LIST, *LPNET_VCA_MASK_REGION_LIST;


//ATM进入区域参数
typedef struct tagNET_VCA_ENTER_REGION//防止干扰ATM检测
{
	DWORD dwSize;
    BYTE byEnable;			//是否激活，0-否，非0-是
	BYTE byRes1[3];
	NET_VCA_POLYGON  struPolygon; //进入区域
	BYTE byRes2[16];
}NET_VCA_ENTER_REGION, * LPNET_VCA_ENTER_REGION;

//IVMS屏蔽区域链表
typedef struct tagNET_IVMS_MASK_REGION_LIST
{
	DWORD dwSize;    //结构长度
	NET_VCA_MASK_REGION_LIST struList[MAX_DAYS][ MAX_TIMESEGMENT];
}NET_IVMS_MASK_REGION_LIST, *LPNET_IVMS_MASK_REGION_LIST;

//IVMS的ATM进入区域参数
typedef struct tagNET_IVMS_ENTER_REGION
{
	DWORD dwSize;
	NET_VCA_ENTER_REGION  struEnter[MAX_DAYS][ MAX_TIMESEGMENT]; //进入区域
}NET_IVMS_ENTER_REGION, *LPNET_IVMS_ENTER_REGION;

// ivms 报警图片上传结构
typedef struct tagNET_IVMS_ALARM_JPEG
{
    BYTE                byPicProType;               
    BYTE                byRes[3];
    NET_DVR_JPEGPARA      struPicParam;     
}NET_IVMS_ALARM_JPEG, *LPNET_IVMS_ALARM_JPEG;

// IVMS 后检索配置
typedef struct tagNET_IVMS_SEARCHCFG
{
    DWORD                        dwSize;
    NET_DVR_MATRIX_DEC_REMOTE_PLAY struRemotePlay;// 远程回放
    NET_IVMS_ALARM_JPEG         struAlarmJpeg; // 报警上传图片配置
    NET_IVMS_RULECFG           struRuleCfg;   //IVMS 行为规则配置
}NET_IVMS_SEARCHCFG, *LPNET_IVMS_SEARCHCFG;
/************************************end******************************************/

//网络硬盘结构配置
typedef struct tagNET_DVR_SINGLE_NET_DISK_INFO
{
	BYTE byNetDiskType;						//网络硬盘类型, 0-NFS,1-iSCSI
	BYTE byRes1[3];							//保留
    NET_DVR_IPADDR struNetDiskAddr;			//网络硬盘地址
    BYTE sDirectory[PATHNAME_LEN];			// PATHNAME_LEN = 128
	WORD wPort;							    //iscsi有端口，现在为默认
	BYTE byRes2[66];							//保留
}NET_DVR_SINGLE_NET_DISK_INFO, *LPNET_DVR_SINGLE_NET_DISK_INFO;

#define MAX_NET_DISK	16//最大网络硬盘个数

typedef struct tagNET_DVR_NET_DISKCFG 
{
    DWORD  dwSize;
    NET_DVR_SINGLE_NET_DISK_INFO struNetDiskParam[MAX_NET_DISK];
}NET_DVR_NET_DISKCFG, *LPNET_DVR_NET_DISKCFG;

//事件类型
//主类型
typedef enum _MAIN_EVENT_TYPE_
{
	EVENT_MOT_DET = 0,		//移动侦测
	EVENT_ALARM_IN = 1,		//报警输入
	EVENT_VCA_BEHAVIOR = 2,	// 行为分析
//     EVENT_VCA_ITS     = 3      // 交通事件     
}MAIN_EVENT_TYPE;

//行为分析主类型对应的次类型， 0xffff表示全部
typedef enum _BEHAVIOR_MINOR_TYPE_
{
	EVENT_TRAVERSE_PLANE     = 0,    // 穿越警戒面
	EVENT_ENTER_AREA,				//目标进入区域,支持区域规则
	EVENT_EXIT_AREA,				//目标离开区域,支持区域规则
	EVENT_INTRUSION,				 // 周界入侵,支持区域规则
	EVENT_LOITER,				 //徘徊,支持区域规则
	EVENT_LEFT_TAKE,				//物品遗留拿取,支持区域规则
	EVENT_PARKING,					//停车,支持区域规则
	EVENT_RUN,					//快速移动,支持区域规则
	EVENT_HIGH_DENSITY,				 //区域内人员聚集,支持区域规则
    EVENT_STICK_UP,				//贴纸条,支持区域规则
    EVENT_INSTALL_SCANNER,				//安装读卡器,支持区域规则
    EVENT_OPERATE_OVER_TIME,        // 操作超时
    EVENT_FACE_DETECT,              // 异常人脸
    EVENT_LEFT,                     // 物品遗留
    EVENT_TAKE                      // 物品拿取
}BEHAVIOR_MINOR_TYPE;

// typedef enum tagITS_MINOR_TYPE
// {
//     ITS_EVENT_CONGESTION    = 0,    // 拥堵
//     ITS_EVENT_PARKING,              // 停车
//     ITS_EVENT_INVERSE,              // 逆行
//     ITS_EVENT_PEDESTRIAN,           // 行人
//     ITS_EVENT_DEBRIS                // 遗留物，抛洒物碎片
// }ITS_MINOR_TYPE;

#define SEARCH_EVENT_INFO_LEN 300	//事件信息长度

//事件搜索条件
typedef struct tagNET_DVR_SEARCH_EVENT_PARAM
{
	WORD wMajorType;			//0-移动侦测，1-报警输入, 2-智能事件
	WORD wMinorType;			//搜索次类型- 根据主类型变化，0xffff表示全部
	NET_DVR_TIME struStartTime;	//搜索的开始时间，停止时间: 同时为(0, 0) 表示从最早的时间开始，到最后，最前面的4000个事件
	NET_DVR_TIME struEndTime;	//
	BYTE byRes[132];			//保留
	union	
	{
		BYTE byLen[SEARCH_EVENT_INFO_LEN];		  
		struct//报警输入
		{
			BYTE byAlarmInNo[MAX_ALARMIN_V30];    //报警输入号，byAlarmInNo[0]若置1则表示查找由报警输入1触发的事件
			BYTE byRes[SEARCH_EVENT_INFO_LEN - MAX_ALARMIN_V30];
		}struAlarmParam;
		struct//移动侦测
		{
			BYTE byMotDetChanNo[MAX_CHANNUM_V30];//移动侦测通道，byMotDetChanNo[0]若置1则表示查找由通道1发生移动侦测触发的事件
			BYTE byRes[SEARCH_EVENT_INFO_LEN - MAX_CHANNUM_V30];
		}struMotionParam;
		struct//行为分析
		{
			BYTE byChanNo[MAX_CHANNUM_V30];	//触发事件的通道
			BYTE byRuleID;					//规则ID，0xff表示全部
			BYTE byRes1[43];				//保留
		}struVcaParam;
//         struct
//         {
//             BYTE    byChanNo[MAX_CHANNUM_V30];
//             BYTE    byAidRuleID;    // 交通事件 规则ID，0xff表示全部 
//             BYTE    byRes[199];
//         }struITSParam;
	}uSeniorParam;
}NET_DVR_SEARCH_EVENT_PARAM, *LPNET_DVR_SEARCH_EVENT_PARAM;

//查找返回结果
typedef struct tagNET_DVR_SEARCH_EVENT_RET
{
	WORD wMajorType;			//主类型
	WORD wMinorType;			//次类型
	NET_DVR_TIME struStartTime;	//事件开始的时间
	NET_DVR_TIME struEndTime;   //事件停止的时间，脉冲事件时和开始时间一样
	BYTE byChan[MAX_CHANNUM_V30];	
	BYTE byRes[36];
	union		
	{
		struct//报警输入结果
		{
			DWORD dwAlarmInNo;     //报警输入号
			BYTE byRes[SEARCH_EVENT_INFO_LEN];
		}struAlarmRet;
		struct//移动侦测结果
		{
			DWORD dwMotDetNo;	//移动侦测通道
			BYTE byRes[SEARCH_EVENT_INFO_LEN];
		}struMotionRet;
		struct//行为分析结果  
		{
			DWORD dwChanNo;					//触发事件的通道号
			BYTE byRuleID;					//规则ID
			BYTE byRes1[3];					//保留
			BYTE byRuleName[NAME_LEN];		//规则名称
			NET_VCA_EVENT_UNION uEvent;     //行为事件参数
		}struVcaRet;
	}uSeniorRet;
}NET_DVR_SEARCH_EVENT_RET, *LPNET_DVR_SEARCH_EVENT_RET;

//SDK_V35  2009-10-26

// 标定配置类型
typedef enum tagCALIBRATE_TYPE
{
    PDC_CALIBRATE  = 0x01,  // PDC 标定
    BEHAVIOR_OUT_CALIBRATE  = 0x02, //行为室外场景标定  
    BEHAVIOR_IN_CALIBRATE = 0x03,    // 行为室内场景标定 
    ITS_CALBIRETE       = 0x04      //  交通事件标定
}CALIBRATE_TYPE;

#define MAX_RECT_NUM  6
typedef struct tagNET_DVR_RECT_LIST
{	
    BYTE    byRectNum;    // 矩形框的个数
    BYTE    byRes1[11];  //保留字节 
    NET_VCA_RECT struVcaRect[MAX_RECT_NUM]; // 最大为6个Rect 
}NET_DVR_RECT_LIST, *LPNET_DVR_RECT_LIST;

// PDC 标定参数
typedef struct tagNET_DVR_PDC_CALIBRATION
{
    NET_DVR_RECT_LIST struRectList;       // 标定矩形框列表
    BYTE           byRes[120];       // 保留字节 
}NET_DVR_PDC_CALIBRATION, *LPNET_DVR_PDC_CALIBRATION;


// 标定线的属性类别，用来表示当前标定线在实际表示的是高度线还是长度线。
typedef enum tagLINE_MODE
{
    HEIGHT_LINE,        //高度样本线
    LENGTH_LINE        //长度样本线
}LINE_MODE;
/*
在设置标定信息的时候，如果相应位设置了使能，并设置相关参数，
若没有设置使能，则标定后可以获取相关的摄像机参数
*/
typedef struct tagNET_DVR_CAMERA_PARAM
{
    BYTE    byEnableHeight;     // 是否使能设置摄像机高度线
    BYTE    byEnableAngle;      // 是否使能设置摄像机俯仰角度
    BYTE    byEnableHorizon;    // 是否使能设置摄像机地平线
    BYTE    byRes[5];   // 保留字节 
    float   fCameraHeight;    // 摄像机高度
    float   fCameraAngle;     // 摄像机俯仰角度
    float   fHorizon;         // 场景中的地平线
}NET_DVR_CAMERA_PARAM, *LPNET_DVR_CAMERA_PARAM;
/*
当fValue表示目标高度的时候，struStartPoint和struEndPoint分别表示目标头部点和脚部点。
当fValue表示线段长度的时候，struStartPoint和struEndPoint分别表示线段起始点和终点，
mode表示当前样本线表示高度线还是长度线。
*/
typedef struct tagNET_DVR_LINE_SEGMENT
{
    BYTE            byLineMode;     // 参照 LINE_MODE
    BYTE            byRes[3];       // 保留字节 
    NET_VCA_POINT   struStartPoint;  
    NET_VCA_POINT   struEndPoint;
    float           fValue;
}NET_DVR_LINE_SEGMENT, *LPNET_DVR_LINE_SEGMENT;

#define  MAX_LINE_SEG_NUM 8

/*
标定样本线目前需要4-8调样本线，以获取摄像机相关参数
*/
typedef struct tagNET_DVR_BEHAVIOR_OUT_CALIBRATION
{
    DWORD                   dwLineSegNum;          // 样本线个数
    NET_DVR_LINE_SEGMENT    struLineSegment[MAX_LINE_SEG_NUM];    // 样本线最大个数
    NET_DVR_CAMERA_PARAM    struCameraParam;    // 摄像机参数
    BYTE byRes[20];
}NET_DVR_BEHAVIOR_OUT_CALIBRATION, *LPNET_DVR_BEHAVIOR_OUT_CALIBRATION;

/*
该结构体表示IAS智能库标定样本，
其中包括一个目标框和一条对应的高度标定线；
目标框为站立的人体外接矩形框；高度线样本标识从人头顶点到脚点的标定线；
用归一化坐标表示；
*/
typedef struct tagNET_DVR_IN_CAL_SAMPLE
{
    NET_VCA_RECT struVcaRect;   // 目标框
    NET_DVR_LINE_SEGMENT struLineSegment;    // 高度标定线
}NET_DVR_IN_CAL_SAMPLE, *LPNET_DVR_IN_CAL_SAMPLE;

#define  MAX_SAMPLE_NUM 5

typedef struct tagNET_DVR_BEHAVIOR_IN_CALIBRATION 
{
    DWORD    dwCalSampleNum;      //  标定样本个数
    NET_DVR_IN_CAL_SAMPLE  struCalSample[MAX_SAMPLE_NUM]; // 标定样本最大个数
    NET_DVR_CAMERA_PARAM    struCameraParam;    // 摄像机参数
    BYTE byRes[16];
}NET_DVR_BEHAVIOR_IN_CALIBRATION, *LPNET_DVR_BEHAVIOR_IN_CALIBRATION;

#define  CALIB_PT_NUM 4
typedef struct tagNET_DVR_ITS_CALIBRATION
{
    unsigned int dwPointNum; //标定点数
    NET_VCA_POINT struPoint[CALIB_PT_NUM]; //图像坐标
    float       fWidth;
    float       fHeight;
    BYTE        byRes1[100];        // 保留字节
}NET_DVR_ITS_CALIBRATION, *LPNET_DVR_ITS_CALIBRATION;

// 标定参数联合体
// 后续的相关标定参数可以放在该结构里面
typedef union tagNET_DVR_CALIBRATION_PRARM_UNION
{
    BYTE byRes[240];                    //联合体结构大小
    NET_DVR_PDC_CALIBRATION struPDCCalibration;  //PDC 标定参数
    NET_DVR_BEHAVIOR_OUT_CALIBRATION  struBehaviorOutCalibration;  //  行为室外场景标定  主要应用于IVS等
    NET_DVR_BEHAVIOR_IN_CALIBRATION  struBehaviorInCalibration;     // 行为室内场景标定，主要应用IAS等 
    NET_DVR_ITS_CALIBRATION struITSCalibration;
}NET_DVR_CALIBRATION_PRARM_UNION, *LPNET_DVR_CALIBRATION_PRARM_UNION;


// 标定配置结构
typedef struct tagNET_DVR_CALIBRATION_CFG
{
    DWORD   dwSize;               //标定结构大小
    BYTE    byEnable;           // 是否启用标定
    BYTE    byCalibrationType;    // 标定类型 根据不同类型在联合体类选择不同的标定 参考CALIBRATE_TYPE
    BYTE    byRes1[2];
    NET_DVR_CALIBRATION_PRARM_UNION uCalibrateParam;  // 标定参数联合体
    BYTE    byRes2[12];
}NET_DVR_CALIBRATION_CFG, *LPNET_DVR_CALIBRATION_CFG; 

//流量统计方向结构体
typedef struct  tagNET_DVR_PDC_ENTER_DIRECTION
{
    NET_VCA_POINT struStartPoint; //流量统计方向起始点
    NET_VCA_POINT struEndPoint;    // 流量统计方向结束点 
}NET_DVR_PDC_ENTER_DIRECTION, *LPNET_DVR_PDC_ENTER_DIRECTION;

typedef struct tagNET_DVR_PDC_RULE_CFG
{
    DWORD           dwSize;              //结构大小
    BYTE            byEnable;             // 是否激活规则;
    BYTE            byRes1[23];       // 保留字节 
    NET_VCA_POLYGON          struPolygon;            // 多边形
    NET_DVR_PDC_ENTER_DIRECTION  struEnterDirection;    // 流量进入方向
} NET_DVR_PDC_RULE_CFG, *LPNET_DVR_PDC_RULE_CFG;

//设置人流量统计参数  复用行为内部关键字参数 
// HUMAN_GENERATE_RATE
// 目标生成速度参数，控制PDC库生成目标的速度。速度越快，目标越容易生成。当输入视频光照条件较差，对比度较低时，或者设置的规则区域较小时，应加快目标生成速度， 避免目标的漏检；当输入视频中对比度较高时，或者规则区域较大时，应该降低目标生成速度，以减少误检。目标生成速度参数共有5级，1级速度最慢，5级最快，默认参数为3。
// 
// DETECT_SENSITIVE
// 目标检测灵敏度控制参数，控制PDC库中一个矩形区域被检测为目标的灵敏度。灵敏度越高，矩形区域越容易被检测为目标，灵敏度越低则越难检测为目标。当输入视频光照条件较差，对比度较低时，应提高检测灵敏度， 避免目标的漏检；当输入视频中对比度较高时，应该降低检测灵敏度，以减少误检。对应参数共有5级，级别1灵敏度最低，5级最高，默认级别为3。
// TRAJECTORY_LEN
// 轨迹生成长度控制参数，表示生成轨迹时要求目标的最大位移像素。对应参数共有5级，级别1，生成长度最长，轨迹生成最慢，5级生成长度最短，轨迹生成最快，默认级别为3。
// TRAJECT_CNT_LEN
// 轨迹计数长度控制参数，表示轨迹计数时要求目标的最大位移像素。对应参数共有5级，级别1，计数要求长度最长，轨迹计数最慢，5级计数要求长度最短，轨迹计数最快，默认级别为3。
// PREPROCESS
// 图像预处理控制参数，0 - 不处理；1 - 处理。默认为0；
// CAMERA_ANGLE
// 摄像机角度输入参数， 0 - 倾斜； 1 - 垂直。默认为0；
typedef enum tagPDC_PARAM_KEY
{
    HUMAN_GENERATE_RATE = 50,              // 目标生成速度 从50开始
    DETECT_SENSITIVE    = 51,               // 检测灵敏度
}PDC_PARAM_KEY;

typedef struct tagNET_DVR_PDC_TARGET_INFO
{
    DWORD       dwTargetID;                 // 目标id 
    NET_VCA_RECT struTargetRect;               // 目标框
    BYTE      byRes1[8];        // 保留字节
}NET_DVR_PDC_TARGET_INFO, *LPNET_DVR_PDC_TARGET_INFO;

typedef struct tagNET_DVR_PDC_TARGET_IN_FRAME
{
    BYTE           byTargetNum;                   //目标个数
    BYTE            byRes1[3];
        NET_DVR_PDC_TARGET_INFO  struTargetInfo[MAX_TARGET_NUM];   //目标信息数组
    BYTE    byRes2[8];                  // 保留字节
}NET_DVR_PDC_TARGET_IN_FRAME, *LPNET_DVR_PDC_TARGET_IN_FRAME;

typedef struct tagNET_DVR_PDC_ALRAM_INFO
{
    DWORD                       dwSize;           // PDC人流量报警上传结构体大小
    BYTE                        byMode;            // 0 单帧统计结果 1最小时间段统计结果  
    BYTE                        byChannel;           // 报警上传通道号
    BYTE                        byRes1[2];         // 保留字节   
    NET_VCA_DEV_INFO  	 struDevInfo;		        //前端设备信息
    union		
    {
        struct   // 单帧统计结果时使用
        {
            DWORD   dwRelativeTime;     // 相对时标
            DWORD   dwAbsTime;          // 绝对时标
            BYTE    byRes[92];            
        }struStatFrame;
        struct
        {
            NET_DVR_TIME                      tmStart; // 统计起始时间 
            NET_DVR_TIME                      tmEnd;  //  统计结束时间 
            BYTE byRes[92];
        }struStatTime;
    }uStatModeParam;  // 作为一个联合体 单帧的时候才有帧内目标信息 最小时间段统计结果需要统计时间 参数
    DWORD                       dwLeaveNum;        // 离开人数
    DWORD                       dwEnterNum;        // 进入人数
    BYTE                        byRes2[40];           // 保留字节
}NET_DVR_PDC_ALRAM_INFO, *LPNET_DVR_PDC_ALRAM_INFO;


//  人流量信息查询 
typedef struct tagNET_DVR_PDC_QUERY
{
    NET_DVR_TIME tmStart;
    NET_DVR_TIME tmEnd;
    DWORD       dwLeaveNum;
    DWORD        dwEnterNum; 
    BYTE        byRes1[256];
}NET_DVR_PDC_QUERY, *LPNET_DVR_PDC_QUERY;

typedef struct    tagNET_DVR_PTZ_POSITION
{
    // 是否启用场景，在设置场景行为规则的时候该字段无效，在设置球机本地配置场景位置信息时作为使能位
    BYTE byEnable;
    BYTE byRes1[3];  //保留
    BYTE byPtzPositionName[NAME_LEN]; //场景位置名称
    NET_DVR_PTZPOS struPtzPos; //ptz 坐标
    BYTE byRes2[40];
}NET_DVR_PTZ_POSITION, *LPNET_DVR_PTZ_POSITION;

typedef struct tagNET_DVR_POSITION_RULE_CFG
{
    DWORD                   dwSize;             // 结构大小 
    NET_DVR_PTZ_POSITION    struPtzPosition;    // 场景位置信息
    NET_VCA_RULECFG         struVcaRuleCfg;     //行为规则配置
    BYTE                    byRes2[80];         // 保留字节
}NET_DVR_POSITION_RULE_CFG, *LPNET_DVR_POSITION_RULE_CFG;

/******************************************
函数:	NET_DVR_GetPositionRule
描述:	获取场景位置规则信息
输入:	lUserID     NET_DVR_Login_V30返回值
        lChannel    通道号
        lPositionIndex 场景索引(目前设备支持10个场景)
        lpPositionRule指向NET_DVR_POSITION_RULE_CFG结构指针
输出:	无
返回值: 成功-TRUE   失败-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetPositionRule(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG lpPositionRule);

/******************************************
函数:	NET_DVR_SetPositionRule
描述:	设置场景位置规则信息TRAFFIC_SCENE_MODE
输入:	lUserID     NET_DVR_Login_V30返回值
        lChannel    通道号
        lPositionIndex 场景索引(目前设备支持10个场景)
        lpPositionRule指向NET_DVR_POSITION_RULE_CFG结构指针
输出:	lpPositionRule指向NET_DVR_POSITION_RULE_CFG结构指针
返回值: 成功-TRUE   失败-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetPositionRule(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_POSITION_RULE_CFG lpPositionRule);

typedef struct tagNET_DVR_LIMIT_ANGLE
{
    BYTE                byEnable;	// 是否启用场景限位功能
    BYTE				byRes1[3];
    NET_DVR_PTZPOS      struUp;     // 上限位
    NET_DVR_PTZPOS      struDown;   // 下限位
    NET_DVR_PTZPOS      struLeft;   // 左限位
    NET_DVR_PTZPOS      struRight;  // 右限位
    BYTE                byRes2[20];
}NET_DVR_LIMIT_ANGLE, *LPNET_DVR_LIMIT_ANGLE;

/******************************************
函数:	NET_DVR_SetPositionLimitAngle
描述:	设置场景规则限位操作
输入:	lUserID     NET_DVR_Login_V30返回值
        lChannel    通道号
        lPositionIndex 场景索引(目前设备支持10个场景)
        lpLimitAngle 指向NET_DVR_LIMIT_ANGLE结构体指针
输出:	无
返回值: 成功-TRUE   失败-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetPositionLimitAngle(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);

/******************************************
函数:	NET_DVR_GetPositionLimitAngle
描述:	获取场景规则限位参数
输入:	lUserID     NET_DVR_Login_V30返回值
        lChannel    通道号
        lPositionIndex 场景索引(目前设备支持10个场景)
        lpLimitAngle 指向NET_DVR_LIMIT_ANGLE结构体指针
输出:	lpLimitAngle 指向NET_DVR_LIMIT_ANGLE结构体指针
返回值: 成功-TRUE   失败-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetPositionLimitAngle(LONG lUserID, LONG lChannel, LONG lPositionIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);

typedef struct tagNET_DVR_POSITION_INDEX
{
    BYTE    byIndex;    // 场景索引
    BYTE    byRes1;
    WORD	wDwell;	// 停留时间 
    BYTE    byRes2[4];   // 保留字节
}NET_DVR_POSITION_INDEX, *LPNET_DVR_POSITION_INDEX;

#define  MAX_POSITION_NUM 10
typedef struct tagNET_DVR_POSITION_TRACK_CFG
{
    DWORD dwSize;
    BYTE    byNum; // 场景个数
    BYTE    byRes1[3];
    NET_DVR_POSITION_INDEX   struPositionIndex[MAX_POSITION_NUM];
    BYTE    byRes2[8];
}NET_DVR_POSITION_TRACK_CFG, *LPNET_DVR_POSITION_TRACK_CFG;

//巡航路径场景信息
typedef struct tagNET_DVR_PATROL_SCENE_INFO
{
    WORD   wDwell;         // 停留时间 30-300
    BYTE   byPositionID;   // 场景号1-10，默认0表示该巡航点不添加场景
    BYTE   byRes[5];
}NET_DVR_PATROL_SCENE_INFO, *LPNET_DVR_PATROL_SCENE_INFO;

// 场景巡航跟踪配置信息
typedef struct tagNET_DVR_PATROL_TRACKCFG
{
    DWORD  dwSize;                                 // 结构大小
    NET_DVR_PATROL_SCENE_INFO struPatrolSceneInfo[10];    // 巡航路径
    BYTE   byRes[16];                              // 保留字节
}NET_DVR_PATROL_TRACKCFG, *LPNET_DVR_PATROL_TRACKCFG;

//球机本地规则菜单配置结构体
typedef struct tagNET_DVR_TRACK_PARAMCFG
{
    DWORD   dwSize;             // 结构大小
    WORD    wAlarmDelayTime;    // 报警延时时间，目前球机只支持全局入侵 范围1-120秒
    WORD    wTrackHoldTime;     // 报警跟踪持续时间  范围0-300秒
    BYTE    byTrackMode;        //  参照 IPDOME_TRACK_MODE
    BYTE	 byPreDirection;	// 跟踪方向预判 0-不启用 1-启用
    BYTE 	 byTrackSmooth;	    // 跟踪连续  0-不启用 1-启用
    BYTE	 byZoomAdjust;	// 倍率系数调整 参见下表
    BYTE	byMaxTrackZoom;	// 最大跟踪倍率系数  0 表示默认倍率系数 与具体机芯参数有关
    BYTE   byRes[11];          //  保留字节                
}NET_DVR_TRACK_PARAMCFG, *LPNET_DVR_TRACK_PARAMCFG;
// 倍率系数值遇倍率关系如下表
// 等级	倍率序数
// 关（0）	标定值
// 1	标定值*0.5
// 2	标定值*0.65
// 3	标定值*0.75
// 4	标定值*0.9
// 5	标定值*1.1
// 6	标定值*1.2
// 7	标定值*1.3

// 球机机芯参数
typedef struct tagNET_DVR_DOME_MOVEMENT_PARAM
{
    WORD wMaxZoom;   // 球机最大倍率系数
    BYTE    byRes[42];  // 保留字节
}NET_DVR_DOME_MOVEMENT_PARAM, *LPNET_DVR_DOME_MOVEMENT_PARAM;

/******************************************
函数:	NET_DVR_GetPtzPosition
描述:   获取球机本地场景PTZ位置信息
输入:	lUserID NET_DVR_Login_v30返回值
        lChannel 通道号
        lPositionID 场景位置ID
        lpPtzPosition 指向NET_DVR_PTZ_POSITION结构指针
输出:	lpPtzPosition 指向NET_DVR_PTZ_POSITION结构指针
返回值: TRUE--成功 FALSE--失败
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);

/******************************************
函数:	NET_DVR_SetPtzPosition
描述:	获取球机本地场景PTZ位置信息
输入:	lUserID NET_DVR_Login_v30返回值
        lChannel 通道号
        lPositionID 场景位置ID
        lpPtzPosition 指向NET_DVR_PTZ_POSITION结构指针
输出:	
返回值: TRUE--成功 FALSE--失败
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);

/******************************************
函数:	NET_DVR_SetPatrolTrack
描述:	设置场景巡航跟踪配置
输入:	lUserID NET_DVR_Login_V30返回值
        lChannel 通道号
        lPatrolIndex 巡航索引
        lpPatrolTrack 指向NET_DVR_PATROL_TRACKCFG结构执政
输出:	
返回值: TRUE--成功 FALSE--失败
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);

/******************************************
函数:	NET_DVR_GetPatrolTrack
描述:	获取场景巡航跟踪配置
输入:	lUserID NET_DVR_Login_V30返回值
        lChannel 通道号
        lPatrolIndex 巡航索引
        lpPatrolTrack 指向NET_DVR_PATROL_TRACKCFG结构执政
输出:   lpPatrolTrack 指向NET_DVR_PATROL_TRACKCFG结构执政
返回值: TRUE--成功 FALSE--失败
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);

/******************************************
函数:	NET_DVR_SetPatrolLimitAngle
描述:	设置场景巡航跟踪限位
输入:	lUserID NET_DVR_Login_V30返回值
        lChannel 通道号
        lPatrolIndex 巡航索引
        lpLimitAngle 指向NET_DVR_LIMIT_ANGLE结构体指针
输出:	无
返回值: TRUE-成功 FALSE-失败
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolLimitAngle(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);

/******************************************
函数:	NET_DVR_GetPatrolLimitAngle
描述:	获取场景巡航跟踪
输入:	lUserID NET_DVR_Login_V30返回值
        lChannel 通道号
        lPatrolIndex 巡航索引
        lpLimitAngle 指向NET_DVR_LIMIT_ANGLE结构体指针
输出:	lpLimitAngle 指向NET_DVR_LIMIT_ANGLE结构体指针
返回值: TRUE-成功 FALSE-失败
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolLimitAngle(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_LIMIT_ANGLE lpLimitAngle);

/********************************智能交通事件 begin****************************************/
#define  MAX_REGION_NUM			8       // 区域列表最大数目
#define  MAX_TPS_RULE			8       // 最大参数规则数目
#define  MAX_AID_RULE			8      // 最大事件规则数目
#define  MAX_LANE_NUM			8		// 最大车道数目

//交通事件类型，
typedef enum tagTRAFFIC_AID_TYPE
{
    CONGESTION          = 0x01,    //拥堵
    PARKING             = 0x02,    //停车  
    INVERSE             = 0x04,    //逆行
    PEDESTRIAN          = 0x08,    //行人                      
    DEBRIS              = 0x10,    //遗留物 抛洒物碎片 
    SMOKE                = 0x20     //烟雾  
}TRAFFIC_AID_TYPE;

typedef enum tagTRAFFIC_SCENE_MODE
{
	FREEWAY = 0,	//  高速户外场景
	TUNNEL,         //  高速隧道场景
	BRIDGE          //  高速桥梁场景
}TRAFFIC_SCENE_MODE;

typedef enum tagITS_ABILITY_TYPE
{
    ITS_CONGESTION_ABILITY = 0x01,      //拥堵
    ITS_PARKING_ABILITY = 0x02,      //停车  
    ITS_INVERSE_ABILITY                = 0x04,      //逆行
    ITS_PEDESTRIAN_ABILITY             = 0x08,      //行人                      
    ITS_DEBRIS_ABILITY                 = 0x10,      //遗留物 抛洒物碎片
    ITS_SMOKE_ABILITY                    = 0x20,      //烟雾-隧道

    ITS_LANE_VOLUME_ABILITY            = 0x010000,  //车道流量
    ITS_LANE_VELOCITY_ABILITY          = 0x020000,  //车道平均速度
    ITS_TIME_HEADWAY_ABILITY           = 0x040000,  //车头时距
    ITS_SPACE_HEADWAY_ABILITY          = 0x080000,  //车头间距
    ITS_TIME_OCCUPANCY_RATIO_ABILITY   = 0x100000,  //车道占有率，（时间上)
    ITS_SPACE_OCCUPANCY_RATIO_ABILITY  = 0x200000,  //车道占有率，百分比计算（空间上)
    ITS_LANE_QUEUE_ABILITY             = 0x400000   //排队长度
}ITS_ABILITY_TYPE;

// 交通统计参数
typedef enum tagITS_TPS_TYPE
{
    LANE_VOLUME           = 0x01,    //车道流量
    LANE_VELOCITY         = 0x02,    //车道速度
    TIME_HEADWAY          = 0x04,    //车头时距
    SPACE_HEADWAY         = 0x08,    //车头间距
    TIME_OCCUPANCY_RATIO  = 0x10,    //车道占有率 (时间上)
    SPACE_OCCUPANCY_RATIO = 0x20,    //车道占有率，百分比计算(空间上)
    QUEUE                 = 0x40     //排队长度
}ITS_TPS_TYPE; 

typedef struct tagNET_DVR_REGION_LIST 
{
	DWORD	dwSize;	// 结构体大小
	BYTE    byNum;      // 区域个数
	BYTE    byRes1[3];    // 保留字节
	NET_VCA_POLYGON struPolygon[MAX_REGION_NUM]; // 区域
	BYTE	byRes2[20];	// 保留字节
}NET_DVR_REGION_LIST,*LPNET_DVR_REGION_LIST;


// 方向结构体
typedef struct tagNET_DVR_DIRECTION
{
    NET_VCA_POINT struStartPoint;   // 方向起始点
    NET_VCA_POINT struEndPoint;     // 方向结束点 
}NET_DVR_DIRECTION, *LPNET_DVR_DIRECTION;

// 单个车道
typedef struct tagNET_DVR_ONE_LANE
{
	BYTE	byEnable; // 车道是否启用
	BYTE	byRes1[11];	// 保留字节
	BYTE    byLaneName[NAME_LEN];       // 车道规则名称
	NET_DVR_DIRECTION struFlowDirection;	// 车道内车流方向
	NET_VCA_POLYGON struPolygon;		// 车道区域
}NET_DVR_ONE_LANE, *LPNET_DVR_ONE_LANE;

// 车道配置
typedef struct tagNET_DVR_LANE_CFG
{
	DWORD	dwSize;	// 结构体大小
	NET_DVR_ONE_LANE struLane[MAX_LANE_NUM];	// 车道参数 数组下标作为车道ID，
	BYTE	byRes1[40];	 // 保留字节
}NET_DVR_LANE_CFG, *LPNET_DVR_LANE_CFG;

// 交通事件参数
typedef struct tagNET_DVR_AID_PARAM
{
	WORD    wParkingDuration;       // 停车持续时间 10-120s
	WORD    wPedestrianDuration;    // 行人持续时间 1-120s
	WORD    wDebrisDuration;        // 抛洒物持续时间 10-120s
	WORD    wCongestionLength;      // 拥堵长度阈值  范围：5-200（米）
	WORD    wCongestionDuration;    // 拥堵持续参数 10-120s
	WORD    wInverseDuration;       // 逆行持续时间 1-10s
	WORD    wInverseDistance;       // 逆行距离阈值 单位m 范围[2-100] 默认 10米
	WORD    wInverseAngleTolerance; // 允许角度偏差 90-180度  车流与逆行允许的夹角
	BYTE    byRes1[28];             //  保留字节
}NET_DVR_AID_PARAM, *LPNET_DVR_AID_PARAM;

// 单条交通事件规则结构体
typedef struct tagNET_DVR_ONE_AID_RULE
{   
    BYTE    byEnable;   // 是否启用事件规则
    BYTE    byRes1[3];  // 保留字节
    BYTE    byRuleName[NAME_LEN];   // 规则名称 
    DWORD   dwEventType;    // 交通事件检测类型 TRAFFIC_AID_TYPE
    NET_VCA_SIZE_FILTER struSizeFilter; // 尺寸过滤器
    NET_VCA_POLYGON     struPolygon;    // 规则区域
    NET_DVR_AID_PARAM struAIDParam; //  事件参数
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//布防时间
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //处理方式 
	BYTE byRelRecordChan[MAX_CHANNUM_V30];			//报警触发的录象通道,为1表示触发该通道
    BYTE    byRes2[20];
}NET_DVR_ONE_AID_RULE, *LPNET_DVR_ONE_AID_RULE;

// 交通事件规则
typedef struct tagNET_DVR_AID_RULECFG
{
    DWORD   dwSize;     // 结构体大小 
    BYTE    byPicProType;	//报警时图片处理方式 0-不处理 非0-上传
    BYTE    byRes1[3];  // 保留字节
    NET_DVR_JPEGPARA struPictureParam; 		//图片规格结构
    NET_DVR_ONE_AID_RULE  struOneAIDRule[MAX_AID_RULE];
    BYTE    byRes2[32];
}NET_DVR_AID_RULECFG, *LPNET_DVR_AID_RULECFG;

// 交通统计参数结构体
typedef struct tagNET_DVR_ONE_TPS_RULE
{
    BYTE    byEnable;       // 是否使能车道交通规则参数
	BYTE	byLaneID;		// 车道ID
    BYTE    byRes1[2];
    DWORD   dwCalcType;     // 统计参数类型ITS_TPS_TYPE
    NET_VCA_SIZE_FILTER struSizeFilter; // 尺寸过滤器 
    NET_VCA_POLYGON struVitrualLoop;    // 虚拟线圈
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//布防时间
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	//处理方式 一般为处理是否上传中心，其他功能不需要
    BYTE    byRes2[20];  // 保留字节
}NET_DVR_ONE_TPS_RULE, *LPNET_DVR_ONE_TPS_RULE;

// 交通参数统计规则配置结构体
typedef struct tagNET_DVR_TPS_RULECFG
{
	DWORD   dwSize;              // 结构大小
	NET_DVR_ONE_TPS_RULE struOneTpsRule[MAX_TPS_RULE]; // 下标对应交通参数ID
	BYTE    byRes2[40];     // 保留字节
}NET_DVR_TPS_RULECFG, *LPNET_DVR_TPS_RULECFG;

// 交通事件信息
typedef struct tagNET_DVR_AID_INFO
{
    BYTE            byRuleID;   // 规则序号，为规则配置结构下标，0-16
    BYTE            byRes1[3];
    BYTE            byRuleName[NAME_LEN]; //  规则名称
    DWORD           dwAIDType;  // 报警事件类型
    NET_DVR_DIRECTION   struDirect; // 报警指向区域   
    BYTE            byRes2[40];  // 保留字节 
}NET_DVR_AID_INFO, *LPNET_DVR_AID_INFO;

// 交通事件报警 
typedef struct tagNET_DVR_AID_ALARM
{
    DWORD               dwSize;         // 结构长度
    DWORD               dwRelativeTime;	// 相对时标
    DWORD               dwAbsTime;		// 绝对时标
    NET_VCA_DEV_INFO  	struDevInfo;	// 前端设备信息
    NET_DVR_AID_INFO    struAIDInfo;    // 交通事件信息
    DWORD               dwPicDataLen;   // 返回图片的长度 为0表示没有图片，大于0表示该结构后面紧跟图片数据
    BYTE                *pImage;        // 指向图片的指针 
    BYTE                byRes[40];      // 保留字节  
}NET_DVR_AID_ALARM, *LPNET_DVR_AID_ALARM;

// 车道队列结构体 
typedef struct tagNET_DVR_LANE_QUEUE
{
    NET_VCA_POINT   struHead;       //队列头
    NET_VCA_POINT   struTail;       //队列尾
    DWORD           dwLength;      //实际队列长度 单位为米 [0-500]
}NET_DVR_LANE_QUEUE, *LPNET_DVR_LANE_QUEUE; 

typedef enum tagTRAFFIC_DATA_VARY_TYPE
{
    NO_VARY,         //无变化 
    VEHICLE_ENTER,   //车辆进入虚拟线圈
    VEHICLE_LEAVE,   //车辆离开虚拟线圈 
    UEUE_VARY       //队列变化             
}TRAFFIC_DATA_VARY_TYPE; 

typedef struct tagNET_DVR_LANE_PARAM
{
    BYTE    byRuleName[NAME_LEN];                 //车道规则名称 
    BYTE    byRuleID;               // 规则序号，为规则配置结构下标，0-7 
    BYTE    byVaryType;             // 车道交通参数变化类型 参照 TRAFFIC_DATA_VARY_TYPE
	BYTE	byLaneType;			// 车道上行或下行
	BYTE	byRes1;
    DWORD    dwLaneVolume;	// 车道流量 ，统计有多少车子通过
    DWORD   dwLaneVelocity;      //车道速度，公里计算
    DWORD   dwTimeHeadway ;      //车头时距，以秒计算
    DWORD   dwSpaceHeadway;      //车头间距，以米来计算
    float   fSpaceOccupyRation; //车道占有率，百分比计算（空间上)
    NET_DVR_LANE_QUEUE  struLaneQueue;         //车道队列长度
    NET_VCA_POINT       struRuleLocation;     //线圈规则的中心点位置
    BYTE    byRes2[32];
}NET_DVR_LANE_PARAM, *LPNET_DVR_LANE_PARAM;


typedef struct tagNET_DVR_TPS_INFO
{
    DWORD   dwLanNum;   // 交通参数的车道数目
    NET_DVR_LANE_PARAM  struLaneParam[MAX_TPS_RULE];
}NET_DVR_TPS_INFO, *LPNET_DVR_TPS_INFO;

typedef struct tagNET_DVR_TPS_ALARM
{
    DWORD dwSize;   // 结构体大小
    DWORD       dwRelativeTime;				// 相对时标
    DWORD       dwAbsTime;						// 绝对时标
    NET_VCA_DEV_INFO  	struDevInfo;		// 前端设备信息
    NET_DVR_TPS_INFO  struTPSInfo;     // 交通事件信息
	BYTE        byRes1[32];         // 保留字节
}NET_DVR_TPS_ALARM, *LPNET_DVR_TPS_ALARM;

// 人脸规则配置 
typedef struct tagNET_DVR_FACEDETECT_RULECFG
{
    DWORD          dwSize;              // 结构体大小
    BYTE           byEnable;            // 是否启用
    BYTE           byres1[3];          // 保留字节    
    BYTE           byRuleName[NAME_LEN];
    NET_VCA_POLYGON     struVcaPolygon;    // 人脸检测规则区域
    BYTE           byPicProType;	//报警时图片处理方式 0-不处理 非0-上传
    BYTE           bySensitivity;   // 规则灵敏度
    WORD            wDuration;      // 触发人脸报警时间阈值
    NET_DVR_JPEGPARA    struPictureParam; 		//图片规格结构
    NET_VCA_SIZE_FILTER struSizeFilter;         //尺寸过滤器
    NET_DVR_SCHEDTIME   struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_2];//布防时间
    NET_DVR_HANDLEEXCEPTION_V30 struHandleType;	  //处理方式 
    BYTE           byRelRecordChan[MAX_CHANNUM_V30];			//报警触发的录象通道,为1表示触发该通道
    BYTE            byRes2[40];         //保留字节
}NET_DVR_FACEDETECT_RULECFG, *LPNET_DVR_FACEDETECT_RULECFG;

typedef struct tagNET_DVR_FACEDETECT_ALARM
{
    DWORD  dwSize;     		// 结构大小
    DWORD 	dwRelativeTime; // 相对时标
    DWORD	dwAbsTime;			// 绝对时标
    BYTE        byRuleName[NAME_LEN];   // 规则名称
    NET_VCA_TARGET_INFO  struTargetInfo;	//报警目标信息
    NET_VCA_DEV_INFO  	 struDevInfo;		//前端设备信息
    DWORD dwPicDataLen;						//返回图片的长度 为0表示没有图片，大于0表示该结构后面紧跟图片数据*/
    BYTE		byAlarmPicType;			// 0-异常人脸报警图片 1- 人脸图片 
    BYTE   byRes[59];              // 保留字节
    BYTE  *pImage;   						//指向图片的指针
}NET_DVR_FACEDETECT_ALARM, *LPNET_DVR_FACEDETECT_ALARM;

typedef struct tagNET_DVR_EVENT_PARAM_UNION
{
    DWORD   uLen[3];        	// 联合体大小为12字节
    DWORD  dwHumanIn;  	//有无人接近 0 - 无人 1- 有人  
    float       fCrowdDensity;  // 人员聚集值
}NET_DVR_EVENT_PARAM_UNION, *LPNET_DVR_EVENT_PARAM_UNION;

// 目前只有有人无人事件和人员聚集事件实时报警上传
typedef struct tagNET_DVR_EVENT_INFO
{
    BYTE   byRuleID;				// Rule ID
    BYTE   byRes[3];				// 保留字节
    BYTE   byRuleName[NAME_LEN];	// 规则名称
    DWORD       dwEventType;    		// 参照VCA_EVENT_TYPE
    NET_DVR_EVENT_PARAM_UNION uEventParam;  // 
}NET_DVR_EVENT_INFO, *LPNET_DVR_EVENT_INFO;

typedef struct tagNET_DVR_EVENT_INFO_LIST
{
    BYTE			byNum;		// 事件实时信息个数
    BYTE			byRes1[3];			// 保留字节
    NET_DVR_EVENT_INFO struEventInfo[MAX_RULE_NUM];	// 事际实时信息
}NET_DVR_EVENT_INFO_LIST,*LPNET_DVR_EVENT_INFO_LIST;

typedef struct tagNET_DVR_RULE_INFO_ALARM
{
    DWORD 			dwSize;				// 结构体大小
    DWORD 		dwRelativeTime; 	// 相对时标
    DWORD		dwAbsTime;			// 绝对时标
    NET_VCA_DEV_INFO  	struDevInfo;		// 前端设备信息
    NET_DVR_EVENT_INFO_LIST struEventInfoList;	//事件信息列表
    BYTE			byRes2[40];			// 保留字节
}NET_DVR_RULE_INFO_ALARM, *LPNET_DVR_RULE_INFO_ALARM;

/******************************************
函数:	NET_DVR_SetSceneMode
描述:	设置场景模式
输入:	lUserID: NET_DVR_Login()的返回值
        lChannel:  通道号
        dwSceneMode: 场景模式
输出:	
返回值: 成功-TRUE 失败-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetSceneMode(LONG  lUserID, LONG lChannel, DWORD dwSceneMode);

/******************************************
函数:	NET_DVR_GetSceneMode
描述:	获取场景模式
输入:	lUserID: NET_DVR_Login()的返回值
        lChannel:  通道号
        pSceneMode 指向场景模式指针
输出:	pSceneMode 指向场景模式指针
返回值: 成功-TRUE 失败-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetSceneMode(LONG lUserID, LONG lChannel, DWORD  *pSceneMode);

/*******************************智能交通事件 end*****************************************/

#define XXX_MAJOR_VERSION      2

/* 子版本号，性能优化、局部结构调整、模块内集成其他库的主版本提升时递增，最大31 */

#define XXX_SUB_VERSION        3

/* 修正版本号，修正bug后递增，最大31 */

#define XXX_REVISION_VERSION   4

typedef struct tagNET_DVR_VCA_VERSION
{
	WORD    wMajorVersion;		// 主版本号
	WORD    wMinorVersion;		// 次版本号
	WORD    wRevisionNumber;	// 修正号
	WORD    wBuildNumber;		// 编译号
	WORD	wVersionYear;		//	版本日期-年
	BYTE	byVersionMonth;		//	版本日期-月
	BYTE	byVersionDay;		//	版本日期-日
	BYTE	byRes[8];			// 保留字节
}NET_DVR_VCA_VERSION, *LPNET_DVR_VCA_VERSION;
NET_DVR_API BOOL __stdcall NET_DVR_GetVCAVersion(LONG lUserID, LONG lChannel, LPNET_DVR_VCA_VERSION lpVersion);

/******************************智能 end***********************************/

/******************************车牌识别 begin******************************************/
typedef struct tagNET_DVR_PLATE_PARAM
{	
    BYTE    byPlateRecoMode;    //车牌识别的模式,默认为1(视频触发模式)
    BYTE    byBelive;;		    //整牌置信度阈值, 只用于视频识别方式, 根据背景复杂程度设置, 误触发率高就设高, 漏车率高就设低, 建议在80-90范围内
    BYTE    byRes[22];          //保留字节
}NET_DVR_PALTE_PARAM, *LPNET_DVR_PALTE_PARAM;

typedef struct tagNET_DVR_PLATECFG
{	
    DWORD		dwSize;
    DWORD    dwEnable;				           /* 是否启用视频车牌识别 0－否 1－是 */
    BYTE    byPicProType;	//报警时图片处理方式 0-不处理 非0-上传
    BYTE    byRes1[3];  // 保留字节
    NET_DVR_JPEGPARA struPictureParam; 		//图片规格结构
    NET_DVR_PALTE_PARAM struPlateParam;   // 车牌识别参数配置
    NET_DVR_HANDLEEXCEPTION struHandleType;	   /* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];//布防时间
	BYTE    byRelRecordChan[MAX_CHANNUM];        //报警触发的录象通道,为1表示触发该通道
    BYTE   byRes[20];   // 保留字节
}NET_DVR_PLATECFG, *LPNET_DVR_PLATECFG;

// 车牌识别结果子结构
typedef struct tagNET_DVR_PLATE_INFO
{
    BYTE  byPlateType;					//车牌类型
    BYTE  byColor;						//车牌颜色
    BYTE  byBright;						//车牌亮度
    BYTE  byLicenseLen;					//车牌字符个数
    BYTE  byEntireBelieve;					//整个车牌的置信度，-100
    BYTE  byRes[35];					//保留
    NET_VCA_RECT	struPlateRect;		//车牌位置
    char sLicense[MAX_LICENSE_LEN];		//车牌号码
    BYTE byBelieve[MAX_LICENSE_LEN];	//各个识别字符的置信度，如检测到车牌"浙A12345", 置信度为,20,30,40,50,60,70，则表示"浙"字正确的可能性只有%，"A"字的正确的可能性是%
}NET_DVR_PLATE_INFO, *LPNET_DVR_PLATE_INFO;

typedef struct tagNET_DVR_PLATERECO_RESULE
{
    DWORD dwSize;
    DWORD    dwRelativeTime;				//相对时标
    DWORD    dwAbsTime;						//绝对时标
    NET_VCA_DEV_INFO struDevInfo;           // 前段设备信息
    NET_DVR_PLATE_INFO struPlateInfo;
    DWORD dwPicDataLen;						//返回图片的长度 为0表示没有图片，大于0表示该结构后面紧跟图片数据*/
    DWORD dwRes[4];							//保留，设置为0
    BYTE  *pImage;   						//指向图片的指针
}NET_DVR_PLATERECO_RESULE, *LPNET_DVR_PLATERECO_RESULE;

/******************************车牌识别 end******************************************/


/*******************************视频综合平台***********************************/
//09-11-21
typedef struct 
{
    NET_DVR_TIME strLogTime;
    DWORD	dwMajorType;	//Main type 1-alarm; 2-abnormal; 3-operation; 0xff-all 
    DWORD	dwMinorType;	//Hypo-Type 0-all;
    BYTE	sPanelUser[MAX_NAMELEN]; //user ID for local panel operation
    BYTE	sNetUser[MAX_NAMELEN];//user ID for network operation
    NET_DVR_IPADDR	struRemoteHostAddr;//remote host IP
    DWORD	dwParaType;//parameter type
    DWORD	dwChannel;//channel number
    DWORD	dwDiskNumber;//HD number
    DWORD	dwAlarmInPort;//alarm input port
    DWORD	dwAlarmOutPort;//alarm output port
    DWORD   dwInfoLen;
    BYTE  byDevSequence;//槽位号
    BYTE  byMacAddr[MACADDR_LEN];//MAC地址,6
    BYTE  sSerialNumber[SERIALNO_LEN];//序列号，48
    char  sInfo[LOG_INFO_LEN - SERIALNO_LEN - MACADDR_LEN - 1 ];
}NET_DVR_LOG_MATRIX, *LPNET_DVR_LOG_MATRIX;

//2009-11-21 视频综合平台
typedef struct tagVEDIOPLATLOG
{
    BYTE bySearchCondition;//搜索条件，0-按槽位号搜索，1-按序列号搜索，2-按MAC地址进行搜索
	//槽位号，0-79：对应子系统的槽位号；
    //0xff：表示搜索所有的日志，包括78K和所有6467；
    //0xfe：表示搜索78K上的日志；0xfd：子域日志；0xfc：域日志。。
    BYTE byDevSequence;
    BYTE  sSerialNumber[SERIALNO_LEN];//序列号，48
    BYTE  byMacAddr[MACADDR_LEN];//MAC地址,6
} NET_DVR_VEDIOPLATLOG, *LPNET_DVR_VEDIOPLATLOG;
//2009-11-21

#define VIDEOPLATFORM_SBUCODESYSTEM_ABILITY          0x211 //视频综合平台编码子系统能力集
typedef struct tagNET_DVR_CODESYSTEMABILITY
{
    DWORD dwSize;
    DWORD dwAbilityVersion;//能力集版本号，高16位表示主版本，低16位表示次版本 
    DWORD dwSupportMaxVideoFrameRate;//单位(K)
	/*按位:
	0:定时录像；
	1:定时|事件触发录像 
	2:移动侦测录像；
	3:网络开关量报警录像；
	4:移动侦测|网络开关量报警录像；
	5:移动侦测&网络开关量报警录像；
	6:周界防范触发录像；
	7:人脸检测触发录像；
	8:车牌识别触发录像；
	9:手动录像*/
    DWORD dwSupportRecordType;
    BYTE  bySupportLinkMode;//按位:第0位:表示主码流，第1位:表示子码流
	BYTE  bySupportStringRow;//支持字符叠加行数
    BYTE  byRes1[2];
	/*0-DCIF，1-CIF，2-QCIF，3-4CIF，4-2CIF，6-QVGA(320*240), 16-VGA，17-UXGA，18-SVGA，19-HD720p，20-XVGA，21-HD900p，22-SXGAp，27-HD1080i，28-2560*1920，29-1600*304，30-2048*1536，31-2448*2048，32-2448*1200，33-2448*800 ，34-XGA（1024x768），35-SXGA（1280x1024）*/
	BYTE  byMainStreamSupportResolution[8];//主码流支持的分辨率，按位
	BYTE  bySubStreamSupportResolution[8];//子码流支持的分辨率，按位
	BYTE  byEventStreamSupportResolution[8];//事件触发码流支持的分辨率，按位
    BYTE  byRes2[100];//保留
}NET_DVR_CODESYSTEMABILITY, *LPNET_DVR_CODESYSTEMABILITY;

/********************************end*******************************************/

/******************************抓拍机*******************************************/
//IO输入配置
typedef struct tagNET_DVR_IO_INCFG
{
    DWORD   dwSize;
    BYTE    byIoInStatus;//输入的IO口状态，0-下降沿，1-上升沿，2-上升沿和下降沿，3-高电平，4-低电平
    BYTE	byRes[3];//保留字节
}NET_DVR_IO_INCFG, *LPNET_DVR_IO_INCFG;

//IO输出配置
typedef struct tagNET_DVR_IO_OUTCFG
{
    DWORD   dwSize;
    BYTE    byDefaultStatus;//IO默认状态：0-低电平，1-高电平 
    BYTE    byIoOutStatus;//IO起效时状态：0-低电平，1-高电平，2-脉冲
    WORD    wAheadTime;//输出IO提前时间，单位us
    DWORD   dwTimePluse;//脉冲间隔时间，单位us
    DWORD   dwTimeDelay;//IO有效持续时间，单位us
	BYTE    byFreqMulti;		//倍频，数值范围[1,15]
	BYTE    byDutyRate;		//占空比，[0,40%]
    BYTE    byRes[2];
}NET_DVR_IO_OUTCFG, *LPNET_DVR_IO_OUTCFG;

//闪光灯配置
typedef struct tagNET_DVR_FLASH_OUTCFG
{
    DWORD  dwSize;
    BYTE   byMode;//闪光灯闪烁模式，0-不闪，1-闪，2-关联闪，3-轮闪
    BYTE   byRelatedIoIn;//闪光灯关联的输入IO号（关联闪时此参数有效）
	BYTE   byRecognizedLane;  /*关联的IO号，按位表示，bit0表示IO1是否关联，0-不关联，1-关联*/
	BYTE   byDetectBrightness;/*自动检测亮度使能闪光灯0-不检测；1-检测*/
	BYTE   byBrightnessThreld;/*使能闪光灯亮度阈值，范围[0,100],高于阈值闪*/
    BYTE   byStartHour;		//开始时间-小时,取值范围0-23
	BYTE   byStartMinute;		//开始时间-分,取值范围0-59
	BYTE   byEndHour;		 	//结束时间-小时,取值范围0-23
	BYTE   byEndMinute;		//结束时间-分,取值范围0-59
	BYTE   byFlashLightEnable;	//设置闪光灯时间使能:0-关;1-开
	BYTE   byRes[2];
}NET_DVR_FLASH_OUTCFG, *LPNET_DVR_FLASH_OUTCFG;

//红绿灯功能（2个IO输入一组）
typedef struct tagNET_DVR_LIGHTSNAPCFG
{
    DWORD   dwSize;
    BYTE	byLightIoIn;//红绿灯的IO 号
    BYTE	byTrigIoIn;//触发的IO号
    BYTE	byRelatedDriveWay;//触发IO关联的车道号
    BYTE	byTrafficLight; //0-高电平红灯，低电平绿灯；1-高电平绿灯，低电平红灯
    BYTE 	bySnapTimes1; //红灯抓拍次数1，0-不抓拍，非0-连拍次数，最大5次 
    BYTE 	bySnapTimes2; //绿灯抓拍次数2，0-不抓拍，非0-连拍次数，最大5次 
    BYTE	byRes1[2];
    WORD	wIntervalTime1[MAX_INTERVAL_NUM];//红灯连拍间隔时间，ms
    WORD	wIntervalTime2[MAX_INTERVAL_NUM];//绿灯连拍间隔时间，ms
    BYTE	byRecord;//闯红灯周期录像标志，0-不录像，1-录像
    BYTE	bySessionTimeout;//闯红灯周期录像超时时间（秒）
    BYTE	byPreRecordTime;//闯红灯录像片段预录时间(秒)
    BYTE	byVideoDelay;//闯红灯录像片段延时时间（秒）
    BYTE	byRes2[32];//保留字节
}NET_DVR_LIGHTSNAPCFG, *LPNET_DVR_LIGHTSNAPCFG;

//测速功能(2个IO输入一组）
typedef struct tagNET_DVR_MEASURESPEEDCFG
{
    DWORD   dwSize;
    BYTE	byTrigIo1;   //测速第1线圈
    BYTE	byTrigIo2;   //测速第2线圈
    BYTE	byRelatedDriveWay;//触发IO关联的车道号
    BYTE	byTestSpeedTimeOut;//测速模式超时时间，单位s
    DWORD   dwDistance;//线圈距离,cm
    BYTE	byCapSpeed;//测速模式起拍速度，单位km/h
    BYTE	bySpeedLimit;//限速值，单位km/h
    BYTE 	bySnapTimes1; //线圈1抓拍次数，0-不抓拍，非0-连拍次数，最大5次 
    BYTE 	bySnapTimes2; //线圈2抓拍次数，0-不抓拍，非0-连拍次数，最大5次 
    WORD	wIntervalTime1[MAX_INTERVAL_NUM];//线圈1连拍间隔时间，ms
    WORD	wIntervalTime2[MAX_INTERVAL_NUM];//线圈2连拍间隔时间，ms
    BYTE	byRes[32];//保留字节
}NET_DVR_MEASURESPEEDCFG, *LPNET_DVR_MEASURESPEEDCFG;

//视频参数配置
typedef struct tagNET_DVR_VIDEOEFFECT
{
    BYTE byBrightnessLevel; /*0-100*/
    BYTE byContrastLevel; /*0-100*/
    BYTE bySharpnessLevel; /*0-100*/
    BYTE bySaturationLevel; /*0-100*/
    BYTE byHueLevel; /*0-100,（保留）*/
    BYTE byRes[3];
}NET_DVR_VIDEOEFFECT, *LPNET_DVR_VIDEOEFFECT;

//增益配置
typedef struct tagNET_DVR_GAIN
{
    BYTE byGainLevel; /*增益：0-100*/
    BYTE byGainUserSet; /*用户自定义增益；0-100，对于抓拍机，是CCD模式下的抓拍增益*/
    BYTE byRes[2];
    DWORD dwMaxGainValue;/*最大增益值，单位dB*/
}NET_DVR_GAIN, *LPNET_DVR_GAIN;

//白平衡配置
typedef struct tagNET_DVR_WHITEBALANCE
{
    BYTE byWhiteBalanceMode; /*0手动白平衡; 1自动白平衡1（范围小）; 2 自动白平衡2（范围宽，2200K-15000K）;3自动控制3*/
    BYTE byWhiteBalanceModeRGain; /*手动白平衡时有效，手动白平衡 R增益*/
    BYTE byWhiteBalanceModeBGain; /*手动白平衡时有效，手动白平衡 B增益*/
    BYTE byRes[5];
}NET_DVR_WHITEBALANCE, *LPNET_DVR_WHITEBALANCE;

//曝光控制
typedef struct tagNET_DVR_EXPOSURE
{
    BYTE  byExposureMode; /*0 手动曝光 1自动曝光*/
    BYTE  byRes[3];
    DWORD dwVideoExposureSet; /* 自定义视频曝光时间（单位us）*//*注:自动曝光时该值为曝光最慢值*/        
    DWORD dwExposureUserSet; /* 自定义曝光时间,在抓拍机上应用时，CCD模式时是抓拍快门速度*/   
    DWORD dwRes;    
} NET_DVR_EXPOSURE, *LPNET_DVR_EXPOSURE;

//宽动态配置
typedef struct tagNET_DVR_WDR
{
    BYTE byWDREnabled; /*宽动态：0 dsibale  1 enable 2 auto*/
    BYTE byWDRLevel1; /*0-F*/
    BYTE byWDRLevel2; /*0-F*/
    BYTE byWDRContrastLevel; /*0-100*/
    BYTE byRes[16];
} NET_DVR_WDR, *LPNET_DVR_WDR;

//日夜转换功能配置
typedef struct tagNET_DVR_DAYNIGHT
{
    BYTE byDayNightFilterType; /*日夜切换：0 day,1 night,2 auto */
    BYTE bySwitchScheduleEnabled; /*0 dsibale  1 enable,(保留)*/
    //模式1(保留)
    BYTE byBeginTime; /*0-100*/
    BYTE byEndTime; /*0-100*/
    //模式2
    BYTE byDayToNightFilterLevel; //0-7
    BYTE byNightToDayFilterLevel; //0-7
    BYTE byDayNightFilterTime;//(60秒)
    BYTE byRes[5];
} NET_DVR_DAYNIGHT, *LPNET_DVR_DAYNIGHT;

//Gamma校正
typedef struct tagNET_DVR_GAMMACORRECT
{
    BYTE byGammaCorrectionEnabled; /*0 dsibale  1 enable*/
    BYTE byGammaCorrectionLevel; /*0-100*/
    BYTE byRes[6];
} NET_DVR_GAMMACORRECT, *LPNET_DVR_GAMMACORRECT;

//背光补偿配置
typedef struct tagNET_DVR_BACKLIGHT
{
    BYTE byBacklightMode; /*背光补偿:0 off 1 UP、2 DOWN、3 LEFT、4 RIGHT、5MIDDLE、6自定义*/
    BYTE byBacklightLevel; /*0x0-0xF*/
    BYTE byRes1[2];
    DWORD dwPositionX1; //（X坐标1）
    DWORD dwPositionY1; //（Y坐标1）
    DWORD dwPositionX2; //（X坐标2）
    DWORD dwPositionY2; //（Y坐标2）
    BYTE byRes2[4];
} NET_DVR_BACKLIGHT, *LPNET_DVR_BACKLIGHT;

//数字降噪功能
typedef struct tagNET_DVR_NOISEREMOVE
{
    BYTE byDigitalNoiseRemoveEnable; /*0-不启用，1-普通模式数字降噪，2-专家模式数字降噪*/
    BYTE byDigitalNoiseRemoveLevel; /*普通模式数字降噪级别：0x0-0xF*/
	BYTE bySpectralLevel;       /*专家模式下空域强度：0-100*/
    BYTE byTemporalLevel;   /*专家模式下时域强度：0-100*/
    BYTE byRes[4];
} NET_DVR_NOISEREMOVE, *LPNET_DVR_NOISEREMOVE;

//CMOS模式下前端镜头配置
typedef struct tagNET_DVR_CMOSMODCFG
{
	BYTE byCaptureMod;   //抓拍模式：0-抓拍模式1；1-抓拍模式2
	BYTE byBrightnessGate;//亮度阈值
	BYTE byCaptureGain1;   //抓拍增益1,0-100
	BYTE byCaptureGain2;   //抓拍增益2,0-100
	DWORD dwCaptureShutterSpeed1;//抓拍快门速度1
	DWORD dwCaptureShutterSpeed2;//抓拍快门速度2
	BYTE  byRes[4];
}NET_DVR_CMOSMODECFG, *LPNET_DVR_CMOSMODECFG;

//IPC CCD参数配置
typedef struct tagNET_DVR_CAMERAPARAMCFG
{
    DWORD dwSize;
    NET_DVR_VIDEOEFFECT struVideoEffect;/*亮度、对比度、饱和度、锐度、色调配置*/    
    NET_DVR_GAIN struGain;/*自动增益*/
    NET_DVR_WHITEBALANCE struWhiteBalance;/*白平衡*/
    NET_DVR_EXPOSURE struExposure; /*曝光控制*/
    NET_DVR_GAMMACORRECT struGammaCorrect;/*Gamma校正*/
    NET_DVR_WDR struWdr;/*宽动态*/
    NET_DVR_DAYNIGHT struDayNight;/*日夜转换*/
    NET_DVR_BACKLIGHT struBackLight;/*背光补偿*/
    NET_DVR_NOISEREMOVE struNoiseRemove;/*数字降噪*/
    BYTE byPowerLineFrequencyMode; /*0-50HZ; 1-60HZ*/
    BYTE byIrisMode; /*0 自动光圈 1手动光圈*/    
    BYTE byMirror ;  /* 镜像：0 off，1- leftright，2- updown，3-center */
    BYTE byDigitalZoom;  /*数字缩放:0 dsibale  1 enable*/
    BYTE byDeadPixelDetect;   /*坏点检测,0 dsibale  1 enable*/
	BYTE byBlackPwl;/*黑电平补偿 ,  0-255*/ 
	BYTE byEptzGate;// EPTZ开关变量:0-不启用电子云台，1-启用电子云台
	BYTE byLocalOutputGate;//本地输出开关变量0-本地输出关闭1-本地BNC输出打开 2-HDMI输出关闭  
				     //20-HDMI_720P50输出开
					 //21-HDMI_720P60输出开
					 //22-HDMI_1080I60输出开
					 //23-HDMI_1080I50输出开
					 //24-HDMI_1080P24输出开
					 //25-HDMI_1080P25输出开
					 //26-HDMI_1080P30输出开
					 //27-HDMI_1080P50输出开
			         //28-HDMI_1080P60输出开
	BYTE byCoderOutputMode;//编码器fpga输出模式0直通3像素搬家
	BYTE byLineCoding; //是否开启行编码：0-否，1-是
	BYTE byRes1[3];
	BYTE byDynamicContrastEN;    //动态对比度增强 0-1
	BYTE byDynamicContrast;    //动态对比度 0-100
	BYTE byJPEGQuality;    //JPEG图像质量 0-100
	NET_DVR_CMOSMODECFG struCmosModeCfg;//CMOS模式下前端参数配置，镜头模式从能力集获取
	BYTE byRes2[4];
}NET_DVR_CAMERAPARAMCFG, *LPNET_DVR_CAMERAPARAMCFG;

//车牌颜色
typedef enum _VCA_PLATE_COLOR_
{
	VCA_BLUE_PLATE  = 0,       //蓝色车牌
	VCA_YELLOW_PLATE,          //黄色车牌
	VCA_WHITE_PLATE,          //白色车牌
	VCA_BLACK_PLATE           //黑色车牌
}VCA_PLATE_COLOR;

//车牌类型
typedef enum _VCA_PLATE_TYPE_
{
	VCA_STANDARD92_PLATE = 0,	//标准民用车与军车
	VCA_STANDARD02_PLATE,		//02式民用车牌 
	VCA_WJPOLICE_PLATE,		    //武警车 
	VCA_JINGCHE_PLATE,			//警车
	STANDARD92_BACK_PLATE, 	    //民用车双行尾牌
	VCA_SHIGUAN_PLATE,          //使馆车牌
	VCA_NONGYONG_PLATE,         //农用车
	VCA_MOTO_PLATE              //摩托车
}VCA_PLATE_TYPE;

//车辆信息
typedef struct tagNET_DVR_VEHICLE_INFO_
{
    DWORD dwIndex;					//车辆序号
    BYTE  byVehicleType;		//车辆类型
    BYTE  byColorDepth;		//车身颜色深浅
    BYTE  byColor;					//车身颜色
    BYTE  byRes1;				//保留
    WORD  wSpeed;					//单位km/h
    WORD  wLength;					//前一辆车的车身长度
	BYTE  byIllegalType;           //0-正常;1-低速2-超速3-逆行
    BYTE  byRes[35];					//保留
}NET_DVR_VEHICLE_INFO, *LPNET_DVR_VEHICLE_INFO;

//车牌检测结果
typedef struct tagNET_DVR_PLATE_RESULT
{
    DWORD   dwSize;						//结构长度
    BYTE	byResultType;			//0-视频识别结果，-图像识别结果
	BYTE    byChanIndex;			//通道号
    BYTE    byRes1[2];				//保留
    DWORD   dwRelativeTime;		//相对时间点  
    BYTE    byAbsTime[32];		//绝对时间点,yyyymmddhhmmssxxx,e.g.20090810235959999（毫秒）
    DWORD   dwPicLen;					//图片长度
    DWORD	dwPicPlateLen;			//车牌小图片长度
    DWORD   dwVideoLen;					//录像内容长度
    BYTE	byTrafficLight;				//0-非红绿灯抓拍，1-绿灯时抓拍；2-红灯时抓拍
    BYTE    byPicNum;				//连拍的图片序号
    BYTE	byDriveChan;				//触发车道号
    BYTE	byRes2[33];					//保留 
    NET_DVR_PLATE_INFO  struPlateInfo;    //车牌信息结构
    NET_DVR_VEHICLE_INFO struVehicleInfo; //车辆信息
    BYTE	*pBuffer1;   		        // 当上传的是图片，指针指向图片信息，当上传的是视频，指针指向视频信息，如果不想获得图片或视频信息，传NULL
    BYTE    *pBuffer2;                  // 当上传的是图片时，指向车牌图片的指针
}NET_DVR_PLATE_RESULT, *LPNET_DVR_PLATE_RESULT;
//后面紧跟图片数据和录像数据，只传一种，图片数据为场景图片+车牌小图片

//车牌报警NET_DVR_PLATE_RESULT
#define COMM_UPLOAD_PLATE_RESULT		0x2800	//上传车牌信息
//图像叠加信息配置        
typedef struct tagNET_DVR_IMAGEOVERLAYCFG
{
	DWORD		dwSize;
	BYTE		byOverlayInfo;//叠加使能开关，0-不叠加，1-叠加
	BYTE		byOverlayMonitorInfo;//是否叠加监测点信息，0-不叠加，1-叠加
	BYTE		byOverlayTime;//是否叠加时间，0-不叠加，1-叠加
	BYTE		byOverlaySpeed;//是否叠加速度，0-不叠加，1-叠加
	BYTE		byOverlaySpeeding;//是否叠加超速比例，0-不叠加，1-叠加
	BYTE		byOverlayLimitFlag;//是否叠加限速标志，0-不叠加，1-叠加
	BYTE		byOverlayPlate;//是否叠加车牌，0-不叠加，1-叠加
	BYTE		byOverlayColor;//是否叠加车身颜色，0-不叠加，1-叠加
    BYTE		byOverlayLength;//是否叠加车长，0-不叠加，1-叠加
    BYTE		byOverlayType;//是否叠加车型，0-不叠加，1-叠加
    BYTE		byOverlayColorDepth;//是否叠加车身颜色深浅，0-不叠加，1-叠加
    BYTE		byOverlayDriveChan;//是否叠加车道，0-不叠加，1-叠加
    BYTE		byOverlayMilliSec; //叠加毫秒信息 0-不叠加，1-叠加
	BYTE		byOverlayIllegalInfo; //叠加违章信息 0-不叠加，1-叠加
	BYTE        byOverlayRedOnTime;  //叠加红灯已亮时间 0-不叠加，1-叠加
	BYTE		byRes1[5];    //保留
	BYTE		byMonitorInfo1[32];    //监测点信息1
	BYTE		byMonitorInfo2[44]; //检测点信息2
	BYTE		byRes2[52];    //保留
}NET_DVR_IMAGEOVERLAYCFG, *LPNET_DVR_IMAGEOVERLAYCFG;

//单IO触发抓拍功能配置
typedef struct tagNET_DVR_SNAPCFG
{
    DWORD   dwSize;
    BYTE	byRelatedDriveWay;//触发IO关联的车道号
    BYTE 	bySnapTimes; //线圈抓拍次数，0-不抓拍，非0-连拍次数，目前最大5次  
    WORD	wSnapWaitTime;  //抓拍等待时间，单位ms，取值范围[0,60000]
    WORD	wIntervalTime[MAX_INTERVAL_NUM];//连拍间隔时间，ms
    BYTE	byRes2[24];//保留字节
}NET_DVR_SNAPCFG, *LPNET_DVR_SNAPCFG;

typedef struct tagNET_DVR_SNAP_ABILITY
{
    DWORD dwSize;
    BYTE  byIoInNum;//IO输入口数
    BYTE  byIoOutNum;//IO输出口数
    BYTE  bySingleSnapNum;//单IO触发组数
    BYTE  byLightModeArrayNum;//红绿灯模式组数
    BYTE  byMeasureModeArrayNum;//测速模式组数
	BYTE  byPlateEnable; //车牌识别能力
	BYTE  byLensMode;//镜头模式0-CCD,1-CMOS
    BYTE  byRes[29];
} NET_DVR_SNAP_ABILITY, *LPNET_DVR_SNAP_ABILITY;
#define SNAPCAMERA_ABILITY          0x300 //抓拍机能力集

typedef struct tagNET_DVR_TRIGCOORDINATE
{
    WORD wTopLeftX; /*线圈左上角横坐标（2个字节）*/
    WORD wTopLeftY; /*线圈左上角纵坐标（2个字节）*/
    WORD wWdith; /*线圈宽度（2个字节）*/
    WORD wHeight; /*线圈高度（2个字节）*/
} NET_DVR_TRIGCOORDINATE, *LPNET_DVR_TRIGCOORDINATE;

typedef enum _PROVINCE_CITY_IDX_
{
	ANHUI_PROVINCE             = 0,              //安徽
	AOMEN_PROVINCE             = 1,              //澳门
	BEIJING_PROVINCE           = 2,              //北京
	CHONGQING_PROVINCE         = 3,              //重庆
	FUJIAN_PROVINCE            = 4,              //福建
	GANSU_PROVINCE             = 5,              //甘肃
	GUANGDONG_PROVINCE         = 6,              //广东
	GUANGXI_PROVINCE           = 7,              //广西
	GUIZHOU_PROVINCE           = 8,              //贵州
	HAINAN_PROVINCE            = 9,              //海南
	HEBEI_PROVINCE             = 10,             //河北
	HENAN_PROVINCE             = 11,             //河南
	HEILONGJIANG_PROVINCE      = 12,             //黑龙江
	HUBEI_PROVINCE             = 13,             //湖北
	HUNAN_PROVINCE             = 14,             //湖南
	JILIN_PROVINCE             = 15,             //吉林
	JIANGSU_PROVINCE           = 16,             //江苏
	JIANGXI_PROVINCE           = 17,             //江西
	LIAONING_PROVINCE          = 18,             //辽宁
	NEIMENGGU_PROVINCE         = 19,             //内蒙古
	NINGXIA_PROVINCE           = 20,             //宁夏
	QINGHAI_PROVINCE           = 21,             //青海
	SHANDONG_PROVINCE          = 22,             //山东
	SHANXI_JIN_PROVINCE        = 23,             //山西
	SHANXI_SHAN_PROVINCE       = 24,             //陕西
	SHANGHAI_PROVINCE          = 25,             //上海
	SICHUAN_PROVINCE           = 26,             //四川
	TAIWAN_PROVINCE            = 27,             //台湾
	TIANJIN_PROVINCE           = 28,             //天津
	XIZANG_PROVINCE            = 29,             //西藏
	XIANGGANG_PROVINCE         = 30,             //香港
	XINJIANG_PROVINCE          = 31,             //新疆
	YUNNAN_PROVINCE            = 32,             //云南
	ZHEJIANG_PROVINCE          = 33              //浙江
}PROVINCE_CITY_IDX;

typedef struct tagNET_DVR_GEOGLOCATION
{
	int iRes[2]; /*保留*/
	DWORD dwCity; /*城市，详见PROVINCE_CITY_IDX */
}NET_DVR_GEOGLOCATION, *LPNET_DVR_GEOGLOCATION;

//场景模式
typedef enum _SCENE_MODE_
{
	UNKOWN_SCENE_MODE   = 0,            //未知场景模式
	HIGHWAY_SCENE_MODE  = 1,            //高速场景模式
	SUBURBAN_SCENE_MODE = 2,            //郊区场景模式(保留)
	URBAN_SCENE_MODE    = 3,            //市区场景模式
	TUNNEL_SCENE_MODE   = 4             //隧道场景模式(保留)
}SCENE_MODE;

typedef struct tagNET_DVR_VTPARAM
{
    DWORD   dwSize;
	BYTE    byEnable;  /* 是否使能虚拟线圈，0-不使用，1-使用*/
	BYTE    byIsDisplay; /* 是否显示虚拟线圈，0-不显示，1-显示*/
	BYTE    byLoopPos; //晚间触发线圈的偏向：0-向上，1-向下
	BYTE    bySnapGain; /*抓拍增益*/
	DWORD   dwSnapShutter; /*抓拍快门速度*/
    NET_DVR_TRIGCOORDINATE struTrigCoordinate; //保留
    NET_DVR_TRIGCOORDINATE struRes[MAX_VL_NUM];
    BYTE    byTotalLaneNum;/*视频触发的车道数1*/
    BYTE    byPolarLenType; /*偏振镜类型，0：不加偏振镜；1：加施耐德偏振镜。*/
    BYTE	byDayAuxLightMode; /*白天辅助照明模式，0：无辅助照明；1：LED灯照明；2：闪光灯照明*/
    BYTE	byLoopToCalRoadBright; /*用以计算路面亮度的车道(虚拟线圈)*/
    BYTE	byRoadGrayLowTh; /*路面亮度低阈值初始化值1*/
    BYTE	byRoadGrayHighTh; /*路面亮度高阈值初始化值140*/
    WORD	wLoopPosBias; /*晚间触发线圈位移30*/
    DWORD   dwHfrShtterInitValue; /*连续图像曝光时间的初始值2000*/
    DWORD   dwSnapShtterInitValue; /*抓拍图像曝光时间的初始值500*/
    DWORD   dwHfrShtterMaxValue; /*连续图像曝光时间的最大值20000*/
    DWORD   dwSnapShtterMaxValue; /*抓拍图像曝光时间的最大值1500*/
    DWORD   dwHfrShtterNightValue; /*晚间连续图像曝光时间的设置值3000*/
    DWORD   dwSnapShtterNightMinValue; /*晚间抓拍图像曝光时间的最小值3000*/
    DWORD   dwSnapShtterNightMaxValue; /*晚间抓拍图像曝光时间的最大值5000*/
    DWORD   dwInitAfe; /*增益的初始值200*/
    DWORD   dwMaxAfe; /*增益的最大值400*/
	WORD    wResolutionX;/* 设备当前分辨率宽*/
	WORD    wResolutionY;/* 设备当前分辨率高*/
    DWORD   dwGainNightValue; /*晚间增益，默认值70*/
	DWORD   dwSceneMode; /*场景模式， 详见SCENE_MODE */
	DWORD   dwRecordMode; /*录像标志：0-不录像，1-录像*/
	NET_DVR_GEOGLOCATION struGeogLocation; /*地址位置*/
	BYTE    byTrigFlag[MAX_VL_NUM]; /*触发标志，0-车头触发；1-车尾触发；2-车头/车尾都触发*/
	BYTE    byTrigSensitive[MAX_VL_NUM];  /*触发灵敏度，1-100*/
	BYTE    byRes2[62];
}NET_DVR_VTPARAM, *LPNET_DVR_VTPARAM;

typedef struct tagNET_DVR_SNAPENABLECFG
{
	DWORD		dwSize;
	BYTE		byPlateEnable;//是否支持车牌识别，0-不支持，1-支持
	BYTE 		byRes1[2];   //保留
	BYTE        byFrameFlip;   //图像是否翻转 0-不翻转，1-翻转
	WORD        wFlipAngle;    //图像翻转角度 0,90,180,270
	WORD        wLightPhase;   //相位，取值范围[0, 360]
	BYTE        byLightSyncPower;  //是否信号灯电源同步，0-不同步；1-同步
	BYTE 		byFrequency;		//信号频率
	BYTE        byUploadSDEnable;  //是否自动上传SD图片，0-否；1-是
	BYTE 		byRes[61]; //保留
}NET_DVR_SNAPENABLECFG, *LPNET_DVR_SNAPENABLECFG;

/* ftp 上传参数*/
typedef struct 
{
	DWORD	dwSize;
	DWORD	dwEnableFTP;			/*是否启动ftp上传功能*/
	char	sFTPIP[16];				/*ftp 服务器*/
	DWORD	dwFTPPort;				/*ftp端口*/
	BYTE	sUserName[NAME_LEN];	/*用户名*/
	BYTE	sPassword[PASSWD_LEN];	/*密码*/
	DWORD	dwDirLevel;	/*0 = 不使用目录结构，直接保存在根目录,1 = 使用1级目录,2=使用2级目录*/
	WORD 	wTopDirMode;	/* 一级目录，0x1 = 使用设备名,0x2 = 使用设备号,0x3 = 使用设备ip地址，0x4=使用监测点,0x5=使用时间(年月)*/
	WORD 	wSubDirMode;	/* 二级目录，0x1 = 使用通道名,0x2 = 使用通道号，,0x3=使用时间(年月日),0x4=使用车道号*/
	BYTE 	byRes[24];
}NET_DVR_FTPCFG, *LPNET_DVR_FTPCFG;

/*可用来命名图片的相关元素 */
#define PICNAME_ITEM_DEV_NAME 	1		/*设备名*/
#define PICNAME_ITEM_DEV_NO 	2		/*设备号*/
#define PICNAME_ITEM_DEV_IP 	3		/*设备IP*/
#define PICNAME_ITEM_CHAN_NAME 	4		/*通道名*/
#define PICNAME_ITEM_CHAN_NO 	5		/*通道号*/
#define PICNAME_ITEM_TIME 		6		/*时间*/
#define PICNAME_ITEM_CARDNO		7		/*卡号*/
#define PICNAME_ITEM_PLATE_NO       8   /*车牌号码*/
#define PICNAME_ITEM_PLATE_COLOR    9   /*车牌颜色*/
#define PICNAME_ITEM_CAR_CHAN       10  /*车道号*/
#define PICNAME_ITEM_CAR_SPEED      11  /*车辆速度*/
#define PICNAME_ITEM_CARCHAN        12  /*监测点*/
#define PICNAME_MAXITEM 		15

//图片命名
typedef struct 
{
	BYTE 	byItemOrder[PICNAME_MAXITEM];	/*	桉数组定义文件命名的规则 */
	BYTE 	byDelimiter;		/*分隔符，一般为'_'*/
}NET_DVR_PICTURE_NAME, *LPNET_DVR_PICTURE_NAME;

/* 串口抓图设置*/
typedef struct 
{
	BYTE	byStrFlag;	/*串口数据开始符*/
	BYTE 	byEndFlag;	/*结束符*/
	WORD	wCardIdx;	/*卡号相对起始位*/
	DWORD 	dwCardLen;	/*卡号长度*/
	DWORD   dwTriggerPicChans;	/*所触发的通道号，按位，从第1位开始计，即0x2表示第一通道*/
}NET_DVR_SERIAL_CATCHPIC_PARA, *LPNET_DVR_SERIAL_CATCHPIC_PARA;

//DVR抓图参数配置（基线）
typedef struct 
{
	DWORD	dwSize;
	NET_DVR_JPEGPARA struJpegPara[MAX_CHANNUM_V30];	/*每个通道的图像参数*/
	WORD	wBurstMode;							/*抓图方式,按位设置.0x1=报警输入触发，0x2=移动侦测触发 0x4=232触发，0x8=485触发，0x10=网络触发*/
	WORD	wUploadInterval;					/*图片上传间隔(秒)[0,65535]*/
	NET_DVR_PICTURE_NAME 	struPicNameRule;	/* 图片命名规则 */
	BYTE	bySaveToHD;		/*是否保存到硬盘*/
	BYTE	byRes1;
	WORD	wCatchInterval;		/*抓图间隔(毫秒)[0,65535]*/
	BYTE	byRes2[12];
	NET_DVR_SERIAL_CATCHPIC_PARA struRs232Cfg;
	NET_DVR_SERIAL_CATCHPIC_PARA struRs485Cfg;
	DWORD dwTriggerPicTimes[MAX_CHANNUM_V30];	/* 每个通道一次触发拍照次数 */
	DWORD dwAlarmInPicChanTriggered[MAX_ALARMIN_V30]; /*报警触发抓拍通道,按位设置，从第1位开始*/
}NET_DVR_JPEGCFG_V30, *LPNET_DVR_JPEGCFG_V30;

//抓拍触发请求结构(保留)
typedef struct tagNET_DVR_MANUALSNAP
{
    BYTE byRes[24]; //保留
}NET_DVR_MANUALSNAP, *LPNET_DVR_MANUALSNAP;

typedef struct tagNET_DVR_SPRCFG    
{
    DWORD dwSize; 
	BYTE byDefaultCHN[MAX_CHJC_NUM]; /*设备运行省份的汉字简写*/
	BYTE byPlateOSD;    /*0-不叠加车牌彩色图,1-叠加车牌彩色图*/
	BYTE bySendJPEG1;   /*0-不传送JPEG图1,1-传送JPEG图1*/
	BYTE bySendJPEG2;   /*0-不传送JPEG图2,1-传送JPEG图2*/
	WORD wDesignedPlateWidth;   /*车牌设计宽度*/
	BYTE byTotalLaneNum;  /*识别的车道数*/
	BYTE byRes1;      /*保留*/
	WORD wRecognizedLane;  /*识别的车道号，按位表示，bit0表示车道1是否识别，0-不识别，1-识别*/
    NET_VCA_RECT struLaneRect[MAX_LANERECT_NUM];  /*车道识别区域*/
	DWORD dwRecogMode;  /*识别的类型，
	    bit0-背向识别：0-正向车牌识别，1-背向识别(尾牌识别) ； 
		bit1-大车牌识别或小车牌识别：0-小车牌识别，1-大车牌识别 ；
		bit2-车身颜色识别：0-不采用车身颜色识别，在背向识别或小车牌识别时禁止启用，1-车身颜色识别；
		bit3-农用车识别：0-不采用农用车识别，1-农用车识别； 
		bit4-模糊识别：0-不采用模糊识别，1-模糊识别；
		bit5-帧定位或场定位：0-帧定位，1-场定位；
		bit6-帧识别或场识别：0-帧识别，1-场识别； 
		bit7-晚上或白天：0-白天，1-晚上 */
	BYTE byRes2[72];    /*保留*/
}NET_DVR_SPRCFG, *LPNET_DVR_SPRCFG;

#define     NET_DVR_GET_PLCCFG    1094   //获取车牌亮度补偿参数
#define     NET_DVR_SET_PLCCFG    1095  //设置车牌亮度补偿参数

typedef struct tagNET_DVR_PLCCFG
{
	DWORD dwSize;
	BYTE byPlcEnable;	//是否启用车牌亮度补偿（默认启用）：0-关闭，1-启用 
	BYTE byPlateExpectedBright;	//车牌的预期亮度（默认值50）, 范围[0, 100]
	BYTE byRes1[2];	//保留 
	BYTE byTradeoffFlash;     //是否考虑闪光灯的影响: 0 - 否;  1 - 是(默认); 
	//使用闪光灯补光时, 如果考虑减弱闪光灯的亮度增强效应, 则需要设为1;否则为0
	BYTE byCorrectFactor;     //纠正系数, 范围[0, 100], 默认值50 (在tradeoff_flash切换时,恢复默认值）
	WORD wLoopStatsEn;  //是否该线圈的亮度，按位表示，0-不统计，1-统计
	BYTE byRes[20];
}NET_DVR_PLCCFG, *LPNET_DVR_PLCCFG;

#define NET_DVR_GET_DEVICESTATECFG              1096   //获取设备当前状态参数

typedef struct tagNET_DVR_DEVICESTATECFG
{
	DWORD dwSize;
	WORD wPreviewNum; //预览连接个数
	WORD wFortifyLinkNum; //布防连接个数
	NET_DVR_IPADDR struPreviewIP[MAX_LINK];  //预览的用户IP地址
	NET_DVR_IPADDR struFortifyIP[MAX_FORTIFY_NUM]; //布防连接的用户IP地址
	DWORD dwVideoFrameRate;	//帧率：0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20; 14-15; 15-18; 16-22;
	BYTE byResolution;  	//分辨率0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5（保留）,16-VGA（640*480）, 17-UXGA（1600*1200）, 18-SVGA （800*600）,19-HD720p（1280*720）,20-XVGA,  21-HD900p, 27-HD1080i, 28-2560*1920, 29-1600*304, 30-2048*1536, 31-2448*2048
	BYTE bySnapResolution;  	//抓拍分辨率0-DCIF 1-CIF, 2-QCIF, 3-4CIF, 4-2CIF 5（保留）,16-VGA（640*480）, 17-UXGA（1600*1200）, 18-SVGA （800*600）,19-HD720p（1280*720）,20-XVGA,  21-HD900p, 27-HD1080i, 28-2560*1920, 29-1600*304, 30-2048*1536, 31-2448*2048
	BYTE byStreamType; //传输类型：0-主码流；1-子码流
	BYTE byTriggerType; //触发模式：0-视频触发；1-普通触发
	DWORD dwSDVolume;  //SD卡容量
	DWORD dwSDFreeSpace; //SD卡剩余空间
	BYTE byDetectorState[MAX_DRIVECHAN_NUM][MAX_COIL_NUM];  //车检器状态：0-未使用；1-正常；2-异常
	BYTE byDetectorLinkState; //车检器连接状态：0-未连接；1-连接
	BYTE byRes2[127]; //保留
}NET_DVR_DEVICESTATECFG, *LPNET_DVR_DEVICESTATECFG;

typedef struct tagNET_DVR_POSTEPOLICECFG
{
	DWORD dwSize;
	DWORD dwDistance;//线圈距离,单位cm，取值范围[0,20000]
	DWORD	dwLightChan[MAX_SIGNALLIGHT_NUM];	//信号灯通道号
	BYTE	byCapSpeed;//标志限速，单位km/h，取值范围[0,255]
	BYTE	bySpeedLimit;//限速值，单位km/h，取值范围[0,255]
	BYTE	byTrafficDirection;//车流方向，0-由东向西，1-由西向东，2-由南向北，3-由北向南
	BYTE	byRes[129];//保留字节
}NET_DVR_POSTEPOLICECFG, *LPNET_DVR_POSTEPOLICECFG;


NET_DVR_API BOOL __stdcall NET_DVR_ContinuousShoot(LONG lUserID, LPNET_DVR_SNAPCFG lpInter);
/***************************** end *********************************************/

#define IPC_PROTOCOL_NUM      50   //ipc 协议最大个数

//协议类型
typedef struct tagNET_DVR_PROTO_TYPE
{ 
    DWORD dwType;               /*ipc协议值*/    
    BYTE  byDescribe[DESC_LEN]; /*协议描述字段*/    
}NET_DVR_PROTO_TYPE, LPNET_DVR_PROTO_TYPE;

//协议列表
typedef struct tagNET_DVR_IPC_PROTO_LIST
{    
	DWORD   dwSize; 
	DWORD   dwProtoNum;           /*有效的ipc协议数目*/   
    NET_DVR_PROTO_TYPE struProto[IPC_PROTOCOL_NUM];   /*有效的ipc协议*/    
    BYTE    byRes[8];
}NET_DVR_IPC_PROTO_LIST, *LPNET_DVR_IPC_PROTO_LIST;

//智能搜索参数
typedef struct tagNET_DVR_SMART_SEARCH_PARAM
{
	BYTE	  byChan;					//通道号
    BYTE      byRes1[3];
	NET_DVR_TIME struStartTime;		//录像开始的时间
	NET_DVR_TIME struEndTime;		//录像停止的时间
    BYTE byMotionScope[64][96];		//侦测区域,0-96位,表示64行,共有96*64个小宏块,为1表示是移动侦测区域,0-表示不是
    BYTE  bySensitivity;   			//搜索灵敏度,1	>80%  2 40%~80%  3 1%~40%
	
    BYTE byRes2[11];
}NET_DVR_SMART_SEARCH_PARAM, *LPNET_DVR_SMART_SEARCH_PARAM;

typedef struct tagNET_DVR_SMART_SEARCH_RET
{
	NET_DVR_TIME struStartTime;	//移动侦测报警开始的时间
	NET_DVR_TIME struEndTime;   //事件停止的时间
	BYTE byRes[64];
}NET_DVR_SMART_SEARCH_RET, *LPNET_DVR_SMART_SEARCH_RET;

// IPSAN 文件目录查找
typedef struct tagNET_DVR_IPSAN_SERACH_PARAM
{
    NET_DVR_IPADDR  struIP;     // IPSAN IP地址
    WORD            wPort;      // IPSAN  端口
    BYTE            byRes[10];  // 保留字节
}NET_DVR_IPSAN_SERACH_PARAM, *LPNET_DVR_IPSAN_SERACH_PARAM;

typedef struct tagNET_DVR_IPSAN_SERACH_RET
{
    BYTE byDirectory[128];  // 返回的文件目录
    BYTE byRes[20];
}NET_DVR_IPSAN_SERACH_RET, *LPNET_DVR_IPSAN_SERACH_RET;

//DVR设备参数
typedef struct
{
	DWORD dwSize;
	BYTE sDVRName[NAME_LEN];     //DVR名称
	DWORD dwDVRID;				//DVR ID,用于遥控器 //V1.4(0-99), V1.5(0-255)
	DWORD dwRecycleRecord;		//是否循环录像,0:不是; 1:是
	//以下不可更改
	BYTE sSerialNumber[SERIALNO_LEN];  //序列号
	DWORD dwSoftwareVersion;			//软件版本号,高16位是主版本,低16位是次版本
	DWORD dwSoftwareBuildDate;			//软件生成日期,0xYYYYMMDD
	DWORD dwDSPSoftwareVersion;		    //DSP软件版本,高16位是主版本,低16位是次版本
	DWORD dwDSPSoftwareBuildDate;		// DSP软件生成日期,0xYYYYMMDD
	DWORD dwPanelVersion;				// 前面板版本,高16位是主版本,低16位是次版本
	DWORD dwHardwareVersion;	// 硬件版本,高16位是主版本,低16位是次版本
	BYTE byAlarmInPortNum;		//DVR报警输入个数
	BYTE byAlarmOutPortNum;		//DVR报警输出个数
	BYTE byRS232Num;			//DVR 232串口个数
	BYTE byRS485Num;			//DVR 485串口个数 --
	BYTE byNetworkPortNum;		//网络口个数
	BYTE byDiskCtrlNum;			//DVR 硬盘控制器个数
	BYTE byDiskNum;				//DVR 硬盘个数
	BYTE byDVRType;				//DVR类型, 1:DVR 2:ATM DVR 3:DVS ......--
	BYTE byChanNum;				//DVR 通道个数
	BYTE byStartChan;			//起始通道号,例如DVS-1,DVR - 1
	BYTE byDecordChans;			//DVR 解码路数
	BYTE byVGANum;				//VGA口的个数 --
	BYTE byUSBNum;				//USB口的个数
    BYTE byAuxoutNum;			//辅口的个数
    BYTE byAudioNum;			//语音口的个数
	BYTE byIPChanNum;			//最大数字通道数  --
	BYTE byZeroChanNum;			//零通道编码个数
    BYTE bySupport;        //能力，位与结果为0表示不支持，1表示支持，
    //bySupport & 0x1, 表示是否支持智能搜索
    //bySupport & 0x2, 表示是否支持备份
    //bySupport & 0x4, 表示是否支持压缩参数能力获取
    //bySupport & 0x8, 表示是否支持多网卡
    //bySupport & 0x10, 表示支持远程SADP
    //bySupport & 0x20  表示支持Raid卡功能
    // bySupport & 0x40 表示支持IPSAN搜索
	BYTE byEsataUseage;		//Esata的默认用途，0-默认备份，1-默认录像
    BYTE byIPCPlug;			//0-不支持即插即用，1-支持即插即用
	BYTE byRes[44];			//保留
}NET_DVR_DEVICECFG_V40, *LPNET_DVR_DEVICECFG_V40;

#define MAX_ZEROCHAN_NUM    16
//零通道压缩配置参数
typedef struct tagNET_DVR_ZEROCHANCFG
{
	DWORD dwSize;			//结构长度
	BYTE  byEnable;			//0-停止零通道编码，1-表示启用零通道编码
	BYTE  byRes1[3];			//保留
	DWORD dwVideoBitrate; 	//视频码率 0-保留 1-16K(保留) 2-32K 3-48k 4-64K 5-80K 6-96K 7-128K 8-160k 9-192K 10-224K 11-256K 12-320K
	// 13-384K 14-448K 15-512K 16-640K 17-768K 18-896K 19-1024K 20-1280K 21-1536K 22-1792K 23-2048K
	//最高位(31位)置成1表示是自定义码流, 0-30位表示码流值(MIN-32K MAX-8192K)。
	DWORD dwVideoFrameRate;	//帧率 0-全部; 1-1/16; 2-1/8; 3-1/4; 4-1/2; 5-1; 6-2; 7-4; 8-6; 9-8; 10-10; 11-12; 12-16; 13-20, //V2.0增加14-15, 15-18, 16-22;
	BYTE  byRes2[32];        //保留
}NET_DVR_ZEROCHANCFG, *LPNET_DVR_ZEROCHANCFG;

//零通道缩放参数
typedef struct tagNET_DVR_ZERO_ZOOMCFG
{
	DWORD dwSize;			    //结构长度
	NET_VCA_POINT  struPoint;	//画面中的坐标点
	BYTE byState;			    //现在的状态，0-缩小，1-放大  
    BYTE byPreviewNumber;       //预览数目,0-1画面,1-4画面,2-9画面,3-16画面 该参数只读
	BYTE byPreviewSeq[MAX_WINDOW_V30];//画面通道信息 该参数只读
    BYTE byRes[30];				//保留 
}NET_DVR_ZERO_ZOOMCFG, *LPNET_DVR_ZERO_ZOOMCFG;

#define DESC_LEN_64 64
typedef struct tagNET_DVR_SNMPCFG
{
    DWORD   dwSize;			//结构长度
    BYTE    byEnable;			//0-禁用SNMP，1-表示启用SNMP
    BYTE    byRes1[3];			//保留
    WORD    wVersion;		//snmp 版本  v1 = 1, v2 =2, v3 =3，设备目前不支持 v3
    WORD    wServerPort; //snmp消息接收端口，默认 161
    BYTE    byReadCommunity[NAME_LEN]; //读共同体，最多31,默认"public"
    BYTE    byWriteCommunity[NAME_LEN];//写共同体,最多31 字节,默认 "private"
    BYTE 	byTrapHostIP [DESC_LEN_64];	//自陷主机ip地址描述，支持IPV4 IPV6和域名描述    
    WORD    wTrapHostPort;   // trap主机端口
    BYTE    byRes2[102];        // 保留
}NET_DVR_SNMPCFG, *LPNET_DVR_SNMPCFG;


#define  PROCESSING          0     //正在处理
#define  PROCESS_SUCCESS     100   //过程完成
#define  PROCESS_EXCEPTION   400   //过程异常
#define  PROCESS_FAILED      500   //过程失败


#define  SOFTWARE_VERSION_LEN 48
typedef struct tagNET_DVR_SADPINFO
{
    NET_DVR_IPADDR  struIP;     // 设备IP地址
    WORD            wPort;      // 设备端口号
    WORD            wFactoryType;   // 设备厂家类型
    char        chSoftwareVersion[SOFTWARE_VERSION_LEN];
    char        chSerialNo[16]; // 序列号
    WORD       wEncCnt;       // 编码通道个数
    BYTE	    byMACAddr[MACADDR_LEN];		// MAC 地址
    NET_DVR_IPADDR  struSubDVRIPMask;   // DVR IP地址掩码
    NET_DVR_IPADDR  struGatewayIpAddr;  // 网关
    NET_DVR_IPADDR	struDnsServer1IpAddr;			/* 域名服务器1的IP地址 */
    NET_DVR_IPADDR	struDnsServer2IpAddr;			/* 域名服务器2的IP地址 */
    BYTE        byDns;
    BYTE        byDhcp;
    BYTE        byRes[158];     // 保留字节
}NET_DVR_SADPINFO, *LPNET_DVR_SADPINFO;

#define  MAX_SADP_NUM   256   // 搜索到设备最大数目
typedef struct tagNET_DVR_SADPINFO_LIST
{
    DWORD               dwSize;   //  结构大小
    WORD                wSadpNum;   // 搜索到设备数目
    BYTE                byRes[6];   // 保留字节
    NET_DVR_SADPINFO    struSadpInfo[MAX_SADP_NUM]; // 搜索
}NET_DVR_SADPINFO_LIST, *LPNET_DVR_SADPINFO_LIST;

typedef struct tagNET_DVR_SADP_VERIFY
{
    char chPassword[PASSWD_LEN];
    NET_DVR_IPADDR struOldIP;
    WORD        wOldPort;
    BYTE        byRes[62];
}NET_DVR_SADP_VERIFY, *LPNET_DVR_SADP_VERIFY;

/*******************************备份接口 begin********************************/
//获取备份设备信息接口定义
#define DESC_LEN_32          32   //描述字长度
#define MAX_NODE_NUM         256  //节点个数

typedef struct tagNET_DVR_DESC_NODE
{ 
    int  iValue;           
    BYTE  byDescribe[DESC_LEN_32]; //描述字段 
    DWORD  dwFreeSpace;           //获取磁盘列表专用,单位为M
    BYTE  byRes[12];			  //保留  
}NET_DVR_DESC_NODE, *LPNET_DVR_DESC_NODE;

typedef struct tagNET_DVR_DISKABILITY_LIST
{ 
    DWORD     dwSize;            //结构长度
    DWORD     dwNodeNum;		 //能力结点个数
    NET_DVR_DESC_NODE  struDescNode[MAX_NODE_NUM];  //描述参数  
}NET_DVR_DISKABILITY_LIST, *LPNET_DVR_DISKABILITY_LIST;

//备份进度列表
#define BACKUP_SUCCESS                100  //备份完成

#define BACKUP_SEARCH_DEVICE          300  //正在搜索备份设备
#define BACKUP_SEARCH_FILE            301  //正在搜索录像文件

#define BACKUP_EXCEPTION			  400  //备份异常
#define BACKUP_FAIL					  500  //备份失败

#define BACKUP_TIME_SEG_NO_FILE       501  //时间段内无录像文件
#define BACKUP_NO_RESOURCE            502  //申请不到资源
#define BACKUP_DEVICE_LOW_SPACE       503  //备份设备容量不足
#define BACKUP_DISK_FINALIZED         504  //刻录光盘封盘
#define BACKUP_DISK_EXCEPTION         505  //刻录光盘异常
#define BACKUP_DEVICE_NOT_EXIST       506  //备份设备不存在
#define BACKUP_OTHER_BACKUP_WORK      507  //有其他备份操作在进行
#define BACKUP_USER_NO_RIGHT          508  //用户没有操作权限
#define BACKUP_OPERATE_FAIL           509  //操作失败

//备份过程接口定义
typedef struct tagNET_DVR_BACKUP_NAME_PARAM
{
    DWORD dwFileNum;   //文件个数
    NET_DVR_FINDDATA_V30 struFileList[MAX_RECORD_FILE_NUM]; //文件列表
    BYTE byDiskDes[DESC_LEN_32];   //备份磁盘描述
    BYTE byWithPlayer;      //是否备份播放器
    BYTE byRes[35];         //保留
}NET_DVR_BACKUP_NAME_PARAM, *LPNET_DVR_BACKUP_NAME_PARAM;

typedef struct tagNET_DVR_BACKUP_TIME_PARAM
{
    LONG            lChannel;        // 按时间备份的通道
    NET_DVR_TIME    struStartTime;   // 备份的起始时间
    NET_DVR_TIME    struStopTime;    // 备份的终止时间
    BYTE byDiskDes[DESC_LEN_32];     //备份磁盘描述
    BYTE byWithPlayer;               //是否备份播放器
    BYTE            byRes[35];       // 保留字节 
}NET_DVR_BACKUP_TIME_PARAM, *LPNET_DVR_BACKUP_TIME_PARAM;
/********************************* end *******************************************/

typedef enum _COMPRESSION_ABILITY_TYPE_
{
    COMPRESSION_STREAM_ABILITY = 0, //码流压缩类型
		MAIN_RESOLUTION_ABILITY = 1,   //主码流压缩分辨率
		SUB_RESOLUTION_ABILITY  = 2,   //子码流压缩分辨率
		EVENT_RESOLUTION_ABILITY =  3,   //事件压缩参数分辨率
		FRAME_ABILITY = 4,        //帧率能力
		BITRATE_TYPE_ABILITY = 5,     //位率类型能力
		BITRATE_ABILITY = 6      //位率上限
}COMPRESSION_ABILITY_TYPE;

//能力列表
typedef struct tagNET_DVR_ABILITY_LIST
{ 
    DWORD     dwAbilityType;		//能力类型 COMPRESSION_ABILITY_TYPE
    BYTE      byRes[32];            //保留字节
    DWORD     dwNodeNum;		//能力结点个数
    NET_DVR_DESC_NODE  struDescNode[MAX_NODE_NUM];  //描述参数  
}NET_DVR_ABILITY_LIST, *LPNET_DVR_ABILITY_LIST;

#define MAX_ABILITYTYPE_NUM  12   //最大能力项
// 压缩参数能力列表
typedef struct tagNET_DVR_COMPRESSIONCFG_ABILITY
{ 
    DWORD     dwSize;            //结构长度
    DWORD     dwAbilityNum;		//能力类型个数
    NET_DVR_ABILITY_LIST struAbilityNode[MAX_ABILITYTYPE_NUM]; //描述参数  
}NET_DVR_COMPRESSIONCFG_ABILITY, *LPNET_DVR_COMPRESSIONCFG_ABILITY;

/********************************9000RH begin****************************************/
#define SUPPORT_PD_NUM			16
#define SUPPORT_ARRAY_NUM		8
#define SUPPORT_VD_NUM			128

typedef enum tagRAID_MODE
{
    RAID0 = 1,
    RAID1,
    RAID10,
    RAID1E,
    RAID5,
    RAID6,
    RAID50,
    JBOD, 
    RAID60
}RAID_MODE;

typedef enum tagHD_SUPPORT_TYPE
{
    HD_TYPE_SATA    = 0x01,
    HD_TYPE_PATA    = 0x02,
    HD_TYPE_SAS     = 0x04,
    HD_TYPE_ATAPI   = 0x08,
    HD_TYPE_TAPE    = 0x10,
    HD_TYPE_SES     = 0x20
}HD_SUPPORT_TYPE;

// 按位表示 位为0表示不支持  1表示支持
typedef enum tagSUPPORT_RAID_TYPE
{
    RAID0_ABILITY   = 0x0001,
    RAID1_ABILITY   = 0x0002,
    RAID10_ABILITY  = 0x0004,
    RAID1E_ABILITY  = 0x0008,
    RAID5_ABILITY   = 0x0010,
    RAID6_ABILITY   = 0x0020,
    RAID50_ABILITY  = 0x0040,
    JBOD_ABILITY    = 0x0080,
    RAID60_ABILITY  = 0x0100
}SUPPORT_RAID_TYPE;

// 物理磁盘 
typedef struct tagNET_DVR_PHY_DISK_INFO
{
    WORD    wPhySlot;         // 硬盘槽位 
    BYTE    byType;         // 硬盘信息；0 普通，1全局热备，2-阵列热备
    BYTE    byStatus;       // 硬盘状态； 1-正常
    BYTE    byMode[40];   // 硬盘类型 字符串
    DWORD   dwHCapacity;    //  磁盘总量高32位 单位kb
    DWORD   dwLCapacity;    //  磁盘总量低32位
    BYTE    byArrrayName[MAX_NAMELEN];
    WORD    wArrayID;          // 所属阵列ID
    BYTE    byRes[102];         // 保留字节  
}NET_DVR_PHY_DISK_INFO, *LPNET_DVR_PHY_DISK_INFO;

typedef struct tagNET_DVR_PHY_DISK_LIST
{
    DWORD   dwSize;
    DWORD   dwCount;
    NET_DVR_PHY_DISK_INFO struPhyDiskInfo[SUPPORT_PD_NUM];
}NET_DVR_PHY_DISK_LIST, *LPNET_DVR_PHY_DISK_LIST;

typedef enum tagBGA_TYPE
{
    BGA_REBUILD = 0x01,            // 重建
    BGA_CONSISTENCY_FIX = 0x02,    // 一致性检查并修复
    BGA_CONSISTENCY_CHECK = 0x04,  // 一致性检查
    BGA_INIT_QUICK = 0x08,         // 初始化(快)
    BGA_INIT_BACK = 0x10,          // 初始化(完全)
    BGA_MIGRATION = 0x20,       // 迁移
    BGA_INIT_FORE = 0x40,           // 初始化
    BGA_COPYBACK = 0x80             // 回迁
}BGA_TYPE;

typedef enum tagBGA_STATE
{
    BGA_STATE_NONE = 0,     //  无后台任务
    BGA_STATE_RUNNING,       //  后台任务正在运行
    BGA_STATE_ABORTED,       //  后台任务取消
    BGA_STATE_PAUSED        //  后台任务暂停
}BGA_STATE;
typedef struct tagNET_DVR_BGA_INFO
{
	BYTE            byBga;  // 后台任务及类型 
	BYTE			 byBgaState;		   /*函数返回值--后台任务状态*/
	WORD    	wBgaPercentage;     /*函数返回值--后台任务执行百分比*/
	BYTE    byRes[4];  // 保留字节
}NET_DVR_BGA_INFO, *LPNET_DVR_BGA_INFO;

// 阵列信息
typedef struct tagNET_DVR_ARRAY_INFO
{
    WORD    wArrayID; // 阵列ID
    BYTE    byRaidMode; // raid模式  参照RAID_MODE
    BYTE    byStatus;  // 0-在线1-磁盘丢失2-不在线
    DWORD   dwHCapacity; // 阵列容量高32位
    DWORD   dwLCapacity; // 阵列容量低32位
    DWORD   dwHFreeSpace;   // 阵列剩余空间高32位
    DWORD   dwLFreeSpace;   // 阵列剩余空间高32位
    BYTE    byArrayName[MAX_NAMELEN]; // 阵列名称
    BYTE    byPDCount;  // 物理磁盘数目
    BYTE    bySpareCount;   // 热备数目
    BYTE    byRes1[2];
    WORD    wPDSlots[SUPPORT_PD_NUM];	// 物理磁盘索引
    WORD    wSparePDSlots[SUPPORT_PD_NUM];	// 热备磁盘索引
    NET_DVR_BGA_INFO	struBgaInfo;	// 后台任务运行状态
    BYTE    byRes2[80]; // 保留字节
}NET_DVR_ARRAY_INFO, *LPNET_DVR_ARRAY_INFO;

typedef struct tagNET_DVR_ARRAY_LIST
{
    DWORD   dwSize;     // 结构体大小
    DWORD   dwCount;    // 阵列个数
    NET_DVR_ARRAY_INFO struArrayInfo[SUPPORT_ARRAY_NUM];
}NET_DVR_ARRAY_LIST, *LPNET_DVR_ARRAY_LIST;

//虚拟磁盘信息
typedef struct tagNET_DVR_VD_INFO
{
    WORD    wSlot;    //虚拟磁盘槽位  
    BYTE    byStatus; // 状态0-正常 1-降级 2-已删除 3-磁盘丢失 4-下线 5-次正常 6-外来
    BYTE    byRaidMode; // Raid 模式 参照 RAID_MODE
    WORD    wArrayID;      // 所属阵列ID
    BYTE    byRepair;   // 是否需要修复 0 不需要 1需要
    BYTE    byRes1[1];  // 保留字节
    BYTE	byArrayName[MAX_NAMELEN];
    BYTE    byName[MAX_NAMELEN];    // 虚拟磁盘名名称
    DWORD   dwHCapacity;    // 虚拟磁盘容量高32位
    DWORD   dwLCapacity;    // 虚拟磁盘容量低32位
    DWORD   dwHFreeSpace;   // 虚拟磁盘剩余空间高32位
    DWORD   dwLFreeSpace;   // 虚拟磁盘剩余空间低32位
    NET_DVR_BGA_INFO	struBgaInfo;	// 后台运行状态
    BYTE    byRes2[80];
}NET_DVR_VD_INFO, *LPNET_DVR_VD_INFO;

typedef struct tagNET_DVR_VD_LIST
{
    DWORD   dwSize;     // 结构体大小
    DWORD   dwCount;    // 虚拟磁盘个数
    NET_DVR_VD_INFO struVDInfo[SUPPORT_VD_NUM];  //虚拟磁盘数组
}NET_DVR_VD_LIST, *LPNET_DVR_VD_LIST;

typedef struct tagNET_DVR_ADAPTER_VERSION
{
    WORD    wMajorVersion;
    WORD    wMinorVersion;
    WORD    wRevisionNumber;
    WORD    wBuildNumber;
}NET_DVR_ADAPTER_VERSION, *LPNET_DVR_ADAPTER_VERSION;

typedef struct tagNET_DVR_VD_SLOT
{
    WORD wVDSlot;
    BYTE  byAlloc;  // 是否已经分配
    BYTE    byRes[5];
    DWORD dwHVDSlotSize;	// 虚拟磁盘空间大小高32位
	DWORD dwLVDSlotSize;	// 虚拟磁盘空间大小低32位
}NET_DVR_VD_SLOT, *LPNET_DVR_VD_SLOT;

typedef struct tagNET_DVR_ARRAY_SPACE_ALLOC_INFO
{
    BYTE    byVDSlotCount;						/*current number of slots in DG*/ 
    BYTE    byRes1[3];              // 保留字节
    NET_DVR_VD_SLOT struVDSlots[SUPPORT_VD_NUM];
}NET_DVR_ARRAY_SPACE_ALLOC_INFO, *LPNET_DVR_ARRAY_SPACE_ALLOC_INFO;

typedef struct tagNET_DVR_RAID_ADAPTER_INFO
{
    DWORD dwSize;    // 结构体大小
    NET_DVR_ADAPTER_VERSION struVersion;	// 适配器版本号
    BYTE    bySlotCount;    //适配器槽位数
    BYTE    bySupportMigrate;  // 迁移(1-支持  0-不支持)
    BYTE    bySupportExpand;   // 扩容  (1-支持  0-不支持)
    BYTE    bySupportRebuild;  // 是否支持重建阵列 (1、支持 0-不支持)
    WORD    wSlotSupportType; //  按位表示 HD_SUPPORT_TYPE
    WORD    wSupportRaidType;      // 支持Raid 类型 按位表示  
    BYTE    byAutoRebuild;      // 0 不自动重建 1自动重建 可设
    BYTE    byRes[27];      // 保留字节
}NET_DVR_RAID_ADAPTER_INFO, *LPNET_DVR_RAID_ADAPTER_INFO;

typedef struct tagNET_DVR_OPERATE_ARRAY_PARAM
{
    //是否一键创建  如果为一键创建，则创建时时候的之需要array名称，而不需要其他参数
    // 其他参数有设备自行创建
    BYTE    byRaidMode;     // 创建/迁移时Raid的类型
    BYTE    byPDCount;  // 物理磁盘数目
    WORD        wArrayID;   // 迁移或者重建时需要指出阵列ID      
    WORD    wPDSlots[SUPPORT_PD_NUM];// 物理磁盘 
    BYTE    byName[MAX_NAMELEN];  // array 名称
    BYTE    byRes2[20];
}NET_DVR_OPERATE_ARRAY_PARAM, *LPNET_DVR_OPERATE_ARRAY_PARAM;


typedef struct tagNET_DVR_OPERATE_VD_PARAM
{
    WORD    wArrayID;		// 阵列ID
    BYTE    bySlot;			// 创建虚拟磁盘指定槽位
    BYTE    byRes1;			// 保留字节
	DWORD	dwHCapacity;	// 虚拟磁盘大小高32位
	DWORD	dwLCapacity;	// 虚拟磁盘大小低32位
    BYTE    byName[MAX_NAMELEN]; // 虚拟磁盘名称
    BYTE    byRes2[16];          // 保留字节 
}NET_DVR_OPERATE_VD_PARAM, *LPNET_DVR_OPERATE_VD_PARAM;


typedef struct tagNET_DVR_SPARE_DISK_PARAM
{
    WORD    wPDSlot;        // 物理磁盘槽位
    WORD    wArrayID;       // 所属的阵列
    BYTE    bySpareType;    // 热备类型 1-全局热备  2 指定阵列  当为指定阵列的时候需要指出所属阵列的ID
    BYTE    byRes[7];       // 保留字节
}NET_DVR_SPARE_DISK_PARAM, *LPNET_DVR_SPARE_DISK_PARAM;

/********************************9000RH End****************************************/


#define MATRIX_MAXDECSUBSYSTEMCHAN	4//视频综合平台解码子系统通道号

//获取解码子系统关联信息
typedef struct tagNET_DVR_DECSUBSYSTEMJIONSTATUS
{
    BYTE	byJoinStatus;//关联状态，0-没有关联，1-已经关联
    BYTE	byJoinSubSystem;//所关联子系统槽位号
    BYTE	byJoinDispNum;//所关联显示通道号
    BYTE	byJoinSubWindowNum;//所关联子窗口号
    BYTE	byRes[4];
}NET_DVR_DECSUBSYSTEMJIONSTATUS,LPNET_DVR_DECSUBSYSTEMJIONSTATUS;

typedef struct tagNET_DVR_SINGLESUBSYSTEMJOININFO
{
    BYTE	bySubSystemType;//子系统类型，0-无，1-解码用子系统，2-编码用子系统，3-级联输出子系统，4-级联输入子系统,5-码分子系统，6-报警子系统
    BYTE	byConnectStatus;//级联系统关联状态，1-连接正常，2-连接断开
    BYTE    byMatrixNum;//级联视频综合平台号，子系统类型是3或4时可用
    BYTE	bySubSystemNum;//级联子系统槽位号，0~79，子系统类型是3或4时可用    
    NET_DVR_DECSUBSYSTEMJIONSTATUS struDecSub [MATRIX_MAXDECSUBSYSTEMCHAN];
    BYTE	byBindStatus;//绑定状态，0-没有绑定，1-已经绑定（大屏拼接时用到）
    BYTE    byRes[7];
}NET_DVR_SINGLESUBSYSTEMJOININFO,LPNET_DVR_SINGLESUBSYSTEMJOININFO;

typedef struct tagNET_DVR_ALLDECSUBSYSTEMJOININFO
{
    DWORD dwSize;
    NET_DVR_SINGLESUBSYSTEMJOININFO struSingleSubSystemJoinInfo [MAX_SUBSYSTEM_NUM];//80
    BYTE  byRes[8];
}NET_DVR_ALLDECSUBSYSTEMJOININFO, *LPNET_DVR_ALLDECSUBSYSTEMJOININFO;

//2010-04-13 增加NAT功能相关配置
typedef struct tagNET_DVR_NATASSOCIATECFG
{
	DWORD		  		dwSize;
    NET_DVR_NETCFG_V30  struNatIpAddress[2];//NAT IP地址 
	BYTE				byNATEnable;//是否启用NAT功能，0-不启用，1-启用
	BYTE		  		byRes[63];
}NET_DVR_NATASSOCIATECFG, *LPNET_DVR_NATASSOCIATECFG;

//2010-06-01 视频综合平台报警配置
typedef struct tagNET_DVR_TEMPERATUREALARMCFG
{
	BYTE	 byEnableTemperatureAlarm;//使能温度超限报警，0-报警，1-不报警
    BYTE	 byRes1[3];
	int 	 iTemperatureUpLimited;	//精确到小数点后两位，如1234表示温度12.34度
	int 	 iTemperatureDownLimited;	
	NET_DVR_HANDLEEXCEPTION_V30 struTempHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
	BYTE	 byRes2[32];
}NET_DVR_TEMPERATUREALARMCFG, *LPNET_DVR_TEMPERATUREALARMCFG;

typedef struct tagNET_DVR_BOARDALARMCFG
{
	BYTE   byEnablePullAlarm;//热插拔报警使能，1-报警，0-不报警
    BYTE   byRes1[3];
	NET_DVR_HANDLEEXCEPTION_V30 struBoardHandleType;	/* 处理方式 */
	NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT_V30]; /*布防时间*/
	BYTE   byRes2[32];
}NET_DVR_BOARDALARMCFG, *LPNET_DVR_BOARDALARMCFG;


typedef struct tagNET_DVR_VIDEOPLATFORMALARMCFG
{
	DWORD 						 dwSize;
	NET_DVR_TEMPERATUREALARMCFG  struTempAlarmCfg;	
	NET_DVR_BOARDALARMCFG 		 struBoardAlarmCfg;	
    NET_DVR_HANDLEEXCEPTION_V30  struHandleException[MAX_EXCEPTIONNUM];//0-风扇异常，1-子系统异常，2-IP地址冲突，3-网线断，4-非法访问，5-光纤异常，6-前面板异常
    BYTE						 byRes[32];
}NET_DVR_VIDEOPLATFORMALARMCFG,*LPNET_DVR_VIDEOPLATFORMALARMCFG;
//2010-05-17
typedef struct  tagNET_DVR_CODESPLITTERASSOCIATE
{
	DWORD		dwSize;
	NET_DVR_IPADDR   struIP;  /*编码器IP地址*/
	WORD		wPort;        //编码器端口号
	BYTE		byRes1[6];
    BYTE		sUserName[NAME_LEN];	/* 用户名（32） */
	BYTE		sPassword[PASSWD_LEN];	/*密码 （16）*/
	BYTE        byChan;//编码器通道号
	BYTE		byRes2[15];
} NET_DVR_CODESPLITTERASSOCIATE, *LPNET_DVR_CODESPLITTERASSOCIATE;

//2010-06-01 视频综合平台报警上传结构
typedef struct tagNET_DVR_MATRIXSUBSYSTEMINFO
{
	BYTE   byMatrixNum;//视频综合平台号
	BYTE	bySubSystemNum;//子系统槽位号
	BYTE   byRes [14];
} NET_DVR_MATRIXSUBSYSTEMINFO, *LPNET_DVR_MATRIXSUBSYSTEMINFO;

typedef struct tagNET_DVR_VIDEOPLATFORM_ALRAMINFO
{
	DWORD  dwSize;      //结构体大小
	BYTE   byAlarmType;	// 0-拔出子板，1-插入子板,2-温度超上限报警，3-温度超下限报警，4-风扇状态异常，5-子系统异常,6-非法访问，7-光纤异常报警,8-前面板异常报警
	BYTE   byRes1[3];
    BYTE   bySubSystemChan[8]; //子板槽位号,一个子板中有8个子系统，其分别对应的槽位号，子系统异常时，bySubSystemChan[0]表示对应子系统序号        
	int    iTemperature;  //温度超限报警时有用，温度值
	BYTE   byMainboardSeq;//温度超限报警时有用，0-非主板，1-主板
    BYTE   byRes2[3];
    BYTE   byFanSequence[32];//风扇异常时风扇号    
	NET_DVR_MATRIXSUBSYSTEMINFO struInputNote;// 光纤异常报警时使用，输入结点
	NET_DVR_MATRIXSUBSYSTEMINFO struOutputNote;//光纤异常报警时使用，输出结点
	BYTE   byRes3[68];	
}NET_DVR_VIDEOPLATFORM_ALRAMINFO,*LPNET_DVR_VIDEOPLATFORM_ALRAMINFO;

typedef struct
{
    char sFileName[100];//图片名
    NET_DVR_TIME struTime;//图片的时间
    DWORD dwFileSize;//图片的大小
    char sCardNum[32];	//卡号
}NET_DVR_FIND_PICTURE,*LPNET_DVR_FIND_PICTURE;

/***************************审讯DVR begin *****************************/
#define MAX_INQUEST_PIP_NUM   3     //单通道显示的画中画数目
#define MAX_INQUEST_CDRW_NUM  4     //最大刻录机数目

typedef struct 
{
	DWORD      dwSize;
    DWORD      dwNum;                       //刻录机的数量
	DWORD      dwRwSelectPara[MAX_CHANNUM_V30];// 是否选中该光驱
	DWORD      dwModeSelect;                //0表示循环刻录模式  1表示并行刻录模式(默认模式)
	BYTE	   byRes[24];                   //保留
	DWORD	   dwStartCDRW;                 //DVR 本地已经开始刻录
	DWORD      dwHdExcp;                    //硬盘有异 常
	DWORD	   dwInterval;                  //时间间隔，10分钟(0)、20分钟(1)、30分钟(2)
	char 	   sLable[64];                  //光盘名称
}NET_DVR_INQUEST_CDRW_CFG, *LPNET_DVR_INQUEST_CDRW_CFG;

typedef struct
{
    char      sFileName[36];			 //文件名
    DWORD     dwFileLen;				 //文件长度
}NET_DVR_INQUEST_FILEINFO, *LPNET_DVR_INQUEST_FILEINFO;

typedef struct 
{
    DWORD     dwFileNum;			         // 需要刻录或者删除的文件数，最多一次20个
	NET_DVR_INQUEST_FILEINFO struFileInfo[MAX_RECORD_FILE_NUM];
	//下面两个参数在表示刻录的文件时使用
	DWORD     dwCDIndex;				    //刻录机的索引：1:选择1号刻录机；2:选择2号刻录机； 3:3号刻录机,4:4号刻录机,5:所有刻录机
	BOOL      bFinalizeDisc;		     	// 0=刻录完之后不封盘；1=刻录完之后封盘
}NET_DVR_INQUEST_FILES, *LPNET_DVR_INQUEST_FILES;

typedef struct {	
	DWORD     dwEnable;			//刻录机状态是否有效,0-无效,1-有效	
	DWORD     dwStatus;			//当dwType=0时，0-光盘正常，1-无光盘或光盘异常	
	//当dwType=1或2时，0-刻录正常，1-无光盘或光盘异常，
	//   2-光盘已封盘，3-光盘空间不足，4-异常导致审讯终止	
	//当dwType=3时，0-刻录正常，1-无光盘或光盘异常，
	//   2-光盘已封盘，3-光盘空间不足	
	BYTE      byRes[16];		//保留字节	
}NET_DVR_INQUEST_CDRW, *LPNET_DVR_INQUEST_CDRW;

typedef struct {	
	DWORD    dwType;                //运行状态：0-审讯开始，1-审讯过程中刻录，2-审讯停止，3-刻录审讯文件	
	NET_DVR_INQUEST_CDRW   strCDRWNum[MAX_INQUEST_CDRW_NUM];   //数组0表示刻录机1	
	BYTE     byRes[24];             //保留	
}NET_DVR_INQUEST_CDRW_STATUS, *LPNET_DVR_INQUEST_CDRW_STATUS;

typedef struct
{
	BYTE     byPipChan;			  //画中画显示的通道 0xFF关闭
	BYTE     byRes[3];			  //保留字节
	WORD     wTopLeftX;			  //画中画的x坐标
	WORD     wTopLeftY;			  //画中画的Y坐标
}NET_DVR_INQUEST_PIP_PARAM, *LPNET_DVR_INQUEST_PIP_PARAM;

typedef struct 
{
	BYTE     byBaseChan;          //显示画中画所在的通道
	BYTE     byBackChan;          //显示画中画背景通道
	BYTE     byPIPMode;           //是否开启, 0:关闭画中画功能 1:打开画中画
	BYTE     byRes;               //保留字节
	NET_DVR_INQUEST_PIP_PARAM  strPipPara[MAX_INQUEST_PIP_NUM];  //画面位置的参数    
}NET_DVR_INQUEST_PIP_STATUS, *LPNET_DVR_INQUEST_PIP_STATUS;

typedef struct 
{
	BYTE	sSecretKey[16];        /*码流加密密钥*/
	BYTE	byRes[64];             /*保留字节*/
}NET_DVR_INQUEST_SECRET_INFO, *LPNET_DVR_INQUEST_SECRET_INFO;

/***************************审讯DVR end *****************************/

//2011-1-13 一体机基线
/***************************一体机************************************/
//曝光和增益控制
typedef struct tagNET_DVR_EXPOSUREGAIN
{
	BYTE byExposureMode; /*模式：0 手动曝光 1自动曝光2光圈优先 3快门优先*/
	BYTE byIrisMode; /* 光圈0-10 ：F1.6/ F1.8/ F2.0/ F2.4/ F2.8/ F3.4/ F4.0/ F4.8/ F5.6/ F8.0/ F11*/
	BYTE byShutterSet; /*快门0-17： 关/自动x2/自动x3/自动x4/自动x8/自动x16/自动x32/ 1/25 / 1/30 / 1/50 1/60 / 1/100 / 1/250 / 1/500 / 1/1k / 1/2k / 1/4k / 1/10k*/
	BYTE bygainLevel; /*增益：0-关,1-低,2-高*/
    BYTE byRes[8];
}NET_DVR_EXPOSUREGAIN, *LPNET_DVR_EXPOSUREGAIN;

//日夜转换功能配置
typedef struct tagNET_DVR_DAYNIGHTZC
{
    BYTE byDayNightFilterType; /*模式：0 day,1 night,2 auto */
    BYTE byDayToNightFilterTime; //白天转黑夜延时0-7：2s/3s/5s/10s/15s/30s/45s/60s
    BYTE byNightToDayFilterTime; //黑夜转白天延时0-7：2s/3s/5s/10s/15s/30s/45s/60s
    BYTE byDayNightFilterLevel;//灵敏度：0-低/1-中/2-高 
    BYTE byRes[4];
}NET_DVR_DAYNIGHTZC, *LPNET_DVR_DAYNIGHTZC;

//聚焦模式
typedef struct tagNET_DVR_FOCUS
{
	BYTE byFocusMode;/*聚焦模式：0 自动1 一次聚焦2 手动*/
	BYTE byFocusModeChoose;/*自动聚焦模式：0 模式一1 模式二*/
	BYTE byMinFocusDistance;/*最小聚焦距离0-4：0.1m/0.5m/1.5m/3m/无穷远*/
	BYTE byZoomSpeed;/*变倍速度0-4：1/2/3/4/5共5级*/
	BYTE byRes[4];
}NET_DVR_FOCUS, *LPNET_DVR_FOCUS;

typedef struct tagNET_DVR_ZOOMCAMCFG
{
    DWORD dwSize;
    NET_DVR_VIDEOEFFECT struVideoEffect;/*亮度、对比度、饱和度、锐度、色调配置*/
    NET_DVR_WHITEBALANCE struWhiteBalance;/*白平衡*/
    NET_DVR_EXPOSUREGAIN struExposureGain; /*曝光和增益控制*/
    NET_DVR_GAMMACORRECT struGammaCorrect;/*Gamma校正*/
	NET_DVR_WDR struWdr;/*宽动态*/
	NET_DVR_DAYNIGHTZC struDayNight;/*日夜转换*/
	NET_DVR_FOCUS struFocus;//聚焦模式
	NET_DVR_BACKLIGHT struBackLight;/*背光补偿*/
	NET_DVR_NOISEREMOVE struNoiseRemove;/*数字降噪*/
	BYTE byLenInit;/*镜头初始化：0 关1 开*/
    BYTE byDigitalZoom;  /*数字放大0-4：关/x2/x4/x8/ x12*/
	BYTE byMirror ;  /* 镜像：0   关;1   水平;2   垂直;3  中心 */
	BYTE byZoomDisplay;/*倍率显示：0 关1 开*/
	BYTE byZoomLimit; /*倍率限制0-17： /1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16/17/18*/
    BYTE byPowerLineFrequencyMode; /*0-50HZ; 1-60HZ*/
    BYTE byDeadPixelDetect;   /*坏点检测,0 dsibale  1 enable*/
	BYTE byBlackPwl;/*黑电平补偿 ,  0-255*/ 
	BYTE byEptzGate;// EPTZ开关变量:0物理云台1电子云台
	BYTE byLocalOutputGate;//本地输出开关变量0-本地输出关闭1-本地BNC输出打开 2-HDMI输出关闭  
	//20-HDMI_720P50输出开
	//21-HDMI_720P60输出开
	//22-HDMI_1080I60输出开
	//23-HDMI_1080I50输出开
	//24-HDMI_1080P24输出开
	//25-HDMI_1080P25输出开
	//26-HDMI_1080P30输出开
	//27-HDMI_1080P50输出开
	//28-HDMI_1080P60输出开
	BYTE byCoderOutputMode;//编码器fpga输出模式0直通3像素搬家
	BYTE byDynamicContrastEN;    //动态对比度增强 0-1
	BYTE byDynamicContrast;    //动态对比度 0-100
	BYTE byJPEGQuality;    //JPEG图像质量 0-100
	BYTE byRes[66];
}NET_DVR_ZOOMCAMCFG, *LPNET_DVR_ZOOMCAMCFG;
/***************************一体机 end************************************/

/********************************接口参数结构(end)*********************************/


/********************************SDK接口函数声明*********************************/
NET_DVR_API BOOL __stdcall NET_DVR_Init();
NET_DVR_API BOOL __stdcall NET_DVR_Cleanup();

//NET_DVR_SetDVRMessage的扩展
#ifdef _WIN32
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessage(UINT nMessage,HWND hWnd);
NET_DVR_API BOOL __stdcall NET_DVR_SetExceptionCallBack_V30(UINT nMessage, HWND hWnd, void (CALLBACK* fExceptionCallBack)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser), void *pUser);
#elif defined(__linux__)
NET_DVR_API BOOL __stdcall NET_DVR_SetExceptionCallBack_V30(UINT reserved1, void* reserved2, void (CALLBACK* fExceptionCallBack)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser), void *pUser);
/*Linux专有 */
//NET_DVR_API BOOL NET_DVR_DrawAreaInit(INITINFO InitInfo, DWORD iUseSDL = 1);
NET_DVR_API BOOL NET_DVR_DrawAreaInit(INITINFO InitInfo, DWORD iUseSDL);

NET_DVR_API BOOL NET_DVR_DrawAreaRelease();
#endif

NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack(BOOL (CALLBACK *fMessCallBack)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack_EX(BOOL (CALLBACK *fMessCallBack_EX)(LONG lCommand,LONG lUserID,char *pBuf,DWORD dwBufLen));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessCallBack_NEW(BOOL (CALLBACK *fMessCallBack_NEW)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen, WORD dwLinkDVRPort));
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessageCallBack(BOOL (CALLBACK *fMessageCallBack)(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen, DWORD dwUser), DWORD dwUser);
typedef void (CALLBACK *MSGCallBack)(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRMessageCallBack_V30(MSGCallBack fMessageCallBack, void* pUser);

NET_DVR_API BOOL __stdcall NET_DVR_SetConnectTime(DWORD dwWaitTime , DWORD dwTryTimes );
NET_DVR_API BOOL __stdcall NET_DVR_SetReconnect(DWORD dwInterval, BOOL bEnableRecon);
NET_DVR_API DWORD __stdcall NET_DVR_GetSDKVersion();
NET_DVR_API DWORD __stdcall NET_DVR_GetSDKBuildVersion();
NET_DVR_API int __stdcall NET_DVR_IsSupport();
NET_DVR_API BOOL __stdcall NET_DVR_StartListen(char *sLocalIP,WORD wLocalPort);
NET_DVR_API BOOL __stdcall NET_DVR_StopListen();

NET_DVR_API LONG __stdcall NET_DVR_StartListen_V30(char *sLocalIP, WORD wLocalPort, MSGCallBack DataCallback, void* pUserData);
NET_DVR_API BOOL __stdcall NET_DVR_StopListen_V30(LONG lListenHandle);
NET_DVR_API LONG __stdcall NET_DVR_Login(char *sDVRIP,WORD wDVRPort,char *sUserName,char *sPassword,LPNET_DVR_DEVICEINFO lpDeviceInfo);
NET_DVR_API LONG __stdcall NET_DVR_Login_V30(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
NET_DVR_API BOOL __stdcall NET_DVR_Logout(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_Logout_V30(LONG lUserID);
NET_DVR_API DWORD __stdcall NET_DVR_GetLastError();
NET_DVR_API char* __stdcall NET_DVR_GetErrorMsg(LONG *pErrorNo);
NET_DVR_API BOOL __stdcall NET_DVR_SetShowMode(DWORD dwShowType,COLORREF colorKey);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRIPByResolveSvr(char *sServerIP, WORD wServerPort, BYTE *sDVRName,WORD wDVRNameLen,BYTE *sDVRSerialNumber,WORD wDVRSerialLen,char* sGetIP);
NET_DVR_API BOOL  __stdcall NET_DVR_GetDVRIPByResolveSvr_EX(char *sServerIP, WORD wServerPort, unsigned char *sDVRName, WORD wDVRNameLen, BYTE *sDVRSerialNumber, WORD wDVRSerialLen, char* sGetIP, DWORD *dwPort);

//预览相关接口
NET_DVR_API LONG __stdcall NET_DVR_PlayDirect(char *sDVRIP, char *sUserName, char *sPassword, \
											  LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser), void* pUser, BOOL bBlocked);
NET_DVR_API LONG __stdcall NET_DVR_RealPlay(LONG lUserID,LPNET_DVR_CLIENTINFO lpClientInfo);
NET_DVR_API LONG __stdcall NET_DVR_RealPlay_V30(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, void(CALLBACK *fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser), void* pUser, BOOL bBlocked);
NET_DVR_API BOOL __stdcall NET_DVR_StopRealPlay(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayDirect(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_RigisterDrawFun(LONG lRealHandle,void (CALLBACK* fDrawFun)(LONG lRealHandle,HDC hDc,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetPlayerBufNumber(LONG lRealHandle,DWORD dwBufNum);
NET_DVR_API BOOL __stdcall NET_DVR_ThrowBFrame(LONG lRealHandle,DWORD dwNum);
NET_DVR_API BOOL __stdcall NET_DVR_SetAudioMode(DWORD dwMode);
NET_DVR_API BOOL __stdcall NET_DVR_OpenSound(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSound();
NET_DVR_API BOOL __stdcall NET_DVR_OpenSoundShare(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSoundShare(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_Volume(LONG lRealHandle,WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_SaveRealData(LONG lRealHandle,char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopSaveRealData(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetRealDataCallBack(LONG lRealHandle,void(CALLBACK *fRealDataCallBack) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetStandardDataCallBack(LONG lRealHandle,void(CALLBACK *fStdDataCallBack) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_CapturePicture(LONG lRealHandle,char *sPicFileName);//bmp

//动态生成I帧
NET_DVR_API BOOL __stdcall NET_DVR_MakeKeyFrame(LONG lUserID, LONG lChannel);//主码流
NET_DVR_API BOOL __stdcall NET_DVR_MakeKeyFrameSub(LONG lUserID, LONG lChannel);//子码流

//云台控制相关接口
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl(LONG lRealHandle,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl_Other(LONG lUserID,LONG lChannel,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ(LONG lRealHandle,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ_Other(LONG lUserID,LONG lChannel,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset(LONG lRealHandle,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset_Other(LONG lUserID,LONG lChannel,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_TransPTZ_EX(LONG lRealHandle,char *pPTZCodeBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControl_EX(LONG lRealHandle,DWORD dwPTZCommand,DWORD dwStop);
NET_DVR_API BOOL __stdcall NET_DVR_PTZPreset_EX(LONG lRealHandle,DWORD dwPTZPresetCmd,DWORD dwPresetIndex);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise(LONG lRealHandle,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise_Other(LONG lUserID,LONG lChannel,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZCruise_EX(LONG lRealHandle,DWORD dwPTZCruiseCmd,BYTE byCruiseRoute, BYTE byCruisePoint, WORD wInput);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack(LONG lRealHandle, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack_Other(LONG lUserID, LONG lChannel, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZTrack_EX(LONG lRealHandle, DWORD dwPTZTrackCmd);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed_Other(LONG lUserID, LONG lChannel, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_PTZControlWithSpeed_EX(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
NET_DVR_API BOOL __stdcall NET_DVR_GetPTZCruise(LONG lUserID,LONG lChannel,LONG lCruiseRoute, LPNET_DVR_CRUISE_RET lpCruiseRet);


//文件查找与回放
NET_DVR_API LONG __stdcall NET_DVR_FindFile(LONG lUserID,LONG lChannel,DWORD dwFileType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFile(LONG lFindHandle,LPNET_DVR_FIND_DATA lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindClose(LONG lFindHandle);
NET_DVR_API LONG __stdcall NET_DVR_FindNextFile_V30(LONG lFindHandle, LPNET_DVR_FINDDATA_V30 lpFindData);
NET_DVR_API LONG __stdcall NET_DVR_FindFile_V30(LONG lUserID, LPNET_DVR_FILECOND pFindCond);
NET_DVR_API BOOL __stdcall NET_DVR_FindClose_V30(LONG lFindHandle);

NET_DVR_API BOOL __stdcall NET_DVR_LockFileByName(LONG lUserID, char *sLockFileName);
NET_DVR_API BOOL __stdcall NET_DVR_UnlockFileByName(LONG lUserID, char *sUnlockFileName);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByName(LONG lUserID,char *sPlayBackFileName, HWND hWnd);
NET_DVR_API LONG __stdcall NET_DVR_PlayBackByTime(LONG lUserID,LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, HWND hWnd);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackControl(LONG lPlayHandle,DWORD dwControlCode,DWORD dwInValue,DWORD *LPOutValue);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayBack(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetPlayDataCallBack(LONG lPlayHandle,void(CALLBACK *fPlayDataCallBack) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackSaveData(LONG lPlayHandle,char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopPlayBackSave(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPlayBackOsdTime(LONG lPlayHandle, LPNET_DVR_TIME lpOsdTime);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackCaptureFile(LONG lPlayHandle,char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByName(LONG lUserID,char *sDVRFileName,char *sSavedFileName);
NET_DVR_API LONG __stdcall NET_DVR_GetFileByTime(LONG lUserID,LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, char *sSavedFileName);
NET_DVR_API BOOL __stdcall NET_DVR_StopGetFile(LONG lFileHandle);
NET_DVR_API int __stdcall NET_DVR_GetDownloadPos(LONG lFileHandle);
NET_DVR_API int	__stdcall NET_DVR_GetPlayBackPos(LONG lPlayHandle);

//升级
NET_DVR_API LONG __stdcall NET_DVR_AdapterUpgrade(LONG lUserID, char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_Upgrade(LONG lUserID, char *sFileName);
NET_DVR_API LONG __stdcall NET_DVR_VcalibUpgrade(LONG lUserID, LONG lChannel, char const *sFileName);
NET_DVR_API int __stdcall NET_DVR_GetUpgradeState(LONG lUpgradeHandle);
NET_DVR_API int __stdcall NET_DVR_GetUpgradeProgress(LONG lUpgradeHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseUpgradeHandle(LONG lUpgradeHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetNetworkEnvironment(DWORD dwEnvironmentLevel);
//远程格式化硬盘
NET_DVR_API LONG __stdcall NET_DVR_FormatDisk(LONG lUserID,LONG lDiskNumber);
NET_DVR_API BOOL __stdcall NET_DVR_GetFormatProgress(LONG lFormatHandle, LONG *pCurrentFormatDisk,LONG *pCurrentDiskPos,LONG *pFormatStatic);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFormatHandle(LONG lFormatHandle);
//报警
NET_DVR_API LONG __stdcall NET_DVR_SetupAlarmChan(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_CloseAlarmChan(LONG lAlarmHandle);
NET_DVR_API LONG __stdcall NET_DVR_SetupAlarmChan_V30(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_CloseAlarmChan_V30(LONG lAlarmHandle);
//语音对讲
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom(LONG lUserID, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser), DWORD dwUser);
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_V30(LONG lUserID, DWORD dwVoiceChan, BOOL bNeedCBNoEncData, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetVoiceComClientVolume(LONG lVoiceComHandle, WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_StopVoiceCom(LONG lVoiceComHandle);
//语音转发
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_MR(LONG lUserID, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser), DWORD dwUser);
NET_DVR_API LONG __stdcall NET_DVR_StartVoiceCom_MR_V30(LONG lUserID, DWORD dwVoiceChan, void(CALLBACK *fVoiceDataCallBack)(LONG lVoiceComHandle, char *pRecvDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_VoiceComSendData(LONG lVoiceComHandle, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetCurrentAudioCompress(LONG lUserID, LPNET_DVR_COMPRESSION_AUDIO lpCompressAudio);
//语音广播
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStart();
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStart_V30(void(CALLBACK *fVoiceDataCallBack)(char *pRecvDataBuffer, DWORD dwBufSize, void * pUser), void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_ClientAudioStop();
NET_DVR_API BOOL __stdcall NET_DVR_AddDVR(LONG lUserID);
NET_DVR_API LONG __stdcall NET_DVR_AddDVR_V30(LONG lUserID, DWORD dwVoiceChan);
NET_DVR_API BOOL __stdcall NET_DVR_DelDVR(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_DelDVR_V30(LONG lVoiceHandle);
////////////////////////////////////////////////////////////
//透明通道设置
NET_DVR_API LONG __stdcall NET_DVR_SerialStart(LONG lUserID,LONG lSerialPort,void(CALLBACK *fSerialDataCallBack)(LONG lSerialHandle,char *pRecvDataBuffer,DWORD dwBufSize,DWORD dwUser),DWORD dwUser);
//485作为透明通道时，需要指明通道号，因为不同通道号485的设置可以不同(比如波特率)
NET_DVR_API BOOL __stdcall NET_DVR_SerialSend(LONG lSerialHandle, LONG lChannel, char *pSendBuf,DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_SerialStop(LONG lSerialHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SendTo232Port(LONG lUserID, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_SendToSerialPort(LONG lUserID, DWORD dwSerialPort, DWORD dwSerialIndex, char *pSendBuf, DWORD dwBufSize);

//解码 nBitrate = 16000
NET_DVR_API void* __stdcall NET_DVR_InitG722Decoder(int nBitrate );
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Decoder(void *pDecHandle);
NET_DVR_API BOOL __stdcall NET_DVR_DecodeG722Frame(void *pDecHandle, unsigned char* pInBuffer, unsigned char* pOutBuffer);
//编码
NET_DVR_API void* __stdcall NET_DVR_InitG722Encoder();
NET_DVR_API BOOL __stdcall NET_DVR_EncodeG722Frame(void *pEncodeHandle,unsigned char* pInBuffer, unsigned char* pOutBuffer);
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Encoder(void *pEncodeHandle);

//远程控制本地显示
NET_DVR_API BOOL __stdcall NET_DVR_ClickKey(LONG lUserID, LONG lKeyIndex);
//远程控制设备端手动录像
NET_DVR_API BOOL __stdcall NET_DVR_StartDVRRecord(LONG lUserID,LONG lChannel,LONG lRecordType);
NET_DVR_API BOOL __stdcall NET_DVR_StopDVRRecord(LONG lUserID,LONG lChannel);
//解码卡
NET_DVR_API BOOL __stdcall NET_DVR_InitDevice_Card(long *pDeviceTotalChan);
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDevice_Card();
NET_DVR_API BOOL __stdcall NET_DVR_InitDDraw_Card(HWND hParent,COLORREF colorKey);
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDDraw_Card();
NET_DVR_API LONG __stdcall NET_DVR_RealPlay_Card(LONG lUserID,LPNET_DVR_CARDINFO lpCardInfo,long lChannelNum);
NET_DVR_API BOOL __stdcall NET_DVR_ResetPara_Card(LONG lRealHandle,LPNET_DVR_DISPLAY_PARA lpDisplayPara);
NET_DVR_API BOOL __stdcall NET_DVR_RefreshSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_ClearSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_RestoreSurface_Card();
NET_DVR_API BOOL __stdcall NET_DVR_OpenSound_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CloseSound_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetVolume_Card(LONG lRealHandle,WORD wVolume);
NET_DVR_API BOOL __stdcall NET_DVR_AudioPreview_Card(LONG lRealHandle,BOOL bEnable);
NET_DVR_API LONG __stdcall NET_DVR_GetCardLastError_Card();
NET_DVR_API HANDLE __stdcall NET_DVR_GetChanHandle_Card(LONG lRealHandle);
NET_DVR_API BOOL __stdcall NET_DVR_CapturePicture_Card(LONG lRealHandle, char *sPicFileName);
//获取解码卡序列号此接口无效，改用GetBoardDetail接口获得(2005-12-08支持)
NET_DVR_API BOOL __stdcall NET_DVR_GetSerialNum_Card(long lChannelNum,DWORD *pDeviceSerialNo);
//日志
NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog(LONG lUserID, LONG lSelectMode, DWORD dwMajorType,DWORD dwMinorType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog(LONG lLogHandle, LPNET_DVR_LOG lpLogData);
NET_DVR_API BOOL __stdcall NET_DVR_FindLogClose(LONG lLogHandle);
NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog_V30(LONG lUserID, LONG lSelectMode, DWORD dwMajorType,DWORD dwMinorType, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime, BOOL bOnlySmart);
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog_V30(LONG lLogHandle, LPNET_DVR_LOG_V30 lpLogData);
NET_DVR_API BOOL __stdcall NET_DVR_FindLogClose_V30(LONG lLogHandle);
// 报警主机日志
NET_DVR_API LONG __stdcall NET_DVR_FindAlarmHostLog(LONG lUserID, LONG lSelectMode, NET_DVR_ALARMHOST_SEARCH_LOG_PARAM *lpSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextAlarmHostLog(LONG lFindHandle, NET_DVR_ALARMHOST_LOG_RET *lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindAlarmHostLogClose(LONG lFindHandle);
//截止2004年8月5日,共113个接口
//ATM DVR
NET_DVR_API LONG __stdcall NET_DVR_FindFileByCard(LONG lUserID,LONG lChannel,DWORD dwFileType, int nFindType, BYTE *sCardNumber, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
//截止2004年10月5日,共116个接口

//编码
NET_DVR_API void* __stdcall NET_DVR_InitG722Encoder();
NET_DVR_API BOOL __stdcall NET_DVR_EncodeG722Frame(void *pEncodeHandle,unsigned char* pInBuffer, unsigned char* pOutBuffer);
NET_DVR_API void __stdcall NET_DVR_ReleaseG722Encoder(void *pEncodeHandle);
//2005-09-15
NET_DVR_API BOOL __stdcall NET_DVR_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sPicFileName);
//JPEG抓图到内存
NET_DVR_API BOOL __stdcall NET_DVR_CaptureJPEGPicture_NEW(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sJpegPicBuffer, DWORD dwPicSize,  LPDWORD lpSizeReturned);


//2006-02-16
NET_DVR_API int __stdcall NET_DVR_GetRealPlayerIndex(LONG lRealHandle);
NET_DVR_API int __stdcall NET_DVR_GetPlayBackPlayerIndex(LONG lPlayHandle);

//2006-08-28 704-640 缩放配置
NET_DVR_API BOOL __stdcall NET_DVR_SetScaleCFG(LONG lUserID, DWORD dwScale);
NET_DVR_API BOOL __stdcall NET_DVR_GetScaleCFG(LONG lUserID, DWORD *lpOutScale);
NET_DVR_API BOOL __stdcall NET_DVR_SetScaleCFG_V30(LONG lUserID, LPNET_DVR_SCALECFG pScalecfg);
NET_DVR_API BOOL __stdcall NET_DVR_GetScaleCFG_V30(LONG lUserID, LPNET_DVR_SCALECFG pScalecfg);
//2006-08-28 ATM机端口设置
NET_DVR_API BOOL __stdcall NET_DVR_SetATMPortCFG(LONG lUserID, WORD wATMPort);
NET_DVR_API BOOL __stdcall NET_DVR_GetATMPortCFG(LONG lUserID, WORD *LPOutATMPort);

//2006-11-10 支持显卡辅助输出
NET_DVR_API BOOL __stdcall NET_DVR_InitDDrawDevice();
NET_DVR_API BOOL __stdcall NET_DVR_ReleaseDDrawDevice();
NET_DVR_API LONG __stdcall NET_DVR_GetDDrawDeviceTotalNums();
NET_DVR_API BOOL __stdcall NET_DVR_SetDDrawDevice(LONG lPlayPort, DWORD nDeviceNum);

NET_DVR_API BOOL __stdcall NET_DVR_PTZSelZoomIn(LONG lRealHandle, LPNET_DVR_POINT_FRAME pStruPointFrame);
NET_DVR_API BOOL __stdcall NET_DVR_PTZSelZoomIn_EX(LONG lUserID, LONG lChannel, LPNET_DVR_POINT_FRAME pStruPointFrame);

//解码设备DS-6001D/DS-6001F
NET_DVR_API BOOL __stdcall NET_DVR_StartDecode(LONG lUserID, LONG lChannel, LPNET_DVR_DECODERINFO lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_StopDecode(LONG lUserID, LONG lChannel);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecoderState(LONG lUserID, LONG lChannel, LPNET_DVR_DECODERSTATE lpDecoderState);
//2005-08-01
NET_DVR_API BOOL __stdcall NET_DVR_SetDecInfo(LONG lUserID, LONG lChannel, LPNET_DVR_DECCFG lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecInfo(LONG lUserID, LONG lChannel, LPNET_DVR_DECCFG lpDecoderinfo);
NET_DVR_API BOOL __stdcall NET_DVR_SetDecTransPort(LONG lUserID, LPNET_DVR_PORTCFG lpTransPort);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecTransPort(LONG lUserID, LPNET_DVR_PORTCFG lpTransPort);
NET_DVR_API BOOL __stdcall NET_DVR_DecPlayBackCtrl(LONG lUserID, LONG lChannel, DWORD dwControlCode, DWORD dwInValue,DWORD *LPOutValue, LPNET_DVR_PLAYREMOTEFILE lpRemoteFileInfo);
NET_DVR_API BOOL __stdcall NET_DVR_StartDecSpecialCon(LONG lUserID, LONG lChannel, LPNET_DVR_DECCHANINFO lpDecChanInfo);
NET_DVR_API BOOL __stdcall NET_DVR_StopDecSpecialCon(LONG lUserID, LONG lChannel, LPNET_DVR_DECCHANINFO lpDecChanInfo);
NET_DVR_API BOOL __stdcall NET_DVR_DecCtrlDec(LONG lUserID, LONG lChannel, DWORD dwControlCode);
NET_DVR_API BOOL __stdcall NET_DVR_DecCtrlScreen(LONG lUserID, LONG lChannel, DWORD dwControl);
NET_DVR_API BOOL __stdcall NET_DVR_GetDecCurLinkStatus(LONG lUserID, LONG lChannel, LPNET_DVR_DECSTATUS lpDecStatus);

//多路解码器
//2007-11-30 V211支持以下接口 //11
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamic(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DYNAMIC_DEC lpDynamicInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStopDynamic(LONG lUserID, DWORD dwDecChanNum); 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_INFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanInfo(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanEnable(LONG lUserID, DWORD dwDecChanNum, DWORD dwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanEnable(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecEnable(LONG lUserID, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDecChanEnable(LONG lUserID, DWORD dwDecChanNum, DWORD dwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanEnable(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwEnable);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanStatus(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_STATUS lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetVideoStandard(LONG lUserID, DWORD dwDecChanNum, LPDWORD lpdwVideoStandard);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetVideoStandard(LONG lUserID, DWORD dwDecChanNum, DWORD dwVideoStandard);

//2007-12-22 增加支持接口 //18
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetTranInfo(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetTranInfo(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetRemotePlay(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_REMOTE_PLAY lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetRemotePlayControl(LONG lUserID, DWORD dwDecChanNum, DWORD dwControlCode, DWORD dwInValue, DWORD *LPOutValue);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetRemotePlayStatus(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_REMOTE_PLAY_STATUS lpOuter);
//2009-4-13 新增
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamic_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PU_STREAM_CFG lpDynamicInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanInfo_V30(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_DEC_CHAN_INFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetTranInfo_V30(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30 lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetTranInfo_V30(LONG lUserID, LPNET_DVR_MATRIX_TRAN_CHAN_CONFIG_V30 lpTranInfo);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDisplayCfg(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG lpDisplayCfg);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDisplayCfg(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_VGA_DISP_CHAN_CFG lpDisplayCfg);

NET_DVR_API LONG __stdcall NET_DVR_MatrixStartPassiveDecode(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_MATRIX_PASSIVEMODE lpPassiveMode /*, void(CALLBACK *fPassiveDataCallBack)(LONG lPassiveHandle, char * pSendBuf, DWORD dwBufSize, DWORD dwStatus, DWORD dwUser), DWORD dwUser*/);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSendData(LONG lPassiveHandle, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStopPassiveDecode(LONG lPassiveHandle);
NET_DVR_API BOOL __stdcall NET_DVR_UploadLogo(LONG lUserID, DWORD dwDispChanNum, LPNET_DVR_DISP_LOGOCFG lpDispLogoCfg, char *sLogoBuffer);
#define	NET_DVR_SHOWLOGO			1		/*显示LOGO*/
#define	NET_DVR_HIDELOGO			2		/*隐藏LOGO*/  
NET_DVR_API BOOL __stdcall NET_DVR_LogoSwitch(LONG lUserID, DWORD dwDecChan, DWORD dwLogoSwitch);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDeviceStatus(LONG lUserID,  LPNET_DVR_DECODER_WORK_STATUS lpDecoderCfg);

#define	DISP_CMD_ENLARGE_WINDOW				1	/*显示通道放大某个窗口*/
#define	DISP_CMD_RENEW_WINDOW				2	/*显示通道窗口还原*/

NET_DVR_API BOOL __stdcall NET_DVR_MatrixDiaplayControl(LONG lUserID, DWORD dwDispChanNum, DWORD dwDispChanCmd, DWORD dwCmdParam);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixPassiveDecodeControl(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PASSIVEDECODE_CONTROL lpInter);
NET_DVR_API LONG __stdcall NET_DVR_MatrixGetPassiveDecodeStatus(LONG lPassiveHandle);

NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetDecChanCfg(LONG lUserID, DWORD dwDecChan, LPNET_DVR_MATRIX_DECCHAN_CONTROL lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetDecChanCfg(LONG lUserID, DWORD dwDecChan, LPNET_DVR_MATRIX_DECCHAN_CONTROL lpInter);

//end
NET_DVR_API BOOL __stdcall NET_DVR_RefreshPlay(LONG lPlayHandle);
//恢复默认值
NET_DVR_API BOOL __stdcall NET_DVR_RestoreConfig(LONG lUserID);
//保存参数
NET_DVR_API BOOL __stdcall NET_DVR_SaveConfig(LONG lUserID);
//重启
NET_DVR_API BOOL __stdcall NET_DVR_RebootDVR(LONG lUserID);
//关闭DVR
NET_DVR_API BOOL __stdcall NET_DVR_ShutDownDVR(LONG lUserID);

//参数配置 begin
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);
NET_DVR_API BOOL __stdcall NET_DVR_SetDVRConfig(LONG lUserID, DWORD dwCommand,LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRWorkState_V30(LONG lUserID, LPNET_DVR_WORKSTATE_V30 lpWorkState);
NET_DVR_API BOOL __stdcall NET_DVR_GetDVRWorkState(LONG lUserID, LPNET_DVR_WORKSTATE lpWorkState);
NET_DVR_API BOOL __stdcall NET_DVR_SetVideoEffect(LONG lUserID, LONG lChannel, DWORD dwBrightValue, DWORD dwContrastValue, DWORD dwSaturationValue, DWORD dwHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_GetVideoEffect(LONG lUserID, LONG lChannel, DWORD *pBrightValue, DWORD *pContrastValue, DWORD *pSaturationValue, DWORD *pHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_ClientGetframeformat(LONG lUserID, LPNET_DVR_FRAMEFORMAT lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_ClientSetframeformat(LONG lUserID, LPNET_DVR_FRAMEFORMAT lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_GetAtmFrameFormat_V30(LONG lUserID, LONG lAtmChannel, LPNET_DVR_ATM_FRAMEFORMAT_V30 lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_SetAtmFrameFormat_V30(LONG lUserID, LONG lAtmChannel, LPNET_DVR_ATM_FRAMEFORMAT_V30 lpFrameFormat);
NET_DVR_API BOOL __stdcall NET_DVR_GetAtmProtocol(LONG lUserID, LPNET_DVR_ATM_PROTOCOL lpAtmProtocol);
NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmOut_V30(LONG lUserID, LPNET_DVR_ALARMOUTSTATUS_V30 lpAlarmOutState);
NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmOut(LONG lUserID, LPNET_DVR_ALARMOUTSTATUS lpAlarmOutState);
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmOut(LONG lUserID, LONG lAlarmOutPort,LONG lAlarmOutStatic);

//视频参数调节
NET_DVR_API BOOL __stdcall NET_DVR_ClientSetVideoEffect(LONG lRealHandle,DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue);
NET_DVR_API BOOL __stdcall NET_DVR_ClientGetVideoEffect(LONG lRealHandle,DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue);

//配置文件
NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_SetConfigFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile_V30(LONG lUserID, char *sOutBuffer, DWORD dwOutSize, DWORD *pReturnSize);

NET_DVR_API BOOL __stdcall NET_DVR_GetConfigFile_EX(LONG lUserID, char *sOutBuffer, DWORD dwOutSize);
NET_DVR_API BOOL __stdcall NET_DVR_SetConfigFile_EX(LONG lUserID, char *sInBuffer, DWORD dwInSize);

//启用日志文件写入接口
NET_DVR_API BOOL __stdcall NET_DVR_SetLogToFile(DWORD bLogEnable, char * strLogDir, BOOL bAutoDel);
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKState(LPNET_DVR_SDKSTATE pSDKState);
NET_DVR_API BOOL __stdcall NET_DVR_GetSDKAbility(LPNET_DVR_SDKABL pSDKAbl);
NET_DVR_API BOOL __stdcall NET_DVR_GetPTZProtocol(LONG lUserID, NET_DVR_PTZCFG *pPtzcfg);
//前面板锁定
NET_DVR_API BOOL __stdcall NET_DVR_LockPanel(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_UnLockPanel(LONG lUserID);

NET_DVR_API BOOL __stdcall NET_DVR_SetRtspConfig(LONG lUserID, DWORD dwCommand, LPNET_DVR_RTSPCFG lpInBuffer, DWORD dwInBufferSize);
NET_DVR_API BOOL __stdcall NET_DVR_GetRtspConfig(LONG lUserID, DWORD dwCommand, LPNET_DVR_RTSPCFG lpOutBuffer, DWORD dwOutBufferSize);

//能力集获取
NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceAbility(LONG lUserID, DWORD dwAbilityType, char* pInBuf, DWORD dwInLength, char* pOutBuf, DWORD dwOutLength);

//2009-8-19 视频综合平台接口函数
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubSystemInfo(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetSubSystemInfo(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetLoopPlanArray(LONG lUserID, DWORD dwArrayNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetLoopPlanArray(LONG lUserID, DWORD dwArrayNum, LPNET_DVR_MATRIX_LOOP_DECINFO_V30 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetAlarmShowMode(LONG lUserID, LPNET_DVR_ALARMMODECFG lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetAlarmShowMode(LONG lUserID, LPNET_DVR_ALARMMODECFG lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetCodeSplitter(LONG lUserID, DWORD dwCodeChan, LPNET_DVR_CODESPLITTERINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetCodeSplitter(LONG lUserID, DWORD dwCodeChan, LPNET_DVR_CODESPLITTERINFO lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartDynamicAssociateDecode(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_DYNAMICDECODE lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAlarmTurn(LONG lUserID, DWORD dwDecChanNum, DWORD dwTurnParam);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixAlarmShowControl(LONG lUserID, DWORD dwDecChanNum, DWORD dwShowMode);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetPlanDecode(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PLANDECODE lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetPlanDecode(LONG lUserID, DWORD dwDecChanNum, LPNET_DVR_PLANDECODE lpInter);

//智能
//设置/获取参数关键字
NET_DVR_API BOOL __stdcall NET_DVR_SetBehaviorParamKey(LONG lUserID, LONG lChannel, DWORD dwParameterKey,int nValue);
NET_DVR_API BOOL __stdcall NET_DVR_GetBehaviorParamKey(LONG lUserID, LONG lChannel, DWORD dwParameterKey,int *pValue);

//获取/设置行为分析目标叠加接口
NET_DVR_API BOOL __stdcall NET_DVR_GetVCADrawMode(LONG lUserID, LONG lChannel, LPNET_VCA_DRAW_MODE lpDrawMode);
NET_DVR_API BOOL __stdcall NET_DVR_SetVCADrawMode(LONG lUserID, LONG lChannel, LPNET_VCA_DRAW_MODE lpDrawMode);

//球机跟踪模式设置接口
NET_DVR_API BOOL __stdcall NET_DVR_SetTrackMode(LONG lUserID, LONG lChannel, LPNET_DVR_TRACK_MODE lpTrackMode);
NET_DVR_API BOOL __stdcall NET_DVR_GetTrackMode(LONG lUserID, LONG lChannel, LPNET_DVR_TRACK_MODE lpTrackMode);

//	重启智能库
NET_DVR_API BOOL __stdcall NET_VCA_RestartLib(LONG lUserID, LONG lChannel);

NET_DVR_API BOOL __stdcall NET_DVR_SaveRealData_V30(LONG lRealHandle, DWORD dwTransType, char *sFileName);

NET_DVR_API BOOL __stdcall NET_DVR_EncodeG711Frame(unsigned int iType, unsigned char *pInBuffer, unsigned char *pOutBuffer);
NET_DVR_API BOOL __stdcall NET_DVR_DecodeG711Frame(unsigned int iType, unsigned char *pInBuffer, unsigned char *pOutBuffer);
//2009-7-22 end

NET_DVR_API LONG __stdcall NET_DVR_FindFileByEvent(LONG lUserID, LPNET_DVR_SEARCH_EVENT_PARAM  lpSearchEventParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextEvent(LONG lSearchHandle, LPNET_DVR_SEARCH_EVENT_RET lpSearchEventRet);
//停止采用 NET_DVR_FindClose

NET_DVR_API LONG __stdcall NET_DVR_FindPDCInfo(LONG lUserID, LONG lChannel, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextPDCInfo(LONG lFindHandle,LPNET_DVR_PDC_QUERY lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindPDCClose(LONG lFindHandle);

// 标定校验 
#define NET_DVR_PDC_VERIFY_CALIBRATION  1  //当值为1是为PDC标定校验 pdc传入值为NET_VCA_POINT   传出值为 NET_VCA_RECT结构
#define NET_DVR_VERIFY_BEHAVIOR_CALIBRATION    2    // 行为分析标定线校验 
#define NET_DVR_VERIFY_ITS_CALIBRATION		3 	// 智能交通标定校验 

NET_DVR_API BOOL __stdcall NET_DVR_VerifyCalibration(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, LPVOID lpOuterBuffer, DWORD dwOuterBufferSize);
NET_DVR_API BOOL __stdcall  NET_DVR_ResetCounter(LONG lUserID,LONG lChannel);

NET_DVR_API BOOL __stdcall NET_DVR_GetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPtzPosition(LONG lUserID, LONG lChannel, LONG lPositionID, LPNET_DVR_PTZ_POSITION lpPtzPosition);
NET_DVR_API BOOL __stdcall NET_DVR_SetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);
NET_DVR_API BOOL __stdcall NET_DVR_GetPatrolTrack(LONG lUserID, LONG lChannel, LONG lPatrolIndex, LPNET_DVR_PATROL_TRACKCFG lpPatrolTrack);

// SDK_V35
NET_DVR_API LONG __stdcall NET_DVR_FindNextLog_MATRIX(LONG lLogHandle, LPNET_DVR_LOG_MATRIX lpLogData);
NET_DVR_API LONG __stdcall NET_DVR_FindDVRLog_Matrix(LONG lUserID, LONG lSelectMode, DWORD dwMajorType, DWORD dwMinorType, LPNET_DVR_VEDIOPLATLOG lpVedioPlatLog, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
//2009-12-17 增加视频综合平台编码子系统能力集

//2009-10-26 抓拍机基线 begin
NET_DVR_API BOOL __stdcall NET_DVR_ManualSnap(LONG lUserID, LPNET_DVR_MANUALSNAP lpInter, LPNET_DVR_PLATE_RESULT lpOuter);
NET_DVR_API BOOL __stdcall NET_DVR_ContinuousShoot(LONG lUserID, LPNET_DVR_SNAPCFG lpInter);
//2009-10-26 抓拍机基线 end

//2009-12-22 增加视频综合平台按通道获取PTZ协议接口
NET_DVR_API BOOL __stdcall NET_DVR_GetPTZProtocol_Ex(LONG lUserID, LONG lChannel, NET_DVR_PTZCFG *pPtzcfg);
//2010-01-16

NET_DVR_API LONG __stdcall NET_DVR_StartEmailTest(LONG lUserID);
NET_DVR_API BOOL __stdcall NET_DVR_StopEmailTest(LONG lEmailTestHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetEmailTestProgress(LONG lEmailTestHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_GetIPCProtoList(LONG lUserID, LPNET_DVR_IPC_PROTO_LIST lpProtoList);
NET_DVR_API LONG __stdcall NET_DVR_SmartSearch(LONG lUserID,  LPNET_DVR_SMART_SEARCH_PARAM lpSmartSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_SearchNextInfo(LONG lSearchHandle, LPNET_DVR_SMART_SEARCH_RET lpSmartSearchRet);
NET_DVR_API BOOL __stdcall NET_DVR_StopSearch(LONG lSearchHandle);

// IP San 文件目录查找
NET_DVR_API LONG __stdcall NET_DVR_FindIpSanDirectory(LONG lUserID, LPNET_DVR_IPSAN_SERACH_PARAM lpIpsanSearchParam);
NET_DVR_API LONG __stdcall NET_DVR_FindNextDirectory(LONG lFindHandle, LPNET_DVR_IPSAN_SERACH_RET lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_FindDirectoryClose(LONG lFindHandle);


typedef void (CALLBACK *REALDATACALLBACK) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);

NET_DVR_API LONG __stdcall NET_DVR_ZeroStartPlay(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, REALDATACALLBACK fRealDataCallBack_V30, void* pUser, BOOL bBlocked);

NET_DVR_API BOOL __stdcall NET_DVR_ZeroStopPlay(LONG lPlayHandle);
NET_DVR_API BOOL __stdcall NET_DVR_ZeroMakeKeyFrame(LONG lUserID, LONG lZeroChan);
NET_DVR_API BOOL __stdcall NET_DVR_PlayBackControl_V40(LONG lPlayHandle,DWORD dwControlCode, LPVOID lpInBuffer, DWORD dwInLen, LPVOID lpOutBuffer, DWORD *lpOutLen);
NET_DVR_API BOOL __stdcall NET_DVR_ZeroTurnOver(LONG lUserID, LONG lChannel, BOOL bNextPreview);

NET_DVR_API BOOL __stdcall NET_DVR_GetDiskList(LONG lUserID, LPNET_DVR_DISKABILITY_LIST lpDiskList);
NET_DVR_API LONG __stdcall NET_DVR_BackupByName(LONG lUserID, LPNET_DVR_BACKUP_NAME_PARAM lpBackupByName);
NET_DVR_API LONG __stdcall NET_DVR_BackupByTime(LONG lUserID, LPNET_DVR_BACKUP_TIME_PARAM lpBackupBytime);
NET_DVR_API BOOL __stdcall NET_DVR_GetBackupProgress(LONG lHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_StopBackup(LONG lHandle);

NET_DVR_API BOOL __stdcall NET_DVR_GetSadpInfoList(LONG lUserID, LPNET_DVR_SADPINFO_LIST lpSadpInfoList);
NET_DVR_API BOOL __stdcall NET_DVR_UpdateSadpInfo(LONG lUserID, LPNET_DVR_SADP_VERIFY lpSadpVerify, LPNET_DVR_SADPINFO lpSadpInfo);


NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubDecSystemJoinInfo(LONG lUserID, LPNET_DVR_ALLDECSUBSYSTEMJOININFO lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_SetCodeSplitterAssociate(LONG lUserID, DWORD dwDecoderChan, DWORD dwSlotNum, LPNET_DVR_CODESPLITTERASSOCIATE lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_GetCodeSplitterAssociate(LONG lUserID, DWORD dwDecoderChan, DWORD dwSlotNum, LPNET_DVR_CODESPLITTERASSOCIATE lpInter);




NET_DVR_API BOOL __stdcall NET_DVR_InquestGetCDRWScheme(LONG lUserID, LPNET_DVR_INQUEST_CDRW_CFG lpCDRWCfg);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetCDRWScheme(LONG lUserID, LPNET_DVR_INQUEST_CDRW_CFG lpCDRWCfg);
NET_DVR_API BOOL __stdcall NET_DVR_InquestDeleteFile(LONG lUserID, LPNET_DVR_INQUEST_FILES lpDeleteFile);
NET_DVR_API BOOL __stdcall NET_DVR_InquestCDWByFile(LONG lUserID, LPNET_DVR_INQUEST_FILES lpCdrwFile);
NET_DVR_API LONG __stdcall NET_DVR_InquestUploadFile(LONG lUserID, char *sFileName);
NET_DVR_API BOOL __stdcall NET_DVR_InquestUploadClose(LONG lUploadHandle);
NET_DVR_API LONG __stdcall NET_DVR_InquestGetUploadState(LONG lUploadHandle, LPDWORD pProgress);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStartCDW( LONG lUserID, BOOL bPause);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStopCDW(LONG lUserID, BOOL bCancelWrite);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetCDWState(LONG lUserID, LPNET_DVR_INQUEST_CDRW_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetPIPStatus(LONG lUserID, LPNET_DVR_INQUEST_PIP_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetPIPStatus(LONG lUserID, LPNET_DVR_INQUEST_PIP_STATUS pStatus);
NET_DVR_API BOOL __stdcall NET_DVR_InquestCheckSecretKey(LONG lUserID, BOOL *bSecretSet);
NET_DVR_API BOOL __stdcall NET_DVR_InquestSetSecretKey(LONG lUserID, LPNET_DVR_INQUEST_SECRET_INFO pSecretInfo);
NET_DVR_API BOOL __stdcall NET_DVR_InquestStreamEncrypt(LONG lUserID, LONG lChannel, BOOL bEncrypt);
NET_DVR_API BOOL __stdcall NET_DVR_InquestGetEncryptState(LONG  lUserID, LONG lChannel, BOOL *bEncrypt);
NET_DVR_API LONG __stdcall NET_DVR_InquestFindFile(LONG lUserID);
NET_DVR_API LONG __stdcall NET_DVR_InquestFindNextFile(LONG lFindHandle, LPNET_DVR_INQUEST_FILEINFO lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_InquestFindClose(LONG lFindHandle);

//查找下载图片
NET_DVR_API LONG __stdcall NET_DVR_FindPicture(LONG lUserID,LONG lChannel,DWORD dwFileType, BOOL bNeedCardNum, BYTE *sCardNumber, LPNET_DVR_TIME lpStartTime, LPNET_DVR_TIME lpStopTime);
NET_DVR_API LONG __stdcall NET_DVR_FindNextPicture(LONG lFindHandle,LPNET_DVR_FIND_PICTURE lpFindData);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFindPicture(LONG lFindHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetPicture(LONG lUserID,char *sDVRFileName,char *sSavedFileName);

// 9000RH
NET_DVR_API LONG __stdcall NET_DVR_RaidFastConfig(LONG lUserID, char *sName);
NET_DVR_API BOOL __stdcall NET_DVR_FastConfigProcess(LONG lHandle, DWORD *pState);
NET_DVR_API BOOL __stdcall NET_DVR_CloseFastConfig(LONG lHandle);
NET_DVR_API BOOL __stdcall NET_DVR_GetArraySpaceAlloc(LONG lUserID, DWORD dwSlot, LPNET_DVR_ARRAY_SPACE_ALLOC_INFO lpOutBuf);
NET_DVR_API BOOL __stdcall NET_DVR_DelArray(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_CreateArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_CalcArraySize(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam, UINT64* lpArraySize);
NET_DVR_API BOOL __stdcall NET_DVR_MigrateArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_RebuildArray(LONG lUserID, LPNET_DVR_OPERATE_ARRAY_PARAM lpArrayParam);
NET_DVR_API BOOL __stdcall NET_DVR_CreateVD(LONG lUserID, LPNET_DVR_OPERATE_VD_PARAM lpVDParam);
NET_DVR_API BOOL __stdcall NET_DVR_DelVD(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_RepairVD(LONG lUserID, DWORD dwID);
NET_DVR_API BOOL __stdcall NET_DVR_SetSpareDisk(LONG lUserID, LPNET_DVR_SPARE_DISK_PARAM lpSpareDisk);
NET_DVR_API BOOL __stdcall NET_DVR_GetPDList(LONG lUserID,  LPNET_DVR_PHY_DISK_LIST lpPDList);
NET_DVR_API BOOL __stdcall NET_DVR_GetArrayList(LONG lUserID, LPNET_DVR_ARRAY_LIST lpArrayList);
NET_DVR_API BOOL __stdcall NET_DVR_GetVDList(LONG lUserID, LPNET_DVR_VD_LIST lpVDList);
NET_DVR_API LONG __stdcall NET_DVR_ExpandDisk(LONG    lUserID,DWORD dwVDSLot);
NET_DVR_API BOOL __stdcall NET_DVR_GetExpandProgress(LONG lExpandHandle, DWORD* pState);
NET_DVR_API BOOL __stdcall NET_DVR_CloseExpandHandle(LONG lExpandHandle);

/*******************************test*****************************************/

NET_DVR_API LONG __stdcall NET_DVR_AlgoDebugStart(LONG lUserID, LONG lCHannel, void(CALLBACK *fAlgoLibInfoCallBack)(LONG lHandle, LONG lChannel,char *pRecvDataBuffer, DWORD dwBufSize, void* pUser), void* pUser);
NET_DVR_API BOOL __stdcall NET_DVR_AlgoDebugSend(LONG lHandle, LONG lChannel, char *pSendBuf, DWORD dwBufSize);
NET_DVR_API BOOL __stdcall NET_DVR_AlgoDebugStop(LONG lHandle);
NET_DVR_API BOOL __stdcall NET_DVR_SetLogPrint(BOOL bLogPrint);
NET_DVR_API BOOL __stdcall NET_DVR_SetLogPrintAction(DWORD nLogLevel, DWORD nToDevice, BOOL bEnable, int Reserve1, int Reserve2);



//2010-09-13
#define	NET_DVR_MATRIX_BIGSCREENCFG_GET		1140//获取大屏拼接参数
#define	NET_DVR_MATRIX_BIGSCREENCFG_SET		1141//设置大屏拼接参数

#define		MAX_BIGSCREENNUM	16//最多大屏拼接数

typedef struct tagNET_DVR_SINGLESCREENCFG
{
    BYTE	byScreenSeq;//屏幕序号,0xff表示不用此屏
    BYTE	bySubSystemNum;//解码子系统槽位号
    BYTE	byDsipNum;//解码子系统上对应显示通道号
    BYTE	byRes[9];
}NET_DVR_SINGLESCREENCFG, *LPNET_DVR_SINGLESCREENCFG;

typedef struct tagNET_DVR_BIGSCREENCFG
{
    DWORD					  dwSize;
    BYTE					  byEnable;//大屏拼接使能，0-不使能，1-使能
    //大屏拼接模式，1-1×1，2-1×2，3-1×3，4-1×4，5-2×1，6-2×2，7-2×3，8-2×4，
    //9-3×1，10-3×2，11-3×3，12-3×4，13-4×1，14-4×2，15-4×3，16-4×4
    BYTE				      byMode;
    BYTE					  byMainDecodeSystem;//主屏槽位号
    BYTE					  byRes1[5];
    //大屏拼接从屏幕信息
    NET_DVR_SINGLESCREENCFG struFollowSingleScreen[MAX_BIGSCREENNUM]; 
    BYTE					  byRes2[16];
}NET_DVR_BIGSCREENCFG, *LPNET_DVR_BIGSCREENCFG;

//2010-09-15
/****************************************************************
功能:多路解码器图像微调接口
参数说明:
lUserID: (解码子系统)NET_DVR_Login()的返回值
dwDispChan:显示通道
dwPicAdjust:微调命令
dwCmdParam：图像微调参数
TRUE表示成功,FALSE表示失败
*****************************************************************/  
#define	DECODEPIC_LEFTADJUST			1		/*图像左移*/
#define	DECODEPIC_RIGHTADJUST			2		/*图像右移*/
#define	DECODEPIC_UPADJUST				3		/*图像上移*/
#define	DECODEPIC_DOWNADJUST			4		/*图像下移*/
#define	DECODEPIC_REDUCEADJUST			5		/*图像缩小*/          
NET_DVR_API BOOL __stdcall NET_DVR_MatrixPicAdjust(LONG lUserID, DWORD dwDispChan, DWORD dwPicAdjust, DWORD dwCmdParam);
/****************************************************************
功能:报警触发录像接口
参数说明:
lUserID: (编码子系统)NET_DVR_Login()的返回值
dwChan:编码通道
dwAlarmSeq：报警序号
dwRecordTime：录像时间(秒)
dwRes：保留
TRUE表示成功,FALSE表示失败
*****************************************************************/  
NET_DVR_API BOOL __stdcall NET_DVR_AlarmJoinedRecord(LONG lUserID, DWORD dwChan, DWORD dwAlarmSeq, DWORD dwRecordTime, DWORD dwRes);
//2010-09-27
#define 	MAX_UNITEDMATRIX_NUM		8//级联中最多视频综合平台数量
#define 	MAX_SUBDOMAIN_NUM		    4//级联中最多子域数量
typedef struct tagNET_DVR_SUBSERVERINFO
{
	BYTE		bySequence;//序号，对于子域，是子域号，对于视频综合平台，是平台号，0表示无此平台\子域
	BYTE		byBelongSubDomain;//对于平台有效，表示属于哪个子域
	BYTE		byRes1[6];
	DWORD       dwMaxIpcNums;//连接的最多IPC数量
    NET_DVR_IPADDR struSubMatrixIP;		/*IP地址*/
    WORD		wSubMatrixPort;        /*子系统端口号*/
    BYTE		byRes2[6];
}NET_DVR_SUBSERVERINFO, *LPNET_DVR_SUBSERVERINFO;

typedef struct tagNET_DVR_UNITEDMATRIXINFO
{
	DWORD dwSize;
	NET_DVR_SUBSERVERINFO struDomainInfo;
	NET_DVR_SUBSERVERINFO struSubDomainInfo[MAX_SUBDOMAIN_NUM];//子域信息
	NET_DVR_SUBSERVERINFO struMatrixInfo[MAX_UNITEDMATRIX_NUM];//视频综合平台信息
    BYTE  byRes[32];
}NET_DVR_UNITEDMATRIXINFO, *LPNET_DVR_UNITEDMATRIXINFO;
/****************************************************************
功能:获取级联78K配置信息
参数说明:
lUserID: NET_DVR_Login()的返回值(78K)
lpInter：LPNET_DVR_UNITEDMATRIXINFO结构
返回值：TRUE表示成功,FALSE表示失败
****************************************************************/			 
NET_DVR_API BOOL __stdcall NET_DVR_GetUnitedMatrixInfo(LONG lUserID, LPNET_DVR_UNITEDMATRIXINFO lpInter);

/*******************************test*****************************************/

typedef struct tagNET_DVR_REGCALLBACKPARAM
{
	char sDeviceID[NAME_LEN];//设备ID串
	char sPassword[PASSWD_LEN];
	BYTE sSerialNumber[SERIALNO_LEN]; /* 设备序列号 */
	DWORD dwDeviceType;//设备类型
	BYTE nStatus;// 上下线状态（0下线，1上线）
	/* net type, 0: unknow; 1: 2G wireless networks; 2: 3G wireless networks; 3: line networks */
	BYTE byNetType;	
	BYTE byRes[14];
}NET_DVR_REGCALLBACKPARAM, *LPNET_DVR_REGCALLBACKPARAM;
typedef LONG(CALLBACK * REGCallBack)(LONG lUserID, LPNET_DVR_REGCALLBACKPARAM pRegCallbackParam, void *pUser);
NET_DVR_API BOOL __stdcall NET_DVR_SetRegisterCallBack(REGCallBack fRegCallBack, void* pUser);
typedef struct tagNET_DVR_PREVIEWPARAM
{
    BYTE byTransProtol;		//传输协议，0-TCP, 1-UDP
    BYTE byTransMode;		///* 传输码流模式 0－主码流 1－子码流*/ 
    NET_DVR_IPADDR struCuIp; //CU端IP地址
    WORD wPort;/*CU端口*/
    WORD wUdpPort;
    BYTE bySupportQos;//是否启用QOS,1-启用，0-不启用
	BYTE byRes[9];
}NET_DVR_PREVIEWPARAM, *LPNET_DVR_PREVIEWPARAM;
NET_DVR_API BOOL CALLBACK NET_DVR_PreviewRequest(LONG lUserID, LONG lChannel, LPNET_DVR_PREVIEWPARAM lpPreviewParam);

typedef struct tagNET_DVR_PREVIEWCALLBACKPARAM
{
	LONG lChannel;
	BYTE nLinkProtocol;
	BYTE nTransMode;
	BYTE byRes[10];
}NET_DVR_PREVIEWCALLBACKPARAM, *LPNET_DVR_PREVIEWCALLBACKPARAM;
typedef LONG(CALLBACK * PREVIEWRESPONSECallBack)(LONG lUserID, LONG lStreamHandle, LPNET_DVR_PREVIEWCALLBACKPARAM pPewviewCallbackParam,void *pUser);

NET_DVR_API BOOL CALLBACK NET_DVR_SetPreviewResponseCallBack(PREVIEWRESPONSECallBack fPreviewResponseCallBack, void *pUser);


//回放
typedef struct tagNET_DVR_PLAYBACKREQUESTPARAM
{
    BYTE byPlayBackMode;		/* 回放下载模式 1－按名字 2－按时间 */
    BYTE byRes1[3];
    union
    {
        char sFileName [100];		/* 回放的文件名 */
        struct 
        {
            LONG	lChannel;				/*回放的通道号*/
            NET_DVR_TIME struStartTime;			/* 按时间回放的开始时间 */
            NET_DVR_TIME struStopTime;			/* 按时间回放的结束时间 */
            BYTE    byRes[48];
        }struPlayBackbyTime;
    }playbackmode;
    NET_DVR_IPADDR struCuIp; //CU端IP地址
    WORD	wPort;/*CU端口*/
    BYTE	byRes2[22];
}NET_DVR_PLAYBACKREQUESTPARAM, *LPNET_DVR_PLAYBACKREQUESTPARAM;
/**************************************************************
                 功能:回放请求接口
                 参数说明:
                 lUserID: 设备注册ID
                 lpPlayBackRequestParam: NET_DVR_PLAYBACKREQUESTPARAM结构指针
                                  返回值：
                                  TRUE成功，FALSE失败
***************************************************************/                 
NET_DVR_API BOOL __stdcall NET_DVR_PlaybackRequest(LONG lUserID, LPNET_DVR_PLAYBACKREQUESTPARAM lpPlayBackRequestParam);

//2010-10-06
typedef struct tagNET_DVR_PLAYBACKCALLBACKPARAM
{
    BYTE byPlayBackMode;		/* 回放下载模式 1－按名字 2－按时间 */
    BYTE byRes1[3];
    union
    {
        char sFileName [100];		/* 回放的文件名 */
        struct 
        {
            LONG    	lChannel;				/*回放的通道号*/
            NET_DVR_TIME struStartTime;			/* 按时间回放的开始时间 */
            NET_DVR_TIME struStopTime;			/* 按时间回放的结束时间 */
            BYTE       byRes[48];
        }struPlayBackbyTime;
    }playbackmode;
    BYTE byRes2[48];
}NET_DVR_PLAYBACKCALLBACKPARAM, *LPNET_DVR_PLAYBACKCALLBACKPARAM;
/***************************************************************
lUserID：用户ID
lPlaybackHandle：回放句柄
lpPlaybackParam：LPNET_DVR_PLAYBACKCALLBACKPARAM结构
pUser:用户数据
注：返回值是0表示上层通过回放请求验证 
****************************************************************/           
typedef LONG(CALLBACK * PLAYBACKRESPONSECallBack)(LONG lUserID, LONG lPlaybackHandle, LPNET_DVR_PLAYBACKCALLBACKPARAM lpPlaybackParam,void *pUser);

/******************************************************************
说明：设置设备端回放推码流回应回调函数
输入参数：
fPlaybackResponseCallBack:设备回放"推流"回调函数指针;
pUser:用户数据
输出参数：
返回值:FALSE失败，TRUE成功
******************************************************************/      
NET_DVR_API BOOL __stdcall NET_DVR_SetPlaybackResponseCallBack(PLAYBACKRESPONSECallBack fPlaybackResponseCallBack, void *pUser);



/************************************************
lUserID：用户ID
lPlayHandle：回放句柄
lVoiceChannel：对讲通道号
nAudioType：音频类型，0-G722,1-G711
pUser:用户数据
注：返回值是0表示上层通过回放请求验证
************************************************/            
typedef LONG(CALLBACK * VOICERESPONSECallBack)(LONG lUserID, LONG lVoiceHandle, LONG lVoiceChannel, BYTE nAudioType, void *pUser);

/*************************************************
说明：设置设备端对讲回应回调函数
输入参数：
fVoiceResponseCallBack:设备对讲回调函数指针;
pUser:用户数据
输出参数：
返回值:FALSE失败，TRUE成功
**************************************************/      
NET_DVR_API BOOL __stdcall NET_DVR_SetVoiceResponseCallBack(VOICERESPONSECallBack fVoiceResponseCallBack, void *pUser);

typedef struct tagNET_DVR_VOICEREQUESETPARAM
{
    BYTE	nVoiceChannel;		//对讲通道号
    BYTE	byRes1[3];
    NET_DVR_IPADDR struCuIp; //CU端IP地址
    WORD	 wPort;/*CU端口*/
    BYTE	byRes2[10];
}NET_DVR_VOICEREQUESTPARAM, *LPNET_DVR_VOICEREQUESTPARAM;
/************************************************************
              功能:对讲请求接口
              参数说明:
              lUserID: 设备注册ID
              lpVoiceParam: NET_DVR_VOICEREQUESTPARAM结构指针
                            返回值：
                            TRUE成功，FALSE失败
**************************************************************/              
NET_DVR_API BOOL __stdcall NET_DVR_VoiceRequest(LONG lUserID, LPNET_DVR_VOICEREQUESTPARAM lpVoiceParam);

typedef struct tagNET_DVR_ALARMSETUPREQUESETPARAM
{
	NET_DVR_IPADDR struAlarmServerIp; //CU端IP地址
	WORD	 wPort;/*CU端口*/
	BYTE	byRes[2];
}NET_DVR_ALARMSETUPREQUESTPARAM, *LPNET_DVR_ALARMSETUPREQUESTPARAM;
/********************************************************
功能:布防请求接口
参数说明:
lUserID: 设备注册ID
lpAlarmSetupParam: NET_DVR_ALARMSETUPREQUESTPARAM结构指针
				   返回值：
				   TRUE成功，FALSE失败
********************************************************/				   
NET_DVR_API BOOL __stdcall NET_DVR_AlarmSetupRequest(LONG lUserID, LPNET_DVR_ALARMSETUPREQUESTPARAM lpAlarmSetupParam);
		
typedef struct _tagNET_DVR_GPSALARMINFO
{
	DWORD dwUserID;//SDK分配给设备的id号
	DWORD	dwSpeed;//速度
	DWORD	dwLongitude;		/* 经度*/
	DWORD	dwLatitude;       /* 纬度*/
	char	sDirection[2];   /* direction[0]:'E'or'W'(东经/西经), direction[1]:'N'or'S'(北纬/南纬) */
	BYTE    byRes[2];              /* 保留位 */
}NET_DVR_GPSALARMINFO, *LPNET_DVR_GPSALARMINFO;
#define  COMM_ALARM_ALARMGPS        0x1106  //GPS报警信息上传

//图片信息上传
typedef struct tagNET_DVR_PICINFO
{
	DWORD   dwSize;				//结构长度
	BYTE    byChanIndex;			//通道号
	BYTE    byRes1[3];				//保留
	BYTE    byAbsTime[32];		//绝对时间点, yyyymmddhhmmssxxx,
	DWORD   dwPicLen;					//图片长度
	BYTE	byRes2[32];
	BYTE	*pPicBuffer;
}NET_DVR_PICTUREINFO, *LPNET_DVR_PICTUREINFO;
#define COMM_UPLOAD_PICTUREINFO		0x2900	//上传图片信息

//平台参数
typedef struct tagNET_DVR_CMSPARAM
{
	DWORD   dwSize;
	NET_DVR_IPADDR struCmsAddr;
	WORD   wCmsPort;
	BYTE   byRes1[2];
	BYTE   sDeviceID[NAME_LEN];
	BYTE   byPassword[PASSWD_LEN];
	NET_DVR_IPADDR struPicServerAddr;
	WORD   wPicServerPort;
	BYTE   byRes2[82];
}NET_DVR_CMSPARAM, *LPNET_DVR_CMSPARAM;


///拨号功能
#define DIALPASSWD_LEN  32 //3G拨号密码长度

typedef struct tagNET_DVR_QOSPARAM
{
	WORD wMaxBitUL;	/* the maximum number of kbits/s in up-link traffic */
	WORD wMaxBitDL;	/* the maximum number of kbits/s in down-link traffic */
	BYTE byTrafficClass;	/* 0: conversationnal; 1: streaming; 2: interactive;3: background; 4: subscribed value(default) */
	BYTE byRes[7];
}NET_DVR_QOSPARAM, *LPNET_DVR_QOSPARAM;


typedef struct tagNET_DVR_PPPDPARAM
{
	BYTE byDialNum[NAME_LEN];		/* dial number, eg. "#777" */
	BYTE byUserName[NAME_LEN];	/* user name, eg. "card" */
	BYTE byPassword[DIALPASSWD_LEN];	/* password, eg. "card" */
	BYTE byApn[NAME_LEN];		/* access point name, eg. "cmnet" */
	NET_DVR_IPADDR struLocalIp;/* local IP address */
	NET_DVR_IPADDR struRemoteIp;/* remote IP address */
	WORD wMtuSize;		/* max transfer unit of ppp interface */
	BYTE byVerifyProtocal;	/* IPCP verify protocal: 0: auto; 1: CHAP; 2: PAP */
	BYTE byRes[25];	
}NET_DVR_PPPDPARAM, *LPNET_DVR_PPPDPARAM;

typedef struct tagNET_DVR_DIALPARAM
{
	DWORD dwSize;
	BYTE bEnable3G;		/* 0: disable; 1: enable 3g */
	BYTE byDialMethod;		/* dial methold: 0: auto dial; 1: manual dial; */
	BYTE bySwitchMethod;	/* switch methold: 0: auto switch;1：3G优先，2: manual switch to 2G; 3: manual switch to 3G; */
	BYTE byRes1[11];
	WORD wOffLineTime;		/* auto off line when no connection exist，second */	
	NET_DVR_PPPDPARAM struPppdParam;
	NET_DVR_QOSPARAM struQosParam;
	BYTE byRes2[24];
}NET_DVR_DIALPARAM, *LPNET_DVR_DIALPARAM;

typedef struct tagNET_DVR_DIALREQUEST
{
	BYTE byConnNum;		/*网卡序号*/
	BYTE byNetType;		/* 指定获得某个网络的默认拨号参数，设置时此参数没用。0：自动；1：CDMA；2：EVDO；3：WCDMA；4：TD-SCDMA */
	BYTE byRes[6];
} NET_DVR_DIALREQUEST, *LPNET_DVR_DIALREQUEST;
/**************************************************
功能: 
参数说明:
lUserID: NET_DVR_Login()的返回值
lpDialRequest:拨号参数请求结构指针
lpDialParam: NET_DVR_DIALPARAM结构指针
 返回值：
 TRUE表示成功,FALSE表示失败
***************************************************/			 
NET_DVR_API BOOL __stdcall NET_DVR_GetDialParam(LONG lUserID, LPNET_DVR_DIALREQUEST lpDialRequest, LPNET_DVR_DIALPARAM lpDialParam);

/***************************************************
			 			 功能: 
			 			 参数说明:
			 lUserID: NET_DVR_Login()的返回值
			 lpDialRequest:拨号参数请求结构
			 lpDialParam: NET_DVR_DIALPARAM结构指针
			 			 返回值：
			 			 TRUE表示成功,FALSE表示失败	
***************************************************/			 		 
NET_DVR_API BOOL __stdcall NET_DVR_SetDialParam(LONG lUserID, LPNET_DVR_DIALREQUEST lpDialRequest, LPNET_DVR_DIALPARAM lpDialParam);

			 
/* UIM card information */
typedef enum
{
	UIM_UNKNOWN = 0,
	UIM_VALID = 1,
	UIM_NOVALID = 4,
	UIM_ROAM = 11,
	UIM_NOEXIST = 255
}UIM_INFO;

/* real 3g mode */
typedef enum
{
	 /* evdo */
	RMODE_CDMA1X = 12,
	RMODE_EVDO = 14,
	RMODE_CDMAHYBRID = 18,
	/* wcdma */
	RMODE_GSM = 21,
	RMODE_GPRS = 22,
	RMODE_EDGE = 23,
	RMODE_WCDMA = 24,
	RMODE_HSDPA = 25,
	RMODE_HSUPA = 26,
	RMODE_HSPA = 27,
	/* tdscdma */
	RMODE_TGSM = 31,
	RMODE_TGPRS = 32,
	RMODE_TEDGE = 33,
	RMODE_TDSCDMA = 34,
	RMODE_TDHSDPA = 35,
	RMODE_TDHSUPA = 36,
	RMODE_TDHSPA = 37
}REAL_MODE;

typedef struct tagNET_DVR_DIALSTATUS
{
	 BYTE byRealMode;		/* REAL_MODE ,real 3g mode networks */
	 BYTE byUimCard;		/* UIM_INFO ,UIM card information */
	 BYTE byRes1[6];
	 DWORD dwSignal;			/* signal RSSI */
	 DWORD dwDialStatus;		/* dial status */
	 NET_DVR_IPADDR struLocalIp;	/* wireless networks IP address */
	 NET_DVR_IPADDR struRemoteIp;	/* wireless networks gateway */
	 NET_DVR_IPADDR struNetMask;	/* wireless networks netmask */
	 NET_DVR_IPADDR struDns;		/* wireless networks DNS */	 
	 BYTE  byRes2[16];
}NET_DVR_DIALSTATUS, *LPNET_DVR_DIALSTATUS;

//短信功能
#define MAX_WHITELIST_NUM	8 //最大白名单数
typedef struct tagNET_DVR_SMSRELATIVEPARAM
{
	 DWORD dwSize;
	 BYTE bEnableSmsAlarm;	/* 0: disable; 1: enable 3g */
	 BYTE byRes1[7];
	 BYTE byWhiteList[MAX_WHITELIST_NUM][16];
	 BYTE byRes2[48];
}NET_DVR_SMSRELATIVEPARAM, *LPNET_DVR_SMSRELATIVEPARAM;
typedef struct tagNET_DVR_3GTIME
{
	 WORD wYear;
	 BYTE byMonth;
	 BYTE byDay;
	 BYTE byHour;
	 BYTE byMinute;
	 BYTE bySecond;
	 BYTE byRes;
}NET_DVR_3GTIME,*LPNET_DVR_3GTIME;


typedef struct tagNET_DVR_SMSLISTINFO
{
	 DWORD  dwSize;
	 DWORD dwTotalSmsNum;//短信条数
	 BYTE  byRes[8];
	 BYTE  *pSmsParam;
	 DWORD dwBufLen;//所分配指针长度，输入参数
}NET_DVR_SMSLISTINFO, *LPNET_DVR_SMSLISTINFO;

typedef struct tagNET_DVR_SMSPARAM
{
	 DWORD dwIndex;			/* the index of sms */
	 BYTE byStatus;			/* read yet or not */
	 BYTE byRes[7];
	 NET_DVR_3GTIME struRecvTime;		/* sms receive time */
}NET_DVR_SMSPARAM, *LPNET_DVR_SMSPARAM;
/****************************************************
功能: 
参数说明:
lUserID: NET_DVR_Login()的返回值
lpStartTime:开始时间
lpStopTime: 结束时间
lpSmsListInfo：NET_DVR_SMSLISTINFO结构指针
返回值：
TRUE表示成功,FALSE表示失败
******************************************************/					 
NET_DVR_API BOOL __stdcall NET_DVR_GetSmsListInfo(LONG lUserID, LPNET_DVR_3GTIME lpStartTime, LPNET_DVR_3GTIME lpStopTime, LPNET_DVR_SMSLISTINFO lpSmsListInfo);

typedef struct tagNET_DVR_SMSCONTENT
{
	BYTE byPhoneNum[16];
	BYTE byMsg[140];
}NET_DVR_SMSCONTENT, *LPNET_DVR_SMSCONTENT;

/***************************************************
			  			功能: 获取短信内容
			  			参数说明:
			  lUserID: NET_DVR_Login()的返回值
			  dwSmsIndex:短信序号
			  lpSmsContent: NET_DVR_SMSCONTENT结构指针
			  			  返回值：
			  			  TRUE表示成功,FALSE表示失败
******************************************************/	 			
NET_DVR_API BOOL __stdcall NET_DVR_GetSmsContent(LONG lUserID, DWORD dwSmsIndex, LPNET_DVR_SMSCONTENT lpSmsContent);

/****************************************************
 功能: 发送短信
   参数说明:
 lUserID: NET_DVR_Login()的返回值
lpSmsContent: NET_DVR_SMSCONTENT结构指针
返回值：
TRUE表示成功,FALSE表示失败
*****************************************************/			  			  
NET_DVR_API BOOL __stdcall NET_DVR_SendSms(LONG lUserID, LPNET_DVR_SMSCONTENT lpSmsContent);

			  
//pin码配置
typedef enum
{
	CPIN_READY = 1,
	CPIN_PIN = 2,
	CPIN_PUK = 3,
	CPIN_PIN2 = 4,
	CPIN_PUK2 = 5
}PIN_READY;

typedef struct tagNET_DVR_PINSTATUS
{
	DWORD dwSize;
	BYTE byStatus;		/* PIN status, defination see enum: PIN_READY */
	BYTE byPinTimes;	/* remain input PIN times */
	BYTE byPukTimes;	/* remain input PUK times */	
	BYTE bEnableLock;	/* now the PIN locking function is enabled or not: 0, not enabled lock; 1, lock enabled */
	BYTE byRes[4];
}NET_DVR_PINSTATUS, *LPNET_DVR_PINSTATUS;

typedef enum
{
	PIN_ENABLE = 1,
	PIN_DISABLE = 2,
	PIN_VERIFY = 3,
	PUK_VERIFY = 4,
	PIN_CHANGE = 5
}PIN_CMD;

typedef struct tagNET_DVR_PINCODEPARAM
{
	 DWORD dwSize;
	 BYTE byPinCmd;		/* PIN command, defination see enum: PIN_CMD */
	 BYTE byRes1[3];
	 BYTE byPinCode[8];		/* pin/puk code */
	 BYTE byNewPinCode[8];	/* new pin code */
	 BYTE byRes2[16];
}NET_DVR_PINCODEPARAM, *LPNET_DVR_PINCODEPARAM;

#define NET_DVR_GET_CMSPARA			1170//获取平台参数
#define NET_DVR_SET_CMSPARA			1171//设置平台参数
#define NET_DVR_GET_DIALSTATUS		1172//获取拨号状态参数
#define NET_DVR_GET_SMSRELATIVEPARA	1173//获取短信相关参数
#define NET_DVR_SET_SMSRELATIVEPARA	1174//设置短信相关参数
#define NET_DVR_GET_PINSTATUS		1175//获取Pin状态
#define NET_DVR_SET_PINCMD			1176//设置PIN命令
/*************************************************
函数名:    	NET_DVR_StartServer
功能：启动服务器监听程序
参  数：
		[in]sLocalIP: 本地IP地址
		[in]wLocalPort: 本地监听端口号，由用户设置
返回值：-1表示失败，其他值作为NET_DVR_StopServer函数的句柄参数。获取错误码调用NET_DVR_GetLastError
说  明：该接口主要用于启动服务器监听，接收设备主动上传的主动注册、预览请求、回放请求、语音对讲请求、
布防请求等信息（支持多线程）。须将设备的CMS服务器地址设置成PC机的IP地址（与接口中的sLocalIP参数一致），
CMS端口设置成PC机的监听端口号（与接口中的wLocalPort参数一致）。该接收中的回调函数不能置为NULL，
否则将无法接收到设备上传的主动注册等信息。
*************************************************/
NET_DVR_API LONG __stdcall NET_DVR_StartServer(char *sLocalIP, WORD wLocalPort);
/*************************************************
函数名:    	NET_DVR_StopServer
函数描述:	停止监听来自DVR的请求(支持多线程)
输入参数:   lServerHandle:NET_DVR_StartServer的返回值
输出参数:   			
返回值:		HPR_TRUE表示成功,HPR_FALSE表示失败
*************************************************/
NET_DVR_API BOOL __stdcall NET_DVR_StopServer(LONG lServerHandle);

/************************************************
            lUserID：用户ID
            lAlarmHandle：布防句柄
            pUser:用户数据
            注：返回值是0表示上层通过回放请求验证
************************************************/            
typedef LONG(CALLBACK * ALARMSETUPRESPONSECallBack)(LONG lUserID, LONG lAlarmHandle, void * pUser);
   
/*************************************************
      说明：设置设备端布防请求回调函数
      输入参数：
      fAlarmSetupResponseCallBack:设备布防请求函数指针;
      pUser:用户数据
            输出参数：
            返回值:FALSE失败，TRUE成功
**************************************************/            
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmSetupResponseCallBack(ALARMSETUPRESPONSECallBack fAlarmSetupResponseCallBack, void * pUser);

/****************************************************
功能: 心跳参数设置(3G设备)
参数说明:
[in] wHeartbeatTime：心跳时间间隔，单位：秒，15-15秒，30-30秒，60-60秒，120-120秒，180-180秒。默认是15秒。
[in] byOvertimes: 心跳超时次数
返回值：
TRUE表示成功,FALSE表示失败
*****************************************************/			  			  
NET_DVR_API BOOL __stdcall NET_DVR_SetHeartbeatParam(WORD wHeartbeatTime, BYTE byOvertimes);
/*******************************test*****************************************/


/************************************************************************/
#define MAX_ALARMHOST_ALARMIN_NUM	512//网络报警主机最大报警输入口数
#define MAX_ALARMHOST_ALARMOUT_NUM	512//网络报警主机最大报警输出口数

#define ALARMHOST_MAX_AUDIOOUT_NUM		    32//网络报警主机最大语音输出数
#define ALARMHOST_MAX_ELECTROLOCK_NUM		32//网络报警主机最大电锁数
#define ALARMHOST_MAX_MOBILEGATE_NUM		32//网络报警主机最大移动门数
#define ALARMHOST_MAX_SIREN_NUM             8 // 最大警号数目

typedef enum tagSENSOR_TYPE
{
	SENSOR_TYPE_NONE = 0,       //无
	SENSOR_TYPE_TEMPERATURE = 1, // 温度
	SENSOR_TYPE_HUMIDITY ,      // 湿度
	SENSOR_TYPE_WINDSPEED,      // 风速
	SENSOR_TYPE_GAS,            //气体
	SENSOR_TYPE_UNKNOW = 255    //未定义
}SENSOR_TYPE;

typedef struct tagNET_DVR_SENSOR_INFO
{
	DWORD  dwSize;                 // 结构体大小
	BYTE    byName[MAX_NAMELEN];    // 传感器名称
	BYTE    byEnable;               // 是否启用 
	BYTE    byValid;                // 是否有效 传感器正常不正常(该参数只能获取不能个配置)
	BYTE    byType;                 // 模拟量类型 参照SENSOR_TYPE
	BYTE	byAlarmMode;//报警模式，五种，15-HHHH、14-HHHL、12-HHLL、8HLLL、0-LLLL，
	//即：1111（上上上上），1110（上上上下），1100（上上下下），1000(上下下下)，0000(下下下下)
	float   fMeasureHigh;           // 量程上限
	float   fMeasureLow;            // 量程下限
	// 报警限1-4 依次增大
	float	fAlarm1;           //报警限1
	float	fAlarm2;           //报警限2
	float	fAlarm3;           //报警限3
	float	fAlarm4;           //报警限4
	DWORD   dwOsdCfg;          //模拟量字符叠加，按位表示0-15对应视频通道1-16
	float	fSensitive;			// 灵敏度表示当实时值的变化超过灵敏度的范围时，则表示实时值发生了变化，否则认为没有发生变化。如：灵敏度为0.1，则表示前后检测的两个值之差大于0.1时，则认为数据发生变化大于0.1，需要上传。如果为1，则表示变化超过1时上报。
	BYTE    byRes3[116];            // 保留字节
}NET_DVR_SENSOR_INFO, *LPNET_DVR_SENSOR_INFO;

typedef struct tagNET_DVR_SIREN_PARAM
{
	DWORD   dwSize;     // 结构大小
    BYTE    byName[NAME_LEN];   // 名称
	WORD    wDelay;     // 输出延迟 单位为秒  0表示一直有输出
    BYTE	byRes1[2];
    BYTE    byAssociateAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];   //表示警号跟随的报警输入通道 （多个报警输入同时触发一个警号输出）数组下标0表示报警输入1，依次类推 0-不跟随 1-跟随
    BYTE    byRes2[68];  // 保留字节　
}NET_DVR_SIREN_PARAM, *LPNET_DVR_SIREN_PARAM;

typedef struct tagNET_DVR_AIR_CONDITION_PARAM
{
	DWORD	dwSize;		// 结构体大小
	BYTE	byEnable;	// 0--关机 1--开机
	BYTE	byMode;		// 空调模式
	BYTE	byTemperature;	// 温度，具体值表示 通常为16-30度
	BYTE	byRes[9];		// 保留字节
}NET_DVR_AIR_CONDITION_PARAM, *LPNET_DVR_AIR_CONDITION_PARAM;

typedef enum tagDETECTOR_TYPE
{
    PANIC_BUTTON = 0,               // 紧急开关
    MAGNETIC_CONTACT,               // 门磁开关
    SMOKE_DETECTOR,                 // 烟感探测器
    ACTIVE_INFRARED_DETECTOR,       // 主动红外探测器
    PASSIVE_INFRARED_DETECTOR,      // 被动红外探测器
    GLASS_BREAK_DETECTOR,           // 玻璃破碎探测器
    VIBRATION_DETECTOR,             // 震动探测器
    DUAL_TECHNOLOGY_PIR_DETECTOR,   // 双鉴移动探测器
    TRIPLE_TECHNOLOGY_PIR_DETECTOR, // 三技术探测器
    HUMIDITY_DETECTOR,              // 湿度探测器
    TEMPERATURE_DETECTOR,           // 温感探测器
    COMBUSTIBLE_GAS_DETECTOR,        // 可燃气体探测器
    OTHER_DETECTOR = 0xffff          // 其他探测器   
}DETECTOR_TYPE;

typedef struct tagNET_DVR_ALARMIN_PARAM
{
	DWORD   dwSize;
	BYTE    byName[NAME_LEN];
	WORD    wDetectorType; // DETECTOR_TYPE
	BYTE    byType;     // 防区报警类型 0-- 即时防区、1--24小时防区、2--延时防区
	BYTE    byRes1;    
	DWORD	dwParam;    // 防区参数  延时防区延时多长时间 
    NET_DVR_SCHEDTIME struAlarmTime[MAX_DAYS][MAX_TIMESEGMENT];/*布防时间时间段*/
	BYTE    byAssociateAlarmOut[MAX_ALARMHOST_ALARMOUT_NUM];  // 报警输入关联报警输出
    BYTE	byAssociateSirenOut[8];		//  警号输出 数组0 表示警号1 值为1表示输出 0 表示不输出
    BYTE    byRes[52];      // 保留字节
}NET_DVR_ALARMIN_PARAM, *LPNET_DVR_ALARMIN_PARAM;

typedef struct tagNET_DVR_ALARMOUT_PARAM
{
	DWORD   dwSize;             // 结构体大小
	BYTE    byName[NAME_LEN];   // 名称
	WORD    wDelay;             // 输出延迟 单位 s 0 表示一直有输出
	BYTE    byRes1[2];          // 保留字节
	BYTE    byAssociateAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];   //表示警号跟随的报警输入通道 （多个报警输入同时触发一个警号输出）数组下标0表示报警输入1，依次类推 0-不跟随 1-跟随
    BYTE    byRes2[60]; 
}NET_DVR_ALARMOUT_PARAM, *LPNET_DVR_ALARMOUT_PARAM;

typedef struct tagNET_DVR_ALARMIN_SETUP
{
    BYTE byAssiciateAlarmIn[MAX_ALARMHOST_ALARMIN_NUM];//报警输入通道 数组下标0对应报警输入口1，依次类推
    BYTE byRes[100];//保留字节
}NET_DVR_ALARMIN_SETUP, *LPNET_DVR_ALARMIN_SETUP;

typedef struct tagNET_DVR_ALARMHOST_MAIN_STATUS
{
	DWORD  dwSize; 
	BYTE   bySetupAlarmStatus[MAX_ALARMHOST_ALARMIN_NUM];//报警输入口布防状态，(最大支持512个报警输入口查询)，0-对应报警输入口处于撤防状态，1-对应报警输入口处于布防状态
	BYTE   byAlarmInStatus[MAX_ALARMHOST_ALARMIN_NUM];//报警输入口报警状态，(最大支持512个报警输入口查询)，0-对应报警输入口当前无报警，1-对应报警输入口当前有报警
	BYTE   byAlarmOutStatus[MAX_ALARMHOST_ALARMOUT_NUM];//报警输出口状态，(最大支持512个报警输出口查询)，0-对应报警输出口无报警，1-对应报警输出口有报警
    BYTE   byBypassStatus[MAX_ALARMHOST_ALARMIN_NUM];  // 旁路状态 数组下标表示0对应报警输入口1 0-表示报警输入口没有旁路 1-表示报警输入口旁路
	BYTE   byRes[600];      //  保留字节
}NET_DVR_ALARMHOST_MAIN_STATUS, *LPNET_DVR_ALARMHOST_MAIN_STATUS;

typedef struct tagNET_DVR_ALARMHOST_OTHER_STATUS
{
	DWORD  dwSize;
    BYTE   bySirenStatus[ALARMHOST_MAX_SIREN_NUM];    // 警号输出状态 0-警号处于无报警状态，1-警号处于有报警状态
    BYTE   byRes[92];             // 保留字节
}NET_DVR_ALARMHOST_OTHER_STATUS, *LPNET_DVR_ALARMHOST_OTHER_STATUS;


//使能状态配置
typedef struct tagNET_DVR_ALARMHOST_ENABLECFG
{
	DWORD dwSize;
	BYTE  byAudioOutEnable[ALARMHOST_MAX_AUDIOOUT_NUM];//语音输出使能，0-禁能，1-使能
	BYTE  byElectroLockEnable[ALARMHOST_MAX_ELECTROLOCK_NUM];//电锁使能，0-禁能，1-使能
	BYTE  byMobileGateEnable[ALARMHOST_MAX_MOBILEGATE_NUM];//移动门使能，0-禁能，1-使能
	BYTE  bySirenEnable[ALARMHOST_MAX_SIREN_NUM];//警号使能， 0-禁能，1-使能
	BYTE  bySerialPurpose;//串口用途，0-用于级联报警主机，1-用于PTZ控制
	BYTE  byRes[63];	
}NET_DVR_ALARMHOST_ENABLECFG, *LPNET_DVR_ALARMHOST_ENABLECFG;

typedef struct tagNET_DVR_ALARMHOST_ABILITY
{
	DWORD   dwSize;					  // 结构体大小
	WORD    wTotalAlarmInNum;         // 报警输入口总数(防区),包括级联
	WORD    wLocalAlarmInNum;         // 本地报警输入口
	WORD    wExpandAlarmInNum;        // 可扩展的报警输入口
	WORD    wTotalAlarmOutNum;        // 报警输出口总数 （设备支持的总数）
	WORD    wLocalAlarmOutNum;        // 本地报警输出口个数
	WORD    wExpandAlarmOutNum;       // 可扩展的报警输出口
	WORD    wTotalRs485Num;           // 报警输出口总数 （设备支持的总数）
	WORD    wLocalRs485Num;           // 本地485口数
	WORD    wExpandRs485Num;          // 可扩展的485口数
	WORD	wFullDuplexRs485Num;    // 全双工的485口数
	WORD    wTotalSensorNum;          // 模拟量最大个数 (设备支持的总数)
	WORD	wLocalSensorNum;		// 本地模拟量个数
	WORD    wExpandSensorNum;         // 可扩展的模拟量个数
	WORD    wAudioOutNum;			    //语音输出个数
	WORD    wGatewayNum;			//门禁个数
	WORD    wElectroLockNum;		    //电锁个数
	WORD    wSirenNum;     			// 主机警号数目
	WORD    wSubSystemNum;			// 可划分子系统数目
    WORD    wNetUserNum;            // 网络用户数
    WORD    wKeyboardUserNum;           // 键盘用户数
    WORD    wOperatorUserNum;           // 操作用户数
    WORD    byRes[86];				//  保留字节
}NET_DVR_ALARMHOST_ABILITY, *LPNET_DVR_ALARMHOST_ABILITY;


typedef struct tagNET_DVR_ALARM_RS485CFG
{
	DWORD   dwSize;                 // 结构体大小
	BYTE    sDeviceName[NAME_LEN];  // 前端设备名称 
	WORD    wDeviceType;            // 前端设备类型ALARM_FRONT_DEVICE _TYPE
	WORD    wDeviceProtocol;        // 前端设备协议 通过获取协议列表获取	
	DWORD   dwBaudRate;             //波特率(bps)，0-50，1-75，2-110，3-150，4-300，5-600，6-1200，7-2400，8-4800，9-9600，10-19200，11-38400，12-57600，13-76800，14-115.2k 
	BYTE    byDataBit;              // 数据有几位：0-5位，1-6位，2-7位，3-8位 
	BYTE    byStopBit;              // 停止位：0-1位，1-2位 
	BYTE    byParity;               //是否校验：0-无校验，1-奇校验，2-偶校验 
	BYTE    byFlowcontrol;           // 是否流控：0-无，1-软流控,2-硬流控 
	BYTE	byDuplex;				// 0 - 半双工1- 全双工  只有通道1可以是全双工其他都只能是半双工
    BYTE    byWorkMode;				// 工作模式 0-控制台 1-透明通道
    BYTE    byRes[38];              // 保留字节
}NET_DVR_ALARM_RS485CFG, *LPNET_DVR_ALARM_RS485CFG;

#define MAX_DEVICE_PROTO_NUM       256
#define MAX_DEVICE_TYPE_NUM			256

// 485前端设备支持协议列表
typedef struct tagNET_DVR_DEVICE_PROTO_LIST
{
    DWORD   dwSize;             // 结构体大小
    DWORD   dwProtoNum;         // 协议个数
    NET_DVR_PROTO_TYPE struProtoType[MAX_DEVICE_PROTO_NUM];  // 协议类型
    BYTE    byRes[12];          // 保留字节
}NET_DVR_DEVICE_PROTO_LIST, *LPNET_DVR_DEVICE_PROTO_LIST;

typedef struct tagNET_DVR_DEVICE_TYPE
{
	DWORD	dwType;
	BYTE	byDescribe[DESC_LEN];
}NET_DVR_DEVICE_TYPE, *LPNET_DVR_DEVICE_TYPE;

typedef struct tagNET_DVR_DEVICE_TYPE_LIST
{
	DWORD	dwSize;				// 结构体大小
	DWORD	dwTypeNum;			// 类型个数
	NET_DVR_DEVICE_TYPE struDeviceType[MAX_DEVICE_TYPE_NUM];
	BYTE	byRes[12];
}NET_DVR_DEVICE_TYPE_LIST, *LPNET_DVR_DEVICE_TYPE_LIST;

#define ALARMHOST_ABILITY     0x500 //网络报警主机能力集 


typedef struct tagNET_DVR_ALARM_DEVICE_USER
{
	DWORD  dwSize;                 // 结构体大小
	BYTE   sUserName[NAME_LEN];    // 用户名
	BYTE	sPassword[PASSWD_LEN];	// 密码
    NET_DVR_IPADDR	struUserIP;					/* 用户IP地址(为0时表示允许任何地址) */
    BYTE	byMACAddr[MACADDR_LEN];			/* 物理地址 */
    BYTE	    byUserType; // 0-普通用户 1-管理员用户
	BYTE   byAlarmOnRight;         // 布防权限
	BYTE   byAlarmOffRight;        // 撤防权限
	BYTE   byBypassRight;          // 旁路权限
	BYTE   byOtherRight[MAX_RIGHT];  // 其他权限
	// 数组0  日志权限
	// 数组1  重启关机
	// 数组2  参数设置权限
	// 数组3  参数获取权限
	// 数组4  恢复默认参数权限
	// 数组5  警号输出权限
	// 数组6  PTZ 控制权限(给矩阵使用) 
	// 数组7  远程升级权限
	BYTE	byRes2[200];              // 保留字节
}NET_DVR_ALARM_DEVICE_USER, *LPNET_DVR_ALARM_DEVICE_USER;

typedef struct tagNET_DVR_KEYBOARD_USER
{
	DWORD 	dwSize; 	// 结构体大小
	DWORD	dwID;		// 键盘用户ID
	BYTE	byDefanceArea[MAX_ALARMHOST_ALARMIN_NUM]; //防区权限  按数组下标表示 最大支持512个防区 0 - 无权限 1- 有权限
	BYTE	byRes[560];		// 保留字节
}NET_DVR_KEYBOARD_USER, *LPNET_DVR_KEYBOARD_USER;

typedef struct tagNET_DVR_OPERATE_USER
{
	DWORD	dwSize;		// 结构体大小
	BYTE    sUserName[NAME_LEN];    // 用户名
	BYTE    sPassword[PASSWD_LEN];  // 密码
	// 防区布防权限 最大支持512个防区 按数组下标表示 0 - 无权限 1 - 有权限
	BYTE    byAlarmOnArea[MAX_ALARMHOST_ALARMIN_NUM];   
	// 防区撤防权限 最大支持512个防区 按下标表示 0 - 无权限 1 - 有权限
	BYTE    byAlarmOffArea[MAX_ALARMHOST_ALARMIN_NUM];  
	// 防区旁路权限 最大支持512个防区 按下标表示 0 - 无权限 1 - 有权限
	BYTE    byBypassArea[MAX_ALARMHOST_ALARMIN_NUM];
	BYTE    byRes[560];             //  保留字节
}NET_DVR_OPERATE_USER, *LPNET_DVR_OPERATE_USER;

typedef struct tagNET_DVR_GATEWAY_CFG
{
    DWORD	dwSize;		// 结构体大小
    BYTE	byName[NAME_LEN];	//  门禁名称	
    BYTE	byEnable;	// 是否启用
    BYTE	byRes1;		// 保留字节
    WORD    wDelayTime;	// 开启延时时间	单位为秒0-65535 0为一直开启
    BYTE	byRes2[32];	// 保留字节
}NET_DVR_GATEWAY_CFG, *LPNET_DVR_GATEWAY_CFG;

typedef struct tagNET_DVR_SENSOR_ALARM
{
    DWORD   dwSize;		        // 结构体大小
    DWORD   dwAbsTime;	        // 绝对时标信息  OSD显示信息
    BYTE    byName[NAME_LEN]; 	// sensor 名称
    BYTE    bySensorChannel;    // 模拟量通道
    BYTE    byType;             // 模拟量类型
    BYTE	byAlarmType;	    // 1-上4、2-上3、3-上2、4-上1、5-下1、6-下2、7-下3、8-下4 和当前模式有关
                                // 例如当为1000时,有上1下1，2，3报警四种报警
    BYTE	byAlarmMode;        //报警模式，五种，-HHHH、-HHHL、-HHLL、HLLL、-LLLL， 作为平台报警程度判断功能 
    //即：1111（上上上上），1110（上上上下），1100（上上下下），1000(上下下下)，0000(下下下下)
    float	fValue;		        // 但前模拟量的值
    BYTE	byRes2[32];		    // 保留字节
}NET_DVR_SENSOR_ALARM, *LPNET_DVR_SENSOR_ALARM;

typedef struct 
{
    /*预留，目前报警主机的报警没有类型(布防网络序，监听主机序)*/
    DWORD  dwAlarmType;             
    /*数组0对应第1个输入端口*/
    BYTE   byAlarmInputNumber[MAX_ALARMHOST_ALARMIN_NUM];
    BYTE	byRes[160];
}NET_DVR_ALARMHOST_ALARMINFO,*LPNET_DVR_ALARMHOST_ALARMINFO;
// 开关量报警上传
typedef struct tagNET_DVR_SWITCH_ALARM
{
    DWORD dwSize;
    BYTE   byName[NAME_LEN]; 	// switch 名称
    WORD  wSwitchChannel;     // 开关量通道
    BYTE	byAlarmType;		// 报警类型 
    BYTE 	byRes[41];			// 保留字节
}NET_DVR_SWITCH_ALARM, *LPNET_DVR_SWITCH_ALARM;

typedef union tagNET_DVR_ALARMHOST_EXCEPTION_PARAM
{
    DWORD   dwUnionSize[20];        // 联合体大小    
}NET_DVR_ALARMHOST_EXCEPTION_PARAM, *LPNET_DVR_ALARMHOST_EXCEPTION_PARAM;

typedef struct tagNET_DVR_ALARMHOST_EXCEPTION_ALARM
{
    DWORD   dwSize;             // 结构体大小
    // 异常参数  1-设备防拆报警 2-设备防拆后后恢复正常 3-主电源掉电报警 4-主电源掉电后恢复正常 5-内部通信故障报警 
    // 6-内部通信故障后恢复正常  7-485外设线路断报警  8-外设线路断后恢复正常 9-自检失败报警  10-自检失败后恢复正常    
    DWORD   dwExceptionType;    
    NET_DVR_ALARMHOST_EXCEPTION_PARAM uExceptionParam;
    BYTE    byRes[16];          // 保留
}NET_DVR_ALARMHOST_EXCEPTION_ALARM, *LPNET_DVR_ALARMHOST_EXCEPTION_ALARM;

NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSetupAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostCloseAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_BypassAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_UnBypassAlarmChan(LONG lUserID, NET_DVR_ALARMIN_SETUP *lpInter);

NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostAssistantControl(LONG lUserID, DWORD dwType, DWORD dwNumber, DWORD dwCmdParam);

NET_DVR_API BOOL __stdcall NET_DVR_SetAirCondition(LONG lUserID, LONG l485Index, NET_DVR_AIR_CONDITION_PARAM* lpAirConditionParam);

NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceTypeList(LONG lUserID, NET_DVR_DEVICE_TYPE_LIST *lpDeviceTypeList);

NET_DVR_API BOOL __stdcall NET_DVR_GetDeviceProtoList(LONG lUserID, LONG lDeviceType, NET_DVR_DEVICE_PROTO_LIST *lpDeviceProtoList);

NET_DVR_API BOOL __stdcall NET_DVR_GetBatteryVoltage(LONG lUserID, float *pVoltage);

NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmDeviceUser(LONG lUserID, LONG lUserIndex, NET_DVR_ALARM_DEVICE_USER* lpDeviceUser);

NET_DVR_API BOOL __stdcall NET_DVR_GetAlarmDeviceUser(LONG lUserID, LONG lUserIndex, NET_DVR_ALARM_DEVICE_USER* lpDeviceUser);

NET_DVR_API BOOL __stdcall NET_DVR_SetKeyboardUser(LONG lUserID, LONG lUserIndex, NET_DVR_KEYBOARD_USER* lpKeyboardUser);

NET_DVR_API BOOL __stdcall NET_DVR_GetKeyboardUser(LONG lUserID, LONG lUserIndex, NET_DVR_KEYBOARD_USER* lpKeyboardUser);

NET_DVR_API BOOL __stdcall NET_DVR_SetOperateUser(LONG lUserID, LONG lUserIndex, NET_DVR_OPERATE_USER* lpOperateUser);

NET_DVR_API BOOL __stdcall NET_DVR_GetOperateUser(LONG lUserID, LONG lUserIndex, NET_DVR_OPERATE_USER* lpOperateUser);

NET_DVR_API BOOL __stdcall NET_DVR_ControlGateway(LONG lUserID, LONG lGatewayIndex, DWORD dwStaic);

/******************************************
函数:	NET_DVR_SetAlarmHostOut
描述:	设置报警输出(报警主机 报警板类)
输入:	lUserID NET_DVR_Login返回值 
        lAlarmOutPort 报警输出口索引 从1开始  0xffff表示全部报警输出口
        lAlarmOutStatic 报警输出状态，0－停止输出，1－输出
输出:	无
返回值: 成功-HPR_TRUE 失败-HPR_FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_SetAlarmHostOut(LONG lUserID, LONG lAlarmOutPort, LONG lAlarmOutStatic);

/******************************************
函数:	fAlarmHostSerialDataCallBack
描述:	建立透明通道回调函数指针
输入:	lSerialHandle NET_DVR_AlarmHostSerialStart返回值
		lPort 485口接收数据的槽位号 从1开始  232 该参数无效
		lDateType 数据类型 0-表示数据接收正常 1-表示通道不支持透明通道（针对485口）
		pRecvDataBuffer 存放数据的缓冲区指针
		pUser 用户数据
输出:	无
返回值: 无
******************************************/
typedef void(CALLBACK *fAlarmHostSerialDataCallBack)
(LONG lSerialHandle, LONG lPort, LONG lDateType, char *pRecvDataBuffer, DWORD  dwBufSize,void *pUser);

/******************************************
函数:	NET_DVR_AlarmHostSerialStart
描述:	和报警主机设备建立透明通道
输入:	lUserID NET_DVR_Login返回值
		lSerialType 建立透明通道类型  1 - 建立232通道 2 - 建立485通道
		cbSerialDataCallBack 指向fAlarmHostSerialDataCallBack函数指针，用于接收透明通道数据
		dwUser  用户数据
输出:	无
返回值: -1 表示失败 其他值作为NET_DVR_AlarmHostSerialSend等函数句柄
******************************************/
NET_DVR_API LONG __stdcall NET_DVR_AlarmHostSerialStart(LONG lUserID, LONG lSerialType, fAlarmHostSerialDataCallBack cbSerialDataCallBack, void *pUser);

/******************************************
函数:	NET_DVR_AlarmHostSerialSend
描述:	向透明通道指定的485口或者232口发送数据
输入:	lSerialHandle NET_DVR_AlarmHostSerialStart返回值
		lPort 当为485透明通道时使用，485口的槽位号，从1开始
		pSendBuf 指向发送数据缓冲区的指针
		dwBufSize 发送数据的大小
输出:	无
返回值: 成功-TURE 失败-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSerialSend(LONG lSerialHandle,LONG lPort,char *pSendBuf,DWORD dwBufSize);

/******************************************
函数:	NET_DVR_AlarmHostSerialStop
描述:	关闭透明通道
输入:	lSerialHandle NET_DVR_AlarmHostSerialStart返回值
输出:	无
返回值: 成功-TRUE 失败-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_AlarmHostSerialStop(LONG  lSerialHandle);

#define  MAX_PU_CHAN_NUM    512

typedef struct tagNET_DVR_PU_CHAN_INFO
{
    NET_DVR_IPADDR  struIpAddr;     // ip地址
    WORD            wPort;          // 端口
    WORD            wChannel;       // 通道     
    BYTE            byRes[24];      // 
}NET_DVR_PU_CHAN_INFO, *LPNET_DVR_PU_CHAN_INFO;

typedef struct tagNET_DVR_PU_CHAN_LIST
{
    DWORD   dwSize;     // 结构体
    DWORD   dwNum;      // 前端通道个数
    NET_DVR_PU_CHAN_INFO struPuChanInfo[MAX_PU_CHAN_NUM];
}NET_DVR_PU_CHAN_LIST, *LPNET_DVR_PU_CHAN_LIST;
/******************************************
函数:	NET_DVR_GetMatrixPuChan
描述:	获取视频综合平台Cam号和Mon号
输入:	lUserID NET_DVR_Login_V30返回值 
        lChanType   获取通道的类型 0-Cam号 1-Mon号
        lpChanList 指向NET_DVR_PU_CHAN_LIST结构指针
输出:	lpChanList 指向NET_DVR_PU_CHAN_LIST结构指针
返回值: 成功-TRUE 失败-FALSE
******************************************/
NET_DVR_API BOOL __stdcall NET_DVR_GetMatrixPuChan(LONG lUserID, LONG lChanType, NET_DVR_PU_CHAN_LIST* lpChanList);


#define  MAX_ALARM_CAM_NUM	32		// 报警触发CAM最大个数

typedef struct tagNET_DVR_PTZ_CTRL
{
	BYTE    byEnable;   // 是否启用PTZ控制
	BYTE    byType;     // PTZ 控制的类型 1- 预置点 2 -巡航  3-轨迹
	BYTE    byPtzNo;    //  ptz 控制的预置点 巡航 轨迹号
	BYTE    byRes[5];    // 保留字节
}NET_DVR_PTZ_CTRL, *LPNET_DVR_PTZ_CTRL;

typedef struct tagNET_DVR_ALARM_CAM_INFO
{
	DWORD			dwCamID;      // 触发的CAM通道操作
	DWORD           dwRecordTime;   // 触发录像时间 单位为s  -1表示一直录像 0 表示不录像
	DWORD           dwMonID;      // 触发Cam到Mon号显示
	DWORD           dwResidentTime; // 轮巡停留时间单位为s  -1表示一直停留 0 表示不停留
	NET_DVR_PTZ_CTRL    struPtzCtrl;    // PTZ控制信息
    BYTE			byAlarmOffMode;		// 报警切换上墙取消模式   0-立即取消，1-自动取消，2-手动取消 立即取消，报警取消时立即取消解码上墙   自动取消，报警取消时等待一定时间后取消解码上墙，我们约定是20秒  手动取消，用户通过手动的方式取消
    BYTE            byDevType;		// 当设备为智能设备时，生效表示智能报警设备取流源 1-解码卡	 2-编码卡
    BYTE            byDecChan;		// 当为解码通道为解码通道号
    BYTE            byRes[17];      // 保留字节
}NET_DVR_ALARM_CAM_INFO, *LPNET_DVR_ALARM_CAM_INFO;

typedef struct tagNET_DVR_ALARM_CAM_CFG
{
	DWORD		dwSize;			// 结构体大小
	BYTE        byEnable;       // 是否启用报警触发CAM联动 设备默认不启用
	BYTE        byRes[7];       // 保留字节
	DWORD		dwNum;			// 触发CAM联动的个数 即取数组的前几个有效处理  
	NET_DVR_ALARM_CAM_INFO struAlarmCam[MAX_ALARM_CAM_NUM];
}NET_DVR_ALARM_CAM_CFG, *LPNET_DVR_ALARM_CAM_CFG;

NET_DVR_API BOOL __stdcall NET_DVR_MatrixAlarmOffMonitor(LONG lUserID, DWORD dwMonID, DWORD dwCamID);

/************************************************************************/

//2010-12-28 高清解码卡能力集 begin
//新的解码卡服务器能力集
#define		MAX_DECODE_CARD_NUM			6   //最多高清解码卡数
/********************高清解码卡输出模式宏定义********************/
typedef enum _HD_DISPLAY_FORMAT
{
	HD_DISPLAY_FORMAT_INVALID = 0x00000000,
	HD_DISPLAY_FORMAT_CVBS = 0x00000001,
	HD_DISPLAY_FORMAT_DVI = 0x00000002,
	HD_DISPLAY_FORMAT_VGA = 0x00000004, 
	HD_DISPLAY_FORMAT_HDMI = 0x00000008, 
	HD_DISPLAY_FORMAT_YPbPr = 0x00000010
}HD_DISPLAY_FORMAT,*LPHD_DISPLAY_FORMAT;

/********************高清解码卡输出模式宏定义********************/
typedef struct tagNET_DVR_DECCARD_ABILITY      /*高清解码卡能力集*/
{
    BYTE byCardType;      //解码卡类型(0:MD,1:MD+,2:HD)
    BYTE byDecNums;      //解码通道数
    BYTE byDispNums;      //显示通道数
    BYTE byDecStartIdx;     //首个解码通道在所有解码通道中的索引
    BYTE byDispStartIdx;     //首个显示通道在所有显示通道中的索引
    BYTE byDispResolution[80]; //输出模式支持的分辨率
    BYTE byDispFormat[8];     //支持的输出模式(按HD_DISPLAY_FORMAT)
    BYTE byWindowMode[4][8]; //支持的窗口模式(比如1,2,4,9,16))
    BYTE byRes [35];
} NET_DVR_DECCARD_ABILITY,*LPNET_DVR_DECCARD_ABILITY;

typedef struct tagNET_DVR_DECODESVR_ABILITY
{
    DWORD dwSize;      /* 结构体大小 */
    BYTE byCardNums;      /* 解码卡数 */
    BYTE byStartChan;     /* 起始通道号 */
    BYTE byRes1[2];
    NET_DVR_DECCARD_ABILITY struDecCardAbility[MAX_DECODE_CARD_NUM];
	BYTE byRes2[64];
}NET_DVR_DECODESVR_ABILITY, *LPNET_DVR_DECODESVR_ABILITY;
#define DECODECARD_ABILITY 0x220 //解码卡服务器能力集
//2010-12-28 高清解码卡能力集 end

//2010-12-28
/*camera配置单元结构*/
typedef struct tagNET_DVR_MATRIX_CAMERACFG
{
    DWORD					dwGlobalIndex;//全局编号
    DWORD					dwInterIndex;//局部编号
	BYTE					sCamName[NAME_LEN];
    NET_DVR_PU_STREAM_CFG	struPuStreamCfg;
} NET_DVR_MATRIX_CAMERACFG,*LPNET_DVR_MATRIX_CAMERACFG;

typedef struct tagNET_DVR_MATRIX_CAMERALIST
{
	DWORD			dwSize;
	BYTE			byRes[12];
	DWORD			dwCamNum;//CAM数量
	BYTE  			*pBuffer;
	DWORD 			dwBufLen;//所分配指针长度，输入参数
} NET_DVR_MATRIX_CAMERALIST,*LPNET_DVR_MATRIX_CAMERALIST;
// 功能: 获取前端CAM列表信息
// 参数说明:
// lUserID: NET_DVR_Login()的返回值
// 			 lpCamListInfo：NET_DVR_MATRIX_CAMERALIST结构指针
// 			 返回值：
// TRUE表示成功,FALSE表示失败
NET_DVR_API BOOL __stdcall NET_DVR_GetCameraListInfo(LONG lUserID, DWORD dwCamNum, DWORD dwStartCam, LPNET_DVR_MATRIX_CAMERALIST lpCamListInfo);

typedef struct tagNET_DVR_DISP_CHAN_INFO
{
    NET_DVR_IPADDR	struIP;				/* 解码器 IP地址 */
    WORD 	wDVRPort;			 	/* 端口号 */
    BYTE 	byDispChannel;			/* 显示通道号 */
    BYTE	byRes[9];
    BYTE	sUserName[NAME_LEN];	/*登陆帐号 */
    BYTE	sPassword[PASSWD_LEN];	/*密码 */
}NET_DVR_DISP_CHAN_INFO,*LPNET_DVR_DISP_CHAN_INFO;

/*monitor配置单元结构*/
typedef struct tagNET_DVR_MATRIX_MONITORCFG
{
    DWORD						dwGlobalIndex;//全局编号
    DWORD						dwInterIndex;
	BYTE						sMonName[NAME_LEN];
    NET_DVR_DISP_CHAN_INFO		struDispChanCfg;
} NET_DVR_MATRIX_MONITORCFG,*LPNET_DVR_MATRIX_MONITORCFG;
typedef struct tagNET_DVR_MATRIX_MONITORLIST
{
    DWORD		dwSize;
	BYTE		byRes[12];
	DWORD		dwMonNum;//MON数量
	BYTE  		*pBuffer;
	DWORD 		dwBufLen;//所分配指针长度，输入参数
} NET_DVR_MATRIX_MONITORLIST,*LPNET_DVR_MATRIX_MONITORLIST;
// 功能: 获取MONITOR列表信息
// 参数说明:
// lUserID: NET_DVR_Login()的返回值
// 			 lpMonListInfo：NET_DVR_MATRIX_MONITORLIST结构指针
// 			 返回值：
// 			 TRUE表示成功,FALSE表示失败
NET_DVR_API BOOL __stdcall NET_DVR_GetMonitorListInfo(LONG lUserID, DWORD dwMonNum, DWORD dwStartMon, LPNET_DVR_MATRIX_MONITORLIST lpMonListInfo);

NET_DVR_API BOOL __stdcall NET_DVR_GetGlobalNum(LONG lUserID, DWORD *dwCamNum, DWORD *dwMonNum);



#define 	MAX_SUBMATRIX_NUM		8//级联中子最多从系统数量
typedef struct tagNET_DVR_SUBMATRIXINFO
{
	BYTE		byMainMatrix;//是否是主系统，1-是，0-否
	BYTE		bySubMatrixSequence;//级联子视频综合平台系统序号
	BYTE		byLoginType;//注册类型，1-直连，2-DNS，3-花生壳
	BYTE		byRes1[9];
	NET_DVR_IPADDR   struSubMatrixIP;		/*IP地址（可修改）*/
	WORD		wSubMatrixPort;        /*子系统端口号（可修改）*/
	BYTE		byRes2[6];
	NET_DVR_IPADDR   struSubMatrixIPMask;    /*IP地址掩码*/
	NET_DVR_IPADDR	struGatewayIpAddr;		 /* 网关地址 */    
	BYTE		sUserName[NAME_LEN];	/* 用户名 （此参数只能获取）*/
	BYTE		sPassword[PASSWD_LEN];	/*密码 （此参数只能获取）*/
	char		sDomainName[MAX_DOMAIN_NAME];//域名(可修改)
	char 		sDnsAddress[MAX_DOMAIN_NAME];/*DNS域名或IP地址*/
	BYTE		sSerialNumber[SERIALNO_LEN];//序列号（此参数只能获取）
	BYTE		byRes3[16];
}NET_DVR_SUBMATRIXINFO, *LPNET_DVR_SUBMATRIXINFO;

typedef struct tagNET_DVR_ALLUNITEDMATRIXINFO
{
	DWORD dwSize;
	NET_DVR_SUBMATRIXINFO struSubMatrixInfo[MAX_SUBMATRIX_NUM];
	BYTE  byRes2[32];
}NET_DVR_ALLUNITEDMATRIXINFO, *LPNET_DVR_ALLUNITEDMATRIXINFO;
		 
// 功能:获取视频综合平台级联配置
// 参数说明:
// lUserID: NET_DVR_Login()的返回值(78K)
// 			 lpInter：LPNET_DVR_ALLUNITEDMATRIXINFO结构
// 			 返回值：
// 			 TRUE表示成功,FALSE表示失败
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetUnitedMatrixInfo(LONG lUserID, LPNET_DVR_ALLUNITEDMATRIXINFO lpInter);

// 功能:设置视频综合平台级联配置
// 参数说明:
// lUserID: NET_DVR_Login()的返回值(78K)
// 			 lpInter：LPNET_DVR_ALLUNITEDMATRIXINFO结构
// 			 返回值：
// 			 TRUE表示成功,FALSE表示失败
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetUnitedMatrixInfo(LONG lUserID, LPNET_DVR_ALLUNITEDMATRIXINFO lpInter);

			 
#define	MAX_GATEWAYTRUNKNUM		1024 //级联视频综合平台中最大路由干线数
	 
typedef struct tagNET_DVR_MATRIXGATEWAYNOTE
{
	 WORD	wTrunkInToOutAbility;//干线带宽，按D1的标准衡量，如4表示支持4个D1
	 WORD	wTrunkOutToInAbility;//干线带宽，按D1的标准衡量，如4表示支持4个D1，双向光纤时用到此值
	 BYTE    byRes[4];
	 NET_DVR_MATRIXSUBSYSTEMINFO struInputNote;
	 NET_DVR_MATRIXSUBSYSTEMINFO struOutputNote;
}NET_DVR_MATRIXGATEWAYNOTE, *LPNET_DVR_MATRIXGATEWAYNOTE;

typedef struct tagNET_DVR_MATRIXGATEWAYINFO
{
	 DWORD dwSize;
	 NET_DVR_MATRIXGATEWAYNOTE struGatewayNote[MAX_GATEWAYTRUNKNUM];
	 BYTE  byRes [32];
}NET_DVR_MATRIXGATEWAYINFO, *LPNET_DVR_MATRIXGATEWAYINFO;
// 		 功能:获取视频综合平台路由配置
// 			 参数说明:
// lUserID: NET_DVR_Login()的返回值(78K)
// 			 lpInter：LPNET_DVR_MATRIXGATEWAYINFO结构
// 			 返回值：
// 			 TRUE表示成功,FALSE表示失败		 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetGatewayInfo(LONG lUserID, LPNET_DVR_MATRIXGATEWAYINFO lpInter);

// 			 功能:设置视频综合平台路由配置
// 			 参数说明:
// lUserID: NET_DVR_Login()的返回值(78K)
// 			 lpInter：LPNET_DVR_MATRIXGATEWAYINFO结构
// 			 返回值：
// 			 TRUE表示成功,FALSE表示失败			 
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetGatewayInfo(LONG lUserID, LPNET_DVR_MATRIXGATEWAYINFO lpInter);


typedef struct tagNET_DVR_MATRIXCODESYSTEMINFO
{
	 BYTE   byMatrixNum;//视频综合平台号
	 BYTE	bySubSystemNum;//子系统槽位号
	 BYTE	byChan;//编码通道
	 BYTE   byRes [13];
}NET_DVR_MATRIXCODESYSTEMINFO,*LPNET_DVR_MATRIXCODESYSTEMINFO;
typedef struct tagNET_DVR_MATRIXDECODESYSTEMINFO
{
	 BYTE    byMatrixNum;//视频综合平台号
	 BYTE	bySubSystemNum;//子系统槽位号
	 BYTE	byDispChan;//显示通道
	 BYTE	bySubDispChan;//显示通道子通道号
	 BYTE    byRes [12];
}NET_DVR_MATRIXDECODESYSTEMINFO,*LPNET_DVR_MATRIXDECODESYSTEMINFO;

typedef struct tagNET_DVR_MATRIXSWITCH
{
	 NET_DVR_MATRIXCODESYSTEMINFO struInputNote;
	 NET_DVR_MATRIXDECODESYSTEMINFO struOutputNote;
	 BYTE	byRes[32];
}NET_DVR_MATRIXSWITCH, *LPNET_DVR_MATRIXSWITCH;
// 		 功能:切换控制
// 			 参数说明:
// lUserID: NET_DVR_Login()的返回值(78K)
// 			 nSwitchMode：1-开始切换，2-停止切换
// 			 lpInter：LPNET_DVR_MATRIXSWITCH结构
// 			 返回值：
// 			 TRUE表示成功,FALSE表示失败
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSpanSwitch(LONG lUserID, BYTE nSwitchMode, LPNET_DVR_MATRIXSWITCH lpInter);

typedef enum {
	ENC_CARD = 0,
	DEC_CARD,
	SD_DEC_CARD,
	FPGA_CARD,
	CS_CARD,
	ALERTOR_CARD,
	NAT_0,
	NAT_1,
	VCA_CARD,
	VGA_DEC_CARD,
	VGA_ENC_CARD,
	ERR_CARD,
} DEV_TYPE;

typedef struct tagNET_DVR_MATRIXSWITCHCTRL
{
	DWORD dwCamId;//摄像机全局编号
	DWORD dwMonId;//监视器全局编号
	BYTE  bySubWindowNum;//监视器对应子窗口号
	/* 切换类型，0:正常切换，1:报警触发切换，2:报警取消，0xff:表示此MON上所有报警全部取消*/
	BYTE   bySwitchType;
	WORD   wAlarmType;//报警设备类型，1:报警主机，2：智能设备
	DWORD  dwResidentTime;/* 显示驻留时间，0xFFFFFFFF 时 为常驻情况，保持显示*/
	BYTE   byVcaDevType;//当报警设备类型是"智能设备"时，按DEV_TYPE类型
	BYTE   byRes[19];
}NET_DVR_MATRIXSWITCHCTRL, *LPNET_DVR_MATRIXSWITCHCTRL;
NET_DVR_API BOOL __stdcall NET_DVR_MatrixStartSwitch(LONG lUserID, LPNET_DVR_MATRIXSWITCHCTRL lpInter);


typedef struct tagNET_DVR_MATRIXDATABASE
{
	//配置文件类型，1-域数据库配置文件，2-子域数据库配置文件，3-平台数据库配置文件,0xff最后一次失败的数据库语句
	DWORD dwDevType; 
	DWORD dwParam; //参数，代表域号、子域号、平台号
	BYTE  byFileType;//文件类型，1-sql语句，2-db语句
	BYTE  byRes [3];
} NET_DVR_MATRIXDATABASE, *LPNET_DVR_MATRIXDATABASE;


// 功能:导入视频综合平台配置文件
// 参数说明:
// lUserID 
// [in] 用户ID号，NET_DVR_Login()或NET_DVR_Login_V30()的返回值 
// lpInter:
// [in] LPNET_DVR_MATRIXDATABASE结构
// sInBuffer 
// [in] 存放配置参数的缓冲区 
// dwInSize 
// [in] 缓冲区大小 
// 返回值：
// TRUE表示成功,FALSE表示失败
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetConfigFile(LONG lUserID, LPNET_DVR_MATRIXDATABASE lpInter, char *sInBuffer,  DWORD dwInSize);



// 功能:导出视频综合平台配置文件
// 参数说明:
// lUserID 
// [in] 用户ID号，NET_DVR_Login()或NET_DVR_Login_V30()的返回值
// lpInter:
// [in] LPNET_DVR_MATRIXDATABASE结构
// sOutBuffer 
// [out] 存放配置参数的缓冲区 
// dwOutSize 
// [in] 缓冲区大小 
// pReturnSize 
// [out] 实际获得的缓冲区大小 
// 返回值：
// TRUE表示成功,FALSE表示失败
// 注意：当sOutBuffer = NULL、dwOutSize = 0且pReturnSize != NULL时用于获取参数配置文件的所需的缓冲区长度；当sOutBuffer != NULL且dwOutSize != 0时用于获取参数配置文件的所需的缓冲区内容。
NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetConfigFile(LONG lUserID, LPNET_DVR_MATRIXDATABASE lpInter, char  *sOutBuffer,  DWORD   dwOutSize,  DWORD   *pReturnSize);
typedef struct tagNET_DVR_SUBSYSTEMINFO_V40
{
	/*子系统类型，1-解码用子系统，2-编码用子系统，3-级联输出子系统，4-级联输入子系统，5-码分器子系统，6-报警主机子系统，7-智能子系统，8-V6解码子系统，9-V6子系统，0-NULL（此参数只能获取）*/
	BYTE		bySubSystemType;
	//子系统通道数，对于码分子系统，代表485串口数量（此参数只能获取）
	BYTE		byChan;
	BYTE		byLoginType;//注册类型，1-直连，2-DNS，3-花生壳
	BYTE		bySlotNum ;//槽位号，此参数只能获取
    BYTE		byRes1[4];
	NET_DVR_IPADDR   struSubSystemIP;		/*IP地址（可修改）*/
		NET_DVR_IPADDR   struSubSystemIPMask;//子网掩码
	NET_DVR_IPADDR	struGatewayIpAddr;	/* 网关地址 */
	WORD		wSubSystemPort;        //子系统端口号（可修改）
	BYTE		byRes2[6];
    BYTE		sUserName[NAME_LEN];	/* 用户名 （此参数只能获取）*/
		BYTE		sPassword[PASSWD_LEN];	/*密码(可修改)*/
		char			sDomainName[MAX_DOMAIN_NAME];//域名(可修改)
	char 		sDnsAddress[MAX_DOMAIN_NAME];/*DNS域名或IP地址*/
	BYTE		sSerialNumber[SERIALNO_LEN];//序列号（此参数只能获取）
	BYTE		byRes3[60];
}NET_DVR_SUBSYSTEMINFO_V40, *LPNET_DVR_SUBSYSTEMINFO_V40;

#define  MAX_SUBSYSTEM_NUM_V40  120
typedef struct tagNET_DVR_ALLSUBSYSTEMINFO_V40
{
	DWORD dwSize;
	NET_DVR_SUBSYSTEMINFO_V40 struSubSystemInfo[MAX_SUBSYSTEM_NUM_V40];
	BYTE byRes[8];
}NET_DVR_ALLSUBSYSTEMINFO_V40, *LPNET_DVR_ALLSUBSYSTEMINFO_V40;

NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubSystemInfo_V40(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO_V40 lpInter);
NET_DVR_API BOOL __stdcall NET_DVR_MatrixSetSubSystemInfo_V40(LONG lUserID, LPNET_DVR_ALLSUBSYSTEMINFO_V40 lpInter);



typedef struct tagNET_DVR_SINGLESUBSYSTEMJOININFO_V40
{
	/*子系统类型，1-解码用子系统，2-编码用子系统，3-级联输出子系统，4-级联输入子系统，5-码分器子系统，6-报警主机子系统，7-智能子系统，8-V6解码子系统，9-V6子系统，0-NULL（此参数只能获取）*/
	BYTE	bySubSystemType; 
	BYTE	byConnectStatus;//级联系统关联状态，1-连接正常，2-连接断开
	BYTE   byMatrixNum;//级联视频综合平台号，子系统类型是3或4时可用
	BYTE	bySubSystemNum;//级联子系统槽位号，0~79，子系统类型是3或4时可用
	NET_DVR_DECSUBSYSTEMJIONSTATUS 
		struDecSub [MATRIX_MAXDECSUBSYSTEMCHAN];
	BYTE	byBindStatus;//绑定状态，0-没有绑定，1-已经绑定（大屏拼接时用到）
	BYTE	bySlotNum ;//槽位号，此参数只能获取
	BYTE  byRes[66];
}NET_DVR_SINGLESUBSYSTEMJOININFO_V40,LPNET_DVR_SINGLESUBSYSTEMJOININFO_V40;

typedef struct tagNET_DVR_ALLDECSUBSYSTEMJOININFO_V40
{
	DWORD dwSize;
	NET_DVR_SINGLESUBSYSTEMJOININFO_V40 struSingleSubSystemJoinInfo[MAX_SUBSYSTEM_NUM_V40];
	BYTE  byRes[48];
}NET_DVR_ALLDECSUBSYSTEMJOININFO_V40, *LPNET_DVR_ALLDECSUBSYSTEMJOININFO_V40;

NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetSubDecSystemJoinInfo_V40(LONG lUserID, LPNET_DVR_ALLDECSUBSYSTEMJOININFO_V40 lpInter);

#define  MAX_OPTICALFIBER_NUM  16
typedef struct tagNET_DVR_SUBSYSTEM_ABILITY
{
	/*子系统类型，1-解码用子系统，2-编码用子系统，3-级联输出子系统，4-级联输入子系统，5-码分器子系统，6-报警主机子系统，7-智能子系统，8-V6解码子系统，9-V6子系统，0-NULL（此参数只能获取）*/
	BYTE	bySubSystemType;
	BYTE   byChanNum;//子系统通道数
	BYTE  byStartChan;//子系统起始通道数
	BYTE	bySlotNum ;//槽位号 
	BYTE  byRes1[4];
	union
	{
		BYTE byRes[200];
		struct
		{
			BYTE  byVGANums;//VGA显示通道个数（从1开始）
			BYTE  byBNCNums;//BNC显示通道个数（从9开始）
			BYTE  byHDMINums;//HDMI显示通道个数（从25开始）
			BYTE  byDVINums;//DVI显示通道个数（从29开始）
			BYTE  byRes[196];
		}struDecoderSystemAbility;
		struct
		{
			BYTE  byCoderType;//编码器类型，0-标清，1-高清
			BYTE  byRes[199];
		}struCoderSystemAbility;
		struct
		{
			WORD	wTrunkAbility;//干线带宽，按D1的标准衡量，如4表示支持4个D1
			BYTE   byOpticalFiberNum;//光纤条数
			BYTE  byRes[197];
		}struInputSystemAbility;
		struct
		{
			WORD	wTrunkAbility;//干线带宽，按D1的标准衡量，如4表示支持4个D1
			BYTE   byOpticalFiberNum;//光纤条数
			BYTE  byRes[197];
		}struOutputSystemAbility;
		struct
		{
			BYTE	by485Num;//码分子系统中485数量
			BYTE	bySlotNum;//每个485槽位数
			BYTE  byRes[198];
		}struCodeSpitterSystemAbility;
		struct
		{
			WORD	wAlarmInNums;
			WORD	wAlarmOutNums;
			/* 标识报警盒是否连接， 1表示已连接， 为0 表示未连接 */
			BYTE  byAlarmBoxEnable[4][8];
			BYTE  byRes[164];
		}struAlarmHostSystemAbility;
		struct
		{
			BYTE  byOpticalFiberNum;//光纤条数
			BYTE  byRes1[3];
			//光纤带宽，按D1的标准衡量，如4表示支持4个D1
			WORD	wTrunkAbility[MAX_OPTICALFIBER_NUM/*16*/];
			BYTE  byRes2[164];
		}struInOutputSystemAbility;
	}struAbility;
}NET_DVR_SUBSYSTEM_ABILITY, *LPNET_DVR_SUBSYSTEM_ABILITY;

typedef struct tagNET_DVR_VIDEOPLATFORM_ABILITY_V40
{
    DWORD dwSize;
	BYTE  byCodeSubSystemNums;//编码子系统数量
	BYTE  byDecodeSubSystemNums;//解码子系统数量
	BYTE  bySupportNat;//是否支持NAT，0-不支持，1-支持
	BYTE  byInputSubSystemNums;//级联输入子系统数量
	BYTE	byOutputSubSystemNums;//级联输出子系统数量
	BYTE	byCodeSpitterSubSystemNums;//码分子系统数量
	BYTE	byAlarmHostSubSystemNums;//报警子系统数量
	BYTE	bySupportBigScreenNum;//所支持最多大屏拼接数量
	BYTE	byVCASubSystemNums;//智能子系统数量
	BYTE	byV6SubSystemNums;//V6子系统数量
	BYTE	byV6DecoderSubSystemNums;//V6解码子系统数量
	BYTE  byRes1[9];
	NET_DVR_SUBSYSTEM_ABILITY struSubSystemAbility[MAX_SUBSYSTEM_NUM_V40];
	BYTE	by485Nums;//485串口个数
	BYTE	by232Nums;//232串口个数
	BYTE	bySerieStartChan;//起始通道
    BYTE  byRes2[637];
}NET_DVR_VIDEOPLATFORM_ABILITY_V40, *LPNET_DVR_VIDEOPLATFORM_ABILITY_V40;
#define VIDEOPLATFORM_ABILITY_V40          0x230 //视频综合平台能力集

typedef struct tagNET_DVR_VIDEOPLATFORM_ABILITY
{
    DWORD dwSize;
	BYTE  byCodeSubSystemNums;//编码子系统数量
	BYTE  byDecodeSubSystemNums;//解码子系统数量
	BYTE  bySupportNat;//是否支持NAT，0-不支持，1-支持
    BYTE  byInputSubSystemNums;//级联输入子系统数量
    BYTE  byOutputSubSystemNums;//级联输出子系统数量
    BYTE  byCodeSpitterSubSystemNums;//码分子系统数量
    BYTE  byAlarmHostSubSystemNums;//报警子系统数量
    BYTE  bySupportBigScreenNum;//所支持最多大屏拼接数量
    BYTE  byVCASubSystemNums;//智能子系统数量
	BYTE  byRes1[11];   
	NET_DVR_SUBSYSTEM_ABILITY struSubSystemAbility[MAX_SUBSYSTEM_NUM];
    BYTE  by485Nums;//485串口个数
    BYTE  by232Nums;//485串口个数
    BYTE  bySerieStartChan;//起始通道
    BYTE  byRes2[637];    
}NET_DVR_VIDEOPLATFORM_ABILITY, *LPNET_DVR_VIDEOPLATFORM_ABILITY;
//获取能力集接口
#define VIDEOPLATFORM_ABILITY          0x210 //视频综合平台能力集

/*********************************9000 2.0 begin***************************************/

#define NET_DVR_GET_HOLIDAY_PARAM_CFG       1240        // 获取节假日参数
#define NET_DVR_SET_HOLIDAY_PARAM_CFG       1241        // 设置节假日参数

#define NET_DVR_GET_MOTION_HOLIDAY_HANDLE   1242        // 获取移动侦测假日报警处理方式
#define NET_DVR_SET_MOTION_HOLIDAY_HANDLE   1243        // 获取移动侦测假日报警处理方式

#define NET_DVR_GET_VILOST_HOLIDAY_HANDLE   1244        // 获取视频信号丢失假日报警处理方式
#define NET_DVR_SET_VILOST_HOLIDAY_HANDLE   1245        // 获取视频信号丢失假日报警处理方式

#define NET_DVR_GET_HIDE_HILIDAY_HANDLE     1246        // 获取遮盖假日报警处理方式
#define NET_DVR_SET_HIDE_HILIDAY_HANDLE     1247        // 设置遮盖假日报警处理方式

#define NET_DVR_GET_ALARMIN_HOLIDAY_HANDLE  1248        // 获取报警输入假日报警处理方式
#define NET_DVR_SET_ALARMIN_HOLIDAY_HANDLE  1249        // 设置报警输入假日报警处理方式

#define NET_DVR_GET_ALARMOUT_HOLIDAY_HANDLE 1250        // 获取报警输出假日报警处理方式
#define NET_DVR_SET_ALARMOUT_HOLIDAY_HANDLE 1251        // 设置报警输出假日报警处理方式

#define NET_DVR_GET_HOLIDAY_RECORD          1252        // 获取假日录像参数
#define NET_DVR_SET_HOLIDAY_RECORD          1253        // 设置假日录像参数

//  模式A 
typedef struct tagNET_DVR_HOLIDATE_MODEA
{
    BYTE    byStartMonth;	// 开始月 从1开始
    BYTE	byStartDay;		// 开始日 从1开始
    BYTE	byEndMonth;		// 结束月 
    BYTE	byEndDay;		// 结束日
    BYTE	byRes[4];		// 保留字节
}NET_DVR_HOLIDATE_MODEA, *LPNET_DVR_HOLIDATE_MODEA;

typedef struct tagNET_DVR_HOLIDATE_MODEB
{
    BYTE	byStartMonth;	// 从1开始
    BYTE	byStartWeekNum;	// 第几个星期 从1开始 
    BYTE	byStartWeekday;	// 星期几
    BYTE	byEndMonth;		// 从1开始
    BYTE	byEndWeekNum;	// 第几个星期 从1开始 
    BYTE	byEndWeekday;	// 星期几	
    BYTE	byRes[2];		// 保留字节 
}NET_DVR_HOLIDATE_MODEB, *LPNET_DVR_HOLIDATE_MODEB;

typedef struct tagNET_DVR_HOLIDATE_MODEC
{
    WORD	wStartYear;		// 年
    BYTE	byStartMon;		// 月
    BYTE	byStartDay;		// 日
    WORD	wEndYear;		// 年
    BYTE	byEndMon;		// 月
    BYTE	byEndDay;		// 日
}NET_DVR_HOLIDATE_MODEC, *LPNET_DVR_HOLIDATE_MODEC;

typedef union tagNET_DVR_HOLIDATE_UNION
{	
    // 联合体大小 12字节
    DWORD				    dwSize[3];
    NET_DVR_HOLIDATE_MODEA	struModeA;	// 模式A
    NET_DVR_HOLIDATE_MODEB	struModeB;	// 模式B
    NET_DVR_HOLIDATE_MODEC	struModeC;	// 模式C
}NET_DVR_HOLIDATE_UNION, *LPNET_DVR_HOLIDATE_UNION;

typedef enum tagHOLI_DATE_MODE
{
    HOLIDATE_MODEA = 0,
    HOLIDATE_MODEB,
    HOLIDATE_MODEC
}HOLI_DATE_MODE;

typedef struct tagNET_DVR_HOLIDAY_PARAM
{
    BYTE	byEnable;			// 是否启用
    BYTE	byDateMode;			// 日期模式 0-模式A 1-模式B 2-模式C
    BYTE	byRes1[2];			// 保留字节
    NET_DVR_HOLIDATE_UNION uHolidate;	// 假日日期
    BYTE	byName[NAME_LEN];	// 假日名称
    BYTE	byRes2[20];			// 保留字节
}NET_DVR_HOLIDAY_PARAM, *LPNET_DVR_HOLIDAY_PARAM;

#define  MAX_HOLIDAY_NUM	32

typedef struct tagNET_DVR_HOLIDAY_PARAM_CFG
{
    DWORD	dwSize;			// 结构体大小
    NET_DVR_HOLIDAY_PARAM struHolidayParam[MAX_HOLIDAY_NUM];	// 假日参数
    DWORD	byRes[40];		// 保留参数
}NET_DVR_HOLIDAY_PARAM_CFG, *LPNET_DVR_HOLIDAY_PARAM_CFG;

// 假日报警处理方式
typedef struct tagNET_DVR_HOLIDAY_HANDLE
{
    DWORD	dwSize;				// 结构体大小
    NET_DVR_SCHEDTIME              struAlarmTime[MAX_TIMESEGMENT_V30];	// 布防时间段
    BYTE	byRes2[240];		// 保留字节
}NET_DVR_HOLIDAY_HANDLE, *LPNET_DVR_HOLIDAY_HANDLE;

typedef struct tagNET_DVR_HOLIDAY_RECORD
{
    DWORD           dwSize;
    NET_DVR_RECORDDAY     struRecDay;     // 录像参数
    NET_DVR_RECORDSCHED   struRecordSched[MAX_TIMESEGMENT_V30]; // 录像时间段
    BYTE      byRes[20];      //  保留字节
}NET_DVR_HOLIDAY_RECORD, *LPNET_DVR_HOLIDAY_RECORD;
/*********************************9000 2.0 end***************************************/

typedef struct tagNET_DVR_ENCODE_JOINT_PARAM
{
    DWORD	dwSize;			// 结构体大小
    BYTE	byJointed;		//  0 没有关联 1 已经关联
    BYTE	byDevType;		// 被关联的设备类型  1 代表智能设备
    BYTE	byRes1[2];		// 保留字节
    NET_DVR_IPADDR	struIP;			// 关联的被取流设备IP地址
    WORD	wPort;			// 关联的被取流设备端口号
    WORD	wChannel;		// 关联的被取流设备通道号
    BYTE	byRes2[20];			// 保留字节
}NET_DVR_ENCODE_JOINT_PARAM, *LPNET_DVR_ENCODE_JOINT_PARAM;	


NET_DVR_API BOOL __stdcall NET_DVR_MatrixGetEncodeJoint(LONG lUserID, LONG lChannel, LPNET_DVR_ENCODE_JOINT_PARAM lpEncodeJoint);

typedef struct tagNET_DVR_VCA_CHAN_WORKSTATUS
{
    BYTE	byJointed;				// 0-没有关联  1-已经关联
    BYTE	byRes1[3];
    NET_DVR_IPADDR	struIP;					// 关联的取流设备IP地址
    WORD	wPort;					// 关联的取流设备端口号
    WORD	wChannel;				// 关联的取流设备通道号
    BYTE	byVcaChanStatus;		// 0 - 未启用 1 - 启用
    BYTE	byRes2[19];				// 保留字节
}NET_DVR_VCA_CHAN_WORKSTATUS, *LPNET_DVR_VCA_CHAN_WORKSTATUS;

typedef struct tagNET_DVR_VCA_DEV_WORKSTATUS
{
    DWORD	dwSize;			// 结构体大小
    BYTE	byDeviceStatus;	// 设备的状态0 - 正常工作 1- 不正常工作
    BYTE	byCpuLoad;		// CPU使用率0-100 分别代表使用百分率
    NET_DVR_VCA_CHAN_WORKSTATUS struVcaChanStatus[MAX_VCA_CHAN];
    DWORD	byRes[40];		// 保留字节
}NET_DVR_VCA_DEV_WORKSTATUS, *LPNET_DVR_VCA_DEV_WORKSTATUS;

NET_DVR_API BOOL __stdcall NET_DVR_GetVcaDevWorkState(LONG lUserID, LPNET_DVR_VCA_DEV_WORKSTATUS lpWorkState);

#endif //





















