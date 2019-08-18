#ifndef _BTREE_H_
#define _BTREE_H_

#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode;
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������

BTNode* BinaryTreeCreate(BTDataType* src);

void BinaryTreeDestory(BTNode* root);

int BinaryTreeSize(BTNode* root);

int BinaryTreeLeafSize(BTNode* root);

int BinaryTreeLevelKSize(BTNode* root, int k);

BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ����
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
// �ǵݹ����
void BinartTreePrevOrderN(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);
void TestBinaryTree();

#endif