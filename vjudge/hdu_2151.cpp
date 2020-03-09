#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#define LL long long
using namespace std;
int dp[110][110];
int main()
{
    int n,p,m,t;
    while(scanf("%d%d%d%d",&n,&p,&m,&t)>0)
    {
        memset(dp,0,sizeof(dp));
        dp[0][p]=1;
        for(int i=1;i<=m;i++)
        {
            dp[i][1]=dp[i-1][2];
            dp[i][n]=dp[i-1][n-1];
            for(int j=2;j<n;j++)
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
        }
        printf("%d\n",dp[m][t]);
    }
}