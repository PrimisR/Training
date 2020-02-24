#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n, m, a, min, i;

    while (scanf("%d%d", &n, &m) != EOF)
    {
        min = INT_MAX;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &a);
            if (a < min)
                min = a;
        }

        printf("%d\n", m / min);
    }

    return 0;
}