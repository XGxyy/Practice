#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v;

	for (int i = 1; i <= 10; ++i){
		/*int c = 0;
		cin >> c;*/
		v.push_back(i);
	}
#if 0//insert
	v.insert(v.begin() + 5, n, 20);//����n��20
#elif 0
	v.insert(v.begin() + 5, v.begin(), v.end());//���������
#else
	int a[5] = { 10, 20, 30, 40, 50 };
	v.insert(v.begin() + 5, a + 1, a + 3);//end���ڵ�λ���ǲ������
#endif

#if 0//erase
	v.erase(v.begin() + 5);//ɾ���±�Ϊ5��Ԫ��
#else
	v.erase(v.begin() + 5, v.end() - 3);//ɾ��5���±굽7���±��Ԫ��(��ɾend����Ԫ��)
#endif

	vector<int> v2;

	for (int i = 1; i <= 10; ++i){
		v2.push_back(i);
	}

//	v.swap(v2);
	//swap��������������������������������

	for (auto& i : v){
		cout << i << ' ';
	}
	
	return 0;
}