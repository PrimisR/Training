#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct val {
    int v;
    int nv;
    int k;
    val(int v,int nv,int k):v(v),nv(nv),k(k){}
    val(){}
    bool operator< (const val o) const {
        return (this -> nv == o.nv)? this->k < o.k : this->nv < o.nv;
    }
};

int main() {
    int T; cin>>T;
    int CASE = 0;
    while(T--) {
        priority_queue<val> pq;
        int n,k; cin>>n>>k;
        int a; cin>>a;
        for(int i=2;i<=n;i++) {
            int na; cin>>na;
            pq.push(val(na-a,na-a,1));
            a = na;
        }
        while(k--) {
            val u = pq.top(); pq.pop();
            pq.push(val(u.v,(int)(ceil((double)u.v/(u.k+1))),u.k+1));
        }
        cout << "Case #" << ++CASE << ": " << pq.top().nv << endl;
    }
    return 0;
}
