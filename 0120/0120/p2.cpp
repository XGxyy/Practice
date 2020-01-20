#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		//map是有序的,unordered_map是无序的
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
};

int main(){

	return 0;
}