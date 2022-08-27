#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include <time.h>
#include <sys/timeb.h>

#define MAX 10

long GetsystemTime()
{
	struct timeb tb;

	ftime(&tb);

	return tb.time * 1000 + tb.millitm;
}

int* CreateArray()
{
	srand((unsigned int)time(NULL));
	int* arr = (int*)malloc(MAX * sizeof(int));

	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}

	return arr;
}

//合并算法
void Merge(int* arr, int start, int end, int mid, int* temp) 
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//辅助空间有多少个元素
	int len = 0;

	//合并
	while (i_start <= i_end && j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[len] = arr[i_start];

			len++;
			i_start++;
		}
		else
		{
			temp[len] = arr[j_start];

			len++;
			j_start++;
		}
	}

	//查看有没有剩下的
	//i
	while (i_start <= i_end)
	{
		temp[len] = arr[i_start];

		i_start++;
		len++;
	}

	//j
	while (j_start <= j_end)
	{
		temp[len] = arr[j_start];

		j_start++;
		len++;
	}

	//覆盖原空间
	for (int i = 0; i < len; i++)
	{
		arr[start + i] = temp[i];
	}
}

//归并排序
void MergeSort(int* arr, int start, int end, int* temp)
{
	if (start >= end)
	{
		return;
	}

	int mid = (start + end) / 2;

	//分组
	//左半边
	MergeSort(arr, start, mid, temp);

	//右半边
	MergeSort(arr, mid + 1, end, temp);

	//合并
	Merge(arr, start, end, mid, temp);
}

int main(void)
{
	int* arr = CreateArray();

	//排序前
	printf("排序前：\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}

	//辅助空间
	int* temp = (int*)malloc(MAX * sizeof(int));

	MergeSort(arr, 0, MAX - 1, temp);

	printf("\n");
	//排序后
	printf("排序后：\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}

	free(temp);
	free(arr);

	return 0;
}