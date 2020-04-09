#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 55;

int a[MAXN];

bool check(int n) {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int d = a[i] - a[j];
            for(int k=0;k<n;k++) {
                if(k == i || k == j) continue;
                if(d % a[k] != 0) return false; 
            }
        }
    }
    return true;
}

int main() {
    int n; cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    bool ans = check(n);
    cout << ((ans)? "yes" : "no") << endl;
    return 0;
}