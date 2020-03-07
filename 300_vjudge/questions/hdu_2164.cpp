#include <stdio.h>
int main()
{
    int n;
    char f[5] = {'P', 'R', 'S', 'P'};
    while (scanf("%d", &n) != EOF)
    {
        while (n--)
        {
            int m;
            scanf("%d", &m);
            int s1 = 0, s2 = 0;
            char a, b;
            while (m--)
            {
                getchar();
                scanf("%c %c", &a, &b);
                int i;
                for (i = 0; i <= 3; i++)
                {
                    if (a == f[i] && b == f[i + 1])
                        s1 += 1;
                    if (a == f[i + 1] && b == f[i])
                        s2 += 1;
                }
            }
            if (s1 > s2)
                printf("Player 1\n");
            if (s2 > s1)
                printf("Player 2\n");
            if (s1 == s2)
                printf("TIE\n");
        }
    }
    return 0;
}