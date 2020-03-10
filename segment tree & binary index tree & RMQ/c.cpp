#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500005;

struct num {
    int input; //记录输入顺序
    int val; //记录值
};

int cmp_val(num a,num b) {
    return a.val < b.val;
}

num arr[MAXN];
int idarr[MAXN]; //排序后替换成新排位
int tree[MAXN];
int n;

inline void init() {
    for(int i=1;i<=n;i++) tree[i] = 0;
}

inline int lowbit(int x) {
    return x & (-x);
}

void upd(int x) {
    for(;x<=n;x+=lowbit(x)) tree[x]++;
}

long long find(int x) {
    long long out = 0;
    for(;x>=1;x-=lowbit(x)) out += tree[x];
    return out;
}

void discrete() {
    sort(arr+1,arr+1+n,cmp_val);
    for(int i=1;i<=n;i++) {
        idarr[arr[i].input] = i; //对号入座即可
    }
}

int main() {
    while(cin>>n && n) {
        for(int i=1;i<=n;i++) {
            cin>>arr[i].val;
            arr[i].input=i;
        }
        discrete();
        init();
        long long ans = 0;
        for(int i=1;i<=n;i++) {
            ans += idarr[i] - 1 - find(idarr[i]);
            upd(idarr[i]);
        }
        cout << ans << endl;
    }
}

