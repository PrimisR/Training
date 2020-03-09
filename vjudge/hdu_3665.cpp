/**
 * Dijkstra
 * */
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 15;
const int inf = 0x3f3f3f3f;

struct edge {
    int to;
    int val;
    edge(){}
    edge(int to,int val):to(to),val(val){}
};

vector<edge> g[MAXN];
int dist[MAXN];
bool visited[MAXN];

struct vertex {
    int id;
    int dist;
    vertex(){}
    vertex(int id,int dist):id(id),dist(dist){}
    bool operator< (const vertex v) const{
        return this->dist > v.dist;
    }
};

int main() {
    int n;
    while(cin>>n) { //0~n-1是镇子，n是海边，距离为0
        for(int i=0;i<=n;i++) {dist[i] = inf; visited[i] = false;} //初始化
        for(int i=0;i<n;i++) {
            int k,is_sea; cin>>k>>is_sea;
            if(is_sea == 1) g[i].push_back(edge(n,0));
            while(k--) {
                int to,val; cin>>to>>val;
                g[i].push_back(edge(to,val));
            } //读图
        }
        //dijkstra 优化
        int st = 0; dist[st] = 0;
        priority_queue<vertex> pq; //包含所有未选入集合s的点
        pq.push(vertex(st,0));
        while(!pq.empty()) {
            vertex u = pq.top(); pq.pop();
            if(visited[u.id]) continue; //从pq中拿出来的最小的没有访问过的距离一定是到达该点的最小距离
            visited[u.id] = true;
            for(int i=0;i<g[u.id].size();i++) {
                int next = g[u.id][i].to; //对于选入的结点下面所有的结点更新距离，并只加入被更新的点(只有这些结点参与排序)
                if(visited[next]) continue;
                if(dist[next] > dist[u.id] + g[u.id][i].val) {
                    dist[next] = dist[u.id] + g[u.id][i].val;
                    pq.push(vertex(next,dist[next]));
                }
            }
        }
        cout << dist[n] << endl;
    }
}