#ifndef _BTREE_H_
#define _BTREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode;
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������

BTNode* BinaryTreeCreate(BTDataType* src);

void BinaryTreeDestory(BTNode** root);

int BinaryTreeSize(BTNode* root);

int BinaryTreeLeafSize(BTNode* root);

int BinaryTreeLevelKSize(BTNode* root, int k);

BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

#endif