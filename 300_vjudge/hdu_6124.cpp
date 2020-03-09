#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int a; cin>>a;
        int r = (a&1)? (a-1)/2+2 : a/2+1;
        cout << r << endl;
    }
    return 0;
}