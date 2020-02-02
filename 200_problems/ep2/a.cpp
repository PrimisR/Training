/**
 * 数位dp，枚举两个数字的各个二进制数字位
 * 半加器等于全加器，说明没有进位，故(a_i & b_i) == 0
 * 由于是两个数相加的问题，前导0不会影响加后的答案，不必处理
 * 限制的判定(alim,blim)是用来判断是否达到上限(最大值)的
 * 
 * 容斥原理
 * 一维:[l,r] = [0,r] - [0,l-1]
 * 二维:[l,r][l,r] = [0,r][0,r] - [0,r][0,l-1] - [0,l-1][0,r] + [l-1,l-1]
 * 类似于面积，前缀和
 * 此题a,b对称，可以省略一步
 * */
#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

const int MAX_BIT = 32;
int au2[MAX_BIT]; //a的二进制上限
int bu2[MAX_BIT]; //b的二进制上限
long long dp[MAX_BIT][2][2]; //用于存储目前位上a,b是否有限制的方案数
//整体思路是：每次dp只枚举最高位,前后进行状态转移

/**
 * 记忆化深搜，自顶向下(从MAX_BIT开始搜索，因为MAX_BIT一定受限制)
 * */
long long dfs(int pos,bool alim,bool blim) {
    if(pos == -1) return 1; //最后一位的枚举是上限内逐个情况枚举
    if(dp[pos][alim][blim] != -1) return dp[pos][alim][blim];

    int aupper = alim? au2[pos] : 1;
    int bupper = blim? bu2[pos] : 1;

    long long ans = 0;
    for(int i=0;i<=aupper;i++) {
        for(int j=0;j<=bupper;j++) {
            if((i&j) == 0)
            ans += dfs(pos-1,alim&&(i==aupper),blim&&(j==bupper));
            //如果这一位受到限制，那么如果这一位到顶，下一位一样受到限制
        }
    }
    dp[pos][alim][blim] = ans;
    return ans;
}

/**
 * 计算0<=a<=au,0<=b<=bu上限的方案数
 * */
long long cal(int au,int bu) {
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<MAX_BIT;i++) au2[i]=bu2[i]=0;
    int len = 0;
    while (au || bu)
    {
        au2[len] = au & 1;
        bu2[len] = bu & 1;
        au >>= 1;
        bu >>= 1;
        len++; 
    }
    return dfs(MAX_BIT-1,true,true);//从0开始都有限制
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int l,r;
        cin>>l>>r;
        if(l == 0) cout << cal(r,r) << endl;
        else cout << cal(r,r)-2*cal(l-1,r)+cal(l-1,l-1) << endl;//二维容斥
    }
    return 0;
}