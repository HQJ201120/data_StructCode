#include "SeqQueue.h"

//初始化
SeqQueue* Init_SeqQueue()
{
	SeqQueue* queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	if (queue == NULL)
	{
		perror("malloc queue");
		return NULL;
	}

	memset(queue->data, 0, MAXSIZE);
	queue->size = 0;

	return queue;
}

//入栈
void Push_SeqQueue(SeqQueue* queue, void* data)
{
	if (queue == NULL || data == NULL)
	{
		return;
	}

	if (queue->size == MAXSIZE)
	{
		return;
	}

	queue->data[queue->size] = data;

	queue->size++;

}

//返回队头元素
void* Top_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	return queue->data[0];
}

//返回队尾元素
void* Back_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	if (IsEmpty(queue) == TRUE)
	{
		printf("错误！为空！");
		return NULL;
	}

	return queue->data[queue->size - 1];
}

//出队
void Pop_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}

	if (IsEmpty(queue) == TRUE)
	{
		printf("错误！为空！");
		return;
	}

	for (int i = 0; i < queue->size - 1; i++)
	{
		queue->data[i] = queue->data[i + 1];
	}

	queue->size--;
}

//判断是否为空
int IsEmpty(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	if (queue->size == 0)
	{
		printf("错误！为空！");
		return TRUE;
	}

	return FALSE;
}

//返回栈中元素的个数
int Size_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	return queue->size;
}

//清空
void Clear_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}

	memset(queue->data, 0, MAXSIZE);
	queue->size = 0;
}

//销毁
void FreeSpeace_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}

	free(queue);
}