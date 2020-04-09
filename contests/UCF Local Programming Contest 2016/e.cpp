#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int r,c;
char g[15][25];

struct node {
    int x;
    int y;
    node(int x,int y):x(x),y(y){}
    node(){}
};

vector<node> m[26];

bool checkr(string str,node u) {
    int x = u.x,y =u.y;
    for(int i=0;i<str.length();i++) {
        if(str[i] != g[x][y]) return false;
        y = (y+1)%c;
    }
    return true;
}
bool checkl(string str,node u) {
    int x = u.x,y =u.y;
    for(int i=0;i<str.length();i++) {
        if(str[i] != g[x][y]) return false;
        y = (y-1+c)%c;
    }
    return true;
}
bool checku(string str,node u) {
    int x = u.x,y =u.y;
    for(int i=0;i<str.length();i++) {
        if(str[i] != g[x][y]) return false;
        x = (x-1+r)%r;
    }
    return true;
}
bool checkd(string str,node u) {
    int x = u.x,y =u.y;
    for(int i=0;i<str.length();i++) {
        if(str[i] != g[x][y]) return false;
        x = (x+1)%r;
    }
    return true;
}

int main() {
    int T;
    cin>>T;
    int CASE = 0;
    while(T--) {
        for(int i=0;i<26;i++) m[i].clear();
        cin>>r>>c; getchar();
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin>>g[i][j];
                m[g[i][j]-'A'].push_back(node(i,j));
            }
            getchar();
        }
        cout << "Word search puzzle #" << ++CASE << ":" << endl;
        int w; cin>>w;
        while(w--) {
            string str;
            string mode; node ans;
            cin>>str;
            char st = str[0];
            for(int i=0;i<m[str[0]-'A'].size();i++) {
                if(checkr(str,m[str[0]-'A'][i])) {
                    mode = "R";
                    ans = m[str[0]-'A'][i];
                    break;
                }
                if(checkl(str,m[str[0]-'A'][i])) {
                    mode = "L";
                    ans = m[str[0]-'A'][i];
                    break;
                }
                if(checku(str,m[str[0]-'A'][i])) {
                    mode = "U";
                    ans = m[str[0]-'A'][i];
                    break;
                }
                if(checkd(str,m[str[0]-'A'][i])) {
                    mode = "D";
                    ans = m[str[0]-'A'][i];
                    break;
                }
            }
            cout << mode << " " << ans.x+1 << " " << ans.y+1 << " " << str << endl;;
        }
        cout << endl;
    }
    return 0;
}