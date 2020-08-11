/**
 * 记忆化搜索
 * 记录搜索过程中从每个平台左端和右端掉落下后落地所用的最短时间
 * dfs搜索返回从(x,y)处掉落到第i个平台上后到落地(y=0)所用的最短时间
 * */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;

struct pf
{
    int l;
    int r;
    int h;
    pf() {}
    pf(int l, int r, int h) : l(l), r(r), h(h) {}
};

int cmp(pf pfa, pf pfb)
{
    return pfa.h > pfb.h;
}

pf p[1010];
int dpl[1010]; //从第i块平台左端点落地所需最短时间
int dpr[1010]; //从第i块平台右端点落地所需最短时间
int n, stx, sty, mx;

bool fallable(int x, int y, int i) // 从x, y座标处能否掉落到第i平台上
{
    return p[i].h <= y && y - p[i].h <= mx && x >= p[i].l && x <= p[i].r;
}

int dfs(int x, int y, int cur)
{
    if (dpl[cur] != inf && dpr[cur] != inf && fallable(x, y, cur))
        return y - p[cur].h + min(dpl[cur] + x - p[cur].l, dpr[cur] + p[cur].r - x); // 返回记忆化搜索的值
    for (int i = cur; i <= n; i++)
    {
        int l = p[i].l;
        int r = p[i].r;
        int h = p[i].h;
        if (fallable(x, y, i))
        {
            if (h == 0)
                return y - h;
            int left = dfs(l, h, i + 1);
            dpl[i] = min(dpl[i], left); // 从左侧掉落到落地的时间最小值
            int right = dfs(r, h, i + 1);
            dpr[i] = min(dpr[i], right); // 从右侧掉落到落地的时间最小值
            return y - h + min(dpl[i] + x - l, dpr[i] + r - x);
        }
    }
    return inf;
}

int main()
{
    int t;
    cin >> t;
    for (int loop = 1; loop <= t; loop++)
    {
        cin >> n >> stx >> sty >> mx;
        for (int i = 1; i <= n; i++)
            cin >> p[i].l >> p[i].r >> p[i].h;
        p[0] = pf(-inf, inf, 0);
        sort(p, p + n + 1, cmp); // 对高度排序，掉落到达的平台一定比现在的平台要低
        for (int i = 0; i <= n; i++)
            dpl[i] = dpr[i] = inf;
        int st = -1, new_sty = -1;
        for (int i = 0; i <= n; i++)
            if (fallable(stx, sty, i)) // 寻找刚开始掉落的平台
            {
                st = i;
                new_sty = p[i].h;
                break;
            }
        cout << dfs(stx, new_sty, st) + (sty - new_sty) << endl;
    }
    return 0;
}