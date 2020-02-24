#include <stdio.h>

long powermod(long a, long n, long m)
{
    long res = 1L;
    while(n) {
        if(n & 1L) {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        n >>= 1;
    }
    return res;
}

int main(void)
{
    long a, n;
    for(;;) {
        scanf("%ld %ld", &a, &n);
        if(a==0 && n==0)
            break;
        printf("%ld\n", powermod(a, n, 1000L));
    }

    return 0;
}