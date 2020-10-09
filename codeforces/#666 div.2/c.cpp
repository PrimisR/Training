#include <cstdio>
#include <iostream>

using namespace std;

long long a[100010];
long long b[100010];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n == 1) {
    cout << "1 1" << endl;
    cout << -a[1] << endl;
    cout << "1 1" << endl;
    cout << 0 << endl;
    cout << "1 1" << endl;
    cout << 0 << endl;
  } else if (n == 2) {
    cout << "1 1" << endl;
    cout << -a[1] << endl;
    cout << "2 2" << endl;
    cout << -a[2] << endl;
    cout << "1 1" << endl;
    cout << 0 << endl;
  } else if (n == 3) {
    cout << "1 1" << endl;
    cout << -a[1] << endl;
    cout << "2 2" << endl;
    cout << -a[2] << endl;
    cout << "3 3" << endl;
    cout << -a[3] << endl;
  } else {
    cout << 1 << " " << n - 1 << endl;
    for (int i = 1; i <= n - 1; i++) {
      b[i] = n * (a[i] - n + 1);
    }
    for (int i = 1; i <= n - 2; i++) {
      cout << b[i] - a[i] << " ";
    }
    cout << b[n - 1] - a[n - 1] << endl;
    cout << n << " " << n << endl;
    cout << -a[n] << endl;
    cout << 1 << " " << n << endl;
    for (int i = 1; i <= n - 1; i++) {
      cout << -b[i] << " ";
    }
    cout << 0 << endl;
  }
  return 0;
}