/**
 * dfs
 * 考虑到可能某一行不摆放的情况
 * */
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10;

char board[MAXN][MAXN];
bool visited[MAXN];
int n,k;
int total;

void dfs(int row,int put) {
    if(put == k) {
        total++;
        return;
    }
    if(row >= n) return;
    for(int i=0;i<n;i++) {
        if(board[row][i] == '.' || visited[i]) continue;
        visited[i] = true;
        dfs(row+1,put+1);
        visited[i] = false;
    }
    dfs(row+1,put);
}

int main() {
    while(cin>>n>>k && n != -1) {
        total = 0;
        for(int i=0;i<n;i++) visited[i] = false;
        getchar();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>board[i][j];
            }
            getchar();
        }
        dfs(0,0);
        cout << total << endl;
    }
}