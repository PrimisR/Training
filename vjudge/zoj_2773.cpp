#include<cstdio>
const int MAXN=302;
int T[MAXN]={0} , w[MAXN]={0};
int main()
{
	for(int i=1;i<MAXN;i++)
	{
		T[i]= (i+1)*i;
		T[i]>>=1;
	}
	for(int k=1;k<MAXN;k++)
	{
		w[k]=w[k-1]+ k * T[k+1];
	}
	int N;
	scanf("%d",&N);
	for(int ri=1;ri<=N;ri++)
	{
		int n;
		scanf("%d",&n);
		printf("%d %d %d\n",ri,n,w[n]);
	}
	return 0;
}