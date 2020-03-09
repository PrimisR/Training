#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

namespace io {
    const int SIZE = 1e7 + 10;
    char inbuff[SIZE];
    char *l, *r;
    inline void init() {
        l = inbuff;
        r = inbuff + fread(inbuff, 1, SIZE, stdin);
    }
    inline char gc() {
        if (l == r) init();
        return (l != r) ? *(l++) : EOF;
    }
    void read(int &x) {
        x = 0; char ch = gc();
        while(!isdigit(ch)) ch = gc();
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
    }
} using io::read;

int main(){
    int t;
    scanf("%d", &t);
    int n, x;
    int cnt1, cnt2;
    while (t--){
        scanf("%d", &n);
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++){
            cin>>x;
            if (x == 1) cnt1++;
            else if (x == 2) cnt2++;
        }
        if (cnt1 > cnt2) cout<<"Kobayashi"<<endl;
        else if (cnt1 == cnt2) cout<<"Draw"<<endl;
        else cout<<"Tohru"<<endl;
    }
    return 0;
}