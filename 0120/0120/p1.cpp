#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0, j = 0;
		for (i = 0; i < nums.size(); i++){
			if (nums[i] != val){
				nums[j] = nums[i];
				j++;
			}
		}
		return j;
	}

	int searchInsert(vector<int>& nums, int target) {
		int len = nums.size();
		int tmp = 0;
		//1 3 5 6     7
		for (int i = 0; i < len; i++){
			if (nums[len - 1] < target){
				tmp = len;
				break;
			}
			if (nums[i] == target){
				tmp = i;
				break;
			}
			else if (nums[i] > target){
				if (i == 0){
					tmp = 0;
					break;
				}
				else if (nums[i - 1] < target){
					tmp = i;
					break;
				}
			}
		}
		return tmp;
	}
};

int main2(){
	//Solution a;

	vector<int> nums = { 1, 3, 5, 6 };

#if 0	
	cout << a.removeElement(nums, 3);
#elif 0
	cout << a.searchInsert(nums, 5);
#else
	int i = 0, a = 0;
	while (i < 20){
		for (;;){
			if ((i % 10) == 0)
				break;
			else 
				i--;

		}
		i += 11;
		a += i;//
	}
#endif
	cout << a;
	return 0;
}