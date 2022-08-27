#define _CRT_SECURE_NO_WARNINGS  //�궨�� 
#include "Seqstack.h"

typedef struct MyStruct
{
	char name[64];
	int age;

}Mystruct;

int main(void)
{
	SqeStack* stack = Init_SqeStack();

	//��������
	Mystruct M1 = { "hjj",18};
	Mystruct M2 = { "xyf",99};
	Mystruct M3 = { "hrj",99};
	Mystruct M4 = { "lhl",99};
	Mystruct M5 = { "zjw",99};

	//��ջ
	Push_SqeStack(stack, &M1);
	Push_SqeStack(stack, &M2);
	Push_SqeStack(stack, &M3);
	Push_SqeStack(stack, &M4);
	Push_SqeStack(stack, &M5);

	while (Size_SqeStack(stack) > 0)
	{
		Mystruct* Mystr = (Mystruct*)Top_SqeStack(stack);
		printf("name: %s,age: %d\n", Mystr->name, Mystr->age);

		Pop_SqeStack(stack);
	}

	FreeSpeace_SqeStack(stack);

	return 0;
}