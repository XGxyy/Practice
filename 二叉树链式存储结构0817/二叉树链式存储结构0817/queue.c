#include "Queue.h"

void QueueInit(Queue* plist){
	assert(plist);
	plist->_head = NULL;
	plist->_rear = NULL;
}

void QueueDestory(Queue* plist){
	QueueNode* tmp;
	while (plist->_head){
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}


void QueuePush(Queue* plist, QuDataType x){
	assert(plist);
	QueueNode* cur = (QueueNode*)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;

	if (QueueEmpty(plist)){
		plist->_head = plist->_rear = cur;
		return;
	}
	plist->_rear->_next = cur;
	plist->_rear = cur;
}

void QueuePop(Queue* plist){
	assert(plist);
	if (plist->_head){
		QueueNode* tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

int QueueEmpty(Queue* plist){
	return plist->_head == NULL;
}

QuDataType QueueTop(Queue* plist){
	if (QueueEmpty(plist)){
		return (QuDataType)0;
	}
	
	return plist->_head->_data;
}













