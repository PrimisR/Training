/**
 * 相同周长圆形面积最大
 * */
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const double PI=3.1415926;

int main()
{
    double L;
    while(~scanf("%lf",&L)){
        if(!L) break;
        printf("%.2lf\n",(L*L)/(2*PI));
    }
    return 0;
}