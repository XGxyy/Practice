#include "BTree.h"

int main(){
	BTNode* root = BinaryTreeCreate("ABD#GI##J###CE#HK###F##");
	BinaryTreePrevOrder(root);
	putchar('\n');
	BinaryTreeInOrder(root);
	putchar('\n');
	BinartTreePrevOrderN(root);
	system("pause");
	return 0;
}