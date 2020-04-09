/**
 * 带权并查集
 * */
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 200005;

struct node {
    int father;
    int val; //初始为0
};

node union_set[MAXN];

int n,m;

int find(int x) {
    if(x == union_set[x].father) return x;
    int fx = union_set[x].father;
    union_set[x].father = find(union_set[x].father);
    union_set[x].val += union_set[fx].val;
    return union_set[x].father;
}

void init() {
    for(int i=0;i<=n;i++) {
        union_set[i].father = i;
        union_set[i].val = 0;
    }
}

int main() {
    int T; cin>>T;
    while(T--) {
        cin>>n>>m;
        init();
        int ans = 0;
        for(int i=1;i<=m;i++) {
            int l,r,w;
            cin>>l>>r>>w;
            int fl = find(l-1);
            int fr = find(r);
            if(fl != fr) {
                union_set[fl].father = fr;
                union_set[fl].val = union_set[r].val - union_set[l-1].val + w;
            }
            else if(abs(union_set[l-1].val - union_set[r].val) != w) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}