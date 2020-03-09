---
title:Block Breaker
---

#### Block Breaker

模拟：

1.注意砖块掉落的条件

2.注意砖掉落的影响

3.队列处理(bfs)

数据量比较大，关闭ios同步:

```c++
ios::sync_with_stdio(false);
```

```c++
/**
 * 一块砖掉落的条件：砖的左右其中至少有一块掉了，并且砖的上下至少有一块掉了
 * 一块砖掉了的影响：应该检测上下左右是否仍然存在，如果有掉落的砖，应该继续这个操作
 * 边界标记：边界的外面是当作有敲不掉的砖的
 * 考虑用队列来处理
 * */

#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
#include <map>

using namespace std;

const int MAXN=2000;

bool breaks[MAXN+2][MAXN+2];

int n,m;

bool is_frame(pair<int,int> pos)//是不是边上的那个砖块
{
    return (pos.first==0||pos.second==0||pos.first==n+1||pos.second==m+1);
}

bool is_fall(pair<int,int> pos)
{
    if(is_frame(pos)) return false;//边缘的砖块不掉落
    if(!breaks[pos.first][pos.second]) return false;//已经掉下去的砖不能再掉下去一次
    if((breaks[pos.first+1][pos.second]&&breaks[pos.first-1][pos.second])||(breaks[pos.first][pos.second+1]&&breaks[pos.first][pos.second-1])) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        memset(breaks,true,sizeof(breaks));
        int q;
        cin>>n>>m>>q;
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            if(!breaks[x][y]) {cout<<"0"<<endl; continue;}
            int fall_breaks=1;
            queue< pair<int,int> > check_queue;
            check_queue.push(pair<int,int>(x+1,y));
            check_queue.push(pair<int,int>(x-1,y));
            check_queue.push(pair<int,int>(x,y+1));
            check_queue.push(pair<int,int>(x,y-1));
            breaks[x][y]=false;
            while(!check_queue.empty())
            {
                pair<int,int> pos=check_queue.front(); check_queue.pop();
                if(is_fall(pos))
                {
                    check_queue.push(pair<int,int>(pos.first+1,pos.second));
                    check_queue.push(pair<int,int>(pos.first-1,pos.second));
                    check_queue.push(pair<int,int>(pos.first,pos.second+1));
                    check_queue.push(pair<int,int>(pos.first,pos.second-1));
                    fall_breaks++;
                    breaks[pos.first][pos.second]=false;
                }
            }
            cout<<<<fall_breaks<<endl;
        }
    }
    return 0;
}
```

