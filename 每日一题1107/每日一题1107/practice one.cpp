//#include <iostream>
//#include <string>
//using namespace std;
//
//string findlonggest(const string& str){
//	string tmp;//����һ����ʱ�ַ�����������������ִ�
//	string maxstr;//ֻ���������ִ�
//	int maxlength = 0;
//
//	for (int i = 0; i < str.length(); i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			while (str[i] >= '0' && str[i] <= '9')
//			{
//				tmp += str[i++];
//			}
//			if (tmp.size()>maxlength)
//			{
//				maxstr = tmp;
//				maxlength = tmp.size();
//			}
//		}
//		tmp.clear();
//	}
//	return maxstr;
//	
//}
//
//int main1(){
//	string str;
//	cin >> str;
//	cout << findlonggest(str) << endl;
//	return 0;
//}