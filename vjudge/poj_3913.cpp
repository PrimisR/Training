#include <stdio.h>

int main(void)
{
    int n, a, b, c;
    scanf("%d", &n);
    puts("Gnomes:");
    while(n--) {
        scanf("%d%d%d", &a, &b, &c);
        printf("%s\n", (a >= b && b >= c) || (a <= b && b <=c) ? "Ordered" : "Unordered");
    }

    return 0;
}