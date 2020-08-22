#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int UPPER = 34;

long long pow3[UPPER];
long long sum[UPPER];

void init() {
  pow3[0] = 1;
  for (int i = 1; i < UPPER; i++) pow3[i] = pow3[i - 1] * 3;
  sum[0] = 0;
  for (int i = 1; i < UPPER; i++) sum[i] = sum[i - 1] + pow3[i - 1] + pow3[i];
}

int main() {
  init();
  long long t;
  cin >> t;
  int p = upper_bound(sum, sum + UPPER, t) - sum;
  int index = p - 1;
  long long ans = index * 2;
  t -= sum[index];
  for (int i = index; i >= 0; i--) {
    ans += t / pow3[i];
    t %= pow3[i];
  }
  cout << ans << endl;
}