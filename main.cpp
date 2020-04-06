
#include "myCPK.h"

#include <iostream>
using namespace std;
int main(void)
{
	chess* test = chess::getinstance();
	string msg;
	int id = 50;
	while (1)
	{
		id = 150 - id;
		getline(cin, msg);
		test->control(msg, id);
		
		while (test->msg_size())
		{
			cout << test->pop_msg() << endl;
		}
	}
}

//#include<stdio.h>
//#include<stdlib.h>
//
//struct TreeNode
//{
//	char data;
//	struct TreeNode* Lchild;
//	struct TreeNode* Rchild;
//};
//
//struct TreeNode* CreatTree(char data)
//{
//	struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(TreeNode));
//	newNode->data = data;
//	newNode->Lchild = NULL;
//	newNode->Rchild = NULL;
//	return newNode;
//}
//
//void insertNode(struct TreeNode* ParentNode, struct TreeNode* Lchild, struct TreeNode* Rchild)
//{
//	ParentNode->Lchild = Lchild;
//	ParentNode->Rchild = Rchild;
//}
//
//void PrintData(struct TreeNode* curNode)
//{
//	printf("%c\t", curNode->data);
//}
//
//void preOrder(struct TreeNode* root)
//{
//	if (root != NULL)
//	{
//		PrintData(root);
//		preOrder(root->Lchild);
//		preOrder(root->Rchild);
//	}
//}
//
//void preOrderstack(struct TreeNode* root)
//{
//	if (root == NULL)
//		return;
//	struct TreeNode* stack[10];
//	int stackTop = -1;
//	struct TreeNode* pMove = root;
//	while (stackTop != -1 || pMove)
//	{
//		while (pMove)
//		{
//			printf("%c\t", pMove->data);
//			stack[++stackTop] = pMove;
//			pMove = pMove->Lchild;
//		}
//		if (stackTop != -1)
//		{
//			pMove = stack[stackTop];
//			stackTop--;
//			pMove = pMove->Rchild;
//		}
//	}
//
//}
//
//void midOrder(struct TreeNode* root)
//{
//	if (root != NULL)
//	{
//		midOrder(root->Lchild);
//		PrintData(root);
//		midOrder(root->Rchild);
//	}
//}
//
//void midOrderstack(struct TreeNode* root)
//{
//	if (root == NULL)
//		return;
//	struct TreeNode* stack[10];
//	struct TreeNode* pMove = root;
//	int stackTop = -1;
//	while (stackTop != -1 || pMove)
//	{
//		while (pMove)
//		{
//			stack[++stackTop] = pMove;
//			pMove = pMove->Lchild;
//		}
//		if (stackTop != -1)
//		{
//			pMove = stack[stackTop--];
//			printf("%c\t", pMove->data);
//			pMove = pMove->Rchild;
//		}
//	}
//}
//
//void lastOrder(struct TreeNode* root)
//{
//
//	if (root != NULL)
//	{
//		lastOrder(root->Lchild);
//		lastOrder(root->Rchild);
//		PrintData(root);
//	}
//}
//
//void lastOrderstack(struct TreeNode* root)
//{
//	if (root == NULL)
//		return;
//	struct TreeNode* stack[10];
//	struct TreeNode* pMove = root;
//	struct TreeNode* VisitNode = NULL;
//	int stackTop = -1;
//	do
//	{
//		while (pMove)
//		{
//			stack[++stackTop] = pMove;
//			pMove = pMove->Lchild;
//		}
//		while (stackTop != -1)
//		{
//			pMove = stack[stackTop--];
//			if (pMove->Rchild == NULL || pMove->Rchild == VisitNode)
//			{
//				printf("%c\t", pMove->data);
//				VisitNode = pMove;
//			}
//			else
//			{
//				stack[++stackTop] = pMove;
//				pMove = pMove->Rchild;
//				while (pMove)
//				{
//					stack[++stackTop] = pMove;
//					pMove = pMove->Lchild;
//				}
//			}
//		}
//	} while (stackTop != -1);
//
//}
//
//
//int main()
//{
//	struct TreeNode* A = CreatTree('A');
//	struct TreeNode* B = CreatTree('B');
//	struct TreeNode* C = CreatTree('C');
//	struct TreeNode* D = CreatTree('D');
//	struct TreeNode* E = CreatTree('E');
//	struct TreeNode* F = CreatTree('F');
//	struct TreeNode* G = CreatTree('G');
//	insertNode(A, B, C);
//	insertNode(B, D, E);
//	//insertNode(D, NULL, G);
//	insertNode(C, F, G);
//	printf("先序遍历:\n");
//	preOrder(A);
//	printf("\n");
//	preOrderstack(A);
//	printf("\n中序遍历:\n");
//	midOrder(A);
//	printf("\n");
//	midOrderstack(A);
//	printf("\n后序遍历:\n");
//	lastOrder(A);
//	printf("\n");
//	lastOrderstack(A);
//	return 0;
//}