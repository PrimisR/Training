#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
 
double a,b,c,d,e;
 
double jf(double px){
    return a*px*px*px/3+b*px*px/2+c*px-d*px*px/2-e*px;
}
 
int main(){
    int t;
    double p1x,p1y,p2x,p2y,p3x,p3y;
    double ans;
 
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf%lf%lf%lf",&p1x,&p1y,&p2x,&p2y,&p3x,&p3y);
        d=(p3y-p2y)/(p3x-p2x);
        e=p2y-d*p2x;
        if(p1x!=p2x){//经检验，数据中没有p1x==p2x的
            a=(p2y-p1y)/(p2x-p1x)/(p2x-p1x);
        }
        else{
            a=(p3y-p1y)/(p3x-p1x)/(p3x-p1x);
        }
        c=p1y+a*p1x*p1x;
        b=-2*p1x*a;
 
        ans=jf(p3x)-jf(p2x);
        printf("%.2lf\n",ans);//.2后四舍五入
    }
 
    return 0;
}