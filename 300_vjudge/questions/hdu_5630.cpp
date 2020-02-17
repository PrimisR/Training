/**
 * 横竖两列间隔翻转即可
 * */
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    while(n--) {
        int r,c; cin>>r>>c;
        cout << (r/2 + c/2) << endl;
    }
}