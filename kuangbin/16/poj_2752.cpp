/**
 * POJ 2752
 * 求一个字符串所有相同的前后缀长度，包括这个字符串本身(len)
 * 解法:
 * len
 * nxt[len]
 * nxt[nxt[len]]
 * ...
 * 直到0为止
 * */
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
int nxt[400010];
vector<int> ans;

void get_nxt() {
  int slen = s.length();
  for (int i = 0; i <= slen; i++) nxt[i] == 0;
  nxt[0] = -1;
  int i = 0;
  int j = -1;
  while (i < slen) {
    if (j == -1 || s[i] == s[j]) {
      i++;
      j++;
      nxt[i] = j;
    } else {
      j = nxt[j];
    }
  }
}

int main() {
  while (cin >> s) {
    ans.clear();
    int slen = s.length();
    get_nxt();
    int x = slen;
    while (x > 0) {
      ans.push_back(x);
      x = nxt[x];
    }
    for (int i = ans.size() - 1; i > 0; i--) {
      cout << ans[i] << " ";
    }
    cout << ans[0] << endl;
  }
  return 0;
}