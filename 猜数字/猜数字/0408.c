#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Menu(){
	printf("*************\n");
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("*************\n");
	printf("请输入你的选择：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Game(){
	int answer = rand() % 100 + 1;
	printf("请输入一个1-100之间的整数进行猜测：");
	while (1){
		int num = 0;
		scanf("%d", &num);

		if (num < answer){
			printf("低了\n");
		}
		else if (num>answer){
			printf("高了\n");
		}
		else{
			printf("猜对了！\n");
			break;
		}
	}
}
int main(){
	srand((unsigned int)time(0));
	while (1){
		int choice = Menu();
		if (choice == 0){
			printf("byebye!\n");
			break;
		}
		else if (choice == 1){
			Game();
		}
		else{
			printf("您的输入有误，请重新输入！");
		}
	}
	system("pause");
	return 0;
}