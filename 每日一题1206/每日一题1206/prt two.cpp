#include <iostream>
#include <string>
using namespace std;

const int Num_root(int n){
	int count = 0;
	if (n < 10){
		return n;
	}
	for (int i = n; i; i /= 10){
		count = count + (i % 10);
	}
	//if (count >= 10){
	//	Num_root(count);
	//	
	//}

		return count;

}

int Num_root(string num){ 
	int cur = 0; 
	for (auto& c : num) 
		cur += c - '0'; 
	num = to_string(cur); 
	while (num.size() > 1)    { 
		cur = 0;   
		for (auto& c : num)
			
			cur += c - '0';   
		num = to_string(cur);
	}    
	return cur; 
}

int main(){
	string num;
	while (cin >> num){
		int root = Num_root(num);
		cout << root << endl;
	}
	return 0;
}