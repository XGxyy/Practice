#ifndef _HEAP_H_
#define _HEAP_H_
#include <stdio.h>
#include <stdlib.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* data;
	int size;
	int capacity;
}Heap;

void adjustDown(Heap* hp, int n);

void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);

int HeapPrint(Heap* hp);
void HeapPrintS(Heap* hp);
void HeapSort(Heap* hp);

#endif