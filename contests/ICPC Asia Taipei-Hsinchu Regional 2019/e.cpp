#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int arr[2000];
        int k,l;
        cin>>k>>l;
        if(l >= 2000) {
            cout << -1 << endl;
        }
        else {
            cout << 1999 << endl;
            int x = (k & 1)? 1 : 2;
            int a = 1;
            int y = (1999*x+k)/2-1;
            arr[1] = a;
            arr[2] = -a-x;
            int tot = a+y;
            for(int i=3;i<=1999;i++) {
                if(tot>=1000000) {
                    arr[i] = 1000000;
                    tot -= 1000000;
                }
                else {
                    arr[i] = tot;
                    tot -= tot;
                }
            }
            for(int i=1;i<=1999;i++) {
                cout << arr[i];
                if(i != 1999) cout << " ";
                else cout << endl;
            }
        }
    }
    return 0;
}