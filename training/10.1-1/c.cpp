#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int cmp(int a,int b) {
    return a<b;
}

int main()
{
    int n;
    while(cin>>n) {
        int p=n/2;
        v.clear();
        for(int i=1;i<=p;i++) {
            int p_i; cin>>p_i;
            v.push_back(p_i-1);
        }
        sort(v.begin(),v.end(),cmp);
        int white_total=0,black_total=0;
        //all in black
        for(int i=0;i<p;i++) {
            black_total+=abs(i*2-v[i]);
        }
        //all in white
        for(int i=0;i<p;i++) {
            white_total+=abs(i*2+1-v[i]);
        }
        cout<<min(black_total,white_total)<<endl;
    }
}