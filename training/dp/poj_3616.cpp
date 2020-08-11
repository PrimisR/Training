/**
 * 先将所有的时段(itvl)从小到大排序(一级起始时间，二级终止时间)，
 * 然后用dp[i](i为排序之后的序号)表示只考虑1~i时段，并且选中第i时段所能获得的最大效率
 * dp[i]初始值为itvls[i].eff,也就是只选取这一段
 * 之后从dp[1~i-1]更新dp[i](j in (1, i-1))
 * 也就是说，如果选中了第j个，那么j之前的最佳效率为dp[j]
 * 排序后会保证dp[j]前面的最大ed为itvls[j].ed,不会影响时间
 * 最后要选取最大的dp值，因为不一定选最后一个时段
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct itvl
{
    int st;
    int ed;
    int eff;
};

int cmp(itvl a, itvl b)
{
    return (a.st == b.st) ? a.ed < b.ed : a.st < b.st;
}

itvl itvls[1010];
int dp[1010];

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++)
    {
        cin >> itvls[i].st >> itvls[i].ed >> itvls[i].eff;
        itvls[i].ed += r;
    }
    sort(itvls + 1, itvls + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        dp[i] = itvls[i].eff;
        for (int j = 1; j < i; j++)
            if (itvls[j].ed <= itvls[i].st)
                dp[i] = max(dp[i], dp[j] + itvls[i].eff);
    }
    cout << max_element(dp + 1, dp + 1 + m) << endl;
    return 0;
}