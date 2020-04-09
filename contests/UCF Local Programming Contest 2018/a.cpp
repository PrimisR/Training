#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int w,h,d;
    cin>>w>>h>>d;
    int s = (w-2*d) * (h-2*d);
    if(w-2*d <= 0 || h-2*d <= 0) s = 0;
    cout << s << endl;
}