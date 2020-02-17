#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const string high = "ni li hai!";
const string low = "duo chi yu!";
const string perfect = "wan mei!";
const string thin = "duo chi rou!";
const string fat = "shao chi rou!";

int main() {
    int n; cin>>n;
    while(n--) {
        int g,h,w;
        cin>>g>>h>>w;
        if(g == 0) {
            if(h > 129) cout << high << " ";
            else if(h <129) cout << low << " ";
            else cout << perfect << " ";

            if(w > 25) cout << fat;
            else if(w < 25) cout << thin;
            else cout << perfect;
        }
        if(g == 1) {
            if(h > 130) cout << high << " ";
            else if(h <130) cout << low << " ";
            else cout << perfect << " ";

            if(w > 27) cout << fat;
            else if(w < 27) cout << thin;
            else cout << perfect;
        }
        cout << endl;
    }
    return 0;
}