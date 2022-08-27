#include "DynamicArray.h"

//��ʼ��
Dynamic_Array* Init_Array() 
{
	//�����ڴ�
	Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));

	//��ʼ��
	myArray->size = 0;
	myArray->capacity = 20;
	myArray->pAddr = (int*)malloc(sizeof(int) * myArray->capacity);

	return myArray;
}

//����
void Push_Back_Array(Dynamic_Array* arr, int value)
{
	if (arr == NULL)
	{
		return;
	}

	//�жϿռ��Ƿ��㹻
	if (arr->size == arr->capacity)
	{
		//����һ�������ڴ�ռ䣬�¿ռ��Ǿɿռ������
		int* newSpeace = (int*)malloc(sizeof(int) * arr->capacity * 2);
		//�������ݵ��µĿռ�
		memcpy(newSpeace, arr->pAddr, arr->capacity * sizeof(int));
		//�ͷžɿռ��ڴ�
		if (arr->pAddr != NULL)
		{
			free(arr->pAddr);
		}

		//��������
		arr->capacity = arr->capacity * 2;
		arr->pAddr = newSpeace;
	}

	//������Ԫ��
	arr->pAddr[arr->size] = value;
	arr->size++;

}

//����λ��ɾ��
void RemoveBypos_Array(Dynamic_Array* arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}

	//λ���Ƿ���Ч
	if (pos < 0 || pos >= arr->size)
	{
		return;
	}

	//ɾ��Ԫ��
	for (int i = pos; i < arr->size; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}

	arr->size--;
}

//����ֵɾ��
void RemoveByvalue_Array(Dynamic_Array* arr, int value)
{
	if (arr == NULL)
	{
		return;
	}

	//�ҵ�ֵ��λ��
	int pos = Find_Array(arr, value);

	//����λ��ɾ��
	RemoveBypos_Array(arr, pos);

}

//����
int Find_Array(Dynamic_Array* arr, int value) 
{
	if (arr == NULL)
	{
		return -1;
	}

	//����
	int pos = -1;
	//�ҵ�ֵ��λ��
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

//��ӡ
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

//�������
void Clear_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return;
	}

	arr->size = 0;
}

//��ö�̬��������
int Capacity_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return -1;
	}

	return arr->capacity;
}

//��ö�̬���鵱ǰԪ�ظ���
int Size_Array(Dynamic_Array* arr)
{
	if (arr == NULL)
	{
		return -1;
	}

	return arr->size;
}

//���ĳ��λ��Ԫ��
int At_Array(Dynamic_Array* arr, int pos)
{
	//�п���ֵ����Ҳ�� -1
	/*if (arr == NULL)
	{
		return -1;
	}*/

	return arr->pAddr[pos];
}

//�ͷŶ�̬�����ڴ�
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