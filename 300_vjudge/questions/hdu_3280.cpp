#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t, cas, n, a[10005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &cas, &n);
        int sum = 0, ans;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        int s, flag;
        for (int i = 1; i <= sum; i++)
        {
            if (sum % i == 0) //不是约数一定不能
            {
                s = 0, flag = 1;
                for (int j = 1; j <= n; j++) //检验每段和
                {
                    s += a[j];
                    if (s == i)
                        s = 0;
                    if (s > i)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag)
            {
                ans = i;
                break;
            }
        }
        printf("%d %d\n", cas, ans);
    }
    return 0;
}