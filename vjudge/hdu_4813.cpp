#include<stdio.h>
#include<iostream>
using namespace std;

string s;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            cout<<s[i];
            if((i+1)%m==0)
                cout<<endl;
        }
    }
}