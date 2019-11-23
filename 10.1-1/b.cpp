#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map<int,int> a_to_x;

int main()
{
    int n,m;
    while(cin>>n) {
        a_to_x.clear();
        for(int i=1;i<=n;i++) {
            int a,x; cin>>a>>x;
            if(!a_to_x.count(a)) {
                a_to_x[a]=x;
            }
        }
        cin>>m;
        for(int i=1;i<=m;i++) {
            int a,x; cin>>a>>x;
            if(!a_to_x.count(a)) {
                a_to_x[a]=x;
            }
            else if(a_to_x[a]<x) {
                a_to_x[a]=x;
            }
        }
        long long total=0;
        for(map<int,int>::iterator it=a_to_x.begin();it!=a_to_x.end();it++) {
            pair<int,int> p=(*it);
            total+=(p.second);
        }
        cout<<total<<endl;
    }
}