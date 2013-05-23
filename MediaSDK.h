/*
 * MediaSDK.h
 *
 *  Created on: 2011-12-23
 *      Author: TianPeng 
 */

#ifndef MEDIASDK_H_
#define MEDIASDK_H_

#include <stdint.h>

typedef int (* PFGETDATACALL) (void* cbArgs, char* pData, int nSize);

int IPC_AddTranMediaSource(							//添加转发服务器上的摄像头,实现套接字连接，参数设置,返回流媒体句柄即 sockt号
				  char*	sHostIp,				//	转发服务器IP及端口
				  uint16_t	sHostPort,
				  char* cameraId,               //摄像头ID
					uint16_t		nStream,			//	码流类型		1:主码流,	 2: 次码流
					uint16_t		nDecoder,				//	解码器类型		1: H264, 2: MJPEG
				  uint16_t		nDefine					//	画面大小		1: 1980, 2: 1080; 3: 720
					);

int IPC_AddMediaSource(							//	添加直连摄像头, 实现套接字连接，参数设置,返回流媒体句柄即 sockt号
				  char*	sHostIp,				//	摄像机IP及端口
				  uint16_t	sHostPort,
					uint16_t		nStream,			//	码流类型		1:主码流,	 2: 次码流
					uint16_t		nDecoder,				//	解码器类型		1: H264, 2: MJPEG
				  uint16_t		nDefine					//	画面大小		1: 1980, 2: 1080; 3: 720
					);
int  IPC_RemoveMediaSource(uint16_t handle); //去除流媒体，关闭套接字连接

int IPC_StartTransmit(uint16_t handle); //开始传送

int IPC_StopTransmit(uint16_t handle);  //停止传送

int IPC_SetGetDataCB(uint16_t handle,PFGETDATACALL pfun, void* cbArgs); //回调函数用于交付数据，转存或转发

int IPC_SetGetDataCBRun(uint16_t handle, int flag); //启动回调函数线程

#endif /* MEDIASDK_H_ */
