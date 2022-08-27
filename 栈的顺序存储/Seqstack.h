#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

//数组去模拟栈的顺序存储
#define MaxSize 64
#define TURE 1
#define FALSE 0

typedef struct SQESTACK
{
	void* data[MaxSize];
	int size;
}SqeStack;

//初始化
SqeStack* Init_SqeStack();

//入栈
void Push_SqeStack(SqeStack* stack, void* data);

//返回栈顶元素
void* Top_SqeStack(SqeStack* stack);

//出栈
void Pop_SqeStack(SqeStack* satck);

//判断是否为空
int IsEmpty(SqeStack* stack);

//返回栈中元素的个数
int Size_SqeStack(SqeStack* stack);

//清空
void Clear_SqeStack(SqeStack* stack);

//销毁
void FreeSpeace_SqeStack(SqeStack* stack);


#endif
