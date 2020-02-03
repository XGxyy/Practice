#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int i, j = 1;
		int count = 0;
		if (x < 0) {
			return false;
		}
		int tmp = x;
		for (i = tmp; tmp; tmp /= 10){
			count = count * 10 + tmp % 10;
		}
		if (count == x){
			return true;
		}
		else{
			return false;
		}
	}
};
//124  421


int main(){
	Solution a;
	cout << a.isPalindrome(121);
	
	return 0;
}