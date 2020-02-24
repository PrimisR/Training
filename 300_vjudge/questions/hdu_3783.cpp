#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    char s[105];
    while(cin>>s&&s[0]!='E')
    {
        int z=0,o=0,j=0;
        int len=strlen(s);
        for(int i=0; i<len; i++)
        {
            if(s[i]=='Z')
                z++;
            else if(s[i]=='O')
                o++;
            else
                j++;
        }
        while(z>0||o>0||j>0)
        {
            if(z)
            {
                cout<<"Z";
                z--;
            }
            if(o)//!
            {
                cout<<"O";
                o--;
            }
            if(j)//!
            {
                cout<<"J";
                j--;
            }
        }
        cout<<endl;
    }
    return 0;
}