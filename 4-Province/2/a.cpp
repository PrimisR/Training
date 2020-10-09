#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int loop = 1; loop <= T; loop++) {
    long long n;
    cin >> n;
    cout << "Case #" << loop << ": " << (n + 2) * (n - 1) / 2 << endl;
  }
  return 0;
}