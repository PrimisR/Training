/**
 * 模拟策略:
 * doll只能在每一个格子向右旋转或者向前走，要求不重复地经过除了障碍物的每个格子，看能否做到
 * 每次一定是走到最远的距离再转向才有可能不重复地走过所有的格子，
 * 因为如果前面有格子再转向的话那么这个格子不可能再经过了
 * 迷宫情况复杂
 * 由于n,m很大而k很小，所以可以针对每行每列由当前位置走下去遇到的第一个障碍物，螺旋走下去
 * 为了避免走重复的格子，要记录走过的最大行和最大列，已经走过的最小行和最小列，
 * 那么当前行能走到的最远距离是由min(最远坐标，最近的障碍物)决定的
 * 
 * 为了寻找到遇到的第一个障碍物，可以用set存储，并用lower_bound查询
 * 注意的是要先判断第一次能否向右，因为第一次还有向下的机会
 * */
#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
const int MAXN = 100005;

long long n,m,k;
int x_max,y_max,x_min,y_min; //已经走过的范围(开区间)
int x,y; //当前位置
int dir; //方向

set<int> x_obs[MAXN];
set<int> y_obs[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=0;i<k;i++) {
        int ox,oy;
        cin>>ox>>oy;
        x_obs[ox].insert(oy);
        y_obs[oy].insert(ox);
    }
    //把外圈墙壁看作障碍物
    for(int i=1;i<=n;i++) {
        x_obs[i].insert(0);
        x_obs[i].insert(m+1);//最远的编号是m+1
    }
    for(int i=1;i<=m;i++) {
        y_obs[i].insert(0);
        y_obs[i].insert(n+1);
    }
    dir = 1;
    x = 1,y = 1; 
    x_max = n+1,y_max = m+1,x_min = 0,y_min = 0; //初始参数
    long long total = 1;
    //第一次之前没有走过，所以向右不能走不代表不能转向下，先要判断
    int changes = min((*x_obs[x].lower_bound(y)), y_max) - y - 1;
    if(changes == 0) {
        dir = 2;
        changes = 1;
    } //如果出门的路被堵死，就向下走
    while(changes) { //如果没有变化，那么结束
        switch (dir)
        {
        case 1: //向右走,从上到下是x，从左向右是y,找到最近的障碍物(小于等于)
            changes = min((*x_obs[x].lower_bound(y)), y_max) - y - 1;
            x_min = x; //向右走改变了x的最小范围(因为之前是走上来的)
            y += changes;
            break;

        case 2: //向下走
            changes = min((*y_obs[y].lower_bound(x)), x_max) - x - 1;
            y_max = y;
            x += changes;
            break;

        case 3: //向左走(--上一个就是比y小的，因为不存在重复的obstacle，而且必然存在两个墙壁)
            changes = y - max(*(--x_obs[x].lower_bound(y)), y_min) - 1;
            x_max = x;
            y -= changes;
            break;

        case 4://向上走
            changes = x - max(*(--y_obs[y].lower_bound(x)), x_min) - 1;
            y_min = y;
            x -= changes;
            break;
        }
        // cout << "coord:" << x << " " << y << endl;
        // cout << "dir:" << dir << endl;
        // cout << "changes:" << changes << endl;
        // cout << "xmax:" << x_max << "ymax:" << y_max << "xmin:" << x_min << "ymin:" << y_min << endl;
        total += changes;
        dir = (dir)%4 +1;
    }
    //cout << total << endl;
    if(total + k == n*m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
