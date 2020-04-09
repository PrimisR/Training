#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 2000005;

struct node {
    int count;
    int son[26];
};

node trie[MAXN];

int T,n,k;

int root,id,total;

void init() {
    total = 0;
    root = 1;
    id = 1;
    for(int i=0;i<MAXN;i++) {
        for(int j=0;j<26;j++) {
            trie[i].count = 0;
            trie[i].son[j] = 0;
        }
    }
}

int new_tree() {
    return ++id;
}

void insert(string &str,int depth,int u) {   
    trie[u].count++;
    if(depth == str.length()) return;
    int x = str[depth] - 'A';
    trie[u].son[x] = (trie[u].son[x] == 0)? new_tree() : trie[u].son[x];
    insert(str,depth+1,trie[u].son[x]);
}

int dfs(int u,int depth) {
    int sgroup = 0;
    for(int i=0;i<26;i++) {
        if(trie[u].son[i] == 0) continue;
        int son = trie[u].son[i];
        if(trie[son].count >= k)
            sgroup += dfs(son,depth+1);
    }
    int ugroup = (trie[u].count - sgroup*k) / k;
    total += ugroup*depth;
    return ugroup+sgroup;
}

int main() {
    cin>>T;
    int CASE = 0;
    while(T--) {
        init();
        cin >> n >> k;
        for(int i=1;i<=n;i++) {
            string str;
            cin>>str;
            insert(str,0,root);
        }
        if(k == 1) total = 0;
        else dfs(root,0);
        cout << "Case #" << ++CASE << ": " << total << endl;
    }
    return 0;
}