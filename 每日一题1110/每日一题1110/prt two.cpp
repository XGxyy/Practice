#include<iostream>
using namespace std;

int main()
{
	int W, H;
	scanf("%d %d", &W, &H);
	int answer = 0;
	if (W % 4 == 0 || H % 4 == 0){
		answer = W * H / 2;
	}
	else if (W % 2 == 0 && H % 2 == 0){
		answer = (W*H / 4 + 1) * 2;
	}
	else{
		answer = W*H / 2 + 1;
	}
	cout << answer << endl;
	return 0;
}