/**
 * 给定k，求第k小的数n，使得φ(n)是合数，即欧拉函数(小于n与n互质的数)
 * 根据欧拉函数公式，质数情况只有1，2，3，4，6
 * 所以第一合数是5，第n是5+n
 * */
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    while(n--) {
        int k;
        cin>>k;
        if(k == 1) cout << 5 << endl;
        else cout << 5+k << endl;
    }
    return 0;
}