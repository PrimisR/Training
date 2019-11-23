#include<stdio.h>
int main()
{
	int n,rem,i;
	while(scanf("%d",&n)==1)
{
	int sta[10]={0};
	while(n>0)
	{
		rem=n%10;
 		for(i=0;i<=9;i++)
 		{
 			if(rem==i)
 			{
 				sta[i]++;
			 }
		 }
		n=n/10;		
	}
	for(i=0;i<=9;i++)
	{
		if(sta[i]!=0)
		{
		printf("%d:%d\n",i,sta[i]);
		}
	}
}
	return 0;
 } 
