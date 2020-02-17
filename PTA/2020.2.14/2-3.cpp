#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct maze {
    int cur;
    int dist;
    maze():cur(0),dist(0){}
    maze(int c,int d):cur(c),dist(d){}
};

vector<int> g[100005];
bool is_c[100005];

int main() {
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        int k; cin>>k;
        if(k == 0) continue;
        for(int j=0;j<k;j++) {
            int edge; cin>>edge;
            is_c[edge] = true;
            g[i].push_back(edge);
        }
    }
    int st;
    for(int i=1;i<=n;i++) {if(!is_c[i]) {st=i; break;}}
    queue<maze> q;
    q.push(maze(st,0));
    maze m;
    while (!q.empty())
    {
        m = q.front(); q.pop();
        for(int i=0;i<g[m.cur].size();i++) {
            q.push(maze(g[m.cur][i],m.dist+1));
        }
    }
    cout << m.cur <<endl;
    return 0;
}