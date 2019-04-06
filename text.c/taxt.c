#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define chang 3
#define kuan 3

char arr[chang][kuan] = { 0 };

int Menu(){
	printf("================\n");
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("================\n");
	printf("请输入你的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//满了返回1,没有返回0
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
	printf("请问玩家输入落子位置坐标(注意最小下标是0哦!空格隔开!):");
	int pc = 0;
	int pk = 0;
	scanf("%d %d", &pc, &pk);
		if (pc > chang - 1 || pk > kuan - 1 || pc < 0 || pk < 0){
			printf("您的输入非法请重输\n");
			continue;
		}
		if (arr[pc][pk] != ' '){
			printf("此位置已被占用,请重输\n");
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
			//被占用了重新随机
			continue;
		}
		arr[cc][ck] = 'o';
		break;
	}
}
//返回x玩家胜
//返回o电脑胜
//返回q和气
//返回空格表示还在继续
char judge(){
	//行
	for (int i = 0; i < chang; ++i){
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]){
			return arr[i][0];
		}
	}
	//列
	for (int i = 0; i < kuan; ++i){
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]){
			return arr[0][i];
		}
	}
	//对角线
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
	//初始化数组

	init();
	char win = '0';
	while (1){
		//打印棋盘
		print();
		//玩家落子
		people();
		//检测输赢
		win = judge();
		if (win != ' '){
			//比完了
			break;
		}
		//电脑落子
		computer();
		//检测输赢
		win = judge();
		if (win != ' '){
			//比完了
			break;
		}
	}
	if (win == 'x'){
		printf("你赢了!\n");
	}
	else if (win == 'o'){
		printf("电脑都打不过哦!\n");
	}
	else if (win == 'q'){
		printf("five five open???\n");
	}
	else {
		printf("怕是出错了...\n");
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
			printf("您的输入有误，请重新输入\n");
		}
	}
	system("pause");
	return 0;
}