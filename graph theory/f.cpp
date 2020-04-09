/**
 * POJ 1860
 * 题目：
 * 我们的城市有几个货币兑换点。
 * 让我们假设每一个点都只能兑换专门的两种货币。可以有几个点，专门从事相同货币兑换。
 * 每个点都有自己的汇率，外汇汇率的A到B是你用1A换取的B的数量。
 * 同时各交换点有一些佣金，你要为你的交换操作的总和。在来源货币中总是收取佣金。
 * 例如，如果你想换100美元到俄罗斯卢布兑换点，那里的汇率是29.75，而佣金是0.39，
 * 你会得到（100 - 0.39）×29.75＝2963.3975卢布。
 * 你肯定知道在我们的城市里你可以处理不同的货币。
 * 让每一种货币都用唯一的一个小于N的整数表示。
 * 然后每个交换点，可以用6个整数表描述：
 * 整数a和b表示两种货币，a到b的汇率，a到b的佣金，b到a的汇率，b到a的佣金。
 * nick有一些钱在货币S，他希望能通过一些操作（在不同的兑换点兑换），增加他的资本。
 * 当然，他想在最后手中的钱仍然是S。帮他解答这个难题，看他能不能完成这个愿望。
 * 
 * 思路：
 * 实际上这道题找到图中存在正环即可，因为如果存在正环资本可以无数次增加
 * 
 * 算法：
 * Bellman-Ford
 * 枚举每一条边e(u,v),如果dist[u]+e.w(权重) < dist[v],则更新dist[v] = dist[u]+e.w
 * 对于这个枚举最多执行n-1次，如果发现对dist没有更新，那么说明最短路径已经查找完毕(可能有到达不了的点)
 * 则跳出循环，否则执行下次循环
 * 判断负环：
 * 如果执行完n-1次，那么之后执行第n次循环，如果发现还能更新dist数组，说明存在负环，会使dist不断减少
 * 复杂度O(V*E)
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>


using namespace std;

const int MAXN = 105;

struct edge {
    int u,v;
    double rate,commission;
};

edge e[MAXN*3];
int n,m,s;
double money;
double dist[MAXN]; //dist记录转换后的钱

bool bellman_ford() {
    for(int i=1;i<=n;i++) dist[i] = 0; //找正环,越大越好，初始化为0
    dist[s] = money;
    for(int i=1;i<=n-1;i++) {
        for(int j=0;j<2*m;j++) {
            if(dist[e[j].v] < (dist[e[j].u]-e[j].commission)*e[j].rate)
                dist[e[j].v] = (dist[e[j].u]-e[j].commission)*e[j].rate;
        }
    }
    for(int j=0;j<2*m;j++) {
        if(dist[e[j].v] < (dist[e[j].u]-e[j].commission)*e[j].rate) return true;
    }
    return false;
}

int main() {
    cin>>n>>m>>s>>money;
    for(int i=0;i<2*m;i+=2) {
        cin>>e[i].u>>e[i].v>>e[i].rate>>e[i].commission>>e[i+1].rate>>e[i+1].commission;
        e[i+1].u = e[i].v;
        e[i+1].v = e[i].u;
    }
    cout << ((bellman_ford())? "YES" : "NO") << endl;
    return 0;
}