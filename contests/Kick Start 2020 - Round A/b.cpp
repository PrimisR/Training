#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int K = 35;
const int P = 1505;
const int N = 55;
const int inf = 0x3f3f3f3f;
const bool DEBUG = false;

int dp[N][P];
int plate[N][K];  //1-indexation
int splate[N][K]; //1-indexation,sum

void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            splate[i][j] = 0;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    int CASE = 0;
    while (T--)
    {
        int n, k, p;
        cin >> n >> k >> p;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                cin >> plate[i][j];
                splate[i][j] = splate[i][j - 1] + plate[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= p; j++)
            {
                int upper = min(j, k);
                dp[i][j] = -inf;
                for (int x = 0; x <= upper; x++)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + splate[i][x]);
                }
            }
        }
        if (DEBUG)
        {
            for (int i = 1; i <= k; i++)
            {
                for (int j = 1; j <= p; j++)
                {
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }
        }

        cout << "Case #" << ++CASE << ": " << dp[n][p] << endl;
    }
    return 0;
}