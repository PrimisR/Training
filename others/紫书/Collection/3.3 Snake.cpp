#include <stdio.h>
#include <string.h>

#define maxn 20

int a[maxn][maxn];
int n;
int x;
int y;//���� 
int tot;//���� 

int main()
{
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	tot=a[x=0][y=n-1]=1;//��ֵ
	while(tot<n*n)//���� 
	//1.�������߽���� 2.��һ������Ϊ0(��ǰ��ʼ����û������)
	{
		while(x+1<n&&!a[x+1][y]) a[++x][y]=++tot;
		//�˴�ʹ����&&������ġ���·������������ʵ��Ƿ��ڴ�
		while(y-1>=0&&!a[x][y-1]) a[x][--y]=++tot;
		//���ж���һ���ٽ��в���
		while(x-1>=0&&!a[x-1][y]) a[--x][y]=++tot;
		while(y+1<n&&!a[x][y+1]) a[x][++y]=++tot; 
	}//�£����ϣ���
	for(x=0;x<n;x++)
	{
		for(y=0;y<n;y++)
			printf("%3d",a[x][y]);
		printf("\n");
	}
	return 0; 
}
