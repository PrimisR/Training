#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 500010;

int n;
long long depth[N];
long long cnt[N];
long long dist[N];
vector<int> g[N];
vector<long long> ans;

void init() {
  for (int i = 1; i <= n; i++) g[i].clear();
  ans.clear();
}

long long dfs_cnt(int cur) {
  cnt[cur] = 1;
  for (int i = 0; i < g[cur].size(); i++) {
    cnt[cur] += dfs_cnt(g[cur][i]);
  }
  return cnt[cur];
}

void dfs_depth(int cur) {
  if (g[cur].size() == 0) {
    ans.push_back(depth[cur] * n - dist[cur]);
    return;
  }
  for (int i = 0; i < g[cur].size(); i++) {
    depth[g[cur][i]] = depth[cur] + 1;
    dist[g[cur][i]] = dist[cur] + cnt[g[cur][i]];
    dfs_depth(g[cur][i]);
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    init();
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      g[p].push_back(i);
    }
    depth[1] = dist[1] = 0;
    dfs_cnt(1);
    dfs_depth(1);
    long long tot = 0;
    for (int i = 1; i <= n; i++) tot += cnt[i];
    tot += (*max_element(ans.begin(), ans.end()));
    cout << tot << endl;
  }
  return 0;
}