#include <iostream>
#include <string>
using namespace std;

void backstr(string& pStr){
	/*string* pStr.begin = pStr.begin();
	string* pStr.end = pStr.end() - 1;*/  //指向最后一个字符	
	//将整个字符串进行逆置	
	string tmp;	
	while (pStr.begin < pStr.end){	
		tmp = pStr.begin;		
		pStr.begin = pStr.end;		
		pStr.end = tmp;		
		pStr.begin++;		
		pStr.end--;
	}	
	pStr.begin = pStr.begin;
	int count = 0;	
	string* pStart;
	string* pEnd;
	while (pStr.begin != '\0'){	
		if (pStr.begin == ' ') //遇到空格
		{			
			pStart = pStr.begin - count;  //指向单词首位	
			pEnd = pStr.begin - 1;         //指向单词末位
			while (pStart < pEnd){  //逆置每个单词	
				tmp = *pStart;		
				*pStart = *pEnd;		
				*pEnd = tmp;		
				pStart++;			
				pEnd--;			
			}			
			count = 0;  //计数清零	
		}	
		else	
		{		
			++count;  //计数
		}	
		++pStr.begin;	
	} 	//处理最后一个单词	
	pStart = pStr.begin - count;  //指向单词首位
	pEnd = pStr.begin - 1;         //指向单词末位
	while (pStart < pEnd)  //逆置每个单词
	{		tmp = *pStart;		
	*pStart = *pEnd;		
	*pEnd = tmp;	
	++pStart;		
	--pEnd;
	}
}

int main(){
	string str;
	cin >> str;
	backstr(str);
	cout << str << endl;
	return 0;
}