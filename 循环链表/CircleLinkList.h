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


//�Ƚ�
typedef int (*COMPARANODE)(CircleLinkNode*, CircleLinkNode*);
//��ӡ
typedef void (*PRINTFNODE)(CircleLinkNode*);

//��ʼ��
CircleLinkList* Init_CircleLinkList();

//����
void Insert_CircleLinkList(CircleLinkList* list, int pos, CircleLinkNode* data);

//��õ�һ��Ԫ��
CircleLinkNode* Front_CircleLinkList(CircleLinkList* list);

//����λ��ɾ��
void RemoveBypos_LinkList(CircleLinkList* list, int pos);

//������ֵɾ��
void RemoveByvalue_LinkList(CircleLinkList* list, CircleLinkNode* data, COMPARANODE compara);

//���������
int Size_LinkList(CircleLinkList* list);

//�ж��Ƿ�Ϊ��
int IsEmpty_LinkList(CircleLinkList* list);

//����
int Find_LinkList(CircleLinkList* list, CircleLinkNode* data, COMPARANODE compara);

//��ӡ����ڵ�
void Print_LinkList(CircleLinkList* list, PRINTFNODE print);

//�ͷ������ڴ�
void FreeSpeace_LinkList(CircleLinkList* list);


#endif