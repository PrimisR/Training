#include <cstdio>
#include <iostream> 
#include <vector>
#include <cmath>

using namespace std;

int aarr[40005];
int barr[40005];
vector<int> seg_a;
vector<int> seg_b;
vector<int> factor;

int main() {
    int alen,blen,k;
    cin>>alen>>blen>>k;
    int len = 0;
    for(int i=0;i<alen;i++) {
        cin>>aarr[i];
        if(aarr[i] == 1) len++;
        else {
            seg_a.push_back(len);
            len = 0;
        }
    }
    if(len != 0) seg_a.push_back(len);
    len = 0;
    for(int i=0;i<blen;i++) {
       cin>>barr[i];
        if(barr[i] == 1) len++;
        else {
            seg_b.push_back(len);
            len = 0;
        }
    }
    if(len != 0) seg_b.push_back(len);

    for(int i=1;i<=sqrt(k);i++) {
        if(k % i == 0) factor.push_back(i);
    }

    int fs = factor.size();

    for(int i=fs-1;i>=0;i--) {
        int a = k/factor[i];
        if(a != factor[i]) factor.push_back(a);
    }

    long long total = 0;
    for(int i=0;i<factor.size();i++) {
        int a = factor[i];
        int b = factor[factor.size()-1-i];
        long long a_total = 0;
        long long b_total = 0;
        for(int j=0;j<seg_a.size();j++) {
            int upd = 0;
            if(seg_a[j] < a) upd = 0;
            else {
                upd = seg_a[j] - a + 1;
            }
            a_total += upd;
        }
        for(int j=0;j<seg_b.size();j++) {
            int upd = 0;
            if(seg_b[j] < b) upd = 0;
            else {
                upd = seg_b[j] - b + 1;
            }
            b_total += upd;
        }
        total += a_total * b_total;
    }
    cout << total << endl;
    return 0;
}