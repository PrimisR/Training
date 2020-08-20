#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

// []
struct itvl {
  int l;
  int r;
  itvl() {}
  itvl(int l, int r) : l(l), r(r) {}
  bool empty() { return r < l; }
};

itvl intersect(itvl a, itvl b) { return itvl(max(a.l, b.l), min(a.r, b.r)); }

itvl lst[100010];
itvl opt[100010];

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> lst[i].l >> lst[i].r;
    opt[n] = lst[n];
    bool flag = true;
    for (int i = n - 1; i >= 1; i--) {
      opt[i] = intersect(lst[i], itvl(opt[i + 1].l - k, opt[i + 1].r + k));
      if (opt[i].empty()) {
        flag = false;
        break;
      }
    }
    if (!flag)
      cout << "NO" << endl;
    else {
      for (int i = 2; i <= n; i++) {
        opt[i] = intersect(opt[i], itvl(opt[i - 1].l - k, opt[i - 1].r + k));
        if (opt[i].empty()) {
          flag = false;
          break;
        }
      }
      if (!flag)
        cout << "NO" << endl;
      else {
        cout << "YES" << endl;
        for (int i = 1; i <= n - 1; i++) cout << opt[i].l << " ";
        cout << opt[n].l << endl;
      }
    }
  }
  return 0;
}