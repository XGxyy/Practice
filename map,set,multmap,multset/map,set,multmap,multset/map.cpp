#include <iostream>
#include <map>

using namespace std;

//map�м�ֵ��Ωһ��,����Ԫ��ʹ�õľ��Ǽ�ֵ

int main(){
	pair<int, int> p;
	p.first = 1;
	p.second = 2;
	
	map<int, int> m;
	m.insert(p);

	map<int, int>::iterator mi = m.begin();

	cout << mi->first << endl;
	cout << mi->second << endl;

	return 0;
}