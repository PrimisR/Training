#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool check(int x, int y, int n)
{
    if (x == n)
        return y == 1;
    else if (y == n)
        return x == 1;
    else
        return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        if (!check(x, y, n))
            cout << "NO" << endl;
        else {
            if (x == n) {
                cout << "YES" << endl;
                for (int i=1;i<=n-1;i++)
                    cout << i << " ";
                cout << n << endl;
            }
            else if (y == n) {
                cout << "YES" << endl;
                for (int i=n;i>=2;i--)
                    cout << i << " ";
                cout << 1 << endl;
            }
            else {
                // 10 2 6: 4 3 2 1 10 9 8 7 6 5
            }
        }
    }
    return 0;
}