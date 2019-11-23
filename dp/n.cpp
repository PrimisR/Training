/**
 * 二维完全背包
 * 
 * 思路：
 * 用杀怪数s和忍耐度m作为状态参量，max_E(s,m)为杀怪数剩余s并且忍耐度剩余n时候获得最多的经验值
 * 由于怪物种类k无限，所以种类k不作为状态参数，经验不一定恰好，也不一定正好能n
 * 
 * 怪物:monster[0]...monster[k-1];
 * monster:exp,cost
 * 对于所有怪物:
 * 0.可以杀掉怪物的条件为体力数大于monster[i];
 * 1.杀掉怪物monster[i]，获得的经验值为max_E(s-1,m-monster[i].cost)+monster[i].exp
 * 
 * 算法：
 * 每次遍历所有怪物，找到能获得的经验最大值
 * */

/**
 * 不能采用自顶向下的方法，因为途中会有计算不到的状态，故无法判断：
 * max_E[s][m]的确是计算得到的所有最大经验值中最大的经验值，但是自顶向下没法寻找最小的忍耐度，因为部分状态没有计算到
 * 还要注意数组下标可以为负，但是值并不正确
 * 不能贪心：
 * 样例：
 * 15 30 5 3
 * 3 4
 * 4 5
 * 6 7
 * 7 8
 * 最优解是12
 * */

#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;

struct monster
{
    int exp;
    int cost;
};

monster monsters[100];
int max_E[101][101];
int n,m,k,s;
int min_m;

int fill_max_E()
{
    int min_m=m;
    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int num=0;num<k;num++)
            {
                if(j>=monsters[num].cost)
                {
                    max_E[i][j]=max(max_E[i][j],max_E[i-1][j-monsters[num].cost]+monsters[num].exp);
                }
            }
            if(max_E[i][j]>=n) min_m=min(min_m,j);
        }
    }
    return min_m;
}

int main()
{
    while(cin>>n>>m>>k>>s)
    {
        memset(max_E,0,sizeof(max_E));
        min_m=m;

        for(int i=0;i<k;i++)
        {
            cin>>monsters[i].exp>>monsters[i].cost;
        }

        int min_m=fill_max_E();
        if(max_E[s][m]<n) cout<<"-1"<<endl;
        else
        {
            cout<<m-min_m<<endl;
        }
        
    }
    return 0;
}