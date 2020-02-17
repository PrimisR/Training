#include <cstdio>
int main()
{
    int n, m;
    int x, y;
    while(~scanf("%d%d%d%d",&n,&m,&x,&y))
    {
        if(x*2==n && y*2==m)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}