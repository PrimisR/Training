#include <iostream>
#include <string.h>
 
using namespace std;
const int maxm=1000010;
int a[maxm];
struct Node{
    int l;
    int r;
    int maxx;
}node[maxm*3];
void build(int id,int l,int r){
    node[id].l=l;
    node[id].r=r;
    if(l==r){
        node[id].maxx=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build((id<<1)+1,mid+1,r);
 
    node[id].maxx=max(node[id<<1].maxx,node[(id<<1)+1].maxx);
    return ;
}
int que(int id,int l,int r){
    int mid=(node[id].l+node[id].r)>>1;
    if(node[id].l==l&&node[id].r==r){
        return node[id].maxx;
    }
    else if(r<=mid){
        return que(id*2,l,r);
    }
    else if(mid+1<=l){//mid+1<=1或者mid<1，不要写错
        return que(id*2+1,l,r);
    }
    else {
        return max(que(id*2,l,mid),que(id*2+1,mid+1,r));
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        int q;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        build(1,1,n);
        cin>>q;
        int l;
        int r;
        for(int i=1;i<=q;i++){
            cin>>l>>r;
            cout<<que(1,l,r)<<endl;
        }
    }
    return 0;
}