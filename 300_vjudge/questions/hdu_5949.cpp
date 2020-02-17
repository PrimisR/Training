#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    int t;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        long long sum=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='H')
                sum+=1;
            else if(s[i]=='O')
                sum+=16;
            else
                sum+=12;
        }
        cout<<sum<<endl;
    }
    return 0;
}