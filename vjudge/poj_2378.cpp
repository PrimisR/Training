#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=10002;
int dp[maxn],sum[maxn],n,flag;
vector<int>p[maxn];
int dfs(int u,int fa)
{
    int  i,j,v,sum=1,mson=0;
    int cnt=p[u].size();
    dp[u]=0;//子孩子
    for(i=0;i<cnt;i++)
    {
        v=p[u][i];
        if(v==fa)continue;
        int ans=dfs(v,u);
        mson=max(mson,ans);//孩子节点中最大孩子数
        sum+=ans;///以u 为根所有孩子数
    }
    dp[u]=max(n-sum,mson);///删除u节点，
    return sum;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,a,b;
        flag=0;
        for(i=1;i<=n;i++)p[i].clear();
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            p[a].push_back(b);
            p[b].push_back(a);
        }
        dfs(1,0);
        for(i=1;i<=n;i++)
        {
            if(2*dp[i]<=n)
            {
                flag=1;
                printf("%d\n",i);
            }
        }
        if(!flag)printf("NONE\n");
    }
    return 0;
}