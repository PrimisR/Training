#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

bool eql(double a,double b) {
    return a-b >= -0.000001 && a-b <= 0.000001;
}

struct point {
    double x;
    double y;
    point(double x,double y):x(x),y(y){}
    point(){}
};

point p[55];

double dist(point a,point b) {
    double dx = a.x-b.x;
    double dy = a.y-b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    //freopen("C:\\Users\\hp\\Desktop\\VS Code\\contests\\UCF Local Programming Contest 2016\\out.txt","w",stdout);
    int T; cin>>T;
    int CASE = 0;
    while(T--) {
        int s; cin>>s;
        for(int i=0;i<s;i++) {
            cin>>p[i].x>>p[i].y;
        }
        int ans = 0;
        for(int i=0;i<s;i++) {
            for(int j=i+1;j<s;j++) {
                for(int k=0;k<s;k++) {
                    if(k == i || k == j) continue;
                    if(eql(p[k].x,(p[i].x+p[j].x)/2) && eql(p[k].y,(p[i].y+p[j].y)/2)) {
                        for(int l=0;l<s;l++) {
                            if(l == i || l == j || l == k) continue;
                            if(eql(dist(p[l],p[i]),dist(p[l],p[j]))) {
                                if(eql(dist(p[l],p[k]),dist(p[i],p[j]))) {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
        std::cout << "Set #" << ++CASE << ": " << ans << endl << endl;
    }
    return 0;
}