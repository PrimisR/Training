#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int loop = 1;loop <= T;loop++) {
        long long a,b;
        cin >> a >> b;
        cout << "Case #" << loop << ":" << endl;
        if(a == b) {
            cout << 1 << endl;
            cout << a << " " << b << endl;
        }
        else {
            cout << 2 << endl;
            cout << a << " " << b << endl;
            cout << b << " " << a << endl;
        }
    }
    return 0;
}