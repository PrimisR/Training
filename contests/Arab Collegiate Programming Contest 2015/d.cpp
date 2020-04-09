/**
 * 在求最小公倍数的时候小心爆long long，注意处理！
 * */
#include <cstdio>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        long long g1 = gcd(a1, b1);
        long long g2 = gcd(a2, b2);
        a1 /= g1;
        b1 /= g1;
        a2 /= g2;
        b2 /= g2;
        long long al = lcm(a1, a2);
        long long bg = gcd(b1, b2);
        long long galbg = gcd(al, bg);
        long long bl = lcm(b1, b2);
        long long t1 = bl / b1 * a1;
        long long t2 = bl / b2 * a2;
        long long tg = gcd(t1, t2);
        long long tgg = gcd(tg, bl);
        cout << tg / tgg << "/" << bl / tgg << " ";
        cout << al / galbg << "/" << bg / galbg << endl;
    }
    return 0;
}