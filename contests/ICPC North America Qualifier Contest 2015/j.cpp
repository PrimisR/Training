#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

const int maxn = 40;
const bool DEBUG = 0;

map<string,int> m;
string t[maxn];
bool visited[maxn];
vector<int> g[maxn];
int id = 0;
int st,ed;
vector<int> route;

void add_edge(string a,string b) {
    int ida = m[a];
    int idb = m[b];
    g[ida].push_back(idb);
    g[idb].push_back(ida);
}

void dfs(int pa,int cur) {
    if(cur == ed) {
        for(int i=0;i<route.size();i++) {
            cout << t[route[i]];
            if(i != route.size()-1) cout << " ";
            else cout << endl;
        }
        exit(0);
    }
    for(int i=0;i<g[cur].size();i++) {
        if(g[cur][i] == pa && visited[g[cur][i]]) continue;
        route.push_back(g[cur][i]);
        visited[g[cur][i]] = true;
        dfs(cur,g[cur][i]);
        route.pop_back();
        visited[g[cur][i]] = false;
    }
}

int main() {
    int n;
    cin >> n;
    getchar();
    for(int loop = 1;loop <= n; loop++) {
        string line;
        getline(cin,line);
        stringstream ss(line);
        vector<string> split;
        string str;
        while(ss>>str) {
            split.push_back(str);
        }
        if(DEBUG) {
            for(int i=0;i<split.size();i++) {
                cout << split[i] << " ";
            }
            cout << endl;
        }
        for(int i=0;i<split.size();i++) {
            if(m.count(split[i]) == 0) {
                m[split[i]] = id;
                t[id] = split[i];
                id++;
            }
        }
        for(int i=1;i<split.size();i++) {
            add_edge(split[0],split[i]);
        }
    }
    string sts,eds;
    cin>>sts>>eds;
    if(m.count(sts) == 0) {
        m[sts] = id;
        t[id] = sts;
        id++;
    }
    if(m.count(eds) == 0) {
        m[eds] = id;
        t[id] = eds;
        id++;
    }
    st = m[sts];
    ed = m[eds];
    route.push_back(st);
    visited[st] = true;
    dfs(-1,st);
    cout << "no route found" << endl;
    return 0;
}