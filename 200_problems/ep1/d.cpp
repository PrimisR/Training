/**
 * 寻找最近的点，使用广度优先搜索
 * */

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 305;
const char SAFE = 'S';
const char DESTROYED = 'D';
const char UNSAFE = 'U';

struct meteor {
    int x;
    int y;
    int t;
};
meteor meteors[50005];
int cursor = 0;
int M;

int cmp(meteor a,meteor b) {
    return a.t < b.t;
}

struct maze {
    int length;
    int x;
    int y;
    maze():length(0){}
    maze(int length,int x,int y):length(length),x(x),y(y){}
};

char map[MAXN][MAXN];
bool visited[MAXN][MAXN];//之前访问过的路径一定更短

void mark(int x,int y,char MARK) {
    if(x < 0 || y < 0) return;
    map[x][y] = MARK;
}

bool check(int x,int y) {
    return !(x < 0 || y < 0 || 
    visited[x][y] || map[x][y] == DESTROYED);
}

int bfs() {
    queue<maze> q;
    if(map[0][0] != DESTROYED) {
        q.push(maze(0,0,0));
        visited[0][0] = true;
    }
    while(!q.empty()) {
        maze u = q.front(); q.pop();
        if(map[u.x][u.y] == SAFE) return u.length;
        for(;cursor < M && meteors[cursor].t == u.length+1;cursor++) {
            mark(meteors[cursor].x,meteors[cursor].y,DESTROYED);
            mark(meteors[cursor].x+1,meteors[cursor].y,DESTROYED);
            mark(meteors[cursor].x-1,meteors[cursor].y,DESTROYED);
            mark(meteors[cursor].x,meteors[cursor].y+1,DESTROYED);
            mark(meteors[cursor].x,meteors[cursor].y-1,DESTROYED);
        }
        if(check(u.x+1,u.y)) {q.push(maze(u.length+1,u.x+1,u.y)); visited[u.x+1][u.y] = true;}
        if(check(u.x-1,u.y)) {q.push(maze(u.length+1,u.x-1,u.y)); visited[u.x+1][u.y] = true;}
        if(check(u.x,u.y+1)) {q.push(maze(u.length+1,u.x,u.y+1)); visited[u.x+1][u.y] = true;}
        if(check(u.x,u.y-1)) {q.push(maze(u.length+1,u.x,u.y-1)); visited[u.x+1][u.y] = true;}
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    for(int i=0;i<MAXN;i++) {
        for(int j=0;j<MAXN;j++) {
            map[i][j] = SAFE;
            visited[i][j] = false;
        }
    }
    cin>>M;
    for(int i=0;i<M;i++) {
        cin>>meteors[i].x>>meteors[i].y>>meteors[i].t;
        if(meteors[i].t == 0) {
            mark(meteors[i].x,meteors[i].y,DESTROYED);
            mark(meteors[i].x+1,meteors[i].y,DESTROYED);
            mark(meteors[i].x-1,meteors[i].y,DESTROYED);
            mark(meteors[i].x,meteors[i].y+1,DESTROYED);
            mark(meteors[i].x,meteors[i].y-1,DESTROYED);
        }
        else {
            mark(meteors[i].x,meteors[i].y,UNSAFE);
            mark(meteors[i].x+1,meteors[i].y,UNSAFE);
            mark(meteors[i].x-1,meteors[i].y,UNSAFE);
            mark(meteors[i].x,meteors[i].y+1,UNSAFE);
            mark(meteors[i].x,meteors[i].y-1,UNSAFE);
        }
    }
    sort(meteors,meteors+M,cmp);
    for(int i=0;i<M;i++) {
        if(meteors[i].t == 0) {
            cursor++;
        }
        else break;
    }
    cout << bfs() << endl;
    return 0;
}

/*
预处理所有格子最小摧毁时间
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
const int MAXN = 305;
const int inf = 1005;

struct maze {
    int length;
    int x;
    int y;
    maze():length(0){}
    maze(int x,int y,int length):length(length),x(x),y(y){}
};

int fall_time[MAXN][MAXN];
bool visited[MAXN][MAXN];//之前访问过的路径一定更短

void update(int x,int y,int t) {
    if(x < 0 || y < 0) return;
    fall_time[x][y] = min(fall_time[x][y],t);
}

bool check(int x,int y,int t) {
    return !(x < 0 || y < 0 || visited[x][y] || t >= fall_time[x][y]);
}

int bfs() {
    queue<maze> q;
    if(fall_time[0][0] != 0) {
        q.push(maze(0,0,0));
        visited[0][0] = true;
    }
    while(!q.empty()) {
        maze u = q.front(); q.pop();
        if(fall_time[u.x][u.y] == inf) return u.length;
        if(check(u.x+1,u.y,u.length+1)) {q.push(maze(u.x+1,u.y,u.length+1)); visited[u.x+1][u.y] = true;}
        if(check(u.x-1,u.y,u.length+1)) {q.push(maze(u.x-1,u.y,u.length+1)); visited[u.x-1][u.y] = true;}
        if(check(u.x,u.y+1,u.length+1)) {q.push(maze(u.x,u.y+1,u.length+1)); visited[u.x][u.y+1] = true;}
        if(check(u.x,u.y-1,u.length+1)) {q.push(maze(u.x,u.y-1,u.length+1)); visited[u.x][u.y-1] = true;}
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    for(int i=0;i<MAXN;i++) {
        for(int j=0;j<MAXN;j++) {
            fall_time[i][j] = inf;
            visited[i][j] = false;
        }
    }
    int M;
    cin>>M;
    for(int i=0;i<M;i++) {
        int x,y,t;
        cin>>x>>y>>t;
        update(x,y,t);
        update(x+1,y,t);
        update(x-1,y,t);
        update(x,y+1,t);
        update(x,y-1,t);
    }
    cout << bfs() << endl;
    return 0;
}
*/