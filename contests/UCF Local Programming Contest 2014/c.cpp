#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int loop = 1; loop <= n; loop++)
    {
        int len, d;
        string str;
        cin >> len >> d >> str;
        d++;
        vector<int> v;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '.')
                v.push_back(i);
        }
        int vp = 0, step = 0;
        while (vp != v.size() - 1)
        {
            int s = v[vp] + d;
            int loc = lower_bound(v.begin(), v.end(), s) - v.begin();
            if(v[loc] != s) loc--;
            if (loc == vp)
            {
                step = 0;
                break;
            }
            vp = loc;
            step++;
        }
        cout << "Day #" << loop << endl;
        cout << len << " " << d-1 << endl;
        cout << str << endl;
        cout << step << endl << endl;
    }
}