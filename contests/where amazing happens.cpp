#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const string lst[] = {"Cleveland Cavaliers",
                      "Golden State Warriors",
                      "San Antonio Spurs",
                      "Miami Heat",
                      "Miami Heat",
                      "Dallas Mavericks",
                      "L.A. Lakers",
                      "L.A. Lakers",
                      "Boston Celtics",
                      "San Antonio Spurs",
                      "Miami Heat",
                      "San Antonio Spurs",
                      "Detroit Pistons",
                      "San Antonio Spurs",
                      "L.A. Lakers",
                      "L.A. Lakers",
                      "L.A. Lakers",
                      "San Antonio Spurs",
                      "Chicago Bulls",
                      "Chicago Bulls",
                      "Chicago Bulls",
                      "Houston Rockets",
                      "Houston Rockets",
                      "Chicago Bulls",
                      "Chicago Bulls",
                      "Chicago Bulls",
                      "Detroit Pistons",
                      "Detroit Pistons",
                      "L.A. Lakers",
                      "L.A. Lakers",
                      "Boston Celtics",
                      "L.A. Lakers",
                      "Boston Celtics",
                      "Philadelphia 76ers",
                      "L.A. Lakers",
                      "Boston Celtics",
                      "L.A. Lakers",
                      "Seattle Sonics",
                      "Washington Bullets",
                      "Portland Trail Blazers",
                      "Boston Celtics",
                      "Golden State Warriors",
                      "Boston Celtics",
                      "New York Knicks",
                      "L.A. Lakers",
                      "Milwaukee Bucks",
                      "New York Knicks",
                      "Boston Celtics",
                      "Boston Celtics",
                      "Philadelphia 76ers",
                      "Boston Celtics",
                      "Boston Celtics",
                      "Boston Celtics",
                      "Boston Celtics",
                      "Boston Celtics",
                      "Boston Celtics",
                      "Boston Celtics",
                      "Boston Celtics",
                      "St. Louis Hawks",
                      "Boston Celtics",
                      "Philadelphia Warriors",
                      "Syracuse Nats",
                      "Minneapolis Lakers",
                      "Minneapolis Lakers",
                      "Minneapolis Lakers",
                      "Rochester Royals",
                      "Minneapolis Lakers",
                      "Minneapolis Lakers",
                      "Baltimore Bullets",
                      "Philadelphia Warriors"};

const int sz = 70;

int main() {
  map<string, int> m;
  for (int i = 0; i < sz; i++) {
    if (!m.count(lst[i]))
      m[lst[i]] = 1;
    else
      m[lst[i]]++;
  }
  int T;
  cin >> T;
  getchar();
  for (int loop = 1; loop <= T; loop++) {
    string s;
    getline(cin, s);
    cout << "Case #" << loop << ": " << ((m.count(s)) ? m[s] : 0) << endl;
  }
}