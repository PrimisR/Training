/**
 * 拓扑排序+bfs流
 * 流过的次数就是发送信息总数
 * 从1流经了哪些结点就是改进发送信息数
 * */
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int p = 1000000007;
const int maxn = 2005;

vector<int> g[maxn];
bool visited[maxn];
int deg[maxn];
int flow[maxn];

int n, l;

int main()
{
    cin >> n >> l;
    for (int i = 1; i <= l; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int a;
            cin >> a;
            g[i].push_back(a);
            deg[a]++;
        }
    }
    visited[1] = true;
    flow[1] = 1;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            if (visited[u])
                visited[g[u][i]] = true;
            flow[g[u][i]] = (flow[g[u][i]] + flow[u]) % p;
            deg[g[u][i]]--;
            if (deg[g[u][i]] == 0)
                q.push(g[u][i]);
        }
    }
    int tot_f = 0,tot_visited = 0;
    for(int i=l+1;i<=n;i++) {
        tot_f = (tot_f + flow[i])%p;
        tot_visited += visited[i];
    }
    cout << tot_f << " " << tot_visited << endl;
    return 0;
}