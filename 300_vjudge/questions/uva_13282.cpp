/**
 * 计算所有的差，并分别统计选择次数最多的段，如果数量相同输出最小的
 * 技巧:
 * memset(复制目的数组，复制源数组，数组的前n个元素*sizeof(类型))
 * unique(arr,arr+n) 返回不重复最后一个元素的下一个元素
 * unique - arr 就能得到不重复元素个数
 * 对于一个确定在数组中的元素,upper_bound(arr,arr+n,k) - lower_bound(arr,arr+n,k)
 * 能够得出k的个数
 * */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[2006],b[2006];
vector<int>v;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int cnt=0;
        v.clear();
        for(int i=1; i<=n; i++)
            cin>>a[i];
        for(int i=1; i<=m; i++)
            cin>>b[i];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(b[j]>a[i]){
                    v.push_back(b[j]-a[i]);
                    cnt++;
                }
            }
        }
        sort(v.begin(),v.begin()+cnt);
        int maxn=0,p=1000000005,t=1;
        for(int i=1; i<cnt; i++){
            if(v[i]==v[i-1]){
                t++;
            }else{
                if(t>maxn){
                    maxn=t;
                    p=v[i-1];
                }
                t=1;
            }
        }
        if(cnt==1){
            cout<<v[0]<<endl;
        }else if(cnt==0){
            cout<<0<<endl;
        }
        else{
            if(t>maxn){
                maxn=t;
                p=v[cnt-1];
            }
            cout<<p<<endl;
        }
    }
    return 0;
}