#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 202000;
const int MOD = 530600414; //相乘爆int

int cff[MAXN] = {0,0,0,1,1,2,3};
int pos_sum[MAXN] = {0,0,0,0,2,5,17};
int len[MAXN] = {0,1,2,3,5,8,13};
int f[MAXN] = {0,0,0,0,0,5,16};

int main() {
    for(int i=7;i<=201316;i++) {
        cff[i] = cff[i-1] + cff[i-2]; cff[i] %= MOD;
        len[i] = len[i-1] + len[i-2]; len[i] %= MOD;
        pos_sum[i] = pos_sum[i-1] + pos_sum[i-2] + ((long long)cff[i-1]*len[i-2])%MOD; pos_sum[i] %= MOD;
        f[i] = f[i-1] + f[i-2] + ((((long long)cff[i-2]*len[i-2])%MOD - pos_sum[i-2])%MOD * (long long)cff[i-1])%MOD + ((long long)cff[i-2]*pos_sum[i-1])%MOD;
        while(f[i] < 0) f[i] += MOD;
        f[i] %= MOD;
    }
    int T; cin>>T; int c = 1;
    while(T--) {
        int x; cin>>x;
        cout << "Case #" << c++ << ": " <<f[x] << endl;
    }
}