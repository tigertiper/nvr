#ifndef _SYSLOG_H_
#define _SYSLOG_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define LOG_MAX_LEN	1024	/* syslog message's max length */

/* priorities */
#define	LOG_EMERG	0	/* system is unusable */
#define	LOG_ALERT	1	/* action must be taken immediately */
#define	LOG_CRIT	2	/* critical conditions */
#define	LOG_ERR		3	/* error conditions */
#define	LOG_WARNING	4	/* warning conditions */
#define	LOG_NOTICE	5	/* normal but significant condition */
#define	LOG_INFO	6	/* informational */
#define	LOG_DEBUG	7	/* debug-level messages */

/* arguments to setlogmask */
#define	LOG_MASK(pri)	(1 << (pri))		/* mask for one priority */
#define	LOG_UPTO(pri)	((1 << ((pri)+1)) - 1)	/* all priorities through pri */

/* option flags for openlog */
#define	LOG_PID		0x01	/* log the pid with each message */
#define	LOG_CONS	0x02	/* log on the console if errors in sending */
#define	LOG_ODELAY	0x04	/* delay open until first syslog() (default) */
#define	LOG_NDELAY	0x08	/* don't delay open */
#define	LOG_NOWAIT	0x10	/* don't wait for console forks: DEPRECATED */
#define	LOG_PERROR	0x20	/* log to stderr as well */

/* facility codes */
#define	LOG_KERN	(0<<3)
#define	LOG_USER	(1<<3)
#define	LOG_MAIL	(2<<3)
#define	LOG_DAEMON	(3<<3)
#define	LOG_AUTH	(4<<3)
#define	LOG_SYSLOG	(5<<3)
#define	LOG_LPR		(6<<3)
#define	LOG_NEWS	(7<<3)
#define	LOG_UUCP	(8<<3)
#define	LOG_CRON	(9<<3)
#define	LOG_AUTHPRIV	(10<<3)
#define	LOG_FTP		(11<<3)
#define	LOG_LOCAL0	(16<<3)
#define	LOG_LOCAL1	(17<<3)
#define	LOG_LOCAL2	(18<<3)
#define	LOG_LOCAL3	(19<<3)
#define	LOG_LOCAL4	(20<<3)
#define	LOG_LOCAL5	(21<<3)
#define	LOG_LOCAL6	(22<<3)
#define	LOG_LOCAL7	(23<<3)

#define	LOG_CONSOLE	LOG_LOCAL0	/* print on stdout */
#define	LOG_VARLOG	LOG_LOCAL1	/* logger to /var/log/xxx */

/**
 * @brief open syslog.
 * 
 * @param *ident (not use).
 * @param opt option flags for openlog.
 * @param fac facility code
 * 		LOG_LOCAL0 - logger to stdout
 * 		other - logger to file (/var/log/<program name>.log)
 * @return none
 */
void openlog(const char *ident, int opt, int fac);
void syslog(int pri, const char *fmt, ...);
void closelog();
int  setlogmask(int mask);

#ifdef __cplusplus
}
#endif

#endif	/* _SYSLOG_H_ */
