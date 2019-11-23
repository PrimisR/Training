#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

set<string> dict;//string 集合

int main()
{
	string s,buf;
	while(cin>>s)//可以判断EOF 
	{
		for(int i=0;i<s.length();i++)//string的成员函数s.length( )
			if(isalpha(s[i]))
				s[i]=tolower(s[i]);//化成小写
			else
				s[i]=' ';//把读取的一个字符串中的字符化成空格，便于读取单词string
		stringstream ss;
		ss<<s;
		while(ss>>buf)
			dict.insert(buf);//set集合可以自动排序，string已经定义了大于小于符号 
	}
	for(auto it=dict.begin();it!=dict.end();++it)
		cout<<(*it)<<"\n";
	return 0;
} 
