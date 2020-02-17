#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int a[1010];
    while(scanf("%d",&n)!=EOF)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<=35)
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}