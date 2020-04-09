#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int map[16][30][30];
int main()
{
    memset(map, 0, sizeof(map));
    map[0][15][15] = 1;
    int i, j, k, t, ans;
    for (i = 1; i <= 15; i++)
        for (j = 1; j <= 30; j++)
            for (k = 1; k <= 30; k++)
                map[i][j][k] = map[i - 1][j][k - 1] + map[i - 1][j][k + 1] + map[i - 1][j - 1][k] + map[i - 1][j + 1][k] + map[i - 1][j - 1][k - 1] + map[i - 1][j + 1][k + 1];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &ans);
        printf("%d\n", map[ans][15][15]);
    }
    return 0;
}