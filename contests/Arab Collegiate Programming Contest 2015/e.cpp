#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10005;

int arr[MAXN];

int main() {
    int T;
    cin>>T;
    while(T--) {
        int a,b;
        cin>>a>>b;
        for(int i=1;i<=a+b+1;i++) {
            cin>>arr[i];
        }
        int r = arr[1];
        for(int i=2;i<=1+a;i++) {
            r &= arr[i];
        }
        for(int i=a+2;i<=a+b+1;i++) {
            r |= arr[i];
        }
        cout << r << endl;
    }
}