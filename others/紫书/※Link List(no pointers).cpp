//链表不一定采用指针实现
#include <cstdio>
#include <cstring>
const int maxn=100000+5;

int last,cur,next[maxn];
char s[maxn]; 

int main()
{
	while(scanf("%s",s+1)==1)//传入s[1]的地址，字符串则从s[1]放入，s[0]为空 
	{
		int n=strlen(s+1);//输入保存在s[1],s[2]中 
		last=cur=0;//光标位于cur号字符的后面,last是最后一个字符的标号 
		next[0]=0;
	//last表示最后一个字符
	//cur表示下一次插入的位置在这个字符之后(标号所对应的字符)
	//next[i]表示该字符的下一个字符标号是next[i] 
		for(int i=1;i<=n;i++)//对于s中的每一个字符，从i到n逐个进行插入 
		{
			char ch=s[i];
			if(ch=='[') cur=0;
			else if(ch==']') cur=last;
			else//cur点是插入的位置，利用链表结构的插入方法 
			{
				next[i]=next[cur];//把cur点的标号赋给i
				next[cur]=i;//把cur指向i
				if(cur==last) last=i;//如果这是最后一个字符，更新最后字符的标号
				//当你插入的这个字符在last之后，那么最后一个字符将变为你插入的字符 
				cur=i;//cur现在位于i后面 
			}
		}
		for(int i=next[0];i!=0;i=next[i]) //next[0]=0的初始值在不断交换中成为末尾的标志
		//last的字符所指向的一直是0
			printf("%c",s[i]);
		printf("\n"); 
	}
}
