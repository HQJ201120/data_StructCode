#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include "CircleLinkList.h"

typedef struct MYDATA
{
	CircleLinkNode node;
	char name[64];
	int age;
}MyData;

void Myprintf(CircleLinkNode* data)
{
	MyData* p = (MyData*)data;
	printf("name : %s  age : %d\n", p->name, p->age);
}

int Compara(CircleLinkNode* data1, CircleLinkNode* data2)
{
	if (data1 == NULL || data2 == NULL)
	{
		return FALSE;
	}

	MyData* p1 = (MyData*)data1;
	MyData* p2 = (MyData*)data2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
	{
		return TURE;
	}

	return FALSE;

}

int main(void)
{
	//创建循环链表
	CircleLinkList* list = Init_CircleLinkList();

	MyData M1, M2, M3, M4, M5;

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

	//插入
	Insert_CircleLinkList(list, 0, (CircleLinkNode*)&M1);
	Insert_CircleLinkList(list, 0, (CircleLinkNode*)&M2);
	Insert_CircleLinkList(list, 0, (CircleLinkNode*)&M3);
	Insert_CircleLinkList(list, 0, (CircleLinkNode*)&M4);
	Insert_CircleLinkList(list, 0, (CircleLinkNode*)&M5);

	Print_LinkList(list, Myprintf);

	printf("-----------------------\n");

	RemoveBypos_LinkList(list, 3);
	Print_LinkList(list, Myprintf);

	printf("-----------------------\n");

	RemoveByvalue_LinkList(list, (CircleLinkNode*)&M5, Compara);
	Print_LinkList(list, Myprintf);

	FreeSpeace_LinkList(list);


	return 0;
}