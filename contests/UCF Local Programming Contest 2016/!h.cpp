#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10000005;

int cnt[MAXN];

int cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int T;
    scanf("%d", &T);
    int CASE = 0;
    while (T--)
    {
        memset(cnt, 0, sizeof(cnt));
        int n;
        scanf("%d", &n);
        int MAX = 0;
        for (int i = 1; i <= n; i++)
        {
            int a;
            scanf("%d", &a);
            cnt[a]++;
            MAX = max(MAX, a);
        }
        long long ans = 0;
        ans += (long long)cnt[0] * (n - cnt[0]);
        ans += (long long)cnt[1] * (n - cnt[1] - cnt[0]);
        for (int i = 2; i <= MAX / 2; i++)
        {
            if (!cnt[i]) continue;
            for (int j = i + i; j <= MAX; j += i)
            {
                if (!cnt[j]) continue;
                ans += (long long)cnt[i] * cnt[j];
            }
        }
        cout << "Test case #" << ++CASE << ": " << ans << endl
             << endl;
    }
    return 0;
}