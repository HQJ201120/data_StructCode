#define _CRT_SECURE_NO_WARNINGS  //∫Í∂®“Â 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include <time.h>
#include <sys/timeb.h>

#define MAX 10

//—°‘Ò≈≈–Ú
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

	//≈≈–Ú«∞
	printf("≈≈–Ú«∞£∫\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}


	SelectSort(arr, MAX);

	printf("\n");
	//≈≈–Ú∫Û
	printf("≈≈–Ú∫Û£∫\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}