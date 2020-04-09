#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int a[MAXN];
int d[MAXN];

int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        d[a[i]] = d[a[i]-1]+1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(d[i]>ans) ans = d[i];
    }
    cout << n-ans << endl;
}