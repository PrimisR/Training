#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    char a[10][10];
    char s[20];
    int i, j;
    int r, c;
    while (scanf("%s", s) && strcmp(s, "ENDOFINPUT") != 0)
    {
        scanf("%d%d%*c", &r, &c);
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                scanf("%c", &a[i][j]);
            }
            getchar();
        }
        scanf("%s", s);
        for (i = 0; i < r - 1; i++)
        {
            for (j = 0; j < c - 1; j++)
            {
                printf("%d", (int)((double)(a[i][j] - '0' + a[i][j + 1] - '0' + a[i + 1][j] - '0' + a[i + 1][j + 1] - '0') / 4.0));
            }
            printf("\n");
        }
    }
    return 0;
}