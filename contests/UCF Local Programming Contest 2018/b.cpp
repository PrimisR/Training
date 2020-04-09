#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 1500000;
vector<int> duplicate[30];
int cnt[26];

struct node {
    bool word;
    int id;
    int son[26];
};

node trie[MAXN];
int root,id;

long long A2(int n) {
    return (long long)n*(n-1);
}

void init() {
    root = 1;
    id = 1;
    for(int i=0;i<MAXN;i++) {
        for(int j=0;j<26;j++) {
            trie[i].word = false;
            trie[i].son[j] = 0;
        }
    }
}

int new_tree() {
    return ++id;
}

void insert(string &str,int depth,int u) {
    if(depth == str.length()) {
        int k = str[0]-'A';
        if(trie[u].word) {
            duplicate[k][trie[u].id]++;
        }
        else {
            trie[u].word = true;
            duplicate[k].push_back(1);
            trie[u].id = duplicate[k].size()-1;
        }
        return;
    }
    int x = str[depth]-'A';
    trie[u].son[x] = (trie[u].son[x] == 0)? new_tree() : trie[u].son[x];
    insert(str,depth+1,trie[u].son[x]);
}

int main() {
    //freopen("C:\\Users\\hp\\Desktop\\VS Code\\contests\\UCF Local Programming Contest 2018\\sga100.in","r",stdin);
    //freopen("C:\\Users\\hp\\Desktop\\VS Code\\contests\\UCF Local Programming Contest 2018\\sga100.out","w",stdout);
    int n;
    cin>>n;
    while(n--) {
        string str;
        cin>>str;
        cnt[str[0]-'A']++;
        insert(str,0,root);
    }
    long long total = 0;
    for(int i=0;i<26;i++) {
        total += A2(cnt[i]);
        for(int j=0;j<duplicate[i].size();j++) {
            total -= A2(duplicate[i][j]);
        }
    }
    // for(int i=0;i<26;i++) {
    //     for(int j=0;j<duplicate[i].size();j++) {
    //         cout << duplicate[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << total << endl;
    return 0;
}