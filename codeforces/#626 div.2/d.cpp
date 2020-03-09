#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

unsigned int arr[400005];

long long cnt(int l,int r,vector<unsigned int> &v) {
    int pl = v.size()-1, pr = v.size()-1;long long total = 0;
    for(int i=0;i<v.size();i++) {
        while(pl >= 0 && v[i]+v[pl] >= l) pl--;
        while(pr >= 0 && v[i]+v[pr] > r) pr--;
        if(pr <= i) break;
        total += (pr - max(pl,i));
    }
    return total;
}

int main() {
    int n; cin>>n;
    unsigned int answer = 0;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int k=0;k<32;k++) {
        vector<unsigned int> v;
        for(int i=0;i<n;i++) v.push_back(arr[i]%(1<<(k+1)));
        sort(v.begin(),v.end());
        long long total = cnt((1<<k),(1<<(k+1))-1,v) + cnt((1<<k)*3,(1<<(k+2))-2,v);
        if(total & 1) 
            answer |= (1<<k);
    }
    cout << answer << endl;
    return 0;
}