#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct p
{
    int x;
    int y;
    p(int x, int y) : x(x), y(y) {}
    p() {}
    p operator+(const p o) const
    {
        return p(this->x + o.x, this->y + o.y);
    }
    p operator*(const int x) const
    {
        return p(this->x * x, this->y * x);
    }
};

p dirs[4] = {p(1, 0), p(0, 1), p(-1, 0), p(0, -1)};

int main()
{
    int n;
    cin >> n;
    int prog = 0;
    while (n--)
    {
        p u(0, 0);
        int dir = 0;
        p coffee, doc;
        int k;
        cin >> k;
        while (k--)
        {
            string op;
            int move;
            cin >> op;
            if (op[0] == 'M')
            {
                cin >> move;
                u = u + dirs[dir] * move;
            }
            else if (op[0] == 'L')
            {
                dir = (dir + 1) % 4;
            }
            else if (op[0] == 'R')
            {
                dir = (dir + 3) % 4;
            }
            else if (op[0] == 'U')
            {
                dir = (dir + 2) % 4;
            }
        }
        cin >> coffee.x >> coffee.y >> doc.x >> doc.y;
        cout << "Robot Program #" << ++prog << ":" << endl;
        cout << "The robot is at (" << u.x << "," << u.y << ")" << endl;
        if (u.x != coffee.x)
        {
            if (u.x < coffee.x)
            {
                if (dir == 1)
                    cout << "RIGHT" << endl;
                else if (dir == 2)
                    cout << "UTURN" << endl;
                else if (dir == 3)
                    cout << "LEFT" << endl;
                dir = 0;
            }
            else
            {
                if (dir == 0)
                    cout << "UTURN" << endl;
                else if (dir == 1)
                    cout << "LEFT" << endl;
                else if (dir == 3)
                    cout << "RIGHT" << endl;
                dir = 2;
            }
            cout << "MOVE " << abs(coffee.x - u.x) << endl;
            u.x = coffee.x;
        }
        if(u.y != coffee.y)
        {
            if(u.y < coffee.y) {
                if(dir == 0)
                    cout << "LEFT" << endl;
                else if(dir == 2)
                    cout << "RIGHT" << endl;
                else if(dir == 3)
                    cout << "UTURN" << endl;
                dir = 1;
            }
            else
            {
                if(dir == 0)
                    cout << "RIGHT" << endl;
                else if(dir == 1)
                    cout << "UTURN" << endl;
                else if(dir == 2)
                    cout << "LEFT" << endl;
                dir = 3;
            }
            cout << "MOVE " << abs(coffee.y - u.y) << endl;
            u.y = coffee.y;
        } 
        if (u.x != doc.x)
        {
            if (u.x < doc.x)
            {
                if (dir == 1)
                    cout << "RIGHT" << endl;
                else if (dir == 2)
                    cout << "UTURN" << endl;
                else if (dir == 3)
                    cout << "LEFT" << endl;
                dir = 0;
            }
            else
            {
                if (dir == 0)
                    cout << "UTURN" << endl;
                else if (dir == 1)
                    cout << "LEFT" << endl;
                else if (dir == 3)
                    cout << "RIGHT" << endl;
                dir = 2;
            }
            cout << "MOVE " << abs(doc.x - u.x) << endl;
            u.x = doc.x;
        }
        if(u.y != doc.y)
        {
            if(u.y < doc.y) {
                if(dir == 0)
                    cout << "LEFT" << endl;
                else if(dir == 2)
                    cout << "RIGHT" << endl;
                else if(dir == 3)
                    cout << "UTURN" << endl;
                dir = 1;
            }
            else
            {
                if(dir == 0)
                    cout << "RIGHT" << endl;
                else if(dir == 1)
                    cout << "UTURN" << endl;
                else if(dir == 2)
                    cout << "LEFT" << endl;
                dir = 3;
            }
            cout << "MOVE " << abs(doc.y - u.y) << endl;
            u.y = doc.y;
        }
        cout << endl;
    }
}