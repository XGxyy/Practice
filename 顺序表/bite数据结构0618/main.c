#include "seqlist.h"

int main(){
	SeqList test;
	SeqListInit(&test, 10);
	SeqListPushBack(&test, 1);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 5);
	SeqListPushBack(&test, 6);
	SeqListPushBack(&test, 7);
	SeqListPushBack(&test, 8);
	SeqListPushBack(&test, 9);
	SeqListPushFront(&test, 10);
	SeqListPushFront(&test, 10);
	SeqListPushFront(&test, 10);
	SeqListPopBack(&test);
	SeqListInsert(&test, 1, 16);
	SeqListErase(&test, 5);
	SeqListPrint(&test);
	SeqListDestory(&test);
	system("pause");
	return 0;
}