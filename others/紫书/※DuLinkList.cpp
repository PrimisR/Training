#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int right[100005];
int left[1000005];

void link(int L,int R)
{
	right[L]=R; left[R]=L;
}
//�������ڵ��н���Link,�ѵ�ַΪL��R�Ľڵ��������� 

int main()
{
	int m,n,kase=0;
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=1;i<=n;i++)
		{
			left[i]=i-1;
			right[i]=(i+1)%(n+1);//���һ��right[n]��ֵΪ0 
		}
		right[0]=1; left[0]=n; //ͷ���ӣ����������ӳɻ����Ҳ�Ϊ1�����Ϊn
		//(ͷ�Ĳ�ͬ����ͷ/β����) 
		int op,X,Y,inv=0;
//---------------˫�����������--------------// 
		while(m--)
		{
			scanf("%d",&op);
			if(op==4) inv=!inv; 
			//op 4���������鷳���������������ʣ�µĲ���Ҫ���������� 
			else//ע��ÿһ��������˳�� 
			{
				scanf("%d%d",&X,&Y);
				if(op==3&&right[Y]==X) swap(X,Y);//op 3�� inv �޹�
				//�����swap������֮����������ͳһ 
				if(op!=3&&inv) op=3-op; //���������ת��ԭ��������ߵķ����ұ�(op12����)
				if(op==1&&X==left[Y]) continue;//����Ѿ�λ������࣬��ȡ��һ��(˳����op�任֮��)
				if(op==2&&X==right[Y]) continue;
//---------------����op����--------------------// 
				int LX=left[X],RX=right[X],LY=left[Y],RY=right[Y];
				//��Ϊ���ø���ǰ����ֵ������Ҫ���ñ�����������
				if(op==1)
				{
					link(LX,RX);//��x�ó�ȥ����x����������
					link(LY,X);//��Y������X��������
					link(X,Y);//��X,Y����	
				}
				else if(op==2)
				{
					link(LX,RX);
					link(Y,X);
					link(X,RY); 
				}
				else if(op==3)
				{
				//���ڵ����Ҫ��������
				//����:X��Y�Ҳ��Y��X�Ҳ࣬��������Ѿ�ͳһ����֤���������� 
					if(right[X]==Y)
					{
						link(LX,Y);
						link(Y,X);
						link(X,RY);
					}
				//���ڵ������������������ 
				//����������������� 
				else
					{
						link(LX,Y);
						link(Y,RX);
						link(LY,X);
						link(X,RY);
					}
				}
			}
		}
//-----------------�������-----------------// 
		int b=0;
		long long ans=0;
		for(int i=1;i<=n;i++)//i��ʾ���ʴ����������������
		{
			b=right[b];//ÿ�θ���b,bҲ�ǵ�i����ַ��Ӧ��ֵ 
			if(i%2==1) ans+=b; 
		}
		if(inv&&n%2==0) ans=(long long)n*(n+1)/2-ans;
		printf("Case %d: %lld\n",++kase,ans);
	}
}

