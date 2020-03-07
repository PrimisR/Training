#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
		int n;
		scanf("%d",&n);
		int i,j=0;
		for(i=0;i<n;i++)
		{
			int s;
			scanf("%d",&s);
			j+=(s+1);
		}
		printf("%d\n",j);
	}
	return 0;
}