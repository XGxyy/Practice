#ifndef _STACK_H_
#define _STACK_H_

#include "BTree.h"

typedef BTNode* StDataType;

typedef struct Stack
{
	StDataType* array;//指向动态开辟数组
	size_t size;//有效数据个数
	size_t capicity;//空间大小
}Stack;

void StackInit(Stack* st, size_t capicity);
void StackDestory(Stack* st);

void StackPush(Stack* st, StDataType x);
void StackPop(Stack* st);

StDataType StackTop(Stack* st);
int StackEmpty(Stack* st);





#endif// _STACK_H_