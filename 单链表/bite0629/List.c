#include "List.h"

void ListInit(List* plist){
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	memset(&plist->_head->_data, 0, sizeof(LTDataType));
	plist->_head->_next = plist->_head->_prev = plist->_head;
}

void ListPushBack(List* plist, LTDataType x){
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev = cur;
	cur->_next = plist->_head;
	if (plist->_head->_next = plist->_head){
		plist->_head->_next = cur;
	}
}

void ListPopBack(List* plist){
	ListNode* tmp = plist->_head->_prev;
	if (tmp != plist->_head){
		plist->_head->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}

void ListPushFront(List* plist, LTDataType x){
	//等于单链表后插
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->_next = plist->_head->_next;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
	if (plist->_head->_prev = plist->_head){
		plist->_head->_prev = cur;
	}
}
void ListPopFront(List* plist){
	ListNode* tmp = plist->_head->_next;
	if (tmp != plist->_head){
		plist->_head->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}

void ListDestory(List* plist){
	ListNode* tmp = plist->_head->_next;
	while (tmp != plist->_head){
		plist->_head->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
		tmp = plist->_head->_next;
	}
}