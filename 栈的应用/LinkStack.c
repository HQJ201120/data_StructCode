#include "LinkStack.h"

//初始化
LinkStack* Init_LinkStack()
{
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	if (stack == NULL)
	{
		return NULL;
	}

	stack->head.next = NULL;
	stack->size = 0;

	return stack;
}

//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return NULL;
	}

	if (stack->size == 0)
	{
		return NULL;
	}
	
	return stack->head.next;
}

//入栈
void Push_LinkStack(LinkStack* stack, LinkNode* data)
{
	if (stack == NULL || data == NULL)
	{
		return;
	}

	//插入到头
	data->next = stack->head.next;
	stack->head.next = data;

	stack->size++;
}

//出栈
void Pop_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	if (stack->size == 0)
	{
		return;
	}

	LinkNode* pNext = stack->head.next;
	stack->head.next = pNext->next;

	stack->size--;

}

//返回栈中元素的个数
int Size_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	return stack->size;
}

//清空
void Clear_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	stack->head.next = NULL;
	stack->size = 0;
}

//释放
void FreeSpeace_LinkStack(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	free(stack);
}