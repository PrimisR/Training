/**
 * 删除n-(m*k)最小的元素，之后忽略掉这些元素分组即可
 * */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[200000];
bool lower[200000];

struct pointer_data
{
    int data;
    int pointer;
    pointer_data() {}
    pointer_data(int pointer,int data) {
        this->data=data;
        this->pointer=pointer;
    }
};

int cmp_pointer(pointer_data a,pointer_data b) {
    return a.data<b.data;
}

pointer_data for_sort[200000];

int main()
{
    int n,m,k;
    while(cin>>n>>m>>k) {
        long long total=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            total+=arr[i];
            lower[i]=false;
            for_sort[i]=pointer_data(i,arr[i]);
        }
        sort(for_sort,for_sort+n,cmp_pointer);
        for(int i=0;i<n-(k*m);i++) {
            lower[for_sort[i].pointer]=true;
            total-=for_sort[i].data;
        }
        cout<<total<<endl;
        int group=0;
        for(int i=0,counter=0;i<n;i++) {
            if(lower[i]==true) continue;
            counter++;
            if(counter==m) {
                group++;
                if(group<k-1) cout<<i+1<<" ";
                else if(group==k-1) cout<<i+1;
            }
            counter%=m;
            total+=arr[i];
        }
        cout<<endl;
    }
}