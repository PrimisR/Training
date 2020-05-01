#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_str(int i) {
    string str = "";
    while(i) {
        str = (char)(i%10 + '0') + str;
        i /= 10;
    }
    return str;
}

bool eql(string o,string num) {
    for(int i=0;i<3;i++) {
        if(o[i] != '-' && o[i] != num[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n; cin>>n;
    int s = 0;
    while(n--) {
        string in[3];
        cin>>in[0]>>in[1]>>in[2];
        string out[3];
        int u = 0;
        for(int i=200;i<=500;i++) {
            string str = to_str(i);
            if(eql(in[u],str)) {
                out[u] = str;
                u++;
                if(u == 3) break;
            }
        }
        cout << "Gas Station #" << ++s << ":" << endl;
        cout << "   Input:  " << in[0] << " " << in[1] << " " << in[2] << endl;
        cout << "   Output: " << out[0] << " " << out[1] << " " << out[2] << endl;
        cout << endl;
    }
    return 0;
}