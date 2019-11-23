#include <stdio.h>
#include <memory.h>

int n;
int fail;
int a[200001];

int main()
{
	while(~scanf("%d",&n))
{
	memset(a,0,sizeof(a));
	fail=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>2&&a[i]%2==1) a[i]=1;
		if(a[i]>2&&a[i]%2==0) a[i]=2;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==1) a[i+1]--;
		if(a[i]==2) a[i]=0;
		if(a[i]<0) {fail=1; break;}
	}
	if(a[n-1]==1||fail)
		printf("NO\n");
	else
		printf("YES\n");
}
}
