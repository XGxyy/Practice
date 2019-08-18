#ifndef _STACK_H_
#define _STACK_H_

#include "BTree.h"

typedef BTNode* StDataType;

typedef struct Stack
{
	StDataType* array;//ָ��̬��������
	size_t size;//��Ч���ݸ���
	size_t capicity;//�ռ��С
}Stack;

void StackInit(Stack* st, size_t capicity);
void StackDestory(Stack* st);

void StackPush(Stack* st, StDataType x);
void StackPop(Stack* st);

StDataType StackTop(Stack* st);
int StackEmpty(Stack* st);





#endif// _STACK_H_