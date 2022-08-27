#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

typedef struct LINKNODE
{
	struct LINKNODE* next;	//�ҹ�
}LinkNode;

typedef struct LINKSTACK
{
	LinkNode head;
	int size;
}LinkStack;

//��ʼ��
LinkStack* Init_LinkStack();

//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack);

//��ջ
void Push_LinkStack(LinkStack* stack, LinkNode* data);

//��ջ
void Pop_LinkStack(LinkStack* stack);

//����ջ��Ԫ�صĸ���
int Size_LinkStack(LinkStack* stack);

//���
void Clear_LinkStack(LinkStack* stack);

//�ͷ�
void FreeSpeace_LinkStack(LinkStack* stack);

#endif
