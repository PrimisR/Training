#include <iostream>
#include <cstdio>

using namespace std;

int mp[1300][1300];

int main() {
    int n;
    cin>>n;
    int num=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mp[3*n-i+1][j]=6*n*n-num+1;
            mp[i][j]=num++;
        }
    }
    for(int i=n+1;i<=n*2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mp[i][n*3-j+1]=6*n*n-num+1;
            mp[i][j]=num++;
        }
        for(int j=n+1;j<=2*n;j++)
        {
            mp[i][n*5-j+1]=6*n*n-num+1;
            mp[i][j]=num++;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            printf("%d%c",mp[i][j],j==n?'\n':' ');
    for(int i=n+1;i<=n*2;i++)
        for(int j=1;j<=4*n;j++)
            printf("%d%c",mp[i][j],j==n*4?'\n':' ');
    for(int i=n*2+1;i<=n*3;i++)
        for(int j=1;j<=n;j++)
            printf("%d%c",mp[i][j],j==n?'\n':' ');
}
//CSDN