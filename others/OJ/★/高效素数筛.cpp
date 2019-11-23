#include <stdio.h>
#include <math.h>

#define N 1000001

int m;
int prime[N];

int main()
{
	while(~scanf("%d",&m))
{	prime[2]=1;
	for(int i=3;i<N;i++)
	{
		prime[i++]=1;
		prime[i]=0;
	}
	for(int i=3;i<N;i+=2)
	{
		if(prime[i])
			for(int j=i+i;j<N;j+=i)
				prime[j]=0;
	}
	for(int i=2;i<=m;i++)
	{
		if(prime[i])
			printf("%d ",i);
	}
	printf("\n");
}
	return 0;
}
