/**
 * 二分图匹配
 * 我们对每行和每列进行编号，如果行或列有墙，就对墙后的行列重新编号
 * 例如：
 * X...
 * ....
 * X.X.
 * ....
 * ->列编号：
 * X346
 * 1346
 * X3X6
 * 2356
 * ->行编号：
 * X111
 * 2222
 * X3X4
 * 5555
 * 而二分图的边，则是将同一个格子内的行和列编号连接起来，也就是说，当选择了一个行，则同时也占有了这一列
 * 然后求二分图的最大匹配数
 * */

/**
 * 二分图最大匹配-匈牙利算法
 * */

#include <cstdio>
#include <iostream>
#include <memory.h>

using namespace std;

const int MAXN = 5;
int uN,vN;
int g[MAXN*MAXN][MAXN*MAXN];
int linker[MAXN*MAXN];
bool used[MAXN*MAXN];

bool dfs(int u) {
    int v=0;
    for(v=0; v<=vN; v++) {
        if(g[u][v] && !used[v]) {
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary() {
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for(int u=0;u<=uN;u++) {
        memset(used, false, sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}

int n;
int row_mark[MAXN][MAXN];
int line_mark[MAXN][MAXN];
char city[MAXN][MAXN];

void edge(int a, int b) {
    g[a][b] = 1;
}

int main() {
    while(cin>>n && n != 0) {
        uN = 0;
        vN = 0;
        memset(row_mark, 0, sizeof(row_mark));
        memset(line_mark, 0, sizeof(line_mark));
        memset(g, 0, sizeof(g));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>city[i][j];
            }
        }
        for(int i=0;i<n;i++) {
            uN++;
            for(int j=0;j<n;j++) {
                if(city[i][j] == 'X') {
                    uN++;
                    g[i][j] = 0;
                    continue;
                }
                row_mark[i][j] = uN;
            }
        }
        for(int j=0;j<n;j++) {
            vN++;
            for(int i=0;i<n;i++) {
                if(city[i][j] == 'X') {
                    vN++;
                    g[i][j] = 0;
                    continue;
                }
                line_mark[i][j] = vN;
            }
        } 
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(city[i][j] == 'X') continue;
                edge(row_mark[i][j],line_mark[i][j]);
            }
        }
        cout<<hungary()<<endl;
    }
}
