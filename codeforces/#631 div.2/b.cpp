#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

int a[MAXN];
int cnt[MAXN];
int visited[MAXN];

bool check(int cut, int maxv)
{
    for (int i = cut + 1; i <= maxv; i++)
    {
        if (cnt[i] != 1)
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        bool legal = true;
        int n;
        cin >> n;
        int maxv = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
            maxv = max(maxv, a[i]);
        }
        int cut = 0;
        for (int i = 1; i <= maxv; i++)
        {
            if (cnt[i] == 2)
            {
                cut = i;
            }
            else
                break;
        }
        legal = check(cut, maxv);
        if (!legal)
        {
            cout << 0 << endl;
        }
        else
        {
            bool ans1 = true;
            bool ans2 = true;
            for (int i = 1; i <= cut; i++)
            {
                visited[i] = false;
            }
            for (int i = cut + 1; i <= maxv; i++)
            {
                visited[i] = true;
            }
            for (int i = 1; i <= cut; i++)
            {
                if (visited[a[i]])
                {
                    ans1 = false;
                    break;
                }
                visited[a[i]] = true;
            }
            for (int i = 1; i <= n - cut; i++)
            {
                visited[i] = false;
            }
            for (int i = n - cut + 1; i <= maxv; i++)
            {
                visited[i] = true;
            }
            for (int i = 1; i <= n - cut; i++)
            {
                if (visited[a[i]])
                {
                    ans2 = false;
                    break;
                }
                visited[a[i]] = true;
            }
            if (!ans1 && !ans2)
            {
                cout << 0 << endl;
            }
            else if (ans1 && !ans2)
            {
                cout << 1 << endl;
                cout << cut << " " << n - cut << endl;
            }
            else if (!ans1 && ans2)
            {
                cout << 1 << endl;
                cout << n - cut << " " << cut << endl;
            }
            else
            {
                if (cut != n - cut)
                {
                    cout << 2 << endl;
                    cout << cut << " " << n - cut << endl;
                    cout << n - cut << " " << cut << endl;
                }
                else
                {
                    cout << 1 << endl;
                    cout << n - cut << " " << cut << endl;
                }
            }
        }
    }
    return 0;
}