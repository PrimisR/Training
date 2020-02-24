/**
 * dp[i][j] i 整片片数 j 半片片数 dp 方案数字
 * 卡特兰数有关
 * dp[i][j] = dp[i-1][j+1] + dp[i][j-1]
 * */
#include <iostream>
#include <cstdio>

using namespace std;

long long dp[31][31];

long long dfs(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == 0)
        return dp[i][j] = 1;
    if (j == 0)
        return dp[i][j] = dfs(i - 1, 1);
    return dp[i][j] = dfs(i - 1, j + 1) + dfs(i, j - 1);
}

int main()
{
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 31; j++)
            dp[i][j] = -1;
    dfs(30, 0);
    int n;
    while(cin>>n && n) {
        cout << dp[n][0] << endl;
    }
}