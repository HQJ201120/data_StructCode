#define _CRT_SECURE_NO_WARNINGS  //�궨�� 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include "DynamicArray.h"

void test()
{
	//��ʼ����̬����
	Dynamic_Array* Myarray = Init_Array();

	printf("����������%d\n", Capacity_Array(Myarray));
	printf("�����С��%d\n", Size_Array(Myarray));

	//����Ԫ��
	for (int i = 0; i < 81; i++)
	{
		Push_Back_Array(Myarray, i);
	}

	printf("����������%d\n", Capacity_Array(Myarray));
	printf("�����С��%d\n", Size_Array(Myarray));

	RemoveBypos_Array(Myarray, 0);
	RemoveByvalue_Array(Myarray, 10);

	//��ӡ
	Print_Array(Myarray);

	//�ͷ�
	FreeSpeace_Array(Myarray);

}

int main(void)
{
	test();

	return 0;
}