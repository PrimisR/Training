#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n;
    while(cin>>n && n) {
        if(n%4 == 0 || (n+1)%4 == 0) {
            cout << "Y" << endl;
        }
        else {
            cout << "N" << endl;
        }
    }
    return 0;
}