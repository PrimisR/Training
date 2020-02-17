/**
 * 模拟开门
 * */
#include<iostream>
using namespace std;
const int maxn = 200009;
int main()
{
	long long n;cin>>n;
	int a[maxn],ans;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==0)
		{
			ans=i;
			break;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==1)
		{
			if(i<ans)ans=i;
			break;
		}
	}
	cout<<ans;
}