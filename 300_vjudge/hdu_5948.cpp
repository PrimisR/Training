#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int a,b;
        cin>>a>>b;
        cout<<a+b+max(a,b)<<endl;
    }
}