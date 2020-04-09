#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int w;
        double b, d, s;
        cin >> w >> b >> d >> s;
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            double x, y;
            cin >> x >> y;
            double r = sqrt(x * x + y * y);
            if(r < b) ans += 50;
            else if(r > s) ans += 0;
            else {
                double theta = atan2(y,x);
                if(theta < 0) theta += 2*pi;
                int pts = (int)(theta * w / (2*pi)) + 1;
                if(r < d) pts *= 2;
                ans += pts;
            }
        }
        cout << ans << endl;
    }
    return 0;
}