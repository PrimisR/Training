/**
 * bitset 二进制应用
 * */
#include <cstdio>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

const int N = 505;
const int M = 20;
const int inf = 0x3f3f3f3f;

bitset<N> bs[M];

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n,m; cin>>n>>m; getchar();
        for(int i=0;i<m;i++) {
            bs[i].reset();
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                char ch;
                cin>>ch;
                bs[i][j] = (ch - '0');
            }
            getchar();
        }
        int minv = inf;
        //枚举幂集
        for(int i=0;i<(1<<m);i++) {
            bitset<N> tmp(0);
            int bit = 0;
            for(int j=0;j<m;j++) {
                if(i & (1<<j)) {
                    tmp = tmp | bs[j];
                    bit++;
                }
            }
            if(tmp.count() == n) minv = min(minv,bit);
        }
        if(minv == inf) {
            cout << -1 << endl;
        }
        else {
            cout << minv << endl;
        }
    }
    return 0;
}