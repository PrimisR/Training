#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c;
        int sum, max;
        int x, y, z;
        scanf("%d%d%d", &a, &b, &c);
        scanf("%d%d%d", &x, &y, &z);
        sum = a * 1000 + b * 100 + c;
        max = x * 1000 + y * 100 + z;
        if (sum > max)
            printf("First\n");
        if (sum < max)
            printf("Second\n");
        if (sum == max)
            printf("Same\n");
    }
    return 0;
}