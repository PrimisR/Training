#include <stdio.h>
#define N 21

short f[N] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 
    987, 1597, 2584, 4181, 6765, 10946, 17711};
int main()
{
    short t = 0;
    short x = 0;
    short j = 0;
    short ans = 0;
    
    scanf ("%d", &t);
    while ( t-- )
    {
        scanf ("%d", &x);
        ans = 0;
        for ( j = N - 1; x > 1; --j)
        {
            if (f[j] <= x)
            {
                x -= f[j];
                ans += f[j - 1];
            }
        }

        printf ("%d\n", ans);
    }
    return 0;
}