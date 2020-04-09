#include <iostream>
using namespace std;
int r,c;
char ans[128],ch;
int sum[32];
int main()
{
	sum[0]=0;
	sum[1]=26;
	int p=26;
	for(int i=2;i<9;++i){
		p*=26;
		sum[i]=sum[i-1]+p;
	}
	while(scanf("%c%d%c%d",&ch,&r,&ch,&c)==4&&(r+c)){
		int i,p;
		for(i=1;sum[i]<c;++i)
			;
		int delta=c-sum[i-1];
		int len=i;
		--delta;
		p=0;
		for(int i=0;i<len;++i)
			ans[i]='A';
		while(delta){
			ans[p++]=delta%26+'A';
			delta/=26;
		}	
		for(int i=len-1;i>=0;--i)
			printf("%c",ans[i]);              
		printf("%d\n",r);
		ch=getchar();
	}
	return 0;	
} 