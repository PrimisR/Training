/**
 * 查询模式串出现次数, KMP
 * */
#include <cstdio>
#include <cstring>

using namespace std;

char s[1000010];
char p[10010];
int nxt[10010];

int kmp(int slen, int plen) {
  int ans = 0;
  int i = 0;
  int j = 0;
  while (i < slen) {
    if (j == -1 || s[i] == p[j]) {
      i++;
      j++;
    } else
      j = nxt[j];
    if (j == plen) {
      ans++;
      j = nxt[j];
    }
  }
  return ans;
}

void get_nxt(int plen) {
  for (int i = 0; i < plen; i++) nxt[i] = 0;
  nxt[0] = -1;
  int i = 0, j = -1;
  while (i < plen) {
    if (j == -1 || p[i] == p[j]) {
      i++;
      j++;
      nxt[i] = j;
    } else
      j = nxt[j];
  }
}

int main() {
  int T;
  scanf("%d", &T);
  getchar();
  while (T--) {
    scanf("%s", p);
    scanf("%s", s);
    int plen = strlen(p);
    int slen = strlen(s);
    get_nxt(plen);
    printf("%d\n", kmp(slen, plen));
  }
  return 0;
}