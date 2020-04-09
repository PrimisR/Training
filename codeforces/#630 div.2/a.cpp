#include <cstdio>
#include <iostream>

using namespace std;

int T;
int l, r, u, d;
int x1, y1, x2, y2;
int x, y;

bool check_x()
{
    int x_max = r - l;
    if (x_max > 0)
    {
        return x + x_max <= x2;
    }
    else if (x_max < 0)
    {
        return x + x_max >= x1;
    }
    else
    {
        if (r == 0)
            return true;
        else
        {
            return x1 != x2;
        }
    }
}

bool check_y()
{
    int y_max = u - d;
    if (y_max > 0)
    {
        return y + y_max <= y2;
    }
    else if (y_max < 0)
    {
        return y + y_max >= y1;
    }
    else
    {
        if (u == 0)
            return true;
        else
        {
            return y1 != y2;
        }
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> l >> r >> d >> u;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if (check_x() && check_y())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}