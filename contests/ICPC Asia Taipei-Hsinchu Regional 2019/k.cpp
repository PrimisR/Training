#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2005;

struct node {
    int id;
    int val;
    node(int id,int val):id(id),val(val){}
    node(){}
    bool operator< (const node o) const {
        return this->val > o.val;
    }
};

node pool[MAXN];
int tot;

void init_pool() {
    tot = 0;
}

int new_node(int val) {
   pool[tot] = node(tot,val);
   return tot++;
}

int main() {
    int T; cin>>T;
    while(T--) {
        init_pool();
        int n; cin>>n;
        int ans = 0;
        priority_queue<node> pq;
        for(int i=0;i<n;i++) {
            int val; cin>>val;
            int ptr = new_node(val);
            pq.push(pool[ptr]);
        }
        while(pq.size() > 1) {
            node u = pq.top(); pq.pop();
            node v = pq.top(); pq.pop();
            ans += u.val + v.val;
            int ptr = new_node(u.val+v.val);
            pq.push(pool[ptr]);
        }
        cout << ans << endl;
    }
}