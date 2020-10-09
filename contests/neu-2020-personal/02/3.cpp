#include <cstdio>
#include <iostream>

using namespace std;

const int a[] = {1, 3, 5, 7, 8, 10, 12};

bool is_a(int m) {
  for (int i = 0; i < 7; i++) {
    if (m == a[i]) return true;
  }
  return false;
}

bool is_b(int m) { return (!is_a(m) && m != 2); }

int c_upper(int year) {
  if ((year / 4 == 0 && year / 100 != 0) || (year / 400 == 0)) return 29;
  return 28;
}

bool cross(int y, int m, int d) {
  return (is_a(m) && d == 31) || (is_b(m) && d == 30) ||
         (m == 2 && d == c_upper(y));
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int y, m, d;
    cin >> y >> m >> d;
    if (cross(y, m, d)) {
      m++;
      d = 1;
    } else
      d++;
    if (m == 13) {
      y++;
      m = 1;
    }
    printf("%04d-%02d-%02d\n", y, m, d);
  }
  return 0;
}