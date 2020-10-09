#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[100010];
int b[100010];
int tree[200020];
int n;

int lowbit(int x) { return x & -x; }

int upd(int x, int d) {
  while (x <= n) {
    tree[x] += d;
    x += lowbit(x);
  }
  return 0;
}

int sum(int x) {
  int ans = 0;
  while (x > 0) {
    ans += tree[x];
    x -= lowbit(x);
  }
  return ans;
}

void clr() { memset(tree, 0, sizeof(tree)); }

int main() {
  int T;
  cin >> T;
  for (int loop = 1; loop <= T; loop++) {
    clr();
    cin >> n;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      int x = sum(a[i]);
      upd(a[i], 1);
      b[a[i]] = i + x - min(i, a[i] - 1);
    }
    cout << "Case #" << loop << ": ";
    for (int i = 1; i <= n - 1; i++) {
      cout << b[i] << " ";
    }
    cout << b[n] << endl;
  }
  return 0;
}