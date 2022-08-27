#ifndef LINUXLINKLIST_H
#define LINUXLINKLIST_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

//链表小节点
typedef struct LINKNODE
{
	struct LINKNODE* next;	//挂钩
}LinkNode;

typedef struct LINKLIST
{
	LinkNode head;
	int size;
}LinkList;

typedef void(*PRINTFNODE)(LinkNode*);

//比较函数指针
typedef int(*COMPARA)(LinkNode*, LinkNode*);

//初始化
LinkList* Init_LinkList();

//查找
int Find_LinkList(LinkList* list, LinkNode* data, COMPARA compara);

//根据位置插入
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);

//删除指定位置的值
void RemoveBypos_LinkList(LinkList* list, int pos);

//获得链表长度
int Size_LinkList(LinkList* list);

//打印链表节点
void Print_LinkList(LinkList* list, PRINTFNODE print);

//释放链表内存
void FreeSpeace_LinkList(LinkList* list);


#endif
