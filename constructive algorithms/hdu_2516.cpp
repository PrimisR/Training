/**
 * 斐波那契博弈
 * n >= 2
 * 两人轮流取石子,先手可以取1~n-1个,以后每次取的石子不超过上次取石子的2倍
 * 取完者胜
 * n = 2, second
 * n = 3, second
 * n = 4, first
 * n = 5, second
 * */
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100;
typedef long long LL;
LL f[maxn];
int main() {
  f[0] = 0;
  f[1] = 1;
  int i = 1;
  do {
    i++;
    f[i] = f[i - 1] + f[i - 2];
  } while (f[i] < (1 << 31) - 1);
  int T = i - 1;

  int n;
  while (scanf("%d", &n) == 1 && n) {
    if (f[T] < n)
      printf("First win\n");
    else
      for (i = 2; i <= T; i++) {
        if (f[i] == n) {
          printf("Second win\n");
          break;
        }
        if (f[i] > n) {
          printf("First win\n");
          break;
        }
      }
  }
  return 0;
}