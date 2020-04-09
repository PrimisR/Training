#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const double eps = 1e-10;

struct point {
    int x;
    int y;
};

double dist(point a,point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt((double)(dx*dx+dy*dy));
}

point p[105];

int main() {
    int n; cin>>n;
    int c = 0;
    while(n--) {
        int total = 0;
        int m; cin>>m;
        for(int i=0;i<m;i++) cin>>p[i].x>>p[i].y;
        for(int i=0;i<m;i++) {
            for(int j=i+1;j<m;j++) {
                for(int k=j+1;k<m;k++) {
                    vector<double> v;
                    v.push_back(dist(p[i],p[j]));
                    v.push_back(dist(p[j],p[k]));
                    v.push_back(dist(p[i],p[k]));
                    sort(v.begin(),v.end());
                    if(v[2] + eps < v[1] + v[0]) {
                        total++;
                    }
                }
            }
        }
        cout << "Test case #" << ++c << ": " << total << " triangle(s) can be formed." << endl;
        cout << endl;
    }
    return 0;
}