#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
int n;
LL a[60][60];
void judge()
{
    a[0][0]=1;
    a[1][1]=a[1][0]=1;
    for(int i=2;i<=60;i++)
    {
        a[i][0]=1,a[i][i]=1;
        for(int j=1;j<i;j++)
        {
            a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
    }/*
    for(int i=1;i<=25;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%d ",a[i][j]);
        }
         printf("\n");
    }*/
}
int main()
{
    judge();
    while(~scanf("%d",&n))
    {
        LL sum=0;
        for(int i=1;;i++)
        {
            if((i-1)*3+1>n)break;
            int x=n-2*(i-1);
            sum+=a[x][i];
        }
        printf("%I64d\n",sum);
    }
    return 0;
}