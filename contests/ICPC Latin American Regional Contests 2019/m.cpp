#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int a[MAXN];
int diff[MAXN];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        diff[i] = a[i + 1] - a[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (diff[i] > k)
            continue;
        int j;
        for (j = i + 1; j < n - 1; j++)
        {
            if(diff[j] > k) {
                break;
            }
        }
        ans = max(ans,j-i);
    }
    cout << ans+1 << endl;
    return 0;
}