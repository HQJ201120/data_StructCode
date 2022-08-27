#define _CRT_SECURE_NO_WARNINGS  //�궨�� 
#include "LinkList.h"

//������������
typedef struct MyStruct
{
	char name[64];
	int age;
	int score;

}Mystruct;

//��ӡ����
void Myprint(void* data)
{
	Mystruct* p = (Mystruct*)data;
	printf("name:%s,age:%d,score:%d\n", p->name, p->age, p->score);
}

int main(void)
{
	//��������
	LinkList* list = Init_LinkList();

	//��������
	Mystruct M1 = { "hjj",18,100 };
	Mystruct M2 = { "xyf",99,20 };
	Mystruct M3 = { "hrj",99,30 };
	Mystruct M4 = { "lhl",99,30 };
	Mystruct M5 = { "zjw",99,30 };

	//���ݲ�������
	Insert_LinkList(list, 0, &M1);
	Insert_LinkList(list, 1, &M2);
	Insert_LinkList(list, 2, &M3);
	Insert_LinkList(list, 3, &M4);
	Insert_LinkList(list, 4, &M5);

	RemoveBypos_LinkList(list, 1);

	//��ӡ
	Print_LinkList(list, Myprint);

	Mystruct* ret = (Mystruct*)GetHead_LinkList(list);
	printf("name:%s,age:%d,score:%d\n", ret->name, ret->age, ret->score);

	//����
	FreeSpeace_LinkList(list);

	return 0;
}