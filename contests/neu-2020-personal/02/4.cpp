#include <cstdio>
#include <iostream>

using namespace std;

long long ccans(long long a, long long b) {
  long long t = 1, ans = 0;
  while (a || b) {
    long long bit = ((a % 10) + (b % 10)) % 10;
    ans += bit * t;
    t *= 10;
    a /= 10;
    b /= 10;
  }
  return ans;
}

int main() {
  long long a, b;
  while (cin >> a >> b) {
    long long ans = a + b;
    long long cans = ccans(a, b);
    cout << ans << " " << cans << endl;
  }
  return 0;
}