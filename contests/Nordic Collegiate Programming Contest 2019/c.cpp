/**
 * 最多切3次，整除1次，如果可以切出子巧克力2次，否则切碎3次
 * */
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long long n, m;
    long long a;
    cin >> n >> m >> a;
    if (a % m == 0 || a % n == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    else
    {
        long long b = n * m - a;
        for (long long i = 1; i <= (long long)sqrt(a); i++)
        {
            if (a % i == 0)
            {
                if ((i <= m && a / i <= n) || (i <= n && a / i <= m))
                {
                    cout << 2 << endl;
                    return 0;
                }
            }
        }
        for (long long i = 1; i <= (long long)sqrt(b); i++)
        {
            if (b % i == 0)
            {
                if ((i <= m && b / i <= n) || (i <= n && b / i <= m))
                {
                    cout << 2 << endl;
                    return 0;
                }
            }
        }
        cout << 3 << endl;
        return 0;
    }
}