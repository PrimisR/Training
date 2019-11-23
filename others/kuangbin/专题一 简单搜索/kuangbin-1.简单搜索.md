#### kuangbin-1.简单搜索

##### 1.简单DFS(深度优先搜索)

##### POJ 1321 棋盘问题

```c
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[10][10];     //记录棋盘位置
int book[10];        //记录一列是否已经放过棋子
int n,k;
int total,m;    //total 是放棋子的方案数 ，m是已放入棋盘的棋子数目

void DFS(int cur)
{
    if(k==m)
    {
        total++;
        return ;
    }
    if(cur>=n)    //边界

        return ;
    for(int j=0; j<n; j++)
        if(book[j]==0 && a[cur][j]=='#')  //判断条件
        {
            book[j]=1;           //标记
            m++;                 
            DFS(cur+1);
            book[j]=0;           //改回来方便下一行的判断
            m--;
        }
    DFS(cur+1);                //到下一行
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&k)&&n!=-1&&k!=-1) //限制条件
    {
        total=0;
        m=0;
        for(i=0; i<n; i++)
            scanf("%s",&a[i]);
        memset(book,0,sizeof(book));
        DFS(0);
        printf("%d\n",total);
    }
    return 0;
}
```

遇到的两个问题：1.**正确回溯**（恢复到放置前的状态） 2.※**有空行的情况**

※本题的DFS:

```C
void DFS(int cur)
{
    if(k==m)
    {
        total++;
        return ;
    }
    if(cur>=n)    

        return ;
    for(int j=0; j<n; j++)
        if(book[j]==0 && a[cur][j]=='#')  
        {
            book[j]=1;           
            m++;                 
            DFS(cur+1);
            book[j]=0;//由于确保了book[j]的标记仅由当前放置引起，可以正常恢复
            m--;
        }
    DFS(cur+1);//※这里的意思是跳过当前行，不进行放置               
}
```

这道题中DNF的思路是：对于某一行，有两种选择：

1. 遍历当前行，查找能够放置的位置，进行放置；
2. 不对当前行进行放置。

