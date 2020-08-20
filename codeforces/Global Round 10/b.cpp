#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int a[200010];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int maxa = *max_element(a, a + n);
    int mina = *min_element(a, a + n);
    if (k & 1) {
      for (int i = 0; i < n - 1; i++) {
        cout << maxa - a[i] << " ";
      }
      cout << maxa - a[n - 1] << endl;
    } else {
      for (int i = 0; i < n - 1; i++) {
        cout << a[i] - mina << " ";
      }
      cout << a[n - 1] - mina << endl;
    }
  }
  return 0;
}
