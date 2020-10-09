#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d;
    int f1 = 0, f2 = 0, f3 = 0;
    cin >> a >> b >> c >> d;
    if ((a + b) % 2 == 1) f1 = 1;

    if (a + d > 0) f2 = 1;

    if (b + c > 0) f3 = 1;


    if (f1 && f2)
      cout << "Ya ";
    else
      cout << "Tidak ";


    if (f1 && f3)
      cout << "Ya ";
    else
      cout << "Tidak ";


    if (!f1 && f3)
      cout << "Ya ";
    else
      cout << "Tidak ";


    if (!f1 && f2)
      cout << "Ya"<<endl;
    else
      cout << "Tidak"<<endl;
  }
  return 0;
}