#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 310;
int dp[MAXN];
int sqr[18];

int main()
{
    for (int i = 1; i <= 17; i++)
        sqr[i] = i * i;
    dp[0] = 1;
    for (int i = 1; i <= 17; i++)
    {
        for (int v = sqr[i]; v <= MAXN; v++)
        {
            dp[v] += dp[v - sqr[i]];
        }
    }
    int n;
    while (cin >> n && n)
    {
        cout << dp[n] << endl;
    }
}