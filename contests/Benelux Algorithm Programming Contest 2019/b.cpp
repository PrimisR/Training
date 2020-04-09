#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    if(n & 1) {
        cout << "Bob" << endl;
    }
    else {
        cout << "Alice" << endl;
        cout << "1" << endl;
    }
}