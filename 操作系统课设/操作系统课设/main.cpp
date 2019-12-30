#include "main.h"
#define NUM 100
#define J 3//���̶���������

using namespace std;

char name[NUM];
int claim[NUM][NUM] = { 0 };//�������
int allocation[NUM][NUM] = { 0 };//�ѷ��䵽����Դ
int need[NUM][NUM] = { 0 };//����Ҫ����Դ

int request[NUM] = { 0 };//������Դ����
int Avaliable[NUM] = { 0 };//ϵͳ������Դ
int Work[NUM] = { 0 };//ϵͳʣ����Դ

int tmp[NUM] = { 0 };//��Ű�ȫ����


int p_num = 0;//���̸���
int m_num = 0;//��Դ������

void Init(){
	cout << "��������̸�������Դ������:";
	cin >> p_num >> m_num;
	cout << "P����Դ����:";
	for (int c = 0; c < m_num; c++){
		cin >> name[c];
	}
	for (int i = 0; i < p_num; i++){
		cout << "P" << i + 1 << "����Դ����:";
		for (int j = 0; j < m_num; j++){

			cin >> claim[i][j];
		}

		cout << "P" << i + 1 << "���ѷ�����Դ��:";
		for (int b = 0; b < m_num; ++b){
			cin >> allocation[i][b];
			need[i][b] = claim[i][b] - allocation[i][b];
		}
	}
}

//��ʾ��Դ
void showdata(){
	int i, j;
	cout << "ϵͳĿǰ���õ���Դ[Avaliable]:" << endl;
	for (i = 0; i < m_num; i++){
		cout << name[i] << " ";
	}
	cout << endl;

	for (j = 0; j < m_num; j++){
		cout << Avaliable[j] << " ";//���������Դ
	}
	cout << endl;

	cout << "         Claim      Allocation    need" << endl;

	cout << "������   ";

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
	cout << "������ϵͳ������Դ[Avaliable]:";
	for (int i = 0; i < m_num; i++){
		cin >> Avaliable[i];
	}
}

void change_data(int i){//������Դ����
	int j, t;
	t = 0;
	for (j = 0; j < m_num; j++) {

		Avaliable[j] = Avaliable[j] - request[j];

		allocation[i][j] = allocation[i][j] + request[j];

		need[i][j] = need[i][j] - request[j];
	}

}

int check(){//��ȫ���
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
						Work[m] = Work[m] + allocation[i][m];//�������
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
			cout << "ϵͳ����ȫ" << endl;//���ɹ�ϵͳ����ȫ
			return -1;
		}

	}

	cout << "ϵͳ�ǰ�ȫ��!" << endl;//�����ȫ������ɹ�
	system("pause");
	cout << "���������:";

	for (i = 0; i < p_num; i++){//������н�������
		cout << "P" << tmp[i] + 1;
		if (i < p_num - 1) {
			cout << "->";
		}
	}
	cout << endl;
	return 0;
}

void Bank_check(){//���м��㷨
	int flag;
	int i = 0, j = 0;

	flag = 1;
	cout << "������Ҫ��������Դ���̺�(1-" << p_num << "):";
	cin >> i;//�������������Դ��
	i = i - 1;
	cout << "���������P" << i + 1 << " �������Դ:" << endl;

	for (j = 0; j < m_num; j++){
		cout << name[j] << ":";
		cin >> request[j];//������Ҫ�������Դ
	}

	for (j = 0; j < m_num; j++){
		if (request[j] > need[i][j]){//�ж������Ƿ�������������������
			cout << "����P" << i + 1 << "�������Դ��������Ҫ����Դ";
			cout << " ����������󣬷��䲻����������䣡" << endl;
			flag = 0;
			break;
		}

		else {

			if (request[j] > Avaliable[j]){//�ж������Ƿ���ڵ�ǰ��Դ�������������
				cout << "����P" << i + 1 << "�������Դ����ϵͳ���ڿ����õ���Դ";
				cout << " ������ڵ�ǰ��Դ����������������!" << endl;
				flag = 0;
				break;
			}
		}
	}

	if (flag == 1) {
		change_data(i);//���ݽ����������任��Դ
		showdata();//���ݽ�����������ʾ�任�����Դ
		check();//���ݽ����������������м��㷨�ж�

		//����
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
	printf("|   1.��ȫ�Լ��    |\n");
	printf("|   2.���м��㷨    |\n");
	printf("|     0.�˳�        |\n");
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
			cout << "����������������������" << endl;
		}
	}

}

void test(){
	int choice = 0;
	while (1){
		system("cls");
		printf(" _______________________________\n");
		printf("|                               |\n");
		printf("|           1.¼�����          |\n");
		printf("|           2.�㷨ѡ��          |\n");
		printf("|         3.��ʾ��Դ����        |\n");
		printf("|       4.����ϵͳ������Դ      |\n");
		printf("|            0.�˳�             |\n");
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
			cout << "���˳�" << endl;
			break;
		}
		else{
			cout << "����������������������" << endl;
		}
	}

}

int main(){
	test();
	return 0;
}
