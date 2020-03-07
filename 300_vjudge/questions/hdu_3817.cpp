#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T; cin>>T;
    int ca = 0;
    while(T--) {
        ca++;
        int a,b,c; cin>>a>>b>>c;
        vector<int> e;
        e.push_back(a);
        e.push_back(b);
        e.push_back(c);
        sort(e.begin(),e.end());
        int c2 = e[2] * e[2];
        int a2b2 = e[0] * e[0] + e[1] * e[1];
        if(c2 > a2b2) {
            cout << "Case " << ca << ": Obtuse triangle" << endl;
        }
        else if(c2 < a2b2) {
            cout << "Case " << ca << ": Acute triangle" << endl;
        }
        else
        {
            cout << "Case " << ca << ": Right triangle" << endl;
        }
        
    }
}