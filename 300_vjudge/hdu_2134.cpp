#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main(void)
{
    double r, s, r1, r2;
    while(scanf("%lf", &r) != EOF && r) {
        s = PI * r * r;
        r1 = sqrt(s / 3.0 / PI);
        r2 = sqrt(s / 3.0 * 2.0 / PI);
        printf("%.3lf %.3lf\n", r1, r2);
    }

    return 0;
}