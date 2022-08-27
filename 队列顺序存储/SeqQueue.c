#include "SeqQueue.h"

//��ʼ��
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

//��ջ
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

//���ض�ͷԪ��
void* Top_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	return queue->data[0];
}

//���ض�βԪ��
void* Back_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	if (IsEmpty(queue) == TRUE)
	{
		printf("����Ϊ�գ�");
		return NULL;
	}

	return queue->data[queue->size - 1];
}

//����
void Pop_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}

	if (IsEmpty(queue) == TRUE)
	{
		printf("����Ϊ�գ�");
		return;
	}

	for (int i = 0; i < queue->size - 1; i++)
	{
		queue->data[i] = queue->data[i + 1];
	}

	queue->size--;
}

//�ж��Ƿ�Ϊ��
int IsEmpty(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	if (queue->size == 0)
	{
		printf("����Ϊ�գ�");
		return TRUE;
	}

	return FALSE;
}

//����ջ��Ԫ�صĸ���
int Size_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	return queue->size;
}

//���
void Clear_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}

	memset(queue->data, 0, MAXSIZE);
	queue->size = 0;
}

//����
void FreeSpeace_SeqQueue(SeqQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}

	free(queue);
}