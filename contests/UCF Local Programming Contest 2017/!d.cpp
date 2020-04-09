/**
 * bfs
 * */
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct node
{
    int step;
    int r;
    int c;
    node(int step, int r, int c) : step(step), r(r), c(c) {}
    node() {}
};

bool visited[125][85];
// int b[125][85];
int len[125];
int sr, sc;
int tr, tc;
int n;

int bfs()
{
    queue<node> q;
    q.push(node(0, sr, sc));
    while (!q.empty())
    {
        node u = q.front();
        q.pop();
        if (u.r == tr && u.c == tc)
            return u.step;
        if (visited[u.r][u.c])
            continue;
        visited[u.r][u.c] = true;
        // b[u.r][u.c] = u.step;
        //up
        if (u.r != 1)
        {
            if (u.c >= len[u.r - 1])
            {
                q.push(node(u.step + 1, u.r - 1, len[u.r - 1]));
            }
            else
            {
                q.push(node(u.step + 1, u.r - 1, u.c));
            }
        }
        //down
        if (u.r != n)
        {
            if (u.c >= len[u.r + 1])
            {
                q.push(node(u.step + 1, u.r + 1, len[u.r + 1]));
            }
            else
            {
                q.push(node(u.step + 1, u.r + 1, u.c));
            }
        }
        //left
        if (u.c != 0)
        {
            q.push(node(u.step + 1, u.r, u.c - 1));
        }
        else
        {
            if (u.r != 1)
            {
                q.push(node(u.step + 1, u.r - 1, len[u.r - 1]));
            }
        }
        //right
        if (u.c != len[u.r])
        {
            q.push(node(u.step + 1, u.r, u.c + 1));
        }
        else
        {
            if (u.r != n)
            {
                q.push(node(u.step + 1, u.r + 1, 0));
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 125; i++)
        {
            for (int j = 0; j < 85; j++)
            {
                visited[i][j] = false;
            }
        }
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> len[i];
        }
        cin >> sr >> sc >> tr >> tc;
        cout << bfs() << endl;

        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j < 58; j++)
        //     {
        //         printf("%02d ",b[i][j]);
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}