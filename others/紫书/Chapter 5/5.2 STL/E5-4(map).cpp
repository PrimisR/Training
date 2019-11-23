#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string,int> cnt;//构造映射 
vector<string> words;//用来存储所有单词 

//将s进行标准化（变小写，排序，构造映射） 
string repr(const string &s)//返回一个string，C++中引用加const,为什么要用引用？ 
{
	string ans=s;
	for(int i=0;i<ans.length();i++)
		ans[i]=tolower(ans[i]);//变成小写
	sort(ans.begin(),ans.end());//把单词重新排序，这样方便构造映射
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
		if(!cnt.count(r))//不一定必要？确保初始值为0 
			cnt[r]=0;
		cnt[r]++;
	}
	vector<string> ans;
	for(int i=0;i<words.size();i++)
		if(cnt[repr(words[i])]==1) ans.push_back(words[i]);//丢入vector排序 
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<"\n";
	return 0;
}
