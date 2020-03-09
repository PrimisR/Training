#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[2005][2005];

int main()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=2000;i++){
        dp[i][1]=1;
        dp[i][0]=0;
        for(int j=2;j<=2000;j++){
            if(i==j){
                dp[i][j]=1;
                continue;
            }
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j;
            dp[i][j]%=1000;
        }
    }
    int n;
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        int sum=0;
        for(int i=1;i<=x;i++){
            sum+=dp[x][i];
        }
        printf("%d\n",sum%1000);
    }
}