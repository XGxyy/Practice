#include <iostream>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		if (A == B){
			A = 0;// write code here
		}
		return A ^ B;
	}
};

int main(){
	int num1, num2;
	cin >> num1 >> num2;
	UnusualAdd A;
	cout << A.addAB(num1, num2) << endl;
	return 0;
}