#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1005;

vector<int> g[N];

int main() {
    int n; cin>>n;
    int m = n*(n-1)/2;
    for(int i=1;i<=m;i++) {
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back(w);
        g[v].push_back(w);
    }
    long long ans = 0;
    for(int i=1;i<=n;i++) {
        sort(g[i].begin(),g[i].end());
        for(int j=1;j<n;j+=2) {
            ans += g[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}