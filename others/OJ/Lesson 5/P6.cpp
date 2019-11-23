#include <stdio.h>

int t;
double n[10];
int count;

int main()
{
	scanf("%d",&t);
	for(int i=0;i<t;i++)
		scanf("%lf",&n[i]);
	for(int i=0;i<t;i++)
	{
		count=0;
		while(n[i]>1.0)
		{
			n[i]=n[i]/2.0;
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
} 
