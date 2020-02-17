#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const string PANG = "PANG";
const string HAIXING = "Hai Xing";

int main() {
    double w,h; cin>>w>>h;
    double result = w/(h*h);
    printf("%.1lf\n",result);
    if(result > 25) {
        cout << PANG << endl;
    }
    else {
        cout << HAIXING << endl;
    }
    return 0;
}