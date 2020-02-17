/**
 * 最小生成树
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream>
#include <string>

using namespace std;

const int MAXN = 30;

struct edge {
    int st;
    int ed;
    int val;
    edge(){}
    edge(int st,int ed,int val):st(st),ed(ed),val(val){}
};

edge edges[3000];

int cmp(edge a,edge b) {
    return a.val < b.val;
}

int father[MAXN];

void init() {
    for(int i=0;i<=MAXN;i++) {father[i] = i;}
}

int find(int a) {
    return (father[a] == a)? a : father[a] = find(father[a]);
}

void unify(int a,int b) {
    int a_fa = find(a);
    int b_fa = find(b);
    if(a_fa != b_fa) father[b_fa] = a_fa;
}

int count(int n) {
    set<int> s;
    for(int i=0;i<=n;i++) {
        father[i] = find(i);
        s.insert(father[i]);
    }
    return s.size();
}

int main() {
    int n;
    while(cin>>n && n) {
        getchar();
        init();
        int total = 0;
        for(int i=0;i<(n-1);i++) {
            char st; int k;
            cin>>st>>k;
            while(k--) {
                char ed; int val;
                cin>>ed>>val;
                edges[total++] = edge(st-'A',ed-'A',val);
            }
        }
        sort(edges,edges+total,cmp);
        int acm = 0,road = 0;
        for(int i=0;i<total;i++) {
            edge e = edges[i];
            if(find(e.st) == find(e.ed)) continue;
            acm+=e.val; road++;
            unify(e.st,e.ed);
            if(road == n-1) break;
        }
        cout << acm << endl;
    }
    return 0;
}