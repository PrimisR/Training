#include <iostream>
using namespace std;
#define ll long long
#define mem(A, B) memset(A, B, sizeof(A))

const int maxn = 6e6 + 10;
const ll mod = 998244353;
ll inv[maxn], sum[maxn];
int T, n;
int main()
{
    mem(inv, 0);
    inv[0] = 1;
    inv[1] = 1;
    sum[0] = 1, sum[1] = 1;
    for (ll i = 2; i <= maxn; i++)
    {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        sum[i] = sum[i - 1] + inv[i] * inv[i]; // inv[i*i] = inv[i] * inv[i]
        sum[i] %= mod;
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%lld\n", (3 * sum[n] * inv[n]) % mod);
    }
    return 0;
}