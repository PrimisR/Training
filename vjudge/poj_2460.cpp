#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int po[201000][2];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int x,y,m;
        m=(n+1)/2;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&po[i][0],&po[i][1]);
        x=po[m][0],y=po[m][1];
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++)
        {
            int tx=po[i][0],ty=po[i][1];
            if((tx>x&&ty>y)||(tx<x&&ty<y))
                cnt1++;
            else if((tx>x&&ty<y)||(tx<x&&ty>y))
                cnt2++;
        }
        printf("%d %d\n",cnt1,cnt2);
    }
    return 0;
}