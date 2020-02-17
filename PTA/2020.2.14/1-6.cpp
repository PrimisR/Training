#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--) {
        string s;
        cin>>s;
        int first=0,last=0;
        for(int i=0;i<=2;i++) {
            first += s[i] - '0';
        }
        for(int i=3;i<=5;i++) {
            last += s[i] - '0';
        }
        if(first == last) {
            cout << "You are lucky!" << endl;
        }
        else {
            cout << "Wish you good luck." << endl;
        }
    }
    return 0;
}