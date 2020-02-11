#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100005;

int main() {
    int n,m,min_v = MAXN;
    cin>>n>>m;
    while(m--) {
        int l,r;
        cin>>l>>r;
        if(r-l+1 < min_v) min_v = r-l+1;
    }
    cout << min_v << endl;
    for(int i=0;i<=n-1;i++) {
        cout << i%min_v;
        if(i != n-1) cout << " ";
        else cout << endl;
    }
    return 0;
}