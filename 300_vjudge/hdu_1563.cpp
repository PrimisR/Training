#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int i,n,a,ans;
	while(scanf("%d",&n),n)
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);	
			ans=ans^a;
		}
		printf("%d\n",ans);
	}
	return 0;
} 