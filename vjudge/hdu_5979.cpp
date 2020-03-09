/**
 * 计算三角形面积求和 S=1/2*a*b*sinc
 * 注意pi用 acos(0)*2
 * */
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n, r;
    while (cin >> n >> r)
    {
        double s = 0.0;
        while (n--)
        {
            int degree;
            cin >> degree;
            double angle = (double)degree / 90.0 * acos(0);
            double si = 0.5 * (double)r * r * sin(angle);
            s += si;
        }
        printf("%.3lf\n", s);
    }
    return 0;
}