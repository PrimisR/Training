#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a;
        scanf("%d", &a);
        if (a == 1 || a == 24)
            printf("Fake news!\n");
        else
            printf("Nobody knows it better than me!\n");
    }
    return 0;
}