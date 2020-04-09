#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 105;

int tree[MAX];
int arr[MAX];
int visited[MAX];
int f[MAX];

int lowbit(int x) {
    return x & (-x);
}

int init() {
    for(int i=1;i<MAX;i++) {
        tree[i] = 0;
        visited[i] = false;
    }
}

void upd(int x) {
    for(;x<MAX;x+=lowbit(x)) {
        tree[x]++;
    }
}

int find(int x) {
    int out = 0;
    for(;x>0;x-=lowbit(x)) {
        out += tree[x];
    }
    return out;
}

int main() {
    int T; cin>>T;
    while (T--)
    {
        int maxv = 0;
        int n,x; cin>>n>>x;
        init();
        for(int i=1;i<=n;i++) {
            cin>>arr[i];
            maxv = max(maxv,arr[i]);
            if(visited[arr[i]]) continue;
            visited[arr[i]] = true;
            upd(arr[i]);
        }
        int r = -1;
        for(int i=1;i<=maxv;i++) {
            f[i] = i - find(i);
            if(f[i] <= x) {
                r = i;
            }
        }
        int ans;
        if(r == maxv) ans = x - f[maxv] + maxv;
        else {
            ans = x - f[r] + r;
        }
        cout << ans << endl;
    }
    return 0; 
}