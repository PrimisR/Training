/**
 * Dijskra算法，寻找最短路
 * 求出起点到所有点的最短路径，包括终点
 * (来自 AlexFaker 的 csdnblog) 
 * 如果A->...->B...->C 是A->C的一条最短路径，那么在这条路径中的A->...B也一定是最短路径
 * 那么这样存在最优子结构，即可贪心
 * 当然这条路径不一定经过所有点
 * ------------------------------------------------------------------------------------
 * 那么一个节点距离起点的最短距离等于min(在这个节点前驱的其他节点到起点的最短距离+两个节点之间的长度)
 * (无向图可以转化成有向图)
 * 算法：
 * 1.起点Start，更新距离Start所有点的距离，找所有点中距离Start最短距离的点u,将u纳入点集S(这样找到的u距离一定最短)，
 *   那么这段路一定是最短路径上的一段路径
 * 2.以这个点u更新其他点的距离，
 *   更新方法：如果这个点的最短距离+其他点到这个点的距离<这个点的最短距离，更新它
 * 3.寻找一个距离最短的点，把这个点加入点集
 *   (这样找到的这个点的距离一定最短，因为其他在这个点集相邻在下游的点长度都要更长，那么再到达这个点的路径长度一定比这条路长)
 * 4.重复上述操作，直到S覆盖了所有的点
 *   (不会走回头路(肯定会长))，所以可以统计总数并标记)
 * (每次不需要遍历S里的所有点，因为很多结果已经计算过了)
 * -------------------------------------------------------------------------------------
 * 二叉堆优化：用来查找最小的顶点
 * */
#include <iostream>
#include <cstdio>
#include <list>
#include <queue>

using namespace std;

const int MAXN=1001;
const int INF=0x3f3f3f3f;

struct post_node
{
    int terminal;
    int d;
    int p;
    post_node(int t,int dval,int pval)
    {
        terminal=t;
        d=dval;
        p=pval;
    }
    post_node()
    {

    }
    bool operator < (const post_node & object) const
    {
        return (d==object.d)? p<object.p : d<object.d;
    }
    bool operator > (const post_node & object) const
    {
        return (d==object.d)? p>object.p : d>object.d;
    }
};

list<post_node> post_edge[MAXN];
list<int> S;
int dist[MAXN];
int cost[MAXN];
bool visited[MAXN];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        post_edge[i].clear();
    }
    S.clear();
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
        cost[i]=INF;
        visited[i]=false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        init(n);
        for(int i=1;i<=m;i++)
        {
            int a,b,d,p;
            cin>>a>>b>>d>>p;
            post_edge[a].push_back(post_node(b,d,p));
            post_edge[b].push_back(post_node(a,d,p));
        }
        int start,terminal;
        cin>>start>>terminal;
        S.push_back(start);
        dist[start]=0; cost[start]=0; visited[start]=true;
        while(S.size()!=n)
        {
            int u=S.back();
            for(list<post_node>::iterator it=post_edge[u].begin();it!=post_edge[u].end();it++)
            {
                post_node post=(*it);
                if(visited[post.terminal]) continue;
                if(dist[post.terminal]>dist[u]+post.d)
                {
                    dist[post.terminal]=dist[u]+post.d;
                    cost[post.terminal]=cost[u]+post.p;
                }
                else if(dist[post.terminal]==dist[u]+post.d)
                {
                    if(cost[post.terminal]>cost[u]+post.p)
                    {
                        cost[post.terminal]=cost[u]+post.p;
                    }
                }
            }

            int min_node;
            int min_dist=INF;
            int min_cost=INF;
            for(int i=1;i<=n;i++)
            {
                if(visited[i]) continue;
                
                if(dist[i]<min_dist)
                {
                    min_dist=dist[i];
                    min_cost=cost[i];
                    min_node=i;
                }
                else if(dist[i]==min_dist)
                {
                    if(cost[i]<min_cost)
                    {
                        min_cost=cost[i];
                        min_node=i;
                    }
                }
            }

            S.push_back(min_node);   
            visited[min_node]=true;
        }
        cout<<dist[terminal]<<" "<<cost[terminal]<<endl;
    }
    return 0;
}