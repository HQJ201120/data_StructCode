#include "DynamicArray.h"

//初始化
Dynamic_Array* Init_Array() 
{
	//申请内存
	Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));

	//初始化
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAddr = (int*)malloc(sizeof(int) * myArray->capacity);

	return myArray;
}

//插入
void Push_Back_Array(Dynamic_Array* arr, int value)
{
	if (arr == NULL)
	{
		return;
	}

	//判断空间是否足够
	if (arr->size == arr->capacity)
	{
		//申请一块更大的内存空间，新空间是旧空间的两倍
		int* newSpeace = (int*)malloc(sizeof(int) * arr->capacity * 2);
		//拷贝数据到新的空间
		memcpy(newSpeace, arr->pAddr, arr->capacity * sizeof(int));
		//释放旧空间内存
		if (arr->pAddr != NULL)
		{
			free(arr->pAddr);
		}

		//更新容量
		arr->capacity = arr->capacity * 2;
		arr->pAddr = newSpeace;
	}

	//插入新元素
	arr->pAddr[arr->size] = value;
	arr->size++;

}

//根据位置删除
void RemoveBypos_Array(Dynamic_Array* arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}

	//位置是否有效
	if (pos < 0 || pos >= arr->size)
	{
		return;
	}

	//删除元素
	for (int i = pos; i < arr->size; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}

	arr->size--;
}

//根据值删除
void RemoveByvalue_Array(Dynamic_Array* arr, int value)
{
	if (arr == NULL)
	{
		return;
	}

	//找到值的位置
	int pos = Find_Array(arr, value);

	//根据位置删除
	RemoveBypos_Array(arr, pos);

}

//查找
int Find_Array(Dynamic_Array* arr, int value) 
{
	if (arr == NULL)
	{
		return -1;
	}

	//查找
	int pos = -1;
	//找到值的位置
	for (int i = 0; i < arr->size; i++)
	{
		if (arr->pAddr[i] == value)
		{
			pos = i;
			break;
		}
	}

	return pos;
}

//打印
void Print_Array(Dynamic_Array* arr) 
{
	if (arr == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->size; i++)
	{
		printf("%d ", arr->pAddr[i]);
	}

	printf("\n");
}

//清空数组
void Clear_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return;
	}

	arr->size = 0;
}

//获得动态数组容量
int Capacity_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return -1;
	}

	return arr->capacity;
}

//获得动态数组当前元素个数
int Size_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return -1;
	}

	return arr->size;
}

//获得某个位置元素
int At_Array(Dynamic_Array* arr, int pos)
{
	//有可能值里面也有 -1
	/*if (arr == NULL)
	{
		return -1;
	}*/

	return arr->pAddr[pos];
}

//释放动态数组内存
void FreeSpeace_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return;
	}

	if (arr->pAddr != NULL)
	{
		free(arr->pAddr);
	}

	free(arr);

}