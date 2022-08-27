#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include "DynamicArray.h"

void test()
{
	//初始化动态数组
	Dynamic_Array* Myarray = Init_Array();

	printf("数组容量：%d\n", Capacity_Array(Myarray));
	printf("数组大小：%d\n", Size_Array(Myarray));

	//插入元素
	for (int i = 0; i < 81; i++)
	{
		Push_Back_Array(Myarray, i);
	}

	printf("数组容量：%d\n", Capacity_Array(Myarray));
	printf("数组大小：%d\n", Size_Array(Myarray));

	RemoveBypos_Array(Myarray, 0);
	RemoveByvalue_Array(Myarray, 10);

	//打印
	Print_Array(Myarray);

	//释放
	FreeSpeace_Array(Myarray);

}

int main(void)
{
	test();

	return 0;
}