#include <cctype>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  getchar();
  while (T--) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string str;
    vector<string> vs;
    while (ss >> str) vs.push_back(str);
    vector<char> abb;
    for (int i = 0; i < vs.size(); i++) {
      abb.push_back((char)toupper(vs[i][0]));
    }
    for (int i = 0; i < abb.size(); i++) cout << abb[i];
    cout << endl;
  }
  return 0;
}