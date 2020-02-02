#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 105;

char field[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N,M;

void dfs(int x,int y) {
    if(visited[x][y]) return;
    visited[x][y] = true;
    if(x-1 >= 0 && y-1 >= 0 && field[x-1][y-1] == 'W') dfs(x-1,y-1);
    if(x-1 >= 0 && field[x-1][y] == 'W') dfs(x-1,y);
    if(x-1 >= 0 && y+1 < M && field[x-1][y+1] == 'W') dfs(x-1,y+1);
    if(y-1 >= 0 && field[x][y-1] == 'W') dfs(x,y-1);
    if(y+1 < M && field[x][y+1] == 'W') dfs(x,y+1);
    if(x+1 < N && y-1 >=0 && field[x+1][y-1] == 'W') dfs(x+1,y-1);
    if(x+1 < N && field[x+1][y] == 'W') dfs(x+1,y);
    if(x+1 < N && y+1 < M && field[x+1][y+1] == 'W') dfs(x+1,y+1);
}

int main() {
    while(cin>>N>>M) {
        getchar();
        int total = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                cin>>field[i][j];
                visited[i][j] = false;
            }
            getchar();
        }
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(visited[i][j] || field[i][j] == '.') continue;
                dfs(i,j);
                total++;
            }
        }
        cout << total <<endl;
    }
    return 0;
}