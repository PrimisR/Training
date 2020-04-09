#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 10005

int n;
int dice[maxn][10];
int opp[7] =
{ 5, 3, 4, 1, 2, 0 };

void input()
{
    scanf("%d", &n);
for (int i = 0; i < n; i++)
for (int j = 0; j < 6; j++)
            scanf("%d", &dice[i][j]);
}

int getmax(int *f, int a, int b)
{
int ret = 0;
for (int i = 0; i < 6; i++)
if (i != a && i != b)
            ret = max(ret, f[i]);
return ret;
}

int find(int *f, int a)
{
for (int i = 0; i < 6; i++)
if (f[i] == a)
return i;
return -1;
}

void work()
{
int ans = 0;
for (int i = 0; i < 6; i++)
    {
int up = i;
int down = opp[up];
int sum = getmax(dice[0], up, down);
for (int j = 1; j < n; j++)
        {
            down = find(dice[j], dice[j - 1][up]);
            up = opp[down];
            sum += getmax(dice[j], up, down);
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
}

int main()
{
//freopen("t.txt", "r", stdin);
    int t;
    scanf("%d", &t);
while (t--)
    {
        input();
        work();
    }
return 0;
}