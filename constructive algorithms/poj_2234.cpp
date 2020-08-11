#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int m;
    while (cin >> m)
    {
        int s = 0;
        int a;
        for (int i = 1; i <= m; i++)
        {
            cin >> a;
            s ^= a;
        }
        cout << ((s != 0) ? "Yes" : "No") << endl;
    }
}