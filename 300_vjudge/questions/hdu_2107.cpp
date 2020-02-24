#include <stdio.h>

int main()

{

    int a[1000], m, i, j, t;

    while (scanf("%d", &m), m)

    {

        for (i = 0; i < m; i++)

        {

            scanf("%d", &a[i]);
        }

        for (i = 0; i < m; i++)

        {

            for (j = i + 1; j < m; j++)

            {

                if (a[i] < a[j])

                {

                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }

        printf("%d\n", a[0]);
    }

    return 0;
}