#include <stdio.h>
 
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0){
        x=1;y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
 
int pow_mod(int a,int b,int c)
{
    int t=a%c, ans=1%c;
    while(b){
        if(b&1){
            ans=ans*t%c;
            b--;
        }
        b=b>>1;
        t=t*t%c;
    }
    return ans;
}
 
int decrypt(int c,int d,int n)
{
    int m=pow_mod(c,d,n);
    return m;
}
 
int main()
{
    //freopen("in.txt","r",stdin);
    int p, q, e, d, f ,l, n, x, y, c;
    while(scanf("%d %d %d %d",&p,&q,&e,&l)!=EOF){
        n=p*q;
        f=(p-1)*(q-1);
        exgcd(e,f,x,y);
        d=((x%f)+f)%f;//d是正数
        for(int i=0;i<l;i++){
            scanf("%d",&c);
            printf("%c",decrypt(c,d,n));
        }
        printf("\n");
    }
    return 0;
}