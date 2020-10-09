#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

long long a[100010];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (n >= 50) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += abs(a[i] - 1);
    }
    cout << ans << endl;
  } else {
    long long m = (long long)floor(pow(a[n - 1], 1.0 / (n - 1)));
    if (m >= 1) {
      long long ans1 = 0;
      long long ans2 = 0;
      long long p = 1;
      ans1 += abs(a[0] - p);
      for (int i = 1; i < n; i++) {
        p *= m;
        ans1 += abs(a[i] - p);
      }
      p = 1;
      ans2 += abs(a[0] - p);
      for (int i = 1; i < n; i++) {
        p *= (m + 1);
        ans2 += abs(a[i] - p);
      }
      cout << min(ans1, ans2) << endl;
    } else {
      long long ans = 0;
      for (int i = 0; i < n; i++) {
        ans += abs(a[i] - 1);
      }
      cout << ans << endl;
    }
  }
  return 0;
}