#include <iostream>
#include <map>

using namespace std;

//map中键值是惟一的,查找元素使用的就是键值

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