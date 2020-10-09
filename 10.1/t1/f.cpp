#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  // ios::sync_with_stdio(0);
  int n, m;
  scanf("%d", &n);
  int ar[1010], sum[1010];
  for (int i = 1; i < n; i++) {
    printf("? %d %d\n", 1, n - i + 1);
    fflush(stdout);
    scanf("%d", &m);
    sum[i] = m;
  }
  printf("? 2 %d\n", n);
  fflush(stdout);
  scanf("%d", &m);
  sum[n] = m;
  int cot = n;
  for (int i = 2; i < n; i++) {
    ar[cot--] = sum[i - 1] - sum[i];
  }
  ar[1] = sum[1] - sum[n];
  ar[2] = sum[n - 1] - ar[1];

  printf("!");
  for (int i = 1; i <= n; i++) {
    printf(" %d", ar[i]);
  }
  return 0;
}