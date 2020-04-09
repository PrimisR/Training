#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        long long n; cin>>n;
        long long c = n * n + n;
        long long b = n + 1;
        long long ans = c ^ b;
        cout << ans << endl;
    }
    return 0;
}