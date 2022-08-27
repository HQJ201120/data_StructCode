#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

#define MAXSIZE 64
#define TRUE 1
#define FALSE 0

typedef struct SEQQUEUE
{
	void* data[MAXSIZE];
	int size;
}SeqQueue;

//��ʼ��
SeqQueue* Init_SeqQueue();

//��ջ
void Push_SeqQueue(SeqQueue* queue, void* data);

//���ض�ͷԪ��
void* Top_SeqQueue(SeqQueue* queue);

void* Back_SeqQueue(SeqQueue* queue);

//��ջ
void Pop_SeqQueue(SeqQueue* queue);

//�ж��Ƿ�Ϊ��
int IsEmpty(SeqQueue* queue);

//����ջ��Ԫ�صĸ���
int Size_SeqQueue(SeqQueue* queue);

//���
void Clear_SeqQueue(SeqQueue* queue);

//����
void FreeSpeace_SeqQueue(SeqQueue* queue);


#endif