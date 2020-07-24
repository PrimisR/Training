#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        int N;
        cin >> N;
        int a[200];
        for (int i = 1; i <= N; i++)
        {
            cin >> a[i];
            a[i] = abs(a[i]);
        }
        int p = 0, n = 0;
        int e = 0;
        for (int i = 1; i <= N - 1; i++)
        {
            int d = a[i + 1] - a[i];
            if (d > 0)
                p++;
            else if (d < 0)
                n++;
            else
                e++;
        }
        if (p + e != n || n + e != p)
        {
            if (p > n)
            {
                for (int i = 2; i <= N - 1; i++)
                {
                    if (a[i - 1] < a[i] && a[i] < a[i + 1])
                    {
                        a[i] = -a[i];
                        p--;
                        n++;
                    }
                    if (a[i - 1] == a[i] && a[i] < a[i + 1])
                    {
                        a[i] = -a[i];
                        e--;
                        n++;
                    }
                    if (p + e == n || n + e == p)
                        break;
                }
            }
            else if (p < n)
            {
                for (int i = 2; i <= N - 1; i++)
                {
                    if (a[i - 1] > a[i] && a[i] > a[i + 1])
                    {
                        a[i] = -a[i];
                        n--;
                        p++;
                    }
                    if (a[i - 1] > a[i] && a[i] == a[i + 1])
                    {
                        a[i] = -a[i];
                        e--;
                        p++;
                    }
                    if (p + e == n || n + e == p)
                        break;
                }
            }
        }

        for (int i = 1; i <= N; i++)
        {
            cout << a[i];
            if (i != N)
                cout << " ";
            else
                cout << endl;
        }
    }
    return 0;
}