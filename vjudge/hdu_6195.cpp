#include<stdio.h>
typedef long long LL;
 
int main()
{
	LL m,k,ans;
	while(~scanf("%lld%lld",&m,&k))
	{
		ans=(m-k+1)*k;
		printf("%lld\n",ans);
	}
	return 0;
}