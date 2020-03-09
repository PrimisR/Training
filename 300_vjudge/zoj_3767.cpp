#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        int p,max_wt,num,sum=0;
        cin>>p>>max_wt;
        for(int i=0;i<p;i++){
            cin>>num;
            sum+=num;
        }
        if(sum>max_wt) cout<<"Warning"<<endl;
        else cout<<"Safe"<<endl;
    }
    return 0;
}