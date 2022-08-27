#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

typedef struct LINKNODE
{
	struct LINKNODE* next;
}LinkNode;

typedef struct LINKQUEUE
{
	LinkNode head;
	int size;
}LinkQueue;

#define TRUE 1
#define FALSE 0

//初始化
LinkQueue* Init_LinkQueue();

//入队
void Push_LinkQueue(LinkQueue* queue, LinkNode* data);

//出队
void Pop_LinkQueue(LinkQueue* queue);

//判断是否为空
int IsEmpty(LinkQueue* queue);

//返回元素个数
int Size_LinkQueue(LinkQueue* queue);

//返回队头元素
void* Top_SeqQueue(LinkQueue* queue);

//清空
void Clear_LinkQueue(LinkQueue* queue);

//释放
void Free_LinkQueue(LinkQueue* queue);

#endif
