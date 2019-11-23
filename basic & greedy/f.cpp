#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int cho[300000];

int cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n;
    cin>>n;
    long long total=0;
    for(int i=0;i<n;i++) 
    {
        cin>>cho[i];
        total+=cho[i];
    }
    sort(cho,cho+n,cmp);
    int q;
    cin>>q;
    while(q--)
    {
        int a;
        cin>>a;
        cout<<total-cho[a-1]<<endl;
    }
    return 0;
}