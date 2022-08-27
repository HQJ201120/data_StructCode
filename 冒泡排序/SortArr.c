#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include <time.h>
#include <sys/timeb.h>

#define MAX 10
int flag = 0;	//0 表示没有排序好

long GetsystemTime()
{
	struct timeb tb;

	ftime(&tb);

	return tb.time * 1000 + tb.millitm;
}

//冒泡排序
void BubSort(int* arr,int len)
{
	for (int i = 0; i < len - 1 && flag == 0; i++)
	{
		flag = 1;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 0;

				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//选择排序
void SelectSort(int* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main(void)
{
	int arr[MAX];
	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}

	//排序前
	printf("排序前：\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}

	//long t_start = GetsystemTime();

	SelectSort(arr,MAX);

	//long t_end = GetsystemTime();
	//printf("%d个元素，所需要的时间：%ld\n", MAX, t_end - t_start);

	printf("\n");
	//排序后
	printf("排序后：\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}