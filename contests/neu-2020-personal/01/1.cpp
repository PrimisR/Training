#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int q = n / m;
    int r = n % m;
    if(r != 0) q++;
    cout << q << endl;
  }
  return 0;
}