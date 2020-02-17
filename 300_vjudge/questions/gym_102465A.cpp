#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000005];

int main()
{
    int n,k; cin>>n>>k;
    int off=0; int max_off = 0;
    while(k--) {
        int hack; cin>>hack;
        int off_upd = 0;
        for(int i=hack;i<=n;i+=hack) {
            arr[i]++;
            if(arr[i] & 1) off_upd++;
            else off_upd--;
        }
        off += off_upd;
        max_off = max(max_off,off);
    }
    cout << max_off << endl;
    return 0;
}