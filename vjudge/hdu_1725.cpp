#include <iostream>
#include <cstdio>

using namespace std;

long long frac[14]; //13! > 2^32

int main()
{
    frac[0] = 1;
    for (int i = 1; i <= 13; i++)
    {
        frac[i] = frac[i - 1] * i;
    }
    int n;
    cin >> n;
    while (n--)
    {
        long long m;
        cin >> m;
        long long sum = 0;
        for (int i = 13; i >= 1; i--)
        {
            if (m >= frac[i])
            {
                sum += m / frac[i];
                m %= frac[i];
            }
        }
        cout << sum << endl;
    }
}