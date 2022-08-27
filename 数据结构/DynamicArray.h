#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��̬�����ڴ�
//��̬���� �����ڴ� �������� �Ƿ��ڴ�
//size���� ��¼��ǰ�����о����Ԫ�ظ���

typedef struct Dynamicarray
{
	int* pAddr;	//������ݵ�ַ
	int size;	//��ǰ�ж��ٸ�Ԫ��
	int capacity;	//������������ǰ��������ɶ���Ԫ��
}Dynamic_Array;

//дһϵ�е���صĶԽṹ������ĺ���
//��ʼ��
Dynamic_Array* Init_Array();

//����
void Push_Back_Array(Dynamic_Array* arr, int value);

//����λ��ɾ��
void RemoveBypos_Array(Dynamic_Array* arr, int pos);

//����ֵɾ��
void RemoveByvalue_Array(Dynamic_Array* arr, int value);

//����
int Find_Array(Dynamic_Array* arr, int value);

//��ӡ
void Print_Array(Dynamic_Array* arr);

//�������
void Clear_Array(Dynamic_Array* arr);

//��ö�̬��������
int Capacity_Array(Dynamic_Array* arr);

//��ö�̬���鵱ǰԪ�ظ���
int Size_Array(Dynamic_Array* arr);

//���ĳ��λ��Ԫ��
int At_Array(Dynamic_Array* arr, int pos);

//�ͷŶ�̬�����ڴ�
void FreeSpeace_Array(Dynamic_Array* arr);

#endif
