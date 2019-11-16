#include <iostream>
#include <vector>
using namespace std;

int main(){
	int num = 0;
	cin >> num;
	vector<int> arr(num);
	int Max = arr[0];
	int sum = 0;
	for (int i = 0; i < num; i++){
		cin >> arr[i];
	}
	for (int j = 0; j < num; j++){
		sum += arr[j];
		if (sum > Max){
			Max = sum;
		}
		else{
			sum = 0;
		}
	}
	cout << Max << endl;
	return 0;
}
