/**
 * 给定两个数n,k,求n^k的前三位和最后三位
 * 后三位：快速幂求模1000
 * 前三位：对于一个数字x，例如123456;
 * lg(x)=lg(123456)=5+lg(1.23456)
 * 取小数部分，10^lg(1.23456)=1.23456;
 * 再将这个数字*100即可获得前三位
 * n^k:lg(n^k)=k*lg(n)
 * 
 * 函数:
 * math库里的log10()函数
 * math库里的fmod()，对浮点数取模，对1取模就是取一个浮点数的小数部分
 * x-(int)x也可以
 * 
 * 陷阱:
 * 后三位中第一位有0要输出0
 * */

#include <cmath>
#include <cstdio>
#include <iostream>
#define long long long

using namespace std;
const int MOD=1000;

long qpow(long base,long index)
{
    long ans=1;
    while(index)
    {
        if(index&1)
        {
            ans=(ans*base)%MOD;
        }
        base=(base*base)%MOD;
        index>>=1;
    }
    return ans;
}


int main()
{
    int T;
    cin>>T;
    int Case=T;
    while(T--)
    {
        long n,k;
        cin>>n>>k;
        int leading,trailing;
        trailing=qpow(n,k);
        double index=k*log10(n);
        double decimal=index-(int)index;
        leading=pow(10,2.0+decimal);
        printf("Case %d: %d %03d\n",Case-T,leading,trailing);
    }
    return 0;
}