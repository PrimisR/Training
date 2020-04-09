#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int a[5][5];

set<int> st;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};


void dfs(int x, int y, int k, int num)
{
    if (k == 6)
    {
        st.insert(num);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < 5 && 0 <= ny && ny < 5)
        {
            k++;
            dfs(nx, ny, k, num * 10 + a[nx][ny]);
            k--;
        }
    }
}

void solve()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dfs(i, j, 1, a[i][j]);
        }
    }
    printf("%d\n", st.size());
}

int main()
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            scanf("%d", &a[i][j]);
    }
    solve();

    return 0;
}