#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include "LinkStack.h"

int Isnumber(char c)
{
	return c >= '0' && c <= '9';
}

typedef struct MYNUM
{
	LinkNode node;
	int val;
}MyNum;

int Calculate(int left, int right, char c)
{
	int ret = 0;

	switch (c)
	{
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;

	default:
		break;
	}

	return ret;
}

int main(void)
{
	char* str = "831-5*+";
	char* p = str;

	LinkStack* stack = Init_LinkStack();

	while (*p != '\0')
	{
		//如果数字，入栈
		if (Isnumber(*p))
		{
			MyNum* num = (MyNum*)malloc(sizeof(MyNum));
			num->val = *p - '0';	//字符型 - '0'，会得到整数型

			Push_LinkStack(stack, (LinkNode*)num);
		}
		else
		{
			//取出右操作数
			MyNum* Right = (MyNum*)Top_LinkStack(stack);
			int RightNum = Right->val;

			Pop_LinkStack(stack);
			free(Right);

			//取出左操作数
			MyNum* Left = (MyNum*)Top_LinkStack(stack);

			int LeftNum = Left->val;
			Pop_LinkStack(stack);

			int ret = Calculate(LeftNum, RightNum, *p);
			MyNum* num = (MyNum*)malloc(sizeof(MyNum));
			num->val = ret;

			//入栈
			Push_LinkStack(stack, (LinkNode*)num);
		}

		p++;
	}

	if (Size_LinkStack(stack) == 1)
	{
		MyNum* num = (MyNum*)Top_LinkStack(stack);

		printf("结果为：%d", num->val);
		Pop_LinkStack(stack);

		free(num);
	}

	FreeSpeace_LinkStack(stack);

	return 0;
}