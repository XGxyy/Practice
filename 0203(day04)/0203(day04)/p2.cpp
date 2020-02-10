#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		/*vector<int> num;
		for (int i = 0; i < m; i++){
			num.push_back(nums1[i]);
		}
		for (int i = 0; i < n; i++){
			num.push_back(nums2[i]);
		}*/
		int flag = m;
		for (int i = 0; i < n; i++){
			nums1[flag] = nums2[i];
			flag++;
		}
		
		int len = m + n;
		for (int i = 0; i < len; i++){
			for (int j = 0; j < len - 1; j++){
				if (nums1[j] > nums1[j + 1]){
					int tmp = nums1[j + 1];
					nums1[j + 1] = nums1[j];
					nums1[j] = tmp;
				}
			}
		}
	}
};

int main(){
	vector<int> nums1 = { 1, 2, 3, 0, 0 ,0};
	vector<int> nums2 = { 2, 5, 6 };

	Solution a;
	a.merge(nums1, 3, nums2, 3);

	return 0;
}