#include "LinkList.h"

//��ʼ��
LinkList* Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;

	//ͷ�ڵ㣬����������
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;


	return list;
}

//����
int Find_LinkList(LinkList* list, void* data)
{
	if (list == NULL || data == NULL)
	{
		return -1;
	}

	int num = 0;
	LinkNode* pCurrent = list->head->next;

	while (pCurrent != NULL)
	{
		if (pCurrent->data == data)
		{
			break;
		}
		num++;

		pCurrent = pCurrent->next;
	}

	return num;
}

//����λ�ò���
void Insert_LinkList(LinkList* list, int pos,void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//posԽ��
	if (pos < 0 || pos > list->size)
	{
		pos = list->size;
	}

	//�����µĽڵ�
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//�ҽڵ�
	//����ָ�����
	LinkNode* pCurrent = list->head;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�½ڵ�������
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	list->size++;
}

//ɾ��ָ��λ�õ�ֵ
void RemoveBypos_LinkList(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}

	if (pos < 0 || pos > list->size)
	{
		return;
	}

	LinkNode* pCurrent = list->head;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//��Ŵ�ɾ���ڵ�
	LinkNode* pDel = pCurrent->next;	//���ҵ���λ�ýڵ����һ����(��ɾ���ı�)��ֵ��һ���±�
	pCurrent->next = pDel->next;	//ɾ��λ�õı����һ�����ַ��ɾ���ı�ǰ����next

	//�ͷŴ�ɾ���ڵ�
	free(pDel);

	list->size--;
}

//���������
int Size_LinkList(LinkList* list)
{

	return list->size;
}

//���ص�һ���ڵ�λ��
void* GetHead_LinkList(LinkList* list)
{
	return list->head->next->data;
}

//��ӡ����ڵ�
void* Print_LinkList(LinkList* list, PRINTLINKNODE print)
{
	if (list == NULL)
	{
		return 0;
	}

	LinkNode* pCurrent = list->head->next;

	while (pCurrent != NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}


	return NULL;
}

//�ͷ������ڴ�
void FreeSpeace_LinkList(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}

	LinkNode* pCurrent = list->head;

	while (pCurrent != NULL)
	{
		//������һ���ڵ�
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	list->size = 0;
	free(list);

}