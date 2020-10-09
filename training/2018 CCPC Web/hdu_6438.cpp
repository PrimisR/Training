/**
 * 一个物品，第i个城市ai元，一个人从左向右遍历所有城市，可以做三种操作：
 * 1. 用ai元买物品
 * 2. 如果有物品，卖出ai元
 * 3. 什么也不做
 * 假设这个人开始有无限金钱，问如何利益最大
 * 1 2 9 10
 * 1 -> 2
 * 1 -> 2 -> 9 (释放2)
 * 1 -> 9 | 2
 * 1 -> 9 | 2 -> 10
 * */
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int a;

struct node {
  long long v;
  int flag;
  node() : v(0), flag(0) {}
  node(long long v, int flag) : v(v), flag(flag) {}
  const bool operator<(const node o) const {
    return (this->v == o.v) ? (this->flag < o.flag) : this->v > o.v;
  }
};

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    priority_queue<node> pq;
    long long p = 0;
    int op = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a;
      if (pq.size() == 0) {
        pq.push(node(a, 0));
        continue;
      }
      node u = pq.top();
      if (a <= u.v)
        pq.push(node(a, 0));
      else {
        if (u.flag == 0)
          op++;
        else
          pq.push(node(u.v, 0));
        p += a - u.v;
        pq.pop();
        pq.push(node(a, 1));
      }
    }
    cout << p << " " << op * 2 << endl;
  }
  return 0;
}