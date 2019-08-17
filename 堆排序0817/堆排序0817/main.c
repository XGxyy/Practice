#include <stdio.h>
#include <stdlib.h>

void adjustDown(int* hp, int size, int m){
	int cur = m;
	int n;
	while (cur * 2 + 1 < size){
		if (cur * 2 + 2 >= size){
			n = cur * 2 + 1;
		}
		else{
			if (hp[cur * 2 + 1] > hp[cur * 2 + 2]){
				n = cur * 2 + 1;
			}
			else{
				n = cur * 2 + 2;
			}
		}
		if (hp[cur] < hp[n]){
			int tmp = hp[cur];
			hp[cur] = hp[n];
			hp[n] = tmp;
			cur = n;
		}
		else
			break;
	}
}

void HeapPop(int* hp, int size){
	if (size == 0){
		return;
	}
	int tmp = hp[0];
	hp[0] = hp[size - 1];
	hp[size - 1] = tmp;
	adjustDown(hp, size - 1, 0);
}

void HeapSort(int* src, int n){
	int i;
	for (i = n / 2 - 1; i >= 0; i--){
		adjustDown(src, n, i);
	}
	for (; n > 1; n--){
		HeapPop(src, n);
	}
}

void printArr(int* arr, int n){
	int i;
	for (i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}

int main(){
	int arr[] = { 1, 7, 9, 4, 3, 5, 2, 6, 15, 10, 12 };
	HeapSort(arr, 11);
	printArr(arr, 11);
	system("pause");
	return 0;
}