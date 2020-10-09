#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    long long n, ans[2] = {};
    cin >> n;
    int flag = 0;
    while (n) {
      if (n & 1) {
        ans[flag]++;
        n--;
      } else if (n == 4) {
        ans[flag] += 3;
        ans[flag ^ 1]++;
        break;
      } else {
        if ((n >> 1) & 1) {
          ans[flag] += (n >> 1);
          n >>= 1;
        } else {
          ans[flag]++;
          n--;
        }
      }
      flag ^= 1;
      // cout << ans[0] << endl;
      // cout << n << endl;
    }
    cout << ans[0] << endl;
  }
  return 0;
}