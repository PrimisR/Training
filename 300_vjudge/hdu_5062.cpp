#include <iostream>
using namespace std;

int main()
{
    int T,N;
    int a[8] = {1,9,18,54,90,174,258};
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        printf("%d\n",a[N]);
    }
    return 0;
}