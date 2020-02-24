#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 21;

long long c(long long n, long long k)
{
    if (k == 0)
        return 1;
    long long ans = 1;
    if (k > n - k)
        k = n - k;
    for (int i = n; i >= n - k + 1; i--)
    {
        ans *= i;
        ans /= (n - i + 1);
    }
    return ans;
}

long long dp[MAXN][2]; //0是高低开头，1是低高开头
long long ans[MAXN];

int main()
{
    //初始值
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    ans[1] = 1;
    //计算答案
    for (int n = 2; n <= MAXN; n++)
    {
        ans[n] = 0;
        dp[n][0] = 0;
        dp[n][1] = 0;
        //枚举位置
        for (int p = 1; p <= n; p++)
        {
            long long upd = 0;
            if (p - 1 & 1)
            {
                upd = dp[p - 1][1] * dp[n - p][1] * c(n - 1, p - 1);
                dp[n][1] += upd;
                ans[n] += upd;
            }
            else
            {
                upd = dp[p - 1][0] * dp[n - p][1] * c(n - 1, p - 1);
                dp[n][0] += upd;
                ans[n] += upd;
            }
        }
    }
    int T;
    cin >> T;
    while (T--)
    {
        int D, n;
        cin >> D >> n;
        cout << D << " " << ans[n] << endl;
    }
    return 0;
}