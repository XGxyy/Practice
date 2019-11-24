#ifndef _DEQUEUE_H_
#define _DEQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#define QUEUENUM 100

typedef int DataType;

typedef struct{
	DataType _data[QUEUENUM];
	DataType* _head;
	DataType* _tail;
	size_t _size;
}Dequeue;

void dequeueInit(Dequeue* qu);

int dequePush(Dequeue* qu, DataType x);
int dequeuePop(Dequeue* qu);
DataType dequeueFront(Dequeue* qu);
DataType dequeueBack(Dequeue* qu);
size_t dequeueIsEmpty(Dequeue* qu);

void dequeueEmpty(Dequeue* qu);

#endif //_DEQUEUE_H_