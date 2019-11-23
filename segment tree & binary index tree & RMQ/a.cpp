/**
 * 二叉索引树，树状数组
 * 修改，查询复杂度都为O(logn)
 * 用数组模拟树形结构
 * 对于每一个数据data[i]:
 * tree[1]=data[1];//0001
 * tree[2]=data[1]+data[2];//0010
 * tree[3]=data[3];//0011
 * tree[4]=data[1]+data[2]+data[3]+data[4];//0100
 * tree[5]=data[5];//0101
 * tree[6]=data[5]+data[6];//0110
 * tree[7]=data[7];//0111
 * tree[8]=data[1]+data[2]+data[3]+data[4]+data[5]+data[6]+data[7]+data[8];//1000
 * ...
 * 
 * lowbit(int x)
 * {
 *     return x&(-x);
 * }//补码表示法，取反+1
 * 最后求得的是末位1带着后面所有的0所表示的数字
 * 例如:
 * lowbit(6)=(110)&(010)(取反+1)=10=2
 * 
 * 更新算法：观察上面数据，当更新data[3]时，给tree[3],tree[4],tree[8]...更新
 * 也就是给tree[i],tree[i+lowbit(i)],tree[(i+lowbit(i))+lowbit(i+lowbit(i))]...直到数组末尾更新
 * 每次 i+=lowbit(i);即可
 * 
 * 求和算法: sum(7)=tree(7)+tree(6)+tree(4)//tree(0111)+tree(0110)+tree(0100)
 * 可以看出其中lowbit的运算
 * */

/**
 * 坐标按照y升序排列，y相同按照x升序排列
 * 那么每次查询编号x前面的sum即可
 * */

#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN=33000;

struct binary_indexed_tree
{
    int tree[MAXN];//0不做存储
    int n;

    int lowbit(int x)
    {
        return x&(-x);
    }

    void update(int pos,int k)//data[pos]增加了k，更新tree
    {
        while(pos<=n)
        {
            tree[pos]+=k;
            pos+=lowbit(pos);
        }
    }

    int sum(int pos)//前i个数字的和
    {
        int sum=0;
        while(pos)
        {
            sum+=tree[pos];
            pos-=lowbit(pos);
        }
        return sum;
    }

    void clear()
    {
        for(int i=0;i<=n;i++) tree[i]=0;
    }

    binary_indexed_tree()
    {
        n=MAXN;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int star;
    int levels[15000];
    binary_indexed_tree bit;
    while(cin>>star)
    {
        bit.clear();
        for(int i=0;i<star;i++) levels[i]=0;
        for(int i=1;i<=star;i++)
        {
            int x,y;
            cin>>x>>y;
            x=x+1;
            levels[bit.sum(x)]++;
            bit.update(x,1);
        }
        for(int i=0;i<=star-1;i++)
        {
            cout<<levels[i]<<endl;
        }
    }
    return 0;
}