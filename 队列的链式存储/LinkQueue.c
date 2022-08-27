#include "LinkQueue.h"

//初始化
LinkQueue* Init_LinkQueue()
{
	LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
	if (queue == NULL)
	{
		perror("queue malloc err");
		return NULL;
	}

	queue->head.next = NULL;
	queue->size = 0;

	return queue;
}

//入队
void Push_LinkQueue(LinkQueue* queue, LinkNode* data)
{
	if (queue == NULL)
	{
		return;
	}

	LinkNode* pCurrent = &(queue->head);
	for (int i = 0; i < queue->size; i++)
	{
		pCurrent = pCurrent->next;
	}

	data->next = pCurrent->next;
	pCurrent->next = data;
	

	/*data->next = queue->head.next;
	queue->head.next = data;*/

	queue->size++;
}

//出队
void Pop_LinkQueue(LinkQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}

	LinkNode* pNext = queue->head.next;
	queue->head.next = pNext->next;

	queue->size--;
}

//判断是否为空
int IsEmpty(LinkQueue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	if (queue->size == 0)
	{
		return TRUE;
	}

	return FALSE;
}

//返回元素个数
int Size_LinkQueue(LinkQueue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	if (IsEmpty(queue) == TRUE)
	{
		return -1;
	}

	return queue->size;
}

//返回队头元素
void* Top_SeqQueue(LinkQueue* queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	return queue->head.next;
}

//清空
void Clear_LinkQueue(LinkQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	
	queue->head.next = NULL;
	queue->size = 0;
}

//释放
void Free_LinkQueue(LinkQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}

	free(queue);
}
