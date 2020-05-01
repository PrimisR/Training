#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
#define maxn 20
char str[maxn];
ll k, s9, s, id, s1, s2, t, t1, t2, sum, c;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    scanf("%s%lld", str, &k);
    int len = strlen(str);
    s9 = s1 = s = 0;
    for (int i = 0; i < len; i++)
        if (str[i] == '.')
            id = i;
    for (int i = len - k; i < len; i++)
    {
        s = s * 10 + str[i] - '0';
        s9 = s9 * 10 + 9;
    }
    for (int i = 0; i < len - k; i++)
    {
        if (str[i] != '.')
            s1 = s1 * 10 + str[i] - '0';
    }
    s2 = 1;
    for (int i = id + 1; i < len - k; i++)
        s2 = s2 * 10;
    s9 *= s2;
    t2 = s9 / s2;
    sum = s + s1 * t2;
    c = gcd(sum, s9);
    sum /= c;
    s9 /= c;
    printf("%lld/%lld\n", sum, s9);
    return 0;
}