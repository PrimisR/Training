//4-2 Hangman Judge
/* 
#include <stdio.h>
#include <string.h>
#define maxn 100

int left,chance; //还需要猜left个位置，错chance次会输
char s[maxn],s2[maxn];
int win,lose;

void guess(char ch)
{
	int bad=1;//默认bad=1,只有匹配成功才正确，这样设置简单 
	for(int i=0;i<strlen(s);i++)
		if(s[i]==ch) {left--;s[i]=' ';bad=0;}//把所有猜过的地方变为空格 
	if(bad) --chance;
	if(!chance) lose=1;
	if(!left) win=1;
}//guess的判断条件，写在一起比较简洁 

int main()
{
	int rnd;
	while(scanf("%d%s%s",&rnd,s,s2)==3&&rnd!=-1)
	{
		printf("Round %d\n",rnd);
		win=lose=0;//初始化 
		left=strlen(s);
		chance=7;
		for(int i=0;i<strlen(s2);i++)
		{
			guess(s2[i]);//一个一个猜字符
			if(win||lose) break; 
		}
		if(win) printf("You win.\n");
		else if(lose) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
	return 0;
} 
*/
 
//4-3 The Dole Queue
/*
#include <stdio.h>
#define maxn 25
int n,k,m,a[maxn];

int go(int p,int d,int t)
{
	while(t--)
	{
		do
		{
			p=(p+d+n-1)%n+1//n是全局变量，-1重新编号，+1重新编回，+n防止变负数 
		}
		while(a[p]==0);//走到下一个非0数字，走到0不计步伐 
	}
}

int main()
{
	while(scanf("%d%d%d",&n,&k,&m)==3&&n)
	{
		for(int i=1;i<=n;i++) a[i]=i;
		int left=n;
		int p1=n,p2=1;
		while(left)
		{
			p1=go(p1,1,k);
			p2=go(p2,-1,m);
			printf("%3d",p1);
			left--;//一定少一个p1，先输出被A选中的 
			if(p2!=p1) {printf("%3d",p2); left--;}
			a[p1]=a[p2]=0;
			if(left) printf(","); 
		}
		printf("\n");
	}
	return 0;
}
*/
//4-4 Message Decoding

#include <stdio.h>
#include <string.h>//使用memset 

int readchar() //跨行读字符readchar 
{
	for(;;)
	{
		int ch=getchar();
		if(ch!='\n'&&ch!='\r') return ch;
	}
}

int readint(int c)//读取一个c位长度的编码 ,并且转化为10进制整数 
{
	int v=0;
	while(c--) v=v*2+readchar()-'0';
	return v; 
}

int code[8][1<<8] //1<<8:2的8次方
int readcodes()
{
	memset(code,0,sizeof(code));//每次读清空数组
	code[1][0]=readchar(); 
}


































