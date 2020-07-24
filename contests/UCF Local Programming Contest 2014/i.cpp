#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 600;

int main()
{
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        int n, p[maxn] = {};
        int dp[maxn][maxn] = {}; //dp[i][j] i - 选择次数 j - 物品
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = 0;
        }
        dp[1][1] = p[1];
        for (int j = 2; j <= n; j++)
        {
            for (int i = 1; i <= j / 2; i++)
            {
                int upper = (j - 1 == 1) ? 1 : (j - 1) / 2;
                dp[i][j] = max(dp[min(i, upper)][j - 1], dp[min(i - 1, upper)][j - 1] + p[j]);
            }
        }
        // for (int i = 0; i <= n / 2; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << "Spree #" << loop << ": " << dp[(n == 1) ? 1 : n / 2][n] << endl;
    }
}