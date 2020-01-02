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
	v.insert(v.begin() + 5, n, 20);//插入n个20
#elif 0
	v.insert(v.begin() + 5, v.begin(), v.end());//插入迭代器
#else
	int a[5] = { 10, 20, 30, 40, 50 };
	v.insert(v.begin() + 5, a + 1, a + 3);//end所在的位置是不插入的
#endif

#if 0//erase
	v.erase(v.begin() + 5);//删除下标为5的元素
#else
	v.erase(v.begin() + 5, v.end() - 3);//删除5号下标到7号下标的元素(不删end处的元素)
#endif

	vector<int> v2;

	for (int i = 1; i <= 10; ++i){
		v2.push_back(i);
	}

//	v.swap(v2);
	//swap函数在容器中是用来交换两个容器的

	for (auto& i : v){
		cout << i << ' ';
	}
	
	return 0;
}