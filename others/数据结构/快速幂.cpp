#include <cstdio>
#include <iostream>

#define sqr(x) x*x

using namespace std;

typedef long long ll;

ll power2(int n)
{
	if(n==0) return 1;
	return (n&1) ? sqr(power2(n>>1))<<1 : sqr(power2(n>>1));//�������� 
}

ll power(int base,int index)
{
	int ans=1;
	while(index!=0)
	{
		if(index&1)
			ans*=base;
		index>>=1;//>>=n�ǲ�����λ��x>>n�Ǽ����ֵ 
		base=sqr(base);//���ϸ���ֵ 
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
 
