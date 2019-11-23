#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string,int> cnt;//����ӳ�� 
vector<string> words;//�����洢���е��� 

//��s���б�׼������Сд�����򣬹���ӳ�䣩 
string repr(const string &s)//����һ��string��C++�����ü�const,ΪʲôҪ�����ã� 
{
	string ans=s;
	for(int i=0;i<ans.length();i++)
		ans[i]=tolower(ans[i]);//���Сд
	sort(ans.begin(),ans.end());//�ѵ������������������㹹��ӳ��
	return ans; 
}

int main()
{
	int n=0;
	string s;
	while(cin>>s)
	{
		if(s[0]=='#') break;
		words.push_back(s);
		string r=repr(s);
		if(!cnt.count(r))//��һ����Ҫ��ȷ����ʼֵΪ0 
			cnt[r]=0;
		cnt[r]++;
	}
	vector<string> ans;
	for(int i=0;i<words.size();i++)
		if(cnt[repr(words[i])]==1) ans.push_back(words[i]);//����vector���� 
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<"\n";
	return 0;
}
