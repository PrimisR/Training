#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        int l, r;
        cin >> l >> r;
        if (l == 1)
        {
            cout << l << " " << r << endl;
        }
        else if (r < (l << 1))
        {
            cout << -1 << " " << -1 << endl;
        }
        else
        {
            cout << l << " " << (l << 1) << endl;
        }
    }
    return 0;
}