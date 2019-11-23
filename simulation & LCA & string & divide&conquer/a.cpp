/**
 * 方法一：
 * 前缀和,二分查找
 * 前缀和：S(n)-S(m);
 * 二分查找:对长度进行二分查找,条件为区间和>=S,升序为1->n
 * 区间长度大小取值 1~n
 * 先枚举所有 n/2 长度的区间，看有没有符合条件的
 * 符合条件：区间和>=s
 * 1.如果有，就可以在 1~n/2 里继续二分，没有必要再查找比 n/2 更长的区间
 * 2.如果没有，就可以在 n/2+1~n 里继续二分，没有必要再查找比 n/2 更短的区间
 * */

/**
 * 方法二：
 * 尺取法
 * */

#include <cstdio>
#include <iostream>

using namespace std;
const int MAXN=1e5;

int pre_sum[MAXN];
int n,s;

bool is_valid(int len)//每次进行一次条件判断的时间复杂度是O(n)
{
    for(int i=1;i<=n-len+1;i++)
    {
        int sum=pre_sum[i+len-1]-pre_sum[i-1];
        if(sum>=s) return true;
    }
    return false;     
}

void pre_sum_input()
{
    pre_sum[0]=0;//初始值
    cin>>pre_sum[1];
    for(int i=2;i<=n;i++)
    {
        int num;
        cin>>num;
        pre_sum[i]=num+pre_sum[i-1];
    }
}

int binarySearch()//最终能够确定最小长度的时间复杂度是O(log n)
{
    int ans=0;//如果没查找到则返回0
    int low=1,high=n,mid;
    while (low<=high)//二分出口
    {
        mid=low+(high-low)/2;
        if(is_valid(mid))
        {
            ans=mid;//由于不知道比目前mid小的长度还有没有符合条件的，要先记录ans
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>s;
        pre_sum_input();
        cout<<binarySearch()<<endl;
    }
    return 0;
}