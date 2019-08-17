#include "heap.h"

int main(){
	int data[10] = { 29, 72, 48, 53, 45, 30, 18, 36, 13, 35 };
	Heap hp;
	HeapInit(&hp, data, 10);
	//HeapPush(&hp, 13);
	//HeapPush(&hp, 11);
	//HeapPop(&hp, 11);


	//HeapPrint(&hp);
	HeapSort(&hp);
	HeapPrintS(&hp);
	HeapDestory(&hp);
	system("pause");
	return 0;
}