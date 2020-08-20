/**
 * 给定n，要求找出三个[1,1e9]，且x!=y, y!=z, z!=x的数
 * 满足2/n = 1/x + 1/y + 1/z
 * n <= 1e4
 * 构造题：
 * 1/n + 1/(n+1) + 1/(n*(n+1)) = 2/n
 * 当 n=1 时， (n+1) = n*(n+1)，故 n=1 无解，由于 n<=1e4 故必定有解
 * */
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1)
    cout << -1 << endl;
  else
    cout << n << " " << n + 1 << " " << n * (n + 1) << endl;
  return 0;
}