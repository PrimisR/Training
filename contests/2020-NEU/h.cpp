#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 100005;

vector<int> g[maxn];
int deg[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    for (int loop = 1; loop <= T; loop++)
    {
        int n, m;
        scanf("%d %d",&n,&m);
        for (int i = 1; i <= n; i++)
        {
            deg[i] = 0;
            g[i].clear();
        }
        vector<int> ans;
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            g[b].push_back(a);
            deg[a]++;
        }
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] == 0)
            {
                pq.push(i);
            }
        }
        while (!pq.empty())
        {
            int u = pq.top();
            pq.pop();
            ans.push_back(u);
            for(int i=0;i<g[u].size();i++) {
                deg[g[u][i]]--;
                if(deg[g[u][i]] == 0) {
                    pq.push(g[u][i]);
                }
            }
        }
        for(int i=0;i<ans.size();i++) {
            printf("%d",ans[i]);
            if(i != ans.size()-1) printf(" ");
            else printf("\n");
        }
    }
}