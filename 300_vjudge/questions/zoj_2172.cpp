#include<stdio.h>  
#include<iostream>  
using namespace std;  
  
  
int main()  
{     
    char words[15][26];  
    int n;  
    int set=1;  
    int i;  
  
    while(1)  
    {  
        cin>>n;  
        if(n==0)  
            break;  
        for(i=0;i<n;i++)  
            cin>>words[i];  
  
        cout<<"SET "<<set++<<endl;  
        for(i=0;i<n;i+=2)  
            cout<<words[i]<<endl;  
          
        if(i==n+1)  
            i=n-2;  
        else  
            i=n-1;  
        for(;i>0;i-=2)  
            cout<<words[i]<<endl;  
    }  
}  