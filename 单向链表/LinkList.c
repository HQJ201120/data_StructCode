#include "LinkList.h"

//初始化
LinkList* Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;

	//头节点，不保存数据
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;


	return list;
}

//查找
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

//根据位置插入
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

	//pos越界
	if (pos < 0 || pos > list->size)
	{
		pos = list->size;
	}

	//创建新的节点
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//找节点
	//辅助指针变量
	LinkNode* pCurrent = list->head;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//新节点入链表
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	list->size++;
}

//删除指定位置的值
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

	//存放待删除节点
	LinkNode* pDel = pCurrent->next;	//把找到的位置节点的下一个表(该删除的表)赋值给一个新表
	pCurrent->next = pDel->next;	//删除位置的表的下一个表地址给删除的表前驱的next

	//释放待删除节点
	free(pDel);

	list->size--;
}

//获得链表长度
int Size_LinkList(LinkList* list)
{

	return list->size;
}

//返回第一个节点位置
void* GetHead_LinkList(LinkList* list)
{
	return list->head->next->data;
}

//打印链表节点
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

//释放链表内存
void FreeSpeace_LinkList(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}

	LinkNode* pCurrent = list->head;

	while (pCurrent != NULL)
	{
		//缓存下一个节点
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	list->size = 0;
	free(list);

}