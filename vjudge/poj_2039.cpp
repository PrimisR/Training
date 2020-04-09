#include<iostream>
#include<fstream>
using namespace std;

const int MAXN = 205;

int main(){
    //ifstream cin("1.txt");
    int n;
    while(cin>>n&&n!=0){
        string s;
        cin>>s;
        char a[MAXN][MAXN];
        for(int i=0;i<s.length();++i){
            int r=i/n;
            int c=i%n;
            if(r%2==1)
                c=n-1-c;
            a[r][c]=s[i];
        }
 
        for(int i=0;i<n;++i)
            for(int j=0;j<(s.length()/n);++j)
                cout<<a[j][i];
        cout<<endl;
    }
    return 0;
}