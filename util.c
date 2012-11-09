#include"info.h"
#define HASH_MASK 1023


int
buf_hash(char *name, int len)
{
	int retval = 0;

	while (len--) {
		retval = (retval + ((*name) >> 4) + ((*name) << 4)) * 11;
		name++;
	}

	retval = retval + (retval >> 6) + (retval >> 12);
	return retval & HASH_MASK;
}

inline void
_Debug(char *s, int line, char *file)
{
#ifdef DEBUG
	printf("file:%s Line:%d::%s", file, line, s);
#endif
}

int
_read(int fd, char *buf, int size, long long offset)
{
	if (lseek64(fd, offset, SEEK_SET) < 0) {
		return -1;
	}
	if (read(fd, buf, size) < 0) {
		return -1;
	}
	return 0;
}

int
_write(int fd, char *buf, int size, long long offset)
{
	if (lseek64(fd, offset, SEEK_SET) < 0) {
		return -1;
	}
	if (write(fd, buf, size) < 0) {
		return -1;
	}
	return 0;
}

int
__write(int fd, char *buf, int size, long long offset, pthread_mutex_t * mutex)
{
	int res = -1;
	pthread_mutex_lock(mutex);
	res = _write(fd, buf, size, offset);
	pthread_mutex_unlock(mutex);
	return res;
}
