#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    //freopen("t.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int h, m;
        scanf("%d:%d", &h, &m);
        if (m)
            printf("0\n");
        else
            printf("%d\n", (h + 36 - 1) % 24 + 1);
    }
    return 0;
}