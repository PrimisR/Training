#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;
    getline(cin,line);
    stringstream ss(line);
    vector<string> split;
    string str;
    while(ss>>str) {
        split.push_back(str);
    }
    if(split[0] == "?") split[0] = "!";
    for(int i=1;i<split.size();i++) {
        if(split[i] == "you") {
            if(split[i-1] == "can") {
                split[i-1] = "Yes ,";
                split[i] = "I can";
            }
            else if(split[i-1] == "are") {
                split[i-1] = "Yes ,";
                split[i] = "I am";
            }
            else if(split[i-1] == "do") {
                split[i-1] = "Yes ,";
                split[i] = "I";
            }
        }
        if(split[i] == "?") split[i] = "!";
    }
    for(int i=0;i<split.size();i++) {
        cout << split[i];
        if(i != split.size()-1) cout << " ";
        else cout << endl;
    }
    return 0;
}