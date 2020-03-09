#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int a[10],ans[10];
int t;
int vis[10],color[10];
int mp[10][10];
int sum=0;
bool judge(int x)
{
  for(int i=1;i<x;i++)
  {
    if(mp[x][i]&&abs(a[x]-a[i])==1)
      return false;
  }
  return true;
}
void dfs(int x)
{
  if(x==9)
  {
    for(int i=1;i<=8;i++)
    {
      ans[i]=a[i];
    }
    sum++;
    return;
  }
  if(sum>=2) return;
  if(vis[x]==2)
    dfs(x+1);
  for(int i=1;i<=8;i++)
  {
    if(!color[i])
    {
      a[x]=i;
      color[i]=1;
      if(judge(x))
        dfs(x+1);
      a[x]=0;
      color[i]=0;
    }
  }
}
int main()
{
  mp[1][2]=mp[1][3]=mp[1][4]=1;
  mp[2][1]=mp[3][1]=mp[4][1]=1;
  mp[2][3]=mp[2][5]=mp[2][6]=1;
  mp[3][2]=mp[5][2]=mp[6][2]=1;
  mp[3][4]=mp[3][5]=mp[3][6]=mp[3][7]=1;
  mp[4][3]=mp[5][3]=mp[6][3]=mp[7][3]=1;
  mp[4][6]=mp[4][7]=1;
  mp[6][4]=mp[7][4]=1;
  mp[5][6]=mp[5][8]=1;
  mp[6][5]=mp[8][5]=1;
  mp[6][7]=mp[6][8]=1;
  mp[7][6]=mp[8][6]=1;
  mp[7][8]=mp[8][7]=1;
  int ca=0;
  scanf("%d",&t);
  while(t--)
  {
    sum=0;
    memset(vis,0,sizeof(vis));
    memset(color,0,sizeof(color));
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=8;i++)
    {
      scanf("%d",&a[i]);
      if(a[i]!=0)
      {
        vis[i]=2;
        color[a[i]]=1;
      }
    }
    dfs(1);
    printf("Case %d: ",++ca);
    if(sum==1)
    {
      for(int i=1;i<=8;i++)
      {
        printf("%d%c",ans[i],i==8?'\n':' ');
      }
    }
    else if(sum>=2)
      printf("Not unique\n");
    else printf("No answer\n");
  }
  return 0;
}