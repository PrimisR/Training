#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    int a[200010];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cout << ((a[n - 1] == a[0]) ? n : 1) << endl;
  }
  return 0;
}
