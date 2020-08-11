#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<math.h>
#include <algorithm>
using namespace std;
#define ll long long
#define lll __int64
#define inf 0x3f3f3f3f
#define mem(A,B) memset(A,B,sizeof(A))
 
int T,n,x;
ll sum,ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans=0;
        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum+=x;
            ans=max(ans,(sum+i-1)/i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}