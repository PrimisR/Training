#include <stdio.h>
#include <string.h>

void swap(char *a,char *b)
{
	char temp;
	temp=*a; *a=*b; *b=temp;
}

char s[5][6];
char order;
int len;
int x;
int y;
int fail;
int puzzle=1; 

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	while((s[0][0]=getchar())!='Z')//return 0;
{
	if(puzzle>1) printf("\n");
	for(int i=0;i<5;i++)
		for(int j=0;j<=5;j++)
			{
				if(i==0&&j==0) j=1;
				s[i][j]=getchar();
				if(s[i][j]==' ') 	{x=i;	y=j;}
			}
	fail=0;
	while(scanf("%c",&order)&&order!='0')
	{
		if(fail) continue;//继续读但不要作更改，就把剩下的都吃掉 
		if(order=='A')	if(--x>=0) swap(&s[x+1][y],&s[x][y]);
	    if(order=='B')	if(++x<5) swap(&s[x-1][y],&s[x][y]);
		if(order=='R')	if(++y<5) swap(&s[x][y-1],&s[x][y]);
		if(order=='L')	if(--y>=0) swap(&s[x][y+1],&s[x][y]);
		if((order!='A'&&order!='B'&&order!='R'&&order!='L'&&order!='\n'&&order!='0')) fail=1;
		if(x<0||x>=5||y<0||y>=5) fail=1;//要读完(不能break),否则会混入s数组(可以数组读取解决) 
	}
	getchar();//吃换行符 
	if(fail)
	{
		printf("Puzzle #%d:\n",puzzle++);
		printf("This puzzle has no final configuration.\n");
	}
	else
	{
		printf("Puzzle #%d:\n",puzzle++);
		for(int i=0;i<5;i++)
			for(int j=0;j<=5;j++)
			{
				putchar(s[i][j]);
				if(j<4)
					putchar(' ');
			}
	}
}
	return 0;
	//main();
}
