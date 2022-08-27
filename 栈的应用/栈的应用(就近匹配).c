#define _CRT_SECURE_NO_WARNINGS  //�궨�� 
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

	printf("��");
}

int main(void)
{
	//�������б����������м�������Ƿ�ƥ�����������ô���ʵ�ֱ������еķ��ųɶԼ�⣿
	//�����ַ���
	//#include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0;}

	char* str = "ada)()";
	char* p = str;
	int index = 0;
	LinkStack* stack = Init_LinkStack();

	while (*p != '\0')
	{
		//�����������ֱ�ӽ�ջ
		if (*p == '(')
		{
			Push_LinkStack(stack, (LinkNode*)CreateMystruct(p,index));
		}

		//����������ţ��ж�ջ����û�б�Ȼ��ȡ��ջ��Ԫ���ж��Ƿ�Ϊ������
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
				printf("������û��ƥ��������ţ�\n");
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
		printf("������û��ƥ��������ţ�\n");
		ShowError(str, mychar->index);

		Pop_LinkStack(stack);
		free(mychar);
	}

	return 0;
}
