#include <stdio.h>
#include <string.h>
#include <ctype.h>

//3-1 Tex Quotes
/*
int main()
{
	int c,q=1;//��ΪEOF����char,��һ��int��,��int��char 
	while((c=getchar())!=EOF)
	{
		if(c=='"')//��˫���Ÿĳ������ź������� 
			{
				printf("%s",q?"``":"''");//a?b;c a�Ƿ��棿�淵b:���淵c 
				q=!q;//���������űض���һ��Ϊ������ 
			}
		else
			printf("%c",c);
	}
}
*/


//3-2 WERTYU
//�����ַ�������
/* 
char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";//\\ת��
int main()
{
	int i,c;
	while((c=getchar())!=EOF)
	{
		for(i=1;s[i]&&s[i]!=c;i++); //��1��ʼ����������"`" 
		//ÿ��Ѱ��i��Ȼ��i����Ϊ1
		if(s[i]) putchar(s[i-1]); //���������ǰһ�� 
		else putchar(c); //�ո�� 
 	} 
 	return 0;
}
*/
//


//3-3 Palindromes
/* 
//��������
const char* rev="A   3  HIL JM O   2TUVWXYZ1SE Z  8 ";//���пո� 
const char* msg[]={"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};
//[]�洢����ַ��� ָ����ʽ
 
char r(char ch)
{
	if(isalpha(ch)) return rev[ch-'A'];//�ַ�����ֵ
	return rev[ch-'0'+25];//����ǰ26����ĸ,�����1λ��0 
}

int main()
{
	char s[30];
	while(scanf("%s",s)==1){
		int len=strlen(s);
		int p=1,m=1;
		for(int i=0;i<(len+1)/2;i++){
			if(s[i]!=s[len-1-i])	p=0;//������ 
			if(r(s[i])!=s[len-1-i])	m=0;//������ 
		}
		printf("%s -- is %s.\n\n",s,msg[m*2+p]);
		//00-������,01-���ģ�10(2)-����11(3)-����+���� 
} 		//���������˼· 
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
	while(scanf("%d",&n)==1&&n)//n=0������� 
	{
		printf("Game %d:\n",++kase);
		int A=0,B=0;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(;;)//���޶��� 
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
			break;//�������� 
		for(int d=1;d<=9;d++)
		{
			int c1=0,c2=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]==d) c1++;//�ɲ�����д�� c[a[i]]++ ? 
				if(b[i]==d) c2++;
			}
			if(c1<c2)//ȡ��С 
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
	for(int m=1;m<maxn;m++)//ö������Ԫ 
	{
		int x=m,y=m;
		while(x>0)//���λ��ӣ�x=0ȡ������λ
		{
			y+=x%10;//ȡ���һλ 
			x/=10;//�׵����һλ 
		}
		if(ans[y]==0||m<ans[y])
			ans[y]=m;//ȡ��С������Ԫ
	}//������
	scanf("%d",&T);//�������,T����0ֹͣ 
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
//��״��s�ı�ʾ��p�Ƿ��q���ֵ���С��С�߸���ans�� 
int less(const char*s,int p,int q)
{
	int n=strlen(s);
	for(int i=0;i<n;i++)
		if(s[(p+i)%n]!=s[(q+i)%n])//��״����㷨��ȡģ��
			return s[(p+i)%n]<s[(q+i)%n]; //ֱ�ӿ��ԱȽ��ַ���С
	return 0; //��� 
}

int main()
{
	int T;
	char s[maxn];
	scanf("%d",&T);
	while(T--)//��������������� 
	{
		scanf("%s",s);
		int ans=0;
		int n=strlen(s);
		for(int i=1;i<n;i++)
			if(less(s,i,ans)) ans=i;//�ӵڶ�����ʼ 
		for(int i=0;i<n;i++)
			putchar(s[(i+ans)%n]);//�ӵ�ans����ʼ��״���(putchar)
		putchar('\n'); 
	}
	return 0;
}










































