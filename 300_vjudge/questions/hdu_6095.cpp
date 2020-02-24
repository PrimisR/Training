#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define g() getchar()
#define rg register
#define go(i,a,b) for(rg int i=a;i<=b;i++)
#define back(i,a,b) for(rg int i=a;i>=b;i--)
#define db double
#define ll long long
#define il inline
#define pf printf
using namespace std;
int fr(){
    int w=0,q=1;
    char ch=g();
    while(ch<'0'||ch>'9'){
        if(ch=='-') q=-1;
        ch=g();
    }
    while(ch>='0'&&ch<='9') w=(w<<1)+(w<<3)+ch-'0',ch=g();
    return w*q;
}
const int N=1e5+2;
int T,n,k,a[N];
int main(){
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    T=fr();
    while(T--){
        n=fr();k=fr();
        go(i,1,n) a[i]=fr();
        sort(a+1,a+1+n);
        rg int ans=1;//初始值为1是因为实力最大的选手一定有可能获胜
        back(i,n,2){
            if(a[i]-a[i-1]>k) break;
            ans++;//这是实力第i-1大的选手可能获胜
        }
        pf("%d\n",ans);
    }
    return 0;
}