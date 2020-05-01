#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 20;

char m[maxn][maxn];

int main()
{
    int n;
    int CASE = 0;
    while (cin >> n && n != 0)
    {
        getchar();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
            getchar();
        }
        int q;
        cin >> q;
        cout << "Input matrix #" << ++CASE << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << m[i][j];
                if (j != n - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
        for (int qi = 1; qi <= q; qi++)
        {
            int r;
            cin >> r;
            vector<char> ans1;
            vector<char> ans2;
            int x1, y1;
            int x2, y2;

            if (r == 1)
            {
                x1 = 0;
                y1 = 0;
                while (x1 < n && y1 < n)
                {
                    ans1.push_back(m[x1][y1]);
                    x1++;
                    y1++;
                }
                cout << "Symmetric diagonals " << r << ":" << endl;
                for (int i = 0; i < ans1.size(); i++)
                {
                    cout << ans1[i];
                    if (i != ans1.size() - 1)
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << endl;
                    }
                }
            }
            else
            {
                x1 = 0;
                y1 = r - 1;
                x2 = r - 1;
                y2 = 0;
                while (x1 < n && y1 < n)
                {
                    ans1.push_back(m[x1][y1]);
                    x1++;
                    y1++;
                }
                while (x2 < n && y2 < n)
                {
                    ans2.push_back(m[x2][y2]);
                    x2++;
                    y2++;
                }
                cout << "Symmetric diagonals " << r << ":" << endl;
                for (int i = 0; i < ans1.size(); i++)
                {
                    cout << ans1[i];
                    if (i != ans1.size() - 1)
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << endl;
                    }
                }
                for (int i = 0; i < ans2.size(); i++)
                {
                    cout << ans2[i];
                    if (i != ans2.size() - 1)
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << endl;
                    }
                }
            }
        }
        cout << endl;
    }
}