#include<stdio.h>
#include<time.h>
int main()
{
	const int MOD=1000000;
	int n,S=0;
	scanf("%d",&n);
	if(n>=25)
	{
		n=25;//其实25！后面有6个0，所以效率和溢出都将被解决 
	}
	for(int i=1;i<=n;i++)//外循环阶乘和 
	{
		int factorial=1;
		for(int j=1;j<=i;j++)//内循环阶乘积 
		{
			factorial=(factorial*j%MOD);//加号之间乘积内求模模不变 
		}
		S=(S+factorial)%MOD;//每步加法求模模不变 
	}
	printf("%d\n",S);
	printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC);
	//clock函数 
	return 0; 
 } 
