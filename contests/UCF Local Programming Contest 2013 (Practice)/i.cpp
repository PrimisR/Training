#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159;

int main() {
    int n; cin>>n;
    int taiji = 0;
    while(n--) {
        int a,b,r;
        cin>>a>>b;
        a = a - b;
        swap(a,b);
        r = a + b;
        int r2 = r * r;
        int a2 = a * a;
        int b2 = b * b;
        double yin = pi * 0.5 * (r2 - a2 + b2);
        double yang = pi * 0.5 * (r2 + a2 - b2);
        yin = round(yin*100)/100;
        yang = round(yang*100)/100;
        printf("Taijitu #%d: yin %.2lf, yang %.2lf\n\n",++taiji,yin,yang);
    }
    return 0;
}