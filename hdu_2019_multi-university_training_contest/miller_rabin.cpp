#include <iostream>
#include <cstdio>

#define long long long

using namespace std;

const int MAXN=2e5+10;

long qmul(long a,long b,long mod)
{
    long ans=0;
    while(b)
    {
        if(b&1)
            ans=(ans+a)%mod;
        a=(a<<1)%mod;
        b>>=1;
    }
    return ans;
}

long qpow(long base,long index,long mod)
{
    long ans=1;
    while(index)
    {
        if(index&1)
            ans=qmul(ans,base,mod);
        base=qmul(base,base,mod);
        index>>=1;
    }
    return ans;
}

bool miller_rabin(long n)
{
    if(n==2) return true;
    if(n<2||!(n&1)) return false;
    
    long m=n-1;//2^r*m+1=n,m is odd
    int r=0;

    while(!(m&1))
    {
        r++;
        m>>=1;
    }
    srand(100);
    int T=2;
    while(T--)//test 2 times
    {
        long a=rand()%(n-1)+1;//a is random
        long x=qpow(a,m,n);
        long tmp=0;
        for(int j=0;j<r;j++)//for any j<r
        {
            tmp=qmul(x,x,n);
            if(tmp==1&&x!=1&&x!=n-1) return false;
            x=tmp;
        }
        if(tmp!=1) return false;
    }
    return true;
}

int main()
{
    int t;
    long p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&p);
        q=p-1;
        while(!miller_rabin(q)) q--;
        long ans=p-1;
        for(long i=p-1;i>q;i--)
            ans=qmul(ans,qpow(i,p-2,p),p);
        printf("%lld\n",ans);
    }
    return 0;
}