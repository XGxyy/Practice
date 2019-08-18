#include "List.h"

void SListInit(SList* plist){
	assert(plist);
	plist->_head = NULL;
}

void SListDestory(SList* plist){
	SListNode* tmp;
	while (plist->_head){
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}



SListNode* BuySListNode(SLTDataType x);

void SListPushFront(SList* plist, SLTDataType x){
	assert(plist);
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}

void SListPopFront(SList* plist){
	assert(plist);
	if (plist->_head){
		SListNode* tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

SListNode* SListFind(SList* plist, SLTDataType x);

void SListInsertAfter(SListNode* pos, SLTDataType x){
	assert(pos);
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;
}

void SListEraseAfter(SListNode* pos){
	assert(pos);
	SListNode* tmp = pos->_next;
	pos->_next = tmp->_next;
	free(tmp);
}

void SListRemove(SList* plist, SLTDataType x);



void SListPrint(SList* plist){
	assert(plist);
	SListNode* cur;
	for (cur = plist->_head; cur; cur = cur->_next){
		printf("%d -> ", cur->_data);
	}
	printf("NULL\n");
}

void TestSList(){
	SList test;
	SListInit(&test);
	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 3);
	SListPushFront(&test, 4);
	SListPushFront(&test, 5);
	SListPushFront(&test, 6);
	SListPushFront(&test, 7);
	SListPushFront(&test, 10);
	SListPrint(&test);
}