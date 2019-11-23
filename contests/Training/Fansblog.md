#### Fansblog

##### Problem Description:

已知质数P，先求得小于P的最大质数Q，再求 Q! mod P，T个样例

##### 数据范围：

$10^9 \le P \le 10^{14}$

$1\le T \le 10$

##### 知识点以及思路：

##### 1.素数密度：

$$
\pi(x) \sim \frac x {\ln x}
$$

其中 $ \pi(x) $ 表示不超过$x$的素数个数，在题目给的范围内，两个相邻素数通常只隔几十个数。

##### 思路：

从P-1开始枚举，逐个判断素数，需要判断素数的方法（据说$\sqrt n$的方法可以）

##### 2.Miller-Rabin随机算法

这个算法用来判断一个数一定概率是否为素数，算法描述如下：

1. 计算奇数$M$，使得$N=2^r *M+1$
2. 选择随机数$A < N$；
3. 对于任意$i<r$,若$A^{2^i *M} \space mod \space N=N-1$,则N通过随机数A的测试；
4. 或者，若$A^M \space mod \space N=1$,则N通过随机数A的测试；
5. 让A取不同的值对N进行行多次测试（一般要求5~10次，有较高要求的话可以进行20~30次），若全部通过则判定N为素数。

若N通过一次测试，则N不是素数的概率为25%；

若N通过 t 次测试，则N不是素数的概率为1/( 4 ^ t )；

事实上，当 t = 5 时，N不是素数的概率已为1/128，已经大于99.99%。

在实际运用中，可首先用300~500个小素数对N进行测试，以提高测试通过的概率与算法的速度。在随机生成的素数中，选取的随机数最好让 r = 0，则可以省去步骤 3 的操作，进一步减少判定时间。

代码（有计算优化）：

```c
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
const int count=10;
int modular_exp(int a,int m,int n)
{
    if(m==0)
        return 1;
    if(m==1)
        return (a%n);
    long long w=modular_exp(a,m/2,n);
    w=w*w%n;
    if(m&1)
        w=w*a%n;
    return w;
} 
bool Miller_Rabin(int n)
{
    if(n==2)
        return true;
    for(int i=0;i<count;i++)
    {
        int a=rand()%(n-2)+2;
        if(modular_exp(a,n,n)!=a)
            return false;
    }
    return true;
}
int main()
{
    srand(time(NULL));
    int n;
    scanf("%d",&n);
    if(Miller_Rabin(n))
        printf("Probably a prime.");
    else
        printf("A composite.");
    printf("\n");
    return 0;
}
```

##### 3.威尔逊定理

当且仅当P为素数时，有
$$
(P-1)! \equiv -1 (mod \space p)
$$

##### 思路：

剩下解决的就是除法后的余数了

##### 4.乘法逆元

可以用于组合数取模的计算
$$
(\frac a b)\space \equiv (a*b^{(p-2)})\space (mod \space p)
$$

##### 代码：

```c++
#include <bits/stdc++.h>

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
```

