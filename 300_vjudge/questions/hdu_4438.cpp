#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       double x,y,p,q;
       scanf("%lf%lf%lf%lf",&x,&y,&p,&q);
       double tiger= q*p*(x+y) + (1-q)*x;
       double wolf= q*y + (1-q)*p*(x+y);
       if(tiger> wolf)
          printf("tiger %.4lf\n",tiger);
       else
          printf("wolf %.4lf\n",wolf);
    }
    return 0;
}