#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#define ll long long
const int maxn = 1e9;
const int INF = 0x3f3f3f3f;
using namespace std;

const double e = 2.71828;

const double es[] = {1,
2.71828,
7.38905,
20.0855,
54.598,
148.413,
403.427,
1096.63,
2980.94,
8103.03,
22026.3};

double qpow(int index) {
    double ans = 1;
    double base = e;
    while(index != 0) {
        if(index & 1) ans *= base;
        base *= base;
        index >>= 1;
    }
    return ans;
}

int d[100005];

int main(){
    ios::sync_with_stdio(0);
    int n;
    int mi = INF;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>d[i];
        if(d[i] < mi) mi = d[i];
    }
    double total = 0;
    for(int i=0;i<n;i++) {
        d[i] -= mi;
        total += es[d[i]];
    }
    for(int i=0;i<n;i++) {
        printf("%.8lf ",es[d[i]]/total);
    }
    return 0;
}