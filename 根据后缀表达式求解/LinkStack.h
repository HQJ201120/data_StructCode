#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

typedef struct LINKNODE
{
	struct LINKNODE* next;	//挂钩
}LinkNode;

typedef struct LINKSTACK
{
	LinkNode head;
	int size;
}LinkStack;

//初始化
LinkStack* Init_LinkStack();

//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack);

//入栈
void Push_LinkStack(LinkStack* stack, LinkNode* data);

//出栈
void Pop_LinkStack(LinkStack* stack);

//返回栈中元素的个数
int Size_LinkStack(LinkStack* stack);

//清空
void Clear_LinkStack(LinkStack* stack);

//释放
void FreeSpeace_LinkStack(LinkStack* stack);

#endif
