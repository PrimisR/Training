#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  while (cin >> s) {
    int ssz = s.length();
    int m;
    cin >> m;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      int l, r;
      cin >> l >> r;
      ans += ((l - 1) + (ssz - r));
    }
    if (ans % 2 == 0)
      cout << "Bob" << endl;
    else
      cout << "Alice" << endl;
  }
  return 0;
}