#include <iostream>
#include <cstdio>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

int main() {
    int x;
    while(cin>>x && x) {
        cout << lowbit(x) << endl;
    }
}