#include <iostream>
#include <cmath>
 
using namespace std;
 
int main()
{
    double vs, r, c;
    int n;
    cin >> vs >> r >> c >> n;
    while(n--) {
        double w;
        cin >> w;
        printf("%.3f\n", c*r*vs*w/sqrt(1+c*r*w*c*r*w));
    }
    return 0;
}