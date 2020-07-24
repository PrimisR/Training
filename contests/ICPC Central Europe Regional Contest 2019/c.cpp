#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 300005;

vector<int> g[maxn];

int ans = 0;
int root = 1;

void dfs(int par, int cur)
{
    int split = 0;
    for (int i = 0; i < g[cur].size(); i++)
    {
        if (g[cur][i] == par)
            continue;
        dfs(cur, g[cur][i]);
        split++;
    }
    if (split >= 2 && cur != root)
        ans += split - 1;
    else if (cur == root)
    {
        if (split > 2)
            ans += split - 2;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}
