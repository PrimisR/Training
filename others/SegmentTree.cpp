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

SegmentTree sak[4*MAX];//���ֻ����Ϊһ���������ķ�ʽ

inline void build(int p,int l,int r)//pΪ���(���նѱ��)���ݹ齨��
{
    sak[p].l=l; sak[p].r=r;
    if(l==r)//����Ҷ�ӽڵ�
    {
        sak[p].data=datas[l];//��Ҷ�ӽ�㸳ֵ
        return; //�ݹ����
    }
    int mid=(l+r)/2;
    build(2*p,l,mid); //�ݹ齨��������(���������Ϊ�����*2)������Ϊ(l+r)/2����ȡ��
    build(2*p+1,mid+1,r); //�ݹ齨��������(���Ϊ���ڵ�*2+1)������Ϊ(l+r)/2����ȡ��
    sak[p].data=sak[2*p].data+sak[2*p+1].data;//�������������������Ϣ���ϴ���
}

inline long long query(int p,int l,int r)//��ѯ��pΪ���
{
    if(l>=sak[p].l&&r<=sak[p].r)
        return sak[p].data; //�����ǰ���䱻��ѯ������ȫ���ǣ���ô����ֵ
    //pushdown(p);
    long long value=0;
    int mid=(sak[p].l+sak[p].r)/2;
    if(l<=mid) value+=query(2*p,l,r);
    if(r>mid) value+=query(2*p+1,l,r);
    return value;//�����ҽ��õ���ֵ����ϴ�
}