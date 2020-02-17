#include <iostream>
#include <cstdio>
using namespace std;

int sqr[101];

int main() {
    for(int i=0;i<=100;i++) sqr[i] = i*i;
    int n;
    while(cin>>n && n) {
        int total = 0;
        while(n--) {
            int k; cin>>k;
            total += sqr[k];
        }
        cout << total << endl;
    }
}