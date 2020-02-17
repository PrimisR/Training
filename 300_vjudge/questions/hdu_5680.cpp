/**
 * 先排序
 * 含a1子集 2^(n-1) (最小)
 * 不含a1，含a2子集，2^(n-2)
 * 不含...含an (最大) 子集 1
 * 所以就是最大值
 * */
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        priority_queue<int> pq;
        while(n--) {
            int a; cin>>a;
            pq.push(a);
        }
        cout << pq.top() << endl;
    }
}