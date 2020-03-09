/**
 * 连续选长为x的边和长为y的边组合，就是 (1+...+m)*(1+...+n)
 * */
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;int sum1,sum2;
		scanf("%d%d",&x,&y);
			
			sum1=x*(1+x)*1/2;
			sum2=y*(1+y)*1/2;
			printf("%d\n",sum1*sum2);
	}
}