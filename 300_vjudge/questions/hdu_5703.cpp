#include <iostream>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        printf ("1");
        for (int i=0;i<n-1;i++)
            printf ("0");
        printf ("\n");
    }
    return 0;
}