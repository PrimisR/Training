#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    while(k--) {
        stack<int> s;
        queue<int> q;
        int required = 1;
        for(int i=0;i<n;i++) {
            int c;cin >> c;
            q.push(c);
        }
        bool fail = false;
        while(!q.empty()) {
            int num = q.front(); q.pop();
            if(num != required) s.push(num);
            if(s.size() > m) {
                fail = true;
                break;
            }
            if(num == required) {
                required++;
                while(!s.empty()) {
                    if(s.top() == required) {
                        required++;
                        s.pop();
                    }
                    else break;
                }
            }
        }
        if(!s.empty()) fail = true;
        if(fail) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}