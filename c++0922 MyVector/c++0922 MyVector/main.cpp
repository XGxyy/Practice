#include <iostream>
#include "Vector.h"

using namespace std;

int main(){

	int a[] = { 1, 3, 1, 5, 7 };
	GZY::Vector<int>v(a, a + 5);

	for (int i = 0; i < v.size(); ++i){
		cout << v[i] << endl;
	}

	system("pause");
	return 0;
}