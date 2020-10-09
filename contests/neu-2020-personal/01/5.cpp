#include <cstdio>
#include <iostream>

using namespace std;

char ch[110][110];
int b[110][110];

void clear() {
  for (int i = 0; i < 110; i++)
    for (int j = 0; j < 110; j++) b[i][j] = 0;
}

void upd(int i, int j) {
  if (ch[i][j] == '.') b[i][j]++;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    clear();
    int n, m;
    cin >> n >> m;
    getchar();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> ch[i][j];
      }
      getchar();
    }
    for (int i = 0; i <= n + 1; i++) {
      ch[i][0] = '.';
      ch[i][m + 1] = '.';
    }
    for (int i = 0; i <= m + 1; i++) {
      ch[0][i] = '.';
      ch[n + 1][i] = '.';
    }
    for (int i = 0; i <= n + 1; i++)
      for (int j = 0; j <= m + 1; j++) {
        if (ch[i][j] == '#') {
          upd(i, j - 1);
          upd(i, j + 1);
          upd(i + 1, j);
          upd(i - 1, j);
        }
      }
    int ans = 0;
    for (int i = 0; i <= n + 1; i++)
      for (int j = 0; j <= m + 1; j++) {
        if (b[i][j] == 1 && b[i][j] != '#') ans++;
      }
    cout << ans << endl;
  }
  return 0;
}