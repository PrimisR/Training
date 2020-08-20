#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const string f[6] = {"3464", "2353", "1242", "6131", "5626", "4515"};
const string h[6] = {"35", "24", "13", "62", "51", "46"};
const string cnct[6] = {"3", "2", "1", "6", "5", "4"};

const string in = "43";

string ans[510];

int main() {
  ans[1] = "";
  ans[2] = "432164";
  for (int r = 3; r <= 500; r++) {
    int full = (r - 2) / 2;
    int half = r & 1;
    ans[r] += cnct[5];
    for (int side = 0; side <= 4; side++) {
      for (int i = 1; i <= full; i++) ans[r] += f[side];
      for (int i = 1; i <= half; i++) ans[r] += h[side];
      ans[r] += cnct[side];
    }
    if (half == 1)
      half--;
    else {
      full--;
      half++;
    }
    for (int i = 1; i <= full; i++) ans[r] += f[5];
    for (int i = 1; i <= half; i++) ans[r] += h[5];
    ans[r] += in;
    ans[r] += ans[r - 2];
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << ans[n] << endl;
  }
  return 0;
}