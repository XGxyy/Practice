#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_dict(vector<string>& str){

	for (int i = 0; i < str.size() - 1; i++){

		if (str[i] > str[i + 1]){

			return false;
		}

	}

	return true;
}

bool is_len(vector<string>& str){
	for (int i = 0; i < str.size() - 1; i++){
		if (str[i].size() > str[i + 1].size()){
			return false;
		}
	}

	return true;
}

int main(){
	int n = 0;
	cin >> n;

	vector<string> str;
	str.resize(n);

	for (int i = 0; i < n; i++){
		//cin.get();//取走缓冲区中的\n符
		cin >> str[i];
	}

	if (is_dict(str) && !is_len(str)){
		cout << "lexicographically" << endl;
	}
	else if (!is_dict(str) && is_len(str)){ 
		cout << "lengths" << endl; 
	}
	else if (is_dict(str) && is_len(str)){
		cout << "both" << endl;
	}
	else{
		cout << "none" << endl;
	}

	return 0;
}