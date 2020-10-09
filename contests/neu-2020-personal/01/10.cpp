#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void rev_oput(string s) {
  for (int i = s.length() - 1; i >= 0; i--) cout << s[i];
}

int main() {
  int T;
  cin >> T;
  getchar();
  while (T--) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string s;
    vector<string> words;
    while (ss >> s) {
      words.push_back(s);
    }
    for (int i = 0; i < words.size() - 1; i++) {
      rev_oput(words[i]);
      cout << " ";
    }
    rev_oput(words[words.size() - 1]);
    cout << endl;
    }
  return 0;
}