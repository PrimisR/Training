#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

set<string> dict;//string ����

int main()
{
	string s,buf;
	while(cin>>s)//�����ж�EOF 
	{
		for(int i=0;i<s.length();i++)//string�ĳ�Ա����s.length( )
			if(isalpha(s[i]))
				s[i]=tolower(s[i]);//����Сд
			else
				s[i]=' ';//�Ѷ�ȡ��һ���ַ����е��ַ����ɿո񣬱��ڶ�ȡ����string
		stringstream ss;
		ss<<s;
		while(ss>>buf)
			dict.insert(buf);//set���Ͽ����Զ�����string�Ѿ������˴���С�ڷ��� 
	}
	for(auto it=dict.begin();it!=dict.end();++it)
		cout<<(*it)<<"\n";
	return 0;
} 
