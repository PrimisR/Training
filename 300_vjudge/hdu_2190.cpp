#include<stdio.h>
int main()
{
    int a[31]={0,1,3,5};
    int T,n;
    for(int i = 4;i<31;i++)
    {
        a[i]=a[i-1]+a[i-2]*2;
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}
