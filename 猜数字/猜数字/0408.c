#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Menu(){
	printf("*************\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("*************\n");
	printf("���������ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Game(){
	int answer = rand() % 100 + 1;
	printf("������һ��1-100֮����������в²⣺");
	while (1){
		int num = 0;
		scanf("%d", &num);

		if (num < answer){
			printf("����\n");
		}
		else if (num>answer){
			printf("����\n");
		}
		else{
			printf("�¶��ˣ�\n");
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
			printf("���������������������룡");
		}
	}
	system("pause");
	return 0;
}