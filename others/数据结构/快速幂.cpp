#include <cstdio>
#include <iostream>

#define sqr(x) x*x

using namespace std;

typedef long long ll;

ll power2(int n)
{
	if(n==0) return 1;
	return (n&1) ? sqr(power2(n>>1))<<1 : sqr(power2(n>>1));//函数递推 
}

ll power(int base,int index)
{
	int ans=1;
	while(index!=0)
	{
		if(index&1)
			ans*=base;
		index>>=1;//>>=n是操作几位，x>>n是计算出值 
		base=sqr(base);//不断更新值 
	}
	return ans;
}

int main()
{
	ll a;
	cin>>a;
	cout<<power2(a)<<endl;
	ll b,c;
	cin>>b>>c;
	cout<<power(b,c)<<endl;
	return 0; 
}
 
