#include "CircleLinkList.h"

//初始化
CircleLinkList* Init_CircleLinkList()
{
	CircleLinkList* list = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	list->size = 0;
	list->head.next = &(list->head);


	return list;
}

//插入
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

	//查找
	CircleLinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//插入新节点
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
}

//获得第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* list)
{
	return list->head.next;
}

//根据位置删除
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

	//缓存当前节点的下一个节点
	CircleLinkNode* pNext = pCurrent->next;
	pCurrent->next = pNext->next;

	list->size--;

}

//根据数值删除
void RemoveByvalue_LinkList(CircleLinkList* list, CircleLinkNode* data, COMPARANODE compara)
{
	if (list == NULL || data == NULL)
	{
		return;
	}

	CircleLinkNode* pPrev = &(list->head);	//被删除指针的前一个
	CircleLinkNode* pCurrent = pPrev->next;	//被删除指针
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

//获得链表长度
int Size_LinkList(CircleLinkList* list)
{
	if (list == NULL)
	{
		return -1;
	}
	
	return list->size;
}

//判断是否为空
int IsEmpty_LinkList(CircleLinkList* list)
{
	if (list->size == 0)
	{
		return TURE;
	}

	return FALSE;
}

//查找
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

//打印链表节点
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

//释放链表内存
void FreeSpeace_LinkList(CircleLinkList* list)
{
	if (list != NULL)
	{
		return;
	}

	free(list);
}