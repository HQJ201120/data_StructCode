#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

typedef void(*PRINTLINKNODE)(void*);

//链表节点
typedef struct LINKNODE
{
	void* data;
	struct LINKNODE* next;
}LinkNode;


//链表结构图
typedef struct LINKLIST
{
	LinkNode* head;
	int size;
}LinkList;

//初始化;
LinkList* Init_LinkList();

//查找
int Find_LinkList(LinkList* list, void* value);

//根据位置插入
void Insert_LinkList(LinkList* list, int pos,void* data);

//删除指定位置的值
void RemoveBypos_LinkList(LinkList* list, int pos);

//获得链表长度
int Size_LinkList(LinkList* list);

//返回第一个节点位置
void* GetHead_LinkList(LinkList* list);

//打印链表节点
void* Print_LinkList(LinkList* list, PRINTLINKNODE print);

//释放链表内存
void FreeSpeace_LinkList(LinkList* list);


#endif