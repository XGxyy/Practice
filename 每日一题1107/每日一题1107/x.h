#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		qsort(numbers);
		int len = numbers.size;
		int count = 0;
		int Hnum = 0;
		for (int i = 0; i < len; i++){
			int tmp = 0;
			for (int j = i; j < len - 1; j++){
				int res = numbers[j];
				if (res == numbers[j + 1]){
					if (count < tmp){
						Hnum = numbers[j];
					}
					tmp++;
				}
				else{

					tmp = count;
					tmp = 0;
				}
			}
		}
		int n = len / 2;
		if (count < n){
			return 0;
		}
		else{
			return Hnum;
		}
	}
};