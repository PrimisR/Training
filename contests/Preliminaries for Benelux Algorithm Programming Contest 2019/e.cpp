#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

struct edge {
    int id;
    int to;
    edge(){}
    edge(int id,int to):id(id),to(to){}
};

vector<edge> g[MAXN]; int n,m;
int visited[MAXN];
bool deleted[MAXM];
vector<int> del;

void dfs(int cur) {
    if(visited[cur] == 1) return;
    visited[cur] = -1;
    for(int i=0;i<g[cur].size();i++) {
        edge e = g[cur][i];
        if(deleted[e.id] == true) continue;
        if(visited[e.to] == -1) {
            del.push_back(e.id);
            deleted[e.id] = true;
            continue;
        }
        dfs(e.to);
    }
    visited[cur] = 1;
}

int main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int st,ed; cin>>st>>ed;
        g[st].push_back(edge(i,ed));
    }
    for(int i=1;i<=n;i++) {
        if(visited[i] == 1) continue;
        dfs(i);
    }
    if(del.size() <= m/2) {
        cout << del.size() << endl;
        for(int i=0;i<del.size();i++) {
            cout << del[i] << endl;
        }
    }
    else {
        cout << m - del.size() << endl;
        for(int i=1;i<=m;i++) {
            if(deleted[i]) continue;
            cout << i << endl;
        }
    }
    
    return 0;
}