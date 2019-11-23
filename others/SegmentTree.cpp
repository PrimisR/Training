#include <cstdio>
#include <iostream>

using namespace std;

const int MAX=300;

int datas[MAX];

struct SegmentTree
{
    int l,r;
    int data;
};

SegmentTree sak[4*MAX];//编号只是作为一种连接树的方式

inline void build(int p,int l,int r)//p为编号(按照堆编号)，递归建树
{
    sak[p].l=l; sak[p].r=r;
    if(l==r)//到了叶子节点
    {
        sak[p].data=datas[l];//在叶子结点赋值
        return; //递归出口
    }
    int mid=(l+r)/2;
    build(2*p,l,mid); //递归建立左子树(左子树编号为根结点*2)，区间为(l+r)/2向下取整
    build(2*p+1,mid+1,r); //递归建立右子树(编号为根节点*2+1)，区间为(l+r)/2向上取整
    sak[p].data=sak[2*p].data+sak[2*p+1].data;//将左右子树的区间和信息向上传递
}

inline long long query(int p,int l,int r)//查询，p为标号
{
    if(l>=sak[p].l&&r<=sak[p].r)
        return sak[p].data; //如果当前区间被查询区间完全覆盖，那么返回值
    //pushdown(p);
    long long value=0;
    int mid=(sak[p].l+sak[p].r)/2;
    if(l<=mid) value+=query(2*p,l,r);
    if(r>mid) value+=query(2*p+1,l,r);
    return value;//把左右结点得到的值层层上传
}