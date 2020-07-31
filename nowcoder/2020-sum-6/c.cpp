#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int matrix[210][210];
int sum[210][210];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)    
    {
        cin >> n >> m;
        double maxr = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> matrix[i][j];
                sum[i][j] = sum[i - 1][j] + matrix[i][j];
                double r = (sum[i][j] * 1.0) / (matrix[i][j] * 1.0);
                maxr = max(r, maxr);
            }
        }
        cout.setf(ios::fixed);
        cout << fixed << setprecision(8) << maxr << endl;
    }
    return 0;
}