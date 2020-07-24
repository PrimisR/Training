#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-6;

//[1,r]
long long fun(long long r)
{
    if (r == 0)
        return 0;
    long long q = sqrt(r+eps) , s = 0;
    for (int i = 1; i <= q; i++)
    {
        s += r / i;
    }
    return (s * 2 - q * q);
}

int main()
{
    long long l, r;
    cin >> l >> r;
    cout << fun(r) - fun(l-1) << endl;
}