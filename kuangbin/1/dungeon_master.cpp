#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 31;
const char ROCK = '#';
const char EMPTY = '.';
const char START = 'S';
const char EXIT = 'E';

struct coord
{
    int l;
    int r;
    int c;
    coord(){}
    coord(int l,int r,int c):l(l),r(r),c(c){}

    bool operator== (coord co) const{
        return (l == co.l) && (r == co.r) && (c == co.c);
    } 
};

struct maze
{
    coord cur;
    int length;
    maze():length(0){}
    maze(coord cur,int length):cur(cur),length(length){}
};

char dungeon[MAXN][MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN];
int L,R,C;
coord s,e;

bool is_blocked(int l,int r, int c) {
    if(l < 0 || r < 0 || c < 0 
    || l >= L || r >= R || c >= C) return true;
    else if(dungeon[l][r][c] == ROCK) return true;
    return false;
}

int bfs() {
    queue<maze> q;
    q.push(maze(s,0));
    while (!q.empty())
    {
        maze u = q.front(); q.pop();
        if(u.cur == e) return u.length;
        //###ATTENTION-VISITED###
        if(visited[u.cur.l][u.cur.r][u.cur.c]) continue;
        visited[u.cur.l][u.cur.r][u.cur.c] = true;
        
        if(!is_blocked(u.cur.l+1,u.cur.r,u.cur.c))
            q.push(maze(coord(u.cur.l+1,u.cur.r,u.cur.c),u.length+1));
        if(!is_blocked(u.cur.l-1,u.cur.r,u.cur.c))
            q.push(maze(coord(u.cur.l-1,u.cur.r,u.cur.c),u.length+1));
        if(!is_blocked(u.cur.l,u.cur.r+1,u.cur.c))
            q.push(maze(coord(u.cur.l,u.cur.r+1,u.cur.c),u.length+1));
        if(!is_blocked(u.cur.l,u.cur.r-1,u.cur.c))
            q.push(maze(coord(u.cur.l,u.cur.r-1,u.cur.c),u.length+1));
        if(!is_blocked(u.cur.l,u.cur.r,u.cur.c+1))
            q.push(maze(coord(u.cur.l,u.cur.r,u.cur.c+1),u.length+1));
        if(!is_blocked(u.cur.l,u.cur.r,u.cur.c-1))
            q.push(maze(coord(u.cur.l,u.cur.r,u.cur.c-1),u.length+1));
    }
    return -1;
}

int main()
{
    while(cin>>L>>R>>C && L != 0) {
        for(int l=0;l<L;l++) {
            for(int r=0;r<R;r++) {
                for(int c=0;c<C;c++) {
                    visited[l][r][c] = false;
                    cin>>dungeon[l][r][c];
                    if(dungeon[l][r][c] == START)
                        s = coord(l,r,c);
                    else if(dungeon[l][r][c] == EXIT)
                        e = coord(l,r,c);
                }
            }
        }
        int result = bfs();
        if(result == -1) {
            cout << "Trapped!" << endl;
        }
        else {
            cout << "Escaped in " << result << " minute(s)." << endl;
        }
    }
    return 0;
}