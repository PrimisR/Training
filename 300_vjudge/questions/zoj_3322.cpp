#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define LL __int64
typedef long long ll;
#define PI 3.1415926
int main()
{
    int a,b,c;
    int a1,b1,c1;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        cin>>a1>>b1>>c1;
        int flag=0;
        if(a>a1)
        {
               cout<<"cpcs"<<endl;
               continue;
        }
        if(a<a1)
        {
            cout<<"javaman"<<endl;
            continue;
        }
            if(b>b1)
        {
               cout<<"cpcs"<<endl;
               continue;
        }
        if(b<b1)
        {
            cout<<"javaman"<<endl;
            continue;
        }
              if(c>c1)
        {
               cout<<"cpcs"<<endl;
               continue;
        }
        if(c<c1)
        {
            cout<<"javaman"<<endl;
            continue;
        }
        cout<<"same"<<endl;
    }
    return 0;
}