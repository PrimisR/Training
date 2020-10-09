#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const long long e9 = 1000000000;

vector<long long> f;

void cal_f() {
  f.push_back(1);
  f.push_back(2);
  long long s = 3;
  while (s <= e9) {
    f.push_back(s);
    s += f[f.size() - 2];
  }
  f.push_back(s);
}

int main() {
  cal_f();
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    cout << n << "=";
    vector<long long> ans;
    while (n) {
      int ptr = upper_bound(f.begin(), f.end(), n) - f.begin() - 1;
      ans.push_back(f[ptr]);
      n -= f[ptr];
    }
    for (int i = ans.size() - 1; i > 0; i--) {
      cout << ans[i] << "+";
    }
    cout << ans[0] << endl;
  }
  return 0;
}
