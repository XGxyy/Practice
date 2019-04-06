#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define chang 3
#define kuan 3

char arr[chang][kuan] = { 0 };

int Menu(){
	printf("================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("================\n");
	printf("���������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//���˷���1,û�з���0
int IsFull(){
	for (int i = 0; i < chang; ++i){
		for (int j = 0; j < kuan; ++j){
			if (arr[i][j] == ' '){
				return 0;
			}
		}
	}
	return 1;
}

void init(){
	for (int i = 0; i < chang; ++i){
		for (int j = 0; j < kuan; ++j){
			arr[i][j] = ' ';
		}
	}
}

void print(){
	for (int i = 0; i < chang; ++i){
		printf("| %c | %c | %c |\n", arr[i][0], arr[i][1], arr[i][2]);
		if (i < chang - 1){
			printf("|---|---|---|\n");
		}
	}
}

void people(){
	while (1){
	printf("���������������λ������(ע����С�±���0Ŷ!�ո����!):");
	int pc = 0;
	int pk = 0;
	scanf("%d %d", &pc, &pk);
		if (pc > chang - 1 || pk > kuan - 1 || pc < 0 || pk < 0){
			printf("��������Ƿ�������\n");
			continue;
		}
		if (arr[pc][pk] != ' '){
			printf("��λ���ѱ�ռ��,������\n");
			continue;
		}
			arr[pc][pk] = 'x';
			break;
	}
}
		
void computer(){
	while (1){
		int cc = rand() % chang;
		int ck = rand() % kuan;
		if (arr[cc][ck] != ' '){
			//��ռ�����������
			continue;
		}
		arr[cc][ck] = 'o';
		break;
	}
}
//����x���ʤ
//����o����ʤ
//����q����
//���ؿո��ʾ���ڼ���
char judge(){
	//��
	for (int i = 0; i < chang; ++i){
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]){
			return arr[i][0];
		}
	}
	//��
	for (int i = 0; i < kuan; ++i){
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]){
			return arr[0][i];
		}
	}
	//�Խ���
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){
		return arr[0][0];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]){
		return arr[0][2];
	}
	if (IsFull()==1){
		return 'h';
	}
	return ' ';
}

void Game(){
	//��ʼ������

	init();
	char win = '0';
	while (1){
		//��ӡ����
		print();
		//�������
		people();
		//�����Ӯ
		win = judge();
		if (win != ' '){
			//������
			break;
		}
		//��������
		computer();
		//�����Ӯ
		win = judge();
		if (win != ' '){
			//������
			break;
		}
	}
	if (win == 'x'){
		printf("��Ӯ��!\n");
	}
	else if (win == 'o'){
		printf("���Զ��򲻹�Ŷ!\n");
	}
	else if (win == 'q'){
		printf("five five open???\n");
	}
	else {
		printf("���ǳ�����...\n");
	}
}

int main(){
	srand((unsigned int)time(0));
	while (1){
		int choice = Menu();
		if (choice == 1){
			Game();
		}
		else if (choice == 0){
			printf("byebye!\n");
			break;
		}
		else{
			printf("����������������������\n");
		}
	}
	system("pause");
	return 0;
}