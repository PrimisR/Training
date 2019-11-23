#include <cstdio>
#include <iostream>

using namespace std;

const int maxn=100;

struct ArcNode
{
    int vertex;//所指向的结点编号
    int weight;
    ArcNode* next;//链表
    ArcNode(int v,int w):vertex(v),weight(w),next(NULL){}
}; //边结点，表示邻接的一条边

struct VertexNode
{
    ArcNode* firstArc;
};

VertexNode vertexs[maxn];

void Insert(int st,int ed,int w)
{
    ArcNode* x=new ArcNode(ed,w);

    if(vertexs[st].firstArc==NULL)
        vertexs[st].firstArc==x;
    else
    {
        ArcNode* y=vertexs[st].firstArc;
        if(y->vertex==ed) //如果这两条边指向同一个结点,用来去重
        {
            if(y->weight)
        }
    }
    
}