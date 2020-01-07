#include <iostream>
#include <vector>

using namespace std;

void printArr(const vector<int>& v, int n){
	for (int i = 0; i < n; i++){
		cout << v[i] << ' ';
	}
	cout << endl;
}

void printGener(int n){
	vector<int> v(n, 0);//����λȫ��0���ǲ���ӡ0
	v[0] = 1;
	printArr(v, 1);
	for (int i = 1; i < n; i++){
		//ִ�еĴ���(�ӵڶ��п�ʼ��)
		for (int j = i; j > 0; j--){
			//��n����n����
			v[j] += v[j - 1];
		}
		printArr(v, i + 1);
	}
}

vector<vector<int>> generate(int numRows){
	vector<vector<int>> data(numRows);//numRows��˳����������ɵ�int˳�������
	
	int i, j;
	data[0].push_back(1);
	//1
	//1 1
	//1 2 1
	//1 3 3 1
	for (i = 1; i < numRows; i++){
		data[i] = data[i - 1];
		for (j = i - 1; j > 0; j--){
			data[i][j] += data[i][j - 1];//��ʹ��push_back�޷����ݻᱨ��
		}
		data[i].push_back(1);//�ֶ������һ������Խ��
	}
	return data;
}

int main1(){
	//printGener(10);(һά�����ӡ�������)
#if 0//˫��vector��Ӧ��(ģ���ά����)
	vector<vector<int>> data(10);

	data[0].push_back(3);
	data[0].push_back(5);

	for (int i = 0; i < 10; i++){
		data[i] = data[0];
	}

	for (int i = 0; i < 10; i++){
		cout << data[i][0] << ' ' << data[i][1] << endl;
	}
#else
	vector<vector<int>> data = generate(10);
	for (auto& i : data){
		for (auto& j : i){
			cout << j << ' ';
		}
		cout << endl;
	}
#endif
	return 0;
}