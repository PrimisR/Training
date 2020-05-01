#include <iostream>
#include <cstdio>

using namespace std;

long long frac[16];

int main()
{
    frac[0] = 1;
    for (int i = 1; i <= 15; i++)
    {
        frac[i] = frac[i - 1] * i;
    }
    double r = 0;
    int n;
    cin >> n;
    if (n > 15)
        n = 15;
    for (int i = 0; i <= n; i++)
    {
        r += 1.0/frac[i];
    }
    printf("%.12lf\n",r);
}