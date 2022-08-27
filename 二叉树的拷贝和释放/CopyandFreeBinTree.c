#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

//二叉树节点
typedef struct BINNODE
{
	char ch;
	struct BINNODE* lchild;	//左节点
	struct BINNODE* rchild;	//右节点
}BinNode;

//遍历二叉树
void Recursion(BinNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//访问根节点
	printf("%c", root->ch);

	//再遍历左子树
	Recursion(root->lchild);

	//再遍历右子树
	Recursion(root->rchild);
}

BinNode* CopyBinTree(BinNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}

	//拷贝左子树
	BinNode* lchild = CopyBinTree(root->lchild);

	//拷贝右子树
	BinNode* rchild = CopyBinTree(root->rchild);

	//创建节点
	BinNode* newnode = (BinNode*)malloc(sizeof(BinNode));
	newnode->ch = root->ch;
	newnode->lchild = lchild;
	newnode->rchild = rchild;

	return newnode;
}

//释放二叉树内存
void FreeSpaceBinTree(BinNode* root)
{
	if (root == NULL)
	{
		return;
	}

	FreeSpaceBinTree(root->lchild);
	FreeSpaceBinTree(root->rchild);

	//释放当前节点
	free(root);
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

	BinNode* root = CopyBinTree(&node1);
	Recursion(root);
	FreeSpaceBinTree(root);
}

int main()
{
	CresteBinTree();

	return 0;
}