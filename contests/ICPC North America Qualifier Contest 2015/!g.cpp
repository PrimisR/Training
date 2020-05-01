#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 20;

int travel_bridge(vector<int> &v)
{
    int sz = v.size();
    if (sz <= 2)
    {
        return v[sz - 1];
    }
    else if (sz == 3)
    {
        return v[0] + v[1] + v[2];
    }
    else
    {
        int tot = 0;
        int a = v[0];
        int b = v[1];
        int z = v[sz - 1];
        int y = v[sz - 2];
        if (b + b < a + y)
        {
            v.erase(v.end() - 1);
            v.erase(v.end() - 1);
            tot += b + a + z + b + travel_bridge(v);
        }
        else
        {
            v.erase(v.end() - 1);
            tot += z + a + travel_bridge(v);
        }
        return tot;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    cout << travel_bridge(v) << endl;
    return 0;
}