/**
 * 查询模式串无交集出现次数, KMP
 * */
#include <cstdio>
#include <cstring>

using namespace std;

char s[1010];
char p[1010];
int nxt[1010];

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
      j = 0;
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
  while (~scanf("%s", s) && s[0] != '#') {
    scanf("%s", p);
    int plen = strlen(p);
    int slen = strlen(s);
    get_nxt(plen);
    printf("%d\n", kmp(slen, plen));
  }
  return 0;
}