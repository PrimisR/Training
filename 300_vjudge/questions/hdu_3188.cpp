#include <iostream>
 
using namespace std;
 
int main()
{
    int t, a, b, c;
 
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
 
        if(a == b || b == c || a == c)
            cout << "perfect" << endl;
        else if(a * a + b * b == c * c || b * b + c * c == a * a || a * a + c * c == b * b)
            cout << "good" << endl;
        else
            cout << "just a triangle" << endl;
    }
 
    return 0;
}