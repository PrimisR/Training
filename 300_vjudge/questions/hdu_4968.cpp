#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int all, av, n, N;
int num[15];
double judge(int x)
{
    if (x < 70)
        return 2;
    if (x < 75)
        return 2.5;
    if (x < 80)
        return 3;
    if (x < 85)
        return 3.5;
    return 4;
}
double mx(int all)
{
    all -= (60 * n);
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++)
    {
        num[i] += 60;
    }
    for (int i = 0; i < n && all; i++)
    {
        int tmp = min(all, 85 - 60);
        all -= tmp;
        num[i] += tmp;
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += judge(num[i]);
    }
    return ans / n;
}
double mi(int all)
{
    all -= (69 * n);
    if (all < 0)
        return 2.0;
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++)
    {
        num[i] += 69;
    }
    for (int i = 0; i < n; i++)
    {
        int tmp = min(all, 100 - 69);
        all -= tmp;
        num[i] += tmp;
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += judge(num[i]);
    }
    return ans / n;
}
int main()
{
    while (~scanf("%d", &N))
    {
        while (N--)
        {
            scanf("%d%d", &av, &n);
            all = av * n;
            double mxx = mx(all), mii = mi(all);
            printf("%.4lf %.4lf\n", mii, mxx);
        }
    }
}