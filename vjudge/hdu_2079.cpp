/**
 * 多重背包
 * dp[i][j] i 前i种课程 j j学分 dp 方案数
 * 
 * */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct item {
    int val;
    int n;
};

int dp[10][45];
item arr[10];

int main() {
    int T; cin>>T;
    while(T--) {
        int n,k; cin>>n>>k;
        for(int i=1;i<=k;i++) {
            cin>>arr[i].val>>arr[i].n;
        } //读入
        for(int i=0;i<=k;i++) {
            for(int j=0;j<=n;j++) {
                dp[i][j] = 0;
            }
        }
        for(int j=1;j<=n;j++) dp[0][j] = 0;
        for(int i=0;i<=k;i++) dp[i][0] = 1; //dp初始化
        for(int i=1;i<=k;i++) {
            for(int j=1;j<=n;j++) {
                int pick_upper = min(j/arr[i].val,arr[i].n);
                for(int pick=0;pick<=pick_upper;pick++) {
                    dp[i][j] += dp[i-1][j-pick*arr[i].val];
                }
            }
        }
        cout << dp[k][n] << endl;
    }
}