#include<iostream>
#include<vector>
#include<map>
#include<string.h>
using namespace std;
#define mian main
int a,b,m,n;
int ar[100010];
int mian()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(ar,0,sizeof(ar));
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        ar[a]++;
        ar[b]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(ar[i]==1)
            ans++;
    cout<<ans<<endl;
    return 0;
}