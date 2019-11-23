/**
 * 求最小生成树
 * 1.Kruskal算法：
 * 算法：
 * 1.建立带有所有节点的空图
 * 2.将边按照权值从小到大排序
 * 3.避圈法：如果边连接的两个点不在同一连通分支，那么加入这条边
 * 4.重复3，直到所有节点在同一连通分支中
 * 判断在同一连通分支的方法:
 * 并查集（不能用标记法，因为中间状态有可能在一个图中有多个连通分支）
 * */

/**
 * 不足够保证畅通的条件:
 * (插入的边数)<(顶点数-1)
 * 成为树的充要条件是 边数=顶点数-1
 * */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

struct edge
{
    int start;
    int terminal;
    int value;
    edge(int s,int t,int v)
    {
        start=s;
        terminal=t;
        value=v;
    }
    edge()
    {

    }
};

struct union_set
{
    int father[100];

    void init()
    {
        for(int i=1;i<=100;i++)
            father[i]=i;
    }

    int find(int x)
    {
        return (father[x]==x)? x:father[x]=find(father[x]);
    }

    void _union(int _father,int _child)
    {
        int father_father=find(_father);
        int child_father=find(_child);
        if(father_father!=child_father)
            father[child_father]=father_father;
    }
    
    union_set()
    {
        init();
    }
};

int edge_cmp(edge a,edge b)
{
    return a.value<b.value;
}

edge edges[10000];

int main()
{
    int n,m;
    while(cin>>n>>m&&n!=0)
    {
        int total_edge=0;
        int total_value=0;
        union_set s;
        for(int i=0;i<n;i++)
        {
            int s,t,v;
            cin>>s>>t>>v;
            edges[i]=edge(s,t,v);
        }
        sort(edges,edges+n,edge_cmp);
        for(int i=0;i<n;i++)
        {
            edge e=edges[i];
            if(s.find(e.start)!=s.find(e.terminal))
            {
                total_value+=e.value;
                s._union(e.start,e.terminal);
                total_edge++;
            }
        }
        if(total_edge!=m-1) cout<<"?"<<endl;
        else cout<<total_value<<endl;
    }
    return 0;
}