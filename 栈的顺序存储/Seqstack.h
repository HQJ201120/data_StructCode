#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

//����ȥģ��ջ��˳��洢
#define MaxSize 64
#define TURE 1
#define FALSE 0

typedef struct SQESTACK
{
	void* data[MaxSize];
	int size;
}SqeStack;

//��ʼ��
SqeStack* Init_SqeStack();

//��ջ
void Push_SqeStack(SqeStack* stack, void* data);

//����ջ��Ԫ��
void* Top_SqeStack(SqeStack* stack);

//��ջ
void Pop_SqeStack(SqeStack* satck);

//�ж��Ƿ�Ϊ��
int IsEmpty(SqeStack* stack);

//����ջ��Ԫ�صĸ���
int Size_SqeStack(SqeStack* stack);

//���
void Clear_SqeStack(SqeStack* stack);

//����
void FreeSpeace_SqeStack(SqeStack* stack);


#endif
