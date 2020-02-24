#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cctype>
using namespace std;
int n,m,temp,MIN;
struct node {
    int spell;
    int HP;
    int vit;
};
node a[12];
void dfs(int dep,int hp)
{
    if(dep>MIN)
    return ;
    if(dep >= n)
    return ;
    if(dep <= n-1&&hp<=0)
    {
        MIN=dep;
        return ;
    }
 
    for(int i=0;i<n;i++)
        if(!a[i].vit)
        {
            int flag=hp;
            if(hp<=a[i].HP)
                hp-=a[i].spell*2;
            else
                hp-=a[i].spell;
            a[i].vit=1;
            dfs(dep+1,hp);
            hp=flag;
            a[i].vit=0;
        }
}
int main()
{
    int x,y;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            a[i].spell=x;
            a[i].HP=y;
            a[i].vit=0;
        }
        MIN=0xfff;
        int flag = m;
        for(int i=0;i<n;i++)
        {
            a[i].vit=1;
            if(a[i].HP>=m)
            m-=2*a[i].spell;
            else
            m-=a[i].spell;
            dfs(0,m);
            a[i].vit=0;
            m=flag;
        }
        if(MIN!=0xfff)
        cout<<MIN+1<<endl;
        else
        cout<<"-1"<<endl;
    }
}