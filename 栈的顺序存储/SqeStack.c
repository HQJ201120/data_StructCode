#include "Seqstack.h"

//初始化
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

//入栈
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

//返回栈顶元素
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

	return stack->data[stack->size - 1];	//数组是从0开始，第一个元素是第0个
}

//出栈
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

	//把最外层出栈
	stack->data[stack->size - 1] = 0;

	stack->size--;
}

//判断是否为空
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

//返回栈中元素的个数
int Size_SqeStack(SqeStack* stack)
{
	return stack->size;
}

//清空
void Clear_SqeStack(SqeStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	memset(stack->data, 0, sizeof(stack->data));

	stack->size = 0;
}

//销毁
void FreeSpeace_SqeStack(SqeStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	free(stack);
}
