/**
 * 这道题两个人只需要知道彼此的数字就可以，不必要精确地知道哪两对是对的
 * 所以在暴力比较完所有的对数之后，比较这个表格的每一行每一列
 * 如果某一行或某一列得出两个不同的数，那么谁也不知道
 * 如果某一行或某一列仅仅得出一个不同的数，那么记录下来
 * 最后统计一下，如果记录的数只有一种，那么所有人都知道，如果有多种，则(一定能保证)彼此知道
 * 
 * 从我的角度来看，只有两人拿着自己手里的数去查询表格
 * */
#include <cstdio>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int MAXN = 15;
pair<int,int> p1[MAXN];
pair<int,int> p2[MAXN];
int cmp_result[MAXN][MAXN];
set<int> count_set;
int n,m;

int equal(pair<int,int> a,pair<int,int> b) {
    if((a.first == b.first && a.second == b.second) ||
    (a.first == b.second && a.second == b.first)) return -1;//完全相同
    else if((a.first != b.first && a.second != b.second) &&
    (a.first != b.second) && (a.second != b.first)) return -1; //完全相异
    else {
        return ((a.first == b.first) || (a.first == b.second))? a.first:a.second; //返回相同的值
    }
}

int answer() {
    for(int i=0;i<n;i++) {
        set<int> s;
        for(int j=0;j<m;j++) {
            if(cmp_result[i][j] == -1) continue;
            s.insert(cmp_result[i][j]);
        }    
        if(s.size() == 1) count_set.insert((*s.begin()));
        else if(s.size() > 1) return -1;
    } 
    for(int j=0;j<m;j++) {
        set<int> s;
        for(int i=0;i<n;i++) {
            if(cmp_result[i][j] == -1) continue;
            s.insert(cmp_result[i][j]);
        }
        if(s.size() == 1) count_set.insert((*s.begin()));
        else if(s.size() > 1) return -1;
    }
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>p1[i].first>>p1[i].second;
    }
    for(int i=0;i<m;i++) {
        cin>>p2[i].first>>p2[i].second;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cmp_result[i][j] = equal(p1[i],p2[j]);
        }
    }
    int ans = answer();
    if(ans == -1) cout << ans << endl;
    else if(count_set.size() == 1) cout << (*count_set.begin()) << endl;
    else cout << 0 << endl;
    return 0;
}