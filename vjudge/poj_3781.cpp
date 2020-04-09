#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <functional>
#define PI acos(-1)
#define eps 1e-8
#define inf 0x3f3f3f3f
#define debug(x) cout<<"---"<<x<<"---"<<endl
typedef long long ll;
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        priority_queue<int> qu;
        int zz, x;
        cin >> zz;
        for (int i = 0; i < 10; i++)
        {
            cin >> x;
            qu.push(x);
        }
        for (int i = 0; i < 2; i++)
        {
            qu.pop();
        }
        cout << zz << " " << qu.top() << endl;
    }
    return 0;
}