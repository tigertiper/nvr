#ifndef _NVR_SRP_H_
#define _NVR_SRP_H_

#include"nvr.h"

unsigned int nvrproc_open(CMMNargs openargs);
unsigned int nvrproc_close(unsigned int camerid);
READres nvrproc_read(READargs readargs);
unsigned int nvrproc_write(WRITEargs writeargs);
HEADERinfo nvrproc_getheader(CMMNargs gethargs);
unsigned int nvrproc_create(CREATEargs createargs);
SEARCHres nvrproc_searchrecord(SEARCHargs searchargs);
unsigned int nvrproc_setrecinfo(SETRECINFOargs setrecinfoargs);
VOLUMinfo nvrproc_getvolumeinfo(unsigned int camerid);
unsigned int nvrproc_delete(DELargs delargs);
unsigned int nvrproc_login(LOGINargs loginargs);
int nvrproc_logout(unsigned int userid);
unsigned long nvrproc_getlasterror();
unsigned int nvrproc_getrecsize(GETRECSIZEargs getRecSizeArgs);
int nvrproc_creatrecvol(CREATRECVOLargs creatRecVolArgs);
int nvrproc_delrecvol(DELRECVOLargs delRecVolArgs);
RECORDBYORDERres nvrproc_searchrecordbyorder(RECORDBYORDERargs searchargs);
int nvrproc_delvedvol(DELVEDVOLargs delVedVolArgs);
void clearInactiveStreams();

#endif

