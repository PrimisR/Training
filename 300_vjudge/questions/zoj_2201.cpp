#include<iostream>
using namespace std;
 
int main()
{
    int T;
    //freopen("a.in","r",stdin);
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        cout<<(n>=m?"MMM BRAINS":"NO BRAINS")<<endl;
    }
    return 0;
}
