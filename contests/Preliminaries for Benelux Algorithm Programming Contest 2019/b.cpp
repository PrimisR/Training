#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

const int MOD = 1000000007;

int to_num(string str) {
    int out = 0;
    for(int i=0;i<str.length();i++) {
        out *= 10;
        out += (int)(str[i]-'0');
    }
    return out;
}

int main() {
    stack<char> b;
    stack<int> result;
    int n; cin>>n;
    result.push(1);
    result.push(0);
    b.push('(');
    string input;
    for(int i=1;i<=(n+1);i++) {
        int num;
        if(i != n+1) cin>>input;
        else input = ")";
        if(input[0] != '(' && input[0] != ')') {
            bool is_plus = (b.size() % 2 == 1);
            num = to_num(input);
            int t = result.top(); result.pop();
            if(is_plus) {
                result.push((t+num)%MOD);
            }
            else {
                long long in = (long long)t * (long long)num;
                result.push((int)(in%MOD));
            }
        }
        else {
            if(input[0] == '(') {
                b.push('(');
                bool is_plus = (b.size() % 2 == 1);
                if(is_plus) {
                    result.push(0);
                }
                else {
                    result.push(1);
                }
            }
            else {
                b.pop();
                bool is_plus = (b.size() % 2 == 1);
                int t1 = result.top(); result.pop();
                int t2 = result.top(); result.pop();
                if(is_plus) {
                    int in = (t1+t2) % MOD;
                    result.push(in);
                }
                else {
                    long long in = (long long)t1 * (long long)t2;
                    result.push((int)(in%MOD));
                }
            }
        }
    }
    cout << result.top() << endl;
    return 0;
}