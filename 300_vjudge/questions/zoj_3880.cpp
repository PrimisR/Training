#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int map[900000];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int an = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            if (a > 6000)
            {
                an++;
            }
        }
        printf("%d\n", an);
    }
    return 0;
}