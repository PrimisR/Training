#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 25;

struct p
{
    int x;
    int y;
    p(int x, int y) : x(x), y(y) {}
    p() {}
};

int step[maxn][maxn];
int dir[8][2] = {{-2, -1}, {-2, 1}, {2, 1}, {2, -1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
int n;

bool valid(int x, int y)
{
    return step[x][y] == -1 && x <= n && y <= n && x >= 1 && y >= 1;
}

void bfs(int sx, int sy)
{
    queue<p> q;
    q.push(p(sx, sy));
    step[sx][sy] = 0;
    while (!q.empty())
    {
        p u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = u.x + dir[i][0];
            int ny = u.y + dir[i][1];
            if(valid(nx,ny)) {
                step[nx][ny] = step[u.x][u.y] + 1;
                q.push(p(nx,ny));
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        memset(step, -1, sizeof(step));
        cin >> n;
        int sx, sy;
        cin >> sx >> sy;
        int tx, ty;
        cin >> tx >> ty;
        bfs(sx,sy);
        cout << "Case #" << loop << ": " << step[tx][ty] << endl << endl;
    }
}