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

//��ʼ��
LinkQueue* Init_LinkQueue();

//���
void Push_LinkQueue(LinkQueue* queue, LinkNode* data);

//����
void Pop_LinkQueue(LinkQueue* queue);

//�ж��Ƿ�Ϊ��
int IsEmpty(LinkQueue* queue);

//����Ԫ�ظ���
int Size_LinkQueue(LinkQueue* queue);

//���ض�ͷԪ��
void* Top_SeqQueue(LinkQueue* queue);

//���
void Clear_LinkQueue(LinkQueue* queue);

//�ͷ�
void Free_LinkQueue(LinkQueue* queue);

#endif
