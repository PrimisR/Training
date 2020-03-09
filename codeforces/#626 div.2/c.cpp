#include <iostream>
#include <cstdio>

using namespace std;

int main() 
{
    int n;
    int ltotal = 0;
    int rtotal = 0;
    int st = -1;
    bool is_balance = true;
    long long total = 0;
    cin >> n;
    for(int i=1;i<=n;i++) {
        char op; cin>>op;
        if(op == '(') ltotal++;
        else rtotal++;
        if (rtotal > ltotal) {
            if(is_balance) {
                is_balance = false;
                st = i;
            }
            
        }
        else
        {
            if(!is_balance) {
                total += i - st + 1;
            }
            is_balance = true;
        }
    }
    if(ltotal == rtotal) cout << total << endl;
    else cout << -1 << endl;
    return 0;
}