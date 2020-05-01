#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin>>n;
    string a,b;
    int game = 0;
    while(n--) {
        cin>>a>>b;
        int pa = a.length()-1;
        int pb = b.length()-1;
        while(pa>=1 && pb>=1) {
            if(a[pa] == b[pb]) {
                pa--;
                pb--;
            }
            else break;
        }
        cout << "Game #" << ++game << ":" << endl;
        cout << "   The input words are " << a << " and " << b << "." << endl;
        cout << "   The words entered in the notebook are ";
        for(int i=0;i<=pa;i++) cout << a[i];
        cout << " and ";
        for(int i=0;i<=pb;i++) cout << b[i];
        cout << "." << endl;
        cout << endl;
    }
    return 0;
}