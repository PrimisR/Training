#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    long long n; cin>>n;
    long long a = -1;
    long long b = -1;
    if(n % 4 == 0) {
        a = (n/2+2)/2;
        b = (n/2-2)/2;
    }
    else if(n % 2 == 1) {
        a = (n+1)/2;
        b = (n-1)/2;
    }
    if(a == -1 && b == -1) {
        cout << "impossible" << endl;
    }
    else {
        cout << a << " " << b << endl;
    }
    return 0;
}