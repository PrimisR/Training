#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 20;

char matrix[maxn][maxn];
bool visited[maxn][maxn];
int n, m;
const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool dead(int dir, int x, int y)
{
    int nx = x + d[dir][0];
    int ny = y + d[dir][1];
    return visited[nx][ny] || nx < 0 || ny < 0 || nx >= n || ny >= m;
}

int main()
{
    int CASE = 0;
    while (cin >> n >> m && n && m)
    {
        memset(visited, false, sizeof(visited));
        getchar();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
            getchar();
        }
        int x = 0, y = -1;
        int dir = 0;
        cout << "Matrix #" << ++CASE << ":" << endl;
        cout << "Original:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << matrix[i][j];
                if (j != m - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
        cout << "Snail:" << endl;
        while (!dead(dir, x, y))
        {
            vector<char> route;
            while (!dead(dir, x, y))
            {
                x = x + d[dir][0];
                y = y + d[dir][1];
                route.push_back(matrix[x][y]);
                visited[x][y] = true;
            }
            for (int i = 0; i < route.size(); i++)
            {
                cout << route[i];
                if (i != route.size() - 1)
                {
                }
                else
                {
                    cout << endl;
                }
            }
            dir = (dir + 1) % 4;
        }
        cout << endl;
    }
}