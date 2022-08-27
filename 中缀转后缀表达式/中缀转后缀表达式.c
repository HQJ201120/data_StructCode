#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include "LinkStack.h"

typedef struct MYCHAR
{
	LinkNode node;
	char* p;
}Mychar;

Mychar* MallocMychar(char* p)
{
	Mychar* mychar = (Mychar*)malloc(sizeof(Mychar));
	mychar->p = p;

	return mychar;
}

int Isnumber(char c)
{
	return c >= '0' && c <= '9';
}

//运算符号
int IsOperator(char c)
{
	return c == '+' || c == '-' || c == '/' || c == '*';
}

//返回运算符号优先级
int GetPriority(char c)
{
	int level = 0;

	if (c == '/' || c == '*')
	{
		level = 2;
	}

	else if (c == '+' || c == '-')
	{
		level = 1;
	}

	else
	{
		level = 0;
	}

	return level;
}

//运算符操作
void Operatoroperation(LinkStack* stack, char* p)
{
	//取出栈顶元素
	Mychar* mychar = (Mychar*)Top_LinkStack(stack);
	if (mychar == NULL)
	{
		Push_LinkStack(stack, (LinkNode*)MallocMychar(p));

		return;
	}
	//如果栈顶优先级低于当前字符优先级，直接入栈
	if (GetPriority(*(mychar->p)) < GetPriority(*p))
	{
		Push_LinkStack(stack, (LinkNode*)MallocMychar(p));
		return;
	}

	//如果不低
	else
	{
		while (Size_LinkStack(stack) > 0)
		{
			//取出栈顶元素
			Mychar* mychar2 = (Mychar*)Top_LinkStack(stack);

			//如果栈顶优先级低于当前字符优先级，直接入栈
			if (GetPriority(*(mychar2->p)) < GetPriority(*p))
			{
				Push_LinkStack(stack, (LinkNode*)MallocMychar(p));
				break;
			}

			printf("%c", *(mychar2->p));
			Pop_LinkStack(stack);
			free(mychar2);
		}
	}
}

void Numberout(char* c)
{
	printf("%c", *c);
}

//判断是不是左括号
int IsLeft(char c)
{
	return c == '(';
}

//左括号操作
void LeftOperate(LinkStack* stack, char* p)
{
	Push_LinkStack(stack, (LinkNode*)MallocMychar(p));
}

int IsRight(char c)
{
	return c == ')';
}

//右括号操作
void RightOperate(LinkStack* stack)
{
	//先判断有没有元素
	while (Size_LinkStack(stack) > 0)
	{
		//取出栈顶元素
		Mychar* mychar = (Mychar*)Top_LinkStack(stack);

		//如果找到左括号
		if (IsLeft(*(mychar->p)))
		{
			//弹出
			Pop_LinkStack(stack);
			break;
		}

		printf("%c", *(mychar->p));
		Pop_LinkStack(stack);
		free(mychar);
	}
}

int main(void)
{
	LinkStack* stack = Init_LinkStack();
	char* str = "8+(3-1)*5";
	char* p = str;

	while (*p != '\0')
	{
		//如果是数字
		if (Isnumber(*p))
		{
			Numberout(p);
		}

		//如果是左括号
		if (IsLeft(*p))
		{
			LeftOperate(stack, p);
		}
		
		//如果是右括号
		if (IsRight(*p))
		{
			RightOperate(stack);
		}

		//如果是运算符号
		if (IsOperator(*p))
		{
			Operatoroperation(stack, p);
		}

		p++;
	}

	//剩余符号弹出
	while (Size_LinkStack(stack) > 0)
	{
		//取出栈顶元素
		Mychar* mychar = (Mychar*)Top_LinkStack(stack);

		printf("%c", *(mychar->p));
		Pop_LinkStack(stack);
		free(mychar);
	}

	return 0;
}