#include <stdio.h>
#include <string.h>
#include <ctype.h>

//3-1 Tex Quotes
/*
int main()
{
	int c,q=1;//因为EOF不是char,是一个int型,用int存char 
	while((c=getchar())!=EOF)
	{
		if(c=='"')//把双引号改成左引号和右引号 
			{
				printf("%s",q?"``":"''");//a?b;c a是否真？真返b:不真返c 
				q=!q;//输入左引号必定下一个为右引号 
			}
		else
			printf("%c",c);
	}
}
*/


//3-2 WERTYU
//构造字符常量表
/* 
char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";//\\转义
int main()
{
	int i,c;
	while((c=getchar())!=EOF)
	{
		for(i=1;s[i]&&s[i]!=c;i++); //从1开始，不可能有"`" 
		//每次寻找i，然后将i重置为1
		if(s[i]) putchar(s[i-1]); //输出常量表前一个 
		else putchar(c); //空格等 
 	} 
 	return 0;
}
*/
//


//3-3 Palindromes
/* 
//常量数组
const char* rev="A   3  HIL JM O   2TUVWXYZ1SE Z  8 ";//含有空格 
const char* msg[]={"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};
//[]存储多个字符串 指针形式
 
char r(char ch)
{
	if(isalpha(ch)) return rev[ch-'A'];//字符返回值
	return rev[ch-'0'+25];//跳过前26个字母,数组第1位是0 
}

int main()
{
	char s[30];
	while(scanf("%s",s)==1){
		int len=strlen(s);
		int p=1,m=1;
		for(int i=0;i<(len+1)/2;i++){
			if(s[i]!=s[len-1-i])	p=0;//不回文 
			if(r(s[i])!=s[len-1-i])	m=0;//不镜像 
		}
		printf("%s -- is %s.\n\n",s,msg[m*2+p]);
		//00-都不是,01-回文，10(2)-镜像，11(3)-镜像+回文 
} 		//二进制输出思路 
	return 0;
}
*/


//3-4 Master-Mind Hints
/*
#define maxn 1010
int main()
{
	int n,a[maxn],b[maxn];
	int kase=0;
	while(scanf("%d",&n)==1&&n)//n=0输入结束 
	{
		printf("Game %d:\n",++kase);
		int A=0,B=0;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(;;)//无限读入 
		{
			A=0;
			B=0;
			for(int i=0;i<n;i++)
			{
				scanf("%d",&b[i]);
				if(a[i]==b[i])
				A++;
			}
			if(b[0]==0)
			break;//跳出条件 
		for(int d=1;d<=9;d++)
		{
			int c1=0,c2=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]==d) c1++;//可不可以写成 c[a[i]]++ ? 
				if(b[i]==d) c2++;
			}
			if(c1<c2)//取最小 
				B+=c1;
			else
				B+=c2;
		}
		printf("(%d,%d)\n",A,B-A);
	}
}
	return 0;
}
*/


//3.5 Digit Generator
/* 
#define maxn 100005

int ans[maxn];

int main()
{
	int T,n;
	memset(ans,0,sizeof(ans));
	for(int m=1;m<maxn;m++)//枚举生成元 
	{
		int x=m,y=m;
		while(x>0)//逐个位相加，x=0取完所有位
		{
			y+=x%10;//取最后一位 
			x/=10;//抛掉最后一位 
		}
		if(ans[y]==0||m<ans[y])
			ans[y]=m;//取最小的生成元
	}//打表结束
	scanf("%d",&T);//输入个数,T减到0停止 
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}
*/


//3.6 Circular Sequence
 
#define maxn 105
//环状串s的表示法p是否比q的字典序小（小者更新ans） 
int less(const char*s,int p,int q)
{
	int n=strlen(s);
	for(int i=0;i<n;i++)
		if(s[(p+i)%n]!=s[(q+i)%n])//环状输出算法（取模）
			return s[(p+i)%n]<s[(q+i)%n]; //直接可以比较字符大小
	return 0; //相等 
}

int main()
{
	int T;
	char s[maxn];
	scanf("%d",&T);
	while(T--)//控制输入个数方法 
	{
		scanf("%s",s);
		int ans=0;
		int n=strlen(s);
		for(int i=1;i<n;i++)
			if(less(s,i,ans)) ans=i;//从第二个开始 
		for(int i=0;i<n;i++)
			putchar(s[(i+ans)%n]);//从第ans个开始环状输出(putchar)
		putchar('\n'); 
	}
	return 0;
}










































