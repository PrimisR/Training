/**
 * 有一群牛，每头牛有 xi 和 vi
 * 对这些牛两两计算 abs(xi-xj) * max(vi,vj),并求和
 * 
 * 首先对牛按照v进行排序，因为是以最大v为标准，所以对于每头牛只需考虑比这头牛v小的牛即可
 * (树状数组先排序输入顺序)
 * 那么要求在比当前牛i 的 vi 小的牛j 中， abs(xi-xj) 的和
 * 按照排序后的序列(1-indexation)，我们要知道在第i头牛之前插入了多少头比xi小的牛，以及这些小于xi牛的xj的和(Σxj,xj<xi)
 * 设 牛i 之前插入了 m 头比 xi 小的牛(xj<xi)，这些牛的坐标和为 s,此前插入所有牛的坐标总和为 t
 * 那么在此之前，比xi小的牛abs(xi-xj) (xj<xi) 的和为 xi*m - s
 * 比xi大的牛abs(xi-xj) (xj>xi) 的和为 (t-s) - xi*(i-1-m)
 * 这样就可以求出总和(不存在xi = xj)
 * 那么我们需要两个树状数组快速求前缀和，x为索引的数量前缀和，x为索引的x前缀和
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 20005;

struct tree {
    int arr[MAXN];

    tree() {
        clear();
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void clear() {
        for(int i=1;i<=MAXN;i++) {
            arr[i] = 0;
        }
    }

    void upd(int x,int d) {
        for(;x<=MAXN;x+=lowbit(x)) {
            arr[x] += d;
        }
    }

    int find(int x) {
        int out = 0;
        for(;x>=1;x-=lowbit(x)) {
            out += arr[x];
        }
        return out;
    }
};

struct cow {
    int v;
    int x;
};

int cmp(cow a,cow b) {
    return a.v < b.v;
}

cow c[MAXN];
tree num;
tree sum;

int main() {
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>c[i].v>>c[i].x;
    }
    sort(c+1,c+1+n,cmp);
    long long ans = 0;
    for(int i=1;i<=n;i++) {
        int x = c[i].x;
        int v = c[i].v;
        int m = num.find(x);
        long long s = sum.find(x);
        long long t = sum.find(20000);
        ans += (x*m - s + (t-s) - x*(i-1-m))*v; 
        num.upd(x,1);
        sum.upd(x,x);
    }
    cout << ans << endl;
    return 0;
}