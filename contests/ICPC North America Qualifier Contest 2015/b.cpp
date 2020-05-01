#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define clc(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N=10010;
const int MOD = 1e9+7;
#define LL long long
void fre() {
    freopen("in.txt","r",stdin);
}
 
inline int r(){
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
int countt;
int  comb1(int m,int k)
{     
    int i;
    for (i=m;i>=k;i--)
    {
        if (k>1)
        {
            comb1(i-1,k-1);
        }
        else
        { 
            countt++;
        }
    }
    return countt;           
}
 
int main(){
    // fre();
    int T;
    int R,s,x,y,w;
    T=r();
    while(T--){
        double p1=0.0;
        int num;
       cin>>R>>s>>x>>y>>w;
       double p=(s-R+1)*1.0/s;
       double ans=0.0;
       for(int i=x;i<=y;i++){
           int c=y-i;
           p1=1.0;
           double p2=1.0-p;
           while(c--){
               p1*=p2;
           }
           int cc=i;
           double P=1.0;
           for(int j=1;j<=i;j++){
              P*=p;
           }
           // cout<<i<<" "<<P<<endl;
           countt=0;
           num=comb1(y,i);
           // cout<<P<<" "<<p1<<" "<<num<<endl;
          ans+=P*p1*num;
       }
       // cout<<ans<<endl;
       if(ans*w>1)
        printf("yes\n");
       else
        printf("no\n");
    }
    return 0;
}