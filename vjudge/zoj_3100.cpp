#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[105];
int main()
{
    int n,i;
    double s,avg;
    int ans;
    while(scanf("%d",&n)&&n)
    {
        s=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(i=1;i<n-1;i++)
        {
            s+=a[i];
        }
        avg=double(s)/double(n-2);
        ans=floor(avg);
        printf("%d\n",ans);
    }
    return 0;
}