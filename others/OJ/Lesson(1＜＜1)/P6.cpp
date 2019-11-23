#include<stdio.h>

int n;
int s;
int factorial=1;

int main()
{
	while(scanf("%d",&n)==1){
	factorial=1;
	s=0;
	for(int i=1;i<=n;i++)
		{
			factorial*=i;
			s+=factorial;
		}
	printf("%d\n",s);}
	return 0;
}
