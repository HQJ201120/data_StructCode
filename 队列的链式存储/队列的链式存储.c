#define _CRT_SECURE_NO_WARNINGS  //ºê¶¨Òå 
#include "LinkQueue.h"

typedef struct MyStruct
{
	LinkNode node;
	char name[64];
	int age;

}Mystruct;

int main(void)
{
	LinkQueue* queue = Init_LinkQueue();

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

	Push_LinkQueue(queue, (LinkNode*)&M1);
	Push_LinkQueue(queue, (LinkNode*)&M2);
	Push_LinkQueue(queue, (LinkNode*)&M3);
	Push_LinkQueue(queue, (LinkNode*)&M4);
	Push_LinkQueue(queue, (LinkNode*)&M5);

	while (Size_LinkQueue(queue) > 0)
	{
		Mystruct* Mystr = (Mystruct*)Top_SeqQueue(queue);
		printf("name: %s,age: %d\n", Mystr->name, Mystr->age);

		Pop_LinkQueue(queue);
	}

	Free_LinkQueue(queue);

	return 0;
}
