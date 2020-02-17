/**
 * 树 node(i,ai)
 * 统计该结点子树下比ai小的结点,总个数是ci
 * 现在给定ci和树本身，要求构造ai
 * 
 * 构造方法:给这些结点分配1到n，用vector存储，
 * 那么每次到这个结点就拿走vector[c],然后把剩下数字分给他的孩子们
 * 也就是第c大的那个数字
 * stdlib.h exit(0)退出dfs的好方法
 * */

#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>

using namespace std;

const int MAXN = 2005;

struct node {
    int p;
    int c;
    int a;
    vector<int> child;
    int sub;
    node():sub(0){}
};

node tn[MAXN]; //tree node
int root;

void dfs(int cur,vector<int> options) {
    if(tn[cur].c > tn[cur].sub) {
        cout << "NO" << endl;
        exit(0);
    }
    tn[cur].a = options[tn[cur].c];
    int i=0;
    vector<int> subop;
    for(int j=0;j<options.size();j++) {
        if(j == tn[cur].c) continue;
        subop.push_back(options[j]);
        if(subop.size() == tn[tn[cur].child[i]].sub+1) {
            dfs(tn[cur].child[i],subop);
            subop.clear(); i++;
        }
    }
}

int main() {
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>tn[i].p>>tn[i].c;
        tn[tn[i].p].child.push_back(i);
        if(tn[i].p == 0) root = i;
    }
    for(int i=1;i<=n;i++) {
        for(int p=tn[i].p;p!=0;p=tn[p].p) {
            tn[p].sub++;
        }
    }
    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back(i);
    dfs(root,v);
    cout << "YES" << endl;
    for(int i=1;i<=n;i++) {
        cout << tn[i].a;
        if(i != n) cout << " ";
        else cout << endl;
    }
    return 0;
}