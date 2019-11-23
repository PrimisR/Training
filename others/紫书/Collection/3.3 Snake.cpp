#include <stdio.h>
#include <string.h>

#define maxn 20

int a[maxn][maxn];
int n;
int x;
int y;//坐标 
int tot;//总数 

int main()
{
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	tot=a[x=0][y=n-1]=1;//赋值
	while(tot<n*n)//填数 
	//1.不超过边界格数 2.下一个格子为0(提前初始化，没有填数)
	{
		while(x+1<n&&!a[x+1][y]) a[++x][y]=++tot;
		//此处使用了&&运算符的“短路”，并不会访问到非法内存
		while(y-1>=0&&!a[x][y-1]) a[x][--y]=++tot;
		//现判断下一格再进行操作
		while(x-1>=0&&!a[x-1][y]) a[--x][y]=++tot;
		while(y+1<n&&!a[x][y+1]) a[x][++y]=++tot; 
	}//下，左，上，右
	for(x=0;x<n;x++)
	{
		for(y=0;y<n;y++)
			printf("%3d",a[x][y]);
		printf("\n");
	}
	return 0; 
}
