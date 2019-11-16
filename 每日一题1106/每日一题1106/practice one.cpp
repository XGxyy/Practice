#include <iostream>
#include <string>
using namespace std;

char* Stringchang(char* str1, char* str2){
	int len2 = strlen(str2);
	int tmp[128] = { 0 };
	char* p = str1;
	int i = 0;
	for (int a = 0; a < len2; a++)
	{
		tmp[(int)str2[a]] = 1;
	}
	while (*p)
	{
		if (0 == tmp[(int)*p])
		{
			str1[i++] = *p;
		}
		p++;
	}
	str1[i] = '\0';
	return str1;
}

int main(){
	char str[] = "There are students";
	char src[] = "aeiou";
	char* tmp = Stringchang(str, src);

	cout << tmp << endl;
	return 0;
}