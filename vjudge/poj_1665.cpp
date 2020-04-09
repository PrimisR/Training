#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const double pi = 3.1415927;
 
int main(void)
{
    double t,d;
    int r;
    int vv = 0;
    while(scanf("%lf %d %lf",&d,&r,&t)!=EOF)
    {
       if(r==0)
        break;
        d /= (5280*12);
       double s = pi*d*r;
       double v = s*3600/t;
       printf("Trip #%d: %.2lf %.2lf\n",++vv,s,v);
    }
    return 0;
}