#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int a, b, c, d;
int main()
{
    cin >> a >> b >> c >> d;
    bool flag = 0;
    if (d > min(b, a + c) || d == min(b, a + c) && max(b, a + c) <= 2 * d)
        flag = 1;
    if (flag)
        cout << "YES" << endl;
    else
        cout << " NO" << endl;
    return 0;
}