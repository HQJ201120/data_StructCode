#define _CRT_SECURE_NO_WARNINGS  //宏定义 
#include "LinkStack.h"

#define FALSE 0
#define TURE 1

//二叉树节点
typedef struct BINNODE
{
	char ch;
	struct BINNODE* lchild;	//左节点
	struct BINNODE* rchild;	//右节点
}BinNode;

//二叉树非递归遍历
typedef struct BINTREENODE
{
	LinkNode node;
	BinNode* root;
	int flag;
}BinTreeNode;

//创建栈中节点
BinTreeNode* BinTreeNodeStackNode(BinNode* node, int flag)
{
	BinTreeNode* newnode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	newnode->root = node;
	newnode->flag = flag;

	return newnode;
}

void NonRecursion(BinNode* root)
{
	LinkStack* stack = Init_LinkStack();
	//把根节点入栈
	Push_LinkStack(stack, (LinkNode*)BinTreeNodeStackNode(root, FALSE));

	while (Size_LinkStack(stack) > 0)
	{
		//取出栈顶元素
		BinTreeNode* node = (BinTreeNode*)Top_LinkStack(stack);
		Pop_LinkStack(stack);

		//判断弹出节点是否为空
		if (node->root == NULL)
		{
			continue;
		}

		if (node->flag == TURE)
		{
			printf("%c", node->root->ch);
		}
		else
		{
			//当前节点右节点入栈
			Push_LinkStack(stack, (LinkNode*)BinTreeNodeStackNode(node->root->rchild, FALSE));
			//当前节点左节点入栈
			Push_LinkStack(stack, (LinkNode*)BinTreeNodeStackNode(node->root->lchild, FALSE));
			//当前节点入栈
			node->flag = TURE;
			Push_LinkStack(stack, (LinkNode*)node);
		}
	}
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

	NonRecursion(&node1);

}

int main(void)
{
	CresteBinTree();

	return 0;
}
