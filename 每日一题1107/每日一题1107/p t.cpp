#include <iostream>
#include <string>
using namespace std;

void backstr(string& pStr){
	/*string* pStr.begin = pStr.begin();
	string* pStr.end = pStr.end() - 1;*/  //ָ�����һ���ַ�	
	//�������ַ�����������	
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
		if (pStr.begin == ' ') //�����ո�
		{			
			pStart = pStr.begin - count;  //ָ�򵥴���λ	
			pEnd = pStr.begin - 1;         //ָ�򵥴�ĩλ
			while (pStart < pEnd){  //����ÿ������	
				tmp = *pStart;		
				*pStart = *pEnd;		
				*pEnd = tmp;		
				pStart++;			
				pEnd--;			
			}			
			count = 0;  //��������	
		}	
		else	
		{		
			++count;  //����
		}	
		++pStr.begin;	
	} 	//�������һ������	
	pStart = pStr.begin - count;  //ָ�򵥴���λ
	pEnd = pStr.begin - 1;         //ָ�򵥴�ĩλ
	while (pStart < pEnd)  //����ÿ������
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