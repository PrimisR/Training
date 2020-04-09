/**
 * 最小生成树，去掉<10，>1000的边
 * */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

#define MAX 0xfffffff

const int N = 101;

typedef struct
{
    int x,y;
}POINT;

POINT p[N];
double map[N][N];
int vis[N];
int T,C,x,y,i,j;

double get_distance(POINT a,POINT b)
{
    return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));
}

void build_map()
{
    double len;
    for (int t = 0; t < C; t++)
    for (int v = t; v < C; v++)
    {
        len = get_distance(p[t],p[v]);
        if(len>=10 &&len <= 1000)
        map[t][v] = map[v][t] = (t==v)?0:len;
        else map[t][v] = map[v][t] = MAX;
    }
    
}

void prim()
{
    int k,t = C;
    double min,sum = 0;
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    while(--t)
    {
        min = MAX;
        for (i = 1; i < C; i++)
        {
            if (vis[i]!=1 && map[0][i] < min)
            {
                min = map[0][i];
                k = i;
            }
        }
        if (min==MAX)break;
        vis[k] = 1;
        sum += min;
        for (i = 1; i < C; i++)
        {
            if (vis[i]!=1 && map[k][i] < map[0][i] )
            map[0][i] = map[k][i];
        }
    }
    //printf("%d\n",t);
    if(t==0)
    {
        printf("%.1f\n",sum*100);
    }else printf("oh!\n");
}


int main()
{
    while(scanf("%d",&T)!= EOF)
    {
        for (int t = 0; t < T; t++)
        {
            scanf("%d",&C);
            for (int c = 0; c < C; c++)
            scanf("%d%d",&p[c].x,&p[c].y);
            build_map();
            prim();
        }
        
    }
    return 0;
}