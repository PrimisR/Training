#include <cstdio>
#include <cstring>

const int maxd=20;

int s[1<<maxd]; //2^maxd-1
int main()
{
	int D,I;
/*	while(scanf("%d%d",&D,&I)==2)
	{
		memset(s,0,sizeof(s));//s��ʾ����״̬ 
		int k,n=(1<<D)-1;//nΪ���ڵ��� 
		for(int i=0;i<I;i++)
		{
			k=1; //��ʾ��ǰ�����ڵ�
			for(;;)
			{
				s[k]!=s[k];//�����ȸı�״̬
				k=s[k]?k*2:k*2+1; 
				if(k>n) break; //�Ѿ����� 
			} 
		}
		printf("%d\n",k/2);//��ӡ���һ�εı��(ǰ�������Ǹı�״̬) 
	}
*/
	while(scanf("%d%d",&D,&I)==2)
	{
		int k=1;
		for(int i=1;i<=D;i++) 
			if(I%2){k=k*2; I=(I+1)/2;}
			else {k=k*2+1; I/=2;}
		printf("%d\n",k);
	} 
	return 0;
} 
