#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1e6;
int heap[maxn];

int cmp(int a,int b) {return a>b;}

int main()
{
    int T;
    cin>>T;
    int n;
    long long s,e;
    
    while(T--)
    {
        s=0;
        e=0;
        cin>>n;
        for(int i=0;i<n;i++) scanf("%d",&heap[i]);
        sort(heap,heap+n,cmp);
        
        int flag=1;
        for(int i=0;i<n;i++,flag^=1)
        {
            if(flag) s+=heap[i];
            else e+=heap[i];
        }
        cout<<s<<" "<<e<<endl;
    }
    return 0;
}