#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include "LinkList.h"

//创建数据类型
typedef struct MyStruct
{
	char name[64];
	int age;
	int score;

}Mystruct;

//打印函数
void Myprint(void* data)
{
	Mystruct* p = (Mystruct*)data;
	printf("name:%s,age:%d,score:%d\n", p->name, p->age, p->score);
}

int main(void)
{
	//创建链表
	LinkList* list = Init_LinkList();

	//创建数据
	Mystruct M1 = { "hjj",18,100 };
	Mystruct M2 = { "xyf",99,20 };
	Mystruct M3 = { "hrj",99,30 };
	Mystruct M4 = { "lhl",99,30 };
	Mystruct M5 = { "zjw",99,30 };

	//数据插入链表
	Insert_LinkList(list, 0, &M1);
	Insert_LinkList(list, 1, &M2);
	Insert_LinkList(list, 2, &M3);
	Insert_LinkList(list, 3, &M4);
	Insert_LinkList(list, 4, &M5);

	RemoveBypos_LinkList(list, 1);

	//打印
	Print_LinkList(list, Myprint);

	Mystruct* ret = (Mystruct*)GetHead_LinkList(list);
	printf("name:%s,age:%d,score:%d\n", ret->name, ret->age, ret->score);

	//销毁
	FreeSpeace_LinkList(list);

	return 0;
}