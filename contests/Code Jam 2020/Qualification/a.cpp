#include <cstdio>
#include <iostream>

using namespace std;

const int N = 105;

int matrix[N][N];

bool row_vis[N][N]; // i-th row
bool col_vis[N][N]; // i-th col

bool check_row(int x,int n) {
    for(int i=1;i<=n;i++) {
        if(row_vis[x][matrix[x][i]]) return false;
        row_vis[x][matrix[x][i]] = true;
    }
    return true;
}

bool check_col(int y,int n) {
    for(int i=1;i<=n;i++) {
        if(col_vis[y][matrix[i][y]]) return false;
        col_vis[y][matrix[i][y]] = true;
    }
    return true;
}

int main() {
    int T; cin>>T;
    int CASE = 0;
    while(T--) {
        int n; cin>>n;
        int trace = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                row_vis[i][j] = false;
                col_vis[i][j] = false;
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cin>>matrix[i][j];
            }
        }
        for(int i=1;i<=n;i++) {
            trace += matrix[i][i];
        }
        int row = 0;
        int col = 0;
        for(int i=1;i<=n;i++) {
            if(!check_row(i,n)) row++;
            if(!check_col(i,n)) col++;
        }
        cout << "Case #" << ++CASE << ": " << trace << " " << row << " " << col << endl;
    }
    return 0;
}