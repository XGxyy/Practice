#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string toLowerCase(string str) {
		int len = str.size();
		for (int i = 0; i < len; i++){
			if (str[i] >= 'A' && str[i] <= 'Z'){
				str[i] += 32;
			}
		}
		return str;
	}
	void rotate(vector<int>& nums, int k) {
		while (k){
			int tmp = nums[nums.size() - 1];
			
			for (int i = nums.size() - 2; i >= 0; i--){
				nums[i + 1] = nums[i];			
			}
			nums[0] = tmp;
			k--;
		}
	}
};

int main1(){
	Solution a;
#if 0
	string str = "Hello";
	
	
	cout << a.toLowerCase(str);
#elif 1
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };

	a.rotate(nums, 3);
	for (int i = 0; i < 7; i++){
		cout << nums[i] << endl;
	}
#else
	int num = 'a' + 1.6;
	cout << num;
#endif
	return 0;
}