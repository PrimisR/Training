#include<stdio.h>
#include<math.h>
int main()
{
	for(int a=1;a<=9;a++)
		for(int b=0;b<=9;b++)//注意a,b定义在内部 
		{
			int n=a*1100+b*11;//n可以现定义 
			int m=floor(sqrt(n)+0.5);//考虑误差 ，floor向下取整
			//利用int,其他没问题，但不保险 
			if(m*m==n)
				printf("%d\n",n); 
		}
	return 0;
 } 
