#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 25;

int a[MAXN];
int a_copy[MAXN];
map<int,int> m;

int main() {
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a_copy[i] = a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-1;i++) {
        m[a[i]] = a[i+1];
    }
    m[a[n]] = a[1];
    for(int i=1;i<=n;i++) {
        cout << m[a_copy[i]];
        if(i != n) cout << " ";
        else cout << endl;
    }
    return 0;
}