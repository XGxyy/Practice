#include <iostream>
#include <vector>
using namespace std;

int main1()
{
	int A, B, C;
	vector<int> v;
	int n;
	while (cin >> n){
		v.push_back(n);
	}
	A = (v[0] + v[2]) / 2;
	B = (v[1] + v[3]) / 2;
	C = v[3] - B;
	if ((A - B == v[0]) && (B - C == v[1]) && (A + B == v[2]) && (B + C == v[3])){
		cout << A << " " << B << " " << C << endl;
	}
	else{
		cout << " No " << endl;
	}
	return 0;
}
