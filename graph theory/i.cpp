/**
 * i这道题仍然用kruskal算法做
 * 复杂度是O(eloge)，而e=(v-1)*v/2,大概为O(v^2logv)
 * 如果采用prim算法
 * 复杂度是O(v^2) 邻接矩阵
 * O(elogv)=O(v^2logv) 邻接表
 * 采用prim算法：
 * 邻接矩阵存储图
 * */

#include <iostream>
#include <cstdio>
#include <memory.h>
#include <vector>

using namespace std;

const int MAXN=100;
const int INF=0x7fffff;

int distances[MAXN][MAXN];
bool visited[MAXN];
vector<int> vertex;

int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        memset(visited,0,sizeof(visited));
        vertex.clear();
        int edge_num=(n-1)*n/2;
        for(int i=1;i<=edge_num;i++)
        {
            int village_1,village_2,distance;
            cin>>village_1>>village_2>>distance;
            distances[village_1][village_2]=distances[village_2][village_1]=distance;
        }
        vertex.push_back(1);
        visited[1]=true;
        int total_edge=0;
        int total_value=0;
        while(total_edge!=n-1)
        {
            int min_value=INF;
            int min_terminal_village;
            int min_start_village;
            for(int i=0;i<vertex.size();i++)
            {
                int v=vertex[i];
                for(int j=1;j<=n;j++)
                {
                    if(j!=v&&!visited[j]&&distances[v][j]<min_value)
                    {
                        min_start_village=v;
                        min_terminal_village=j;
                        min_value=distances[v][j];
                    }
                }
            }
            total_value+=min_value;
            visited[min_terminal_village]=true;
            total_edge++;
            vertex.push_back(min_terminal_village);
        }
        cout<<total_value<<endl;
    }
    return 0;
}