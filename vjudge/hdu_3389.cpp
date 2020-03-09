#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int T,Case,n,x,ans;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);ans=0;
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&x);
            if (i%6==0||i%6==2||i%6==5) ans^=x;
        }
        if (!ans) printf("Case %d: Bob\n",++Case);
        else printf("Case %d: Alice\n",++Case);
    }
}