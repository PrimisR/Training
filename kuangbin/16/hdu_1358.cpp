#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char s[1000010];
int nxt[1000010];
int len;

void get_nxt() {
  for (int i = 0; i <= len; i++) nxt[i] = 0;
  nxt[0] = -1;
  int i = 0;
  int j = -1;
  while (i < len) {
    if (j == -1 || s[i] == s[j]) {
      i++;
      j++;
      nxt[i] = j;
    } else
      j = nxt[j];
  }
}

int main() {
  int tcase = 0;
  while (~scanf("%d", &len) && len) {
    scanf("%s", s);
    get_nxt();
    printf("Test case #%d\n", ++tcase);
    for (int i = 1; i <= len; i++) {
      int sec = i - nxt[i];
      if (i != sec && (i % sec == 0)) {
        printf("%d %d\n", i, i / sec);
      }
    }
    printf("\n");
  }
  return 0;
}