/**
 * 三分函数
 * */
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double t1,t2;
    int n;
    cin>>n;
    double H,h,D;
    for(int i=1;i<=n;i++)
    {
        cin>>H>>h>>D;
        if(H>h+D) printf("%.3f\n",h);
        if(H*H>(H-h)*D&&H<=h+D) printf("%.3f\n",H+D-2*sqrt((H-h)*D));
        if(H*H<=(H-h)*D) printf("%.3f\n",h*D/H);
    }
    return 0;
}