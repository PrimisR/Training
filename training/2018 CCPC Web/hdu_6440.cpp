/**
 * 构造一种新的加法和乘法，对0<=m<p, 0<=n<p都满足
 * (m+n)^p = m^p + n^p, 其中p为素数
 * 给定p, 输出一个加法结果表和一个乘法结果表,大小为p*p
 * 由费马小定理,(m+n)^p = m+n (mod p)
 * m^p = m(mod p)
 * n^p = n(mod p)
 * (m+n)^p = m+n (mod p) (m+n > p 同理)
 * 所以定义为对p求模
 * */
#include <cstdio>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int p;
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < p - 1; j++) {
        printf("%d ", (i + j) % p);
      }
      printf("%d\n", (i + p - 1) % p);
    }
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < p - 1; j++) {
        printf("%d ", (i * j) % p);
      }
      printf("%d\n", (i * (p - 1)) % p);
    }
  }
  return 0;
}