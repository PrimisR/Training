/**
 * 最近公共祖先节点：
 * 给定一棵树，对于其中的两个节点，有一些共同的祖先节点，其中深度最大的是两者的最近公共祖先节点
 * 输入：
 * 总节点数N
 * N-1条边，其中前者为父节点，后者为子节点
 * 最后一行为查询的两个点的标号
 * */

/**
 * LCA离线算法 Tarjan
 * 从根开始深度优先搜索dfs，当访问完一个节点的所有子树之后，就用这个节点代替这个子树里的所有节点(并查集)
 * 当访问到一个查询节点的时候，另一个节点已经访问完毕，则输出当前状况下另一个节点的并查集
 * 由于是离线算法，可以提前记录所有询问，并在一次dfs后给出所有解答，其时间复杂度为O(n+q)
 * 其中n代表数据数量，q代表查询数量
 * */

#include <cstdio>
#include <iostream>
#include <list>

using namespace std;

bool is_root[10001];
int father[10001];
int is_visited[10001];
list<int> child_node[10001];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;//并查集初始化
        child_node[i].clear();//清空树存储
        is_root[i]=true;//清空是否是根的记录
        is_visited[i]=false;//深搜记录
    }
}

int find_father(int child)
{
    return (father[child]==child)? child : father[child]=find_father(father[child]);
}

int _union(int _father,int _child)
{
    int father_father=find_father(_father);
    int child_father=find_father(_child);
    if(child_father!=father_father)
        father[child_father]=father_father;
}

int find_root(int n)
{
    for(int i=1;i<=n;i++)
        if(is_root[i]) return i;
}

void tarjan(int thisnode,int &query_u,int &query_v)
{
    //针对下面每一个子节点深搜，搜索后向父亲节点合并
    //这里是对树的深度优先遍历--后序遍历
    for(list<int>::iterator it=child_node[thisnode].begin();it!=child_node[thisnode].end();it++)
    {
        int child=(*it);
        tarjan(child,query_u,query_v);
        _union(thisnode,child);
    }
    //当一个节点下的所有子树都被搜索完过后，子树和父节点将被合并到同一个集合里

    is_visited[thisnode]=true;//这用来表示这个节点已经由它的父节点代替
    //如果当前节点是查询节点，并且另一个节点已经访问过了，就输出当前状态下另一个节点的并查集
    if(query_u==thisnode&&is_visited[query_v])
    {
        cout<<find_father(query_v)<<endl;
    } 

    if(query_v==thisnode&&is_visited[query_u])
    {
        cout<<find_father(query_u)<<endl;
    }

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        init(n);
        for(int i=1;i<=n-1;i++)
        {
            int first,second;
            cin>>first>>second;
            child_node[first].push_back(second);
            is_root[second]=false;
        }
        int root=find_root(n);

        int query_u,query_v;
        cin>>query_u>>query_v;
        tarjan(root,query_u,query_v);
    }
    return 0;
}
