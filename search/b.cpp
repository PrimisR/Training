#include <cstdio>
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF=0x7fffff;

struct position
{
    int x;
    int y;
    position(int xval,int yval) 
    {
        x=xval;
        y=yval;
    }
    position()
    {

    }
};

struct maze
{
    int x,y;
    int step;
    maze(int xval,int yval,int stepval)
    {
        x=xval;
        y=yval;
        step=stepval;
    }
    maze()
    {

    }
};

position y_st;
position m_st;
int r,c;
int kfcs;

int m[205][205];
int visited[205][205];
int kfcmin[2][40005];
vector<int> totalkfc;

void bfs()
{
    queue<maze> qy;
    maze y_start=maze(y_st.x,y_st.y,0);
    maze m_start=maze(m_st.x,m_st.y,0);
    qy.push(y_start);
    while(!qy.empty())
    {
        maze u=qy.front();
        qy.pop();

        if(u.x<0||u.y<0||u.x>=r||u.y>=c||visited[u.x][u.y]||m[u.x][u.y]==-1||m[u.x][u.y]==-3) continue;

        if(m[u.x][u.y]>0)
        {
            if(u.step<kfcmin[0][m[u.x][u.y]]) kfcmin[0][m[u.x][u.y]]=u.step;
        }
        visited[u.x][u.y]=true;
        qy.push(maze(u.x+1,u.y,u.step+1));
        qy.push(maze(u.x-1,u.y,u.step+1));
        qy.push(maze(u.x,u.y+1,u.step+1));
        qy.push(maze(u.x,u.y-1,u.step+1));    
    }
    queue<maze> qm;
    qm.push(m_start);
    memset(visited,false,sizeof(visited));
    while(!qm.empty())
    {
        maze u=qm.front();
        qm.pop();

        if(u.x<0||u.y<0||u.x>=r||u.y>=c||visited[u.x][u.y]||m[u.x][u.y]==-1||m[u.x][u.y]==-2) continue;

        if(m[u.x][u.y]>0)
        {
            if(u.step<kfcmin[1][m[u.x][u.y]]) kfcmin[1][m[u.x][u.y]]=u.step;
        }
        visited[u.x][u.y]=true;
        qm.push(maze(u.x+1,u.y,u.step+1));
        qm.push(maze(u.x-1,u.y,u.step+1));
        qm.push(maze(u.x,u.y+1,u.step+1));
        qm.push(maze(u.x,u.y-1,u.step+1));    
    }
}

void init() 
{
    for(int i=0;i<40005;i++) {kfcmin[0][i]=INF; kfcmin[1][i]=INF;}   
}

int main()
{
    while(cin>>r>>c)
    {
        kfcs=0;
        init();
        memset(visited,false,sizeof(visited));
        memset(m,0,sizeof(m));
        totalkfc.clear();
        getchar();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                char c;
                c=getchar();
                if(c=='Y') {m[i][j]=-2; y_st=position(i,j);}
                else if(c=='M') {m[i][j]=-3; m_st=position(i,j);}
                else if(c=='#') {m[i][j]=-1;}
                else if(c=='@') {m[i][j]=++kfcs;}
                else m[i][j]=0;
            }
            getchar();
        }
        bfs();
        for(int i=1;i<=kfcs;i++)
        {
            totalkfc.push_back(kfcmin[0][i]+kfcmin[1][i]);
        }
        sort(totalkfc.begin(),totalkfc.end());
        cout<<totalkfc[0]*11<<endl;
    }
    return 0;
}