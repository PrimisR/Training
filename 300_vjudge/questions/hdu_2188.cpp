
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    while ( n-- )
    {
        int a, b;
        cin >> a >> b;
        if ( a % ( b + 1 ) == 0 )
        {
            cout << "Rabbit" << endl;
        }
        else
        {
            cout << "Grass" << endl;
        }
    }
    return 0;
}