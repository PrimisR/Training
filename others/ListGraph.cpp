#include <cstdio>
#include <iostream>

using namespace std;

const int maxn=100;

struct ArcNode
{
    int vertex;//��ָ��Ľ����
    int weight;
    ArcNode* next;//����
    ArcNode(int v,int w):vertex(v),weight(w),next(NULL){}
}; //�߽�㣬��ʾ�ڽӵ�һ����

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
        if(y->vertex==ed) //�����������ָ��ͬһ�����,����ȥ��
        {
            if(y->weight)
        }
    }
    
}