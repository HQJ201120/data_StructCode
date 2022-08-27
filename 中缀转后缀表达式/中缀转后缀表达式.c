#define _CRT_SECURE_NO_WARNINGS  //�궨�� 
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

//�������
int IsOperator(char c)
{
	return c == '+' || c == '-' || c == '/' || c == '*';
}

//��������������ȼ�
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

//���������
void Operatoroperation(LinkStack* stack, char* p)
{
	//ȡ��ջ��Ԫ��
	Mychar* mychar = (Mychar*)Top_LinkStack(stack);
	if (mychar == NULL)
	{
		Push_LinkStack(stack, (LinkNode*)MallocMychar(p));

		return;
	}
	//���ջ�����ȼ����ڵ�ǰ�ַ����ȼ���ֱ����ջ
	if (GetPriority(*(mychar->p)) < GetPriority(*p))
	{
		Push_LinkStack(stack, (LinkNode*)MallocMychar(p));
		return;
	}

	//�������
	else
	{
		while (Size_LinkStack(stack) > 0)
		{
			//ȡ��ջ��Ԫ��
			Mychar* mychar2 = (Mychar*)Top_LinkStack(stack);

			//���ջ�����ȼ����ڵ�ǰ�ַ����ȼ���ֱ����ջ
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

//�ж��ǲ���������
int IsLeft(char c)
{
	return c == '(';
}

//�����Ų���
void LeftOperate(LinkStack* stack, char* p)
{
	Push_LinkStack(stack, (LinkNode*)MallocMychar(p));
}

int IsRight(char c)
{
	return c == ')';
}

//�����Ų���
void RightOperate(LinkStack* stack)
{
	//���ж���û��Ԫ��
	while (Size_LinkStack(stack) > 0)
	{
		//ȡ��ջ��Ԫ��
		Mychar* mychar = (Mychar*)Top_LinkStack(stack);

		//����ҵ�������
		if (IsLeft(*(mychar->p)))
		{
			//����
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
		//���������
		if (Isnumber(*p))
		{
			Numberout(p);
		}

		//�����������
		if (IsLeft(*p))
		{
			LeftOperate(stack, p);
		}
		
		//�����������
		if (IsRight(*p))
		{
			RightOperate(stack);
		}

		//������������
		if (IsOperator(*p))
		{
			Operatoroperation(stack, p);
		}

		p++;
	}

	//ʣ����ŵ���
	while (Size_LinkStack(stack) > 0)
	{
		//ȡ��ջ��Ԫ��
		Mychar* mychar = (Mychar*)Top_LinkStack(stack);

		printf("%c", *(mychar->p));
		Pop_LinkStack(stack);
		free(mychar);
	}

	return 0;
}