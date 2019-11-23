#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int INF=0X7fffff;

int maze[5][5];
bool visited[5][5];

int minstep=INF;

struct p
{
    int x,y;
    p(int xval,int yval)
    {
        x=xval;
        y=yval;
    }
};
vector<p> minroute;
vector<p> currentroute;

void dfs(int x,int y,int steps)
{
    if(x==4&&y==4) 
    {
        if(steps<minstep) minroute=currentroute;
        return;
    }

    if(x<0||y<0||x>4||y>4||maze[x][y]==1||visited[x][y]) return;

    visited[x][y]=true; currentroute.push_back(p(x,y));
    dfs(x+1,y,steps+1);
    dfs(x-1,y,steps+1);
    dfs(x,y+1,steps+1);
    dfs(x,y-1,steps+1);
    visited[x][y]=false; currentroute.pop_back();
}

int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin>>maze[i][j];
    dfs(0,0,0);
    for(int i=0;i<minroute.size();i++)
    {
        printf("(%d, %d)\n",minroute[i].x,minroute[i].y);
    }
    printf("(4, 4)\n");
    return 0;
}