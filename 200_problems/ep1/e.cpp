#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

bool prime[40];
bool visited[20];
int n;

vector<int> v;

void init() {
    for(int i=0;i<40;i++) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i=2;i<40;i++) {
        if(prime[i] == false) continue;
        for(int j=i+i;j<40;j+=i) {
            prime[j] = false;
        }
    } 
    v.push_back(1);
    visited[1] = true;
}

void dfs() {
    if(v.size() == n) {
        if(!prime[v[v.size()-1]+1]) return;
        for(int i=0;i<v.size();i++) {
            cout<<v[i];
            if(i!=v.size()-1) cout<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=2;i<=n;i++) {
        if(visited[i]) continue;
        if(prime[v[v.size()-1]+i]) {
            v.push_back(i);
            visited[i] = true;
            dfs();
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    int case_count = 0;
    init();
    while(cin>>n) {
        case_count++;
        if(case_count != 1) cout<<endl;
        cout<<"Case "<<case_count<<":"<<endl;
        for(int i=2;i<=n;i++) visited[i] = false;
        dfs();
    }
}