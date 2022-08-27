#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include "LinkStack.h"

typedef struct MyStruct
{
	LinkNode node;
	char* pAddr;
	int index;
}Mystruct;

Mystruct* CreateMystruct(char* p,int index)
{
	Mystruct* mychar = (Mystruct*)malloc(sizeof(Mystruct));
	mychar->pAddr = p;
	mychar->index = index;

	return mychar;
}

void ShowError(char* str, int index)
{
	printf("%s\n", str);
	
	for (int i = 0; i < index; i++)
	{
		printf(" ");
	}

	printf("↑");
}

int main(void)
{
	//几乎所有编译器都具有检测括号是否匹配的能力，那么如何实现编译器中的符号成对检测？
	//如下字符串
	//#include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0;}

	char* str = "ada)()";
	char* p = str;
	int index = 0;
	LinkStack* stack = Init_LinkStack();

	while (*p != '\0')
	{
		//如果是左括号直接进栈
		if (*p == '(')
		{
			Push_LinkStack(stack, (LinkNode*)CreateMystruct(p,index));
		}

		//如果是右括号，判断栈里有没有表，然后取出栈顶元素判断是否为左括号
		if (*p == ')')
		{
			if (Size_LinkStack(stack) > 0)
			{
				Mystruct* mychar = (Mystruct*)Top_LinkStack(stack);
				if (*(mychar->pAddr) == '(')
				{
					Pop_LinkStack(stack);
					free(mychar);
				}
			}
			else
			{
				printf("右括号没有匹配的左括号！\n");
				ShowError(str, index);
				break;
			}
		}

		p++;
		index++;
	}

	while (Size_LinkStack(stack) > 0)
	{
		Mystruct* mychar = (Mystruct*)Top_LinkStack(stack);
		printf("左括号没有匹配的右括号！\n");
		ShowError(str, mychar->index);

		Pop_LinkStack(stack);
		free(mychar);
	}

	return 0;
}
