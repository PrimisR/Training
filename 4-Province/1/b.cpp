#include <algorithm>
#include <iostream>

using namespace std;

const int p = 1000000007;

long long p2[60];
long long x[60];
long long w[100010];

int cmp(long long a, long long b) { return a > b; }

int main() {
  p2[0] = 1;
  for (int i = 1; i < 60; i++) p2[i] = p2[i - 1] * 2;
  while (cin >> x[0]) {
    for (int i = 1; i < 60; i++) cin >> x[i];
    int n;
    cin >> n;
    bool flag = true;
    for (int i = 0; i < n; i++) cin >> w[i];
    sort(w, w + n);
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 59; j >= 0; j--) {
        if (x[j] && w[i] >= p2[j]) {
          long long cnt = min(w[i] / p2[j], x[j]);
          w[i] -= cnt * p2[j];
          x[j] -= cnt;
        }
      }
      if (w[i] > 0) {
        flag = false;
        break;
      }
    }
    if (!flag)
      cout << -1 << endl;
    else {
      long long ans = 0;
      for (int i = 0; i < 60; i++) {
        ans += (x[i] % p) * (p2[i] % p);
        ans %= p;
      }
      cout << ans << endl;
    }
  }
  return 0;
}