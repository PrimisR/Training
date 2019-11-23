#include <stdio.h>

#define K 3

int m;

int j(int x)
{
	if(x==1) return 0;
	if(x>1&&x<K) return (j(x-1)+K)%x;
	if(x>=K) return K*((j(x-x/K)-(x%K)+(x-x/K))%(x-x/K))/(K-1);
}

int main()
{
	while(~scanf("%d",&m))
{
	printf("%d\n",j(m)+1);
}
}
