#include <stdio.h>

//2.1
/*int a;
int b;
int c;

int main()
{
	for(a=1;a<=9;a++)
		for(b=0;b<=9;b++)
			for(c=0;c<=9;c++)
				{if(100*a+10*b+c==a*a*a+b*b*b+c*c*c)
					printf("%d\n",100*a+10*b+c);}
	return 0;
} */


//2.4
/*

int n;
int m;
int no; 
float sum;

int main()
{
	no=1;
	while((scanf("%d %d",&n,&m)==2)&&(n||m))//判断n,m是否同时为0
	{
		sum=0.0;
		for(int i=n;i<=m;i++)
			sum+=(1.0/((float)i*(float)i));
		printf("Case %d : %.5f\n",no++,sum);
	}
} 
*/
//2.2
//--------------------------//
/*韩信点兵 1.可以枚举(10到100) 2.采用算法 
合并条件：*/
//--------------------------//
/* 
int a;
int b;
int c;
int m;

int main()
{
	while(scanf("%d %d %d",&a,&b,&c))
	{
		m=(a*70+b*21+c*15)%105;
		if(m>=10&&m<=100)
			printf("%d\n",m);
		else
			printf("No answer\n");
	}
} 
*/ 

//2.5
/*
int main()
{
	int a,b,c;
	int p1,p2;
	int r; 
	int kase=1;
	while(scanf("%d %d %d",&a,&b,&c)==3&&a&&b&&c)
	{
		p1=a/b;
		r=a-p1*b;
		printf("Case %d:%d.",kase,p1);
		for(int i=1;i<=c;i++)
		{
			p2=10*r/b;
			r=10*r-p2*b;
			if(i==c&&(10*r/b)>=5)
				p2++;
			printf("%d",p2);
			if(i==c)
				printf("\n");
		}
	}
	return 0;
} 
*/


