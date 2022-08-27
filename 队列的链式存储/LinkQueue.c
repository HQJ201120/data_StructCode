#include "LinkQueue.h"

//��ʼ��
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

//���
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

//����
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

//�ж��Ƿ�Ϊ��
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

//����Ԫ�ظ���
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

//���ض�ͷԪ��
void* Top_SeqQueue(LinkQueue* queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	return queue->head.next;
}

//���
void Clear_LinkQueue(LinkQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	
	queue->head.next = NULL;
	queue->size = 0;
}

//�ͷ�
void Free_LinkQueue(LinkQueue* queue)
{
	if (queue == NULL)
	{
		return;
	}

	free(queue);
}
