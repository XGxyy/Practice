#include "BTree.h"
#include "stack.h"



void StackInit(Stack* st, size_t capicity){
	assert(st);

	st->capicity = capicity;
	st->array = (StDataType*)malloc(capicity * sizeof(StDataType));
	assert(st->array);

	st->size = 0;
}
void StackDestory(Stack* st){
	assert(st);

	if (st->array){
		free(st->array);
		st->array = NULL;
		st->capicity = 0;
		st->size = 0;
	}
}

void CheckCapicity(Stack* st){
	assert(st);

	if (st->size == st->capicity){
		st->capicity *= 2;
		st->array = (StDataType*)realloc(st->array, st->capicity * sizeof(StDataType));
	}
}

void StackPush(Stack* st, StDataType x){
	assert(st);

	CheckCapicity(st);

	st->array[st->size] = x;
	st->size++;
}
void StackPop(Stack* st){
	assert(st || st->size);

	st->size--;
}

StDataType StackTop(Stack* st){
	if (StackEmpty(st)){
		return (StDataType)0;
	}

	return st->array[st->size - 1];
}

int StackEmpty(Stack* st){
	return st->size == 0;
}













