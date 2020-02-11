/**
 * 动态规划题，多重背包
 * 用dp存储方案数
 * 状态:当前家庭数目family,当前蚂蚁总数size
 * 有dp[family][size] = Σdp[family-1][size-k](k:0~当前家庭内蚂蚁总数与当前size的最小值)
 * 这样需要一个 1e3 * 1e5 的dp数组，空间需求过大
 * 
 * 空间优化:滚动数组
 * 由于最终的结果最多会与上一次的family相关，所以可以每次仅仅使用一个1e5大小的数组用来存储上一次的结果
 * 
 * 时间优化：前缀和
 * 快速处理区间多次加和
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int MOD = 1000000;

int members[1005];
int dp[100005];
int pre_sum[100005];// 包含从0到当前项本项的dp和(前缀和)

int main()
{
    ios::sync_with_stdio(false);
    int T,A,S,B;
    while(cin>>T>>A>>S>>B) {
        for(int i=0;i<=T;i++) dp[i] = 0,pre_sum[i] = 0;
        for(int i=0;i<=A;i++) members[i] = 0;

        for(int i=0;i<A;i++) {
        int ant; cin>>ant;
        members[ant]++;
        }

        // 初值，0是要算做有一种情况的
        dp[0] = 1; pre_sum[0] = 1; 
        for(int i=1;i<=A;i++) pre_sum[i] = (pre_sum[i-1] + dp[i])%MOD;
        for(int family=1;family<=T;family++) {
            for(int size=1;size<=A;size++) { // 针对dp除了0以外每个格子
                int upper = min(members[family],size);
                dp[size] = (size-upper-1 == -1)? pre_sum[size]:pre_sum[size]-pre_sum[size-upper-1];
                dp[size] = (dp[size]+MOD)%MOD;
            }
            for(int i=1;i<=A;i++) pre_sum[i] = (pre_sum[i-1] + dp[i])%MOD;
            // for(int i=0;i<=A;i++) cout << dp[i] << " "; cout << endl;
            // for(int i=0;i<=A;i++) cout << pre_sum[i] << " "; cout << endl;
        }
        cout << (pre_sum[B] - pre_sum[S-1] + MOD) % MOD << endl;
    }
    
    return 0;
}