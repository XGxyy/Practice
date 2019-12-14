#include "dequeue.h"

int main(){
	Dequeue test;
	dequeueInit(&test);
	dequePush(&test, 1);
	dequePush(&test, 2);
	dequePush(&test, 3);
	printf("%d\n", dequeueFront(&test));
	dequeuePop(&test);
	printf("%d\n", dequeueFront(&test));
	system("pause");
	return 0;
}