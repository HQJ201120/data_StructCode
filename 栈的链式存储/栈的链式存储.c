#define _CRT_SECURE_NO_WARNINGS  //ºê¶¨Òå 
#include "LinkStack.h"

typedef struct MyStruct
{
	LinkNode node;
	char name[64];
	int age;
}Mystruct;

int main(void)
{
	LinkStack* stack = Init_LinkStack();
	
	Mystruct M1, M2, M3, M4, M5;

	strncpy(M1.name, "hjj", sizeof(M1.name));
	strncpy(M2.name, "hrj", sizeof(M2.name));
	strncpy(M3.name, "zjx", sizeof(M3.name));
	strncpy(M4.name, "xyf", sizeof(M4.name));
	strncpy(M5.name, "lhl", sizeof(M5.name));

	M1.age = 18;
	M2.age = 80;
	M3.age = 80;
	M4.age = 80;
	M5.age = 80;

	Push_LinkStack(stack, (LinkNode*)&M1);
	Push_LinkStack(stack, (LinkNode*)&M2);
	Push_LinkStack(stack, (LinkNode*)&M3);
	Push_LinkStack(stack, (LinkNode*)&M4);
	Push_LinkStack(stack, (LinkNode*)&M5);

	while (Size_LinkStack(stack) > 0)
	{
		Mystruct* p = (Mystruct*)Top_LinkStack(stack);

		printf("name: %s,age: %d\n", p->name, p->age);

		Pop_LinkStack(stack);
	}

	FreeSpeace_LinkStack(stack);


	return 0;
}
