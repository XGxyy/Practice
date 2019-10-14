#include <iostream>
#include "list.h"

using namespace std;
int main(){
	G::list<int>l(4, 5);
	for (auto & i : l){
		cout << i <<' ';
	}

		system("pause");
	return 0;
}