#include <cstdio>
#include <vector>
#include <iostream>
#include <assert.h>
#include <ctime>
#include <algorithm>
using namespace std;

void fill_random_int(vector<int> &v,int cnt)
{
	v.clear();
	for(int i=0;i<cnt;i++)
		v.push_back(rand());
}

vector<int> fill_random_int(int cnt)
{
	vector<int> v;
	for(int i=0;i<cnt;i++)
		v.push_back(rand());
	return v;
}

void test_sort(vector<int> &v)
{
	sort(v.begin(),v.end());
	for(int i=0;i<v.size()-1;i++)
		assert(v[i<=v[i+1]]);//给出错误提示 
}

int main()
{
	srand(time(NULL));
	vector<int> ve;
	int cnt;
	cin>>cnt;
	fill_random_int(ve,cnt);
	test_sort(ve);
	for(auto it=ve.begin();it!=ve.end();it++)
		cout<<(*it)<<endl;
	cout<<endl;	
} 
