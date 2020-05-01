#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200005;
const int inf = 1000000007;

int a[maxn];
int is_in[maxn];
int in[maxn];
int out[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    for (int loop = 1; loop <= T; loop++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &is_in[i]);
        }
        int max_out = -inf, min_in = inf;
        for (int i = n; i >= 1; i--)
        {
            if (is_in[i])
            {
                out[i] = max_out;
            }
            else
            {
                max_out = max(max_out, a[i]);
                out[i] = max_out;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (is_in[i])
            {
                min_in = min(min_in,a[i]);
                in[i] = min_in;
            }
            else
            {
                in[i] = min_in;
            }
        }
        int max_b = -inf;
        for (int i = 1; i <= n; i++)
        {
            max_b = max(max_b, out[i] - in[i]);
        }
        if (max_b > 0)
        {
            cout << max_b << endl;
        }
        else
        {
            cout << "GAN" << endl;
        }

        // for(int i=1;i<=n;i++) {
        //     cout << in[i] << " ";
        // }
        // cout << endl;
        // for(int i=1;i<=n;i++) {
        //     cout << out[i] << " ";
        // }
        // cout << endl;
    }
    return 0;
}