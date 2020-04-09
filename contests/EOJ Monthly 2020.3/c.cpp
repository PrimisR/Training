#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int n;
int a[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
        for (int j = 0; j < n; j++)
        {
            int in;
            cin >> in;
            a[i] |= in;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i != n - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}