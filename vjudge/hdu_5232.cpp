#include <cstdio>
#include <iostream>
using namespace std;
int g[300][300];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>g[i][j];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j])
                {
                    ans++;
                    g[i][j]=0;
                    g[j][i]=0;
                }
            }
        }
        cout<<(ans+n)*2<<endl;
    }
}