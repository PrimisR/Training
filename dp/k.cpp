/**
 * 0-1背包问题
 * x 表示第x个物品 val(x)表示这个物品的价值 vol(x)表示这个物品的大小 x=0,1,...,n;
 * W(y) 表示当前背包的大小，y=0,1,...,v;
 * max_V(x,y)表示在背包大小为y,有x个物品时，所能获取的最大价值
 * 
 * 该问题满足最优性原理
 * 对于(x,y)这个状态，对于当前物品x，有两个选择
 * 1.如果选择装下这个物品x，那么拿取完这个物品的状态是(x-1,y-vol(x)),应该寻找这个状态的最优解,那么这一次获得的价值为max_V(x-1,y-vol(x))+val(x);
 * 2.如果选择不装下这个物品x，那么这个状态下的最优解和(x-1,y)的状态是相同的，这一次获得的价值为max_V(x-1,y);
 * 
 * 对于当前的背包状态：
 * 如果装得下，那么可以采取两个选择，然后选取最大获得的价值
 * 如果装不下，只能不装
 * 
 * 背包问题没有后效性，可以从子问题逐渐推导
 * 边界条件:
 * if (x==0||y==0) (没有东西可拿或者背包没有容量) max_V(x,y)=0;
 * */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

struct bone
{
    int volume=0;
    int value=0;
};

bone bones[2000];

int result[2000][2000];

int max_V(int x,int y)
{
    if(x==0) return result[x][y];//第一个物品可能没有重量

    if(result[x][y]) return result[x][y];

    if(y>=bones[x].volume) return result[x][y]=max( max_V(x-1,y) , max_V(x-1,y-bones[x].volume)+bones[x].value );
    else return result[x][y]=max_V(x-1,y);
}//自顶向下

int fill_result(int n,int v)
{
    for(int i=1;i<=n;i++)//第一个物品可能没有重量
        for(int j=0;j<=v;j++)
            result[i][j] = (j>=bones[i].volume)? max(result[i-1][j],result[i-1][j-bones[i].volume]+bones[i].value) : result[i-1][j];
    return result[n][v];
}//自底向上

void init()
{
    memset(result,0,sizeof(result));
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        init();
        int n,v;
        cin>>n>>v;
        for(int i=1;i<=n;i++) cin>>bones[i].value;
        for(int i=1;i<=n;i++) cin>>bones[i].volume;
        cout<<max_V(n,v)<<endl;
        //cout<<fill_result(n,v)<<endl;
    }
    return 0;
}