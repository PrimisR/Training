#include <cstdio>
#include <cmath>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int s1,s2;
        int a1,b1,p,a=0,b=0,s,t;   //a1,b1表示颠倒之后的值，a,b为原来的值，
        scanf("%d%d",&s1,&s2);
        {
            a1=(s1+s2)/2;         //求颠倒之后的a1的值
            b1=s1-a1;             //求颠倒之后的b1的值
        }
        while(a1)                //求a,b的原值
        {
            p=a1%10;
            a=10*a+p;
            a1=a1/10;
        }
        while(b1)
        {
            p=b1%10;
            b=10*b+p;
            b1=b1/10;
        }
        s=a+b;
        t=a-b;
        printf("%d %d\n",s,t);
    }
    return 0;
}