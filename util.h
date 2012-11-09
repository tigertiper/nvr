#include<pthread.h>
#include<unistd.h>
#include<string.h>
#ifdef DEBUG
#include<stdio.h>
#endif
typedef pthread_mutex_t spin_lock_;
typedef pthread_rwlock_t spin_rwlock;
#define HASH_MASK 0x000001FF	//1023
/*
inline int spin_init(spin_lock_ spinlock);
inline int spin_lock(spin_lock_ spinlock);
inline int spin_trylock(spin_lock_ spinlock);
inline int spin_unlock(spin_lock_ spinlock);
inline int spin_destroy(spin_lock_ spinlock);
inline int spin_rwinit(spin_rwlock spinlock);
inline int spin_rdlock(spin_rwlock spinlock);
inline int spin_wrlock(spin_rwlock spinlock);
inline int spin_rwunlock(spin_rwlock spinlock);
inline int spin_trywrlock(spin_rwlock spinlock);
inline int spin_rwdestroy(spin_rwlock spinlock);*/


int buf_hash(char *name, int len);
inline void _Debug(char *s, int line, char *file);
int _read(int fd, char *buf, int size, unsigned long long offset);
int _write(int fd, char *buf, int size, unsigned long long offset);
int __write(int fd, char *buf, int size, unsigned long long offset,
	    pthread_mutex_t * mutex);
