#include<stdio.h>
int main()
{
	int n,s=0,factorial=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		{
			factorial*=i;
			s+=factorial;
		}
	printf("%d",s%100000);//��ģȡ����λ 
	return 0;
}
