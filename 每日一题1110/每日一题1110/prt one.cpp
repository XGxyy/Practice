#include <iostream>
#include <string>
using namespace std;

class Solution {
public://+ 1024
	int StrToInt(string str) {
		int len = str.size();
		char first = str[0];
		int num = 0;
		int count = 1;
		for (int i = len - 1; i > 0; i--){
			if (str[i] > '9' || str[i] < '0'){
				return 0;
			}
			num = num + (str[i] - '0') * count;
			count *= 10;
		}
		if (first == '-'){
			return -num;
		}
		else{
			return num;
		}
	}
};

int main1(){
	string str;
	cin >> str;
	Solution a;
	cout << a.StrToInt(str) << endl;
	return 0;
}