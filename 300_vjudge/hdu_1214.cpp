#include <cstdio>

int main()
{
    int n;
    while(scanf("%d" , &n)!=EOF)
    {
        int t = n/2;
        int ans = t*(t-1)/2;
        int tt = n-t;
        ans += tt * (tt-1) / 2;
        printf("%d\n" , ans);
    }
    return 0;
}