/**
 * 巧妙的贪心思想
 * 每两头牛进行比较，与后面的牛无关
 * */
#include <cstdio>
#include <algorithm>
using namespace std;

struct spair
{
    int id;
    int time;
    int flower;
}pairs[100005];

int cmp(spair p1,spair p2)
{
    return p1.time*1.0/p1.flower<p2.time*1.0/p2.flower;
}

int main()
{
    int n;
    long long total;
    long long sumflower;
    while(~scanf("%d",&n))
    {
    total=0;
    sumflower=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&(pairs[i].time),&(pairs[i].flower));
        sumflower+=pairs[i].flower;
        pairs[i].id=i+1;
    }
    sort(pairs,pairs+n,cmp);
    for(int i=0;i<n;i++)
    {
        sumflower-=pairs[i].flower;
        total+=pairs[i].time*sumflower*2;
    }
    printf("%lld\n",total);
    }
    return 0;
}