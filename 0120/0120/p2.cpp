#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		//map�������,unordered_map�������
		unordered_map<char, int>map;
		for (int i = 0; i < magazine.length(); i++)
			map[magazine[i]] += 1;
		for (int i = 0; i < ransomNote.length(); i++)
		{
			map[ransomNote[i]] -= 1;
			if (map[ransomNote[i]] < 0)
				return false;
		}
		return true;
	}

	//������
	bool isPalindrome(int x) {
		string str;
		for (int i = x; i; i /= 10){
			
		}
	}

};

int main(){

	return 0;
}