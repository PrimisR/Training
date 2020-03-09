/**
 * stack
 * */
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int n;
    cin>>n;
    getchar();
    while(n) {
        char ch;
        stack<char> s;
        ch = getchar();
        while(ch != ' ' && ch != '\n') {
            s.push(ch);
            ch = getchar();
        }
        if(ch == '\n') n--;
        while(!s.empty()) {
            cout << s.top();
            s.pop();
        }
        putchar(ch);
    }
}