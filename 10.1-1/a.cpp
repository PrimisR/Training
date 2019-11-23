/**
 * 不是回文，输出len
 * 是回文，同一字母输出0，不同字母输出len-1
 * */

#include <cstdio>
#include <iostream>
#include <string>
#include <set>

using namespace std;

string s;
set<char> unique_char;

int is_palindrome() {
    int len=s.length();
    for(int i=0;i<len/2+1;i++) {
        if(s[i]!=s[len-i-1]) return len;
        unique_char.insert(s[i]);
    }
    if(unique_char.size()==1) return 0;
    return len-1;
}

int main()
{
    while(cin>>s) {
        unique_char.clear();
        cout<<is_palindrome()<<endl;
    }
    return 0;
}