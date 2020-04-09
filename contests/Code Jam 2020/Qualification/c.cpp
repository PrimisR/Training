#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1005;

struct itvl {
    int input;
    int l;
    int r;
};

itvl t[N];
vector<int> c;
vector<int> j;
char ans[N];

bool itrsct(itvl a,itvl b) {
    return (a.l < b.r && b.l < a.r);
}

int cmp(itvl a,itvl b) {
    return a.l < b.l;
}

bool valid_c(int ptr) {
    for(int i=0;i<c.size();i++) {
        if(itrsct(t[ptr],t[c[i]])) return false;
    }
    return true;
}

bool valid_j(int ptr) {
    for(int i=0;i<j.size();i++) {
        if(itrsct(t[ptr],t[j[i]])) return false;
    }
    return true;
}

int main() {
    int T; cin>>T;
    int CASE = 0;
    while (T--)
    {
        int n; cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>t[i].l>>t[i].r;
            t[i].input = i;
        }
        sort(t+1,t+n+1,cmp);
        c.clear(); j.clear();
        bool impossible = false;
        for(int i=1;i<=n;i++) {
            if(valid_c(i)) {
                c.push_back(i);
                ans[t[i].input] = 'C';
            }
            else if(valid_j(i)){
                j.push_back(i);
                ans[t[i].input] = 'J';
            }
            else {
                impossible = true;
                break;
            }
        }
        if(impossible) {
            cout << "Case #" << ++CASE << ": IMPOSSIBLE" << endl;
        }
        else {
            cout << "Case #" << ++CASE << ": ";
            for(int i=1;i<=n;i++) {
                cout << ans[i];
            }
            cout << endl;
        }
    }
    return 0;
}