/**
 * 求最大 斜率绝对值
 * 按x排序求相邻两点斜率
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 200005;

struct point
{
    double x;
    double y;
};

int cmp(point a, point b)
{
    return a.x < b.x;
}

point p[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    sort(p,p+n,cmp);
    double max_v = -1;
    for(int i=0;i<n-1;i++) {
        max_v = max(max_v,fabs(p[i+1].y-p[i].y)/fabs(p[i+1].x-p[i].x));
    }
    printf("%.12lf\n",max_v);
    return 0;
}