CC = gcc

PROGS = nvrd

NVRD_OBJ = rd_wr.o bitops_add.o util.o parms.o \
		   nvr_srp.o multi_stream.o syslog.o init.o
RPC_OBJ = nvr_svc.o nvr_sif.o nvr_xdr.o		   

CFLAGS += -g -pthread

LIBS = -lpthread

CONFIG = JYJ

ifeq ($(CONFIG), TAM)
	CFLAGS += -DTAM
#	CFLAGS += -DSPACE_TIME_SYNCHRONIZATION
#	CFLAGS += -DPARALLELRECORD 
#	CFLAGS += -DUPDATE
endif

ifeq ($(CONFIG), JYJ)
	CFLAGS += -DJYJ
	CFLAGS += -DSPACE_TIME_SYNCHRONIZATION
#	CFLAGS += -DPARALLELRECORD 
#	CFLAGS += -DUPDATE
endif

ifeq ($(CONFIG), NAR)
	CFLAGS += -DNAR
	CFLAGS += -DSPACE_TIME_SYNCHRONIZATION
#	CFLAGS += -DPARALLELRECORD 
#	CFLAGS += -DUPDATE
	CFLAGS += -DMEDIATRANSTORE
	LIBS += -Wl,-rpath,./lib -L./lib -lhcnetsdk -lhpr
	NVRD_OBJ += MediaTranStore.o MediaSDK.o
endif

all: ${PROGS}

${PROGS}:$(RPC_OBJ) $(NVRD_OBJ)
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}
	chmod 755 $@

${NVRD_OBJ}:%.o:%.c %.h info.h
	${CC} ${CFLAGS} -c $< -o $@

${RPC_OBJ}:%.o:%.c nvr.h
	${CC} ${CFLAGS} -c $< -o $@ 

.PHONY:clean clean_nvrd install

install: 
	@echo nothing to install

clean:
	-rm -f *.o ${PROGS}
	-rm -f *.out
	-rm -f tags

clean_nvrd:
	-rm ${NVRD_OBJ} ${PROGS}


