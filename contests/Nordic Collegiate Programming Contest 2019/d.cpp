#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const int MAXN = 200;
string name[MAXN];

int num(int len, int step, int depth)
{
    int ans = (step - 1) % (len - depth);
    for (int i = depth; i >= 1; i--)
    {
        ans = (ans + step) % (len - i + 1);
    }
    return ans;
}

int main()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<string> split;
    string str;
    while (ss >> str)
    {
        split.push_back(str);
    }
    int step = split.size();
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
    }
    vector<int> t[2];
    bool flag = 0;
    t[0].push_back((step - 1)%n);
    flag ^= 1;
    for (int i = 1; i < n; i++)
    {
        t[flag].push_back(num(n, step, i));
        flag ^= 1;
    }
    for (int i = 0; i < 2; i++)
    {
        cout << t[i].size() << endl;
        for (int j = 0; j < t[i].size(); j++)
        {
            cout << name[t[i][j]] << endl;
        }
    }
    return 0;
}