#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
 
 
 
#define pi acos(-1)
#define endl '\n'
#define me(x) memset(x,0,sizeof(x));
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
typedef long long LL;
const int INF=0x3f3f3f3f;
const LL LINF=0x3f3f3f3f3f3f3f3fLL;
const int dx[]={-1,0,1,0,-1,-1,1,1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
const int maxn=1e3+5;
const int maxx=1e7+1;
const double EPS=1e-7;
const int mod=1000000007;
template<class T>inline T min(T a,T b,T c) { return min(min(a,b),c);}
template<class T>inline T max(T a,T b,T c) { return max(max(a,b),c);}
template<class T>inline T min(T a,T b,T c,T d) { return min(min(a,b),min(c,d));}
template<class T>inline T max(T a,T b,T c,T d) { return max(max(a,b),max(c,d));}
struct node
{
    double x, y;
};
double getk(node a, node b)
{
    if(a.x == b.x)
        return 0.0;
    return (b.x - a.x) / (b.y - a.y) * -1;
}
double dist(node a, node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
 
int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        node a, b, c, p;
        scanf("%lf %lf", &a.x, &a.y);
        scanf("%lf %lf", &b.x, &b.y);
        scanf("%lf %lf", &c.x, &c.y);
        scanf("%lf %lf", &p.x, &p.y);
        if(a.y == b.y)
            swap(b,c);
        if(b.y == c.y)
            swap(a,b);
        double k0 = getk(a, b);
        double k1 = getk(b, c);
        node cc, p0, p1;
        p0.x = 0.5 * (a.x + b.x);
        p0.y = 0.5 * (a.y + b.y);
        p1.x = 0.5 * (b.x + c.x);
        p1.y = 0.5 * (b.y + c.y);
        cc.x = (k0 * p0.x - p0.y - k1 * p1.x + p1.y) / (k0 - k1);
        cc.y = k0 * (cc.x - p0.x) + p0.y;
        double r = (cc.x-a.x)*(cc.x-a.x) + (cc.y-a.y)*(cc.y-a.y);
        double ab = dist(a,b);
        double bc = dist(b,c);
        double ac = dist(a,c);
        double maxx = max(ab, bc, ac);
        int flag = 1;
        if(maxx == ab && ((bc*bc+ac*ac-ab*ab)/2*bc*ac < 0))
        {
            flag = 0;
            cc.x = 0.5 * (a.x + b.x);
            cc.y = 0.5 * (a.y + b.y);
            r = ab / 2 * ab / 2;
        }
        else if(maxx == bc && ((ab*ab+ac*ac-bc*bc)/2*ab*ac < 0))
        {
            flag = 0;
            cc.x = 0.5 * (b.x + c.x);
            cc.y = 0.5 * (b.y + c.y);
            r = bc * bc / 4;
        }
        else if(maxx == ac && ((ab*ab+bc*bc-ac*ac)/2*ab*bc < 0))
        {
            flag = 0;
            cc.x = 0.5 * (a.x + c.x);
            cc.y = 0.5 * (a.y + c.y);
            r = ac * ac / 4;
        }
        if((cc.x-p.x)*(cc.x-p.x) + (cc.y-p.y)*(cc.y-p.y) - r < EPS)
            printf("Case #%d: Danger\n", i);
        else
            printf("Case #%d: Safe\n", i);
 
    }
    return 0;
}