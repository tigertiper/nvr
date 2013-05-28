#ifndef _PARMS_H
#define _PARMS_H

#include"info.h"

void sb_to_buf(char *buf, SBlock * sb);
void buf_to_sb(char *buf, SBlock * sb);
void vnode_to_buf(char *buf, vnode * v);
void buf_to_vnode(char *buf, vnode * v);
void DSI_to_buf(char *buf, seginfo * seg);
void buf_to_DSI(char *buf, seginfo * seg);
int set_clr_bitmap(_sbinfo sbinfo, vnode * v, int flag);
int free_blocks(_sbinfo sbinfo, vnode * v, int time);
int put_sb(_sbinfo sbinfo, vnode * v);
char *extend_buf(vnode * v, _sbinfo sbinfo, char mode);
int test_or_alloc_ID(_sbinfo sbinfo, char *name, int len, int *n, int flag);
int cal_alloc_chunk(_sbinfo sbinfo, vnode * v, unsigned long long  blocks);
_sbinfo get_sbinfo(const char *volumeid);
_vnodeInfo get_Vi(vnode * v, int key);
int delete_vi(_sbinfo sbinfo, vnode * v, char mode, int key);
int free_vi(_sbinfo sbinfo, int nr);
_vnodeInfo alloc_vi(_sbinfo sbinfo);
int put_vnode(_sbinfo sbinfo, vnode * v, char *_vbitmap, int ID);
int free_vnode(_sbinfo sbinfo, vnode * v);

#endif

