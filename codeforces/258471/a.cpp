#include <cstdio>
#include <iostream>

using namespace std;

char encode(char c, int shift) {
    return (c-'a'+shift)%26+'a';
}

char decode(char c, int shift) {
    return (c-'a'-shift+26)%26+'a';
}

int main() {
    char c;
    string s;
    int shift;
    cin>>c>>shift>>s;
    if(c=='E')
        for(int i=0;i<s.length();i++) {
            s[i]=encode(s[i],shift);
        }
    else
        for(int i=0;i<s.length();i++) {
            s[i]=decode(s[i],shift);
        }   
    cout<<s<<endl;
    return 0;
}