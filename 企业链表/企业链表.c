#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include "LinuxLinkList.h"

typedef struct MYDATA
{
	LinkNode node;	//挂钩
	char name[64];
	int age;
}MyData;

void Myprint(LinkNode* data)
{
	MyData* p = (MyData*)data;
	printf("name : %s  age : %d\n", p->name, p->age);
}

int compara(LinkNode* node1, LinkNode* node2)
{
	MyData* p1 = (MyData*)node1;
	MyData* p2 = (MyData*)node2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
	{
		return 0;
	}

	return -1;
}

int main(void)
{
	LinkList* list = Init_LinkList();

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

	Insert_LinkList(list, 0, (LinkNode*)&M1);	//寻址只能访问挂钩节点
	Insert_LinkList(list, 0, (LinkNode*)&M2);	
	Insert_LinkList(list, 0, (LinkNode*)&M3);	
	Insert_LinkList(list, 0, (LinkNode*)&M4);	
	Insert_LinkList(list, 0, (LinkNode*)&M5);	

	//RemoveBypos_LinkList(list, 3);

	Print_LinkList(list, Myprint);

	int ret = Find_LinkList(list, (LinkNode*)&M1, compara);

	printf("ret = %d", ret);

	FreeSpeace_LinkList(list);



	return 0;
}