#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int x,y;
    cin>>x>>y;
    cout << 5000 - (x*y)/2 - (100-y)*(100-x)/2 - (100-x)*y << endl;
    return 0;
}