/**
 * 约瑟夫环
 * */
#include <iostream>

using namespace std;

bool arr[70000];

int out_number(int len,int i_th,int step) {
    if(i_th == 1) return (step-1)%len;
    return (out_number(len-1,i_th-1,step)+step)%len;
}

int main() {
    int n,m;
    while(cin>>n>>m) {
        for(int i=0;i<2*n;i++) arr[i] = false;
        for(int i=1;i<=n;i++) {
            arr[out_number(2*n,i,m)] = true;
        }
        for(int i=0;i<2*n;i++) {
            if(!(i%50) && i) cout << endl;
            char ch = (arr[i])? 'B' : 'G';
            cout << ch;
        }
        cout << endl << endl;
    }
    return 0;
}