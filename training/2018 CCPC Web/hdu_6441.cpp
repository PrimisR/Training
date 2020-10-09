/**
 * 费马大定理
 * x^n + y^n = z^n 在 n>2 时没有正整数解
 * 等同于找勾股数
 * */
#include <cstdio>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, a;
    scanf("%d %d", &n, &a);
    if (n == 0 || n > 2)
      printf("-1 -1\n");
    else if (n == 1)
      printf("1 %d\n", a + 1);
    else {
      int b = -1, c = -1;
      if (a % 2 == 1) {
        b = ((a * a) - 1) / 2;
        c = b + 1;

      } else {
        b = (a * a) / 4 - 1;
        c = b + 2;
      }
      printf("%d %d\n", b, c);
    }
  }
  return 0;
}