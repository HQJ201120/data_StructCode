#include "CircleLinkList.h"

//��ʼ��
CircleLinkList* Init_CircleLinkList()
{
	CircleLinkList* list = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	list->size = 0;
	list->head.next = &(list->head);


	return list;
}

//����
void Insert_CircleLinkList(CircleLinkList* list, int pos, CircleLinkNode* data)
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
	CircleLinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�����½ڵ�
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
}

//��õ�һ��Ԫ��
CircleLinkNode* Front_CircleLinkList(CircleLinkList* list)
{
	return list->head.next;
}

//����λ��ɾ��
void RemoveBypos_LinkList(CircleLinkList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}

	if (pos < 0 || pos >= list->size)
	{
		return;
	}

	CircleLinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//���浱ǰ�ڵ����һ���ڵ�
	CircleLinkNode* pNext = pCurrent->next;
	pCurrent->next = pNext->next;

	list->size--;

}

//������ֵɾ��
void RemoveByvalue_LinkList(CircleLinkList* list, CircleLinkNode* data, COMPARANODE compara)
{
	if (list == NULL || data == NULL)
	{
		return;
	}

	CircleLinkNode* pPrev = &(list->head);	//��ɾ��ָ���ǰһ��
	CircleLinkNode* pCurrent = pPrev->next;	//��ɾ��ָ��
	for (int i = 0; i < list->size; i++)
	{
		if (compara(pCurrent, data) == TURE)
		{
			pPrev->next = pCurrent->next;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pPrev->next;
	}

	list->size--;

}

//���������
int Size_LinkList(CircleLinkList* list)
{
	if (list == NULL)
	{
		return -1;
	}
	
	return list->size;
}

//�ж��Ƿ�Ϊ��
int IsEmpty_LinkList(CircleLinkList* list)
{
	if (list->size == 0)
	{
		return TURE;
	}

	return FALSE;
}

//����
int Find_LinkList(CircleLinkList* list, CircleLinkNode* data, COMPARANODE compara)
{
	if (list == NULL || data == NULL)
	{
		return -1;
	}

	int flag = -1;
	CircleLinkNode* pCurrent = list->head.next;
	for (int i = 0; i < list->size; i++)
	{
		if (compara(pCurrent, data) == TURE)
		{
			flag = i;
			break;
		}

		pCurrent = pCurrent->next;
	}

	return flag;
}

//��ӡ����ڵ�
void Print_LinkList(CircleLinkList* list, PRINTFNODE print)
{
	if (list == NULL)
	{
		return;
	}

	CircleLinkNode* pCurrent = list->head.next;
	for (int i = 0; i < list->size; i++)
	{
		print(pCurrent);

		pCurrent = pCurrent->next;
	}

}

//�ͷ������ڴ�
void FreeSpeace_LinkList(CircleLinkList* list)
{
	if (list != NULL)
	{
		return;
	}

	free(list);
}