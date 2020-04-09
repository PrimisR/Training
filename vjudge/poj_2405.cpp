#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
 
const double pi=acos(double(-1));
 
int main(){
    int d,v;
    while(cin>>d>>v && (d||v) ){
        double D=(double)d,V=(double)v;
        double tmp=D*D*D-6*V/pi;
        printf("%.3f\n",pow(tmp,1.0/3.0));
    }
    return 0;
}