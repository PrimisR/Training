/**
 * dp
 * */
#include <iostream>
#include <cstdio>

using namespace std;

int dp[31];

int main() {
    dp[1] = 1;
    dp[2] = 3;
    for(int i=3;i<=30;i++) {
        dp[i] = dp[i-1] + dp[i-2]*2;
    }//放1和放2
    int n;
    cin>>n;
    while(n--) {
        int k;
        cin>>k;
        cout<<dp[k]<<endl;
    }
}