#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

struct matrix
{
    double arr[2][2];

    double det() {
        return arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
    }

    matrix(int a1,int a2,int b1,int b2) {
        arr[0][0] = a1;
        arr[0][1] = a2;
        arr[1][0] = b1;
        arr[1][1] = b2;
    }
};


int main() {
    double x1,y1,x2,y2,x3,y3;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3) {
        double xc,yc;
        double dx1 = x2-x1, dx2 = x3-x1, dy1 = y2-y1, dy2 = y3-y1;
        double sx1 = x2+x1, sx2 = x3+x1, sy1 = x2+x1, sy2 = y3+y1;
        double px1 = x1*x1, px2 = x2*x2, px3 = x3*x3;
        double py1 = y1*y1, py2 = y2*y2, py3 = y3*y3;
        matrix m1(2*dx1,2*dy1,2*dx2,2*dy2);
        matrix m2(px2-px1+py2-py1,2*dy1,px3-px1+py3-py1,2*dy2);
        matrix m3(2*dx1,px2-px1+py2-py1,2*dx2,px3-px1+py3-py1);
        xc = m2.det()/m1.det();
        yc = m3.det()/m1.det();
        double dx = xc - x1;
        double dy = yc - y1;
        double r = sqrt(dx*dx + dy*dy);
        double c = 2 * PI * r;
        printf("%.2lf\n",c);
    }
}