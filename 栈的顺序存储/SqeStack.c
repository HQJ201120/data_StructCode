#include "Seqstack.h"

//��ʼ��
SqeStack* Init_SqeStack()
{
	SqeStack* stack = (SqeStack*)malloc(sizeof(SqeStack));
	if (stack == NULL)
	{
		return NULL;
	}
	memset(stack->data, 0, sizeof(stack->data));
	stack->size = 0;

	return stack;
}

//��ջ
void Push_SqeStack(SqeStack* stack, void* data)
{
	if (stack == NULL || data == NULL)
	{
		return;
	}

	if (stack->size == MaxSize)
	{
		return;
	}

	stack->data[stack->size] = data;

	stack->size++;

}

//����ջ��Ԫ��
void* Top_SqeStack(SqeStack* stack)
{
	if (stack == NULL)
	{
		return NULL;
	}

	if (stack->size == 0)
	{
		return NULL;
	}

	return stack->data[stack->size - 1];	//�����Ǵ�0��ʼ����һ��Ԫ���ǵ�0��
}

//��ջ
void Pop_SqeStack(SqeStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	if (stack->size == 0)
	{
		return;
	}

	//��������ջ
	stack->data[stack->size - 1] = 0;

	stack->size--;
}

//�ж��Ƿ�Ϊ��
int IsEmpty(SqeStack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	if (stack->size == 0)
	{
		return TURE;
	}

	return FALSE;
}

//����ջ��Ԫ�صĸ���
int Size_SqeStack(SqeStack* stack)
{
	return stack->size;
}

//���
void Clear_SqeStack(SqeStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	memset(stack->data, 0, sizeof(stack->data));

	stack->size = 0;
}

//����
void FreeSpeace_SqeStack(SqeStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	free(stack);
}
