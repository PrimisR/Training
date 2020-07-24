#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 100;

vector<int> g[maxn];
string name[maxn];
int n, src;

int visited[maxn];
bool is_ans[maxn];

void dfs(int cur, queue<int> &q)
{
    if (visited[cur] == 1)
        return;
    visited[cur] = -1;
    for (int i = 0; i < g[cur].size(); i++)
    {
        if (visited[g[cur][i]] == -1)
        {
            q.push(g[cur][i]);
            is_ans[g[cur][i]] = true;
            continue;
        }
        dfs(g[cur][i], q);
    }
    visited[cur] = 1;
}

int main()
{
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        cin >> n >> src;
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
            visited[i] = 0;
            is_ans[i] = false;
        }
        for (int i = 1; i <= n; i++)
            cin >> name[i];
        for (int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++)
            {
                int v;
                cin >> v;
                g[i].push_back(v);
            }
        }
        queue<int> q;
        dfs(src, q);
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            visited[i] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            ans.push_back(u);
            for (int i = 0; i < g[u].size(); i++)
            {
                if (is_ans[g[u][i]])
                    continue;
                q.push(g[u][i]);
                is_ans[g[u][i]] = true;
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Chain Email #" << loop << ":" << endl;
        if (ans.empty())
        {
            cout << "Safe chain email!" << endl;
        }
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << name[ans[i]] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}