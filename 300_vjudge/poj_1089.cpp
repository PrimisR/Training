#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

struct Interval {
    int l;
    int r;
};

Interval interval[MAXN];

int cmp(Interval a,Interval b) {
    return a.l < b.l;
}


int main() {
    int n; cin>>n;
    for(int i=0;i<n;i++) {
        cin>>interval[i].l>>interval[i].r;
    }
    sort(interval,interval+n,cmp);
    int leftmost = interval[0].l;
    int rightmost = interval[0].r;
    for(int i=0;i<n;i++) {
        if(interval[i].l <= rightmost) {
            if(interval[i].r > rightmost) //大于才能更新
                rightmost = interval[i].r;
        }
        else {
            cout << leftmost << " " << rightmost << endl;
            leftmost = interval[i].l;
            rightmost = interval[i].r;
        }
    }
    cout << leftmost << " " << rightmost << endl;
    return 0;
}