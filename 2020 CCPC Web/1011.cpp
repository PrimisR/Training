#include <cstdio>
#include <iostream>

using namespace std;

int a[100][100];
int k[10][10];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    long long s = 0;
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        scanf("%d", &k[i][j]);
        s += k[i][j];
      }
    }
    s -= k[1][1];
    if (k[1][1] == 0 || s != 0) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - 1; j++) {
          cout << 0 << " ";
        }
        cout << 0 << endl;
      }
    } else {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - 1; j++) {
          cout << a[i][j] << " ";
        }
        cout << a[i][n] << endl;
      }
    }
  }
  return 0;
}