#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Menu(){
	printf("������������������������������������\n");
	printf("������������������������������������\n");
	printf("������������������������������������\n");
	printf("������������ ɨ      �� ������������\n");
	printf("����������������   �� ��������������\n");
	printf("������������������������������������\n");
	printf("������������������������������������\n");
	printf("��������  ��1. ��ʼ��Ϸ   ����  ����\n");
	printf("����������  0. �˳���Ϸ     ��������\n");
	printf("������    ����������ѡ�񣺡���    ��\n");
	printf("������������������������������������\n");
	printf("������������������������������������\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MAXCHANG 9
#define MAXKUAN 9
#define COUNT 10

void _map(char show_map[MAXCHANG][MAXKUAN], char mine_map[MAXCHANG][MAXKUAN]){
	for (int i = 0; i < MAXCHANG; ++i){
		for (int j = 0; j < MAXKUAN; ++j){
			show_map[i][j] = '*';
		}
	}
	for (int i = 0; i < MAXCHANG; ++i){
		for (int j = 0; j < MAXKUAN; ++j){
			mine_map[i][j] = '0';
		}
	}
	int count = COUNT;	
	//���������"!",���������0,1,2,3,4,5,6,7,8��ʾ
	while (count > 0){
		int mine_i = rand() % MAXCHANG;
		int minr_j = rand() % MAXKUAN;
		if (mine_map[mine_i][minr_j] == '!'){
			continue;
		}
		mine_map[mine_i][minr_j] = '!';
		--count;
	}
}

void PrintMap(char map[MAXCHANG][MAXKUAN]){
	printf("����������������������\n");
	for (int i = 0; i < MAXCHANG; ++i){
		printf("��");
		for (int j = 0; j < MAXKUAN; ++j){
			printf("%c ", map[i][j]);
		}
		printf("��\n");
	}
	printf("����������������������\n");
	printf("****��������Ϊ0-8****\n");
}

// (c-1,k-1) (c-1,k) (c-1,k+1)
// (c,k-1)   (c,k)   (c,k+1)
// (c+1,k-1) (c+1,k) (c+1,k+1)
//void open_mine(int x, int y, char mine_map[MAXCHANG][MAXKUAN], char show_map[MAXCHANG][MAXKUAN]);

void judge(int c, int k, char mine_map[MAXCHANG][MAXKUAN], char show_map[MAXCHANG][MAXKUAN]){
	int count = 0;
	if (c - 1 >= 0 && k-1 >= 0 && mine_map[c - 1][k - 1] == '!'){
		++count;
	}
	if (c - 1 >= 0 && mine_map[c - 1][k] == '!'){
		++count;
	}
	if (c - 1 >= 0 && k + 1 < MAXKUAN && mine_map[c - 1][k + 1] == '!'){
		++count;
	}
	if (k - 1 >= 0 && mine_map[c][k - 1] == '!'){
		++count;
	}
	if (k + 1 < MAXKUAN && mine_map[c][k + 1] == '!'){
		++count;
	}
	if (c + 1 <= MAXCHANG && k - 1 >= 0 && mine_map[c + 1][k - 1] == '!'){
		++count;
	}
	if (c + 1 <= MAXCHANG && mine_map[c + 1][k] == '!'){
		++count;
	}
	if (c + 1 <= MAXCHANG && k + 1 < MAXKUAN && mine_map[c + 1][k + 1] == '!'){
		++count;
	}
	show_map[c][k] = count + '0';
	//if (count == 0){
	//	open_mine(c, k, mine_map, show_map);
	//}
	//else{
	//	return;
	//}
}

//������Χչ��
//void open_mine(int x, int y, char mine_map[MAXCHANG][MAXKUAN], char show_map[MAXCHANG][MAXKUAN]){
//	if (x - 1 >= 0 && y - 1 >= 0 && mine_map[x - 1][y - 1] == '0')
//	{
//		judge(x - 1, y - 1, mine_map, show_map);//��ʾ��������Χ����
//	}
//	if (x - 1 >= 0 && mine_map[x - 1][y] == '0')
//	{
//		judge(x - 1, y, mine_map, show_map);//��ʾ��������Χ����
//	}
//	if (x - 1 >= 0 && y + 1 < MAXKUAN && mine_map[x - 1][y + 1] == '0')
//	{
//		judge(x - 1, y + 1, mine_map, show_map);//��ʾ��������Χ����
//	}
//	if (y - 1 >= 0 && mine_map[x][y - 1] == '0')
//	{
//		judge(x, y - 1, mine_map, show_map);//��ʾ��������Χ����
//	}
//	if (y + 1 < MAXKUAN && mine_map[x][y + 1] == '0')
//	{
//		judge(x, y + 1, mine_map, show_map);//��ʾ��������Χ����
//	}
//	if (x + 1 <= MAXCHANG && y - 1 >= 0 && mine_map[x + 1][y - 1] == '0')
//	{
//		judge(x + 1, y - 1, mine_map, show_map);//��ʾ��������Χ����
//	}
//	if (x + 1 <= MAXCHANG && mine_map[x + 1][y] == '0')
//	{
//		judge(x + 1, y, mine_map, show_map);//��ʾ��������Χ����
//	}
//	if (x + 1 <= MAXCHANG && y + 1 < MAXKUAN && mine_map[x + 1][y + 1] == '0')
//	{
//		judge(x + 1, y + 1, mine_map, show_map);//��ʾ��������Χ����
//	}
//}

//int count_show_map(char show_map[MAXCHANG][MAXKUAN])//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
//{
//	int count = 0;
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= MAXCHANG - 2; i++)
//	{
//		for (j = 1; j <= MAXKUAN - 2; j++)
//		{
//			if (show_map[i][j] == '*')
//			{
//				count++;
//			}
//		}
//
//	}
//	return count;
//}

void game(){
	char show_map[MAXCHANG][MAXKUAN] = { 0 };
	char mine_map[MAXCHANG][MAXKUAN] = { 0 };
	//1.��ʼ����ͼ��9*9����һ����ά���飩���õ��ף�10�����ڶ�����ά���飩
	_map(show_map, mine_map);
	//2.��ӡ��ʼ��ͼ
	PrintMap(show_map);
	int num = 0;
	//3.��Ҳ�ש
	while (1){
		printf("��������Ҫ������λ��(�Ⱥ����,�ո����!): ");
		int c = 0;
		int k = 0;
		scanf("%d %d", &c, &k);
		if (c < 0 || c >= MAXCHANG || k < 0 || k >= MAXKUAN){
			printf("��������Ƿ�!������\n");
			continue;
		}
		if (show_map[c][k] != '*'){
			printf("��λ���ѽ�����!\n");
			continue;
		}
		//4.�ж��Ƿ����
		if (mine_map[c][k] == '!'){
			system("cls");
			printf("���ź�!��ȵ�������!\n");
			PrintMap(mine_map);
			system("pause");
			printf("game over!\n");
			system("cls");
			return;
		}
		++num;
		//5.�ж�ʤ�����������еķ��׸�������Ϸ����
		if (num == MAXCHANG * MAXKUAN - COUNT /*|| count_show_map(show_map) == COUNT*/){
			printf("��ϲ��,winner!\n");
			return;
		}
		//6.��û��ʤ��Ҳû��ʧ�ܴ�ӡ�ȹ�ש��֮��ĵ�ͼ
		//{
		//��1�������ﲻ���׵���Χ�������ӡ��Χ8�����ӵ�����
		//��2�������ﲻ������Χ�˸�����Ҳû�׾ʹ���Χ�İ˸�����
		//��3��ѭ���˲���һֱ���򿪵�ÿһ��������Χ�����׵ľ���Ϊֹ
		//}
		judge(c, k, mine_map, show_map);
		system("cls");
		PrintMap(show_map);
	}
	
}

int main(){
	srand((unsigned int)time(0));
	while (1){
		int choice = Menu();
		system("cls");
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("good bye!\n");
			break;
		}
		else{
			printf("�Ƿ�����������\n");
		}
	}
	system("pause");
	return 0;
}