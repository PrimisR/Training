#include <iostream>
using namespace std;

int main() {
    int a,b;
    while(cin>>a>>b) {
        if((a+b)%86) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
}