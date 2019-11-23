/**
 * 比赛相赢形成一个偏序关系，形成一个有向图
 * 算法：
 * 1.每次取入度为0的点，加入答案
 * 2.所有被该点指向的点入度-1（删除边）
 * 3.不断重复上述操作,直到所有点都被加入答案
 * */

#include <iostream>
#include <cstdio>
#include <list>

using namespace std;
const int MAXN=600;

list<int> post_vertex[MAXN];
list<int> answer;
int in_degree[MAXN];//0
bool chosen_as_answer[MAXN];//false

void init(int n)
{
    for(int i=1;i<=n;i++) 
    {
        post_vertex[i].clear();
        in_degree[i]=0;
        chosen_as_answer[i]=0;
    }
    answer.clear();
}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        init(n);
        while(m--)
        {
            int u,v;//(u,v),u->v
            cin>>u>>v;
            post_vertex[u].push_back(v);
            in_degree[v]++;
        }
        while(answer.size()!=n)
        {
            for(int i=1;i<=n;i++)
            {
                if(in_degree[i]==0&&!chosen_as_answer[i])
                {
                    for(list<int>::iterator it=post_vertex[i].begin();it!=post_vertex[i].end();it++)
                    {
                        in_degree[*it]--;
                    }
                    answer.push_back(i);
                    chosen_as_answer[i]=true;
                    break;
                }
            }
        }
        for(list<int>::iterator it=answer.begin();it!=answer.end();it++)
        {
            if(n!=1)
            {
                cout<<(*it)<<" ";
                n--;
            }
            else
                cout<<(*it)<<endl;   
        }
    }
    return 0;
}