#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int cnt[26] = {};
    string s;
    for (int i = 1; i <= n; i++) {
      cin >> s;
      for (int i = 0; i < s.length(); i++) cnt[s[i] - 'a']++;
    }
    bool flag = true;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % n != 0) {
        flag = false;
        break;
      }
    }
    cout << ((flag) ? "YES" : "NO") << endl;
  }
  return 0;
}