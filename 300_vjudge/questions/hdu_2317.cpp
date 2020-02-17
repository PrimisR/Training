#include<iostream>
using namespace std;
int main()
{
       int n,a,b,c;
       cin>>n;
       while(n--)
       {
             cin>>a>>b>>c;
             if(a<(b-c))
                      cout<<"advertise"<<endl;
             else if(a>(b-c))
                     cout<<"do not advertise"<<endl;
             else
                     cout<<"does not matter"<<endl;
        }
   return 0;
}