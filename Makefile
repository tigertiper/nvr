#nvr

#CC = g++
CC = gcc

SRC = nvr.c nvr_sdk.c nvr_cif.c nvr_clnt.c nvr_sif.c nvr_srp.c nvr_svc.c nvr.x

PROGS = nvrd

NVR_GFILES = nvr_clnt.c nvr_cif.c nvr_sdk.c nvr_test.c nvr.h nvr_sdk.h nvr_common.h Debug.h

NVRD_GFILES = nvr_svc.c nvr_sif.c nvr_srp.c nvr.h multi_stream.c 

NVR_OBJ =  nvr_clnt.o nvr_cif.o nvr_test.o nvr_sdk.o
NVRD_OBJ = nvr_svc.o nvr_sif.o nvr_srp.o multi_stream.o

DEVICE_OBJ = rd_wr.o bitops_add.o util.o parms.o
#	cc  -o ves  -g -DDebug  rd_wr.o bitops_add.o parms.o util.o  init.o -pthread


all: ${PROGS}

nvr:${NVR_OBJ} nvr_xdr.o
	${CC} -g ${CFLAGS} -o $@ ${NVR_OBJ} nvr_xdr.o -lpthread
	chmod 755 nvr

${NVR_OBJ}:${NVR_GFILES} nvr_xdr.c
	${CC} -g ${CFLAGS} -c $*.c nvr_xdr.c
	
nvrd:$(NVRD_OBJ) nvr_xdr.o ${DEVICE_OBJ}
	${CC} -g ${CFLAGS} -o $@ ${NVRD_OBJ} nvr_xdr.o ${DEVICE_OBJ} -lpthread
	chmod 755 nvrd

${NVRD_OBJ}:${NVRD_GFILES} nvr_xdr.c
	${CC} -g ${CFLAGS} -c $*.c nvr_xdr.c 


bitops_add.o:bitops_add.c bitops_add.h
	cc -c  bitops_add.c 
util.o:util.c util.h 
	cc -g -c util.c -pthread
parms.o:parms.c info.h
	cc  -g -c  parms.c -pthread
#init.o:init.c  init.h
#	cc -g -c  init.c -pthread
rd_wr.o:rd_wr.c rd_wr.h
	cc  -g  -c rd_wr.c -pthread

nvr.h: nvr.x
	rpcgen nvr.x



.PHONY:clean clean_nvr clean_nvrd install

install: 
	@echo nothing to install

clean:
	-rm *.o ${PROGS}
	
clean_nvr:
	-rm ${NVR_OBJ} nvr
	
clean_nvrd:
	-rm ${NVRD_OBJ} nvrd


