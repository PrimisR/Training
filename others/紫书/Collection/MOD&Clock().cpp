#include<stdio.h>
#include<time.h>
int main()
{
	const int MOD=1000000;
	int n,S=0;
	scanf("%d",&n);
	if(n>=25)
	{
		n=25;//��ʵ25��������6��0������Ч�ʺ������������� 
	}
	for(int i=1;i<=n;i++)//��ѭ���׳˺� 
	{
		int factorial=1;
		for(int j=1;j<=i;j++)//��ѭ���׳˻� 
		{
			factorial=(factorial*j%MOD);//�Ӻ�֮��˻�����ģģ���� 
		}
		S=(S+factorial)%MOD;//ÿ���ӷ���ģģ���� 
	}
	printf("%d\n",S);
	printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC);
	//clock���� 
	return 0; 
 } 
