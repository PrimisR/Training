#include <iostream>
#include <cstdio>

using namespace std;

bool chess[1005][1005];
int resultfx[1005]={0,0,1,3};

void fx()
{
    for(int i=4;i<1005;i++)
    {
        resultfx[i]=resultfx[i-1]+i-1;
    }
}

int main()
{
    fx();
    int n;
    cin>>n;
    int total=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        chess[x][y]=true;
    }
    for(int i=-1004;i<1005;i++)
    {
        int count=0;
        for(int j=1;j<1005;j++)
        {
            int x=j; int y=j+i;
            if(x<1||y<1||x>=1005||y>=1005) continue;
            if(chess[x][y]) count++;
        }
        total+=resultfx[count];
    }
//    cout<<total<<endl;
    for(int i=2;i<2012;i++)
    {
        int count=0;
        for(int j=1;j<i;j++)
        {
            int x=j; int y=i-j;
            if(x<1||y<1||x>=1005||y>=1005) continue;
            if(chess[x][y]) count++;
        }
        total+=resultfx[count];
    }
    cout<<total<<endl;
    return 0;
}
