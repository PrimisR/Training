#include <cstdio>
#include <iostream>

using namespace std;

int exgcd(int a,int b,int &x,int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int _x,_y;
    int gcd = exgcd(b,a%b,_x,_y);
    x = _y;
    y = _x-(a/b)*_y;
    return gcd;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n,b;
        cin>>n>>b;
        int x,y;
        int gcd = exgcd(b,9973,x,y);
        while(x < 0) x += 9973;
        cout << (x*n)%9973 << endl;
    }
}