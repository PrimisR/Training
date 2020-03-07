#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool a[16010];
void p()
{
    a[1]=a[2]=false;//根据题意，1和2不算素数  
    int tmp;  
    for(int i=3;i<16010;i++){  
        tmp=(i+1)/2;  
        for(int j=2;j<=tmp;j++){  
            if(i%j==0){  
                a[i]=false;  
                break;  
            }  
        }  
    }  
}
int main()
{
    int n;
    int j=0;
    memset(a,true,sizeof(a));
    p();
    while(cin>>n&&n>0){
        if(a[n]) cout<<++j<<": yes"<<endl;
        else cout<<++j<<": no"<<endl;
    }
    return 0;
}