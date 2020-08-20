/**
 * 棋盘上有一些棋子，每个格子只能放一个棋子，每次必须向左移动一个棋子，但是不超过在它左边的一个棋子
 * 不能移出棋盘，无法操作者输
 * 对于两个棋子，贴在一起是先手必败状态
 * 因为先手只能移动前面的棋子，后手对应移动到前面棋子的后面，仍保持先手必败，直到移动到棋盘的最左端
 * 所以将1,2/3,4两个棋子之间的距离看作子游戏，贴在一起先手必败
 * 偶数个棋子两两组成一对，奇数个添加一个0位置的棋子
 * Nim 游戏
 * */
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    int a[1010];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int s = 0;
    if (n & 1) {
      a[0] = 0;
      for (int i = 0; i <= n - 1; i += 2) s ^= (a[i + 1] - a[i] - 1);
    } else
      for (int i = 1; i <= n - 1; i += 2) s ^= (a[i + 1] - a[i] - 1);
    if (s == 0)
      cout << "Bob will win" << endl;
    else
      cout << "Georgia will win" << endl;
  }
  return 0;
}