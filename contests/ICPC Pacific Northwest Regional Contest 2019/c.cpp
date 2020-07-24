#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100005;

vector<int> g[maxn];
bool visited[maxn];
int n, m;

struct node
{
    int cur;
    int step;
    node(int cur, int step) : cur(cur), step(step) {}
};

int bfs()
{
    queue<node> q;
    q.push(node(1, 0));
    visited[1] = true;
    while (!q.empty())
    {
        node u = q.front();
        q.pop();
        if (u.cur == n)
            return u.step;
        for (int i = 0; i < g[u.cur].size(); i++)
        {
            if(visited[g[u.cur][i]]) continue;
            q.push(node(g[u.cur][i],u.step+1));
            visited[g[u.cur][i]] = true;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << bfs()-1 << endl;
}