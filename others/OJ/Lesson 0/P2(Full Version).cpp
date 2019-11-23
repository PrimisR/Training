#include<stdio.h>
int main()
{
	int amount,i,half,j1,k1,s1,s2,p;
	int k2,j2,s3,s4,item,total,core;
	char sign;
	while(scanf("%d %c",&amount,&sign)==2)
{
	i=3; 
	half=(amount-1)/2;
	do
	{
		half=half-i;
		i+=2;
	}
	while(half>=0);
	core=i-4;
	for(j1=1;j1<=(core+1)/2;j1++)
	{
		for(s1=1;s1<j1;s1++)
		{
			printf(" ");
		}
		for(k1=core-2*(j1-1);k1>0;k1--)
		{
			printf("%c",sign);
		}
		for(s2=1;s2<j1;s2++)
		{
			printf(" ");
		}
		if(s2==(core+1)/2)
		{
		break;
		}
	printf("\n");
	}
	printf("\n");
	for(j2=1;j2<(core+1)/2;j2++)
	{
		for(s3=core-2*(j2+1);s3>0;s3-=2)
		{
			printf(" ");
		}
		for(k2=1;k2<=2*j2+1;k2++)
		{
			printf("%c",sign);
		}
		for(s4=core-2*(j2+1);s4>0;s4-=2)
		{
			printf(" ");
		}
	printf("\n");
	}
	item=(core-1)/2+1;
	total=(core+1)*item-1;
	printf("%d\n",amount-total);
}
	return 0;
 } 
