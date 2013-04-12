#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG_ALL          					0x0
#define _DEBUG_ALL			0xFFFFFFFF
#define	_DEBUG_HEAD			0x00000001
#define DEBUG_DETAIL 		0x00000002
#define DEBUG_FREQUENT_METHOD 		0x00000003
#define DEBUG_METHOD 		0x00000004
#define DEBUG_TASK 			0x00000008
#define	DEBUG_NORMAL		0x00000010
#define	DEBUG_LOG			0x00000020
#define DEBUG_WARNING 		0x00000040
#define DEBUG_ERROR	 		0x00000080
#define DEBUG_FATAL 		0x00000100

    
#ifdef __DEBUG
#define TRACE(LEVEL, FORMAT, ARG...)    if((LEVEL)>=TRACE_LEVEL) \
    printf("[%d] %s %d %s \n" FORMAT "\n", LEVEL, __FILE__, __LINE__, __func__,
##ARG);
#endif				/*  */

extern int debug_level;

#ifdef __KERNEL__
	#include <linux/delay.h>
	#include <asm/atomic.h>
	#define _PRINT_ 	printk
#else
	#include <stdio.h>
	#include <syslog.h>
	#include <string.h>
	#define _PRINT_ 	printf
#endif

#define PRINT _PRINT_

#define	PRINT_HEAD(LEVEL) \
	do { \
		if( debug_level  & _DEBUG_HEAD ){ \
			PRINT("[%d] %s %d %s() \n\t", LEVEL, __FILE__,__LINE__,__func__); \
		} \
	}while(0)
	
#define	PRINT_LN(FORMAT, ARG...) \
	do { \
		PRINT(FORMAT, ##ARG); 	\
	}while(0) 

#define TRACE(LEVEL, FORMAT, ARG...)    \
	do{ \
		if((~debug_level) & LEVEL ) { \
			PRINT_HEAD(LEVEL);	\
			PRINT_LN(FORMAT, ##ARG);	\
		} \
	}while(0) 

#define	TRACE_WARNNING(FORMAT, ARG...)  \
	do{ \
		if( debug_level & DEBUG_WARNING)  {	\
			PRINT("##Warnning##");  \
			PRINT_HEAD(DEBUG_WARNING);	\
			PRINT_LN(FORMAT, ##ARG);	 \
		} \
	}while(0)

#define	TRACE_ERROR(FORMAT, ARG...)  \
	do{ \
		if( debug_level & DEBUG_ERROR)  {	\
			PRINT("###ERROR###");	 \
			PRINT_HEAD(DEBUG_ERROR);	\
			PRINT_LN(FORMAT, ##ARG);	 \
		} \
		openlog(__FILE__, LOG_PID, LOG_USER); \
		syslog(LOG_ERR, "[%d]%s(): "FORMAT,__LINE__,__func__,##ARG);	\
		closelog(); \
	}while(0)
	
#define	TRACE_PERROR(FORMAT, ARG...)  \
	do{ \
		if( debug_level & DEBUG_ERROR)  {	\
			PRINT("###ERROR###");	 \
			PRINT_HEAD(DEBUG_ERROR);	\
			perror(":"); \
			PRINT_LN(FORMAT, ##ARG);	 \
		} \
		openlog(__FILE__, LOG_PID, LOG_USER); \
		syslog(LOG_ERR, "[%d]%s() %s:"FORMAT,  __LINE__,__func__,strerror(errno),##ARG);	\
		closelog(); \
	}while(0)

//added by wsr 20121030
#define	TRACE_LOG(FORMAT, ARG...)  \
	do{ \
		if( debug_level <= DEBUG_LOG)  { \
			PRINT_HEAD(DEBUG_LOG);	\
			PRINT_LN(FORMAT, ##ARG);	 \
			syslog(LOG_NOTICE, "[%d]%s(): "FORMAT,__LINE__,__func__,##ARG);	\
		}\
	}while(0)

/*
added by wsr 20121030
#define	TRACE_LOG(FORMAT, ARG...)  \
	do{ \
		PRINT_HEAD(DEBUG_LOG);	\
		PRINT_LN(FORMAT, ##ARG);	 \
		openlog(__FILE__, LOG_PID, LOG_USER); \
		syslog(LOG_NOTICE, "[%d]%s(): "FORMAT,__LINE__,__func__,##ARG);	\
		closelog(); \
	}while(0)

*/
//end

extern int trace_enter_count ;

#define	TRACE_ENTER(FORMAT, ARG...)  \
	do{ \
		if( debug_level <= DEBUG_METHOD)  {	\
			trace_enter_count++; \
			int i = 0; \
			for(i=0; i<trace_enter_count; i++) { PRINT(">");}\
			PRINT_LN("ENTER %s(){",  __func__);	 \
		} \
	}while(0)

#define	TRACE_LEAVE(FORMAT, ARG...)  \
	do{ \
		if( debug_level <= DEBUG_METHOD)  {	\
			int i = 0; \
			for(i=0; i<trace_enter_count; i++) { PRINT("<");}\
			PRINT_LN("}LEAVE %s()",  __func__);	 \
			trace_enter_count--; \
		} \
	}while(0)
	


#endif


	   
