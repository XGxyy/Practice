#include <iostream>

using namespace std;

int main1(){
	int num1, num2;
	cin >> num1 >> num2;

	if (num1 > num2){
		int tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
	
	int i = num1;
	while (1){
		if (i % num1 == 0 && i % num2 == 0){
			break;
		}
		i++;
	}

	cout << i << endl;
	return 0;
}