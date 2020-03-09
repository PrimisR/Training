#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1e4 + 10;
const int INF = 0x3f3f3f3f;
struct S
{
    char name[55];
    int p;
}s[110];
struct M
{
    char name[55];
    int p;
}m[110];
struct D
{
    char name[55];
    int p;
}d[110];

bool cmp_s(S x, S y)
{
    return x.p < y.p;
}

bool cmp_m(M x, M y)
{
    return x.p < y.p;
}

bool cmp_d(D x, D y)
{
    return x.p < y.p;
}

int main(void)      //ZOJ 3875 Lunch Time
{
    //freopen ("G.in", "r", stdin);

    int t;
    scanf ("%d", &t);
    while (t--)
    {
        int a, b, c;
        int tot = 0, s_id, m_id, d_id;

        scanf ("%d%d%d", &a, &b, &c);
        for (int i=1; i<=a; ++i)
        {
            scanf ("%s%d", &s[i].name, &s[i].p);
        }
        sort (s+1, s+1+a, cmp_s);
        for (int i=1; i<=b; ++i)
        {
            scanf ("%s%d", &m[i].name, &m[i].p);
        }
        sort (m+1, m+1+b, cmp_m);
        for (int i=1; i<=c; ++i)
        {
            scanf ("%s%d", &d[i].name, &d[i].p);
        }
        sort (d+1, d+1+c, cmp_d);

         if (a & 1)
         {
            tot += s[(a+1)/2].p;    s_id = (a+1) / 2;
         }
         else
         {
            int l = a / 2; int r = l + 1;
            if (s[l].p < s[r].p)
            {
                tot += s[r].p;  s_id = r;
            }
            else
            {
                tot += s[l].p;  s_id = l;
            }
         }
         if (b & 1)
         {
            tot += m[(b+1)/2].p;    m_id = (b+1) / 2;
         }
         else
         {
            int l = b / 2; int r = l + 1;
            if (m[l].p < m[r].p)
            {
                tot += m[r].p;  m_id = r;
            }
            else
            {
                tot += m[l].p;  m_id = l;
            }
         }
         if (c & 1)
         {
             tot += d[(c+1)/2].p;    d_id = (c+1) / 2;
         }
         else
         {
            int l = c / 2; int r = l + 1;
            if (d[l].p < d[r].p)
            {
                tot += d[r].p;  d_id = r;
            }
            else
            {
                tot += d[l].p;  d_id = l;
            }
         }

         printf ("%d %s %s %s\n", tot, s[s_id].name, m[m_id].name, d[d_id].name);
    }


    return 0;
}