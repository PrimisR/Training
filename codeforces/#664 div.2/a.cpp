#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int b[4];
    int c = inf;
    int odd = 0;
    for (int i = 0; i < 4; i++) {
      cin >> b[i];
      if (b[i] & 1) odd++;
    }
    for (int i = 0; i < 3; i++) c = min(c, b[i]);
    if (odd == 1 || odd == 0)
      cout << "Yes" << endl;
    else if ((odd == 3 || odd == 4) && c != 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}