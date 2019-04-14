#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Menu(){
	printf("██████████████████\n");
	printf("█　　　　　　　　　　　　　　　　█\n");
	printf("█　　　　　　　　　　　　　　　　█\n");
	printf("█　　　　　 扫      雷 　　　　　█\n");
	printf("█　　　　　　　   　 　　　　　　█\n");
	printf("█　　　　　　　　　　　　　　　　█\n");
	printf("█　　　　　　　　　　　　　　　　█\n");
	printf("█　　　  　1. 开始游戏   　　  　█\n");
	printf("█　　　　  0. 退出游戏     　　　█\n");
	printf("█　　    请输入您的选择：　　    █\n");
	printf("█　　　　　　　　　　　　　　　　█\n");
	printf("██████████████████\n");
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
	//如果是雷用"!",如果不是用0,1,2,3,4,5,6,7,8表示
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
	printf("███████████\n");
	for (int i = 0; i < MAXCHANG; ++i){
		printf("█");
		for (int j = 0; j < MAXKUAN; ++j){
			printf("%c ", map[i][j]);
		}
		printf("█\n");
	}
	printf("███████████\n");
	printf("****横纵坐标为0-8****\n");
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

//坐标周围展开
//void open_mine(int x, int y, char mine_map[MAXCHANG][MAXKUAN], char show_map[MAXCHANG][MAXKUAN]){
//	if (x - 1 >= 0 && y - 1 >= 0 && mine_map[x - 1][y - 1] == '0')
//	{
//		judge(x - 1, y - 1, mine_map, show_map);//显示该坐标周围雷数
//	}
//	if (x - 1 >= 0 && mine_map[x - 1][y] == '0')
//	{
//		judge(x - 1, y, mine_map, show_map);//显示该坐标周围雷数
//	}
//	if (x - 1 >= 0 && y + 1 < MAXKUAN && mine_map[x - 1][y + 1] == '0')
//	{
//		judge(x - 1, y + 1, mine_map, show_map);//显示该坐标周围雷数
//	}
//	if (y - 1 >= 0 && mine_map[x][y - 1] == '0')
//	{
//		judge(x, y - 1, mine_map, show_map);//显示该坐标周围雷数
//	}
//	if (y + 1 < MAXKUAN && mine_map[x][y + 1] == '0')
//	{
//		judge(x, y + 1, mine_map, show_map);//显示该坐标周围雷数
//	}
//	if (x + 1 <= MAXCHANG && y - 1 >= 0 && mine_map[x + 1][y - 1] == '0')
//	{
//		judge(x + 1, y - 1, mine_map, show_map);//显示该坐标周围雷数
//	}
//	if (x + 1 <= MAXCHANG && mine_map[x + 1][y] == '0')
//	{
//		judge(x + 1, y, mine_map, show_map);//显示该坐标周围雷数
//	}
//	if (x + 1 <= MAXCHANG && y + 1 < MAXKUAN && mine_map[x + 1][y + 1] == '0')
//	{
//		judge(x + 1, y + 1, mine_map, show_map);//显示该坐标周围雷数
//	}
//}

//int count_show_map(char show_map[MAXCHANG][MAXKUAN])//判断剩余未知区域的个数，个数为雷数时玩家赢
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
	//1.初始化地图：9*9（第一个二维数组）设置地雷；10个（第二个二维数组）
	_map(show_map, mine_map);
	//2.打印初始地图
	PrintMap(show_map);
	int num = 0;
	//3.玩家踩砖
	while (1){
		printf("请输入你要翻开的位置(先横后纵,空格隔开!): ");
		int c = 0;
		int k = 0;
		scanf("%d %d", &c, &k);
		if (c < 0 || c >= MAXCHANG || k < 0 || k >= MAXKUAN){
			printf("您的输入非法!请重输\n");
			continue;
		}
		if (show_map[c][k] != '*'){
			printf("此位置已近翻开!\n");
			continue;
		}
		//4.判断是否踩雷
		if (mine_map[c][k] == '!'){
			system("cls");
			printf("很遗憾!你踩到地雷了!\n");
			PrintMap(mine_map);
			system("pause");
			printf("game over!\n");
			system("cls");
			return;
		}
		++num;
		//5.判断胜利，若打开所有的非雷格子则游戏结束
		if (num == MAXCHANG * MAXKUAN - COUNT /*|| count_show_map(show_map) == COUNT*/){
			printf("恭喜你,winner!\n");
			return;
		}
		//6.若没有胜利也没有失败打印踩过砖块之后的地图
		//{
		//（1）若这里不是雷但周围有雷则打印周围8个格子的雷数
		//（2）若这里不是雷周围八个格子也没雷就打开周围的八个格子
		//（3）循环此操作一直到打开的每一个格子周围都有雷的警告为止
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
			printf("非法输入请重输\n");
		}
	}
	system("pause");
	return 0;
}