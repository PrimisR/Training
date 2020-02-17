#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n; cin>>n; getchar();
    string line;
    while(n--) {
        getline(cin,line);
        stringstream ss(line);
        vector<string> seq;
        string str;
        while(ss>>str) {
            seq.push_back(str);
        }
        int first = -1,last = -1;;
        for(int i=0;i<seq.size();i++) {
            if(seq[i][seq[i].size()-1] == ',') {
                if(seq[i][seq[i].size()-2] == 'g' &&
                seq[i][seq[i].size()-3] == 'n' &&
                seq[i][seq[i].size()-4] == 'o' )
                first = i;
            }
            if(seq[i][seq[i].size()-1] == '.') {
                if(seq[i][seq[i].size()-2] == 'g' &&
                seq[i][seq[i].size()-3] == 'n' &&
                seq[i][seq[i].size()-4] == 'o' )
                last = i;
            }
        }
        if(first == -1 || last == -1) {
            cout << "Skipped" << endl;
        }
        else {
            seq[last] = "zhong.";
            seq[last-1] = "ben";
            seq[last-2] = "qiao";
            for(int i=0;i<seq.size();i++) {
                cout << seq[i];
                if(i != seq.size()-1) cout << " ";
                else cout << endl;
            }
        }
    }
    return 0;
}