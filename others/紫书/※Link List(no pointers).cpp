//����һ������ָ��ʵ��
#include <cstdio>
#include <cstring>
const int maxn=100000+5;

int last,cur,next[maxn];
char s[maxn]; 

int main()
{
	while(scanf("%s",s+1)==1)//����s[1]�ĵ�ַ���ַ������s[1]���룬s[0]Ϊ�� 
	{
		int n=strlen(s+1);//���뱣����s[1],s[2]�� 
		last=cur=0;//���λ��cur���ַ��ĺ���,last�����һ���ַ��ı�� 
		next[0]=0;
	//last��ʾ���һ���ַ�
	//cur��ʾ��һ�β����λ��������ַ�֮��(�������Ӧ���ַ�)
	//next[i]��ʾ���ַ�����һ���ַ������next[i] 
		for(int i=1;i<=n;i++)//����s�е�ÿһ���ַ�����i��n������в��� 
		{
			char ch=s[i];
			if(ch=='[') cur=0;
			else if(ch==']') cur=last;
			else//cur���ǲ����λ�ã���������ṹ�Ĳ��뷽�� 
			{
				next[i]=next[cur];//��cur��ı�Ÿ���i
				next[cur]=i;//��curָ��i
				if(cur==last) last=i;//����������һ���ַ�����������ַ��ı��
				//������������ַ���last֮����ô���һ���ַ�����Ϊ�������ַ� 
				cur=i;//cur����λ��i���� 
			}
		}
		for(int i=next[0];i!=0;i=next[i]) //next[0]=0�ĳ�ʼֵ�ڲ��Ͻ����г�Ϊĩβ�ı�־
		//last���ַ���ָ���һֱ��0
			printf("%c",s[i]);
		printf("\n"); 
	}
}
