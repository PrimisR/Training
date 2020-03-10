/**
 * 给定一组序列，然后在所有的这个序列的循环序列中(把第一个数放到最后)
 * 求最小的序列逆序数值
 * 
 * 求初始序列的逆序数(无重复数)
 * 对于每个数，首先知道自己在序列中的排序位置(排序)
 * 在不断地读入序列的过程中，每个数的逆序数=排序位数-前面比自己小的数的个数+1
 * 比如：2 5 3 1 4
 * 3排第3，前面有1,2,而2在前面，说明3后面有1个比自己小的,逆序数为1
 * 那么怎么知道自己前面有几个比自己小的数?
 * 树状数组查询前缀即可。(对离散化后的id查询)
 * 
 * 对于每个循环序列之间的逆序数有递推关系
 * 假设此时序列第一id是x(序列中的排位,以1为底)
 * 那么后面有(x-1)个数比x小，移到后面去就会减少(x-1)个逆序对
 * 相应增加(n-x)个逆序对
 * */
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 5005;

int arr[MAXN];
int tree[MAXN];
//全排列，可认为id是i+1
inline int id(int x)
{
    return x + 1;
}
inline int lowbit(int x)
{
    return x & (-x);
}
inline void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        tree[i] = 0;
    }
}
//更新某点
void upd(int x)
{
    for (; x <= MAXN; x += lowbit(x))
        tree[x]++;
}
//查询比x小的数之前插入了多少个
int find(int x)
{
    int out = 0;
    for (; x >= 1; x -= lowbit(x))
        out += tree[x];
    return out;
}

int main()
{
    int n;
    while (cin >> n)
    {
        init();
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            int x = id(arr[i]);
            ans += x - 1 - find(x);
            upd(x);
        }
        int u = ans;
        for (int i = 1; i <= n - 1; i++)
        {
            int x = id(arr[i]);
            u = u - (x - 1) + (n - x); //因为此时x在第一个,后面有(x-1)个比x小的数
            if (u < ans)
                ans = u;
        }
        cout << ans << endl;
    }
    return 0;
}
