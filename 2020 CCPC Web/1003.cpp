#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int a[1000010];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    sort(a, a + m);
    int ptr = lower_bound(a, a + m, k) - a;
    long long ans = 0;
    ans += (k - 1) * 2;
    for (int i = 0; i < ptr; i++) ans += (k - a[i]) * 2;
    for (int i = ptr; i < m; i++) ans += (a[i] - k) * 2;
    if(ptr != 0) {
        ans -= (k - a[0]) * 2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}