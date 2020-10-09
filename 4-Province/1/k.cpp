#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    long long h,r;
    cin >> h >> r;
    cout << r * r * (r * 4 + h * 3);
    return 0;
}