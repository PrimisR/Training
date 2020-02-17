#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int t, a, b, c, i, ans;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d", &a, &b, &c);
        int left = 1000, right = 9999, flag = 0;
        for (i = left; i <= right; i++)
        {
            if (i % a != 0)
                continue;
            if ((i + 1) % b != 0)
                continue;
            if ((i + 2) % c != 0)
                continue;
            flag = 1;
            ans = i;
            break;
        }
        if (flag)
            printf("%d\n", ans);
        else
            printf("Impossible\n");
    }
    return 0;
}