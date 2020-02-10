#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int count = 0;
		int tmp = 0;
		for (int i = 0; i < s.size(); i++){		
			if (s[i] == ' '){
				tmp = 0;
				continue;
			}
			tmp++;
			count = tmp;
		}
		return count;
	}
};

int main1(){
	string s = "Hellow Word";
	Solution a;
	cout << a.lengthOfLastWord(s);
	return 0;
}