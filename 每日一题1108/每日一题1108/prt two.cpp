#include <iostream>
#include <vector>
using namespace std;

int main(){
	int num = 0, index = 0;
	cout << "��������һ��ʮ����������������Ҫת���Ľ��ơ�";
	cin >> num >> index;
	char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	vector<char> end ;
	int point = 0, j = 0;
	for (int i = num; i; i /= index){
			end.push_back(hex[i % index]);
			j++;	
	}
	for (vector<char>::reverse_iterator it = end.rbegin(); it != end.rend(); ++it)
	{
		cout << *it;
	}
	cout << "\n";
	return 0;
}