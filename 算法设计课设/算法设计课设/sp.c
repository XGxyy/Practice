////题目一  最小费用购物
////问题描述 : 商店中每种商品都有标价.例如, 一朵花的价格是2元
////	   ..为了吸引顾客, 商店提供了一组优
////	   惠商品价.优惠商品是把一种或多种商品分成一组, 并降价
////	   销售.例如, 3朵花的价格不是6元而是5元.2个花瓶加1朵花
////	   的优惠价是10元.是设计一种算法, 计算出某一顾客所购商
////	   品应付的最少费用.参考的知识 : 动态规划.程序语言不限.
////动态规划算法也可以说是 '记住求过的解来节省时间'"
////	一朵花的价格是2元
////	一个花瓶的价格是5元
////	3朵花的价格不是6元而是5元.
////	2个花瓶加1朵花原价12元，优惠价是10元.
//
#include "ks.h"
//#define KIND 2//商品种类
//#define GROUP 2//特价组合数
//
////假定7是花 共三朵 原价2元
////    8是花瓶 共两个 原价5元
//
//void test(){
//	int ID;//C商品的编码
//	int NUM;//K购买该种商品的数量
//	int TruePrice;//P该种商品的正常单价
//	int num[1000];//货号对应的物品
//	int I[5][3] = { 0 };//购买的物品标号，个数，单价
//	int project[99][12] = { 0 };//优惠方案（种类，商品标号及个数，总价）
//	//Story* com = (Story*)malloc(sizeof(Story));
//	//assert(com != NULL);
//	int i[5], j[5];
//	int m, n, x, y;
//	int min;
//	int work[6][6][6][6][6];//表示每个物品可以买到的最小价格（每次购买的总价格）              
//	//设p_i为第i种优惠,将单价也视为一种优惠.
//	//dp[n1][n2][n3][n4][n5] = min m i = 1{dp[n1−pi1][n2−pi2][n3−pi3][n4−pi4][n5−pi5]}
//	/*FILE *fp;                   
//	fp = fopen("C:\\Users\\wangkexin\\Desktop\\input.txt", "r");
//	if (fp == NULL){
//		printf("fail!\n");
//	}*/
//	for (m = 0; m < KIND; m++){
//		printf("请按顺序输入第%d类商品的信息(编码，库存，真实价格)\n:", m + 1);
//		printf("*****注意用空格隔开！*****\n");
//		scanf("%d %d %d", &ID, &NUM, &TruePrice);
//		I[m][0] = ID;
//		I[m][1] = NUM;
//		I[m][2] = TruePrice;
//		num[ID] = m;
//	}
//	/*fclose(fp);
//	fp = NULL;*/
//	/*FILE* fpr = fopen("C:\\Users\\wangkexin\\Desktop\\OFFERO.txt", "r");
//	if (fpr == NULL){
//		printf("fail!\n");
//	}*/
//	//scanf("%d", &Group);
//	for (m = 0; m < GROUP; m++){
//		printf("请输入优惠政策需要购买的商品种类数:");
//		scanf("%d", &y);                //一个组合所需物品数量
//		project[m][0] = y;
//
//		for (n = 1; n <= 2 * y; n++){//判断是个数还是商品号
//			printf("先输购买个数要求，再输商品编号！:");
//			scanf("%d", &x);
//			if (n % 2 == 1){//x = 7， n = 1；x = 3， n = 2；
//				 project[m][n] = num[x];//p[0][2] = 3
//			}
//			else
//				project[m][n] = x;//p[0][1] = num[7]；
//		}
//		printf("请输入 %d 号优惠政策的价格:", m + 1);
//		scanf("%d", &project[m][n]);
//	}
//	work[0][0][0][0][0] = 0;//边界情况
//	for (i[0] = 0; i[0] <= I[0][1]; i[0]++){          //把所有商品 个数情况遍历一遍
//		for (i[1] = 0; i[1] <= I[1][1]; i[1]++){
//			for (i[2] = 0; i[2] <= I[2][1]; i[2]++){
//				for (i[3] = 0; i[3] <= I[3][1]; i[3]++){
//					for (i[4] = 0; i[4] <= I[4][1]; i[4]++){
//						if (i[0] == 0 && i[1] == 0 && i[2] == 0 && i[3] == 0 && i[4] == 0)
//							continue;//先出i[1]的循环即i[]是记录每个商品库存的数组
//						else{
//							work[i[0]][i[1]][i[2]][i[3]][i[4]] = 1000000;//work[0][1][0][0][0] = 1000000
//							min = i[0] * I[0][2] + i[1] * I[1][2] + i[2] * I[2][2] + i[3] * I[3][2] + i[4] * I[4][2];//总值
//							for (m = 0; m < GROUP; m++){
//								for (n = 0; n < 5; n++)
//									j[n] = i[n];//换j存
//								for (n = 1; n <= 2 * project[m][0]; n = n + 2){//m = 0,p[0][0] = 1,
//									if (i[project[m][n]] - project[m][n + 1] < 0)//p[0][1](编号)-p[0][2](库存)
//										j[project[m][n]] = 0;
//									else
//										j[project[m][n]] = i[project[m][n]] - project[m][n + 1];//j[0] = 4
//								}
//								if (work[j[0]][j[1]][j[2]][j[3]][j[4]] + project[m][n] < min)
//									min = work[j[0]][j[1]][j[2]][j[3]][j[4]] + project[m][n];
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	printf("最优解价格为：%d\n", min);
//}
////3 花  2 花瓶   方案一：5+10； 方案二：10+2+2
////
//
#include "ks.h"

int Menu(){
	int choice = 0;
	
	printf("                             ______________________________\n");
	printf("                            |                              |\n");
	printf("                            |       1.初始化我的商店       |\n"); 
	printf("                            |                              |\n");
	printf("                            |       2.购物的最小费用       |\n");
	printf("                            |                              |\n");
	printf("                            |       0.    exit  !          |\n");
	printf("                            |______________________________|\n");
	printf("您的选择是:");
    scanf("%d", &choice);
	return choice;
}

void Init(Stroy* sp){
	printf("请输入商品种类数!:");
	scanf("%d", &sp->KIND);
	for (int i = 0; i < sp->KIND; ++i){
		printf("请按顺序输入第%d类商品的信息(编码，库存，真实价格):\n", i + 1);
		printf("*****注意用空格隔开！*****\n");
		scanf("%d %d %d", &sp->data[i].ID, &sp->data[i].NUM, &sp->data[i].TruePrice);
		num[sp->data[i].ID] = i + 1;
	}
	printf("请输入您商店的特价方案个数:");
	int GROUP = 0;
	scanf("%d", &GROUP);
	for (int m = 0; m < GROUP; m++){
		int n, x, y;
		printf("请输入优惠政策需要购买的商品种类数:");
		scanf("%d", &y);                //一个组合所需物品数量
		project[m][0] = y;
		for (n = 1; n <= 2 * y; n++){//判断是个数还是商品号
			printf("输入商品编号，再输购买个数要求！:");
			scanf("%d", &x);
			if (n % 2 == 1){//x = 7， n = 1；x = 3， n = 2；
				project[m][n] = num[x];//p[0][1] = num[7] = ；
			}
			else
				project[m][n] = x;//p[0][2] = 3
		}
		printf("请输入 %d 号优惠政策的价格:", m + 1);
		scanf("%d", &project[m][n]);
	}
	for (int i = 0; i < CLASS; i++){
		for (int j = 0; j < CLASS; ++j){
			printf("%d ", project[i][j]);
		}
		putchar('\n');
	}
}

int MinCost(Stroy* sp){
	int A = sp->data[0].NUM;
	int B = sp->data[1].NUM;
	int C = 0;
	int D = 0;
	int E = 0;
	int i = 0; 
	int min = MAX;
	int FlowerM1 = MAX, FlowerM2 = MAX;
	int Flower;
	int Globle;
	for (i = 0; i < 2; i++){
		int A1 = project[i][1];//编号 
		int B1 = project[i][2];//个数
		int C1 = project[i][3];//编号
		int D1 = project[i][4];//个数
		int E1 = project[i][5];//优惠价格
			if (A1 == num[sp->data[0].ID] && C1 == D1 == 0){
				Flower = B1;
				if (project[i][5] / B1 < FlowerM1)
					FlowerM1 = project[i][5] / B1;
			}
			if ((A1 == num[sp->data[0].ID] && C1 == num[sp->data[1].ID]) || (A1 == num[sp->data[1].ID] && C1 == num[sp->data[0].ID])){
				if (A1 == num[sp->data[0].ID] && C1 == num[sp->data[1].ID])
					Globle = D1;
				else
					Globle = B1;
				if (project[i][5] * (sp->data[0].TruePrice / sp->data[0].TruePrice + sp->data[1].TruePrice) < FlowerM2)
					FlowerM2 = project[i][5] * (sp->data[0].TruePrice / sp->data[0].TruePrice + sp->data[1].TruePrice);
			}
		}
	if (FlowerM1 < FlowerM2){
		
			int g1 = sp->data[1].NUM / Globle;
			int g2 = (sp->data[0].NUM - g1) / 3;
			min = GROUPONE * g1 + g2 * 5 + (sp->data[0].NUM - g1 - g2 * 3) * sp->data[0].TruePrice + (sp->data[1].NUM - g1 * 2) * sp->data[1].TruePrice;
		
	}
		else{
			int g1 = sp->data[0].NUM / Flower;
			Flower = project[0][5] * (sp->data[0].NUM - g1 * Flower);
			min = g1 * project[0][5] * g1 + sp->data[0].TruePrice + sp->data[1].NUM  * sp->data[1].TruePrice;
		}
	if (min > A * sp->data[0].TruePrice + B * sp->data[1].TruePrice + C * sp->data[2].TruePrice + D * sp->data[3].TruePrice + E * sp->data[4].TruePrice)
		min = A * sp->data[0].TruePrice + B * sp->data[1].TruePrice + C * sp->data[2].TruePrice + D * sp->data[3].TruePrice + E * sp->data[4].TruePrice;
	return min;
}

void test(){
	Stroy sp;
	int project[CLASS][CLASS] = { 0 };//优惠方案（种类，商品标号及个数，总价）
	int min;
	while (1){
		int choice = Menu();
		if (choice == 1){
			Init(&sp);
			//system("pause");
			system("cls");
		}
		else if (choice == 2){
			if (sp.data[0].TruePrice > sp.data[1].TruePrice){
				int tmp1 = sp.data[1].TruePrice;
				sp.data[1].TruePrice = sp.data[0].TruePrice;
				sp.data[0].TruePrice = tmp1;
				int tmp2 = sp.data[1].ID;
				sp.data[1].ID = sp.data[0].ID;
				sp.data[0].ID = tmp2;
				int tmp3 = sp.data[1].NUM;
				sp.data[1].NUM = sp.data[0].NUM;
				sp.data[0].NUM = tmp3;
			}
			min = MinCost(&sp);
			printf("最优解价格为：%d\n", min);
			system("pause");
			system("cls");
		}
		else if (choice == 0){
			printf("感谢使用再见！\n");
			break;
		}
		else{
			printf("您的输入有误！\n");
		}
	}
}

int main(){
	test();
	system("pause");
	return 0;
}
//
////3*2+2*5 = 16;
////5+2*5 = 15;
////10+2*2 = 14;