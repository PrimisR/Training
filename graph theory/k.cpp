/**
 * 一笔画问题(多个联通分量)
 * */
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 100005;

int n,m;

int father[MAXN];
int deg[MAXN];
int cnt[MAXN];

void init() {
    for(int i=1;i<=n;i++) {
        father[i] = i;
    }
}

int find(int i) {
    return (father[i] == i)? i : father[i] = find(father[i]);
}

void uni(int i,int j) {
    int fi = find(i);
    int fj = find(j);
    if(fi != fj) father[fi] = fj;
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        init();
        memset(deg,0,sizeof(deg));
        memset(cnt,-1,sizeof(cnt));
        for(int i=1;i<=m;i++) {
            int u,v; scanf("%d%d",&u,&v);
            deg[u]++;
            deg[v]++;
            uni(u,v);
        }
        for(int i=1;i<=n;i++) {
            int fi = find(i);
            if(cnt[fi] == -1 && deg[i] > 0) { //如果不是单独的点
                cnt[fi] = 0;
            } 
            if(deg[i] & 1) {
                cnt[fi]++;
            }
        } //单独点<0,否则统计奇点
        int ans = 0;
        for(int i=1;i<=n;i++) {
            if(cnt[i] == 0) {
                ans += 1;
            }
            else if(cnt[i] > 0) {
                ans += cnt[i]/2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}