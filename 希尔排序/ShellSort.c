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

//希尔排序
void ShellSort(int* arr, int len)
{
	int increasement = len;	//增量
	int i, j, k;

	do {
		//确定分组增量
		increasement = increasement / 3 + 1;

		for (i = 0; i < increasement; i++)
		{
			for (j = i + increasement; j < len; j += increasement)
			{
				int tmp = arr[j];

				if (arr[j] < arr[j - increasement])
				{
					for (k = j - increasement; k >= 0 && tmp < arr[k]; k -= increasement)
					{
						arr[k + increasement] = arr[k];
					}

					arr[k + increasement] = tmp;
				}
			}
		}
	} while (increasement > 1);
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

	ShellSort(arr, MAX);

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