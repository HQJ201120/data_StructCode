#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//动态增长内存
//动态数组 申请内存 拷贝数据 是否内存
//size概念 记录当前数据中具体的元素个数

typedef struct Dynamicarray
{
	int* pAddr;	//存放数据地址
	int size;	//当前有多少个元素
	int capacity;	//容量，容器当前最大能容纳多少元素
}Dynamic_Array;

//写一系列的相关的对结构体操作的函数
//初始化
Dynamic_Array* Init_Array();

//插入
void Push_Back_Array(Dynamic_Array* arr, int value);

//根据位置删除
void RemoveBypos_Array(Dynamic_Array* arr, int pos);

//根据值删除
void RemoveByvalue_Array(Dynamic_Array* arr, int value);

//查找
int Find_Array(Dynamic_Array* arr, int value);

//打印
void Print_Array(Dynamic_Array* arr);

//清空数组
void Clear_Array(Dynamic_Array* arr);

//获得动态数组容量
int Capacity_Array(Dynamic_Array* arr);

//获得动态数组当前元素个数
int Size_Array(Dynamic_Array* arr);

//获得某个位置元素
int At_Array(Dynamic_Array* arr, int pos);

//释放动态数组内存
void FreeSpeace_Array(Dynamic_Array* arr);

#endif
