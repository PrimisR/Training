#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a[6],b[6];
    for(int i=0;i<6;i++) cin>>a[i];
    for(int i=0;i<6;i++) cin>>b[i];
    int cnt = 0;
    int draw = 0;
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
        {
            if(a[i] > b[j])
                cnt++;
            else if(a[i] == b[j])
                draw++;
        }
    double r = (double)cnt / (double)(36-draw);
    printf("%.5lf\n",r);
}