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

int CaculateLeafDerth(BinNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int depth = 0;

	//求左子树的高度
	int leftDepth = CaculateLeafDerth(root->lchild);
	int rightDerth = CaculateLeafDerth(root->rchild);
	depth = leftDepth > rightDerth ? leftDepth + 1 : rightDerth + 1;

	return depth;
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
	int depth = CaculateLeafDerth(&node1);

	printf("树的高度：%d\n", depth);
}

int main()
{
	CresteBinTree();

	return 0;
}