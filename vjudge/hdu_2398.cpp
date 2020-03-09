#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    double a,r,tot;
     int cnt=0;
  while(scanf("%lf%lf%lf",&a,&r,&tot)!=EOF)
   {
         r/=100;
        while(tot-a>1.0e-8)
        {
            cnt++;
            a*=(r+1);
        }
        printf("%d\n",cnt);
        cnt=0;
    }
    return 0;
}