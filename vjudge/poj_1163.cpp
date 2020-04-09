#include <cstdio>
#include <iostream>
#include <algorithm>
int dp[105][105];
int n;
using namespace std;
int main()
{
    int i, j;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= i; j++)
            {
                scanf("%d", &dp[i][j]);
            }
        }
        int DP();
        printf("%d\n", DP());
    }
    return 0;
}

int DP()
{
    int i, j;
    for (int i = n - 1; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[1][1];
}