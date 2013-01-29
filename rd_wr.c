#include<string.h>
#include<unistd.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include"rd_wr.h"
#include"multi_stream.h"
#include"Debug.h"
unsigned long long InitFlag = 0;
#define  _TLEN(v)         ((v->savedDays*24*60*60)/(TimeBuffSize))
#define _FISTTIMESIZE(v)    TimeBuffSize
#define _Maxtime(v)       (v->savedDays*24*60*60)
#define _TimeBuffSize(v)  TimeBuffSize
#define address_of_pointer(x) (long)((void*)x)


CameraInfo* CameraInfos = NULL; 

//#define RandBase 200*1024     //for test


int
get_vnode(_sbinfo sbinfo, vnode * v, int ID)
{
	int fd1;
	char buf[Vnode_SIZE];
	pthread_mutex_lock(&sbinfo->mutex);
	if ((fd1 = open(sbinfo->volName, O_RDONLY)) < 0) {
		ErrorFlag = OPEN_FILE_ERR;
		pthread_mutex_unlock(&sbinfo->mutex);
		return -1;
	}
	pthread_mutex_unlock(&sbinfo->mutex);
	if (_read(fd1, buf, Vnode_SIZE, VnodeAddr + ID * Vnode_SIZE) < 0) {
		close(fd1);
		ErrorFlag = READ_LVM_ERR;
		return -1;
	}
	buf_to_vnode(buf, v);
	close(fd1);
	return 0;
}



inline int
get_bitmap(int fd, _sbinfo sbinfo)
{				//读取逻辑卷的bitmap。
	return _read(fd, sbinfo->bitmap, MaxBlocks, BitmapAddr);

}

/*
在内存中申请一个缓冲区，用于读写。
每读一路视频时，分配一个node，这个node从缓存池中分配。
sbinfo->_bh为bfHead结构体，用于管理这个缓冲区，
sbinfo->_bf指向这个缓冲区。
*/
int
get_buf(_sbinfo sbinfo)
{
	int size;
	if ((sbinfo->_bh = (bfHead) malloc(sizeof(struct bufferHead))) == NULL) {
		ErrorFlag = MALLOC_ERR;
		return -1;
	}
	size = (sizeof(struct vnodeInfo)) * BuffNodeNum;
	//初始化bfHead结构体。
	memset(sbinfo->_bh->map, 0, MaxBufBitmapLen);
	//   spin_rwinit(sbinfo->_bh->spin);
	pthread_rwlock_init(&sbinfo->_bh->spin, NULL);
	if ((sbinfo->_bf = malloc(size)) == NULL) {
		ErrorFlag = MALLOC_ERR;
		spin_rwdestroy(sbinfo->_bh->spin);
		free(sbinfo->_bh);
		return -1;
	}
	return 0;
}

int
vnodes_build(_sbinfo sbinfo)
{				//根据硬盘结构信息，建立vnode内存结构
	int i = 0;
	int fd1;
	char *buf;
	vnode *v;
	pthread_mutex_lock(&sbinfo->mutex);
	if ((fd1 = open(sbinfo->volName, O_RDWR)) < 0) {
		ErrorFlag = OPEN_FILE_ERR;
		pthread_mutex_unlock(&sbinfo->mutex);
		goto err;
	}
	pthread_mutex_unlock(&sbinfo->mutex);
	if ((buf = malloc(Vnode_SIZE * MaxUsers)) == NULL) {
		ErrorFlag = MALLOC_ERR;
		close(fd1);
		goto err;
	}
	if (_read(fd1, buf, Vnode_SIZE * MaxUsers, VnodeAddr) < 0) {
		ErrorFlag = READ_LVM_ERR;
		goto err1;
	}
	if (get_buf(sbinfo) < 0) {
		goto err1;
	}
	while (i < MaxUsers) {
		if (bit(sbinfo->vnodemapping, i)) {	//有vnode
			v = (vnode *) (sbinfo->vnodeTable + i * sizeof(vnode));
			buf_to_vnode(buf + i * Vnode_SIZE, v);
		}
		i++;
	}			//end while(i<MaxUsers)?
	close(fd1);
	free(buf);
	return 0;
      err1:
	free(buf);
	close(fd1);
      err:
	return -1;
}

inline int
get_vbitmap(int fd, _sbinfo sbinfo)
{				//从逻辑卷中读取vbitmap
	return _read(fd, sbinfo->vnodemapping, MaxUsers / 8, VBitmapAddr);
}

/*
   建立逻辑卷的内存结构，围绕sbinfo结构进行。
*/
int
men_build(SBlock * sb, _sbinfo sbinfo, char *volname, int flag)
{				//flag==0,表示硬盘结构未建立。flag＝＝1或者其他,表示已经建立
	int fd;
	sbinfo->_es = sb;	//指向超级块
	memcpy(sbinfo->volName, volname, VolNameLength);	//拷贝逻辑卷名字
	if ((sbinfo->bitmap = malloc(sizeof(char) * (MaxBlocks + MaxUsers / 8))) == NULL) {	//将bitmap和vbitmap的空间一起申请。
		ErrorFlag = MALLOC_ERR;
		goto err1;
	}
	
	sbinfo->vnodemapping = sbinfo->bitmap + MaxBlocks;
	if ((sbinfo->vnodeTable = (char *)malloc(sizeof(vnode) * MaxUsers)) == NULL) {	//申请vnode的缓存
		ErrorFlag = MALLOC_ERR;
		goto err2;
	}

	if (flag == 0) {	//硬盘结构没有建立，就需要初始化硬盘，把superblock，bitmap和vbitmap写回逻辑卷
		memset(sbinfo->bitmap, 0, (uint32_t) (MaxBlocks + MaxUsers / 8));	//将bitmap和vbitmap全部清零
		if (put_sb(sbinfo, NULL))	//将superblock和bitmap写回
			goto err3;
		if (put_vnode(sbinfo, NULL, sbinfo->vnodemapping, -1) < 0)
			goto err3;
		if (get_buf(sbinfo) < 0)
			goto err3;
	}			//end if(flag==0)?
	else {
		pthread_mutex_lock(&sbinfo->mutex);
		if ((fd = open(sbinfo->volName, O_RDONLY)) < 0) {
			pthread_mutex_unlock(&sbinfo->mutex);
			ErrorFlag = OPEN_FILE_ERR;
			goto err3;
		}
		pthread_mutex_unlock(&sbinfo->mutex);
		if (get_bitmap(fd, sbinfo) < 0) {
			ErrorFlag = READ_LVM_ERR;
			close(fd);
			goto err3;
		}
		if (get_vbitmap(fd, sbinfo) < 0) {
			close(fd);
			ErrorFlag = READ_LVM_ERR;
			goto err3;
		}
		close(fd);
		if (vnodes_build(sbinfo) < 0)
			goto err3;
	}			//end else?
	return 0;
      err3:
	free(sbinfo->vnodeTable);
      err2:
	free(sbinfo->bitmap);
      err1:
	return -1;
}

int
is_vedio_LVM(const char *Volpath, SBlock * sb)
{
	int fd1;
	char buf[SB_SIZE];
	// SBlock * sb;
	/*if((sb=malloc(sizeof(SBlock)))<0){
	   ErrorFlag=MALLOC_ERR;
	   return -1;
	   } */
	if ((fd1 = open(Volpath, O_RDONLY)) < 0) {
		ErrorFlag = OPEN_FILE_ERR;
		goto err;
	}
	if (_read(fd1, buf, SB_SIZE, 0) < 0) {
		ErrorFlag = READ_LVM_ERR;
		goto err;
	}
	buf_to_sb(buf, sb);
	sb->mTime = time(NULL);
	close(fd1);
	if (sb->magic != MAGIC || (strcmp(sb->fileSystemName, FILE_SYS_NAME) != 0)) {
		// free(sb);
		return 0;
	} else {
		// free(sb);
		return 1;
	}
      err:
// free(sb);
	close(fd1);
	return 0;
}


_sbinfo
init(const char *volume_path)
{
	//fb firstblock
	_initInfo *info;
	SBlock *sb;
	_sbinfo sbinfo;
	int i, m = 0;
	if (!InitFlag) {
		for (i = 0; i < LvmCount; i++)
			sbTable.table[i] = NULL;	//初始化SBtable
		spin_rwinit(sbTable.spin);
		InitFlag = 1;
	}
	if ((info = malloc(sizeof(_initInfo))) == NULL) {
		ErrorFlag = MALLOC_ERR;
		goto err;
	}
	strcpy(info->volName, volume_path);
	strcpy(info->fileSystemName, FILE_SYS_NAME);
	info->mode = 1;
	if ((sb = malloc(sizeof(SBlock))) == NULL) {	//申请超级块内存
		ErrorFlag = MALLOC_ERR;
		goto err1;
	}			//end if？
	if (!is_vedio_LVM(info->volName, sb)) {
		free(sb);
		goto err1;
	}
	//  info->size=get_lv_size(info->volName);

	if ((sbinfo = malloc(sizeof(struct sbInfo))) == NULL) {	//申请超级块信息内存
		ErrorFlag = MALLOC_ERR;
		free(sb);
		goto err1;
	}			//end if？
	//added by wsr 20121029
	//memset(&sbinfo, 0, sizeof(struct sbInfo));
	//end
	pthread_mutex_init(&sbinfo->mutex, NULL);
	/*  
	   将超级块信息sbinfo保存在全局链表和table数组中
	 */
	if (!spin_wrlock(sbTable.spin)) {	//加锁
		while (m < LvmCount && sbTable.table[m])
			m++;
		if (m >= LvmCount) {
			spin_rwunlock(sbTable.spin);
			ErrorFlag = MAX_LVM_COUNT;
			goto err3;
		}
		sbTable.table[m] = sbinfo;
		spin_rwunlock(sbTable.spin);	//解锁
	} else {
		ErrorFlag = CREATING_LVM;
		goto err3;
	}
	if (men_build(sb, sbinfo, info->volName, info->mode) < 0) {	//在内存中建立除superblock之外的内存结构
		ErrorFlag = BUILD_MEM_ERR;
		goto err3;
	}
//is_vedio_LVM(info->volName);
//close(fd);
	free(info);
	return sbinfo;
      err3:
	free(sb);
	pthread_mutex_destroy(&sbinfo->mutex);
	free(sbinfo);
      err1:
	free(info);
      err:
	return NULL;
}



int
write_snode(_sbinfo sbinfo, vnode * v, _vnodeInfo vi, int startTime, int endTime, char flag)
{

	//flag==0 write startTime;flag==1,write endTime;flag==2 write both;
	segindex *index;
	int a;
	// _vnodeInfo vi;
	// if((vi=get_Vi(v,WriteRECORD,0))==NULL) goto err;
	if ((index = (segindex *) malloc(sizeof(segindex))) == NULL) {
		ErrorFlag = MALLOC_ERR;
		goto err;
	}			//end if((index=(segindex *)malloc???
	switch (flag) {
		case 0:
			index->start_time = startTime;
			index->end_time = endTime;
			vi->is_starttime = SET;
			a = 0;
			break;
		case 1:
			index->end_time = endTime;
			a = SEG_SIZE / 2;
			break;
		case 2:
			index->start_time = startTime;
			index->end_time = endTime;
			a = 0;
			break;
		default:
			free(index);
			goto err;
	}
	if (__write(vi->fd, (char *)((char *)index + a), SEG_SIZE - a, v->curSnode + a, &vi->mutex) < 0) {
		ErrorFlag = WRITE_LVM_ERR;
		if (flag == 0)
			vi->is_starttime = NOTSET;
		free(index);
		goto err;
	}
	v->curSnode += SEG_SIZE;
	if (v->curSnode >= ((v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr + SEG_SIZE * 1024)) {
		v->curSnode = (v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr;
		v->SnodeRecycle = ISRecycled;
	}
	free(index);
	return 0;
      err:
	return -1;
}

int
write_seg_head(_sbinfo sbinfo, vnode * v, _vnodeInfo vi, seginfo * seg, segindex * index, char *buf, short size)
{
	int fd;
	uint64_t addr;
	char buf_[DSI_SIZE];
	// _vnodeInfo vi;
	// vi=get_Vi(v,WriteRECORD,0);
	// if(!vi) goto err;
	fd = vi->fd;
	addr = v->curSnode - (v->block[0][0]) * (sbinfo->_es->blockSize) - DataAddr;	/////////////////////////???????????????????
	if (vi->is_starttime == NOTSET && index && write_snode(sbinfo, v, vi, index->start_time, index->end_time, 0))
		goto err;
	addr = (addr / SEG_SIZE) * (SEGINFO_SIZE);
	addr += DataAddr + (v->block[0][0]) * (sbinfo->_es->blockSize) + 1024 * SEG_SIZE;
	seg->size = size;
	DSI_to_buf(buf_, seg);
	if (_write(fd, buf_, DSI_SIZE, addr) < 0) {
		ErrorFlag = WRITE_LVM_ERR;
		v->curSnode -= SEG_SIZE;
		if (v->curSnode < ((v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr)) {
			if (v->SnodeRecycle == ISRecycled)
				v->curSnode = (v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr + 1023 * SEG_SIZE;
			else
				v->curSnode = (v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr;
		}
		goto err1;
	}
	//addr+=sizeof(seginfo);
	if (buf != NULL) {
		if (write(fd, buf, size) < 0) {
			ErrorFlag = WRITE_LVM_ERR;
			v->curSnode -= SEG_SIZE;
			if (v->curSnode < ((v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr)) {
				if (v->SnodeRecycle == ISRecycled)
					v->curSnode = (v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr + 1023 * SEG_SIZE;
				else
					v->curSnode = (v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr;
			}
			goto err1;
		}
	}
	return 0;
      err1:
      err:
	return -1;
}


int
CreatRecordSeg(char *cameraid, seginfo * sinfo, char *buf, short size)
{				//vnodeinfo->count need to deal with 
	int ID;
	vnode *v;
	//seginfo * seg;
	segindex *index;
	_sbinfo sbinfo;
	int handle;
	_vnodeInfo vi;
	handle = get_dev_ID(cameraid, &sbinfo);
	if (handle == -1)
		return -1;
	sbinfo = SBINFO(handle);
	if (test_or_alloc_ID(sbinfo, cameraid, strlen(cameraid), &ID, 0) != 1) {
		ErrorFlag = NOT_EXIST_RECORD;
		goto err;
	}
	if (_ID(handle) != ID)
		goto err;
	v = (vnode *) ((char *)sbinfo->vnodeTable + sizeof(vnode) * ID);
	//if((seg=(seginfo  *)malloc(sizeof(seginfo)))==NULL){
	//_Debug("create seg err!\n",__LINE__,__FILE__);
	//     goto err;
	//}
	if ((index = (segindex *) malloc(sizeof(segindex))) == NULL) {
		ErrorFlag = MALLOC_ERR;
		goto err1;
	}
	//memcpy(seg,sinfo,sizeof(seginfo));
	//index->start_time=index->end_time=0;
	if ((vi = (_vnodeInfo) extend_buf(v, sbinfo, WriteRECORD)))
		vi->is_starttime = NOTSET;
	
	if (write_seg_head(sbinfo, v, vi, sinfo, NULL, buf, size) < 0) {
		goto err2;
	}
	v->status++;
	free(index);
	//  free(seg);      
	return (handle & 0xFFFFFF00) | (vi->key & 0x000000FF);
      err2:
	free(index);
      err1:
	//        free(seg);                                                                                                                      
      err:
	return -1;
}

int
space_enough(_sbinfo sbinfo, vnode * v, int size, int *n)
{
	int i;
	uint64_t addr1, addr2;
	for (i = 0; i < MaxchunkCount && v->block[i][0] != CHUNKNULL; i++) {
		if (i == 0)
			addr1 = v->block[i][0] * (sbinfo->_es->blockSize) + DataAddr + DataAddr1;
		else
			addr1 = v->block[i][0] * (sbinfo->_es->blockSize) + DataAddr;
		addr2 = v->block[i][1] * (sbinfo->_es->blockSize) + DataAddr;
		if (v->storeAddr >= addr1 && v->storeAddr < addr2) {
			(*n) = i;
			if ((addr2 - v->storeAddr) < size) {
				i++;
				if (i >= MaxchunkCount || v->block[i][0] == CHUNKNULL)
					i = 0;
				(*n) = i;
				if (i == 0) {
					v->storeAddr = v->block[i][0] * (sbinfo->_es->blockSize) + DataAddr + DataAddr1;
					v->isRecycle = ISRecycled;
				} else
					v->storeAddr = v->block[i][0] * (sbinfo->_es->blockSize) + DataAddr;
				//size=size-(addr2-v->storeAddr);///////
			}
			return size;
		}
	}
	// _Debug("not enough space!\n",__LINE__,__FILE__);
	return 0;
}

int
write_back_tnodes(_sbinfo sbinfo, vnode * v, _vnodeInfo vi, StreamInfo * si)
{
	uint16_t count, count1;
	char *vi_addr;
	uint32_t size_;
	count = si->count % WriteLen;
	if (count == 0 && si->count >= WriteLen)
		count = WriteLen;
	if (count == 0 && si->count < WriteLen)
		return 0;
	vi_addr = (char *)&si->t[si->count - count];
	if (v->count == 0) {	//建立一级索引
		if (__write(vi->fd, (char *)&(si->t[0]), Tnode_SIZE,
			    (si->v->firstIndex - FISTTIMESIZE * Tnode_SIZE + si->v->wr_count * Tnode_SIZE), &vi->mutex) < 0) {
			ErrorFlag = WRITE_LVM_ERR;
			goto err;
		}		//end if(_write)?
		v->count = 1;
		v->wr_count++;
	}
	if (count >= WriteLen) {
		v->curSnode -= SEG_SIZE;
		if (v->curSnode < ((v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr)) {
			if (v->SnodeRecycle == ISRecycled)
				v->curSnode = (v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr + 1023 * SEG_SIZE;
			else
				v->curSnode = (v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr;
		}
        if(!si->t[count-1].time)
        {
            ErrorFlag = ZERO_TNODE;
            goto err;
        }
		write_snode(sbinfo, v, vi, 0, si->t[count - 1].time, 1);
	}
	if (v->wr_count == 0) {
		if ((v->queryAdd - v->firstIndex) / Tnode_SIZE < (_FISTTIMESIZE(v) - 1) * _TLEN(v))
			count1 = (v->queryAdd - v->firstIndex) / Tnode_SIZE + _TLEN(v) + count;
		else
			count1 = (v->queryAdd - v->firstIndex) / Tnode_SIZE - (_FISTTIMESIZE(v) - 1) * _TLEN(v) + count;
	} else
		count1 = (v->queryAdd - v->firstIndex) / Tnode_SIZE - (v->wr_count - 1) * _TLEN(v) + count;
	if (count1 > _TLEN(v)) {
		count1 -= _TLEN(v);
		if (__write
		    (vi->fd, (char *)&(si->t[si->count - count1]), Tnode_SIZE,
		     (v->firstIndex - FISTTIMESIZE * Tnode_SIZE + v->wr_count * Tnode_SIZE), &vi->mutex) < 0) {
			ErrorFlag = WRITE_LVM_ERR;
			goto err;
		}		//end if(_write)?
		if (v->wr_count == 0)
			v->count = 2;
		v->wr_count++;
		if (v->wr_count >= _FISTTIMESIZE(v)) {
			// v->count=2;
			v->wr_count = v->wr_count % _FISTTIMESIZE(v);
		}
	}			//end if(count1>_TLEN(v)){??
	if ((v->queryAdd + count * Tnode_SIZE) >= (v->firstIndex + _Maxtime(v) * Tnode_SIZE)) {
		size_ = (v->firstIndex + _Maxtime(v) * Tnode_SIZE - v->queryAdd);
		size_ = (size_ / Tnode_SIZE) * Tnode_SIZE;
		if (__write(vi->fd, vi_addr, size_, v->queryAdd, &vi->mutex) < 0) {
			ErrorFlag = WRITE_LVM_ERR;
			goto err;
		}
		if (__write(vi->fd, (char *)(vi_addr + size_), count * Tnode_SIZE - size_, v->firstIndex, &vi->mutex) < 0) {
			ErrorFlag = WRITE_LVM_ERR;
			goto err;
		}
		v->isRecycle = ISRecycled;
		v->queryAdd = v->firstIndex + count * Tnode_SIZE - size_;
	}			//end if((v->queryAdd+TimeBuffSize???
	else {
		if (__write(vi->fd, vi_addr, count * Tnode_SIZE, v->queryAdd, &vi->mutex) < 0) {
			ErrorFlag = WRITE_LVM_ERR;
			goto err;
		}
		v->queryAdd = v->queryAdd + count * Tnode_SIZE;
	}			//end else??
	//vi->count=0;

	return count;
      err:
	return -1;
}

//int write_tnodes(_sbinfo sbinfo,vnode *v,_vnodeInfo vi, long long begin_addr, long long end_time){
//}
int
writeTnodeToBuf(StreamInfo * si, uint32_t startTime, int size)
{
	int n;
	if (si->vi->is_starttime == NOTSET) {
		if (write_snode(si->sbinfo, si->v, si->vi, startTime, startTime + 1, 0) < 0)
			goto err;
	}
	if ((size = space_enough(si->sbinfo, si->v, size, &n)) == 0)
		return -1;
	if (si->vi->count < TimeBuffSize) {
		si->vi->t[si->vi->count].time = startTime;
		si->vi->t[si->vi->count].addr = si->v->storeAddr;
		si->vi->t[si->vi->count].len = size;
	}
	si->vi->count++;
	/*if(si->v->count==0){//建立一级索引
	   if(_write(si->vi->fd,(char *)&(si->vi->t[si->vi->count-1]),Tnode_SIZE,
	   (si->v->firstIndex-FISTTIMESIZE*Tnode_SIZE+si->v->wr_count*Tnode_SIZE))<0){
	   ErrorFlag=WRITE_LVM_ERR;
	   goto err;
	   }//end if(_write)?
	   si->v->count=1;
	   si->v->wr_count++;
	   } */
	if (si->vi->count >= WriteLen) {	//
		memcpy(si->t, si->vi->t, WriteLen * sizeof(tnode));
		//printf("::%d\n", si->vi->t[0].time);
		si->count = si->vi->count;
		si->vi->count = 0;
		/*
		   if(write_back_tnodes(si->sbinfo,si->v,si->vi)<0) goto err;
		   if(put_vnode(si->sbinfo,si->v,NULL,si->ID)<0) goto err ; */
	}			//if(si->vi->count%WriteLen==0)???
	return 0;
      err:
	return -1;
}

int
write_data(_sbinfo sbinfo, vnode * v, _vnodeInfo vi, char *buf, unsigned int _size, StreamInfo * si)
{
	int n;
	uint32_t size;
	uint64_t addr;
	// _vnodeInfo vi;
/*
      if(size<_size){
         if(n==0) 
               addr=v->block[n][0]*(sbinfo->_es->blockSize)+DataAddr+DataAddr1;
              else addr=v->block[n][0]*(sbinfo->_es->blockSize)+DataAddr;
          if(writeToBuf(si,(char *)buf,size,v->storeAddr)<0){
                    ErrorFlag=WRITE_LVM_ERR;
                       return -1;
                                         }
               //if(_write(fd,((char *)buf+size),_size-size,addr)<0){
          	  	  if(writeToBuf(si,((char *)buf+size),_size-size,addr) < 0){
                    ErrorFlag=WRITE_LVM_ERR;
                       return -1;
                                         }    
       v->storeAddr=addr+_size-size;
                      }*/

	if (writeToBuf(si, buf, _size) < 0) {
		ErrorFlag = WRITE_LVM_ERR;
		return -1;
	}
	v->storeAddr += _size;

	return 0;
}

int
initWriteStream(unsigned int handle, vnode ** v, int *ID, _sbinfo * sbinfo, _vnodeInfo * vi)
{
	if (handle == -1) {
		ErrorFlag = ERR_HANDLE;
		return -1;
	}
	*sbinfo = SBINFO(handle);
	(*ID) = _ID(handle);
	if ((*ID) >= MaxUsers && !bit((*sbinfo)->vnodemapping, (*ID))) {
		ErrorFlag = ERR_HANDLE;
		return -1;
	}
	(*v) = (vnode *) ((*sbinfo)->vnodeTable + (*ID) * sizeof(vnode));
// snode not set startTime
	if (((*vi) = get_Vi(*v, handle & 0x0000FF)) == NULL) {
		ErrorFlag = ERR_HANDLE;
		return -1;
	}
}

/*
int WriteStream(uint32_t handle, uint32_t startTime, char *buf, unsigned int size)
{
	vnode * v;
      int ID;
     _sbinfo sbinfo;
          _vnodeInfo vi;
     if(handle==-1) {
       ErrorFlag=ERR_HANDLE;
       return -1;
     }
     sbinfo=SBINFO(handle);
     ID=_ID(handle);
   if(ID>=MaxUsers && !bit(sbinfo->vnodemapping,ID)){
          ErrorFlag=ERR_HANDLE;
                  goto err;
         }
      v=(vnode *)(sbinfo->vnodeTable+ID*sizeof(vnode));     
// snode not set startTime
      if((vi=get_Vi(v,handle & 0x0000FF))==NULL){
           ErrorFlag=ERR_HANDLE;
           goto err;
        }
   if(vi->is_starttime==NOTSET && write_snode(sbinfo,v,vi,startTime,startTime+1,0)<0)
          goto err;
//snode not set startTime end?
     if(write_back_tnode(sbinfo,v,vi,startTime,size,ID)<0){
           // _Debug("write tnode err!\n",__LINE__,__FILE__);
            goto err;
                   }
     if(write_data(sbinfo,v,vi,buf,size)<0) goto err;
          return 0;
err:
         return -1;
}*/

/*
通过起始时间和结束时间找到对应的snode，
如果startTime到endTime中间有多个snode，返回第二个的startTime。
*/
uint32_t
find_snode(_sbinfo sbinfo, vnode * v, int fd, char *_buf, uint32_t startTime, uint32_t endTime, int *n, segindex * index, segindex * index1)
{
	uint64_t addr;
	uint32_t return_time, t;
	int len, m, h, k;
	segindex *si;
	addr = v->block[0][0] * (sbinfo->_es->blockSize) + DataAddr;	//找到snode的起始地址
	if (v->SnodeRecycle == ISRecycled) {
		len = SEG_SIZE * 1024;	//如果snode的空间已经覆盖
		(*n) = (v->curSnode - ((v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr)) / SEG_SIZE;
		//          h=((*n)-1)<0?1023:((*n)-1);
	} else {
		len = v->curSnode - addr;
		(*n) = 0;
		// h=len/SEG_SIZE-1;
	}
	if (_read(fd, _buf, len, addr) < 0) {	//snodes全部读到buf
		ErrorFlag = READ_LVM_ERR;
		return ERR_RETURN;
	}
	return_time = ERR_RETURN;
	m = len / SEG_SIZE;
	for (; m > 0; m--) {
		si = (segindex *) (_buf + (*n) * SEG_SIZE);
		if (si->start_time == 0 || endTime < si->start_time || startTime > si->end_time || si->start_time > si->end_time) {	//注意区间＝
			(*n) = (++(*n)) % 1024;
			continue;
		}
		// if(index) memcpy(index,si,SEG_SIZE);
		else {
			t = si->end_time;
			return_time = startTime;

			if (index1) {
				index1->start_time = si->start_time;
				index1->end_time = si->end_time;
			}
			if (index) {
				h = (*n);
				k = m;
				while (k > 0 && (si->start_time == 0 || si->start_time <= endTime)) {
					if (si->start_time != 0) {
						index->start_time = si->start_time;
						index->end_time = si->end_time;
					}
					k--;
					if (k > 0) {
						h = (h + 1) % 1024;
						si = (segindex *) (_buf + h * SEG_SIZE);
					}
				}
			}
			h = (*n);
			while (m > 1) {
				si = (segindex *) (_buf + ((1 + h) % 1024) * SEG_SIZE);
				if (si->start_time == 0) {
					m--;
					h = (++h) % 1024;
					continue;
				}
				if (si->start_time > t && si->start_time <= endTime)
					return_time = si->start_time;
				else	//这已经是最后一个snode，找不到下一个snode
					return_time = startTime;
				break;
			}
			break;
		}
		(*n) = (++(*n)) % 1024;
	}			//end for???
	return return_time;
}

/*
handle |16位ID|＋｜8位LVM编号｜＋｜8位未使用｜
*/

int
read_tnode(unsigned int timeBegin, _vnodeInfo vi, vnode * v, long long addr, unsigned long long *beginTime_addr, unsigned long long *next_addr, int mode)
{
//mode==1 表示不需要timeBegin有效，mode＝＝0，表示无效。
	uint32_t size, end;
	uint64_t addr1;
	int j;
	uint8_t flag = 0, flag1 = 0;
	while (1) {
		size = TimeBuffSize * Tnode_SIZE;
		end = TimeBuffSize * Tnode_SIZE;
		addr1 = addr + size;
		if (v->count == 2 && !flag1) {
			if ((addr + size) > (v->firstIndex + _Maxtime(v) * Tnode_SIZE)) {
				size = (v->firstIndex + _Maxtime(v) * Tnode_SIZE) - addr;
				addr1 = v->firstIndex;
				flag1 = 1;
			}	//end if((addr+size)>( ???
		}		//if(v->isRecycle==ISRecycled)???
		else {
			if (v->queryAdd <= addr)
				return 0;
			if ((addr + size) > v->queryAdd) {
				size = v->queryAdd - addr;
				end = v->queryAdd - addr;
			}
		}		//end else ???
		if (_read(vi->fd, (char *)vi->t, size, addr) < 0) {
			ErrorFlag = READ_LVM_ERR;
			return -1;
		}
		vi->count = 0;
		if (mode) {
			for (j = 0; j < size / Tnode_SIZE; j++) {
				if (vi->t[j].time == timeBegin) {
					vi->count = j;
					flag = 1;
					if (beginTime_addr != NULL)
						*beginTime_addr = addr + j * Tnode_SIZE;
					break;
				}
			}	//end for(j = 0; j <size/Tnode_SIZE; j++)???
		}
		if (size < end) {	//v->isRecycle==ISRecycled成立
			if (_read(vi->fd, (char *)vi->t + size, end - size, addr1) < 0) {
				ErrorFlag = READ_LVM_ERR;
				return -1;
			}
			if (mode) {
				for (j = size / Tnode_SIZE; j < end / Tnode_SIZE; j++) {
					if (vi->t[j].time == timeBegin) {
						vi->count = j;
						flag = 1;
						if (beginTime_addr != NULL)
							*beginTime_addr = addr1 + j * Tnode_SIZE;
						break;
					}
				}	//end for
			}

		}		//end if(size<end)???
		addr1 = addr1 + end - size;
		j = end / Tnode_SIZE;
		if (j < TimeBuffSize)
			vi->t[j].time = 0;	//表示该tnode无用
		if (mode && !flag && (v->count == 2 || v->count == 1 && addr1 < v->queryAdd)
		    && vi->t[TimeBuffSize - 1].time < timeBegin)
			addr = addr1;
		else
			break;
	}			//end while(1)????
	if (next_addr)
		*next_addr = addr1;
	if ((mode && flag) || !mode)
		return end / Tnode_SIZE;
	else
		return 0;
}

long long
getAddrByTime(int timeBegin, _vnodeInfo vi, vnode * v, unsigned long long *beginTime_addr)
{				//dev mode是顺序和倒序。
	//tnode* ptn = (tnode *)vn->FirstIndexTable; // record firstindex address;
	int i = 0;
	int startpos = 0;
	uint64_t addr, addr1;
	uint32_t end = 0;
	uint32_t size;
	if (v->count == 2)
		startpos = v->wr_count;
	if (_read(vi->fd, (char *)vi->t, _TimeBuffSize(v) * sizeof(tnode), v->firstIndex - FISTTIMESIZE * Tnode_SIZE) < 0) {
		ErrorFlag = READ_LVM_ERR;
		goto err;
	}			//end if(_read(vi->fd,(char *)vi->t,Ti???
	size = ((i + startpos) % _FISTTIMESIZE(v)) * Tnode_SIZE * _TLEN(v);
	addr = v->firstIndex + size;
	addr1 = 0;
	while (timeBegin >= vi->t[(i + startpos) % _FISTTIMESIZE(v)].time)	//retrival the firstindex by time
	{
		if (timeBegin == vi->t[(i + startpos) % _FISTTIMESIZE(v)].time
		    || timeBegin < vi->t[(i + 1 + startpos) % _FISTTIMESIZE(v)].time || (v->count == 1 && i == (v->wr_count - 1))
		    || i == (_FISTTIMESIZE(v) - 1)) {
			size = ((i + startpos) % _FISTTIMESIZE(v)) * Tnode_SIZE * _TLEN(v);
			addr = v->firstIndex + size;
			if ((end = read_tnode(timeBegin, vi, v, addr, beginTime_addr, &addr1, 1)) <= 0)
				goto err;

			break;
		}		//end if(timeBegin < vi->t[(i+1+startpos) % FISTTIMESIZE].time){???
		if (++i >= _FISTTIMESIZE(v))
			break;
	}			//end while???
	if (i >= _FISTTIMESIZE(v))
		goto err;
	return addr1;
      err:return 0;
}

_vnodeInfo
getVnodeInfo(int handle)
{
	int ID;
	vnode *v;
	_sbinfo sbinfo;
	ID = _ID(handle);
	sbinfo = SBINFO(handle);
	if (!sbinfo)
		goto err;
	if (!bit(sbinfo->vnodemapping, ID)) {
		ErrorFlag = ERR_HANDLE;
		goto err;
	}
	v = (vnode *) (sbinfo->vnodeTable + ID * sizeof(vnode));
	return get_Vi(v, (handle & 0x000000FF));
      err:
	return NULL;
}

int
rev_ReadStream(vnode * v, _vnodeInfo vi, char *buf, int size)
{
	uint64_t addr1, addr = 0;
	uint32_t _size = 0, size1 = 0;
	uint8_t flag = 0, flag1 = 0;
	while (1) {
		if (vi->count < 0) {
			flag = 0;
			addr1 = vi->nextTimeAddr;
			if (v->count == 1 && vi->nextTimeAddr <= v->firstIndex)
				break;
			if (addr1 > (TimeBuffSize * Tnode_SIZE + v->firstIndex)) {
				addr1 = addr1 - TimeBuffSize * Tnode_SIZE;
				if (read_tnode(0, vi, v, addr1, NULL, NULL, 0) <= 0)
					goto err;
			}	//end if
			else {
				if (v->count == 1) {
					addr1 = v->firstIndex;
					flag = 1;
					if (read_tnode(0, vi, v, addr1, NULL, NULL, 0) <= 0)
						goto err;
					vi->count = (vi->nextTimeAddr - v->firstIndex) / Tnode_SIZE;
				}	//end if(v->isRecycle!=ISRecycled)???
				else {
					addr1 += _Maxtime(v) * Tnode_SIZE - TimeBuffSize * Tnode_SIZE;
					if (read_tnode(0, vi, v, addr1, NULL, NULL, 0) <= 0)
						goto err;
				}
			}	//end else??      
			vi->nextTimeAddr = addr1;
			if (flag)
				vi->count--;
			else
				vi->count = TimeBuffSize - 1;
		}		//end if(vi->count<0)???
		while (1) {
			if (vi->count >= 0) {
				if (vi->t[vi->count].time < vi->endTime || vi->t[vi->count].time > vi->beginTime) {	//如果到结束时间了，就读取
					if (addr != 0 && _size) {
						if (_read(vi->fd, buf, _size, addr) < 0) {
							ErrorFlag = READ_LVM_ERR;
						}
					}	//end  if(addr!=0 && _size)???
					size1 += _size;
					_size = 0;
					flag1 = 1;
					break;
				}	//end if(vi->t[vi->count].time<vi->endTime????
				else if (vi->t[vi->count].len == 0) {	//如果成立，表明这段数据已经删除
					if (addr != 0 && _size) {
						if (_read(vi->fd, buf, _size, addr) < 0) {
							ErrorFlag = READ_LVM_ERR;
						}	//end if(addr!=0 && _size){??? 
						size1 += _size;
						buf += _size;
					}	//end ifif(addr!=0 && _size)???     
					vi->count--;
					_size = 0;
					addr = 0;
				}	//end else if(vi->t[vi->count].len==0)???
				else {
					if (addr == 0) {	//，新的开始，前面的数据已经读取了
						addr = vi->t[vi->count].addr;
						_size = vi->t[vi->count].len;
					}	//end if(addr==0)???
					else if ((addr - vi->t[vi->count].len) != vi->t[vi->count].addr) {	//数据存储不连续
						if (_size && (_read(vi->fd, buf, _size, addr) < 0)) {
							ErrorFlag = READ_LVM_ERR;
						}
						buf += _size;
						size1 += _size;
						_size = vi->t[vi->count].len;
						addr = vi->t[vi->count].addr;
					}	//end else if
					else {	//数据存储连续
						_size += vi->t[vi->count].len;
						addr -= vi->t[vi->count].len;
					}	//end else
					if ((size1 + _size) >= size) {	//buf 缓冲区已满
						if ((size1 + _size) == size)
							vi->count--;
						while ((size1 + _size) > size) {
							_size -= vi->t[vi->count].len;
							addr += vi->t[vi->count].len;
						}	//end while???
						if (_read(vi->fd, buf, _size, addr) < 0) {
							ErrorFlag = READ_LVM_ERR;;
						}
						size1 += _size;
						flag1 = 1;
						break;
					}	//end if((_size1+_size)>=size){ ???
					vi->count--;
				}	//end else?
			}	//end if(vi->count>=0)???
			else {
				if (_size && addr) {
					if (_read(vi->fd, buf, _size, addr) < 0) {
						ErrorFlag = READ_LVM_ERR;
					}
					size1 += _size;
					buf += _size;
					_size = 0;
					addr = 0;
				}	//end if(_size && addr)???
				break;
			}	//end else????
		}		//end inner while(1)??
		if (flag1)
			break;
	}			//end outer while(1);
	return size1;
      err:
	return -1;
}

int
_ReadStream(vnode * v, _vnodeInfo vi, char *buf, int size)
{				//顺序读
	uint32_t _size = 0, size1 = 0;
//uint32_t   size3;
	uint64_t addr = 0, addr1;
	uint32_t end = TimeBuffSize;
	while (1) {
		if (vi->count >= 0 && vi->count < end) {
			if (vi->t[vi->count].time == 0 || vi->t[vi->count].time > vi->endTime || vi->t[vi->count].time < vi->beginTime) {	//如果到结束时间了，就读取
				//if(vi->t[vi->count].time==vi->endTime)
				//         end=1;//for test
				if (addr != 0 && _size) {
					if (_read(vi->fd, buf, _size, addr - _size) < 0) {
						ErrorFlag = READ_LVM_ERR;
					}
				}
				size1 += _size;
				_size = 0;
				addr = 0;
				break;
			}	//end if(vi->t[count-1].time>vi->endTime)
			else if (vi->t[vi->count].len == 0) {	//如果成立，表明这段数据已经删除
				if (addr != 0 && _size) {
					if (_read(vi->fd, buf, _size, addr - _size) < 0) {
						ErrorFlag = READ_LVM_ERR;
					}
					size1 += _size;
					buf += _size;
				}
				// printf("%d\n",vi->t[vi->count]);    
				vi->count++;
				addr = 0;
				_size = 0;
			} else {
				if (addr == 0) {	//，新的开始，前面的数据已经读取了
					addr = vi->t[vi->count].addr + vi->t[vi->count].len;
					_size = vi->t[vi->count].len;
				} else if (addr != vi->t[vi->count].addr) {	//数据存储不连续
					if (_read(vi->fd, buf, _size, addr - _size) < 0) {
						ErrorFlag = READ_LVM_ERR;
					}
					buf += _size;
					size1 += _size;
					_size = vi->t[vi->count].len;
					addr = vi->t[vi->count].addr + vi->t[vi->count].len;
				}	//end else if
				else {	//数据存储连续
					_size += vi->t[vi->count].len;
					addr += vi->t[vi->count].len;
				}	//end else
				if ((size1 + _size) >= size) {	//buf 缓冲区已满
					if ((size1 + _size) == size)
						vi->count++;
					if ((size1 + _size) > size) {
						_size -= vi->t[vi->count].len;
						addr -= vi->t[vi->count].len;
					}
					if (_size > 0 && _read(vi->fd, buf, _size, addr - _size) < 0) {
						ErrorFlag = READ_LVM_ERR;
					}
					size1 += _size;

					break;
				}	//end if(size==0 || _size>size) ?
				vi->count++;
			}	//end else?
		}		//(vi->count>=0 && vi->count <=size3)
		else {
			if ((end = read_tnode(0, vi, v, vi->nextTimeAddr, NULL, &addr1, 0)) <= 0) {
				vi->nextTimeAddr = addr1;
				if (addr != 0 && _size) {
					if (_read(vi->fd, buf, _size, addr - _size) < 0) {
						ErrorFlag = READ_LVM_ERR;
					}
					size1 += _size;
					addr = 0;
					_size = 0;
				}
				break;
			}	//end if(end=read_tnode ??? 
			vi->nextTimeAddr = addr1;
		}		//end else??
	}			//end while(1)???
	return size1;
}

int
ReadStream(uint32_t handle, char *buf, int size, char mode)
{
//buf缓存最大为4G，mode＝＝0，表示顺序；mode＝＝1，表示逆序。
	_vnodeInfo vi;
	vnode *v;
	if ((vi = getVnodeInfo(handle)) == NULL) {
		ErrorFlag = ERR_HANDLE;
		return -1;
	}
	//  printf("%d %s",handle>>8 & 0x000000FF, sbTable.table[0].sbinfo);
	v = SBINFO(handle)
	    ? ((vnode *) (SBINFO(handle)->vnodeTable + _ID(handle) * sizeof(vnode))) : NULL;
	if (v == NULL)
		return -1;
	if (mode == 1)
		return rev_ReadStream(v, vi, buf, size);
	else
		return _ReadStream(v, vi, buf, size);
}

int
openRecordSeg(const char *cameraid, int beginTime, int endTime, int mode)
{				//mode==0 顺序读取；mode＝＝1 逆序读取；
	int handle;
	_sbinfo sbinfo;
	vnode *v;
	int ID, nr;
	_vnodeInfo vi;
	handle = get_dev_ID(cameraid, &sbinfo);
	if (handle == -1)
		return -1;
	sbinfo = SBINFO(handle);
	ID = _ID(handle);
	v = (vnode *) (sbinfo->vnodeTable + ID * sizeof(vnode));
	vi = (_vnodeInfo) extend_buf(v, sbinfo, ReadRECORD);
	if (vi == NULL)
		return -1;
	vi->beginTime = beginTime;
	vi->endTime = endTime;
	if (mode == 0) {
		if (beginTime > endTime) {
			vi->beginTime = endTime;
			vi->endTime = beginTime;
		}
		vi->nextTimeAddr = getAddrByTime(beginTime, vi, v, NULL);
		if (vi->nextTimeAddr <= 0) {
			nr = delete_vi(sbinfo, v, vi->status, handle & 0x0000FF);
			if (nr >= 0)
				free_vi(sbinfo, nr);
			return -1;
		}
	}			//end if(mode==0)???
	else {
		if (beginTime < endTime) {
			vi->beginTime = endTime;
			vi->endTime = beginTime;
		}
		if (getAddrByTime(vi->beginTime, vi, v, &vi->nextTimeAddr) <= 0) {
			nr = delete_vi(sbinfo, v, vi->status, handle & 0x0000FF);
			if (nr >= 0)
				free_vi(sbinfo, nr);
			return -1;
		}
		vi->count = -1;
	}			//end else????
	// printf("%u---fd:%d:%d\n",(unsigned int)pthread_self(),vi->fd,vi->key);
	v->status++;
	handle = (handle & 0xFFFFFF00) | (vi->key & 0x000000FF);
	return handle;
}

int
DeleteRecordSeg(uint32_t startTime, uint32_t endTime, const char *cameraid)
{
	_sbinfo sbinfo;
	int handle;
	int n, fd, ID;
	uint32_t t, a = 0;
	uint64_t addr;
	vnode *v;
	char *buf;
	segindex si;
	handle = get_dev_ID(cameraid, &sbinfo);
	if (handle == -1) {
		ErrorFlag = NOT_EXIST_RECORD;
		return -1;
	}
	sbinfo = SBINFO(handle);
	ID = _ID(handle);
	v = (vnode *) (sbinfo->vnodeTable + ID * sizeof(vnode));
	pthread_mutex_lock(&sbinfo->mutex);
	if ((fd = open(sbinfo->volName, O_RDWR)) < 0) {
		pthread_mutex_unlock(&sbinfo->mutex);
		ErrorFlag = OPEN_FILE_ERR;
		return -1;
	}
	pthread_mutex_unlock(&sbinfo->mutex);
	if ((buf = (char *)malloc(sizeof(char) * 1024 * 10)) == NULL) {
		ErrorFlag = MALLOC_ERR;
		close(fd);
		return -1;
	}
	t = startTime;
	do {
		startTime = t;
		if ((t = find_snode(sbinfo, v, fd, buf, startTime, endTime, &n, NULL, &si)) == ERR_RETURN) {
			ErrorFlag = ERR_TIME_INTERL;
			close(fd);
			free(buf);
			return -1;
		}
		if (si.start_time < startTime || si.end_time > endTime)
			continue;
		addr = SEG_SIZE * n;
		addr = (v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr + addr;
		if (_write(fd, (char *)&a, sizeof(a), addr) < 0) {
			close(fd);
			free(buf);
			ErrorFlag = WRITE_LVM_ERR;
			return -1;
		}
	}
	while (t != startTime);
	close(fd);
	free(buf);
	return 0;
}



int
CloseRecordSeg(uint32_t handle, StreamInfo * si)
{				//mode==0,关闭读；mode==1,关闭写。
	_sbinfo sbinfo;
	vnode *v;
	_vnodeInfo vi;
	int ID;
	int nr;
	uint32_t endTime;
	if (handle == -1)
		return -1;
	sbinfo = SBINFO(handle);
	ID = _ID(handle);
	v = (vnode *) (sbinfo->vnodeTable + ID * sizeof(vnode));
	if (!(vi = get_Vi(v, handle & 0x0000FF))) {
		ErrorFlag = ERR_HANDLE;
		return -1;
	}
	if (vi->status == 1) {	//写
		if (si->count > 0)
			endTime = si->t[si->count - 1].time;	//
		else
			endTime = si->t[WriteLen - 1].time;
		if (si->count != 0 && write_back_tnodes(sbinfo, v, vi, si) < 0)
			return -1;
		v->curSnode -= SEG_SIZE;
		if (v->curSnode < ((v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr)) {
			if (v->SnodeRecycle == ISRecycled)
				v->curSnode = (v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr + 1023 * SEG_SIZE;
			else
				v->curSnode = (v->block[0][0]) * (sbinfo->_es->blockSize) + DataAddr;
		}
		if (write_snode(sbinfo, v, vi, 0, endTime, 1) < 0) {
			v->curSnode += SEG_SIZE;
			return -1;
		}
	}			//end if(mode==1)???
	close(vi->fd);
	pthread_mutex_destroy(&vi->mutex);
	v->status--;
	if (put_vnode(sbinfo, v, NULL, ID) < 0)
		return -1;
	if ((nr = delete_vi(sbinfo, v, vi->status, handle & 0x0000FF)) < 0) {
		// ErrorFlag=700000005;
		return -1;
	}
	//dec_buf(sbinfo,nr);
	free_vi(sbinfo, nr);
	return 0;
}

     /*
        获取录像段头
        handle是句柄
        要求buf的容量大于等于10K
      */
uint32_t
_GetRecordSegHead(const char *cameraid, uint32_t * pStartTime, uint32_t * pEndTime, char *buf, int *size)
{
	int ID, n, fd;
	vnode *v;
	// _vnodeInfo vi; 
	uint32_t len;
	uint64_t addr;
	uint32_t return_time = ERR_RETURN;
	_sbinfo sbinfo;
	segindex si, si1;
	//分析handle
	int handle;
	/* char vol_path[VolNameLength];
	   if(read_vol_by_camera(vol_path,cameraid)<0) return -1;
	   if(!spin_rdlock(sbTable.spin)){//?????
	   for(handle=0;handle<LvmCount;handle++){
	   sbinfo=sbTable.table[handle];
	   if(sbinfo && (strcmp(sbinfo->volName,vol_path)==0)) break;
	   }
	   spin_rwunlock(sbTable.spin);
	   }
	   if(handle>=LvmCount){
	   if(init(vol_path)<0)
	   return -1;
	   } */
	handle = get_dev_ID(cameraid, &sbinfo);
	if (handle == -1)
		return -1;
	ID = _ID(handle);
	//if((vi=getVnodeInfo(handle))==NULL) goto err;
	//通过snode找到对应的录像段，其中n返回对应的位置编号
	pthread_mutex_lock(&sbinfo->mutex);
	if ((fd = open(sbinfo->volName, O_RDONLY)) < 0) {
		pthread_mutex_unlock(&sbinfo->mutex);
		ErrorFlag = OPEN_FILE_ERR;
		goto err;
	}
	pthread_mutex_unlock(&sbinfo->mutex);
	v = (vnode *) (sbinfo->vnodeTable + ID * sizeof(vnode));
	return_time = find_snode(sbinfo, v, fd, buf, *pStartTime, *pEndTime, &n, &si, &si1);
	*pStartTime = si1.start_time;
	*pEndTime = si.end_time;
	if (return_time == ERR_RETURN)
		goto err1;
	addr = v->firstIndex - 1024 * SEGINFO_SIZE - FISTTIMESIZE * Tnode_SIZE + n * SEGINFO_SIZE;
	//通过录像段头找到录像段的长度。
	if (_read(fd, (char *)&len, sizeof(uint32_t), addr) < 0) {
		ErrorFlag = READ_LVM_ERR;
		goto err1;
	}
	if (_read(fd, buf, len, addr + DSI_SIZE) < 0) {
		ErrorFlag = READ_LVM_ERR;
		goto err1;
	}
	(*size) = len;
	close(fd);
	return return_time;
      err1:
	close(fd);
      err:
	return ERR_RETURN;
}

int
DeleteRecordPara(const char *cameraid, uint32_t beginTime, uint32_t endTime)
{
	int handle;
	uint64_t addr1, addr2, addr3;
	int ID;
	int j;
	vnode *v;
	int size, size_, size1;
	_sbinfo sbinfo;
	_vnodeInfo vi;
	size = TimeBuffSize * Tnode_SIZE;
	handle = get_dev_ID(cameraid, &sbinfo);
	if (handle == -1)
		return -1;
	ID = _ID(handle);
	v = (vnode *) (sbinfo->vnodeTable + ID * sizeof(vnode));
	if (!(vi = alloc_vi(sbinfo))) {
		return -1;
	}
	pthread_mutex_lock(&sbinfo->mutex);
	if ((vi->fd = open(sbinfo->volName, O_RDWR)) < 0) {
		pthread_mutex_unlock(&sbinfo->mutex);
		ErrorFlag = OPEN_FILE_ERR;
		goto err;
	}
	pthread_mutex_unlock(&sbinfo->mutex);
	if ((getAddrByTime(beginTime, vi, v, &addr1) == 0)
	    || (getAddrByTime(endTime, vi, v, &addr2) == 0)) {
		ErrorFlag = TIME_ERR;
		goto err1;
	}
	if ((addr1 >= v->firstIndex && addr1 < (v->firstIndex + _Maxtime(v) * Tnode_SIZE))
	    && (addr2 >= v->firstIndex && addr2 < (v->firstIndex + _Maxtime(v) * Tnode_SIZE))) {
		if (addr2 < addr1)
			addr2 += _Maxtime(v) * Tnode_SIZE;
		size1 = addr2 - addr1;
		while (size1 > 0) {
			if (read_tnode(beginTime, vi, v, addr1, NULL, &addr3, 1) < 0)
				goto err1;
			if (TimeBuffSize * Tnode_SIZE < size1)
				size = TimeBuffSize * Tnode_SIZE;
			else
				size = size1;
			//if(addr2<=addr1) break;
			size1 -= size;
			j = size / Tnode_SIZE - 1;
			beginTime = vi->t[j].time;
			for (; j >= 0; j--)
				vi->t[j].len = 0;
			//  beginTime=vi->t[j-1].time;
			if ((addr1 + size) >= (v->firstIndex + _Maxtime(v) * Tnode_SIZE)) {
				size_ = (v->firstIndex + _Maxtime(v) * Tnode_SIZE - addr1);
				size_ = (size_ / Tnode_SIZE) * Tnode_SIZE;
				if (_write(vi->fd, (char *)vi->t, size_, addr1) < 0) {
					ErrorFlag = WRITE_LVM_ERR;
					goto err1;
				}
				if (_write(vi->fd, (char *)((char *)vi->t + size_), size - size_, v->firstIndex) < 0) {
					ErrorFlag = WRITE_LVM_ERR;
					goto err1;
				}
			}	//end if((addr1+size)>=???
			else {
				if (_write(vi->fd, (char *)vi->t, size, addr1) < 0) {
					ErrorFlag = WRITE_LVM_ERR;
					goto err1;
				}
			}	//end else??           
			addr1 = addr3;
		}		//end while(1)???
	}			//end if if((addr1>=v->firstIndex &&???
	close(vi->fd);
	free_vi(sbinfo, (((char *)vi) - (char *)sbinfo->_bf) / sizeof(struct vnodeInfo));
	return 0;
      err1:
	close(vi->fd);
      err:
	free_vi(sbinfo, (((char *)vi) - (char *)sbinfo->_bf) / sizeof(struct vnodeInfo));
	return -1;
}



uint32_t
findOriginTime(vnode * v, int fd)
{ 
    long long offset;
    tnode originTnode;  
    
    if(v->count == 2){
            offset = v->firstIndex - FISTTIMESIZE * Tnode_SIZE + v->wr_count* sizeof(tnode);
    }
    else{
            offset = v->firstIndex - FISTTIMESIZE * Tnode_SIZE;
    }               
    if (_read(fd, (char*)&originTnode, sizeof(tnode), offset) < 0) {
		ErrorFlag = READ_LVM_ERR;
		return ERR_RETURN;
	}
    
    return originTnode.time;
}


uint32_t
GetRecordInfo(const char *cameraid, uint32_t * pStartTime, uint32_t * pEndTime, seginfo * si)
{
	int ID, n, fd;
	vnode *v;
	// _vnodeInfo vi; 
	uint64_t addr;
	uint32_t return_time = ERR_RETURN;
	_sbinfo sbinfo;
	segindex sIndex;
	//分析handle
	int handle;
	char buf[16 * 1024];
    uint32_t origin_time;
	handle = get_dev_ID(cameraid, &sbinfo);
	if (handle == -1)
		return -1;
	ID = _ID(handle);
	pthread_mutex_lock(&sbinfo->mutex);
	if ((fd = open(sbinfo->volName, O_RDONLY)) < 0) {
		pthread_mutex_unlock(&sbinfo->mutex);
		ErrorFlag = OPEN_FILE_ERR;
		goto err;
	}
	pthread_mutex_unlock(&sbinfo->mutex);
	v = (vnode *) (sbinfo->vnodeTable + ID * sizeof(vnode));

    origin_time = findOriginTime(v, fd);
    if(origin_time == ERR_RETURN)
        goto err1;
    if(*pEndTime < origin_time) {
        ErrorFlag = TIME_ERR;
        goto err1;
    } 
    if(*pStartTime < origin_time) {
        return_time = find_snode(sbinfo, v, fd, buf, origin_time, *pEndTime, &n, NULL, &sIndex);
        if (return_time == origin_time)
            return_time = *pStartTime;
    }
    else {
        return_time = find_snode(sbinfo, v, fd, buf, *pStartTime, *pEndTime, &n, NULL, &sIndex);
    }
	if (*pStartTime < sIndex.start_time)
		*pStartTime = sIndex.start_time;
    if (*pStartTime < origin_time)
        *pStartTime = origin_time;
	if (*pEndTime > sIndex.end_time)
		*pEndTime = sIndex.end_time;
    if (return_time == ERR_RETURN)
        goto err1; 
    
	addr = v->firstIndex - 1024 * SEGINFO_SIZE - FISTTIMESIZE * Tnode_SIZE + n * SEGINFO_SIZE;
	//通过录像段头找到录像段的长度。
	if (_read(fd, buf, DSI_SIZE, addr) < 0) {
		ErrorFlag = READ_LVM_ERR;
		goto err1;
	}
	buf_to_DSI(buf, si);
	close(fd);
	return return_time;
      err1:
	  	printf("....get record info failed, err = %d......\n", ErrorFlag);
	close(fd);
      err:
	  	printf("....get record info failed, err = %d......\n", ErrorFlag);
	return ERR_RETURN;
}

uint32_t
GetRecordInfoOnebyOne(const char *cameraid, uint32_t * pStartTime, uint32_t * pEndTime, seginfo * si, int *n)
{
	int ID, fd,len,m;
	vnode *v;
	// _vnodeInfo vi; 
	uint64_t addr;
	_sbinfo sbinfo;
	segindex *sIndex;
	//����handle
	int handle;
	char buf[16 * 1024];
    uint32_t origin_time;
	handle = get_dev_ID(cameraid, &sbinfo);
	if (handle == -1)
		return ERR_RETURN;
	ID = _ID(handle);
	pthread_mutex_lock(&sbinfo->mutex);
	if ((fd = open(sbinfo->volName, O_RDONLY)) < 0) {
		pthread_mutex_unlock(&sbinfo->mutex);
		ErrorFlag = OPEN_FILE_ERR;
		return ERR_RETURN;
	}
	pthread_mutex_unlock(&sbinfo->mutex);
	v = (vnode *) (sbinfo->vnodeTable + ID * sizeof(vnode));
    addr = v->block[0][0] * (sbinfo->_es->blockSize) + DataAddr;	//�ҵ�snode����ʼ��ַ
	if (v->SnodeRecycle == ISRecycled) {
		len = 1024;	//���snode�Ŀռ��Ѿ�����
		m = (*n + (v->curSnode - addr) / SEG_SIZE)%1024;
	} else {
		len = (v->curSnode - addr) / SEG_SIZE;
        m = *n;
	}
    if(*n > len -1){
        close(fd);
        return 2;
    }
	if (_read(fd, buf, len*SEG_SIZE, addr) < 0) {	//snodesȫ������buf
		ErrorFlag = READ_LVM_ERR;
        close(fd);
		return ERR_RETURN;
	}
    sIndex = (segindex *) (buf + m * SEG_SIZE); //
    if(sIndex->start_time == 0){
        close(fd);
        return 1;
    }
    *pStartTime = sIndex->start_time;
    *pEndTime = sIndex->end_time;

    origin_time = findOriginTime(v, fd);
    if(origin_time == ERR_RETURN)
        goto err;
    if(*pEndTime < origin_time) {
        close(fd);
        return 1;
    }
    if(*pStartTime < origin_time){
        *pStartTime = origin_time;
    }
    
    addr = v->firstIndex - 1024 * SEGINFO_SIZE - FISTTIMESIZE * Tnode_SIZE + m * SEGINFO_SIZE;
 	if (_read(fd, buf, DSI_SIZE, addr) < 0) {
		ErrorFlag = READ_LVM_ERR;
        close(fd);
		return ERR_RETURN;
	}
	buf_to_DSI(buf, si);      
    close(fd);    
    return 0;
     err:
     close(fd);
     return ERR_RETURN;
}


int
GetRecordSegSize(const char *cameraid, uint32_t StartTime, uint32_t EndTime)
{
	int handle;
	uint64_t addr1, addr2, addr3, addr4;
	int ID;
	int i, j = -1, h = -1, k, count;
	vnode *v;
	_sbinfo sbinfo;
	_vnodeInfo vi;
	uint64_t size = 0;
	tnode t;
	handle = get_dev_ID(cameraid, &sbinfo);
	if (handle == -1)
		return -1;
	ID = _ID(handle);
	v = (vnode *) (sbinfo->vnodeTable + ID * sizeof(vnode));
	if (!(vi = alloc_vi(sbinfo))) {
		return -1;
	}
	pthread_mutex_lock(&sbinfo->mutex);
	if ((vi->fd = open(sbinfo->volName, O_RDWR)) < 0) {
		pthread_mutex_unlock(&sbinfo->mutex);
		ErrorFlag = OPEN_FILE_ERR;
		goto err;
	}
	pthread_mutex_unlock(&sbinfo->mutex);
	if ((getAddrByTime(StartTime, vi, v, &addr3) == 0)
	    || (getAddrByTime(EndTime, vi, v, &addr4) == 0)) {
		ErrorFlag = TIME_ERR;
		goto err1;
	}
	addr1 = addr3;
	addr2 = addr4;
	if (_read(vi->fd, (char *)&addr3, sizeof(unsigned long long), addr1 + 2 * sizeof(int)) < 0 || _read(vi->fd, (char *)&t, sizeof(tnode), addr2) < 0) {
		ErrorFlag = READ_LVM_ERR;
		goto err1;
	}
	addr4 = t.addr + t.len;
	for (i = 0; i < MaxchunkCount && v->block[i][0] != CHUNKNULL; i++) {
		if (i == 0)
			addr1 = v->block[i][0] * (sbinfo->_es->blockSize) + DataAddr + DataAddr1;
		else
			addr1 = v->block[i][0] * (sbinfo->_es->blockSize) + DataAddr;
		addr2 = v->block[i][1] * (sbinfo->_es->blockSize) + DataAddr;
		if (addr3 >= addr1 && addr3 < addr2)
			j = i;
		if (addr4 >= addr1 && addr4 < addr2)
			h = i;
	}
	if (j == -1 || h == -1 || (j > h && v->isRecycle != ISRecycled)) {
		ErrorFlag = TIME_ERR;
		goto err1;
	}
	if (j > h && v->isRecycle == ISRecycled || (j == h && v->isRecycle == ISRecycled && addr3 >= addr4))
		count = h + i - j;
	else
		count = h - j;
	if (count == 0) {
        if(addr3 <= addr4)
		    size = addr4 - addr3;
        else {
            k = j;
			if (k == 0)
				addr1 = v->block[k][0] * (sbinfo->_es->blockSize) + DataAddr + DataAddr1;
			else
				addr1 = v->block[k][0] * (sbinfo->_es->blockSize) + DataAddr;
			addr2 = v->block[k][1] * (sbinfo->_es->blockSize) + DataAddr;
            size = (addr2-addr3) + (addr4-addr1);
        }
	} else {
		k = j;
		for (; count >= 0; count--) {
			if (k == 0)
				addr1 = v->block[k][0] * (sbinfo->_es->blockSize) + DataAddr + DataAddr1;
			else
				addr1 = v->block[k][0] * (sbinfo->_es->blockSize) + DataAddr;
			addr2 = v->block[k][1] * (sbinfo->_es->blockSize) + DataAddr;
			if (count == 0)
				size += addr4 - addr1;
			else
				size += addr2 - addr3;
			k = (++k) % i;
			if (k == 0)
				addr3 = v->block[k][0] * (sbinfo->_es->blockSize) + DataAddr + DataAddr1;
			else
				addr3 = v->block[k][0] * (sbinfo->_es->blockSize) + DataAddr;
		}		//end for?
	}			//end else?
	close(vi->fd);
	free_vi(sbinfo, (((char *)vi) - (char *)sbinfo->_bf) / sizeof(struct vnodeInfo));
	return size / (1024);
      err1:
	close(vi->fd);
      err:
	free_vi(sbinfo, (((char *)vi) - (char *)sbinfo->_bf) / sizeof(struct vnodeInfo));
	return -1;

}
inline int
is_allow_alloc(_sbinfo sbinfo, short blocks)
{				//欲分配blocks的块，是否有足够的空闲块。
	return ((sbinfo->_es->vnodeCount < (MaxUsers - 1))
		&& (sbinfo->_es->freeBlocksCount >= blocks));
}


inline unsigned long long
minLvmSize()
{				//逻辑块的最小大小
	return DataAddr;
}


int
alloc_blocks_for_vnode(_sbinfo sbinfo, unsigned long long blocks, vnode * v)
{				//blocks为需要分配的块数，为vnode分配数据块
	if (!is_allow_alloc(sbinfo, blocks)) {
		goto err;
	}			//end if(!is_allow_alloc(sbinfo,blocks))
	//
	if (cal_alloc_chunk(sbinfo, v, blocks) < 0)
		goto err;
	set_clr_bitmap(sbinfo, v, 1);
	sbinfo->_es->vnodeCount++;
	sbinfo->_es->freeBlocksCount -= blocks;
	if (put_sb(sbinfo, v) < 0)
		goto err;
	return 0;
      err:
	return -1;

}

int
fill_vnode(_sbinfo sbinfo, vnode * v, int ID, char *volumeid, char *name, char *alias, short savedDays, char delPolicy, char encodeType)
{
	memcpy(v->cameraid, name, CNameLength);
	memcpy(v->alias, alias, CNameLength);
	memcpy(v->volName, volumeid, VolNameLength);
	v->isRecycle = NOTRecycled;
	v->savedDays = savedDays;
	v->delPolicy = delPolicy;
	v->encodeType = encodeType;
	v->SnodeRecycle = NOTRecycled;
	v->count = 0;
	v->wr_count = 0;
	v->status = 0;
	/* 
	   |1024*SEG_SIZE |1024*SEGINFO_SIZE |FISTTIMESIZE*Tnode_SIZE|Maxtime*Tnode_SIZE|
	 */
	v->curSnode = DataAddr + (v->block[0][0]) * (sbinfo->_es->blockSize);
	v->firstIndex = v->curSnode + 1024 * SEG_SIZE + 1024 * SEGINFO_SIZE + FISTTIMESIZE * Tnode_SIZE;
	v->storeAddr = v->firstIndex + Maxtime * Tnode_SIZE;
	v->queryAdd = v->firstIndex;
	v->_bf = NULL;
	spin_rwinit(v->spin);
	return 0;
}


int
alloc_ID(const char *vol_path, const char *cameraid, _sbinfo * sbinf, int *ID)
{
	int m, n;
	int flag = 0, count = 0;
	int handle = 0;
	_sbinfo sbinfo = NULL;
	char *vbitmap;
	int fd;
	char buf[Vnode_SIZE];
	vnode *v;
	if (read_vol_by_camera(NULL, cameraid) == 0) {
		ErrorFlag = EXIST_SAME_NAME;
		return -1;
	}
	if (!spin_rdlock(sbTable.spin)) {	//?????
		for (handle = 0; handle < LvmCount; handle++) {
			sbinfo = sbTable.table[handle];
			if (sbinfo && (strcmp(sbinfo->volName, vol_path) == 0))
				break;
		}
		spin_rwunlock(sbTable.spin);
	}
	if (handle >= LvmCount) {
		if ((sbinfo = init(vol_path)) == NULL)
			return -1;
	}
	m = buf_hash((char *)cameraid, strlen(cameraid));
	count = 0;
	while (count < MaxUsers && m < MaxUsers) {
		if (bit(sbinfo->vnodemapping, m)) {
			if (strcmp(((vnode *) ((char *)sbinfo->vnodeTable + m * sizeof(vnode)))->cameraid, cameraid) == 0) {
				flag = 1;
				break;
			}	//end if(strcmp(????
		}		//end if(bit???
		else {
			flag = 0;
			(*ID) = m;
			break;
		}
		m = (m + 1) % MaxUsers;
		count++;
	}			//end while????
	*sbinf = sbinfo;
	return flag;
}

int get_cameras_from_vol(char cameras[][CNameLength], int *num,
			 const char *volName)
{
 
int count=0;
char *vbitmap;
int fd;
char buf[Vnode_SIZE];
vnode v;
(*num)=0;
  if((fd=open(volName,O_RDONLY))<0){
                 ErrorFlag=OPEN_FILE_ERR;
                  return -1;
     }
 if((vbitmap=(char *)malloc(sizeof(char) *(MaxUsers / 8)))==NULL){
              ErrorFlag=MALLOC_ERR;
              return -1;
          }
           if(_read(fd, vbitmap, MaxUsers / 8, VBitmapAddr)<0){
                    close(fd);
                   free(vbitmap);
                   return -1;
           }
           count=0;
            while(count<MaxUsers) {
                  if(bit(vbitmap,count)){
                      if(_read(fd,buf,Vnode_SIZE,VnodeAddr+count*Vnode_SIZE)<0){
                       close(fd);
                       free(vbitmap);
                       return -1;
                      }
                    buf_to_vnode(buf,&v);
                   memcpy(cameras[*num],v.cameraid,CNameLength); 
                    (*num)++;
              }
            count++;
          }
     close(fd);
    free(vbitmap);
     return 0;
}
 
int
CreateRecordVol(char *volumeid, char *name, char *alias, short savedDays, char delPolicy, char encodeType, unsigned long long blocks)
{
	int ID;
	//uint64_t blocks;
	vnode *v;
	_sbinfo sbinfo = NULL;
	int flag;
    if(!read_vol_by_camera(NULL, name))//if exist same camera in list, remove it
    {
        removeCameraInfo(name);
    }
	flag = alloc_ID(volumeid, name, &sbinfo, &ID);
	if (flag == -1)
		goto err;
	if (flag == 1) {
		ErrorFlag = EXIST_SAME_NAME;
		goto err;
	}

	v = (vnode *) (sbinfo->vnodeTable + sizeof(vnode) * ID);	//
	if (alloc_blocks_for_vnode(sbinfo, blocks, v) < 0)
		goto err;
	if (fill_vnode(sbinfo, v, ID, volumeid, name, alias, savedDays, delPolicy, encodeType) < 0)
		goto err;
	setbit_(sbinfo->vnodemapping, ID);
	if (put_vnode(sbinfo, v, sbinfo->vnodemapping, ID) < 0) {
		clrbit_(sbinfo->vnodemapping, ID);
		goto err;
	}
	if (addCameraInfo(name, volumeid)< 0) {
		printf("..........Add Camera failed!.........\n");
		clrbit_(sbinfo->vnodemapping, ID);
		goto err;
	}
    showCameraList();
	return 0;

      err:
	  	printf("....create record vol failed, err = %d......\n", ErrorFlag);
	return -1;
}
 
int
DeleteRecordVol(const char *cameraid, int mode)
{				//mode==0 强制删除 mode==1 要等读写完成之后才删除
	_sbinfo sbinfo;
	vnode *v;
	int ID, handle;
	_vnodeInfo vi;
	//seginfo * seg;
	TRACE_LOG("Delete RecordVol...");
	handle = get_dev_ID(cameraid, &sbinfo);
	if (handle == -1)
		return -1;
	ID = _ID(handle);
	v = (vnode *) (sbinfo->vnodeTable + sizeof(vnode) * ID);
	if (mode && v->status > 0)
		goto err;
	if (!mode && v->status > 0) {
		vi = v->_bf;
		if (!spin_wrlock(v->spin)) {
			while (vi) {
				close(vi->fd);
				pthread_mutex_destroy(&vi->mutex);
				free_vi(sbinfo, (((char *)vi) - (char *)sbinfo->_bf) / sizeof(struct vnodeInfo));
				vi = vi->next;
			}
			spin_rwunlock(v->spin);
		}

	}
	free_blocks(sbinfo, v, (uint32_t) time(NULL));
	if (put_sb(sbinfo, v) < 0)
		goto err;
	free_vnode(sbinfo, v);
	if (put_vnode(sbinfo, v, sbinfo->vnodemapping, (((char *)v) - (char *)sbinfo->vnodeTable) / sizeof(vnode)) < 0)
		goto err;
	if (removeCameraInfo (cameraid) < 0)
		goto err;
    showCameraList();
	return 0;
      err:
	return -1;
}
 
int
DeleteVideoVol(const char *vol_path)
{
	_sbinfo sbinfo;
	vnode *v;
	int m, handle, flag = 0;
	_vnodeInfo vi;
	//seginfo * seg;
	if (!spin_rdlock(sbTable.spin)) {	//?????
		for (handle = 0; handle < LvmCount; handle++) {
			sbinfo = sbTable.table[handle];
			if (sbinfo && (strcmp(sbinfo->volName, vol_path) == 0)) {
				//     sbTable.table[handle]=NULL;
				break;
			}
		}
		spin_rwunlock(sbTable.spin);
	}
	if (handle >= LvmCount)
		return 0;
	m = 0;
	while (m < MaxUsers) {
		if (bit(sbinfo->vnodemapping, m)) {	//有vnode
			v = (vnode *) (sbinfo->vnodeTable + m * sizeof(vnode));
			if (v->status > 0) {
				flag = 1;
				break;
			}
		}
		m++;
	}			//end while(i<MaxUsers)?
	if (flag == 1)
		return -2;
	if (removeCameraInfoByVol(vol_path) < 0) {
		return -1;
	}
	if (!spin_wrlock(sbTable.spin)) {	//?????
		for (handle = 0; handle < LvmCount; handle++) {
			sbinfo = sbTable.table[handle];
			if (sbinfo && (strcmp(sbinfo->volName, vol_path) == 0)) {
				sbTable.table[handle] = NULL;
				break;
			}
		}
		spin_rwunlock(sbTable.spin);
	}
	m = 0;
	while (m < MaxUsers) {
		if (bit(sbinfo->vnodemapping, m)) {	//有vnode
			v = (vnode *) (sbinfo->vnodeTable + m * sizeof(vnode));
			if (!spin_wrlock(v->spin)) {
				for (vi = v->_bf; vi; vi = vi->next) {
					close(vi->fd);
					pthread_mutex_destroy(&vi->mutex);
				}
			}
			spin_rwunlock(v->spin);
			spin_rwdestroy(v->spin);
		}
		m++;
	}			//end while(i<MaxUsers)?
	spin_rwdestroy(sbinfo->_bh->spin);
	free(sbinfo->bitmap);
	free(sbinfo->vnodeTable);
	free(sbinfo->_bh);
	free(sbinfo->_bf);
	free(sbinfo->_es);
	pthread_mutex_destroy(&sbinfo->mutex);
	free(sbinfo);
	return 0;
}

int creatCameraList()//creat camera list
{
    CameraInfos = NULL;
    if( NULL == (CameraInfos = malloc(sizeof(CameraInfo))))
    {
        ErrorFlag = MALLOC_ERR;
        return -1;
    }
    bzero(CameraInfos->CameraID, CAMERAIDLEN);
    bzero(CameraInfos->lv_name,VolNameLength);
    CameraInfos->next = NULL;
    return 0;
}

void showCameraList()
{
    if(CameraInfos)
    {
         TRACE_LOG("Show Camera List:\n");
         CameraInfo * p = CameraInfos;
         while(p->next != NULL)
         {
            TRACE_LOG("%s\n",p->next->CameraID);
            p = p->next;
         }
    }
}

int addCameraInfo(const char * cameraID, const char * volName)
{  
    CameraInfo* pCameraInfo = NULL;
    if(NULL ==CameraInfos)//camera list is not exist 
    {
        ErrorFlag = NOT_EXIST_CAMERALIST;
		printf("AddCameraInfo():Not exist cameralist!");
        return -1;
    } 
    if(!read_vol_by_camera(NULL, cameraID))
    {
        ErrorFlag = EXIST_SAME_NAME;
        return -1;    
    }
    pCameraInfo = CameraInfos->next;//insert one node 
    if( NULL == (CameraInfos->next = malloc(sizeof(CameraInfo))))
    {
        ErrorFlag = MALLOC_ERR;
        return -1;
    }

    strcpy(CameraInfos->next->CameraID, cameraID);
    strcpy(CameraInfos->next->lv_name, volName);
    CameraInfos->next->next = pCameraInfo;
    return 0;
}

int read_vol_by_camera(char * vol_path, const char * cameraID)
{
    if(NULL ==CameraInfos)//if head is null ,camera list is not exit 
    {
        ErrorFlag = NOT_EXIST_CAMERALIST;
        return -1;
    }
    CameraInfo* pCameraInfo = CameraInfos;
    while(pCameraInfo->next != NULL)
    {
        if(!strcmp(pCameraInfo->next->CameraID, cameraID))
        { 
            if(vol_path)
                strcpy(vol_path, pCameraInfo->next->lv_name);
            return 0;
        }
        pCameraInfo = pCameraInfo->next;        
    }
    ErrorFlag = NOT_EXIST_RECORD;
    return -1;     
}

int removeCameraInfo(const char *cameraID)
{
    
    if(NULL ==CameraInfos)//  camera list is not creat 
    {
         ErrorFlag = NOT_EXIST_CAMERALIST;
         return -1;
    }
    CameraInfo* pCameraInfo = CameraInfos;
    CameraInfo* pTemp = NULL;
    while(pCameraInfo->next != NULL)
    {
        if(!strcmp(pCameraInfo->next->CameraID, cameraID))
        {   
            pTemp = pCameraInfo->next;
            pCameraInfo->next = pCameraInfo->next->next;
            free(pTemp);
            return 0;
        }
        pCameraInfo = pCameraInfo->next; 
    }
    ErrorFlag = NOT_EXIST_RECORD;
    return -1;
}

int removeCameraInfoByVol(const char *vol_path)
{ 
    if(NULL ==CameraInfos)//  camera list is not creat 
    {
         ErrorFlag = NOT_EXIST_CAMERALIST;
         return -1;
    }
    CameraInfo* pCameraInfo = CameraInfos;
    CameraInfo* pTemp = NULL;
    while(pCameraInfo->next != NULL)
    {
        if(!strcmp(pCameraInfo->next->lv_name, vol_path))
        {   
            pTemp = pCameraInfo->next; 
            pCameraInfo->next = pCameraInfo->next->next; 
            free(pTemp); 
        }
        pCameraInfo = pCameraInfo->next; 
    } 
    return 0;
}


