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
	vector<int> v(n, 0);//其他位全是0但是不打印0
	v[0] = 1;
	printArr(v, 1);
	for (int i = 1; i < n; i++){
		//执行的次数(从第二行开始跑)
		for (int j = i; j > 0; j--){
			//第n行填n个数
			v[j] += v[j - 1];
		}
		printArr(v, i + 1);
	}
}

vector<vector<int>> generate(int numRows){
	vector<vector<int>> data(numRows);//numRows个顺序表容器构成的int顺序表容器
	
	int i, j;
	data[0].push_back(1);
	//1
	//1 1
	//1 2 1
	//1 3 3 1
	for (i = 1; i < numRows; i++){
		data[i] = data[i - 1];
		for (j = i - 1; j > 0; j--){
			data[i][j] += data[i][j - 1];//不使用push_back无法扩容会报错
		}
		data[i].push_back(1);//手动多插入一个不会越界
	}
	return data;
}

int main1(){
	//printGener(10);(一维数组打印杨辉三角)
#if 0//双层vector的应用(模拟二维数组)
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