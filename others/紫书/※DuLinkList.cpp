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
//在两个节点中建立Link,把地址为L和R的节点左右相连 

int main()
{
	int m,n,kase=0;
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=1;i<=n;i++)
		{
			left[i]=i-1;
			right[i]=(i+1)%(n+1);//最后一个right[n]赋值为0 
		}
		right[0]=1; left[0]=n; //头盒子，将整个盒子成环，右侧为1，左侧为n
		//(头的不同侧向头/尾插入) 
		int op,X,Y,inv=0;
//---------------双向链表构建完成--------------// 
		while(m--)
		{
			scanf("%d",&op);
			if(op==4) inv=!inv; 
			//op 4操作过于麻烦，则标记这个操作，剩下的操作要考虑这个标记 
			else//注意每一步操作的顺序 
			{
				scanf("%d%d",&X,&Y);
				if(op==3&&right[Y]==X) swap(X,Y);//op 3和 inv 无关
				//这里的swap可以在之后把两种情况统一 
				if(op!=3&&inv) op=3-op; //如果链被反转，原来放在左边的放在右边(op12互换)
				if(op==1&&X==left[Y]) continue;//如果已经位于其左侧，读取下一个(顺序在op变换之后)
				if(op==2&&X==right[Y]) continue;
//---------------读入op结束--------------------// 
				int LX=left[X],RX=right[X],LY=left[Y],RY=right[Y];
				//因为会用更改前的数值，所以要先用变量保存起来
				if(op==1)
				{
					link(LX,RX);//把x拿出去，把x左右连起来
					link(LY,X);//把Y的左侧和X连接起来
					link(X,Y);//把X,Y相连	
				}
				else if(op==2)
				{
					link(LX,RX);
					link(Y,X);
					link(X,RY); 
				}
				else if(op==3)
				{
				//相邻的情况要分类讨论
				//相邻:X在Y右侧或Y在X右侧，上面操作已经统一，保证左侧者在左边 
					if(right[X]==Y)
					{
						link(LX,Y);
						link(Y,X);
						link(X,RY);
					}
				//相邻的情况如果正常连会错连 
				//如果不相邻正常连接 
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
//-----------------操作完成-----------------// 
		int b=0;
		long long ans=0;
		for(int i=1;i<=n;i++)//i表示访问次数，把奇数次相加
		{
			b=right[b];//每次更新b,b也是第i个地址对应的值 
			if(i%2==1) ans+=b; 
		}
		if(inv&&n%2==0) ans=(long long)n*(n+1)/2-ans;
		printf("Case %d: %lld\n",++kase,ans);
	}
}

