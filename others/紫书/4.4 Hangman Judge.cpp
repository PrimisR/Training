//4-2 Hangman Judge
/* 
#include <stdio.h>
#include <string.h>
#define maxn 100

int left,chance; //����Ҫ��left��λ�ã���chance�λ���
char s[maxn],s2[maxn];
int win,lose;

void guess(char ch)
{
	int bad=1;//Ĭ��bad=1,ֻ��ƥ��ɹ�����ȷ���������ü� 
	for(int i=0;i<strlen(s);i++)
		if(s[i]==ch) {left--;s[i]=' ';bad=0;}//�����в¹��ĵط���Ϊ�ո� 
	if(bad) --chance;
	if(!chance) lose=1;
	if(!left) win=1;
}//guess���ж�������д��һ��Ƚϼ�� 

int main()
{
	int rnd;
	while(scanf("%d%s%s",&rnd,s,s2)==3&&rnd!=-1)
	{
		printf("Round %d\n",rnd);
		win=lose=0;//��ʼ�� 
		left=strlen(s);
		chance=7;
		for(int i=0;i<strlen(s2);i++)
		{
			guess(s2[i]);//һ��һ�����ַ�
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
			p=(p+d+n-1)%n+1//n��ȫ�ֱ�����-1���±�ţ�+1���±�أ�+n��ֹ�为�� 
		}
		while(a[p]==0);//�ߵ���һ����0���֣��ߵ�0���Ʋ��� 
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
			left--;//һ����һ��p1���������Aѡ�е� 
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
#include <string.h>//ʹ��memset 

int readchar() //���ж��ַ�readchar 
{
	for(;;)
	{
		int ch=getchar();
		if(ch!='\n'&&ch!='\r') return ch;
	}
}

int readint(int c)//��ȡһ��cλ���ȵı��� ,����ת��Ϊ10�������� 
{
	int v=0;
	while(c--) v=v*2+readchar()-'0';
	return v; 
}

int code[8][1<<8] //1<<8:2��8�η�
int readcodes()
{
	memset(code,0,sizeof(code));//ÿ�ζ��������
	code[1][0]=readchar(); 
}


































