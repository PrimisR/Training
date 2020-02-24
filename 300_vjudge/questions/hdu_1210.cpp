#include <cstdio>

int main()
{
    int n;
    while(scanf("%d" , &n)!=EOF)
    {
        int k = 2 , ans = 1;
        while(k != 1){
            if( k <= n ) k <<= 1;
            else k = (k - n)*2-1;
            ans++;
        }
        printf("%d\n" , ans);
    }
    return 0;
}