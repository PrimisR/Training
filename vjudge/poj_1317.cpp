
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
char dic[]="_abcdefghijklmnopqrstuvwxyz.";
char str[80];
char ans[80];
int main()
{
	int k;
	while(scanf("%d",&k)!=EOF&&k)
	{
		scanf("%s",str);
		int len=strlen(str);
		for(int i=0;i<len;i++)
		{
			int tmp;
			if(str[i]=='_')
				tmp=0;
			else if(str[i]=='.')
				tmp=27;
			else
				tmp=str[i]-'a'+1;
			tmp+=i;
			tmp%=28;
			int t=k*i;
			t%=len;
			ans[t]=dic[tmp];
		}
		ans[len]='\0';
		printf("%s\n",ans);
	}
	return 0;
}