#include <cstdio>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

const int maxn=300;
const int root=1;

int Left[maxn];
int Right[maxn];
bool have_value[maxn];
int value[maxn];
int failed;
int cnt; //按照节点的生成顺序给节点标号，用cnt计数（最大编号）

void newtree()
{
    Left[root]=Right[root]=0;
    have_value[root]=false;
    cnt=root;
}

int newnode()
{
    int u=++cnt;
    Left[u]=Right[u]=0;
    have_value[root]=false;
    return u;
}


struct Node
{
    bool have_value;
    int v;
    Node *left,*right;
    Node():have_value(false),left(NULL),right(NULL){}
};

Node node[10000];

Node* Newnode()
{
    Node *u=&node[++cnt];
    u->left=u->right=NULL;
    u->have_value=false;
    return u; //这样写会引起内存溢出,cnt一直增加，但用完的内存无法重用
    //“释放内存”很不方便
}

//内存池

queue<Node*> freenodes;
Node nodes[maxn];

void init()
{
    for(int i=0;i<maxn;i++)
        freenodes.push(&node[i]);
}

Node* NewNode()
{
    Node *u=freenodes.front();
    u->left=u->right=NULL; u->have_value=false;
    freenodes.pop();
    return u;
}

void deletenode(Node *u)
{
    freenodes.push(u);
}

