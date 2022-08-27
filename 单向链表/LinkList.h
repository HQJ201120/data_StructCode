#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

typedef void(*PRINTLINKNODE)(void*);

//����ڵ�
typedef struct LINKNODE
{
	void* data;
	struct LINKNODE* next;
}LinkNode;


//����ṹͼ
typedef struct LINKLIST
{
	LinkNode* head;
	int size;
}LinkList;

//��ʼ��;
LinkList* Init_LinkList();

//����
int Find_LinkList(LinkList* list, void* value);

//����λ�ò���
void Insert_LinkList(LinkList* list, int pos,void* data);

//ɾ��ָ��λ�õ�ֵ
void RemoveBypos_LinkList(LinkList* list, int pos);

//���������
int Size_LinkList(LinkList* list);

//���ص�һ���ڵ�λ��
void* GetHead_LinkList(LinkList* list);

//��ӡ����ڵ�
void* Print_LinkList(LinkList* list, PRINTLINKNODE print);

//�ͷ������ڴ�
void FreeSpeace_LinkList(LinkList* list);


#endif