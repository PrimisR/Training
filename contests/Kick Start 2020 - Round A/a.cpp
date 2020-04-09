#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int a[MAXN];

int main() {
    int T;
    cin>>T;
    int CASE = 0;
    while(T--) {
        int n,b;
        cin>>n>>b;
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        sort(a,a+n);
        int total = 0;
        int house = 0;
        for(int i=0;i<n;i++) {
            if(total + a[i] > b) break;
            total += a[i];
            house++;
        }
        cout << "Case #" << ++CASE << ": " << house << endl;
    }
    return 0;
}