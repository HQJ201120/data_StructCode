#define _CRT_SECURE_NO_WARNINGS  //�궨�� 
#include "LinkStack.h"

#define FALSE 0
#define TURE 1

//�������ڵ�
typedef struct BINNODE
{
	char ch;
	struct BINNODE* lchild;	//��ڵ�
	struct BINNODE* rchild;	//�ҽڵ�
}BinNode;

//�������ǵݹ����
typedef struct BINTREENODE
{
	LinkNode node;
	BinNode* root;
	int flag;
}BinTreeNode;

//����ջ�нڵ�
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
	//�Ѹ��ڵ���ջ
	Push_LinkStack(stack, (LinkNode*)BinTreeNodeStackNode(root, FALSE));

	while (Size_LinkStack(stack) > 0)
	{
		//ȡ��ջ��Ԫ��
		BinTreeNode* node = (BinTreeNode*)Top_LinkStack(stack);
		Pop_LinkStack(stack);

		//�жϵ����ڵ��Ƿ�Ϊ��
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
			//��ǰ�ڵ��ҽڵ���ջ
			Push_LinkStack(stack, (LinkNode*)BinTreeNodeStackNode(node->root->rchild, FALSE));
			//��ǰ�ڵ���ڵ���ջ
			Push_LinkStack(stack, (LinkNode*)BinTreeNodeStackNode(node->root->lchild, FALSE));
			//��ǰ�ڵ���ջ
			node->flag = TURE;
			Push_LinkStack(stack, (LinkNode*)node);
		}
	}
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

	NonRecursion(&node1);

}

int main(void)
{
	CresteBinTree();

	return 0;
}
