#define _CRT_SECURE_NO_WARNINGS  //�궨�� 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

//�������ڵ�
typedef struct BINNODE
{
	char ch;
	struct BINNODE* lchild;	//��ڵ�
	struct BINNODE* rchild;	//�ҽڵ�
}BinNode;

void Recursion(BinNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//�ٱ���������
	Recursion(root->lchild);

	//�ٱ���������
	Recursion(root->rchild);

	//���ʸ��ڵ�
	printf("%c", root->ch);
}

//����
void CresteBinTree()
{
	//�����ڵ�
	BinNode node1 = { 'A',NULL,NULL };
	BinNode node2 = { 'B',NULL,NULL };
	BinNode node3 = { 'C',NULL,NULL };
	BinNode node4 = { 'D',NULL,NULL };
	BinNode node5 = { 'E',NULL,NULL };
	BinNode node6 = { 'F',NULL,NULL };
	BinNode node7 = { 'G',NULL,NULL };
	BinNode node8 = { 'H',NULL,NULL };

	//������ϵ
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	//�ݹ����
	Recursion(&node1);

	printf("\n");
}

int main()
{
	CresteBinTree();

	return 0;
}