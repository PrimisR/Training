#### Stay Real

##### Problem Description:

给一个最小堆，S和E轮流拿取子节点分数，使得自己的分数最大，S先开始，求S,E的分数。

##### Input：

$T$-test cases

$n$-number of nodes

$h_1,h_2...h_n$-key of the $i-th$ node(根据堆的编号，父节点为$i$,左节点为$2i$,右结点为$2i+1$)

##### Output:

$S,E$

##### 知识点：

##### 堆：

1. 完全二叉树
2. 某节点的值不大于或不小于其父节点的值

##### 最小堆：

根节点最小的堆。即节点值都不小于其父节点的值。

##### 最大堆：

根节点最大的堆。即节点值都不大于其父节点的值。

##### 思路：

最小堆，因为当前所有节点值最大的点一定是叶子结点，所以可以采用贪心的思路，每次拿取整个堆中节点值最大的结点。

对数组进行排序即可。

##### 代码：

```c++
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1e6;
int heap[maxn];

int cmp(int a,int b) {return a>b;}

int main()
{
    int T;
    cin>>T;
    int n;
    long long s,e;
    
    while(T--)
    {
        s=0;
        e=0;
        cin>>n;
        for(int i=0;i<n;i++) scanf("%d",&heap[i]);
        sort(heap,heap+n,cmp);
        
        int flag=1;
        for(int i=0;i<n;i++,flag^=1)
        {
            if(flag) s+=heap[i];
            else e+=heap[i];
        }
        cout<<s<<" "<<e<<endl;
    }
    return 0;
}
```

