#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000005;

int a[MAXN];
int n;

int main() {
    cin>>n;
    int sn = 0; long long sk2 = 0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        sn += a[i];
    }
    long long m = -1;
    for(int k = 1;k <= n-1 ; k++) {
        sn -= a[k]; sk2 += a[k] * a[k];
        long long s = sk2 * sn;
        if(s > m) m = s;
    }
    cout << m << endl;
    return 0;
}