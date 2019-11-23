#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int one=0;
    int two=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a==1) one++;
        else two++;
    }
    if(one==0)
    {
        for(int i=0;i<two;i++)
        {
            cout<<"2";
            if(i!=two-1) cout<<" ";
        }
        cout<<endl;
    }
    else if(two==0)
    {
        for(int i=0;i<one;i++)
        {
            cout<<"1";
            if(i!=one-1) cout<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"2"<<" ";
        cout<<"1";
        if(two!=1||one!=1) cout<<" ";
        for(int i=0;i<two-1;i++)
        {
            cout<<"2";
            if(i!=two-2||one!=1) cout<<" ";
        }
        for(int i=0;i<one-1;i++)
        {
            cout<<"1";
            if(i!=one-2) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}