#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int on[2001];
bool matrix[2001][2001];

bool check(int n,int m) 
{
    int fail=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int b=(matrix[i][j])? 1:0;
            if(on[j]==b) {
                fail++;
                break;
            }
        }
    }
    if(fail==n) return false;
    return true;
}

int main()
{
    int n,m;
    while(cin>>n>>m) {
        getchar();
        for(int i=0;i<2001;i++) on[i]=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                char b; cin>>b;
                b=b-'0';
                matrix[i][j]=(b==1)? true:false;
                on[j]+=b;
            }
            getchar();
        }
        string str=(check(n,m))? "YES" : "NO";
        cout<<str<<endl;
    }
    return 0;
}