/**
 * dp[i][j] i 当前序列位置 j 该位置用的音符
 * dp[i][j] = max(dp[i-1][pre_j in range(1,MAXM)] + score[pre_j][j])
 * dp[1][j] = 0;
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXM = 55;
const int MAXN = 105;

int score[MAXM][MAXM];
int dp[MAXN][MAXM]; 
int arr[MAXN];

int n,m;

int main() {
    int T; cin>>T;
    while(T--) {
        cin>>n>>m;
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=m;j++) {
                cin>>score[i][j];
            }
        }
        for(int i=1;i<=n;i++) {
            cin>>arr[i];
        }
        for(int j=1;j<=m;j++) {
            dp[1][j] = 0;
        }
        for(int i=2;i<=n;i++) {
            if(arr[i-1] != -1 && arr[i] != -1) {
                dp[i][arr[i]] = dp[i-1][arr[i-1]] + score[arr[i-1]][arr[i]];
            }
            else if(arr[i] != -1) {
                dp[i][arr[i]] = 0;
                for(int pre_j=1;pre_j<=m;pre_j++) {
                    dp[i][arr[i]] = max(dp[i-1][pre_j]+score[pre_j][arr[i]],dp[i][arr[i]]);
                }
            }
            else if(arr[i-1] != -1) {
                for(int cur_j=1;cur_j<=m;cur_j++) {
                    dp[i][cur_j] = dp[i-1][arr[i-1]] + score[arr[i-1]][cur_j];
                }
            }
            else {
                for(int j=1;j<=m;j++) {
                    dp[i][j] = 0;
                    for(int pre_j=1;pre_j<=m;pre_j++) {
                        dp[i][j] = max(dp[i-1][pre_j]+score[pre_j][j],dp[i][j]);
                    }
                }
            }
            
        }
        int max_dp = 0;
        for(int j=1;j<=m;j++) {
            max_dp = max(dp[n][j],max_dp);
        }
        cout << max_dp << endl;
    }
}