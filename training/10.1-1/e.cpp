/**
 * 实际上不需要链式结构，只需要输出度数为1的点即可
 * 图形分为两种，一种是一条链，一种是以一个点为根的多条链
 * */

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int degree[100001];
vector<int> post_node[100001];
vector<int> degree_1;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n) {
        int count=0;
        int root=0;
        for(int i=1;i<=n;i++) {
            degree[i]=0;
            post_node[i].clear();
        }
        degree_1.clear();

        for(int i=1;i<=n-1;i++) {
            int a,b; cin>>a>>b;
            post_node[a].push_back(b);
            post_node[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        for(int i=1;i<=n;i++) {
            if(degree[i]>2) {
                root=i;
                count++;
            }
            else if(degree[i]==1) {
                degree_1.push_back(i);
            }
        }
        if(count>1) cout<<"No"<<endl;
        else {
            cout<<"Yes"<<endl;
            if(count==0) root=degree_1.front();
            cout<<post_node[root].size()<<endl;
            if(degree_1.size()==2) cout<<degree_1[0]<<" "<<degree_1[1]<<endl;
            else {
                for(int i=0;i<degree_1.size();i++) {
                    cout<<root<<" "<<degree_1[i]<<endl;
                }
            }
        }
    }
}