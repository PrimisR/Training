#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int trans(char c) {
    if(c >= '2' && c <= '9') {
        return c - '0';
    }
    else {
        switch (c)
        {
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 1;
        }
    }
}

int cmp(int a,int b) {
    return a > b;
}

int main() {
    int n; cin>>n;
    int k = 0;
    while(n--) {
        string str; cin>>str;
        int count[15]{};
        string mode;
        for(int i=0;i<str.length();i++) {
            int id = trans(str[i]);
            count[id]++;
        }
        sort(count+1,count+1+13,cmp);
        if(count[1] == 4) mode = "FOUR OF A KIND";
        else if(count[1] == 3 && count[2] >=2) mode = "FULL HOUSE";
        else if(count[1] == 3 && count[2] <= 1) mode = "THREE OF A KIND";
        else if(count[1] == 2) mode = "TWO OF A KIND";
        else mode = "BUST";
        cout << "UCF Hold-em #" << ++k << ": " << str << endl;
        cout << "Best possible hand: " << mode << endl;
        cout << endl;
    }
    return 0;
}