#include <cstdio>
#include <iostream>

using namespace std;

const long long MOD = 29;

long long exgcd(long long a,long long b,long long &x,long long &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long _x,_y;
    long long gcd = exgcd(b,a%b,_x,_y);
    x = _y;
    y = _x - (a/b)*_y;
    return gcd;
}

long long qpow(long long base,long long index,long long mod) {
    long long out = 1;
    while (index)
    {
        if(index & 1) out = (out * base) % mod;
        base = (base*base) % mod;
        index >>= 1;
    }
    return out%mod;
}

long long rev(long long a,long long mod) { //mod下a的逆元
    long long x,y;
    long long gcd = exgcd(a,mod,x,y);
    while(x < 0) x += mod;
    return x;
}

int main() {
    long long x;
    long long rev_a = rev(2*166,MOD);
    while(cin>>x && x) {
        cout << ((qpow(2,2*x+1,MOD)-1) * (qpow(3,x+1,MOD)-1) * (qpow(167,x+1,MOD)-1) * rev_a) % MOD << endl;
    }
}