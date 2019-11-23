#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int li[130];

int cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>li[i];
    sort(li,li+n,cmp);
    cout<<li[0]<<" ";
    for(int i=1;i<n;i++)
    {
        if(li[0]%li[i]!=0||(li[i-1]==li[i]&&li[0]%li[i]==0)) 
        {
            cout<<li[i]<<endl;
            break;
        }
    }
    return 0;
}