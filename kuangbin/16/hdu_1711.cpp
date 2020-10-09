/**
 * KMP模板
 * */
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[1000010];
int b[10010];
int nxt[10010];

int kmp(int n, int m) {
  int i = 0;
  int j = 0;
  while (i < n && j < m) {
    if (j == -1 || a[i] == b[j]) {
      i++;
      j++;
    } else
      j = nxt[j];
  }
  if (j == m)
    return i - j;
  else
    return -1;
}

void get_nxt(int m) {
  nxt[0] = -1;
  int i = 0, j = -1;
  while (i < m) {
    if (j == -1 || b[i] == b[j]) {
      i++;
      j++;
      nxt[i] = j;
    } else
      j = nxt[j];
  }
}

void init() { memset(nxt, 0, sizeof(nxt)); }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    init();
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    get_nxt(m);
    int ans = kmp(n, m);
    if (ans == -1)
      printf("-1\n");
    else
      printf("%d\n", ans + 1);
  }
  return 0;
}