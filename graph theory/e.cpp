/**
 * 一个矩阵R行C列，起始点在左上角,每个元素有一个高度E
 * 初始速度是V，当Bessie从A高度滑到B高度，速度就乘以2^(A-B)
 * 从第一个区块到第二个区块所用时间是他在第一个区块速度的倒数
 * 问到右下角最短时间
 * 
 * 思路:实际上每一点的速度都是固定的，假设起始点是a，终点是c，路过b
 * 那么c点的速度是V*2^(a-b)*2(b-c) = V*2(a-c)
 * 和b完全无关，所以从某一点到其他某点的时间是固定的
 * t = 1/(V*2^(a-c))
 * 将矩阵转换成一个无向图求最短路即可
 * */
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 10000 + 10;
#define INF 10000000000

int R, C;
double v[100 + 5][100 + 5];
int height[100 + 5][100 + 5];
int dr[] = {-1, 1, 0, 0}; //上下左右
int dc[] = {0, 0, -1, 1};

struct Edge
{
    int from, to;
    double dist;
    Edge(int from, int to, double dist) : from(from), to(to), dist(dist) {}
};

struct HeapNode
{
    double d;
    int u;
    HeapNode(double d, int u) : d(d), u(u) {}
    bool operator<(const HeapNode &rhs) const
    {
        return d > rhs.d;
    }
};

struct Dijkstra
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];
    double d[maxn];
    int p[maxn];

    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, double dist)
    {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m - 1);
    }

    void dijkstra()
    {
        priority_queue<HeapNode> Q;
        for (int i = 0; i < n; i++)
            d[i] = INF;
        d[0] = 0.0;
        memset(done, 0, sizeof(done));
        Q.push(HeapNode(d[0], 0));

        while (!Q.empty())
        {
            HeapNode x = Q.top();
            Q.pop();
            int u = x.u;
            if (done[u])
                continue;
            done[u] = true;

            for (int i = 0; i < G[u].size(); i++)
            {
                Edge &e = edges[G[u][i]];
                if (d[e.to] > d[u] + e.dist)
                {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    Q.push(HeapNode(d[e.to], e.to));
                }
            }
        }
    }
} DJ;

int main()
{
    scanf("%lf%d%d", &v[0][0], &R, &C);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &height[i][j]);
            if (i != 0 || j != 0)
            {
                v[i][j] = v[0][0] * pow(2.0, height[0][0] - height[i][j]); //速度
            }
        }

    DJ.init(R * C);

    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
        {
            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C)
                {
                    DJ.AddEdge(r * C + c, nr * C + nc, 1.0 / v[r][c]); //错误2,之前写成了 r*R+c,nr*R+nc
                }
            }
        }

    DJ.dijkstra();

    printf("%.2f\n", DJ.d[R * C - 1]); //%.2f输出

    return 0;
}