/**
 * 下载时间不受顺序影响
 * */

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int T,n,B;
    int Case = 1;
    while(cin>>T>>n>>B && T) {
        double S; int P;
        double total = 0.0;
        for(int i=0;i<T;i++) {
            cin>>S>>P;
            total += S * (double)(100-P) * 0.01;
        }
        printf("Case %d: %.2f\n\n",Case++,total/(double)B);
    }
}