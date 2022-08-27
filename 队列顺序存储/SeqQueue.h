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

//初始化
SeqQueue* Init_SeqQueue();

//入栈
void Push_SeqQueue(SeqQueue* queue, void* data);

//返回队头元素
void* Top_SeqQueue(SeqQueue* queue);

void* Back_SeqQueue(SeqQueue* queue);

//出栈
void Pop_SeqQueue(SeqQueue* queue);

//判断是否为空
int IsEmpty(SeqQueue* queue);

//返回栈中元素的个数
int Size_SeqQueue(SeqQueue* queue);

//清空
void Clear_SeqQueue(SeqQueue* queue);

//销毁
void FreeSpeace_SeqQueue(SeqQueue* queue);


#endif