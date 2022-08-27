#define _CRT_SECURE_NO_WARNINGS  //∫Í∂®“Â 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include <time.h>
#include <sys/timeb.h>

#define MAX 10

//≤Â»Î≈≈–Ú
void InsertSort(int* arr, int len)
{
	int j;

	for (int i = 1; i < len; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int tmp = arr[i];

			for (j = i - 1; j >= 0 && tmp < arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}

			arr[j + 1] = tmp;
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

	//≈≈–Ú«∞
	printf("≈≈–Ú«∞£∫\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}


	InsertSort(arr, MAX);

	printf("\n");
	//≈≈–Ú∫Û
	printf("≈≈–Ú∫Û£∫\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}