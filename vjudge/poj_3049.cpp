#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int l,c,yuan,fu,lenth;
char a[16],s[16];
bool Yuan(char x){
    if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')return 1;
    return 0;
}
void dfs(int x){
    if(lenth==l){
        if(yuan&&fu>=2)printf("%s\n",s+1);
        return;
    }
    for(int i=x;i<=c;i++){
        lenth++;
        if(Yuan(a[i]))yuan++;
        else fu++;
        s[lenth]=a[i];
        dfs(i+1);
        lenth--;
        if(Yuan(a[i]))yuan--;
        else fu--;
    }
}
int main(){
    scanf("%d%d",&l,&c);
    for(int i=1;i<=c;i++)cin>>a[i];
    sort(a+1,a+1+c);
    dfs(1);
}