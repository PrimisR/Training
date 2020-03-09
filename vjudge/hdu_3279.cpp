#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
 
int a[15];
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&cas);
        for(int i=0;i<10;i++)
            scanf("%d",&a[i]);
        sort(a,a+10);
        int i,cnt=1;
        for(i=8;i>=0;i--)
        {
            if(a[i]!=a[i-1])
            {
                cnt++;
                if(cnt==3)
                    break;
            }
        }
        printf("%d %d\n",cas,a[i]);
    }
}
