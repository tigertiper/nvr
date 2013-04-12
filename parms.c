#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<time.h>
#include<sys/stat.h>
#include"info.h"

#ifndef _LARGEFILE_SOURCE
#define _LARGEFILE_SOURCE
#endif

#ifndef _LARGEFILE64_SOURCE
#define _LARGEFILE64_SOURCE
#endif

#define _FILE_OFFSET_BITS 64

#define address_of_pointer(x) (long)((void*)x)
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER) 
SBTable sbTable;
void
sb_to_buf(char *buf, SBlock * sb)
{				//å°è¶çº§åçä¿¡æ¯èœ¬æ¢æbuf
	memcpy(buf, sb->fileSystemName, FNameLength * sizeof(char));
	buf = buf + FNameLength * sizeof(char);
	memcpy(buf, &sb->totalSize, sizeof(unsigned long long));
	buf += sizeof(unsigned long long);
	memcpy(buf, &sb->vnodeCount, sizeof(short));
	buf += sizeof(short);
	memcpy(buf, &sb->blockSize, sizeof(long long));
	buf += sizeof(long long);
	memcpy(buf, &sb->mTime, sizeof(int));
	buf += sizeof(int);
	memcpy(buf, &sb->wTime, sizeof(int));
	buf += sizeof(int);
	memcpy(buf, &sb->magic, sizeof(short));
	buf += sizeof(short);
	memcpy(buf, &sb->dataBlocksCount, sizeof(long long));
	buf += sizeof(long long);
	memcpy(buf, &sb->freeBlocksCount, sizeof(long long));
	buf += sizeof(long long);
	memcpy(buf, &sb->interval, sizeof(int));
	buf += sizeof(int);
}

void
buf_to_sb(char *buf, SBlock * sb)
{
	memcpy(sb->fileSystemName, buf, FNameLength * sizeof(char));
	buf = buf + FNameLength * sizeof(char);
	memcpy(&sb->totalSize, buf, sizeof(long long));
	buf += sizeof(long long);
	memcpy(&sb->vnodeCount, buf, sizeof(short));
	buf += sizeof(short);
	memcpy(&sb->blockSize, buf, sizeof(long long));
	buf += sizeof(long long);
	memcpy(&sb->mTime, buf, sizeof(int));
	buf += sizeof(int);
	memcpy(&sb->wTime, buf, sizeof(int));
	buf += sizeof(int);
	memcpy(&sb->magic, buf, sizeof(short));
	buf += sizeof(short);
	memcpy(&sb->dataBlocksCount, buf, sizeof(long long));
	buf += sizeof(long long);
	memcpy(&sb->freeBlocksCount, buf, sizeof(long long));
	buf += sizeof(long long);
	memcpy(&sb->interval, buf, sizeof(int));
	buf += sizeof(int);
}

void
vnode_to_buf(char *buf, vnode * v)
{
	int i;
	memcpy(buf, v->cameraid, CNameLength * sizeof(char));
	buf = buf + CNameLength * sizeof(char);
	memcpy(buf, v->alias, CNameLength * sizeof(char));
	buf = buf + CNameLength * sizeof(char);
	memcpy(buf, v->volName, VolNameLength * sizeof(char));
	buf = buf + VolNameLength * sizeof(char);
	for (i = 0; i < MaxchunkCount; i++) {
		memcpy(buf, &(v->block[i][0]), sizeof(int));
		buf += sizeof(int);
		memcpy(buf, &(v->block[i][1]), sizeof(int));
		buf += sizeof(int);
	}
	memcpy(buf, &v->storeAddr, sizeof(long long));
	buf += sizeof(long long);
	memcpy(buf, &v->curSnode, sizeof(long long));
	buf += sizeof(long long);
	memcpy(buf, &v->firstIndex, sizeof(long long));
	buf += sizeof(long long);
	memcpy(buf, &v->queryAdd, sizeof(long long));
	buf += sizeof(long long);
	memcpy(buf, &v->isRecycle, sizeof(char));
	buf += sizeof(char);
	memcpy(buf, &v->savedDays, sizeof(short));
	buf += sizeof(short);
	memcpy(buf, &v->delPolicy, sizeof(char));
	buf += sizeof(char);
	memcpy(buf, &v->encodeType, sizeof(char));
	buf += sizeof(char);
	memcpy(buf, &v->SnodeRecycle, sizeof(char));
	buf += sizeof(char);
	memcpy(buf, &v->count, sizeof(short));
	buf += sizeof(short);
	memcpy(buf, &v->wr_count, sizeof(short));
	buf += sizeof(short);
	memcpy(buf, &v->status, sizeof(char));
}

void
buf_to_vnode(char *buf, vnode * v)
{
	int i;
	memcpy(v->cameraid, buf, CNameLength * sizeof(char));
	buf = buf + CNameLength * sizeof(char);
	memcpy(v->alias, buf, CNameLength * sizeof(char));
	buf = buf + CNameLength * sizeof(char);
	memcpy(v->volName, buf, VolNameLength * sizeof(char));
	buf = buf + VolNameLength * sizeof(char);
	for (i = 0; i < MaxchunkCount; i++) {
		memcpy(&(v->block[i][0]), buf, sizeof(int));
		buf += sizeof(int);
		memcpy(&(v->block[i][1]), buf, sizeof(int));
		buf += sizeof(int);
	}
	memcpy(&v->storeAddr, buf, sizeof(long long));
	buf += sizeof(long long);
	memcpy(&v->curSnode, buf, sizeof(long long));
	buf += sizeof(long long);
	memcpy(&v->firstIndex, buf, sizeof(long long));
	buf += sizeof(long long);
	memcpy(&v->queryAdd, buf, sizeof(long long));
	buf += sizeof(long long);
	memcpy(&v->isRecycle, buf, sizeof(char));
	buf += sizeof(char);
	memcpy(&v->savedDays, buf, sizeof(short));
	buf += sizeof(short);
	memcpy(&v->delPolicy, buf, sizeof(char));
	buf += sizeof(char);
	memcpy(&v->encodeType, buf, sizeof(char));
	buf += sizeof(char);
	memcpy(&v->SnodeRecycle, buf, sizeof(char));
	buf += sizeof(char);
	memcpy(&v->count, buf, sizeof(short));
	buf += sizeof(short);
	memcpy(&v->wr_count, buf, sizeof(short));
	buf += sizeof(short);
	memcpy(&v->status, buf, sizeof(char));
	v->_bf = NULL;		//æåå¯¹åºççŒå²åº
}

void
DSI_to_buf(char *buf, seginfo * seg)
{
	memcpy(buf, &seg->size, sizeof(int));
	buf += sizeof(int);
	memcpy(buf, &seg->frame, sizeof(int));
	buf += sizeof(int);
	memcpy(buf, &seg->width, sizeof(short));
	buf += sizeof(short);
	memcpy(buf, &seg->height, sizeof(short));
	buf += sizeof(short);
	memcpy(buf, &seg->des, sizeof(char) * MaxDesLen);
}

void
buf_to_DSI(char *buf, seginfo * seg)
{
	memcpy(&seg->size, buf, sizeof(int));
	buf += sizeof(int);
	memcpy(&seg->frame, buf, sizeof(int));
	buf += sizeof(int);
	memcpy(&seg->width, buf, sizeof(short));
	buf += sizeof(short);
	memcpy(&seg->height, buf, sizeof(short));
	buf += sizeof(short);
	memcpy(seg->des, buf, sizeof(char) * MaxDesLen);
}

int
cal_blocks(vnode * v)
{				//æ ¹æ®vnodeè®¡ç®åºå·²ç»åéçåæ°
	int i, j;
	int sum = 0;
	for (i = 0; i < MaxchunkCount && v->block[i][0] != CHUNKNULL; i++) {
		j = v->block[i][0];
		while (j < v->block[i][1]) {
			sum++;
			j++;
		}
	}			//end for( i=0;????
	return sum;
}

/*
äžºvnodeå°è¯åéæ°æ®åä¹åïŒç¶ååè®Ÿçœ®bitmap
*/
int
set_clr_bitmap(_sbinfo sbinfo, vnode * v, int flag)
{
	int i, j;
	for (i = 0; i < MaxchunkCount && v->block[i][0] != CHUNKNULL; i++) {
		j = v->block[i][0];
		while (j < v->block[i][1]) {
			if (flag == 1)
				setbit_(sbinfo->bitmap, j);
			else
				clrbit_(sbinfo->bitmap, j);
			j++;
		}
	}
	return 0;
}

int
free_blocks(_sbinfo sbinfo, vnode * v, int time)
{				//å°superblockçç¶ææ¢å€å°åévä¹å
	sbinfo->_es->wTime = time;
	sbinfo->_es->vnodeCount--;
	sbinfo->_es->freeBlocksCount += cal_blocks(v);
	set_clr_bitmap(sbinfo, v, 0);
	return 0;
}

int
free_vnode(_sbinfo sbinfo, vnode * v)
{
	//added by wsr 20121029
	char buf[Vnode_SIZE * MaxUsers];
	memset(buf, 0, Vnode_SIZE * MaxUsers);
	spin_wrlock(v->spin);
	buf_to_vnode(buf, v);
	spin_rwunlock(v->spin);
	//end
	spin_rwdestroy(v->spin);
	return clrbit_(sbinfo->vnodemapping, (address_of_pointer(v) - address_of_pointer(sbinfo->vnodeTable)) / (sizeof(vnode)));
}

int
put_sb(_sbinfo sbinfo, vnode * v)
{
	int fd1;
	char buf[SB_SIZE];
	uint32_t temp;
	temp = sbinfo->_es->wTime;
	pthread_mutex_lock(&sbinfo->mutex);
	if ((fd1 = open(sbinfo->volName, O_WRONLY)) < 0) {
		pthread_mutex_unlock(&sbinfo->mutex);
		ErrorFlag = OPEN_FILE_ERR;
		return -1;
	}
	pthread_mutex_unlock(&sbinfo->mutex);
	sbinfo->_es->wTime = (uint32_t) time(NULL);
	sb_to_buf(buf, sbinfo->_es);
	if (v == NULL) {	//如果当写的过程中出错，不需要维护一致性
		if (_write(fd1, buf, SB_SIZE, 0) < 0)
			goto err1;
		if (_write(fd1, sbinfo->bitmap, MaxBlocks, BitmapAddr) < 0)
			goto err1;
		// if(_write(fd1,sbinfo->vnodemapping,MaxUsers/8,VBitmapAddr)<0) goto err1;
	}			//end if(v!=NULL)?
	else {
		if (_write(fd1, (char *)buf, SB_SIZE, 0) < 0) {
			free_blocks(sbinfo, v, temp);	//如果分配一个vnode出错，则内存superbilock恢复到vnode分配之前的状态。
			ErrorFlag = WRITE_LVM_ERR;
			goto err1;
		}
		if (_write(fd1, sbinfo->bitmap, MaxBlocks, BitmapAddr) < 0) {
			free_blocks(sbinfo, v, temp);
			sb_to_buf(buf, sbinfo->_es);
			lseek64(fd1, 0, SEEK_SET);	//因为superblock已经写入逻辑卷，需要重新写入。
			write(fd1, buf, SB_SIZE);
			ErrorFlag = WRITE_LVM_ERR;
			goto err1;
		}
	}			//end else
	close(fd1);
	return 0;
      err1:
	close(fd1);
	return -1;
}

char *
extend_buf(vnode * v, _sbinfo sbinfo, char mode)
{				//è¯»çæ¶åéèŠåéåšsbinfo->_bhçŒå²åºäž­åéäžäžªvnodeInfo
	int nr;
	uint8_t key = 0;
	_vnodeInfo vi, p;
	while (spin_trywrlock(sbinfo->_bh->spin));
	if ((nr = find_first_zero(sbinfo->_bh->map, MaxBufBitmapLen * 8)) == MaxBufBitmapLen * 8) {
		ErrorFlag = MAX_RDWR_COUNT;
		spin_rwunlock(sbinfo->_bh->spin);
		return NULL;
	}
	setbit_(sbinfo->_bh->map, nr);
	spin_rwunlock(sbinfo->_bh->spin);
	// if(!v->_bf) spin_rwinit(v->spin);
	while (spin_wrlock(v->spin));	/////////
	vi = v->_bf;
	if (vi == NULL || vi->key > key) {	//分配key是有序的。
		p = v->_bf;
		v->_bf = (_vnodeInfo) (sbinfo->_bf + sizeof(struct vnodeInfo) * nr);
		v->_bf->next = p;
		vi = v->_bf;
		p = NULL;
	} else {
		while (vi) {
			key++;
			if (!vi->next || vi->next->key > key) {
				p = vi->next;
				vi->next = (_vnodeInfo) (sbinfo->_bf + sizeof(struct vnodeInfo) * nr);
				vi->next->next = p;
				p = vi;
				vi = vi->next;
				break;
			}
			vi = vi->next;
		}
	}			//end else???
	pthread_mutex_lock(&sbinfo->mutex);
	vi->fd = open(sbinfo->volName, O_RDWR);
	pthread_mutex_unlock(&sbinfo->mutex);
	pthread_mutex_init(&vi->mutex, NULL);
	if (vi->fd <= 2) {
		pthread_mutex_lock(&sbinfo->mutex);
		vi->fd = open(sbinfo->volName, O_RDWR);
		pthread_mutex_unlock(&sbinfo->mutex);
	}
	spin_rwunlock(v->spin);
	// }
	/* else {
	   ErrorFlag=LOCK_ERR;
	   return NULL;
	   } */
	vi->key = key;
	vi->ID = ((char *)v - (char *)sbinfo->vnodeTable) / sizeof(vnode);
	if (mode == ReadRECORD) {
		vi->status = ReadRECORD;
		vi->nextTimeAddr = 0;
		vi->count = TimeNULL;
		//vi->fd=open(sbinfo->volName,O_RDWR);
		//   if(vi->fd<=2){
		//      vi->fd=open(sbinfo->volName,O_RDWR);
		//      }
	} else {
		vi->count = 0;
		vi->status = WriteRECORD;
		vi->is_starttime = NOTSET;
		// vi->fd=open(sbinfo->volName,O_RDWR);
		//  if(vi->fd<=2){
		//close(vi->fd);
		//   vi->fd=open(sbinfo->volName,O_RDWR);
		//   }
	}
	//////////////////////////////////////////////
	if (vi->fd < 0) {
		while (spin_trywrlock(sbinfo->_bh->spin));
		clrbit_(sbinfo->_bh->map, nr);
		spin_rwunlock(sbinfo->_bh->spin);
		while (spin_trywrlock(v->spin));
		if (p)
			p->next = p->next->next;
		else
			v->_bf = vi->next;
		spin_rwunlock(v->spin);
		pthread_mutex_destroy(&vi->mutex);
		ErrorFlag = ALLOC_FD_ERR;
		return NULL;
	}
	//  v->status++;
	return (char *)vi;
}

int
free_vi(_sbinfo sbinfo, int nr)
{
	while (spin_trywrlock(sbinfo->_bh->spin));
	clrbit_(sbinfo->_bh->map, nr);
	spin_rwunlock(sbinfo->_bh->spin);
	return 0;
}

_vnodeInfo
alloc_vi(_sbinfo sbinfo)
{
	int nr;
	while (spin_trywrlock(sbinfo->_bh->spin));
	if ((nr = find_first_zero(sbinfo->_bh->map, MaxBufBitmapLen * 8)) == MaxBufBitmapLen * 8) {
		ErrorFlag = MAX_RDWR_COUNT;
		spin_rwunlock(sbinfo->_bh->spin);
		return NULL;
	}
	spin_rwunlock(sbinfo->_bh->spin);
	return (_vnodeInfo) (sbinfo->_bf + sizeof(struct vnodeInfo) * nr);
}

int
put_vnode(_sbinfo sbinfo, vnode * v, char *_vbitmap, int ID)
{				//ævnodeåæŽäžªvnodebitmapäœåŸååé»èŸå·ïŒåœIDäžºïŒ1æ¶ïŒäžéèŠååvnode
	int fd;
	char buf[Vnode_SIZE];
	pthread_mutex_lock(&sbinfo->mutex);
	if ((fd = open(sbinfo->volName, O_WRONLY)) < 0) {
		pthread_mutex_unlock(&sbinfo->mutex);
		ErrorFlag = OPEN_FILE_ERR;
		return -1;
	}
	pthread_mutex_unlock(&sbinfo->mutex);
	if (ID != -1) {
		vnode_to_buf(buf, v);
		if (_write(fd, buf, Vnode_SIZE, VnodeAddr + ID * Vnode_SIZE) < 0) {
			close(fd);
			ErrorFlag = WRITE_LVM_ERR;
			return -1;
		}
	}			//end if(addr!=-1)?? 
	if (_vbitmap && (_write(fd, _vbitmap, MaxUsers / 8, VBitmapAddr) < 0)) {
		close(fd);
		ErrorFlag = WRITE_LVM_ERR;
		return -1;
	}
	close(fd);
	return 0;
}

int
test_or_alloc_ID(_sbinfo sbinfo, char *name, int len, int *n, int flag)
{
//*nÊÇ·µ»ØµÄID£¬lenÊÇnameµÄ³€¶È¡£flag==0±íÊŸÓÃÓÚ²éÕÒ»òÕß²âÊÔ£¬flag==1,ÓÃÓÚ·ÖÅävnode
	int count = 0;
	int flag1 = 0;
	(*n) = buf_hash(name, len);
	while (count < MaxUsers && (*n) < MaxUsers) {
		if (bit(sbinfo->vnodemapping, *n)) {
			if (strcmp(((vnode *) ((char *)sbinfo->vnodeTable + (*n) * sizeof(vnode)))->cameraid, name) == 0) {
				flag1 = 1;
				break;
			}
		}
		(*n) = ((*n) + 1) % MaxUsers;
		count++;
	}			//end while()???

	return flag1;
}

int
cal_alloc_chunk(_sbinfo sbinfo, vnode * v, unsigned long long  blocks)
{				//é¢åéæ°æ®å
	int nr, i = 0, sum = 0;
	nr = find_first_zero(sbinfo->bitmap, MaxBlocks * 8);
	while (sum < blocks && i < MaxchunkCount) {
		v->block[i][0] = nr;
		sum++;
		nr++;
		while (sum < blocks && !bit(sbinfo->bitmap, nr)) {
			nr++;
			sum++;
		}
		v->block[i][1] = nr;
		if (i == 0 && sum < 2 && sum < blocks)
			sum = 0;
		else
			i++;
		while (bit(sbinfo->bitmap, nr))
			nr++;
	}			//end (sum<=blocks && i<MaxchunkCount)?
	if (i == MaxchunkCount || sum < blocks) {
		ErrorFlag = TOO_FLAGS;
		//_Debug("too frags\n",__LINE__,__FILE__);
		for (i = 0; i < MaxchunkCount; i++)
			v->block[i][0] = CHUNKNULL;
		return -1;
	}			//end if(i==MaxchunkCount || sum<blocks)?
	while (i < MaxchunkCount) {
		v->block[i][0] = CHUNKNULL;
		i++;
	}
	return 0;
}

_sbinfo
get_sbinfo(const char *volumeid)
{
	_sbinfo sbinfo = NULL;
	int handle;
	if (!spin_tryrdlock(sbTable.spin)) {
		for (handle = 0; handle < LvmCount; handle++) {
			sbinfo = sbTable.table[handle];
			if (sbinfo && strcmp(volumeid, sbTable.table[handle]->volName) == 0)
				break;
		}		//end for(handle=0;handle<LvmCount;handle++)???
		spin_rwunlock(sbTable.spin);
	}			//end if(!spin_rdlock(sbTable.spin))???
	else {
		ErrorFlag = CREATING_LVM;
		return sbinfo;
	}
	if (!sbinfo)
		ErrorFlag = NOT_EXIST_LVM;
	return sbinfo;
}

_vnodeInfo
get_Vi(vnode * v, int key)
{				//mode æ¯è¯»æèåïŒåœäžºè¯»çæ¶åïŒkeyäžºçŽ¢åŒ
	_vnodeInfo vi = NULL;
	if (!v->_bf)
		return NULL;
	while (spin_tryrdlock(v->spin));
//if(!spin_rdlock(v->spin)){
	for (vi = v->_bf; vi; vi = vi->next)
		if (vi->key == key)
			break;
	spin_rwunlock(v->spin);
//}
	return vi;
}

int
delete_vi(_sbinfo sbinfo, vnode * v, char mode, int key)
{				//å¯èœäŒå²çª
	_vnodeInfo vi, p;
	while (spin_wrlock(v->spin));
	if (mode == WriteRECORD) {
        vi = v->_bf;
        while(vi) {
            if (vi->status == WriteRECORD)
			    break;
            p = vi;
            vi = vi->next;
        }            
	}			//end if(mode==WriteRECORD){????
	else {
        vi = v->_bf;
        while(vi) {
            if (vi->status == ReadRECORD && vi->key == key)
			    break;
            p = vi;
            vi = vi->next;
        }     
	}			//end else??
	if (!vi) {
		spin_rwunlock(v->spin);
		return -1;
	}
    if(vi == v->_bf)
        v->_bf = vi->next;
	else
		p->next = vi->next;
	spin_rwunlock(v->spin);
	//if(!v->_bf) spin_rwdestroy(v->spin);
// v->status--;
	return (((char *)vi) - (char *)sbinfo->_bf) / sizeof(struct vnodeInfo);
}

int
get_dev_ID(const char *cameraid, _sbinfo * sbinf)
{
	int m, n;
	int flag = 0, count = 0;
	int handle = 0;
	_sbinfo sbinfo = NULL;
	char *vbitmap;
	int fd;
	char buf[Vnode_SIZE];
	vnode *v;
	char vol_path[VolNameLength];
	if (read_vol_by_camera(vol_path, cameraid) < 0) {
		//ErrorFlag = NOT_EXIST_RECORD;
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
		sbinfo = (_sbinfo) init(vol_path);
		if (!sbinfo)
			return -1;
		for (handle = 0; handle < LvmCount; handle++)
			if (sbinfo == sbTable.table[handle])
				break;
	}
	n = buf_hash((char *)cameraid, strlen(cameraid));
	count = 0;
	m = n;
	while (count < MaxUsers && m < MaxUsers) {
		if (bit(sbinfo->vnodemapping, m)) {
			if (strcmp(((vnode *) ((char *)sbinfo->vnodeTable + m * sizeof(vnode)))->cameraid, cameraid) == 0) {
				flag = 1;
				m = m << 16 & 0xFFFF0000;
				break;
			}	//end if(strcmp(????
		}		//end if(bit???
		m = (m + 1) % MaxUsers;
		count++;
	}			//end while????
	if (flag == 0) {
		ErrorFlag = NOT_EXIST_RECORD;
		return -1;
	}
	if (sbinf)
		*sbinf = sbinfo;
	handle = handle << 8 & 0x0000FF00;
	handle = handle | m;
	return handle;
}




