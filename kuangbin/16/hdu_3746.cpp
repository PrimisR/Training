/**
 * next数组求字符串循环节
 * */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int nxt[100500];
char p[100500];

void get_nxt(int plen) {
  memset(nxt, 0, sizeof(nxt));
  nxt[0] = -1;
  int i = 0;
  int j = -1;
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
  ios::sync_with_stdio(false);
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s",p);
    int plen = strlen(p);
    get_nxt(plen);
    int sec = plen - nxt[plen];
    if ((sec != plen) && (plen % sec == 0))
      printf("0\n");
    else
      printf("%d\n", sec - (plen % sec));
  }
  return 0;
}