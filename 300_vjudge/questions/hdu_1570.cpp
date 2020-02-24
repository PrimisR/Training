#include <stdio.h>

#define N 10
long long fact[N + 1];

void init()
{
    int i;
    fact[1] = fact[0] = 1;
    for(i = 2; i <= N; i++)
        fact[i] = fact[i - 1] * i;
}

int main(void)
{
    init();

    int t, n, m;
    char c;

    scanf("%d%*c", &t);
    while(t--) {
        scanf("%c%d%d%*c", &c, &n, &m);
        long long a = fact[n] / fact[n - m];
        printf("%lld\n", c == 'A' ?  a : a / fact[m]);
    }

    return 0;
}