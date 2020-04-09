/**
 * 给定n个点(1...n)，m条边，编号s为终点
 * 然后给定w个点作为起始点
 * 多源最短路，可以用一个0作为超级原点连接这些点，权值为0
 * */
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1005;
const int inf = 0x3f3f3f3f;

struct edge
{
    int to;
    int val;
    edge(int to,int val):to(to),val(val){}
};

struct vertex {
    int id;
    int dist;
    vertex(int id,int dist):id(id),dist(dist){}
    vertex(){}
    bool operator< (const vertex v) const {
        return this->dist > v.dist;
    }
};

vector<edge> g[MAXN];
int dist[MAXN];
bool visited[MAXN];

int st = 0,ed;
int n,m;
int w;

void init() {
    for(int i=0;i<=n;i++) {
        g[i].clear();
        dist[i] = inf;
        visited[i] = false;
    }
}

void D() {
    dist[st] = 0;
    priority_queue<vertex> pq;
    pq.push(vertex(st,0));
    while (!pq.empty())
    {
        vertex u = pq.top(); pq.pop();
        if(visited[u.id]) continue;
        visited[u.id] = true;
        for(int i=0;i<g[u.id].size();i++) {
            int next = g[u.id][i].to;
            if(visited[next]) continue;
            if(dist[next] > dist[u.id]+g[u.id][i].val) {
                dist[next] = dist[u.id] + g[u.id][i].val;
                pq.push(vertex(next,dist[next]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    while(cin>>n>>m>>ed) {
        init();
        for(int i=1;i<=m;i++) {
            int from,to,val;
            cin>>from>>to>>val;
            g[from].push_back(edge(to,val));
        }
        cin>>w;
        for(int i=1;i<=w;i++) {
            int a; cin>>a;
            g[0].push_back(edge(a,0));
        }
        D();
        if(dist[ed] == inf) {
            cout << -1 << endl;
        }
        else {
            cout << dist[ed] << endl;
        }
    }
}