#ifndef LINUXLINKLIST_H
#define LINUXLINKLIST_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

//����С�ڵ�
typedef struct LINKNODE
{
	struct LINKNODE* next;	//�ҹ�
}LinkNode;

typedef struct LINKLIST
{
	LinkNode head;
	int size;
}LinkList;

typedef void(*PRINTFNODE)(LinkNode*);

//�ȽϺ���ָ��
typedef int(*COMPARA)(LinkNode*, LinkNode*);

//��ʼ��
LinkList* Init_LinkList();

//����
int Find_LinkList(LinkList* list, LinkNode* data, COMPARA compara);

//����λ�ò���
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);

//ɾ��ָ��λ�õ�ֵ
void RemoveBypos_LinkList(LinkList* list, int pos);

//���������
int Size_LinkList(LinkList* list);

//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTFNODE print);

//�ͷ������ڴ�
void FreeSpeace_LinkList(LinkList* list);


#endif
