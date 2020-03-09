#include <cstdio>
#include <iostream>
#define ll long long

using namespace std;

ll gcd(ll a,ll b)
{
    return b==0 ? a:gcd(b,a%b);
}

ll arr[1005];

int main()
{
    ll n,m;
    ll g;
    
    while(cin>>n>>m)
    {
        bool fail=false;
        for(int i=0;i<n;i++) {cin>>arr[i];}
        ll lcm=arr[0];
        for(int i=1;i<n;i++)
        {
            g=gcd(lcm,arr[i]);
            lcm=arr[i]/g*lcm;
        }
            ll total=0;
            for(int i=0;i<n;i++)
            {
                total+=lcm/arr[i];
            }
            if(m%total) cout<<"No"<<endl;
            else
            {
                ll s=m/total;
                cout<<"Yes"<<endl;
                for(int i=0;i<n;i++)
                {
                    cout<<lcm/arr[i]*s;
                    if(i!=n-1) cout<<" ";
                    else cout<<endl;
                }
            }    
        }
}