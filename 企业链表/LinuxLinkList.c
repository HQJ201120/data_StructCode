#include "LinuxLinkList.h"

//初始化
LinkList* Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;


	return list;
}

//查找
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

//根据位置插入
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

	//查找
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//插入新节点
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
}

//删除指定位置的值
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

//获得链表长度
int Size_LinkList(LinkList* list)
{


	return list->size;
}

//打印链表节点
void Print_LinkList(LinkList* list, PRINTFNODE print)
{
	if (list == NULL)
	{
		return;
	}

	//辅助指针
	LinkNode* pCurrent = list->head.next;
	while (NULL != pCurrent)
	{
		print(pCurrent);

		pCurrent = pCurrent->next;
	}

}

//释放链表内存
void FreeSpeace_LinkList(LinkList* list)
{
	if (list != NULL)
	{
		return;
	}

	free(list);
}