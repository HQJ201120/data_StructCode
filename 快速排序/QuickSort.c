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

//��������
void QuikSort(int* arr, int start, int end)
{
	int Begin = start;
	int over = end;
	int tmp = arr[start];	//��׼��

	//������������ʼ���ܴ��ڽ���
	if (Begin < over)
	{
		while (Begin < over)
		{
			//���������ұȻ�׼��С��
			while (Begin < over && arr[over] >= tmp)
				{
					over--;
				}

			//���
			if(Begin < over)
			{
				arr[Begin] = arr[over];

				Begin++;
			}

			//���������ұȻ�׼�������
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

		//�ѻ�׼���ŵ���ȵ�λ��
		arr[Begin] = tmp;

		//����벿�ֽ��п�������
		QuikSort(arr, start, Begin - 1);

		//���Ұ벿�ֽ��п�������
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

	//����ǰ
	printf("����ǰ��\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	//long t_start = GetsystemTime();

	QuikSort(arr, 0, len - 1);

	//long t_end = GetsystemTime();
	//printf("%d��Ԫ�أ�����Ҫ��ʱ�䣺%ld\n", MAX, t_end - t_start);

	printf("\n");
	//�����
	printf("�����\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}