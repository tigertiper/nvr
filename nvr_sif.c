#include <rpc/rpc.h>

#define PRC_SVC

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "nvr.h"
#include "nvr_srp.h"

unsigned int *
nvrproc_open_1_svc(CMMNargs * openargs, struct svc_req *rpstp)
{
	static unsigned int retcode;
	retcode = nvrproc_open(*(CMMNargs *) openargs);
	return &retcode;
}

unsigned int *
nvrproc_close_1_svc(unsigned int *camerid, struct svc_req *rpstp)
{
	static unsigned int retcode;
	retcode = nvrproc_close(*(unsigned int *)camerid);
	return &retcode;
}

READres *
nvrproc_read_1_svc(READargs * readargs, struct svc_req * rpstp)
{
	static READres res;
	res = nvrproc_read(*(READargs *) readargs);
	return &res;
}

unsigned int *
nvrproc_write_1_svc(WRITEargs * writeargs, struct svc_req *rpstp)
{
	static unsigned int retcode;
	retcode = nvrproc_write(*(WRITEargs *) writeargs);
	return &retcode;
}

HEADERinfo *
nvrproc_getheader_1_svc(CMMNargs * gethargs, struct svc_req * rpstp)
{
	static HEADERinfo retcode;
	retcode = nvrproc_getheader(*(CMMNargs *) gethargs);
	return &retcode;
}

unsigned int *
nvrproc_create_1_svc(CREATEargs * createargs, struct svc_req *rpstp)
{
	static unsigned int retcode;
	retcode = nvrproc_create(*(CREATEargs *) createargs);
	return &retcode;
}

SEARCHres *
nvrproc_searchrecord_1_svc(SEARCHargs * searchargs, struct svc_req * rpstp)
{
	static SEARCHres retcode;
	retcode = nvrproc_searchrecord(*searchargs);
	return &retcode;
}

unsigned int *
nvrproc_setrecinfo_1_svc(SETRECINFOargs * setrecinfoargs, struct svc_req *rpstp)
{
	static unsigned int retcode;
	retcode = nvrproc_setrecinfo(*(SETRECINFOargs *) setrecinfoargs);
	return &retcode;
}

VOLUMinfo *
nvrproc_getvolumeinfo_1_svc(unsigned int *camerid, struct svc_req * rpstp)
{
	static VOLUMinfo retcode;
	retcode = nvrproc_getvolumeinfo(*(unsigned int *)camerid);
	return &retcode;
}

unsigned int *
nvrproc_delete_1_svc(DELargs * delargs, struct svc_req *rpstp)
{
	static unsigned int retcode;
	retcode = nvrproc_delete(*(DELargs *) delargs);
	return &retcode;
}

unsigned int *
nvrproc_login_1_svc(LOGINargs * loginargs, struct svc_req *rpstp)
{
	static unsigned int retcode;
	retcode = nvrproc_login(*(LOGINargs *) loginargs);
	return &retcode;
}

int *
nvrproc_logout_1_svc(unsigned int *userid, struct svc_req *rpstp)
{
	static int retcode;
	retcode = nvrproc_logout(*(unsigned int *)userid);
	return &retcode;
}

unsigned long *
nvrproc_getlasterror_1_svc(void *va, struct svc_req *rpstp)
{
	static unsigned long retcode;
	retcode = nvrproc_getlasterror();
	return &retcode;
}

unsigned int *
nvrproc_getrecsize_1_svc(GETRECSIZEargs * getRecSizeArgs, struct svc_req *rpstp)
{
	static unsigned int retcode;
	retcode = nvrproc_getrecsize(*(GETRECSIZEargs *) getRecSizeArgs);
	return &retcode;
}

int *
nvrproc_creatrecvol_1_svc(CREATRECVOLargs * creatRecVolArgs, struct svc_req *rpstp)
{
	static int retcode;
	retcode = nvrproc_creatrecvol(*(CREATRECVOLargs *) creatRecVolArgs);
	return &retcode;
}

int *
nvrproc_delrecvol_1_svc(DELRECVOLargs * delRecVolArgs, struct svc_req *rpstp)
{
	static int retcode;
	retcode = nvrproc_delrecvol(*(DELRECVOLargs *) delRecVolArgs);
	return &retcode;
}

RECORDBYORDERres* 
nvrproc_searchrecordbyorder_1_svc(RECORDBYORDERargs* recordByOrderargs , struct svc_req *rpstp)
{
	static RECORDBYORDERres retrecord;
	retrecord = nvrproc_searchrecordbyorder(*(RECORDBYORDERargs*) recordByOrderargs);
	return &retrecord;
}

int *
nvrproc_delvedvol_1_svc(DELVEDVOLargs * delVedVolArgs, struct svc_req *rpstp)
{
	static int retcode;
	retcode = nvrproc_delvedvol(*(DELVEDVOLargs *) delVedVolArgs);
	return &retcode;
}

