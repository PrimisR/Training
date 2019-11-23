#include <stdio.h>
#include <memory.h>

int n;
int a[1000000];
int sum;
int result;

int main()
{
	while(~scanf("%d",&n))
{
	memset(a,0,sizeof(a));
	sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=0;i<n;i++)
	{
		sum-=(a[i]*2);
		if(sum<=0)
		{
			result=i+1;
			break;
		}
	}
	printf("%d\n",result);
}
	return 0;
} 
