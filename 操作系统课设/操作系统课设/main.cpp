#include "main.h"
#define NUM 100
#define J 3//表格固定三组数据

using namespace std;

char name[NUM];
int claim[NUM][NUM] = { 0 };//最大需求
int allocation[NUM][NUM] = { 0 };//已分配到的资源
int need[NUM][NUM] = { 0 };//还需要的资源

int request[NUM] = { 0 };//请求资源向量
int Avaliable[NUM] = { 0 };//系统可用资源
int Work[NUM] = { 0 };//系统剩余资源

int tmp[NUM] = { 0 };//存放安全序列


int p_num = 0;//进程个数
int m_num = 0;//资源种类数

void Init(){
	cout << "请输入进程个数和资源种类数:";
	cin >> p_num >> m_num;
	cout << "P的资源名称:";
	for (int c = 0; c < m_num; c++){
		cin >> name[c];
	}
	for (int i = 0; i < p_num; i++){
		cout << "P" << i + 1 << "的资源总数:";
		for (int j = 0; j < m_num; j++){

			cin >> claim[i][j];
		}

		cout << "P" << i + 1 << "的已分配资源数:";
		for (int b = 0; b < m_num; ++b){
			cin >> allocation[i][b];
			need[i][b] = claim[i][b] - allocation[i][b];
		}
	}
}

//显示资源
void showdata(){
	int i, j;
	cout << "系统目前可用的资源[Avaliable]:" << endl;
	for (i = 0; i < m_num; i++){
		cout << name[i] << " ";
	}
	cout << endl;

	for (j = 0; j < m_num; j++){
		cout << Avaliable[j] << " ";//输出分配资源
	}
	cout << endl;

	cout << "         Claim      Allocation    need" << endl;

	cout << "进程名   ";

	for (j = 0; j < J; j++){
		for (i = 0; i < m_num; i++){
			cout << name[i] << " ";
		}
		cout << "      ";
	}
	cout << endl;

	for (i = 0; i < p_num; i++){
		cout << "P" << i + 1 << "        ";
		for (j = 0; j < m_num; j++){
			cout << claim[i][j] << " ";
		}
		cout << "      ";

		for (j = 0; j < m_num; j++){
			cout << allocation[i][j] << " ";
		}
		cout << "      ";

		for (j = 0; j < m_num; j++){
			cout << need[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}

void change_Avaliable(){
	cout << "请设置系统可用资源[Avaliable]:";
	for (int i = 0; i < m_num; i++){
		cin >> Avaliable[i];
	}
}

void change_data(int i){//进行资源分配
	int j, t;
	t = 0;
	for (j = 0; j < m_num; j++) {

		Avaliable[j] = Avaliable[j] - request[j];

		allocation[i][j] = allocation[i][j] + request[j];

		need[i][j] = need[i][j] - request[j];
	}

}

int check(){//安全检查
	int i, k = 0, m, apply, Finish[100] = { 0 };
	int j;
	//int flag = 0;

	for (i = 0; i < m_num; i++){
		Work[i] = Avaliable[i];
	}

	for (i = 0; i < p_num; i++){
		apply = 0;
		for (j = 0; j < m_num; j++){
			if (Finish[i] == 0 && need[i][j] <= Work[j]){
				apply++;
				if (apply == m_num){
					for (m = 0; m < m_num; m++){
						Work[m] = Work[m] + allocation[i][m];//变分配数
					}
					Finish[i] = 1;
					tmp[k] = i;
					i = -1;

					k++;
					//flag++;
				}
			}
		}
	}

	for (i = 0; i < m_num; i++){
		if (Finish[i] == 0){
			cout << "系统不安全" << endl;//不成功系统不安全
			return -1;
		}

	}

	cout << "系统是安全的!" << endl;//如果安全，输出成功
	system("pause");
	cout << "分配的序列:";

	for (i = 0; i < p_num; i++){//输出运行进程数组
		cout << "P" << tmp[i] + 1;
		if (i < p_num - 1) {
			cout << "->";
		}
	}
	cout << endl;
	return 0;
}

void Bank_check(){//银行家算法
	int flag;
	int i = 0, j = 0;

	flag = 1;
	cout << "请输入要求分配的资源进程号(1-" << p_num << "):";
	cin >> i;//输入须申请的资源号
	i = i - 1;
	cout << "请输入进程P" << i + 1 << " 申请的资源:" << endl;

	for (j = 0; j < m_num; j++){
		cout << name[j] << ":";
		cin >> request[j];//输入需要申请的资源
	}

	for (j = 0; j < m_num; j++){
		if (request[j] > need[i][j]){//判断申请是否大于需求，若大于则出错
			cout << "进程P" << i + 1 << "申请的资源大于它需要的资源";
			cout << " 申请大于需求，分配不合理，不予分配！" << endl;
			flag = 0;
			break;
		}

		else {

			if (request[j] > Avaliable[j]){//判断申请是否大于当前资源，若大于则出错
				cout << "进程P" << i + 1 << "申请的资源大于系统现在可利用的资源";
				cout << " 申请大于当前资源，分配出错，不予分配!" << endl;
				flag = 0;
				break;
			}
		}
	}

	if (flag == 1) {
		change_data(i);//根据进程需求量变换资源
		showdata();//根据进程需求量显示变换后的资源
		check();//根据进程需求量进行银行家算法判断

		//回收
		int a = check();
		if (a == -1){
			for (j = 0; j < m_num; j++) {
				Avaliable[j] = Avaliable[j] + request[j];
			}
		}
		int t = 0;
		for (int a = 0; a < m_num; a++){

			if (allocation[i][a] == claim[i][a]){
				t++;
			}
		}
		if (t == m_num && a == 0){
			for (j = 0; j < m_num; j++) {
				Avaliable[j] = Avaliable[j] + claim[i][j];
			}
		}
	}
}

void al_sel(){
	system("cls");
	printf(" ___________________\n");
	printf("|                   |\n");
	printf("|   1.安全性检查    |\n");
	printf("|   2.银行家算法    |\n");
	printf("|     0.退出        |\n");
	printf("|                   |\n");
	printf("|___________________|\n");
	int sle = 0;
	while (cin >> sle){
		if (sle == 1){
			check();
		}
		else if (sle == 2){
			Bank_check();
		}
		else if (sle == 0){
			test();
			break;
		}
		else{
			cout << "您的输入有误请重新输入" << endl;
		}
	}

}

void test(){
	int choice = 0;
	while (1){
		system("cls");
		printf(" _______________________________\n");
		printf("|                               |\n");
		printf("|           1.录入进程          |\n");
		printf("|           2.算法选择          |\n");
		printf("|         3.显示资源矩阵        |\n");
		printf("|       4.设置系统可用资源      |\n");
		printf("|            0.退出             |\n");
		printf("|_______________________________|\n");
		cin >> choice;
		if (choice == 1){
			Init();
		}
		else if (choice == 2){
			al_sel();
		}
		else if (choice == 3){
			showdata();
		}
		else if (choice == 4){
			change_Avaliable();
		}
		else if (choice == 0){
			cout << "已退出" << endl;
			break;
		}
		else{
			cout << "您的输入有误请重新输入" << endl;
		}
	}

}

int main(){
	test();
	return 0;
}
