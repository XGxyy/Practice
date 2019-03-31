#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>	
int find(int a[], int n, int f){
	int left = 0;
	int right = n - 1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (a[mid] == f)
		{
			return mid;
			break;
		}
		else if (a[mid] <= f)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (left > right)
	{
		return -1;
	}
}
int main(){
	int n = 0;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("请输入你要查找的数字：");
	int to_find = 0;
	scanf("%d", &to_find);
	n = sizeof(a) / sizeof(a[0]) - 1;
	printf("%d\n", find(a, n, to_find));
	system("pause");
	return 0;
}