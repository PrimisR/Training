#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

struct node
{
    int l;
    int r;
    int v;
};
node nodes[MAXN*4];
int data[MAXN];

void build(int cu,int l,int r) {
    nodes[cu].l = l;
    nodes[cu].r = r;
    if(l == r) {
        nodes[cu].v = data[l];
        return;
    }
    int mid = (l+r)/2;
    build(cu*2,l,mid);
    build(cu*2+1,mid+1,r);
    nodes[cu].v = max(nodes[cu*2].v,nodes[cu*2+1].v);
}

void update(int cu,int d_ptr,int nv) {
    if(nodes[cu].l == nodes[cu].r) {
        nodes[cu].v = nv;
        return;
    }
    int mid = (nodes[cu].l + nodes[cu].r)/2;
    if(d_ptr<=mid) update(cu*2,d_ptr,nv);
    else update(cu*2+1,d_ptr,nv);
    nodes[cu].v = max(nodes[cu*2].v,nodes[cu*2+1].v);
}

int query(int cu,int l,int r) {
    if(nodes[cu].l == l && nodes[cu].r == r) {
        return nodes[cu].v;
    }
    int mid = (nodes[cu].l+nodes[cu].r)/2;
    if(r<=mid) return query(cu*2,l,r);
    if(l>mid) return query(cu*2+1,l,r);
    return max(query(cu*2,l,mid),query(cu*2+1,mid+1,r));
}

int main()
{
    ios::sync_with_stdio(false);
    int N,M;
    while(cin>>N>>M) {
        for(int i=1;i<=N;i++) {
            cin>>data[i];
        }
        build(1,1,N);
        while(M--) {
            char op;
            int A,B;
            cin>>op;
            cin>>A>>B;
            switch (op)
            {
            case 'Q':
                cout<<query(1,A,B)<<endl;
                break;
            case 'U':
                update(1,A,B);
                break;
            }
        }
    }
}