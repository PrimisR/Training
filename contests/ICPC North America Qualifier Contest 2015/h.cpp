#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const bool DEBUG = 0;

int sqr[101];
char t[105][105];

int pre() {
    for(int i=0;i<=100;i++) {
        sqr[i] = i*i;
    }
}

int main()
{
    pre();
    int n;
    cin >> n;
    for (int loop = 1; loop <= n; loop++)
    {
        memset(t,0,sizeof(t));
        string str;
        cin>>str;
        int len = str.length();
        int l = lower_bound(sqr,sqr+101,len) - sqr;
        for(int i=0;i<len;i++) {
            t[(i%l)+1][l-i/l] = str[i];
        }
        if(DEBUG) {
            cout << str << endl;
            cout << l << endl;
            for(int i=1;i<=l;i++) {
                for(int j=1;j<=l;j++) {
                    cout << t[i][j] << " ";
                }
                cout << endl;
            }
        }
        string ans = "";
        for(int i=1;i<=l;i++) {
            for(int j=1;j<=l;j++) {
                if(t[i][j] == 0) continue;
                ans = ans + t[i][j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
