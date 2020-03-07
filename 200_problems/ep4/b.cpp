/**
 * n个灯，n-1个导线(树)
 * 对于每个导线,一端是主灯,一端是副灯(有向)
 * 其中一盏灯连接power grid，然后传输电能(根节点)
 * 每个灯有亮度，第i盏灯的亮度是2^i，一个导线的重要度是把这个导线被切断所有不亮的灯亮度总和
 * 给定n和n-1个ai，其中ai代表第i个导线的主灯，并且n-1个导线已经按照重要性递减排序
 * 
 * 1.第一个a_1必定是根节点
 * 2.除了根节点每个结点入度为1
 * 3.出度可由ai个数统计
 * 4.那么没有出度的点一定是叶子节点，并且一定按照亮度分配给最后几个导线
 * (因为如果最后几个导线指向除了这些以外有入度的结点,那么重要值一定比除了这些以外有入度的结点大)
 * 5.给这些分配完的导线源结点出度-1
 * 6.如果某个结点出度为0，那么这个结点与其子树可以合并成一个大结点，并重复之前的操作
 * (这一步可以使用优先队列!)
 * 
 * 也就是按出度拓扑排序
 * 
 * 在记录子树总权值的时候，只记录2的最大的次幂(因为比这个次幂小的可以忽略，相加的和和其他没有可比性)
 * */
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

struct node {
    int id;
    int val;
    node(){}
    node(int id,int val):id(id),val(val){}

    bool operator< (const node a) const{
        return this->val > a.val;
    }
};

int deg[MAXN]; // 出度
int edge[MAXN][2]; // 0是起点,1是终点
int imp[MAXN]; // 子树总权值

int main() {
    int n; cin>>n;
    for(int i=1;i<=n-1;i++) {
        cin>>edge[i][0];
        deg[edge[i][0]]++;
    }
    priority_queue<node> pq;
    for(int i=1;i<=n;i++) {
        if(deg[i] == 0) {
            pq.push(node(i,i));
        }
    }
    for(int i=n-1;i>=1;i--) {
        node u = pq.top(); pq.pop();
        int s = edge[i][0];
        edge[i][1] = u.id;
        imp[s] = max(u.val,imp[s]);
        deg[s]--;
        if(deg[s] == 0) pq.push(node(s,max(imp[s],s)));
    }
    cout << edge[1][0] << endl;
    for(int i=1;i<=n-1;i++) {
        cout << edge[i][0] << " " << edge[i][1] << endl;
    }
    return 0;
}