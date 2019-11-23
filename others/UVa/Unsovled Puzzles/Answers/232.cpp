#include <stdio.h>
#include <memory.h>

char s[11][11];
int mark[10][10];
int c;
int r;
int no;
int identifier;

char sp[1000][10];
int p[1000];
int len[10];
int m;
int n;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	while(scanf("%d",&r)==1&&r)
	{
		if(identifier)
			printf("\n");
		scanf("%d",&c); 
		no=0;
		memset(mark,0,sizeof(mark));
		memset(s,0,sizeof(s));
		getchar();
		for(int i=0;i<r;i++)
			for(int j=0;j<=c;j++)//吃回车
				s[i][j]=getchar();
		for(int i=0;i<c;i++)//第一行 
			if(s[0][i]!='*')
				mark[0][i]=1;
		for(int i=1;i<r;i++)//第一列 
			if(s[i][0]!='*')
				mark[i][0]=1;
		for(int i=1;i<r;i++)
			for(int j=1;j<c;j++)
					if(s[i][j]>='A'&&s[i][j]<='Z'&&(s[i-1][j]=='*'||s[i][j-1]=='*'))
						mark[i][j]=1; 
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(mark[i][j]==1)
					mark[i][j]=++no;
		printf("puzzle #%d:\n",++identifier);
		printf("Across\n");
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(mark[i][j])
				{
					printf("%3d.",mark[i][j]);
					putchar(s[i][j]);
					while(j<r&&s[i][j+1]!='*'&&s[i][j+1]!='\n') 
						putchar(s[i][++j]);
					printf("\n");
				}
		printf("Down\n");//Down输出顺序不正确
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(mark[i][j])
				{
					printf("%3d.",mark[i][j]);
					m=i;
					n=j;
					putchar(s[m][n]);
					while(m<r&&s[m+1][n]!='*'&&s[m+1][n]!=0)
					{
						mark[++m][n]=0;
						putchar(s[m][n]);
					}
					printf("\n");
				}
	}
}
