/**
 * nim博弈板子
 * */
#include <iostream>
using namespace std;

int main() {
    int m;
    while(cin>>m && m) {
        int sum = 0;
        for(int i=0;i<m;i++) {
            int k; cin>>k;
            sum ^= k;
        }
        if(sum == 0) cout << "Grass Win!" << endl;
        else cout << "Rabbit Win!" << endl;
    }
}