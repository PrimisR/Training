#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

bool b[150][150];

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int t = n * m;
  int cnt = 0;
  while (cnt < t) {
    cnt++;
    b[x][y] = true;
    cout << x << " " << y << endl;
    for (int i = 1; i <= n; i++) {
        if(!b[i][y]) {
            x = i;
            cnt++;
            cout << x << " " << y << endl;
            b[i][y] = true;
        }    
    }
    y = y % m + 1;
  }
  return 0;
}