#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int a[100005];
        int b[100005];
        long long int aa[5] = {0};
        long long int bb[5] = {0};
        memset(aa, 0, sizeof(aa));
        memset(bb, 0, sizeof(bb));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 1)
            {
                aa[1] += a[i];
                bb[1] += b[i];
            }
            else if (i % 3 == 2)
            {
                aa[2] += a[i];
                bb[2] += b[i];
            }
            else if (i % 3 == 0)
            {
                aa[3] += a[i];
                bb[3] += b[i];
            }
        }
        //    for(int i=1;i<=3;i++)
        //    {
        //       printf("%lld %lld\n",aa[i],bb[i]);
        //    }

        long long int ans1, ans2, ans3;
        ans3 = aa[1] * bb[1] + aa[3] * bb[2] + aa[2] * bb[3];
        ans1 = aa[2] * bb[1] + aa[1] * bb[2] + aa[3] * bb[3];
        ans2 = aa[3] * bb[1] + aa[2] * bb[2] + aa[1] * bb[3];
        printf("%lld %lld %lld\n", ans1, ans2, ans3);
    }
}