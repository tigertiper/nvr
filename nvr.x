/*nvr.x*/

const camerIDLEN = 256;
const  dataLEN = 1024;
const describeLEN = 1024;

/*@param: user login*/
struct LOGINargs{
	char ip[IPLEN];
	int port;
	char userName[userNameLEN];
	char pwd[pwdLEN];
};


/*@param: open record segment*/
struct CMMNargs{
	unsigned int loginID;
	char camerID[camerIDLEN];
	int recordType;
	unsigned int beginTime;
	unsigned int endTime;
	unsigned int mode; 
};


/*@param: read the data of record segment */
struct READargs{
	unsigned int playHandle;
	unsigned int readSize;
	unsigned int mode; 
};


/*@param: get information of record segment*/
typedef struct CMMNargs SEARCHargs;

/*@result: read data of record segment*/
struct READres{
	unsigned int dataLen;
	opaque data<>;
};

/*@param: get header information of record segment */
struct HEADERinfo{
    opaque data<>;
    unsigned int beginTime;
    unsigned int endTime;
    unsigned int nextBeginTime;
};
 
/*@result: get header information of record segment*/
struct SEARCHres{
	struct CMMNargs cmmnArgs;
	char describe[describeLEN];
	int describeLen;
	unsigned int nextBeginTime;
};

/*@param: create record segment*/
struct CREATEargs{
	unsigned int loginID;
	char camerID[camerIDLEN];
	char camerAlias[camerIDLEN];
	int recordType;
	opaque header<>;
	unsigned int headLen;
	char decribe[describeLEN];
	int decribeLen;
};

/*@param: write data to record segment*/
struct WRITEargs{
	unsigned int recordHandle;
	unsigned int dataLen;
	unsigned int beginTime;
	opaque data<>;
};

/*@param: delete record segment*/
typedef struct CMMNargs DELargs;

/*@param: get information of record volume*/
struct VOLUMinfo{
	unsigned int volSizeHigh;
	unsigned int volSizeLow;
	unsigned int usedSizeHigh;
	unsigned int usedSizeLow;
	int savedDays;
	int delPolicy;
	int encoderType;
	int resolusion;
	int datarate;
};


/*@param: modify information of record volume*/
typedef struct SEARCHres SETRECINFOargs;


program NVRPROG{
	version NVRVERS{
		unsigned int NVRPROC_OPEN(CMMNargs) = 1;
		unsigned int NVRPROC_CLOSE(unsigned int) = 2;
		READres NVRPROC_READ(READargs) = 3;
		unsigned int NVRPROC_WRITE(WRITEargs) = 4;
		HEADERinfo NVRPROC_GETHEADER(CMMNargs) = 5;
		unsigned int NVRPROC_CREATE(CREATEargs) = 6;
		SEARCHres NVRPROC_SEARCHRECORD(SEARCHargs) = 7;
		unsigned int NVRPROC_SETRECINFO(SETRECINFOargs) = 8;
		VOLUMinfo NVRPROC_GETVOLUMEINFO(unsigned int) = 9;
		unsigned int NVRPROC_DELETE(DELargs) = 10;
		unsigned int NVRPROC_LOGIN(LOGINargs) =11;
		int NVRPROC_LOGOUT(unsigned int) =12;
		unsigned long NVRPROC_GETLASTERROR() =13;
	} = 1;
} = 0x30090949;


