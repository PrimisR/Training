#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[3000];


int cmp(int a,int b) {
    return a>b;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n,cmp);
    int sum=0;
    for(int i=0;i<k;i++) {
        sum+=arr[i];
    }
    cout<<sum<<endl;
    return 0;
}