#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str[3];
    vector<string> ans;
    for (int i = 0; i < 3; i++)
    {
        cin >> str[i];
        if (str[i] != "bubble" && str[i] != "tapioka")
        {
            ans.push_back(str[i]);
        }
    }
    if (ans.size() == 0)
        ans.push_back("nothing");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}