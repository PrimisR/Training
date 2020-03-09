#### Quailty and CCPC

##### Problem Description

给定参赛人数n，和获奖人数百分比(10*d)%，看是否获奖人数恰好为OO.5名。

##### 思路：

排序，求模

##### 代码：

```C++
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct team
{
    char name[11];
    int solved;
    int penalty;

    bool operator < (const team &o) const
    {
        if(solved!=o.solved) return solved>o.solved;
        else return penalty<o.penalty;
    }
};

team teams[100100];
int T,n,d;
const char str[]="Quailty is very great";

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=0;i<n;i++)
        {
            scanf("%s %d %d",teams[i].name,&teams[i].solved,&teams[i].penalty);
        }
        int x=n*d;
        if(x%10!=5) printf("%s\n",str);
        else
        {
            sort(teams,teams+n);
            printf("%s\n",teams[x/10].name);
        }    
    }
    return 0;
}
```

