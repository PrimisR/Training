#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    int iter = 0;
    while (n != 1)
    {
        n = (n & 1) ? n + 1 : n >> 1;
        iter++;
    }
    cout << iter << endl;
}