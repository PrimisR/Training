#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 300005;

struct num
{
    int input;
    int val;
};

num a[MAXN];
int ra[MAXN];
int tree[MAXN];
int n;
vector<int> ans;

int cmp(num a, num b)
{
    return a.val < b.val;
}

void init()
{
    for (int i = 1; i <= n; i++)
        tree[i] = 0;
}

int lowbit(int x)
{
    return x & (-x);
}

void upd(int x)
{
    for (; x <= n; x += lowbit(x))
        tree[x]++;
}

int find(int x)
{
    int ans = 0;
    for (; x >= 1; x -= lowbit(x))
        ans += tree[x];
    return ans;
}

void discrete()
{
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        ra[a[i].input] = i;
    }
}

bool search()
{
    init();
    upd(ra[1]);
    for (int i = 2; i < n; i++)
    {
        int smaller = find(ra[i]);
        int larger = find(n) - smaller;
        if (larger == 0)
        {
            upd(ra[i]);
            continue;
        }
        if(find(n) - find(n-larger) != larger) return true;
        //只要最大的几个数都没有提前插入
        upd(ra[i]);
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].val;
            a[i].input = i;
        }
        discrete();
        if (search())
            ans.push_back(k);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
