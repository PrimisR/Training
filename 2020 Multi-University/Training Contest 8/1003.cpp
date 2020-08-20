#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const double pi = acos(-1);

//(0 -> 2*pi)
double ccwangle(int x, int y) {
  double angle = atan2(y, x);
  if (y < 0) angle += 2 * pi;
  return angle;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double ccwa = ccwangle(x1, y1);
    double ccwb = ccwangle(x2, y2);
    double ccwc = ccwangle(x3, y3);
    if (ccwb < ccwa) ccwb += 2 * pi;
    if (ccwc < ccwa) ccwc += 2 * pi;
    if (ccwb < ccwc)
      cout << "Counterclockwise" << endl;
    else
      cout << "Clockwise" << endl;
  }
  return 0;
}