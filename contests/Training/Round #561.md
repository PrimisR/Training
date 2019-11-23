#### Round #561

##### a.

统计数量太大，是long long的...

##### c.

首先确定条件，小的数是大数的绝对值的一半及其以上才可以，故可以排序，然后二分查找一半，再进行双指针，计算两个元素中间的数量

AC代码：

```c++
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;

int cmp(int a,int b)
{return a<b;}

int abs(int x)
{
    if(x>=0) return x;
    return -x;
}

int main()
{
    int x;
    long long pairs=0;
    scanf("%d",&x);
    while(x--)
    {
        int a;
        scanf("%d",&a);
        a=abs(a);
        v.push_back(a);
    }
    sort(v.begin(),v.end(),cmp);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
//        cout<<(*it)<<endl;
        vector<int>::iterator mid=lower_bound(v.begin(),it,((*it)+1)/2);//二分查找
//        cout<<(*mid)<<endl;
        pairs+=(it-mid);
    }
    cout<<pairs<<endl;
    return 0;
}
```

