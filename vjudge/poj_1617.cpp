#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <ctime>
using namespace std;
#define ll long long
#define MOD 1000000007
#define TASK "proddiff"
#define nmax 1002
#define pi  acos(-1.0)
 
string s,t;
int num[2000];
int main()
{
   // freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
 
    while (cin>>s>>t)
    {
        string ans = "";
        for (int i=0; i<2000; i++)
            num[i] = 0;
        int k = 0;
       for (int i=0; i<30; i++)
        for (int j=0; j<s.length(); j++)
            if (i==s[j]-'A')
            {
                num[k] = j;
                k++;
            }
            k = 0;
            while (k<s.length())
            {
                for (int i=0; i<s.length(); i++)
                    if (num[i]==k)
                    {
                        for (int j=0; j<t.length()/s.length(); j++)
                            ans+=t[t.length()/s.length()*i+j];
                        k++;
                    }
            }
 
            string res = "";
            for (int i=0; i<t.length()/s.length(); i++)
            {
                for (int j=0; j<s.length(); j++)
                    res += ans[i+t.length()/s.length()*j];
            }
            cout<<res<<endl;
    }
}