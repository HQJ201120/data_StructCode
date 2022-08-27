#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int num = 0;	//叶子节点数目

//二叉树节点
typedef struct BINNODE
{
	char ch;
	struct BINNODE* lchild;	//左节点
	struct BINNODE* rchild;	//右节点
}BinNode;

void CaculateLeafNum(BinNode* root)
{
	if (root == NULL)
	{
		return;
	}

	if (root->lchild == NULL && root->rchild == NULL)
	{
		num++;
	}

	//左子树叶子节点数目
	CaculateLeafNum(root->lchild);

	//右子树叶子节点数目
	CaculateLeafNum(root->rchild);
}

//构建
void CresteBinTree()
{
	//创建节点
	BinNode node1 = { 'A',NULL,NULL };
	BinNode node2 = { 'B',NULL,NULL };
	BinNode node3 = { 'C',NULL,NULL };
	BinNode node4 = { 'D',NULL,NULL };
	BinNode node5 = { 'E',NULL,NULL };
	BinNode node6 = { 'F',NULL,NULL };
	BinNode node7 = { 'G',NULL,NULL };
	BinNode node8 = { 'H',NULL,NULL };

	//建立关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	//
	CaculateLeafNum(&node1);

	printf("数目为：%d\n", num);
}

int main()
{
	CresteBinTree();

	return 0;
}