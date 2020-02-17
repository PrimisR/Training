#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n,k; cin>>n>>k;
    vector<int> s;
    while(n--) {
        int si; cin>>si;
        s.push_back(si);
    }
    sort(s.begin(),s.end(),greater<int>());
    int total = 0;
    for(int i=0;i<k;i++) {
        total += s[i];
    }
    cout << total << endl;
    return 0;
}