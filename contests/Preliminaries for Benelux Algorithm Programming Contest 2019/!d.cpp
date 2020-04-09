#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 105;

double dp[MAXN];

int main() {
    dp[0] = 0;
    int n,k; cin>>n>>k;
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=n;j++) {
            dp[i] += max((double)j,dp[i-1]);
        }
        dp[i] /= double(n);
    }
    printf("%.12lf\n",dp[k]);
    return 0;
}