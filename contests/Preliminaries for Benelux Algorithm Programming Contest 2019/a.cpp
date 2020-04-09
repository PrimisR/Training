#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int rmax = -1;
    int cmax = -1;
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++) {
        int ri; cin>>ri;
        if(ri > rmax) rmax = ri;
    }
    for(int i=0;i<c;i++) {
        int ci; cin>>ci;
        if(ci > cmax) cmax = ci;
    }
    if(rmax != cmax) cout << "impossible" << endl;
    else cout << "possible" << endl;
    return 0;
}