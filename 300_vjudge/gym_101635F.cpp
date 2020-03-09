#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    int m;
    while (cin >> n >> m)
    {
        int x, y;
        int sum = 0;
        while (m--)
        {
            scanf("%d%d", &x, &y);
            sum += x * y;
        }
        printf("%d\n", sum / n);
    }
    return 0;
}