/**
 * 区间修改线段树
 * +懒惰标记:
 * 本区间已经被更新过了，而子区间没有被更新
 * 相对标记:可以共存，顺序与答案无关
 * 绝对标记:每次要把标记下传，再给当前节点打上新的标记
 * */

#include <cstdio>

const int MAXN = 100005;

struct node {
    int l;
    int r;
    long long v;
    long long lazy;
};

node nodes[MAXN*4];
long long data[MAXN];

/**
 * 将当前节点的懒惰标记下传
 * */
void pushdown(int cu) {
    if(nodes[cu].l == nodes[cu].r) { //到达叶子节点，不必下传
        nodes[cu].lazy = 0;
        return;
    }
    nodes[cu*2].v += (nodes[cu*2].r-nodes[cu*2].l+1)*nodes[cu].lazy;
    nodes[cu*2+1].v += (nodes[cu*2+1].r-nodes[cu*2+1].l+1)*nodes[cu].lazy;
    nodes[cu*2].lazy += nodes[cu].lazy;
    nodes[cu*2+1].lazy += nodes[cu].lazy;
    nodes[cu].lazy = 0;
}

/**
 * 相对标记的更新区间,类似于查询区间的分割
 * lazy标记标记的是该节点下所有子节点都没有更新
 * @param cu 当前节点
 * @param l 区间左端点
 * @param r 区间右端点
 * @param d 更新差值(区间中每个数都加)(相对标记)
 * */
void upd_invl(int cu,int l,int r,long long d) {
    if(nodes[cu].l == l && nodes[cu].r == r) { //到达完全重合的节点
        nodes[cu].v += (r-l+1)*d;
        nodes[cu].lazy += d;
        return;
    }
    //先pushdown
    if(nodes[cu].lazy) pushdown(cu);
    int mid = (nodes[cu].l+nodes[cu].r)/2;
    if(r<=mid) upd_invl(cu*2,l,r,d);
    else if(l>mid) upd_invl(cu*2+1,l,r,d);
    else {
        upd_invl(cu*2,l,mid,d);
        upd_invl(cu*2+1,mid+1,r,d);
    }
    nodes[cu].v = nodes[cu*2].v + nodes[cu*2+1].v;
    //由于此处用子节点的值更新了父节点的值，所以必须先pushdown
}

/**
 * 区间查询
 * 查询之前先要下传懒惰标记
 * */
long long query(int cu,int l,int r) {
    if(nodes[cu].l == l && nodes[cu].r == r) {
        return nodes[cu].v;
    }
    if(nodes[cu].lazy) pushdown(cu);
    int mid = (nodes[cu].l+nodes[cu].r)/2;
    if(r<=mid) return query(cu*2,l,r);
    if(l>mid) return query(cu*2+1,l,r);
    return query(cu*2,l,mid)+query(cu*2+1,mid+1,r);
}

void build(int cu,int l,int r) {
    nodes[cu].l = l;
    nodes[cu].r = r;
    if(nodes[cu].l == nodes[cu].r) {
        nodes[cu].v = data[l];
        return;
    }
    int mid = (l+r)/2;
    build(cu*2,l,mid);
    build(cu*2+1,mid+1,r);
    nodes[cu].v = nodes[cu*2].v + nodes[cu*2+1].v;
}

int main()
{
    int N,Q;
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;i++) {
        scanf("%lld",&data[i]);
    }
    getchar();
    build(1,1,N);
    while(Q--) {
        char op; int a,b; long long c;
        scanf("%c",&op);
        switch (op)
        {
        case 'Q':
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(1,a,b));
            break;
        
        case 'C':
            scanf("%d%d%lld",&a,&b,&c);
            upd_invl(1,a,b,c);
            break;
        }
        getchar();
    }
    return 0;
}