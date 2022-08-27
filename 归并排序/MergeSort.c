#define _CRT_SECURE_NO_WARNINGS  //�궨�� 
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

//�ϲ��㷨
void Merge(int* arr, int start, int end, int mid, int* temp) 
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;

	//�����ռ��ж��ٸ�Ԫ��
	int len = 0;

	//�ϲ�
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

	//�鿴��û��ʣ�µ�
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

	//����ԭ�ռ�
	for (int i = 0; i < len; i++)
	{
		arr[start + i] = temp[i];
	}
}

//�鲢����
void MergeSort(int* arr, int start, int end, int* temp)
{
	if (start >= end)
	{
		return;
	}

	int mid = (start + end) / 2;

	//����
	//����
	MergeSort(arr, start, mid, temp);

	//�Ұ��
	MergeSort(arr, mid + 1, end, temp);

	//�ϲ�
	Merge(arr, start, end, mid, temp);
}

int main(void)
{
	int* arr = CreateArray();

	//����ǰ
	printf("����ǰ��\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}

	//�����ռ�
	int* temp = (int*)malloc(MAX * sizeof(int));

	MergeSort(arr, 0, MAX - 1, temp);

	printf("\n");
	//�����
	printf("�����\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}

	free(temp);
	free(arr);

	return 0;
}