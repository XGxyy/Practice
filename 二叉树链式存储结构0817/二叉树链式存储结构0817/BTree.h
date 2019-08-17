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
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树

BTNode* BinaryTreeCreate(BTDataType* src);

void BinaryTreeDestory(BTNode** root);

int BinaryTreeSize(BTNode* root);

int BinaryTreeLeafSize(BTNode* root);

int BinaryTreeLevelKSize(BTNode* root, int k);

BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

#endif