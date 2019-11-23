/**
 * 递推公式:
 * if(x==y) f(x,x)=f(x-1,x-1)+f(x,x-1);
 * else f(x,y)=f(x-1,y)+f(x,y-1);
 * 边界条件:
 * f(x,1)=1; (x>=1)
 * 图形是一个下三角矩阵
 * */

/**
 * 卡特兰数
 * */

#include <iostream>
#include <cstdio>

#define long long long

using namespace std;

long f_result[36][36];

long f(int x,int y)
{
    if(f_result[x][y]) return f_result[x][y];

    if(x!=y) return f_result[x][y]=f(x-1,y)+f(x,y-1);

    return f_result[x][x]=f(x-1,x-1)+f(x,x-1);
}

void init()
{
    for(int i=1;i<=35;i++)
        f_result[i][1]=1;
}

int main()
{
    init();
    int n;
    int T=1;
    while(cin>>n&&n!=-1)
        cout<<T++<<" "<<n<<" "<<f(n,n)*2<<endl;
    return 0;
}