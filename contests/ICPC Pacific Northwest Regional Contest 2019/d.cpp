#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    int cnt = 0;
    while (a > b)
    {
        if (a & 1)
        {
            a++;
            a >>= 1;
            cnt += 2;
        }
        else
        {
            a >>= 1;
            cnt += 1;
        }
    }
    cnt += (b - a);
    cout << cnt << endl;
}