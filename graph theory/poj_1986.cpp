/**
 * POJ 1986
 * Tarjan 离线 LCA
 * */
#include <cstdio>
#include <vector>

using namespace std;
// 带权边
struct edge {
  int to;
  int val;
  edge() {}
  edge(int to, int val) : to(to), val(val) {}
};
// 用ID标记每个查询
struct qry {
  int id;
  int cw;  // 查询的另一个顶点
  qry() {}
  qry(int id, int cw) : id(id), cw(cw) {}
};

const int N = 90000;
const int Q = 30000;
// 并查集
int f[N];

void finit(int n) {
  for (int i = 1; i <= n; i++) f[i] = i;
}

int find(int x) { return (f[x] == x) ? x : f[x] = find(f[x]); }

void uni(int x, int y) { f[find(y)] = find(x); }

// 图 + Tarjan
vector<qry> queries[N];  // 含有该点的所有查询
vector<edge> g[N];       // 图

bool visited[N]; // 标记是否访问过
int depth[N]; // 深度
int ans[Q]; // 查询答案

void init(int n) {
  finit(n);
  for (int i = 0; i <= n; i++) {
    visited[i] = false;
    depth[i] = 0;
  }
}

void tarjan(int cur) {
  visited[cur] = true;
  for (int i = 0; i < g[cur].size(); i++) {
    if (visited[g[cur][i].to]) continue;
    tarjan(g[cur][i].to); // dfs
    uni(cur, g[cur][i].to); // 并查集合并
  }
  for (int i = 0; i < queries[cur].size(); i++) {
    if (visited[queries[cur][i].cw]) {
      int lca = find(queries[cur][i].cw); // lca为另一个点的并查集结果
      ans[queries[cur][i].id] =
          depth[cur] + depth[queries[cur][i].cw] - 2 * depth[lca]; // 直接计算每个查询的答案
    }
  }
}
// 预处理深度
void dfs_for_depth(int anc, int cur) {
  for (int i = 0; i < g[cur].size(); i++) {
    if (g[cur][i].to == anc) continue;
    depth[g[cur][i].to] = depth[cur] + g[cur][i].val;
    dfs_for_depth(cur, g[cur][i].to);
  }
}

int main() {
  int n, m, q;
  while (~scanf("%d %d", &n, &m)) {
    init(n);
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      char d;
      scanf("%d %d %d %c", &u, &v, &w, &d);
      g[u].push_back(edge(v, w));
      g[v].push_back(edge(u, w));
    }
    scanf("%d", &q);
    for (int qid = 1; qid <= q; qid++) {
      int u, v;
      scanf("%d %d", &u, &v);
      queries[u].push_back(qry(qid, v));
      queries[v].push_back(qry(qid, u));
    }
    int root = 1;
    depth[root] = 0;
    dfs_for_depth(0, root);
    tarjan(root);
    for (int qid = 1; qid <= q; qid++) {
      printf("%d\n", ans[qid]);
    }
  }
  return 0;
}