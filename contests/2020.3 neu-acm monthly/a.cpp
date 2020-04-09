#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;

vector<int> g[MAXN];
int cnt[2];
int n;

void dfs(int p,int u,int depth) {
    cnt[depth & 1]++;
    for(int i=0;i<g[u].size();i++) {
        if(g[u][i] == p) continue;
        dfs(u,g[u][i],depth+1);
    }
};

void init() {
    for(int i=0;i<=n;i++) g[i].clear();
    cnt[0] = cnt[1] = 0;
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        init();
        cin>>n;
        for(int i=1;i<=n-1;i++) {
            int u,v; scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int root = 1; cnt[0]++;
        for(int i=0;i<g[1].size();i++) {
            dfs(1,g[1][i],1);
        }
        long long ans = ((long long)cnt[0] * (cnt[0]-1)) / 2 + ((long long)cnt[1] * (cnt[1]-1)) / 2;
        cout << ans << endl;
    }
    return 0;
}

