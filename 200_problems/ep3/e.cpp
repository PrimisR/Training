/**
 * 给定一个有向图，没有自环和重边，对边染色
 * 使用k种颜色染色，保证图中任何一个回路的各个边不是仅仅由同一种颜色组成
 * 找到符合条件最小的k，并构造出颜色
 * 1.没有回路k=1
 * 2.有回路k=2
 * 构造:
 * dfs，走向走过的结点涂2，没走过涂1
 * */
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 5005;

struct edge {
    int id;
    int to;
    edge(){}
    edge(int id,int to):id(id),to(to){}
};

int color[MAXN];
vector<edge> g[MAXN];
int visited[MAXN]; // 0表示没访问过，-1表示后代节点正在被访问中，1表示访问完毕，后代节点都被访问
int k = 1;

void dfs(int cur) {
    if(visited[cur] == 1) return; //如果他的子节点已经都访问过了，就没有必要再进行一次dfs了
    visited[cur] = -1;
    for(int i=0;i<g[cur].size();i++) {
        edge e = g[cur][i];
        if(visited[e.to] == -1) {
            k = 2;
            color[e.id] = 2;
            continue; //继续下一个子结点
        }
        else color[e.id] = 1;
        dfs(e.to);
    }
    visited[cur] = 1;
}

int main() {
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v; cin>>u>>v;
        g[u].push_back(edge(i,v));
    }
    for(int i=1;i<=n;i++) {
        if(visited[i] == 1) continue;
        dfs(i);
    }
    cout << k << endl;
    for(int i=1;i<=m;i++) {
        cout << color[i];
        if(i != m) cout << " ";
        else cout << endl;
    }
    return 0;
}