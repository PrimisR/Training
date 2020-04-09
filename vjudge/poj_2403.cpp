#include <iostream>
#include <string>
using namespace std;
struct word
{
    int date;//键值 
    string a;//单词 
}w[10000];
int main()
{
    int m,n,i;
    cin>>m>>n;
    for (i=0;i<m;i++)
        cin>>w[i].a>>w[i].date;
    while(n--)
    {
        string ch,c;
        int sum=0;
        c=".";//信息输入结束条件        
        while(cin>>ch&&ch!=c)
        {
            for(i=0;i<m;i++)
                if(ch==w[i].a) 
                    sum+=w[i].date;
        }
        cout<<sum<<endl;
    }
    return 0;
}