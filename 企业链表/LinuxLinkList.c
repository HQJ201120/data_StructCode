#include "LinuxLinkList.h"

//��ʼ��
LinkList* Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;


	return list;
}

//����
int Find_LinkList(LinkList* list, LinkNode* data, COMPARA compara)
{
	if (list == NULL || data == NULL)
	{
		return -1;
	}

	LinkNode* pCurrent = list->head.next;
	int index = 0;
	int flag = -1;
	while(pCurrent != NULL)
	{
		if (compara(pCurrent, data) == 0)
		{
			flag = index;
			break;
		}

		pCurrent = pCurrent->next;
		index++;
	}


	return flag;
}

//����λ�ò���
void Insert_LinkList(LinkList* list, int pos, LinkNode* data)
{
	if (list == NULL || data == NULL)
	{
		return;
	}

	if (pos < 0 || pos > list->size)
	{
		pos = list->size;
	}

	//����
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�����½ڵ�
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
}

//ɾ��ָ��λ�õ�ֵ
void RemoveBypos_LinkList(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}

	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	pCurrent->next = pCurrent->next->next;

	list->size--;
}

//���������
int Size_LinkList(LinkList* list)
{


	return list->size;
}

//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTFNODE print)
{
	if (list == NULL)
	{
		return;
	}

	//����ָ��
	LinkNode* pCurrent = list->head.next;
	while (NULL != pCurrent)
	{
		print(pCurrent);

		pCurrent = pCurrent->next;
	}

}

//�ͷ������ڴ�
void FreeSpeace_LinkList(LinkList* list)
{
	if (list != NULL)
	{
		return;
	}

	free(list);
}