/**
 * 给定一个无向树包含n个顶点，找到一组线段满足:
 * 1.线段的两端是1-2n的某个整数，并且1-2n的任何整数仅仅作为某一个线段的某一个端点
 * 2.线段是非退化的，不能退化成一个点
 * 3.对于点对(i,j)，i in [1,n],j in [i,n] 并且 i != j
 * 顶点 i,j 相连当且仅当线段 i,j 相交，但是两个线段并不互相包含(理解为区间)
 * 
 * 树深搜 先序遍历
 * scanf最快
 * */
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 500005;
const int inf = 0x3f3f3f3f;

vector<int> g[MAXN];
int ep[MAXN][2]; // endpoints
int max_alloc;

void dfs(int cur,int parent) {
    int child = g[cur].size()-1;
    ep[cur][1] = max_alloc - child - 1;
    max_alloc = ep[cur][1];
    for(int j=0,i=ep[cur][1]+1;j<g[cur].size();j++) {
        if(g[cur][j] == parent) continue;
        ep[g[cur][j]][0] = i++;
        dfs(g[cur][j],cur);
    }
}

int main() {
    int n; scanf("%d",&n);
    for(int i=0;i<n-1;i++) {
        int l,r; scanf("%d %d",&l,&r);
        g[l].push_back(r); g[r].push_back(l);
    }
    // regard 1 as root
    ep[1][0] = 2*n; max_alloc = ep[1][0]-1; //对root进行了特殊处理,因为max_alloc会更新
    dfs(1,0);
    for(int i=1;i<=n;i++) {
        printf("%d %d\n",ep[i][1],ep[i][0]);
    }
    return 0;
}