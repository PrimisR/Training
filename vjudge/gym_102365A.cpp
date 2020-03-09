#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    char op;
    int s;
    string str;
    cin>>op>>s>>str;
    if(op == 'D') s = -s;
    for(int i=0;i<str.length();i++) {
        cout<<(char)((str[i]-'a'+s+26)%26+'a');
    }
    cout << endl;
    return 0;
}