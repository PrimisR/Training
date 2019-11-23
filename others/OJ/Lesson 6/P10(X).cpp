#include <stdio.h>

int total;
int r_lim;
int c_lim;
int chess;
int combination;
int factorial_1;
int factorial_2; 

int main()
{
	while(~scanf("%d %d %d",&r_lim,&c_lim,&chess))
{
	total=1;
	factorial_1=1;
	factorial_2=1;
	for(int i=0;i<chess;i++)
		total*=(c_lim-i);
	for(int i=1;i<=chess;i++)
	{
		factorial_1*=(r_lim+1-i);
		factorial_2*=i;
	}
	combination=factorial_1/factorial_2;
	printf("%d\n",combination*total);
}
	return 0;
}
