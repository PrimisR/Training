/**
 * 生成正确的矩阵，然后比较两个矩阵
 * */

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char board[101][101];
char correct_board[101][101];

int m,n;

void clear_board() {
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            correct_board[i][j]='0';
        }
    }
}

void mark_board(int x,int y) {
    if(x<0||y<0||x>=m||y>=n) return;
    if(correct_board[x][y]=='*') return;
    correct_board[x][y]++;
}

void read() {
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            board[i][j]=getchar();
            if(board[i][j]=='.') board[i][j]='0';
            else if(board[i][j]=='*') {
                correct_board[i][j]='*';
                for(int x=i-1;x<i+2;x++) {
                    for(int y=j-1;y<j+2;y++) {
                        if(x==i&&y==j) continue;
                        mark_board(x,y);
                    }
                }
            }
        }
        getchar();
    }
}

bool equals() {
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(board[i][j]!=correct_board[i][j]) return false;
        }
    }
    return true;
}

int main()
{
    while(cin>>m>>n) {
        getchar();
        clear_board();
        read();
        string str=(equals())? "YES" : "NO";
        cout<<str<<endl;
    }
}