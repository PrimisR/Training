/**
 * 最长上升子序列
 * */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string ec, s;
    cin >> s;
    for (char c : s)
    {
        auto it = lower_bound(ec.begin(), ec.end(), c);
        if (it == ec.end())
            ec.push_back(c);
        else
            *it = c;
        for(int i=0;i<ec.size();i++) {
            cout << ec[i] << " ";
        }
        cout << endl;
    }
    cout << (26 - ec.size()) << endl;
    return 0;
}
