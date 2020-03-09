#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[300]={0};
    int i,la;
    long long s;
    cin.getline(a,256,'\n');//输入一行（包括空格）
    while(a[0]!='#')
    {
        la=strlen(a);
        s=0;
        for(i=0;i<la;i++)
        {
            if(a[i]!=' ')//空格直接跳过
                s+=(((int)a[i]-64)*(i+1));//注：我乘i+1是因为循环从0开始
        }
        cout<<s<<endl;
        cin.getline(a,256,'\n');//输入一行（包括空格）
    }
    return 0;
}
