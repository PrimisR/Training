/**
 * 1~n 个点，i 到 i+1 中间有一条长度为1的路(i in 1~(n-1))
 * 向这个图加了三条长度为1的边
 * 求几对结点间的最短距离
 * 思路:如果没有所给的六个点，最短距离就是直接距离，
 * 否则可以利用floyd先求出这六个点两两之间的最短路，然后再两两枚举这六个点求最短路即可
 * 
 * 注意long long 和 输入
 * */
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const int mod = 1000000007;

long long id[6];
long long dist[6][6];

int n, m;

void init()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            dist[i][j] = abs(id[i] - id[j]);
        }
    }
    dist[0][1] = dist[1][0] = dist[2][3] = dist[3][2] = dist[4][5] = dist[5][4] = 1;
}

void F()
{
    for (int k = 0; k < 6; k++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i < 6; i++)
        {
            cin >> id[i];
        }
        init();
        F();
        long long sum = 0;
        for (int q = 1; q <= m; q++)
        {
            int st, ed;
            cin >> st >> ed;
            long long ans = abs(st-ed);
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    ans = min(ans, abs(st - id[i]) + dist[i][j] + abs(ed - id[j]));
                }
            }
            sum = (sum+q*ans)%mod;
        }
        cout << sum << endl;
    }
    return 0;
}