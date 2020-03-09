#include <iostream>
#include <cstdio>
#define ll long long
#define mod 1000000007
using namespace std;
int a[100005];
int main()
{
    int t, n, i, j, aa, bb, x;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        aa = bb = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if (x % 2)
                aa++;
            else
                bb++;
        }
        if (aa >= bb)
            i = 1;
        else
            i = 0;
        printf("2 %d\n", i);
    }
}