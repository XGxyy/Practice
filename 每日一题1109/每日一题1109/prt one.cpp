#include <iostream>
#include <string>
using namespace std;

bool judgeHW(string& str){
	int begin = 0;	
	int len = str.size();
	int end = len - 1; 
	for (; begin < end; begin++, end--){
		if (str[begin] != str[end]){
			return false;
		}
	}
	return true;
}

int newHW(string str1,string str2){
	int len = str1.size();

	int count = 0;
	for (int i = 0; i < len; i++){
		string tmp = str1;
		
		tmp.insert(i, str2);
		
		if (judgeHW(tmp)){
			count++;
		}
	}
	return count;
}

int main1(){
	string str1;
	string str2;

	getline(cin, str1);
	getline(cin, str2);
		cout << newHW(str1, str2) << endl;

	return 0;
}