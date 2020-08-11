#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const long long e14 = 100000000000000;

long long a[100005];
long long b[100005];

int main()
{
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        int n;
        cin >> n;
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        b[0] = inf;
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            b[i] = min(b[i], b[i - 1]);
        }
        long long ans_hi = 0, ans_lo = a[1] * b[1];
        int l = 1, r = 1;
        while (r <= n)
        {
            while (r <= n && a[r] <= a[l])
                r++;
            if (r == n + 1)
                break;
            ans_lo += b[r] * (a[r] - a[l]);
            ans_hi += ans_lo / e14;
            ans_lo %= e14;
            l = r;
        }
        cout << "Case #" << loop << ": " << b[1] << " ";
        if (ans_hi != 0)
            printf("%lld%014lld\n",ans_hi,ans_lo);
        else
            printf("%lld\n",ans_lo);
    }
    return 0;
}