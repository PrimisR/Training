#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    string a;
    int numb[30];
    while(scanf("%d",&n) != EOF && n)
    {
        int maxn = 0,m;
        getchar();      //注意
        for(int i = 0;i < n; i++)
        {
            getline(cin,a);
            numb[i] = 0;
            for(int j = 0;j < 25; j++)
            {
                if(a[j] == 'X')
                    numb[i]++;
            }
            if(maxn < numb[i])
            {
                maxn = numb[i];
                m = i;
            }
        }
        int sum = 0;
        for(int i = 0;i < n; i++)
        {
            sum = sum + (numb[m] - numb[i]);
        }
        printf("%d\n",sum);
    }
    return 0;
}