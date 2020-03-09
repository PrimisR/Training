#include <stdio.h>

int main(void)
{
    double s1, s2, y, q, e, f, g;
    int n;
    while (scanf("%d", &n) == 1)
    {
        while (n--)
        {
            scanf("%lf%lf%lf%lf%lf", &y, &q, &e, &f, &g);
            if (q < 100)
            {
                s1 = y * (1 + e / 100 * q / 365);
                s1 = s1 * (1 + f / 100);
            }
            else if (q < 365)
            {
                s1 = y * (1 + e / 100 * q / 365);
                s1 = s1 * (1 + g / 100);
            }
            else if (q == 365)
            {
                s1 = y * (1 + f / 100);
                s1 = s1 * (1 + g / 100);
            }
            s2 = y * (1 + f / 100 * (q + 365) / 365);
            printf("%.1lf\n%.1lf\n", s1, s2);
        }
    }
    return 0;
}