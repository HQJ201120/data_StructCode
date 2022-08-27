#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include "CircleLinkList.h"

#define M 8
#define N 3

typedef struct MYNUM
{
	CircleLinkNode node;
	int value;
}MyNum;

void Myprintf(CircleLinkNode* data)
{
	MyNum* p = (MyNum*)data;
	printf("%d ", p->value);
}

int Compara(CircleLinkNode* data1, CircleLinkNode* data2)
{
	if (data1 == NULL || data2 == NULL)
	{
		return FALSE;
	}

	MyNum* p1 = (MyNum*)data1;
	MyNum* p2 = (MyNum*)data2;

	if (p1->value == p2->value)
	{
		return TURE;
	}

	return FALSE;

}

int main(void)
{
	//创建
	CircleLinkList* list = Init_CircleLinkList();

	//插入
	MyNum num[M];

	for (int i = 0; i < 8; i++)
	{
		num[i].value = i + 1;
		Insert_CircleLinkList(list, i, (CircleLinkNode*)&num[i]);
	}

	Print_LinkList(list, Myprintf);

	printf("\n");

	int index = 1;
	CircleLinkNode* pCurrent = list->head.next;
	while (Size_LinkList(list) > 1)
	{
		if (index == N)
		{
			MyNum* temnum = (MyNum*)pCurrent;
			printf("%d ", temnum->value);

			//缓存待删除节点的下一个节点
			CircleLinkNode* pNext= pCurrent->next;

			RemoveByvalue_LinkList(list, pCurrent, Compara);
			pCurrent = pNext;

			if (pCurrent == &(list->head))
			{
				pCurrent = pCurrent->next;
			}
			index = 1;
		}

		pCurrent = pCurrent->next;
		if (pCurrent == &(list->head))
		{
			pCurrent = pCurrent->next;
		}

		index++;
	}

	if (Size_LinkList(list) == 1)
	{
		MyNum* tmpNum = (MyNum*)Front_CircleLinkList(list);

		printf("%d ", tmpNum->value);
	}
	else
	{
		printf("ERROR");
	}


	FreeSpeace_LinkList(list);

	return 0;
}