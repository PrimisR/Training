/**
 * 给定一个数组v,每次可以取最前面的元素或最后面的元素
 * 第k次取增加价值为v[i]*k，求总价值
 * 设dp[i][j]为
 * 剩余[i,j]长度内所能获得的最大值
 * 所求为dp[1][n]
 * 则有如下转移方程
 * dp[i][j] = max(dp[i+1][j]+a[i]*(n+i-j), dp[i][j-1]+a[j]*(n+i-j))
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[2010][2010];
int a[2010];
int n;

int main()
{

    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            dp[i][i] = a[i] * n;
        }
        for (int i = n - 1; i >= 1; i--)
            for (int j = i + 1; j <= n; j++)
            {
                int k = n + i - j;
                dp[i][j] = max(dp[i + 1][j] + a[i] * k, dp[i][j - 1] + a[j] * k);
            }
        cout << dp[1][n] << endl;
    }
}