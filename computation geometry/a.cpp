/**
 * 纸板彼此不相交，就是n个纸板形成从左到右n+1个分区
 * 如果Li=f(Ui)，Li应为单调不递减，可以进行二级排序从左到右
 * 升序输出 玩具数:有几个分区有这些玩具数
 * 叉乘，可以判断一个点在一条直线的一侧或另一侧
 * 那么可以利用二分的思想，判断一个点在哪个区
 * */

#include <iostream>
#include <cstdio>
#include <algorithm>
#define long long long

using namespace std;

int x1,y1;
int x2,y2;
int n,m;

struct point
{
    int x;
    int y;
    point(){}
    point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
};

struct line
{
    int Ui;
    int Li;
    line(){}
    line(int Ui,int Li)
    {
        this->Ui=Ui;
        this->Li=Li;
    }
};

int cmp(line a,line b)
{
    return (a.Ui==b.Ui)? a.Li<b.Li : a.Ui<b.Ui; 
}
/**
 * 以(Ui,y1)为起点,(Li,y2)为终点规定直线(y1>y2)，另一个向量以(Ui,y1)为起点，以p(x,y)为终点
 * 结果>0在直线右侧，<0在直线左侧
 * */
long cross_product(point p,line l)
{
    return (l.Li-l.Ui)*(p.y-y1)-(p.x-l.Ui)*(y2-y1);
}

int t[1001];//t[i]表示i玩具有几个有i个玩具的分区
line lines[1001];
int toys[1001];//toys[0]是lines[0]条直线左边的分区，toys[1]是lines[0]直线右边，lines[1]左边的分区
//lines[n]是n右边的分区

int binarySearch(point p)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(cross_product(p,lines[mid])<0) high=mid-1;
        else low=mid+1;
    }
    return mid;
}

int main()
{
    while (cin>>n&&n!=0)
    {
        cin>>m>>x1>>y1>>x2>>y2;
        for(int i=0;i<1001;i++)
        {
            t[i]=0; toys[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            int Ui,Li;
            cin>>Ui>>Li;
            lines[i]=line(Ui,Li);
        }
        sort(lines,lines+n,cmp);
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            point p=point(x,y);
            //二分查找
            int mid=binarySearch(p);
            if(cross_product(p,lines[mid])<0) toys[mid]++;
            else toys[mid+1]++;
        }
        for(int i=0;i<=n;i++)
        {
            t[toys[i]]++;
        }
        cout<<"Box"<<endl;
        for(int i=1;i<=n;i++)
        {
            if(t[i]) cout<<i<<": "<<t[i]<<endl;
        }
    }
    
}