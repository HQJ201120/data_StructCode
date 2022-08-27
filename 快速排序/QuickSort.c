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

//快速排序
void QuikSort(int* arr, int start, int end)
{
	int Begin = start;
	int over = end;
	int tmp = arr[start];	//基准数

	//结束条件，开始不能大于结束
	if (Begin < over)
	{
		while (Begin < over)
		{
			//从右向左找比基准数小的
			while (Begin < over && arr[over] >= tmp)
				{
					over--;
				}

			//填坑
			if(Begin < over)
			{
				arr[Begin] = arr[over];

				Begin++;
			}

			//从左向右找比基准数大的数
			while (Begin < over && arr[Begin] <= tmp)
			{
				Begin++;
			}

			if (Begin < over)
			{
				arr[over] = arr[Begin];

				over--;
			}
		}

		//把基准数放到相等的位置
		arr[Begin] = tmp;

		//对左半部分进行快速排序
		QuikSort(arr, start, Begin - 1);

		//对右半部分进行快速排序
		QuikSort(arr, Begin + 1, end);
	}
}

int main(void)
{
	int arr[] = { 4,2,8,0,5,7,1,3,9 };
	int len = sizeof(arr) / sizeof(int);

	/*srand((unsigned int)time(NULL));
	int len = MAX - 1;

	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}*/

	//排序前
	printf("排序前：\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	//long t_start = GetsystemTime();

	QuikSort(arr, 0, len - 1);

	//long t_end = GetsystemTime();
	//printf("%d个元素，所需要的时间：%ld\n", MAX, t_end - t_start);

	printf("\n");
	//排序后
	printf("排序后：\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}