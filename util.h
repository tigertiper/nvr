#ifndef _UTIL_H
#define _UTIL_H

#include<pthread.h>
#include<unistd.h>
#include<string.h>

typedef pthread_mutex_t spin_lock_;
typedef pthread_rwlock_t spin_rwlock;
#define HASH_MASK 0x000001FF	//1023


int buf_hash(char *name, int len);
inline void _Debug(char *s, int line, char *file);
int _read(int fd, char *buf, int size, unsigned long long offset);
int _write(int fd, char *buf, int size, unsigned long long offset);
int __write(int fd, char *buf, int size, unsigned long long offset,
	    pthread_mutex_t * mutex);

#endif
