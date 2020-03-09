/**
 * 完全背包
 * */
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 125;

int dp[MAXN];

int main()
{
    dp[0] = 1;
    for (int i = 1; i <= MAXN - 1; i++)
    {
        for (int j = i; j <= MAXN - 1; j++)
        {
            dp[j] += dp[j - i];
        }
    }
    int n;
    while (cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}