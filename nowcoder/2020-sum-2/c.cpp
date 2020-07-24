#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 200005;

vector<int> g[maxn];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    return 0;
}