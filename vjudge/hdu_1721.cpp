/**
 * 通过加减来不断“运输”粒子
 * */
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int a,b,c,d,e,f,g,h;
    while(cin>>a && a != -1) {
        cin>>b>>c>>d>>e>>f>>g>>h;
        bool able = (a-e+f-g+h-b+c-d) == 0;
        if(able) cout << "All the seeds can be cleared away!" << endl;
        else cout << "Sorry,it can't be cleared away!" << endl;
    }
}