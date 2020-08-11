#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(A, B) memset(A, B, sizeof(A))

const ll mod = 998244353;
int T;
ll n;
ll k = 499122177;

ll fpm(ll x, ll power)
{
    ll ans = 1;
    for (; power; power >>= 1, (x *= x) %= mod)
        if (power & 1)
            (ans *= x) %= mod;
    return ans;
}
int main()
{
    scanf("%d", &T);
    k *= 3;
    k %= mod;
    while (T--)
    {
        scanf("%lld", &n);
        ll cur = fpm(2, n), ans;
        ans = fpm(k, n);
        ans *= 2;

        printf("%lld\n", (cur + 1 + ans) % mod);
    }
    return 0;
}