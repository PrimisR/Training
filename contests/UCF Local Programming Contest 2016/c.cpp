#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 55;

bool row[MAXN];
bool col[MAXN];
bool board[MAXN][MAXN];

int n, m;

void init()
{
    memset(row, true, sizeof(row));
    memset(col, true, sizeof(col));
    memset(board, true, sizeof(board));
}

bool legal(int x, int y)
{
    return !(x > n || y > n || x <= 0 || y <= 0);
}

bool fall(int x, int y) {
    return (!row[x] && !col[y]);
}

void check(int x,int y) {
    if(y == 0) {
        for(int i=1;i<=n;i++) {
            if(col[i] == false) {
                if(board[x][i] == false) continue;
                else {
                    board[x][i] = false;
                    check(0,i);
                }
            }
        }
    }
    else {
        for(int i=1;i<=n;i++) {
            if(row[i] == false) {
                if(board[i][y] == false) continue;
                else {
                    board[i][y] = false;
                    check(i,0);
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    int CASE = 0;
    while (T--)
    {
        init();
        int invalid = 0;
        cin >> n >> m;
        for(int i=1;i<=m;i++) {
            int x,y; cin>>x>>y;
            if(!board[x][y]) 
            {
                invalid++;
                continue;
            }
            board[x][y] = false;
            if(row[x]) {
                row[x] = false;
                check(x,0);
            }
            if(col[y]) {
                col[y] = false;
                check(0,y);
            }
        }
        cout << "Strategy #" << ++CASE << ": " << invalid << endl << endl;
    }
    return 0;
}
