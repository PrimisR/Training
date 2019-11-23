#include<stdio.h>
int main()
{
	int n1,count=0;
	scanf("%d",&n1);
	long long n=n1; //使用long long类型 
	while(n>1)
	{
		if(n%2==1)
			{
			n=3*n+1;
			}
		else
			n=n/2; 
	count++;
	}
	printf("%d\n",count);
	return 0;
 } 
