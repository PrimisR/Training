#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool is_useful[10];

bool check(int a) {
    if(a == 0 && !is_useful[0]) return false;
    while(a) {
        int digit = a%10;
        if(!is_useful[digit]) return false;
        a/=10;
    }
    return true;
}

int main() {
    vector<int> v;
    for(int i=0;i<=9;i++) {
        is_useful[i] = true;
    }
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int a; cin>>a;
        is_useful[a] = false;
    }
    cin>>m;
    for(int i=0;i<=999;i++) {
        if(check(i)) v.push_back(abs(i-m));
    }
    sort(v.begin(),v.end());
    cout << v[0] << endl;
    return 0;
}