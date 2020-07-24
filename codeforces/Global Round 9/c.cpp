#include <cstdio>
#include <iostream>

using namespace std;

int a[300005];
int n;

int main()
{
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if(a[n] > a[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}