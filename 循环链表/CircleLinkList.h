#ifndef CIRCLELINKLIST_H
#define CIRCLELINKLIST_H
#define TURE 1
#define FALSE 0

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

typedef struct CIRCLELINKNODE
{
	struct CIRCLELINKNODE* next;
}CircleLinkNode;

typedef struct CIRCLELINKLIST
{
	CircleLinkNode head;
	int size;
}CircleLinkList;


//比较
typedef int (*COMPARANODE)(CircleLinkNode*, CircleLinkNode*);
//打印
typedef void (*PRINTFNODE)(CircleLinkNode*);

//初始化
CircleLinkList* Init_CircleLinkList();

//插入
void Insert_CircleLinkList(CircleLinkList* list, int pos, CircleLinkNode* data);

//获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* list);

//根据位置删除
void RemoveBypos_LinkList(CircleLinkList* list, int pos);

//根据数值删除
void RemoveByvalue_LinkList(CircleLinkList* list, CircleLinkNode* data, COMPARANODE compara);

//获得链表长度
int Size_LinkList(CircleLinkList* list);

//判断是否为空
int IsEmpty_LinkList(CircleLinkList* list);

//查找
int Find_LinkList(CircleLinkList* list, CircleLinkNode* data, COMPARANODE compara);

//打印链表节点
void Print_LinkList(CircleLinkList* list, PRINTFNODE print);

//释放链表内存
void FreeSpeace_LinkList(CircleLinkList* list);


#endif