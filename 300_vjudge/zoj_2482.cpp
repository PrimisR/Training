#include <iostream>
 
using namespace std;
 
//固定的长度下，直接将2的幂值放入数组调用比方便很多
int mrk[ 8 ] = {128, 64, 32, 16, 8, 4, 2, 1};
 
int main () {
        int n;
        cin >> n;
        while ( n-- ) {
                for ( int i = 0; i < 4; i++ ) {
                        int sum = 0;
                        char k;
                        for ( int j = 0; j < 8; j++ ) {
                                cin >> k;
                                sum += ( k - '0' ) * mrk[ j ];
                        }
                        if ( i )
                                cout << ".";
                        cout << sum;
                }
                cout << endl;
        }
        return 0;
}
