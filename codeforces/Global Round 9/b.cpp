#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
int board[400][400];
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int cat(int x, int y)
{
    if ((x == 1 && y == 1) || (x == 1 && y == m) || (x == n && y == 1) || (x == n && y == m))
        return 2;
    else if (x != 1 && x != n && y != 1 && y != m)
        return 4;
    else
        return 3;
}

int main()
{
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        bool good = true;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> board[i][j];
                if (board[i][j] > cat(i, j))
                    good = false;
            }
        }
        if (!good)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    cout << cat(i,j);
                    if(j != m) cout << " ";
                    else cout << endl;
                }
            }
        }
    }
    return 0;
}